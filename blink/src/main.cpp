/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void blink(int val) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(val);
    Serial.print("Blink wait time: ");
    Serial.print(val);
    Serial.println(".");
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
}

void loop() {
    int i;
    for (i = 200; i < 1500; i += 200) {
        blink(i);
    }
}