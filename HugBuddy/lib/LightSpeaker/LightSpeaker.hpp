#ifndef LIGHT_SPEAKER_HPP
#define LIGHT_SPEAKER_HPP

#include <Arduino.h>
#include <Talkie.h>

const uint8_t sp_Oh[] PROGMEM = {0x49,0x8E,0xC5,0x4C,0x06,0xDD,0x18,0xD9,0x34,0x51,0x2D,0xF1,0xEA,0x64,0x57,0x4D,0x65,0xC8,0xAD,0x53,0xC3,0x50,0xB3,0x06,0x37,0x0E,0xF3,0x8B,0x3D,0x9A,0x14,0x99,0xC0,0x2F,0xCC,0x0A,0x54,0xAC,0x22,0xB7,0x30,0x26,0x98,0xB6,0x88,0xF5,0x22,0xAD,0x52,0xC6,0x22,0x91,0x8B,0xB9,0xD2,0x29,0xB3,0x8D,0x4F,0x23,0xAB,0x94,0xC4,0x12,0x36,0x8D,0x2C,0xCA,0x16,0x8B,0x51,0x2B,0x56,0xCF,0x44,0x24,0x06,0x6E,0xC2,0xDD,0x92,0x20,0x81,0xCB,0x50,0x37,0xB3,0x8B,0x86,0x20,0x53,0x55,0x54,0x0A,0x9A,0x83,0x48,0x55,0x51,0x49,0xA8,0x8A,0xD0,0xDD,0xC5,0x6D,0x13,0xB0,0x00,0x53,0x55,0x93,0x45,0xC0,0x0C,0x5C,0xD5,0xCC,0x36,0x39,0x2A,0x30,0x15,0x55,0xD9,0xA8,0xEB,0x40,0x54,0x44,0x65,0xA1,0xB8,0x03,0x51,0x65,0x93,0x04,0x0F,0xE8,0x32};
const uint8_t sp_dark[] PROGMEM = {0x49,0x37,0x2E,0x37,0x1D,0x1D,0x1B,0x9D,0xDD,0x2C,0x41,0x49,0x42,0x7A,0x62,0x27,0xD2,0xCC,0x36,0x02,0x23,0x75,0x35,0x75,0xC5,0x04,0x4C,0x54,0xCC,0xDC,0x1C,0x13,0xB0,0x32,0x11,0x36,0x95,0x4C,0xAE,0xC6,0x45,0x45,0x55,0x32,0xE1,0x2A,0x15,0x55,0x53,0x59,0x0C,0xAC,0x5C,0x55,0x23,0x64,0x1B,0x99,0xAF,0x34,0x09,0xF6,0xE2,0x14,0xB9,0xCC,0xCC,0x29,0x8B,0x51,0xC4,0x52,0xB3,0x64,0x2D,0x4A,0x61,0x5B,0x2C,0x4B,0xD8,0x28,0x95,0x6D,0x77,0x69,0x66,0x2B,0x34,0xB0,0xCA,0xD5,0x9D,0x2E,0xB1,0x40,0xDB,0x0C,0x35,0x39,0x4A,0xC9,0xCC,0xC2,0x3B,0x69,0x3B,0x53,0x95,0xA8,0x30,0xD4,0xE2,0x6C,0x7B,0x34,0x9D,0xC5,0x71,0x70,0xFD,0x94,0x0C,0x13,0x35,0xCE,0x0B,0x83,0xCA,0x9C,0xD5,0x38,0x2F,0x74,0x2A,0x57,0x63,0xE2,0x82,0xD0,0xA8,0x5D,0x9C,0xAA,0x0B,0x63,0xA1,0x51,0x0D,0x2A,0x26,0x8E,0x99,0x56,0x34,0xC8,0x98,0x38,0x24,0x5A,0x95,0x24,0xA3,0x12,0x9F,0x78,0x83,0x5D,0x0C,0xDB,0x74,0xD4,0x5A,0x11,0xC9,0xE8,0x31,0x32,0xD5,0xDD,0x64,0x23,0xD0,0x88,0x54,0x77,0x57,0x8C,0x40,0xCF,0x42,0xCD,0xCC,0x16,0xA3,0xAA,0x66,0x33,0x09,0x4B,0x84,0x2E,0x5C,0x2C,0xCD,0x24,0x12,0x3A,0x73,0xD1,0x30,0x95,0x85,0xA8,0xC8,0xDD,0x5C,0xCD,0x12,0x3C,0xA0,0xCB};
const uint8_t sp_scared[] PROGMEM = {0x45,0x8D,0xC9,0xC3,0x0B,0x1D,0x27,0xC5,0x0E,0x0D,0x11,0xAA,0xED,0x64,0x3E,0xC5,0x4D,0xBD,0x8D,0x02,0xC1,0x4B,0xAB,0x08,0xBA,0x46,0x22,0x5B,0xBC,0xDD,0x95,0x3A,0xD9,0x6C,0xF2,0x51,0x4A,0x6A,0x34,0x73,0xC8,0xD6,0x30,0x8E,0x32,0xF8,0x13,0xEE,0x54,0x39,0xCC,0x22,0x2F,0xD9,0xC3,0x25,0x0B,0x8B,0x9E,0x90,0x2A,0x91,0xEC,0x2C,0xDB,0xCC,0x36,0x20,0x72,0xB0,0x5D,0x0B,0xDF,0x02,0x27,0xC1,0x76,0x2D,0x7C,0x1A,0x9C,0x28,0x47,0xAB,0x70,0x2F,0xB3,0xEC,0x5C,0x1B,0x47,0x65,0x54,0xB2,0x73,0x5D,0x2B,0xF6,0x65,0x3A,0xC6,0x33,0x3D,0x28,0x86,0xE5,0x08,0x9F,0xD5,0x60,0xCB,0xB0,0x2D,0x82,0xC0,0x55,0xBD,0xDC,0x36,0xE9,0xB3,0x11,0xB2,0x08,0x89,0xE4,0x2F,0x5C,0x58,0x45,0x6D,0x91,0xB3,0x68,0x23,0x22,0x95,0x44,0xC0,0xAC,0x8C,0x88,0xCD,0x16,0xD1,0x2B,0x17,0x23,0x71,0x5B,0xCA,0x09,0xDC,0x36,0x03,0x65,0x07,0x2F,0x28,0xDB,0x32,0xA2,0x13,0x7C,0x6F,0x7C,0xD3,0x98,0x4E,0xF0,0xA3,0x91,0x09,0x67,0x39,0x21,0x08,0x4E,0x26,0x44,0xA5,0xB8,0x30,0x04,0x5E,0x31,0x66,0x62,0xA2,0x18,0x68,0xD5,0x8C,0xB6,0x89,0x43,0xA4,0x35,0x71,0x2A,0x2A,0xF6,0x91,0xD7,0xD8,0xE8,0xAA,0x58,0x25,0xDD,0x60,0xA5,0xCB,0x12,0xEC,0xB3,0xC6,0x44,0x0E,0x8B,0x03,0xB5,0xB2,0x52,0x39,0x84,0x0D,0x4C,0x3D,0xC3,0x64,0x13,0x39,0x73,0x11,0x57,0x95,0x05,0x0F,0xE8,0x32};
const uint8_t sp_Hey[] PROGMEM = {0xE2,0xA9,0x5A,0xC2,0x55,0x22,0x2A,0x39,0x4A,0x4D,0x77,0x4D,0x92,0x24,0x1F,0xB2,0x49,0x39,0x49,0x91,0x83,0xCF,0x11,0xC5,0x38,0x45,0x8E,0x36,0x47,0x85,0xEC,0x14,0x2D,0xEA,0x58,0x17,0xB4,0x9D,0x9C,0xA8,0x63,0x43,0x51,0x76,0xF0,0xA3,0xB4,0x0D,0x65,0xD9,0x2E,0x0C,0xC2,0x36,0x14,0x9D,0xA8,0x48,0x99,0x5A,0x66,0x72,0x22,0x62,0xE6,0x67,0x89,0x24,0x31,0x89,0x60,0xDE,0x62,0x56,0xC5,0x24,0x82,0xB2,0xAA,0x3C,0xEC,0x20,0x3E,0x22,0x75,0x37,0x73,0x0C,0x0F,0xE8,0x32};
const uint8_t sp_Easy[] PROGMEM = {0x06,0xF4,0x24,0x6E,0x98,0x9A,0x38,0x50,0xB3,0xBA,0x11,0x8E,0xEB,0x40,0xCD,0xEB,0xDA,0x39,0x89,0x03,0xB9,0xEE,0xEB,0xA4,0xA4,0x02,0x24,0xB1,0xB7,0x93,0xE2,0x11,0x30,0x70,0xC9,0x2E,0xB7,0xC3,0xC0,0xC0,0x2D,0x7B,0xCD,0xB1,0x01,0x85,0xCE,0xAB,0xC0,0xB8,0x4E,0xB1,0x22,0x2E,0x14,0x92,0x18,0x5D,0xA9,0x3C,0x63,0x48,0x22,0x4C,0xE6,0x7A,0x55,0x51,0x31,0xA3,0xB4,0xB4,0x6C,0xF7,0x58,0xCE,0xF6,0xC6,0xD7,0x13,0xEC,0x24,0x27,0xD8,0xD8,0x08,0xB0,0x92,0xDC,0xA8,0x6D,0x22,0xD0,0x76,0xF2,0x92,0xB1,0xB6,0x20,0x29,0xC9,0x8F,0x4E,0xDB,0x82,0xA5,0x84,0x20,0x46,0x19,0x75,0x91,0x63,0xC2,0x18,0x79,0x45,0x8C,0x8E,0x89,0x42,0xA2,0x35,0x72,0xA9,0x2A,0x0A,0x91,0xC6,0xC8,0xA4,0x8A,0xD0,0x04,0xEE,0x44,0xB5,0x43,0x42,0x64,0xDC,0x27,0x4D,0x29,0xE2,0x82,0x14,0x4E,0x37,0x3B,0x88,0xCB,0x4A,0xD8,0x5D,0x64,0x3F,0xA0,0xCB};
const uint8_t sp_just[] PROGMEM = {0xC5,0x88,0xD1,0xC2,0x0B,0x6D,0x27,0xC3,0x4C,0x2D,0x61,0x6E,0xEC,0x0C,0x79,0x38,0x88,0xA3,0xB6,0x32,0xC0,0x33,0x73,0x73,0x27,0xC2,0x00,0xDF,0x55,0xC3,0xD4,0x32,0x03,0xBC,0x12,0x35,0x77,0xC3,0x2C,0xC9,0x3A,0x2B,0xDC,0xB6,0x01,0xB6,0x30,0x09,0x96,0x57,0xD9,0x51,0x8A,0xB8,0x38,0xC1,0x7B,0xC7,0x80,0x95,0xE2,0x45,0x6F,0x15,0x8D,0x56,0x92,0x1F,0xA3,0x85,0x27,0xDA,0x09,0x41,0x88,0x12,0x19,0xE0,0x44,0x05,0x3C,0x98,0x67,0x90,0x1B,0x11,0x08,0xEE,0xEE,0xEB,0xB1,0x09,0x97,0xB9,0x12,0xA5,0x39,0x21,0x6B,0x65,0x4A,0x62,0x26,0x89,0x08,0x95,0x8A,0xAA,0x88,0x24,0xF2,0x16,0xA2,0xA2,0x2A,0xB6,0x48,0x96,0x70,0xA8,0xA9,0x4B,0x26,0x59,0x26,0xA1,0x6E,0x6A,0x9B,0x21,0x85,0x9B,0x7A,0x39,0x6D,0xD4,0x65,0xC5,0xA4,0xA1,0xB4,0xE1,0x01,0x5D,0x86};
const uint8_t sp_bear[] PROGMEM = {0x41,0xF5,0x33,0x35,0x1A,0xE5,0x38,0xCD,0x5E,0x91,0x4A,0x70,0xA2,0x34,0x7E,0x58,0x3B,0x45,0x89,0x50,0xC9,0x73,0x8E,0x30,0xD9,0x4A,0xA1,0x23,0x24,0x5B,0x25,0x3B,0xC9,0x36,0x8D,0x0D,0x48,0x1C,0x44,0x5F,0xCD,0xB7,0xC0,0x69,0xE0,0x6D,0x4D,0xEF,0x06,0x37,0x46,0xD0,0xB6,0xC3,0x5A,0x2D,0x3B,0xDE,0xB4,0x51,0x5D,0xB2,0xEB,0x04,0xB3,0x93,0x7D,0xD8,0x89,0x92,0xD4,0x0B,0xCA,0x96,0xD8,0x4C,0x21,0x3B,0xD9,0xDC,0x63,0x13,0x14,0xE4,0xAB,0x32,0x93,0x83,0x48,0xAC,0x3B,0x2A,0xC3,0x8E,0x32,0x44,0x8E,0x2C,0x13,0x26,0xCE,0xD0,0x25,0x5A,0x8D,0xDC,0xB8,0xDD,0xC5,0x5C,0x61,0x4C,0xE2,0x4C,0x1F,0x72,0x4D,0xD0,0x49,0x30,0x83,0x8F,0x55,0x21,0xC7,0xC1,0x0A,0xDE,0x57,0x9D,0x94,0x04,0x37,0x39,0x1E,0x4B,0xA6,0xE3,0xFC,0x14,0x68,0x2C,0x98,0xB6,0x09,0x52,0xA2,0x55,0x33,0xDA,0x26,0x8C,0x89,0x57,0xD9,0xA8,0xA8,0x28,0x24,0x1A,0x27,0x93,0xA2,0x42,0x1F,0x79,0x82,0xC4,0x0A,0x0B,0x79,0xD0,0x68,0x16,0x25,0x84,0x11,0xC2,0xB4,0x33,0xEC,0x20,0x2E,0x2B,0x46,0x73,0xA3,0x05,0x0F,0xE8,0x32};
const uint8_t spPAUSE1[] PROGMEM = {0x00,0x00,0x00,0x00,0xFF,0x0F};
const uint8_t sp_love[] PROGMEM = {0xC5,0x4C,0xC9,0xC2,0x9B,0x14,0x17,0x23,0x64,0x4F,0x4B,0x88,0x9D,0x0C,0x37,0x22,0xD5,0xA1,0x76,0xD0,0xCD,0x36,0x37,0x87,0xC4,0x46,0x17,0x4B,0xBC,0x8C,0x52,0x0B,0x83,0x3E,0xE5,0x4E,0x91,0x22,0x0C,0xF2,0x8D,0x23,0x94,0xB6,0xD1,0xF9,0x11,0x1F,0x23,0x3B,0x49,0xF7,0x53,0x72,0x14,0x2A,0x15,0x2D,0x34,0xF5,0x49,0x70,0xDC,0xE4,0xD8,0xCC,0xBA,0xC8,0x76,0xE2,0x7D,0x37,0x2F,0x47,0xA7,0x46,0x50,0xDD,0x34,0x8C,0xD3,0x10,0xD0,0xA8,0x8C,0x30,0x97,0x43,0x40,0x4F,0x2D,0x3A,0xDD,0xB1,0x32,0x89,0x9B,0x75,0xC6,0x24,0xC6,0xD1,0x2A,0xAF,0x15,0x24,0x07,0x2F,0x08,0xDB,0x71,0xA4,0xEB,0x02,0xAF,0x63,0xD3,0x90,0x8E,0x0B,0xBD,0xF1,0x35,0x67,0x39,0x2E,0xB2,0xD9,0xCA,0x9D,0xD9,0x98,0x48,0x0F,0x0D,0x77,0x61,0x22,0x62,0x75,0x58,0xCB,0x95,0x36,0x8B,0xC5,0x51,0xF2,0x0C,0xD9,0x2C,0xC6,0xAD,0x48,0x23,0x63,0x93,0x08,0xD8,0xC9,0x30,0x77,0x83,0x78,0xA7,0x92,0x4D,0xD4,0x31,0x2A,0xA3,0x0C,0x55,0x51,0xDB,0xA4,0x4C,0xD0,0xCD,0xCC,0x64,0x93,0xBB,0x00,0x33,0x31,0x93,0x8C,0xBA,0x06,0xC4,0x4D,0xC4,0xCA,0x03,0xBA,0x0C};
const uint8_t sp_ready[] PROGMEM = {0xCC,0xC4,0x75,0xD4,0x22,0x6C,0x39,0xDD,0x54,0x5A,0xB7,0x90,0x9C,0xF4,0x94,0x68,0x65,0x58,0x56,0x53,0x63,0xB4,0xB5,0x64,0xC9,0x4D,0x8E,0xC1,0xC7,0x94,0xED,0x24,0xD1,0x87,0x68,0x53,0x4E,0xAA,0x44,0x1E,0x32,0xDD,0xC4,0x8D,0x93,0x95,0xCF,0x75,0xC5,0x38,0x49,0x73,0x3A,0x2F,0x15,0xAD,0x38,0x33,0xF0,0xB8,0x56,0xB4,0x63,0x3C,0xCF,0xE2,0x4A,0xD0,0xB6,0x08,0xA5,0x9C,0x33,0x64,0x3B,0x2C,0x62,0x76,0x97,0x51,0x9C,0xB0,0x08,0xC7,0x6D,0x12,0x71,0x42,0x42,0x60,0xB6,0xC2,0x4D,0x16,0x8A,0x03,0x96,0x70,0x0B,0x3B,0x88,0xC9,0x48,0xCC,0x2D,0x64,0x3D,0xA0,0xCB};

#define EYE1_PIN 39
#define EYE2_PIN 34
#define SPEAKER_PIN 25

enum LightState {DARK, LIGHT}; 

class LightSpeaker 
{
    static Talkie voice;
    static uint64_t last_debouncing_time, debouncing_time;
    static uint16_t dark_limit;
    static LightState state, last_state;
    static void light_analyze();

    public:
        static uint8_t light_speaker_init();
        static LightState get_light_state();
        static void light_speaker_loop();
        static void say_hard_hug();
        static void say_dark();
        static void say_love();
        static void say_ready();

};

#endif