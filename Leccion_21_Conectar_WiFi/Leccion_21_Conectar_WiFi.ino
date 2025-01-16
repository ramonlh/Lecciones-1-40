// Placa "ESP32 Dev Module"

#define titleccion "Leccion 21 Conectar WiFi"

#include <TFT_eSPI.h> // Hardware-specific library
#include <WiFi.h>

const int led = 2;
const char *ssid = "MOVISTAR_8453";   // Change this to your WiFi SSID
const char *password = "18921892";    // Change this to your WiFi password

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
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) 
    {
    delay(500);
    Serial.print(".");
    }
    
  digitalWrite(led, HIGH);
  tft.println();
  tft.print("Conectado a ");
  tft.println(ssid);
  tft.print("IP address: ");
  tft.println(WiFi.localIP());
}

void loop(void) 
{
}
