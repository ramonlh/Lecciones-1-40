// Placa "ESP32 Dev Module"

#define titleccion "Leccion 15 Temperatura NTC 10K"

#include <TFT_eSPI.h> // Hardware-specific library

#define tempPin 27

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(tempPin, INPUT_PULLUP);

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
}
float Steinhart_Hart(float R)
{
  float logR = log(R);
  float A = 0.00111492089;
  float B = 0.0002372075385;
  float C = 0.00000006954079529;
  float temperatura = 1 / (A + (B*logR) + C * logR *logR * logR);
  return temperatura - 273.0;
}

void loop(void) 
{
  float valor = analogRead(tempPin);   // mínimo = 0, máximo = 4095
  float voltaje = valor * 3.3 / 4096;
  float resistencia = (voltaje * 10000) / (5.0 - voltaje);
  float temperatura = 1 / (0.000111492089);

  tft.fillRect(0,50,300,100,TFT_BLACK);
  tft.setCursor(0,50);
  Serial.print("Valor digital: "); Serial.println(valor);
  Serial.print("Voltaje: ");  Serial.println(voltaje);
  Serial.print("Resistencia: ");  Serial.println(resistencia);
  Serial.print("Temperatura: ");  Serial.println(Steinhart_Hart(resistencia));

  tft.print("Valor digital: "); tft.println(valor);
  tft.print("Voltaje: ");  tft.println(voltaje);
  tft.print("Resistencia: ");  tft.println(resistencia);
  tft.print("Temperatura: ");  tft.println(Steinhart_Hart(resistencia));
  
  delay(1000);
}
