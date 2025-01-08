#ifndef HUGS_HPP
#define HUGS_HPP

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_BMP085.h>

#define MOTOR1_PIN 26
#define MOTOR2_PIN 27

enum HuggingState {NO_HUG, HUG, HARD_HUG};

class Hugs 
{
    // for sensor
    static uint32_t no_hug_limit, simple_hug_limit, hard_hug_limit; 
    static HuggingState state, last_state;
    static uint64_t debouncing_time;
    static uint64_t last_debouncing_time;
    static Adafruit_BMP085 pressure_sensor;

    // for motors
    static uint64_t start_hug_time;
    static uint64_t hug_time;
    static uint8_t hug_simulation_on;
    static void hug_simulation();
    static void sensor_analyze();

    public:
        static uint8_t hugs_init();
        static void hugs_loop();
        static void start_hug();
        static HuggingState get_sensor_state();
};

#endif