// constants
const int LED_PIN = 2;
const int BUTTON_PIN = 12;

// global vars
int last;
int current;
int state;

void setup() {
    // init pins
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    // set starting states
    last = HIGH;
    current = HIGH;
    state = LOW;
}

void loop() {
    // re-read button value
    current = digitalRead(BUTTON_PIN);

    // if went from high to low, button was pressed, so toggle state
    if(last == HIGH && current == LOW) {
        state = !state;
    }

    // update last 
    last = current;

    // finally, write state
    digitalWrite(LED_PIN, state);
}
