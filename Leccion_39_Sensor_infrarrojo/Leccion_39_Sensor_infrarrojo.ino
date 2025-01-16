// Placa "ESP32 Dev Module"

#define titleccion "Leccion 39 Sensor infrarrojo"

#include <TFT_eSPI.h> // Hardware-specific library

#define LED_BUILTIN      2
#define IR_PIN          14  // D15

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(IR_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

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

void loop() {
  int valordig = digitalRead(IR_PIN);
  if (valordig == HIGH)
    {
    tft.fillCircle(100, 100, 30, TFT_RED);
    digitalWrite(LED_BUILTIN,HIGH);
    }
  else
    {
    tft.fillCircle(100, 100, 30, TFT_GREEN );
    digitalWrite(LED_BUILTIN,LOW);
    }
}
