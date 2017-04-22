const int switchPin = 8;
const int DELAY = 20;
unsigned long previousTime= 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 1000;
void setup() {
  for(int x = 2; x < 8; x++){
    pinMode(x, OUTPUT);  
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  if(currentTime-previousTime > interval){
   previousTime = currentTime;
   digitalWrite(led, HIGH);
   led++;
   if(led == 7){
    for(int i = 0; i < 10; i++){
      for(int x = 2; x < 8; x++){
         digitalWrite(x, HIGH);
         delay(DELAY);
      }
      for(int x = 2; x < 8; x++){
         digitalWrite(x, LOW);
         delay(DELAY);
      }
      
    }
    
   }  
 }
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){
    for(int x = 2; x < 8; x++){
      digitalWrite(x, LOW);
    }  
    led = 2;
    previousTime = currentTime;
  }
  prevSwitchState = switchState;
}
