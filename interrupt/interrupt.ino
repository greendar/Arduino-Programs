const int BTN = 2;
const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;
volatile int selectedLED = RED;

void setup(){
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);

  attachInterrupt(digitalPinToInterrupt(BTN), ISRswap, RISING);
}

void loop(){
  for(int i = 255; i >= 0; i--){
    analogWrite(selectedLED, i);
    delay(10);
  }
  for(int i = 0; i <= 255; i++){
    analogWrite(selectedLED, i);
    delay(10);
  }
  delay(1000);
}

void ISRswap(){
  if(selectedLED == GREEN) selectedLED = RED;
  if(selectedLED == RED) selectedLED = BLUE;
  if(selectedLED == BLUE) selectedLED = GREDD;
}
