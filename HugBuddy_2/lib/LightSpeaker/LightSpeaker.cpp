#include "LightSpeaker.hpp"

Talkie LightSpeaker::voice;
uint64_t LightSpeaker::last_debouncing_time, LightSpeaker::debouncing_time = 100;
uint16_t LightSpeaker::dark_limit = 250;
LightState LightSpeaker::state = LIGHT, LightSpeaker::last_state = LIGHT;

uint8_t LightSpeaker::light_speaker_init() 
{
    // speaker
    pinMode(SPEAKER_PIN, OUTPUT);
    digitalWrite(SPEAKER_PIN, HIGH);

    // light sensor
    pinMode(EYE1_PIN, INPUT);
    pinMode(EYE2_PIN, INPUT);
    last_debouncing_time = millis();

    return 1;
}

void LightSpeaker::light_speaker_loop() 
{
    LightSpeaker::light_analyze();
}

LightState LightSpeaker::get_light_state() 
{
    return LightSpeaker::state;
}

void LightSpeaker::say_dark() 
{
    voice.say(sp_Oh);
    voice.say(spPAUSE1);
    voice.say(sp_dark);
    voice.say(spPAUSE1);
    voice.say(sp_scared);
}

void LightSpeaker::say_hard_hug()
{
    voice.say(sp_Hey);
    voice.say(spPAUSE1);
    voice.say(sp_Easy);
    voice.say(spPAUSE1);
    voice.say(sp_just);
    voice.say(sp_bear);
}

void LightSpeaker::say_love() 
{
    voice.say(sp_love);
}

void LightSpeaker::light_analyze() 
{
    uint16_t value1 = analogRead(EYE1_PIN);
    uint16_t value2 = analogRead(EYE2_PIN);
    LightState current_state;
    if (value1 < LightSpeaker::dark_limit && value2 < LightSpeaker::dark_limit) current_state = DARK;
    else current_state = LIGHT;
    if (current_state != last_state) last_debouncing_time = millis();
    if (millis() - last_debouncing_time > debouncing_time) 
    {
        if (current_state != state) state = current_state;
    }
    last_state = current_state;
}
