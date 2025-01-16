// Placa "ESP32 Dev Module"

#define titleccion "Lección 8 Pantalla TFT"

#include <TFT_eSPI.h> // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

void setup(void) {
  Serial.begin(115200);
  Serial.println();
  Serial.println(titleccion);
  // Pantalla TFT
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.println("Hola");
  tft.setTextSize(2);
  tft.println("Hola");
  tft.setTextSize(3);
  tft.println("Hola");
  tft.setTextSize(4);
  tft.println("Hola");
  tft.setTextSize(5);
  tft.println("Hola");
  tft.setTextSize(6);
  tft.println("Hola");
  tft.setTextSize(7);
  tft.println("Hola");
}

void loop(void) {
}
