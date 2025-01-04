#include <Arduino.h>
#include <WiFiConnection.hpp>

void setup() {
  Serial.begin(9600);
  WiFiConnection::wifi_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFiConnection::hug_receive())
    Serial.println("yeeeey!");
}

