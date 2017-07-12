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
    pinMode(LED_BUILTIN, OUTPUT);
}

void blink(int val) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(val);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
}

void loop() {
    int i;
    for (i = 200; i < 1500; i += 200) {
        blink(i);
    }
}