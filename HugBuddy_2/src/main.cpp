#include <Arduino.h>
#include <WiFiConnection.hpp>
#include <Hugs.hpp>
#include <LightSpeaker.hpp>



void setup() {
  Serial.begin(9600);
  WiFiConnection::wifi_init();
  Hugs::hugs_init();
  LightSpeaker::light_speaker_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  Hugs::hugs_loop();
  LightSpeaker::light_speaker_loop();

  if (WiFiConnection::hug_receive()) 
  {
    Hugs::start_hug();
    if (Hugs::get_sensor_state() != NO_HUG) LightSpeaker::say_love();
  }
  switch (Hugs::get_sensor_state())
  {
    case HARD_HUG:
      // say too hard
      LightSpeaker::say_hard_hug();
    case HUG:
      WiFiConnection::hug_send();
      break;
    default:
      break;
  }
  switch (LightSpeaker::get_light_state())
  {
  case DARK:
    LightSpeaker::say_dark();
    Hugs::start_hug();
    break;
  
  default:
    break;
  }
}

