int switchState = 0;
void setup() {
  //setup of pins
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);

  if(switchState == LOW){
    //switch isn't pressed
    //green LED On
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
  }
  else {
    //switch is pressed
    //Green off, red on 4: ON, red on 3: blink
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    delay(250);
    digitalWrite(3, LOW);
    delay(250);
  }

}
