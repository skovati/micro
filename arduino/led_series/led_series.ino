// constants
const int LED_1 = 12;
const int LED_2 = 11;
const int LED_3 = 10;

void setup() {
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    red();
    delay(1000);
    green();
    delay(1000);
    blue();
    delay(1000);
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
