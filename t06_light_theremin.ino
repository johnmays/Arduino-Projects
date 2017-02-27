
/*  [PLEASE READ]
 *   THIS CODE WILL NOT WORK UNLESS YOU GO AGAINST THE INSTRUCTIONS
 *   AND HOOK A BUTTON/ SWITCH POWER UP TO DIGITAL PIN 2,
 *   THE SWITCH SHOULD HAVE A 10 kOhms RESISTOR(BR,BL,OR,GLD)
 */
int switchState = 0;
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;
const int switchPin = 2;
void setup() {
  //coordinating pins
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(ledPin, HIGH);
  //calibration
  while(millis() < 5000){
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;  
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  //the switch
  switchState = digitalRead(switchPin);
  //determining piezo sounds
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  if(switchState == LOW){
    //switch is not pressed: make noise
    tone(8,pitch, 20);
    delay(10);
  }
}
