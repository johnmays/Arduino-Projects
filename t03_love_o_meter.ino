const int sensorPin = A0; 
const float baselineTemp = 18.0;
void setup() {
  Serial.begin(9600);  //opens a serial so that I can read values
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){ //sets 3 pins to their LEDs and turns them off
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber,LOW);
  }
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  //next we convert the sensor values to volts
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print("Voltage: ");
  Serial.print(voltage);
  //then we convert the voltage into temperatures by C degrees
  float temperature = (voltage - .5) * 100;
  Serial.print("Temp: ");
  Serial.print(temperature);
    //now we decide which LEDS will be on with an if/else statement
  if(temperature < baselineTemp + 2){
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);  
  }else if(temperature >= baselineTemp + 2 && temperature < baselineTemp + 4){
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }else if(temperature >= baselineTemp + 4 && temperature < baselineTemp + 6){
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
  }else if(temperature >= baselineTemp + 6){
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
}
