// Placa "ESP32 Dev Module"

#define titleccion "Lección 18 Sensor de sonido-Microfono"

#define anaPin 21
#define digPin 22

#include <TFT_eSPI.h> 

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  // Pantalla TFT
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(0, 0);
  tft.setTextSize(2);

  pinMode(anaPin, INPUT);
  pinMode(digPin, INPUT_PULLDOWN);
}

void loop(void) {
  Serial.print(digitalRead(digPin));  Serial.print(",");
  Serial.println(analogRead(anaPin)); 
  delay(100);
}
