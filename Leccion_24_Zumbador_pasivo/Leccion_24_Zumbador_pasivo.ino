// Placa "ESP32 Dev Module"

#define titleccion "Lección 24 Zumbador pasivo"

#define zumbPin 14

void setup(void) {
  Serial.begin(115200);
  Serial.println("");
  Serial.println(titleccion);

  pinMode(zumbPin, OUTPUT);
}

void loop(void) {
  tone(zumbPin,440);
  delay(1000);
  noTone(zumbPin);
  delay(1000);

}
