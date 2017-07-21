#include <Keypad4x4.h>

#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Adafruit_PCD8544.h>

#include <Servo.h>

int servoPin = 4;

Servo servo;

int servoAngle = 0;

char keys[ROWS][COLS] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {12, 10, 9, 8}; //connect to the column pinouts of the keypad

Keypad4x4 keypad = Keypad4x4(makeKeymap(keys), rowPins, colPins);

// Define the pins used to control the LCD module
#define LCD_SCLK    13
#define LCD_DIN     11
#define LCD_DC      5
#define LCD_CS      7
#define LCD_RST     6

Adafruit_PCD8544 display = Adafruit_PCD8544(
        LCD_SCLK, LCD_DIN, LCD_DC, LCD_CS, LCD_RST
);

void setup() {
    Serial.begin(9600);

    // Start the display and set a good contrast
    display.begin();
    display.setContrast(50);
    display.clearDisplay();

    servo.attach(servoPin);
}

void loop() {
    char key = keypad.getKey();

    if (key) {
        Serial.println(key);
        display.print(key);
        display.display();

        if (key == '1') {
            servo.write(45);      // Turn SG90 servo Left to 45 degrees
            delay(1000);          // Wait 1 second
            servo.write(90);      // Turn SG90 servo back to 90 degrees (center position)
            delay(1000);          // Wait 1 second
            servo.write(135);     // Turn SG90 servo Right to 135 degrees
            delay(1000);          // Wait 1 second
            servo.write(90);      // Turn SG90 servo back to 90 degrees (center position)
            delay(1000);
        } else if (key == '2') {
            for (servoAngle = 0; servoAngle < 180; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
            {
                servo.write(servoAngle);
                delay(50);
            }
        } else if (key == '*') {
            for (servoAngle = 0; servoAngle < 1800; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
            {
                servo.write(servoAngle);
                delay(10);
            }
        } else {
            for (servoAngle = 180;
                 servoAngle > 0; servoAngle--)  //now move back the micro servo from 0 degrees to 180 degrees
            {
                servo.write(servoAngle);
                delay(10);
            }
        }
    }
}
