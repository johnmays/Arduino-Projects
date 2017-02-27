/*CIRCUIT IS VERY SIMPLE:
* 3 POTENTIOMETERS HOOKED UP AS FOLLOWS
* WITH ONE RGB LED HOOKED UP AS FOLLOWS(.023 AMPS)
*/
  //constants for pins 
const int redPotPin = A0;
const int greenPotPin = A1;
const int bluePotPin = A2;
const int redLedPin = 11;
const int greenLedPin = 9;
const int blueLedPin = 10;
  //variables for sensor/rgb values
int redValue = 0;
int greenValue = 0;
int blueValue = 0;
int redPotValue = 0;
int bluePotValue = 0;
int greenPotValue = 0;
void setup() {
    //setting pinModes
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
    //reading the pot values
  redPotValue = analogRead(redPotPin);
  greenPotValue = analogRead(greenPotPin);
  bluePotValue = analogRead(bluePotPin);
    //calculating the LED Output Values
  redValue = redPotValue/4;
  greenValue = greenPotValue/4;
  blueValue = bluePotValue/4;
    //Writing the LED Values to their respective pins
  analogWrite(redLedPin, redValue);
  analogWrite(greenLedPin, greenValue);
  analogWrite(blueLedPin, blueValue);
  
}
