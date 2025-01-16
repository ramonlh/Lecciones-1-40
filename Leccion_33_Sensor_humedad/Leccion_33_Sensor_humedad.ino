// Placa "ESP32 Dev Module"

#define titleccion "Leccion 33 Sensor de Humedad"

#include <TFT_eSPI.h> // Hardware-specific library

#define digPin 26
#define anaPin 25

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(digPin, INPUT_PULLUP);
  pinMode(anaPin, INPUT);

    // Pantalla TFT
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  tft.println();
  tft.println(titleccion);
}

void loop(void) 
{
  int valordig = digitalRead(digPin);
  int valorana = analogRead(anaPin);
  if (valordig == HIGH)
    {
    tft.fillCircle(100, 100, 30, TFT_RED);
    Serial.println(valorana);
    }
  else
    {
    tft.fillCircle(100, 100, 30, TFT_GREEN );
    Serial.println(valorana);
    }
  delay(500);
}
