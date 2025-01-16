// Placa "ESP32 Dev Module"

#define titleccion "Lección 23 Led 7 colores"

#define digPin 14

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(digPin, OUTPUT);
  digitalWrite(digPin,HIGH);
}

void loop(void) {
}
