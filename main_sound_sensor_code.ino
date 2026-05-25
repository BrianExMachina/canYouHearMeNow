#define soundState A1 // attach the data pin labeled OUT to pin A1

int soundSensed;      // stores the real-time sound reading (0-1023)

int blue_leds = 2;

int red_leds = 5;

void setup() {
    pinMode(blue_leds, OUTPUT);
    
    pinMode(red_leds, OUTPUT);
    
    Serial.begin(9600);
}

void loop() {
    int low  = 255; // below this = quiet
    
    int high = 600; // above this = loud

    soundSensed = analogRead(soundState); // read sound sensor (0-1023)

    Serial.print("soundSensed: ");
    Serial.println(soundSensed);

    if (soundSensed < low) {
        digitalWrite(blue_leds, HIGH);
    } else {
        digitalWrite(blue_leds, LOW);
    }

    if (soundSensed > high) {
        digitalWrite(red_leds, HIGH);
    } else {
        digitalWrite(red_leds, LOW);
        digitalWrite(blue_leds, HIGH);
    }

    delay(100);
}
