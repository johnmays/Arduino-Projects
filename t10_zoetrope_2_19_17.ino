//switch names to numbers
const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;
//state of program variables
int onOffSwitchState = 0;
int previousOnOffSwitchState  = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState= 0;
//variables for the motor
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;
void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
  digitalWrite(directionSwitchPin, LOW);

}

void loop() {
//checking the switches and pot values
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin)/4;
//Doing things if such values have changed
  if(onOffSwitchState != previousOnOffSwitchState){
   //something has changed
    if(onOffSwitchState == HIGH){
      //motor is on
      motorEnabled = !motorEnabled;
    }
  }
  if(directionSwitchState != previousDirectionSwitchState){
    //something has changed
    if(directionSwitchState == HIGH){
      //changing motor direction
      motorDirection != motorDirection;//0 to 1 or 1 to 0, weird
    }
  }
//changing motor direction w/ control pins based on motorDirection(changed above)
  if(motorDirection == 0){
    //one direction
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    //the other
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
//changing motor speed based on pot
  if(motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
  }else{
    analogWrite(enablePin,0);
  }
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
  
}
