#include "WiFiConnection.hpp"

const char WiFiConnection::SSID_preference_name[] = "SSID";
const char WiFiConnection::pass_preference_name[] = "password";
const char WiFiConnection::myIP_preference_name[] = "myIP";
const char WiFiConnection::buddyIP_preference_name[] = "buddyIP";
const char WiFiConnection::preference_name[] = "WiFiConnection";
const char WiFiConnection::gateway_preference_name[] = "gateway";
const char WiFiConnection::mask_preference_name[] = "mask";
String WiFiConnection::ssid, WiFiConnection::password, WiFiConnection::myIP, WiFiConnection::buddyIP;
WiFiServer WiFiConnection::server;

uint8_t WiFiConnection::wifi_init() 
{
    Preferences preference;

    // open the preference namespace
    preference.begin(WiFiConnection::preference_name, false);

    if (preference.getString(WiFiConnection::SSID_preference_name, "").isEmpty()) 
    {
        // no wifi saved in memory
        // need to scan nearest networks and ask the user to choice one network

        // initialize serial
        Serial.setTimeout(100000);
        Serial.println("Serial starts!");

        do  {
            WiFiConnection::wifi_scan();

            // ask for password
            Serial.print("Password: ");
            while (!Serial.available());
            WiFiConnection::password = Serial.readStringUntil('\n');
            WiFiConnection::password.trim();

        } while (!WiFiConnection::wifi_connect());
        
        // we need to ask for friend IP
        Serial.println("Please insert your buddy IP address:");
        while(!Serial.available());
        WiFiConnection::buddyIP = Serial.readStringUntil('\n');
        WiFiConnection::buddyIP.trim();

        if (WiFiConnection::create_friend_connection()) {
            WiFiConnection::save_preferences(preference);
            return 1;
        }
        else {
            Serial.println("Initialisation failed, please try again!");
            return 0;
        }
    } else {
        // we have already save the connection information
        // get all the information from preferences
        WiFiConnection::ssid = preference.getString(WiFiConnection::SSID_preference_name);
        WiFiConnection::password = preference.getString(WiFiConnection::pass_preference_name);
        WiFiConnection::myIP = preference.getString(WiFiConnection::myIP_preference_name);
        WiFiConnection::buddyIP = preference.getString(WiFiConnection::buddyIP_preference_name);
        String gateway = preference.getString(WiFiConnection::gateway_preference_name);
        String mask = preference.getString(WiFiConnection::mask_preference_name);

        // set the static IP
        IPAddress myIP_address, gateway_address, mask_address;
        myIP_address.fromString(myIP);
        gateway_address.fromString(gateway);
        mask_address.fromString(mask);

        try {
            if (!WiFi.config(myIP_address, gateway_address, mask_address)) throw std::runtime_error("Not configure");

            if (!WiFiConnection::wifi_connect()) throw std::runtime_error("Not connected");

            if (!WiFiConnection::create_friend_connection()) throw std::runtime_error("Not connected to buddy");
            return 1;
        } catch (std::exception& e) {
            // we have same errors so we will delete the preferences and return 0
            preference.clear();
            return 0;
        }
    }

}

void WiFiConnection::wifi_scan() 
{
    // we will scan the nearest network and print them on the Serial
    // and we will wait for an number in order to get the network to which the client wants to connect
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    uint16_t number_networks = WiFi.scanNetworks();
    Serial.println("Scan completed!");
    if (number_networks == 0) {
        Serial.println("No networks found!");
        return;
    }

    Serial.print(number_networks);
    Serial.println(" networks found!");

    for (uint16_t i = 0; i < number_networks; ++i) 
    {
        Serial.print(i + 1);
        Serial.print(". ");
        Serial.print(WiFi.SSID(i));
        Serial.print(" (");
        Serial.print(WiFi.RSSI(i));
        Serial.print(")");
        Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
    }

    Serial.println();
    Serial.println("Please select what network do you want to connect to: ");
    String network_selected;
    uint16_t index_network_selected = 65535;
    do {
        if (index_network_selected != 65535) Serial.println("Wrong number, please try again!");
        while (!Serial.available());
        network_selected = Serial.readStringUntil('\n');
        network_selected.trim();
        index_network_selected = atoi(network_selected.c_str());
    } while (index_network_selected <= 0 || index_network_selected > number_networks);

    WiFiConnection::ssid = WiFi.SSID(index_network_selected - 1);
    Serial.print("Selected network: ");
    Serial.println(WiFiConnection::ssid);
}

uint8_t WiFiConnection::wifi_connect() 
{
    // we have the SSID and the password we just need to do the connection
    // we will wait 5 seconds to connect to the wifi and if the connection is not made we will 
    // return false

    WiFi.mode(WIFI_STA);
    Serial.print("WiFi connecting.");
    WiFi.begin(WiFiConnection::ssid.c_str(), WiFiConnection::password.c_str());
    for (uint8_t i = 0; i < 5 && WiFi.status() != WL_CONNECTED; i++) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println();
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Connected");
        WiFiConnection::myIP = WiFi.localIP().toString();
        Serial.print("My IP is: ");
        Serial.println(WiFiConnection::myIP);
        return 1;
    }
    Serial.println("Connection failed! Try again!");
    return 0;
}

uint8_t WiFiConnection::create_friend_connection() 
{
    // first we will create the server for our bear and after this we will try to connect to the friend server
    // we will try 10 times with a delay of 3 seconds between attempts

    WiFiConnection::server.begin(7777);

    // try to connect to the other one server
    WiFiClient outcoming_client;
    uint8_t me_to_buddy = 0;
    uint8_t buddy_to_me = 0;
    for (int i = 0; i < 10; ++i) 
    {
        Serial.print("Attempt ");
        Serial.println(i + 1);
        // try to connect to the buddy server
        if (!me_to_buddy && outcoming_client.connect(WiFiConnection::buddyIP.c_str(), 7777)) {
            outcoming_client.println("HELLO");
            outcoming_client.stop();
            Serial.println("Connected to the buddy server!");
            me_to_buddy = 1;
        }
        // try to read the buddy connection
        if (!buddy_to_me) 
        {
            WiFiClient incoming_client = server.available();
            if (incoming_client) 
            {
                // read the HELLO 
                String response = incoming_client.readString();
                response.trim();
                Serial.println(response);
                if (response == "HELLO") buddy_to_me = 1;
                incoming_client.stop();
                Serial.println("Buddy connected to local server!");
            }
        }
        if (me_to_buddy && buddy_to_me) {
            Serial.println("Connection made!");
            return 1;
        }
        delay(3000);
    }
    Serial.println("Failed to connect with the buddy!");
    return 0;
}

void WiFiConnection::save_preferences(Preferences preference) 
{
    preference.putString(WiFiConnection::SSID_preference_name, WiFiConnection::ssid);
    preference.putString(WiFiConnection::pass_preference_name, WiFiConnection::password);
    preference.putString(WiFiConnection::myIP_preference_name, WiFiConnection::myIP);
    preference.putString(WiFiConnection::buddyIP_preference_name, WiFiConnection::buddyIP);
    preference.putString(WiFiConnection::gateway_preference_name, WiFi.gatewayIP().toString());
    preference.putString(WiFiConnection::mask_preference_name, WiFi.subnetMask().toString());
    preference.end();
}

uint8_t WiFiConnection::hug_receive() 
{
    WiFiClient incoming_client = server.available();
    if (incoming_client) 
    {
        // read the message from the client
        String response = incoming_client.readString();
        response.trim();
        if (response == "HUG") {
            incoming_client.stop();
            return 1;
        }
        incoming_client.stop();
    }
    return 0;
}

void WiFiConnection::hug_send() 
{
    // connect to the buddy and send him a hug
    WiFiClient outcoming_client;
    if (outcoming_client.connect(WiFiConnection::buddyIP.c_str(), 7777)) 
    {
        outcoming_client.println("HUG");
        outcoming_client.stop();
    }
}