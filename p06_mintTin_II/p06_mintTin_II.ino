#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12,11,5,4,3,2); //  Init LCD, correlating to LCD Pins: 4,6,11,12,13,14
const int switchPin = 10;
int previousSwitchState = 0;
const int backlightPin = 13;
boolean backlight = true;
const int servoPin = 9;
Servo openSesame;


void setup() {
  lcd.begin(16,2); //Init coordinates
  lcd.print("Hello, World");
  pinMode(switchPin, INPUT);
  pinMode (backlightPin, OUTPUT);
  digitalWrite(backlightPin, HIGH);

  openSesame.attach(servoPin);
  openSesame.write(89);

  delay(1000);
}

void loop() {
  int switchState = digitalRead(switchPin);
  if(previousSwitchState != switchState && switchState == 0){
    if(backlight == true){
      digitalWrite(backlightPin, HIGH);
      backlight = false;
      openSesame.write(89);
    }else if (backlight == false){
      digitalWrite(backlightPin, LOW);
      backlight = true;
      openSesame.write(1);
    }    
  }
  previousSwitchState = switchState;
}
