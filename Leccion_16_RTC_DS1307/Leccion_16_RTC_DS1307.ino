// Placa "ESP32 Dev Module"

#define titleccion "Lección 16 Reloj DS1307"

#include <TFT_eSPI.h> 
#include <DFRobot_DS1307.h>

#define SDApin 21
#define SCLpin 22

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
DFRobot_DS1307 DS1307;

void setup()
{
  Serial.begin(115200);
  //pinMode(13,OUTPUT); digitalWrite(13,HIGH);
  Wire.begin(SDApin,SCLpin);
  // Pantalla TFT
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_YELLOW);
  tft.setCursor(0, 0);
  tft.setTextSize(2);

  // Initialize RTC
  while( !(DS1307.begin()) ){
    tft.println("ERROR al iniciar");
    delay(3000);
  }
  uint16_t setTimeBuff[7] = {0, 43, 21, 2, 25, 11, 2024};
  DS1307.setTime(setTimeBuff);                     // para poner en hora
  // Start RTC timing function this bit is part of the seconds byte
  DS1307.start();
  // control the operation of the SQW/OUT pin mode SQW Pin output mode:
  // eSquareWave_LOW, eSquareWave_HIGH, eSquareWave_1Hz, eSquareWave_4kHz, eSquareWave_8kHz, eSquareWave_32kHz
  DS1307.setSqwPinMode(DS1307.eSquareWave_1Hz);
}

void loop()
{
  uint16_t getTimeBuff[7] = {0};
  DS1307.getTime(getTimeBuff);
  char outputarr[128];
  sprintf(outputarr, "%d/%d/%d %d:%d:%d\r\n",
            getTimeBuff[4],
            getTimeBuff[5],
            getTimeBuff[6],
         //   getTimeBuff[3],   // dia de la semana
            getTimeBuff[2],
            getTimeBuff[1],
            getTimeBuff[0]
            );
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(20, 100);
  tft.print(outputarr);
  delay(1000);
}
