// Placa "ESP32 Dev Module"

#define titleccion "Leccion 9 Sensor Presencia"

#include <TFT_eSPI.h> // Hardware-specific library

#define presPin 22

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(presPin, INPUT_PULLUP);

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
  int valor = digitalRead(presPin);
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
