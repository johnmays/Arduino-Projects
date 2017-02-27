//LIGHT AND SENSORS: (NAME TO RESPECTIVE PIN)
const int greenLEDPin = 9;
const int blueLEDPin = 10;
const int redLEDPin = 11;
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;
//LIGHTS AND SENSORS:(INITIAL INTEGER VALUES)
int redVal = 0;
int greenVal = 0;
int blueVal = 0;
int redSensorVal = 0;
int greenSensorVal = 0;
int blueSensorVal = 0;
void setup() {
  Serial.begin(9600);  //in order to read serial values from the color sensors
  //PINMODES:
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);

}

void loop() {
  redSensorVal = analogRead(redSensorPin);
  greenSensorVal = analogRead(greenSensorPin);
  blueSensorVal = analogRead(blueSensorPin);
  Serial.print("Sensor Values: \t RED: ");
  Serial.print(redSensorVal);
  Serial.print("\t GREEN: ");
  Serial.print(greenSensorVal);
  Serial.print("\t BLUE: ");
  Serial.println(blueSensorVal);
  redVal = redSensorVal / 4;
  greenVal = greenSensorVal / 4;
  blueVal = blueSensorVal / 4;
  analogWrite(redLEDPin, redVal);
  analogWrite(greenLEDPin, greenVal);
  analogWrite(blueLEDPin, blueVal);

}
