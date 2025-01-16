// Placa "ESP32 Dev Module"

#define titleccion "Lección 7 Pantalla TFT Prueba táctil"

#include <SPI.h>
#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();

void setup(void) {
  Serial.begin(115200);
  Serial.println("\n\nStarting...");
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(0, 0);
  tft.print("Tocar un punto");
}

void loop() {
  uint16_t x, y;
  if (tft.getTouch(&x, &y))
    {
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 50);
    tft.printf("x: %i ", x);
    tft.printf("y: %i ", y);
    tft.printf("z: %i \n", tft.getTouchRawZ());
    tft.setCursor(0, 0);
    tft.print("Tocar un punto");
    }
}
