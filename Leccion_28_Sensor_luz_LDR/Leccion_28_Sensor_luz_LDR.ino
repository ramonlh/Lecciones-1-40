// Placa "ESP32 Dev Module"

#define titleccion "Leccion 28 Sensor luz LDR"

#include <TFT_eSPI.h> // Hardware-specific library

#define rxPin 25

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(rxPin, INPUT_PULLUP);

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
  int valor = digitalRead(rxPin);   
  tft.fillRect(0,50,300,40,TFT_BLACK);
  tft.setCursor(0,50);
  tft.print("Valor digital: "); tft.println(valor);
  Serial.print("Valor digital: "); Serial.println(valor);
  delay(250);
}
