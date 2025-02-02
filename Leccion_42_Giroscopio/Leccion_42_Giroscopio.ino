//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

const int mpuAddress = 0x68;  // Puede ser 0x68 o 0x69
MPU6050 mpu(mpuAddress);

int ax, ay, az;
int16_t gx, gy, gz;

long tiempo_prev, dt;
float girosc_ang_x, girosc_ang_y, girosc_ang_z;
float girosc_ang_x_prev, girosc_ang_y_prev, girosc_ang_z_prev;

void updateGiro()
{
  dt = millis() - tiempo_prev;
  tiempo_prev = millis();

  girosc_ang_x = (gx / 131)*dt / 1000.0 + girosc_ang_x_prev;
  girosc_ang_y = (gy / 131)*dt / 1000.0 + girosc_ang_y_prev;
  girosc_ang_z = (gz / 131)*dt / 1000.0 + girosc_ang_z_prev;

  girosc_ang_x_prev = girosc_ang_x;
  girosc_ang_y_prev = girosc_ang_y;
  girosc_ang_z_prev = girosc_ang_z;
}

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  Serial.println(mpu.testConnection() ? F("IMU iniciado correctamente") : F("Error al iniciar IMU"));
}

void loop()
{
  // Leer las velocidades angulares 
  mpu.getRotation(&gx, &gy, &gz);

  updateGiro();

  // Mostrar resultados
  Serial.print(F("Rotacion en X:  "));
  Serial.print(girosc_ang_x);
  Serial.print(F("\tElevacion Y: "));
  Serial.print(girosc_ang_y);
  Serial.print(F("\tAzimut Z: "));
  Serial.println(girosc_ang_z);

  delay(1000);
}