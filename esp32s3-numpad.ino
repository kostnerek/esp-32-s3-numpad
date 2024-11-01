#include <BleCombo.h>
#include <Keypad.h>

#define KEY_NUM_0 0xEA
#define KEY_NUM_1 0xE1
#define KEY_NUM_2 0xE2
#define KEY_NUM_3 0xE3
#define KEY_NUM_4 0xE4
#define KEY_NUM_5 0xE5
#define KEY_NUM_6 0xE6
#define KEY_NUM_7 0xE7
#define KEY_NUM_8 0xE8
#define KEY_NUM_9 0xE9
#define KEY_NUM_SLASH 0xDC
#define KEY_NUM_ASTERISK 0xDD
#define KEY_NUM_MINUS 0xDE
#define KEY_NUM_PLUS 0xDF
#define KEY_NUM_ENTER 0xE0
#define KEY_NUM_PERIOD 0xEB

const int ROW_NUM = 4;    // Four rows
const int COLUMN_NUM = 4; // Four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {KEY_NUM_0, KEY_NUM_1, KEY_NUM_2, KEY_NUM_3},
  {KEY_NUM_4, KEY_NUM_5, KEY_NUM_6, KEY_NUM_7},
  {KEY_NUM_8, KEY_NUM_9, KEY_NUM_SLASH, KEY_NUM_ASTERISK},
  {KEY_NUM_MINUS, KEY_NUM_PLUS, KEY_NUM_ENTER, KEY_NUM_PERIOD},
  
};

byte pin_rows[ROW_NUM] = {0, 1, 2, 3};       // Connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {4, 5, 6, 8};  // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

int x2i(char *s) 
{
  int x = 0;
  for(;;) {
    char c = *s;
    if (c >= '0' && c <= '9') {
      x *= 16;
      x += c - '0'; 
    }
    else if (c >= 'A' && c <= 'F') {
      x *= 16;
      x += (c - 'A') + 10; 
    }
    else break;
    s++;
  }
  return x;
}
void setup() {
  Serial.begin(115200);
  Serial.println("Starting work!");
  Keyboard.begin();
}

void loop() {
  char key = keypad.getKey();
  if(Keyboard.isConnected()) {
    // Keyboard.println("Hello World");
     if (key) {
      Serial.print("KEY:");
      // Keyboard.write(0xCA);
      char *keyPtr = &key;
      Keyboard.write(key);
      Serial.println(key);
      Serial.println(x2i(keyPtr));
      //delay(50);
      //Keyboard.release(HEX);
    }
  }
  
}
