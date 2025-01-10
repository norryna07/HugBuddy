#include "Hugs.hpp"

uint32_t Hugs::no_hug_limit = 100000, Hugs::simple_hug_limit = 110000, Hugs::hard_hug_limit = 115000; 
HuggingState Hugs::state = NO_HUG, Hugs::last_state = NO_HUG;
uint64_t Hugs::debouncing_time = 1000, Hugs::last_debouncing_time;
Adafruit_BMP085 Hugs::pressure_sensor;

uint64_t Hugs::start_hug_time, Hugs::hug_time = 2000;
uint8_t Hugs::hug_simulation_on = false;

uint8_t Hugs::hugs_init() 
{
    // initialize the sensor 
    // try to initialize it 3 times, if do not work return 0
    for (int i = 0; i < 3 && !pressure_sensor.begin(); ++i) {
        Serial.println("Could not find a valid BMP085/BMP180 sensor, check wiring!");
        delay(1000);
    }
    if (!pressure_sensor.begin()) 
    {
        Serial.println("Sensor not found!");
        return 0;
    }

    // initialize the motors
    pinMode(MOTOR1_PIN, OUTPUT);
    pinMode(MOTOR2_PIN, OUTPUT);
    digitalWrite(MOTOR1_PIN, LOW);
    digitalWrite(MOTOR2_PIN, LOW);

    Hugs::last_debouncing_time = millis();

    no_hug_limit = pressure_sensor.readPressure() + 5000;
    simple_hug_limit = no_hug_limit + 10000;
    hard_hug_limit = simple_hug_limit + 5000;

    return 0;
}

void Hugs::hugs_loop() 
{
    Hugs::hug_simulation();
    Hugs::sensor_analyze();
}

void Hugs::start_hug() 
{
    // this function will set the simulation to on
    if (!Hugs::hug_simulation_on) {
        Serial.println("HUG START");
        Hugs::hug_simulation_on = true;
        Hugs::start_hug_time = millis();
        digitalWrite(MOTOR1_PIN, HIGH);
        digitalWrite(MOTOR2_PIN, HIGH);
    }
}

void Hugs::hug_simulation() 
{
    if (!hug_simulation_on) return;
    Serial.println(millis() - start_hug_time);
    if (millis() - start_hug_time > hug_time) {
        hug_simulation_on = false;
        digitalWrite(MOTOR1_PIN, LOW);
        digitalWrite(MOTOR2_PIN, LOW);
        return;
    }
}

HuggingState Hugs::get_sensor_state() {
    return Hugs::state;
}

void Hugs::sensor_analyze() 
{
    uint32_t value = pressure_sensor.readPressure();
    HuggingState current_state;
    Serial.println(value);
    if (value < Hugs::no_hug_limit) current_state = NO_HUG;
    else if (value < Hugs::simple_hug_limit) current_state = HUG;
         else if (value < Hugs::hard_hug_limit) current_state = HARD_HUG;
              else current_state = NO_HUG;
    
    if (current_state != last_state) {
        last_debouncing_time = millis();
    }
    if (millis() - last_debouncing_time > debouncing_time) {
        if (current_state != state) {
            state = current_state;
        }
    }
    last_state = current_state;
}