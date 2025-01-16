// Placa "ESP32 Dev Module"

#define titleccion "Leccion 13 Sensor Mercurio"

#include <TFT_eSPI.h> // Hardware-specific library

#define magnetPin 14
#define ledPin 12


TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(magnetPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

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
  int valor = digitalRead(magnetPin);
  if (valor == HIGH)
    {
    tft.fillCircle(100, 100, 30, TFT_RED);
    digitalWrite(ledPin,HIGH);
    }
  else
    {
    tft.fillCircle(100, 100, 30, TFT_GREEN );
    digitalWrite(ledPin,LOW);
    }
  delay(100);
}
