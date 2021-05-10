// simple button library to deal with debouncing
#include <Button.h>

// constants
const int BITS = 4;
const int PINS[4] = {2, 3, 4, 5};

// button init
Button mode(12);
Button input(11);

// global vars
int binary[BITS];
int decimal;

void setup() {
    mode.begin();
    input.begin();
    for(int i = 0; i < BITS; i++) {
        pinMode(PINS[i], OUTPUT);
    }
    Serial.begin(9600);
}

void loop() {
    // bring LEDs low to clear previous output
    for(int i = 0; i < BITS; i++) {
        digitalWrite(PINS[i], LOW);
    }

    // if mode button is pressed, read in decimal number
    if(mode.pressed()) {
        // flash LEDs twice to signal input mode
        flashLEDs();
        delay(100);
        flashLEDs();

        readDecimal();
        if(decimal > 15) {
            flashLEDs();
            delay(800);
            flashLEDs();
            delay(800);
            flashLEDs();
            delay(800);
            return;
        }

        // then convert to binary
        decimalToBinary();

        // and then display until 
        while(!mode.pressed()) {
            displayBinary();
        }
    }
}

void readDecimal() {
    decimal = 0;
    while(!mode.pressed()) {
        if(input.pressed()) {
            flashLEDs();
            decimal++;
        }
    }
}

void decimalToBinary() {
    for(int i = BITS-1; i >= 0; i--) {
        binary[i] = decimal % 2;
        decimal /= 2;
    }
}
    
void displayBinary() {
    for(int i = 0; i < BITS; i++) {
        digitalWrite(PINS[i], binary[i]);
    }
}

void flashLEDs() {
    for(int i = 0; i < BITS; i++) {
        digitalWrite(PINS[i], HIGH);
    }
    delay(100);
    for(int i = 0; i < BITS; i++) {
        digitalWrite(PINS[i], LOW);
    }
}
