#include <Servo.h>

const int servoPin = 9;
const int switchPin = 8;
Servo openSesame;
int previousSwitchState;

void setup() {
  openSesame.attach(servoPin);
  openSesame.write(1);

}

void loop() {
  int switchState = digitalRead(switchPin);
  if(switchState != previousSwitchState && previousSwitchState == 0){
    int servoPosition = openSesame.read();
    if(servoPosition != 89){
      openSesame.write(89);
    }else{
      openSesame.write(1);  
    }
  }
  previousSwitchState = switchState;
}
