int delayTime = 50; //Delay 20 ms
int ledOn = 0; //LED Begins off

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(8, OUTPUT);
}


void loop(){
  if(digitalRead(2) == LOW && ledOn == 0){
    delay(delayTime);
    if(digitalRead(2) == LOW){
      digitalWrite(8, HIGH);
      ledOn = 1;
    }
  }

  if(digitalRead(2) == LOW && ledOn == 1){
    delay(delayTime);
    if(digitalRead(2) == LOW){
      digitalWrite(8, LOW);
      ledOn = 0;
    }
  }
  delay(100);
}
