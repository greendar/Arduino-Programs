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


#include <IRremote.h>

const int RECV_PIN=6;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true); //NOT SURE WHAT THIS DOES
}

void loop() {
 if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    irrecv.resume(); // Receive the next value
 delay(100);
 }
}
