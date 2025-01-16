// Placa "ESP32 Dev Module"

#define titleccion "Leccion 38 Joystick analogico"

#include <TFT_eSPI.h> // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

#define xPin 26
#define yPin 25
#define sPin 14


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
  tft.setTextSize(2);
  tft.setTextColor(TFT_YELLOW);

  // Joystick
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT_PULLUP);
}

void loop(void) {

  int x = analogRead(xPin);
  int y = analogRead(yPin);
  int s = digitalRead(sPin);

  Serial.print("x: "); Serial.print(x);
  Serial.print("  y: "); Serial.print(y);
  Serial.print("  s: "); Serial.println(s);

  tft.fillRect(0, 100, 250, 130, TFT_BLACK);
  tft.setCursor(0,100);
  tft.print("x: "); tft.println(x);
  tft.print("y: "); tft.println(y);
  tft.print("Boton: "); tft.println(s);
  delay(500);
  }