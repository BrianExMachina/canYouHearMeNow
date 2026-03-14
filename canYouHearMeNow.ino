    #define soundState A1 //attach the data pin labled OUT to pin A1
    
    int soundSensed;// create a global variable called soundSensed
    int red_leds = 5;

    int blue_leds = 2;

void setup() {
    pinMode(blue_leds, OUTPUT);
   pinMode(red_leds, OUTPUT);
   Serial.begin(9600);// begin the serial monitor at a rate of 9600 buts per second 9600 BAUD

}

void loop() {
  // the real time readings go in the loop 
   
  int low = 255;
  
  int high = 1023;

   soundSensed = analogRead(soundState);// convert the fluctuating sound to 0-1,023 -10 bits
  

  Serial.print("soundState:"); 
  Serial.println(soundSensed);

  
   
if (soundSensed > low ){ 

     digitalWrite(blue_leds, HIGH);
     Serial.print("soundState low:"); 
     Serial.println(soundSensed);
   
}else{
   delay(100);
      digitalWrite(blue_leds, LOW);
      digitalWrite(red_leds, HIGH);
      delay(100);
   }

 if (soundSensed < high){
     digitalWrite(red_leds, HIGH);
  Serial.print("soundState high:"); 
  
  Serial.println(soundSensed);
   
   }else{
    delay(100);
      digitalWrite(red_leds, LOW);
      digitalWrite(blue_leds, HIGH);
      delay(100);
   }


}
