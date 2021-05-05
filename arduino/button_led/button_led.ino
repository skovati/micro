// constants
const int LED_PIN = 2;
const int BUTTON_PIN = 12;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  digitalWrite(LED_PIN, !digitalRead(BUTTON_PIN));
}
