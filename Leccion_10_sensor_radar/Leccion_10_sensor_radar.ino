// Placa "ESP32 Dev Module"

#define titleccion "Lección 10 Sensor Radar RCWL-0516"

#include <TFT_eSPI.h> // Hardware-specific library
#include "RCWL0516.h"

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
// OUT connected to GPIO26
#define RCWPin 27
RCWL0516 radar(RCWPin);

void setup(void) {
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

  // Initialize sensor radar
  radar.activate();
	tft.println("Radar iniciado");

  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
}


void loop(void) {
  // radar
  int value = digitalRead(RCWPin);
  if (value == HIGH)
    {
    tft.fillCircle(100, 100, 30, TFT_RED);
    Serial.println("ON");
    }
  else
    {
    tft.fillCircle(100, 100, 30, TFT_GREEN );
    Serial.println("OFF");
    }  
  delay(100);
}
