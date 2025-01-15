#include <Arduino.h>
#include <WiFiConnection.hpp>
#include <Hugs.hpp>
#include <LightSpeaker.hpp>



void setup() {
  Serial.begin(9600);
  uint8_t correct = 1;
  correct &= WiFiConnection::wifi_init();
  correct &= Hugs::hugs_init();
  correct &= LightSpeaker::light_speaker_init();
  Serial.println(correct);
  if (correct) LightSpeaker::say_ready();
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

