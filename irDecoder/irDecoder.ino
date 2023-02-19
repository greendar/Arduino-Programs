//irDecoder.ino
//From
//https://www.hackster.io/sainisagar7294/arduino-based-ir-remote-decoder-ac67c4

//I removed the LCD programming

/* hello guys here I am using older versions on Ir library so please download and install all the previous version 
 *  the link to download preferred library is: 
 *  This code is made by Sagar saini/ Youtube: sagar networks
 *  Any questions or queries DM me on instagram Saini_sagar_7294.
 *  Explore my website for more interesting projects: www.circuitkicker.com
 */

//IR CODES
/*
1     EF10BF00
2     EE11BF00
3     ED12BF00
*/

//irDecoder.ino
//From
//https://www.hackster.io/sainisagar7294/arduino-based-ir-remote-decoder-ac67c4

//I removed the LCD programming

/* hello guys here I am using older versions on Ir library so please download and install all the previous version 
 *  the link to download preferred library is: 
 *  This code is made by Sagar saini/ Youtube: sagar networks
 *  Any questions or queries DM me on instagram Saini_sagar_7294.
 *  Explore my website for more interesting projects: www.circuitkicker.com
 */

//IR CODES
/*
1     EF10BF00
2     EE11BF00
3     ED12BF00
*/

//irDecoder.ino
//From
//https://www.hackster.io/sainisagar7294/arduino-based-ir-remote-decoder-ac67c4

//I removed the LCD programming

/* hello guys here I am using older versions on Ir library so please download and install all the previous version 
 *  the link to download preferred library is: 
 *  This code is made by Sagar saini/ Youtube: sagar networks
 *  Any questions or queries DM me on instagram Saini_sagar_7294.
 *  Explore my website for more interesting projects: www.circuitkicker.com
 */

//IR CODES
/*
1     EF10BF00
2     EE11BF00
3     ED12BF00
*/


#include <IRremote.h>

const int RECV_PIN=6;
const int red = 3;
const int blue = 4;
const int green = 5;

int signalIn;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true); //NOT SURE WHAT THIS DOES
}

void loop() {
 if (IrReceiver.decode()) {
    auto myRawdata= IrReceiver.decodedIRData.decodedRawData;
    if(myRawdata == 0xEF10BF00){
      greenOn();
    }else if(myRawdata == 0xEF11BF00){
      blueOn();
    }else if(myRawdata == 0xEF12BF00){
      redOn();
    } else {
      allOff();
    }
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    irrecv.resume(); // Receive the next value
    delay(100);
 }
}

void greenOn(){
  Serial.println("Green ON");
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
}

void blueOn(){
  Serial.println("Blue ON");
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
}
void redOn(){
  Serial.println("Red ON");
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
}

void allOff(){
  Serial.println("All OFF");
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
}