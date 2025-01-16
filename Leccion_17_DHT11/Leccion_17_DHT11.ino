// Placa "ESP32 Dev Module"

#define titleccion "Lección 17 Sensor de Temperatura y Humedad DHT11"

#include <TFT_eSPI.h> // Hardware-specific library
#include "DHTesp.h" // Click here to get the library: http://librarymanager/All#DHTesp

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
DHTesp dht;
/** Pin number for DHT11 data pin */
int dhtPin = 25;

void setup(void) {
  Serial.begin(115200);
  // Pantalla TFT
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(0, 0);
  tft.setTextSize(1);
  // Initialize temperature sensor
  tft.println();
  tft.println(titleccion);

  // datos por el pin 13
	dht.setup(dhtPin, DHTesp::DHT11);
	tft.println("DHT initiated");
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
}


void loop(void) {
  TempAndHumidity valores = dht.getTempAndHumidity();
  tft.fillRect(0, 100, 250, 130, TFT_BLACK);
	if (dht.getStatus() != 0) {
    tft.setCursor(0,200);
		tft.println("DHT11 error: " + String(dht.getStatusString()));
  	}
  else {
    tft.setCursor(0,100);
    tft.println("Temperatura: " + String(valores.temperature) + " C");
    tft.println("Humedad: " + String(valores.humidity) + " %");
    }
  // Wait 2 seconds to let system settle down
  delay(3000);
}
