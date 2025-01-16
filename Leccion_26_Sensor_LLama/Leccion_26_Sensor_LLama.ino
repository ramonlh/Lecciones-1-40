// Placa "ESP32 Dev Module"

#define titleccion "Lección 26 Sensor LLama"

#define digPin 14

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

  pinMode(digPin, INPUT_PULLDOWN);
}

void loop(void) {
  int valor = digitalRead(digPin);
  if (valor == HIGH)
    {
    tft.fillCircle(100, 100, 30, TFT_RED);
    Serial.println("ON");
    }
  else
    {
    tft.fillCircle(100, 100, 30, TFT_GREEN );
    Serial.println("OFF");
    }
  delay(250);
}
