// constants
const int LED_1 = 12;
const int LED_2 = 11;
const int LED_3 = 10;

// global vars
int del;

void setup() {
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    Serial.begin(9600);
    del = 500;
}

void loop() {
    while(del < 1000) {
        del += 50;
        Serial.println("under 1000");
        display();
    }
    while(del > 100) {
        del -= 50;
        Serial.println("over 100");
        display();
        display();
    }
}

void display() {
    red();
    delay(del);
    green();
    delay(del);
    blue();
    delay(del);
}

void red() {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
}

void green() {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
}

void blue() {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, HIGH);
}
