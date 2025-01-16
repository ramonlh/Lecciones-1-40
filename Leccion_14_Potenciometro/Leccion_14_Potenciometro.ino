// Placa "ESP32 Dev Module"

#define titleccion "Leccion 14 Potenciometro"

#include <TFT_eSPI.h> // Hardware-specific library

#define anaPin 26

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(anaPin, INPUT_PULLUP);

    // Pantalla TFT
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.println();
  tft.println(titleccion);
  tft.setTextSize(3);
}

void loop(void) 
{
  int valor = analogRead(anaPin);   // mínio=0, máximo = 4095
  tft.fillRect(0,100,200,30,TFT_BLACK);
  tft.setCursor(0,100);
  tft.println(valor);
  delay(250);
}
