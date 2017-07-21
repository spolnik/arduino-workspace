#ifndef KEYPAD_H
#define KEYPAD_H

#include "Key.h"

#define OPEN LOW
#define CLOSED HIGH

typedef char KeypadEvent;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef struct {
    byte rows;
    byte columns;
} KeypadSize;

#define LIST_MAX 10		// Max number of keys on the active list.
#define MAPSIZE 10		// MAPSIZE is the number of rows (times 16 columns)
#define makeKeymap(x) ((char*)x)

#define ROWS 4
#define COLS 4

class Keypad4x4 : public Key {
public:
    Keypad4x4(char *userKeymap, byte *row, byte *col);

    virtual void pin_mode(byte pinNum, byte mode) { pinMode(pinNum, mode); }
    virtual void pin_write(byte pinNum, boolean level) { digitalWrite(pinNum, level); }
    virtual int  pin_read(byte pinNum) { return digitalRead(pinNum); }

    uint bitMap[MAPSIZE];	// 10 row x 16 column array of bits. Except Due which has 32 columns.
    Key key[LIST_MAX];
    unsigned long holdTimer;

    char getKey();
    bool getKeys();
    KeyState getState();
    void begin(char *userKeymap);
    bool isPressed(char keyChar);
    void setDebounceTime(uint);
    void setHoldTime(uint);
    void addEventListener(void (*listener)(char));
    int findInList(char keyChar);
    int findInList(int keyCode);
    char waitForKey();
    bool keyStateChanged();
    byte numKeys();

private:
    unsigned long startTime;
    char *keymap;
    byte *rowPins;
    byte *columnPins;
    KeypadSize sizeKpd;
    uint debounceTime;
    uint holdTime;
    bool single_key;

    void scanKeys();
    bool updateList();
    void nextKeyState(byte n, boolean button);
    void transitionTo(byte n, KeyState nextState);
    void (*keypadEventListener)(char);
};

#endif