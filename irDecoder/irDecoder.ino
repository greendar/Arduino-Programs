//irDecoder.ino
//Feb 19, 2023

//From
//https://www.hackster.io/sainisagar7294/arduino-based-ir-remote-decoder-ac67c4

/* Green
I removed the LCD programming
here is a link to a tinkercad version of that runs this code

https://www.tinkercad.com/things/jRSHZsyinPr-powerful-trug/editel?sharecode=OTDbghaj2IJgt8Gtz82rkzqUy1r8XZXW8T9Q_BuGi3g

for tinkercad only 1, 2, and 3 on the controller are used
IR Codes
1     EF10BF00
2     EE11BF00
3     ED12BF00

If you wish to use a different remote or other buttons this project will print out the encoded values on the serial monitor.

Below is the orignial documentation.
*/

/* hello guys here I am using older versions on Ir library so please download and install all the previous version 
 *  the link to download preferred library is: 
 *  This code is made by Sagar saini/ Youtube: sagar networks
 *  Any questions or queries DM me on instagram Saini_sagar_7294.
 *  Explore my website for more interesting projects: www.circuitkicker.com
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
	Serial.print(IrReceiver.decodedIRData.decodedRawData, HEX);
    Serial.print("   ");
    switch(myRawdata){
      case 0xEF10BF00:
        greenOn();
        delay(500);
        break;
      case 0xEE11BF00:
        blueOn();
        delay(500);
        break;
      case 0xED12BF00:
        redOn();
        delay(500);
        break;
      default:
        allOff();
        delay(500);
    }
    irrecv.resume(); // Receive the next value
    delay(200);
 }
}

void greenOn(){
  Serial.println("Green ON");
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
}

void blueOn(){
  Serial.println("Blue  ON");
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
}
void redOn(){
  Serial.println("Red   ON");
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
}

void allOff(){
  Serial.println("All   OFF");
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
}
