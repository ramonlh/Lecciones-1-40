// Placa "ESP32 Dev Module"

#define titleccion "Lección 19 Sensor de presion BMP085"

#include <TFT_eSPI.h> 
#include <Adafruit_BMP085.h>

#define SDApin 21
#define SCLpin 22

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
Adafruit_BMP085 bmp;

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);
  pinMode(13,OUTPUT); digitalWrite(13,HIGH);

  // Pantalla TFT
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(0, 0);
  tft.setTextSize(2);

  Wire.begin(SDApin,SCLpin);
  if (!bmp.begin()) 
    {
	  tft.println("No se encontro el sensor BMP085");
	  while (1) {}
  }
  tft.setCursor(0, 0);
  tft.println("Temperatura: ");
  tft.setCursor(0, 20);
  tft.println("Presion: ");
  tft.setCursor(0, 40);
  tft.println("Altitud: ");
  tft.setCursor(0, 60);
  tft.println("Presion n.m.: ");
  tft.setCursor(0, 80);
  tft.println("Altitud real: ");
  tft.setTextColor(TFT_YELLOW);
}

void loop(void) {
  tft.fillRect(150, 0, 80, 20, TFT_BLACK);
  tft.setCursor(160, 0);
  tft.print(bmp.readTemperature());  tft.println(" C");

  tft.fillRect(150, 20, 80,20,  TFT_BLACK);
  tft.setCursor(160, 20);
  tft.print(bmp.readPressure());  tft.println(" Pa");

  tft.fillRect(150, 40, 80,20,  TFT_BLACK);
  tft.setCursor(160, 40);
  tft.print(bmp.readAltitude());  tft.println(" metros");

  tft.fillRect(150, 60, 80,20,  TFT_BLACK);
  tft.setCursor(160, 60);
  tft.print(bmp.readSealevelPressure());  tft.println(" Pa");

  tft.fillRect(150, 80, 80,20,  TFT_BLACK);
  tft.setCursor(160, 80);
  tft.print(bmp.readAltitude(101500));
  tft.println(" metros");

  delay(5000);
}
