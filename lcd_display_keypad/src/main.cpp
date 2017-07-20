#include <Keypad.h>

#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Adafruit_PCD8544.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
        {'1','2','3','A'},
        {'4','5','6','B'},
        {'7','8','9','C'},
        {'*','0','#','D'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {12, 10, 9, 8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Define the pins used to control the LCD module
#define LCD_SCLK    13
#define LCD_DIN     11
#define LCD_DC      5
#define LCD_CS      7
#define LCD_RST     6

Adafruit_PCD8544 display = Adafruit_PCD8544(
        LCD_SCLK, LCD_DIN, LCD_DC, LCD_CS, LCD_RST
);

void setup(){
    Serial.begin(9600);

    // Start the display and set a good contrast
    display.begin();
    display.setContrast(50);
    display.clearDisplay();
}

void loop(){
    char key = keypad.getKey();

    if (key){
        Serial.println(key);
        display.print(key);
        display.display();
    }

    delay(1000);
}