# HugBuddy

## General description
HugBuddy is an innovative pair of teddy bears designed to simulate the comforting sensation of a hug and foster emotional connections, even when loved ones are far apart. Equipped with cutting-edge technology, HugBuddy combines touch, sound, and interactive behavior to create a unique and meaningful communication experience.
### How it works?
When one HugBuddy is hugged, an internal pressure sensor detects the embrace and triggers a Wi-Fi signal to its counterpart. The paired HugBuddy responds by vibrating, replicating the sensation of a hug. To add personality and emotional depth, the bears are equipped with speakers that play pre-recorded messages, such as “You hugged me too hard.” Additionally, HugBuddy features a photoresistor to detect when the lights are turned off, prompting the bear to vibrate and say, “I’m scared,” fostering a sense of companionship and care.
### What was the inpiration?
HugBuddy was inspired by the universal need for human connection and the comfort offered by a simple hug. By integrating the timeless charm of teddy bears with modern technology, HugBuddy aims to create a tangible link between loved ones, bridging emotional gaps in long-distance relationships.
### Why it's useful?
HugBuddy is more than a toy—it’s a step forward in human-device interaction. This project explores the potential of technology to simulate emotional closeness, offering comfort and companionship to individuals separated by distance. HugBuddy could benefit children, long-distance couples, or anyone seeking a sense of connection, while also advancing research in emotional robotics and remote interaction.


## Hardware Design

### Functionality
![Block diagram](./images/diagram.png)

#### ESP32
- micro controller for this project
- control all the other blocks
- connect over Wi-Fi with the other bear
- power by 3 AA batteries

#### Vibration motor
-  use to simulate the vibration of the teddy bear
- we need to because the motor is very small (1 cm)
- control using digital pins

#### Keyestudio 8002b
- use to tell some default phrases
- control with an analog pin

#### BMP180
- use to detect the pressure when the bear is hugged
- connect via I2C

#### Photocell
- use to determinate the change of the light (to implement the fear of darkness)
- need 2 to be used like eyes
- connect over an analog pin 

#### Pulse sensor
- use to read the pulse of a person in order to simulate it in the other bear
- connect over an analog pin

#### Batteries
- use to power the ESP32 and the other blocks

### Implementation
![](./images/schita_bb.png)

#### Vibration motor
- work with 80mA, but the ESP32 pins provide just 20-30mA
- add a NPN transistor to can provide a bigger current intensity
- wire ESP32 pin with the base of the NPN transistor, add a resistor to control the current intensity (otherwise the NPN transistor can be burn)
- when the base receive current will close the connection between the vibration motor and the ground pin
- the ESP32 pins for connection can be any output digital pin (do not need an analog pin)
- [wiring tutorial](https://deepbluembedded.com/arduino-vibration-motor-code-circuit/)

#### Keyestudio 8002b
- do not need additional components
- need to be wire to an analog pin in order to can use `tune()` function
- [wiring tutorial](https://www.keyestudio.com/blog/how-to-use-8002b-audio-power-amplifier-with-esp32-225)

#### BPM180
- communicate with ESP32 using I2C
- wire the SDA pin with the ESP32 SDA pin (GPIO 21) and the SCL pin with the ESP32 SCL pin (GPIO 22)
- [wiring tutorial](https://randomnerdtutorials.com/esp32-with-bmp180-barometric-sensor/)

#### Photocell
- wire a photocell with an resistor (in order to scale the current intensity)
- connect the circuit at 3.3V and at ground
- read the value of the photocell resistance using an analog input pin from ESP32 (GPIO39, GPIO34)
- [wiring tutorial](https://esp32io.com/tutorials/esp32-light-sensor)

#### Pulse sensor
- wire at 3.3V and ground pins
- wire the signal pin to an analog input pin from ESP32 (GPIO 36)
- [wiring tutorial](https://microcontrollerslab.com/pulse-sensor-esp32-tutorial/)

#### Battery
- to power the ESP32 and all the other blocks
- connect the + to VIN from ESP32 and the - to GND
- [wiring tutorial](https://linuxhint.com/power-esp32-battery/)

### Bill of materials
The proprieties of the component were generated using Fritzing app. The whole project can be find [here](./images/schita.fzz)

| Amount | Part Type                                      | Properties                                                                                                                                                                | Datasheet                                                                                                                                                 | Image         |
|--------|------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|---------------|
| 3      | Battery Holders                               | voltage 1.2V; package battery-aa-kit; variant aa-kit; internal resistance 0.1Ω                                                                                           |                                                                                                                                                          |               |
| 2      | NPN-Transistor                                | package TO92 [THT]; type NPN (EBC)                                                                                                                                       | [Datasheet](https://www.sparkfun.com/datasheets/Components/BC546.pdf)                                                                                   | <img src="./images/bc547.png" style="height: 200px;" />     |
| 1      | Barometric Pressure Sensor - BMP180 Breakout (GY-68) | chip BMP180; variant variant 3                                                                                                                                           | [Datasheet](https://cdn-shop.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf)                                                                            | <img src="./images/bpm180.png" style="height: 200px;" />    |
| 1      | ESP32S-HiLetgo                                | variant HiLetgo; type NudeMCU-32S; pins 38; part # ESP32S-HiLetgo                                                                                                       | [Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf) [Pinout Reference](https://lastminuteengineers.com/esp32-pinout-reference/) | <img src="./images/esp32.png" style="height: 200px;" />     |
| 1      | Keyestudio 8002B                              | variant variant 1                                                                                                                                                        | [Datasheet 1](https://wiki.keyestudio.com/KS0374_keyestudio_Power_Amplifier_Module) [Datasheet 2](https://www.keyestudio.com/blog/how-to-use-8002b-audio-power-amplifier-with-esp32-225) | <img src="./images/8002b.png" style="height: 200px;" />     |
| 2      | Photocell (LDR)                               | dark resistance @0.01lx 300kΩ; package THT; power 0.25W; light resistance @100lx 400Ω; luminance 10lx                                                                   | [Datasheet](https://www.mouser.com/datasheet/2/737/photocells-932884.pdf?srsltid=AfmBOordjdsNJ4Icbo64gmVYUtEhyTft1gwpifDJjs1EM_v42nWLPoZW)                | <img src="./images/photocell.png" style="height: 200px;" /> |
| 1      | Pulse Sensor                                  | package SIP; variant variant 1                                                                                                                                           | [Datasheet 1](https://cdn-shop.adafruit.com/product-files/1093/PulseSensorAmpedGettingStartedGuide.pdf) [Datasheet 2](https://www.optimusdigital.ro/ro/index.php?controller=attachment&id_attachment=447&srsltid=AfmBOoq_gU5Ko2xSBZUHxwFK_QClgCfg95LmCOTURWX_54XSfYMxzBmh) | <img src="./images/pulse.png" style="height: 200px;" />     |
| 2      | 330Ω Resistor                                 | tolerance ±5%; package 0603 [SMD]; resistance 330Ω                                                                                                                       | [Datasheet](https://www.mouser.com/datasheet/2/414/GP-1671375.pdf?srsltid=AfmBOooitb8up3LF_TTmedORVxlq6UULtGa8dP_f_AtcUQPtNcRgwpDB)                       | <img src="./images/330r.png" style="height: 200px;" />      |
| 2      | 10kΩ Resistor                                 | tolerance ±5%; package 0603 [SMD]; resistance 10kΩ                                                                                                                       | [Datasheet](https://www.mouser.com/datasheet/2/414/GP-1671375.pdf?srsltid=AfmBOooitb8up3LF_TTmedORVxlq6UULtGa8dP_f_AtcUQPtNcRgwpDB)                       | <img src="./images/10kr.png" style="height: 200px;" />      |
| 2      | Vibration Motor- ROB-08449                    | package vibe-motor-10mm; variant 10mm                                                                                                                                    | [Datasheet 1](https://www.mouser.com/datasheet/2/321/28821-Flat-Coin-Vibration-Motor-Documentation-369707.pdf?srsltid=AfmBOorlhJBz6bqxh24OIA6QHMYG4CS-eSHEXZp5raEHkIJkOgh_TKIe) [Datasheet 2](https://asset.conrad.com/media10/add/160267/c1/-/en/002298375DS00/datasheet-2298375-tru-components-tc-9193500-5-ks.pdf) | <img src="./images/vibration.png" style="height: 200px;" />             |

### Physical setup

#### Vibration modules - [video](https://youtube.com/shorts/6yC7BauQsrw?feature=share)
<img src="./images/vibration-module.jpg" width="33%" />
<img src="./images/vibration-setup.jpeg" width="33%" />
<img src="./images/vibration-modules.jpg" width="33%" />

---

#### Keyestudio 8002b - [video](https://youtube.com/shorts/pHokNqjklVg?feature=share)
<img src="./images/speaker-module.jpg" style="width: 50%; margin-left: 25%; margin-right: 25%" />

---

#### BMP180 - [video](https://youtube.com/shorts/UoWgT8tCj3w?feature=share)
<img src="./images/bmp180-setup.jpg" style="width: 49%" />
<img src="./images/bpm180-module.jpg" style="width: 49%" />

---

#### Photocell - [video](https://youtube.com/shorts/r_aeARwO2eg?feature=share)
<img src="./images/photocell-module.jpg" style="width: 33%;" />
<img src="./images/photocell-setup.jpeg"  style="width: 33%;" />
<img src="./images/photocell-modules.jpg" style="width: 33%;" />

---

#### Pulse sensor
<img src="./images/pulse-module.jpg" style="width: 50%; margin-left: 25%; margin-right: 25%"/>

---

  


## Software Design

## Results

## Conclusions

## Journal
