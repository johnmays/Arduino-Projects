/*CIRCUIT:
*16x2 LCD Alphanumerical+ wired into 5V power in ground
*Permanent write mode with GND going to R/W Pin
*Out of loop potentiometer hooked up directly to LCD, controls contrast
*Tilt(LOW, HIGH) Switch wired in with a 10kOhm resistor as a reset switch
*D4-D7 LCD Character Pins wired into D5-D2 on Arduino respectively 
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16,2);
  pinMode(switchPin, INPUT);
  //FIRST MESSAGE:
  lcd.print("Ask the");
  lcd.setCursor(0,1);
  lcd.print("Crystal Ball!");
  delay(2000);
}

void loop() {
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){
    if(switchState == LOW){
        reply = random(10);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("The Ball Says:");
        lcd.setCursor(0,1);
        switch(reply){
          case 0:
          lcd.print("Yes");
          break;
          case 1:
          lcd.print("Most Definitely");
          break;  
          case 2:
          lcd.print("Outlook Good");
          break;  
          case 3:
          lcd.print("Doubtful");
          break;  
          case 4:
          lcd.print("Certainly");
          break;  
          case 5:
          lcd.print("Ask Again");
          break;  
          case 6:
          lcd.print("No");
          break;  
          case 7:
          lcd.print("Definitely Not");
          break;
          case 8:
          lcd.print("Unsure");
          break;      
          case 9:
          lcd.print("?");
          break;
        }
      }  
  }  
  prevSwitchState = switchState;
  delay(500);
}
