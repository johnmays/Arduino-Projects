const int ledArrayPinOne = 8;
const int ledArrayPinTwo = 7;
const int ledArrayPinThree = 6;
const int ledArrayPinFour = 5;
const int ledArrayPinFive = 4;
const int detectedLedPin = 3;
const int detectorPin = 5;

int detectorSignal = 0;
int lowestActivityValue = 35;


void setup(){
  pinMode(ledArrayPinOne ,OUTPUT);  
  pinMode(ledArrayPinTwo ,OUTPUT);
  pinMode(ledArrayPinThree ,OUTPUT);
  pinMode(ledArrayPinFour ,OUTPUT);
  pinMode(ledArrayPinFive ,OUTPUT);
  pinMode(detectedLedPin ,OUTPUT);
  //pinMode(detectorPin ,INPUT);

  Serial.begin(9600);
  
}

void loop(){
  detectorSignal = analogRead(detectorPin);
  constrain(detectorSignal, 1, 100);
  map(detectorSignal,1,100,1,255); 
  Serial.println(detectorSignal);


  if(detectorSignal >= lowestActivityValue){
    digitalWrite(detectedLedPin, HIGH);
     
  }else{
   digitalWrite(detectedLedPin, LOW);  
  }
  displayOnArray();
;;
}

void displayOnArray(){
  if(detectorSignal >= lowestActivityValue){
    digitalWrite(ledArrayPinOne, HIGH);
  }else{
    digitalWrite(ledArrayPinOne, LOW);
  }
  if(detectorSignal > 51){
    digitalWrite(ledArrayPinTwo, HIGH);
  }else{
    digitalWrite(ledArrayPinTwo, LOW);
  }
  if(detectorSignal > 102){
    digitalWrite(ledArrayPinThree, HIGH);
  }else{
    digitalWrite(ledArrayPinThree, LOW);
  }
  if(detectorSignal > 153){
    digitalWrite(ledArrayPinFour, HIGH);
  }else{
    digitalWrite(ledArrayPinFour, LOW);
  }
  if(detectorSignal > 204){
    digitalWrite(ledArrayPinFive, HIGH);
  }else{
    digitalWrite(ledArrayPinFive, LOW);
  }   
  
}
