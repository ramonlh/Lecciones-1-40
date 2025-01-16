// Placa "ESP32 Dev Module"

#define titleccion "Leccion 36 Sensor de temperatura DS18B20"

#include <TFT_eSPI.h> // Hardware-specific library
#include <OneWire.h>
#include <DallasTemperature.h>

#define oneWirePin 14

OneWire oneWireBus(oneWirePin);
DallasTemperature sensor(&oneWireBus);
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
  tft.setTextSize(1);
  tft.println();
  tft.println(titleccion);
  tft.setTextSize(2);
  tft.setTextColor(TFT_YELLOW);
  tft.setCursor(0,100);
  tft.print("Temperatura: ");

  // sensor
  sensor.begin(); 
}

void loop(void) 
{
  sensor.requestTemperatures();
  delay(10);

  tft.fillRect(150, 100, 250, 130, TFT_BLACK);
  tft.setCursor(150,100);
  tft.print(sensor.getTempCByIndex(0));
  tft.println(" C");

  Serial.print("Temperatura : ");
  Serial.print(sensor.getTempCByIndex(0));
  Serial.println(" ºC");
  delay(1000);
}
