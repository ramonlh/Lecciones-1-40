// Placa "ESP32 Dev Module"

#define titleccion "Leccion 37 Sensor de color"

#include <TFT_eSPI.h> // Hardware-specific library



#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <ESP_Color.h>

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

#define SDApin 21
#define SCLpin 22

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

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

  // Sensor de color
  Wire.begin(SDApin,SCLpin);
  if (tcs.begin()) {
    Serial.println("Sensor encontrado");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}

void loop(void) {
  uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);
  // colorTemp = tcs.calculateColorTemperature(r, g, b);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);

  Serial.print("Lux:");  Serial.print(lux, DEC);
  Serial.print("   RED: ");  Serial.print(r, DEC);
  Serial.print("  GREEN: ");  Serial.print(g, DEC);
  Serial.print("  BLUE: ");  Serial.print(b, DEC);
  String color = "";
  if ((r-g>50) & (r-b>50))
    color = "ROJO";
  if ((g-b>10) & (g-r>30))
    color = "VERDE";
  if ((b-g>20) & (b-r>40))
    color = "AZUL";
  if ((r-b>40) & (g-b>40))
    color = "AMARILLO";
  Serial.print("  color:"); Serial.println(color);

  tft.fillRect(0, 100, 250, 130, TFT_BLACK);
  tft.setCursor(0,100);
  tft.print(color);
  delay(500);
  }