String stringIn = "";
int values[3];

void setup() {
  Serial.begin(115200);
}

void loop() {
  while(Serial.available() == 0){
  }
  stringIn = Serial.readString();
  int space1 = stringIn.indexOf(' ');
  int space2 = stringIn.indexOf(' ', space1 + 1);
  int len = stringIn.length();
  String str1 = stringIn.substring(0, space1);
  String str2 = stringIn.substring(space1 + 1, space2);
  String str3 = stringIn.substring(space2 + 1, len);
  values[0] = str1.toInt();
  values[1] = str2.toInt();
  values[2] = str3.toInt();
  Serial.print(values[0] + 1);
  Serial.print(' ');
  Serial.print(values[1] + 1);
  Serial.print(' ');
  Serial.print(values[2] + 1);
  Serial.print(' ');  
  Serial.println(stringIn);

}
