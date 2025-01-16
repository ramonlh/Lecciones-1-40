// Placa "ESP32 Dev Module"

#define titleccion "Leccion 40 Teclado I2C 4x4"

#include <TFT_eSPI.h> // Hardware-specific library

#include <Wire.h>
#include <FabricaDigital_MCP23008.h>
#include <Keypad_MCP23008.h>

#define SDApin 13
#define SCLpin 12

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

const byte I2C_ADDRESS = 0x20;
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'H','C','8','4'},
  {'G','B','7','3'},
  {'F','A','6','2'},
  {'E','9','5','1'}
};
byte rowPins[ROWS] = {7, 6, 5, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3, 2, 1, 0}; //connect to the column pinouts of the keypad

Keypad_MCP23008 keypad = Keypad_MCP23008(rowPins, colPins, ROWS, COLS);


void setup(){
  Serial.begin(115200);

    // Pantalla TFT
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.println();
  tft.println(titleccion);
  tft.setTextSize(2);
  tft.setTextColor(TFT_YELLOW);

  Wire.begin(SDApin,SCLpin);

  keypad.begin(I2C_ADDRESS, makeKeymap(keys));
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
}
