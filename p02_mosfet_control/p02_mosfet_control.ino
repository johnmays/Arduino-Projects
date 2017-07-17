/* ~Quick IRF520n MOSFET test with button.
 *  
 * ~Switch should turn open MOSFET's gate
 * 
 * ~CIRCUIT: pushButton w/ 10KΩ pullup on Digital Pin 3,
 * MOSFET's GATE Pin on Digital Pin 2 w/ another 10KΩ pullup 
 * to GND, branching a standard LED's (-) from MOSFET's DRAIN 
 * pin and out through the SOURCE pin.
 * 
 * ~When a (+) signal is applied to the GATE pin, current may
 * flow from SOURCE to DRAIN, bypassing the internal diode, 
 * which does allow current to flow from DRAIN to SOURCE.
 */

const int fetPin = 2;
const int switchPin = 3;
void setup() {
  pinMode(switchPin, INPUT);
  pinMode(fetPin, OUTPUT);

}

void loop() {
  int switchState = digitalRead(switchPin);
  if(switchState){
    digitalWrite(fetPin, HIGH);
  }else{
    digitalWrite(fetPin, LOW);
  }

}
