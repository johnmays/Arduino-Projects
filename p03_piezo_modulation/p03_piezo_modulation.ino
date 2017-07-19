/* This program is just meant to test different square waves on the
 * piezo at different frequencies and duty cycles
 * 
 */
//const int switchPin = 2;
const int piezoPin = 9;
//const int potPin = 0;


void setup() {
  //pinMode(switchPin, INPUT);

}

void loop() {
  //int potValue = analogRead(potPin);
  //int piezoValue = potValue / 4;
  //int switchState = digitalRead(switchPin);
  //if(switchState == 0){
    //analogWrite(piezoPin, piezoValue);
  //}else{
    //analogWrite(piezoPin, 254);
    //delay(1000);
    //analogWrite(piezoPin, 0);
    //delay(1000);
  //}
   analogWrite(piezoPin, 254);
   delay(1000);
   analogWrite(piezoPin, 0);
   delay(1000);
  
}
