// Placa "ESP32 Dev Module"

#define titleccion "Leccion 7 Boton"

#define magnetPin 35

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(magnetPin, INPUT_PULLUP);
}

void loop(void) 
{
  if (digitalRead(magnetPin) == HIGH)
    Serial.println("ABIERTO");
  else
    Serial.println("CERRADO");
  delay(1000);
}
