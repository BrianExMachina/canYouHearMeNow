#define soundState A1 //attach the data pin labelled OUT to pin A1

int soundSensed;// create a global variable called soundSensed
int blue_leds = 5;
int red_leds = 2;

void setup() {
    pinMode(blue_leds, OUTPUT);
    pinMode(red_leds, OUTPUT);
    Serial.begin(9600);// begin the serial monitor at a rate of 9600 bits per second 9600 BAUD
}

void loop() {
    // the real time readings go in the loop 
    int low = 255;
    int high = 600;
    
    soundSensed = analogRead(soundState);// convert the fluctuating sound to 0-1,023 -10 bits
    
    Serial.print("soundState:"); 
    Serial.println(soundSensed);
    
    if (soundSensed > high){ // loud sound
        digitalWrite(blue_leds, HIGH);
        digitalWrite(red_leds, LOW);
        Serial.print("soundState:"); 
        Serial.println(soundSensed);
    } else if (soundSensed > low){ // medium sound
        digitalWrite(red_leds, HIGH);
        digitalWrite(blue_leds, LOW);
        Serial.print("soundState:"); 
        Serial.println(soundSensed);
    } else { // quiet
        digitalWrite(red_leds, LOW);
        digitalWrite(blue_leds, LOW);
    }
    delay(100);
}
