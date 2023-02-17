// from pg 159 Blum Exploring Arduino


const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

int val1;
int val2;
int val3;

void setup(){
    Serial.begin(9600);
    Serial.setTimeout(10);

    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

    //check whether RGB LED is common cathode or anode
    //if common anode change
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
}

void loop(){
    if (Serial.available() > 0){
        //expect to receive 3 integers over serial
        //parsInt know full integer is received once comma or newline is seen
        val1 = Serial.parseInt();
        val2 = Serial.parseInt();
        val3 = Serial.parseInt();

        //clear out remaining buffer contents
        while (Serial.available()){
            Serial.read();}
    }
    int val1c = constrain(val1, 0, 100);
    int val2c = constrain(val2, 0, 100);
    int val3c = constrain(val3, 0, 100);

    //if common anode change
    int rval = map(val1c, 0, 100, 0, 255);
    int gval = map(val2c, 0, 100, 0, 255);
    int bval = map(val3c, 0, 100, 0, 255);

    analogWrite(RED, rval);
    analogWrite(GREEN, gval);
    analogWrite(BLUE, bval);

    Serial.println("Red:    "  + String(val1c) +"%");
    Serial.println("Green:  "  + String(val2c) +"%");
    Serial.println("Blue:   "  + String(val3c) +"%\n");
}


