// Placa "ESP32 Dev Module"

#define titleccion "Leccion 34 Sensor Ultrasonidos"

#include <TFT_eSPI.h> // Hardware-specific library

const int obstPin = 14;

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(obstPin, INPUT);

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
}

void loop(void) 
{
  int valordig = digitalRead(obstPin);
  if (valordig == HIGH)
    {
    tft.fillCircle(100, 100, 30, TFT_RED);
    Serial.println(valordig);
    }
  else
    {
    tft.fillCircle(100, 100, 30, TFT_GREEN );
    Serial.println(valordig);
    }
  delay(10);
}
