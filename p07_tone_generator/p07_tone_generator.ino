const int ladderPin = A0;
const int piezoPin = 8;
const int notes[] = {262, 294, 330, 349};

const int switchPin = 9;
const int potPin = A1;
 
void setup(){
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
}

void loop(){
  int ladderValue = analogRead(ladderPin);
  //Serial.println(ladderValue);
  if(ladderValue >= 1020){
    tone(piezoPin, notes[0]);
  }else if(ladderValue <= 1010 && ladderValue >= 990){
    tone(piezoPin, notes[1]);
  }else if(ladderValue <= 515 && ladderValue >= 505){
    tone(piezoPin, notes[2]);
  }else if(ladderValue <= 10 && ladderValue >= 5){
    tone(piezoPin, notes[3]);
  }else if(ladderValue < 5){
    noTone(piezoPin);
  }

  int switchState = digitalRead(switchPin);
  if(switchState != 0){
      int potValue = analogRead(potPin);
      int pitch = map(potValue, 0, 1023, 50, 4000);
      Serial.println(pitch);
      tone(piezoPin, pitch, 20);
  }
  
}
