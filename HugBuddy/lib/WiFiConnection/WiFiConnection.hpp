#ifndef WIFI_CONNECTION_HPP
#define WIFI_CONNECTION_HPP

#include <Arduino.h>
#include <WiFi.h>
#include <Preferences.h>

class WiFiConnection {

    static const char SSID_preference_name[];
    static const char pass_preference_name[];
    static const char myIP_preference_name[];
    static const char buddyIP_preference_name[];
    static const char gateway_preference_name[];
    static const char mask_preference_name[];
    static const char preference_name[];
    static String ssid, password, myIP, buddyIP;
    static WiFiServer server;
    
    static uint8_t wifi_connect();
    static void wifi_scan();
    static uint8_t create_friend_connection();
    static void save_preferences(Preferences);

    public:
        static uint8_t wifi_init();
        static uint8_t hug_receive();
        static void hug_send();
};

#endif