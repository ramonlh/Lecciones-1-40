// Placa "ESP32 Dev Module"

#define titleccion "Lección 20 Escribir en puerto serie"

void setup()
{
  Serial.begin(115200);     // Prepara puerto serie y fijar velocidad
  Serial.println();
  Serial.println(titleccion);
}

void loop() {
  Serial.println("Escribimos en el puerto serie");
  // Esperamos 2 segundos
  delay(2000);

}
