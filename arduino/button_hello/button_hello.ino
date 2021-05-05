const int BUTTON_PIN = 2;

int lastState = HIGH;
int currentState;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  /* currentState = digitalRead(BUTTON_PIN); */
  /* if(lastState == LOW && currentState == HIGH) */
  /*   Serial.println("The state changed from LOW to HIGH"); */
  /* lastState = currentState; */
    Serial.println(digitalRead(BUTTON_PIN));
}
