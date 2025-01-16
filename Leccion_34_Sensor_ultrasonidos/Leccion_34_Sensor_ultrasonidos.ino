// Placa "ESP32 Dev Module"

#define titleccion "Leccion 34 Sensor Ultrasonidos"

#include <TFT_eSPI.h> // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

#define pin_US_receptor 26
#define pin_US_emisor 25

const int EchoPin = pin_US_receptor;
const int TriggerPin = pin_US_emisor;

int ping(int TriggerPin, int EchoPin) {
  long duration, distanceCm;
  
  digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  
  duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
  
  distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
  return distanceCm;
}

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);

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
  tft.setCursor(0,50);
  tft.print("Distancia: ");
// para PLACA EXPERIMENTAL V1
Serial.print("TFT_MISO:"); Serial.println(TFT_MISO); //  19
Serial.print("TFT_MOSI:"); Serial.println(TFT_MOSI); //   23
Serial.print("TFT_SCLK:");Serial.println(TFT_SCLK); //   18
Serial.print("TFT_CS:"); Serial.println(TFT_CS);   //     15
Serial.print("TFT_DC:"); Serial.println(TFT_DC);   //      2
Serial.print("TFT_RST:"); Serial.println(TFT_RST);  //     4    // Set TFT_RST to -1 if the display RESET is connected to RST or 3.3V
Serial.print("TOUCH_CS:");Serial.println(TOUCH_CS); //    5  
}

void loop(void) 
{
  int cm = ping(TriggerPin, EchoPin);
  tft.fillRect(150,50,300,40,TFT_BLACK);
  tft.setCursor(150,50);
  tft.println(cm);
  delay(100);
}
