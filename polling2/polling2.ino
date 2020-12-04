
int ledOn = 0;  // LED starts off
int delayTime = 500; // 50 ms

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(8, OUTPUT); // LED Pin

}

void loop() {
  if(digitalRead(2) == LOW && ledOn == 0){
    delay(delayTime);
    if(digitalRead(2) == LOW){
      digitalWrite(8, HIGH); // LED turns on
      ledOn = 1;
    }
  }
  delay(delayTime);

  if(digitalRead(2) == LOW && ledOn == 1){
    delay(delayTime);
    if(digitalRead(2) == LOW){
      digitalWrite(8, LOW); // LED turns off
      ledOn = 0;
    }
  }
  delay(delayTime);
}
