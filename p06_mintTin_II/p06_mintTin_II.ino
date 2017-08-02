#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2); //  Init, correlating to LCD Pins: 4,6,11,12,13,14
const int switchPin = 10;
int previousSwitchState = 0;
boolean backlight = true;

void setup() {
  lcd.begin(16,2); //Init coordinates
  lcd.print("Hello, World");
  pinMode(switchPin, INPUT);

}

void loop() {
  //LATER, fu M
  int switchState = digitalRead(switchPin);
  if(previousSwitchState != switchState && switchState == 0){
    if(backlight == true){
      digitalWrite(8, HIGH);
      backlight = false;
    }else if (backlight == false){
      digitalWrite(8, LOW);
      backlight = true;
    }    
  }
  previousSwitchState = switchState;
}
