
# Arduino Sound Sensor LED Indicator

## Overview
This Arduino sketch reads audio input from a sound sensor module and uses two LEDs (blue and red) to visually indicate the detected sound level in real time.

## Video Demo
https://github.com/user-attachments/assets/32e7bbf6-f9ab-4af0-be68-a427372417f8

---

## Hardware Requirements

| Component | Quantity |
|---|---|
| Arduino board (Uno, Nano, etc.) | 1 |
| Sound sensor module (with OUT pin) | 1 |
| Blue LED | 10 |
| Red LED | 10 |
| Jumper wires | Several |

---

## Wiring / Pin Connections

| Component | Arduino Pin |
|---|---|
| Sound Sensor OUT | A1 |
| Blue LED | Digital Pin 2 |
| Red LED | Digital Pin 5 |

> **Note:** Connect the sound sensor's VCC to 5V and GND to GND on the Arduino.

---

## How It Works

The sketch continuously reads the sound sensor's analog output (a value from **0 to 1023**, using Arduino's 10-bit ADC) and compares it against two thresholds:

| Variable | Value | Meaning |
|---|---|---|
| `low` | 255 | Minimum threshold — sound detected above ambient noise |
| `high` | 600 | Maximum threshold — loud sound detected |

### LED Behavior

| Condition | Blue LED | Red LED |
|---|---|---|
| Sound level **above** `low` (255) |OFF| ON |
| Sound level **below** `low` (255) | ON | OFF |
| Sound level **below** `high` (600) | ON | OFF |
| Sound level **above** `high` (600) | OFF | ON |

In simple terms:
- **Blue LED ON** → Sound is being detected at a normal or loud level
- **Red LED ON** → Sound is low or absent

---

## Serial Monitor
The sketch outputs real-time sound readings to the **Serial Monitor** at **9600 baud**.

To view:
1. Open the Arduino IDE
2. Go to **Tools → Serial Monitor**
3. Set baud rate to **9600**

Example output:
```
soundState: 312
soundState: 478
soundState: 601
```

---

## Code Summary

```cpp
#define soundState A1   // Sound sensor OUT pin

int soundSensed;        // Stores the current analog reading
int red_leds = 5;       // Red LED on pin 5
int blue_leds = 2;      // Blue LED on pin 2

int low = 255;          // Low sound threshold
int high = 600;         // High sound threshold
```

---

## Cust Download Full Message
Now

