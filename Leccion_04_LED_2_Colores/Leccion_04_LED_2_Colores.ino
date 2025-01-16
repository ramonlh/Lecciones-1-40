// Placa "ESP32 Dev Module"

#define titleccion "Lección 4 LED de dos colores"

int verdePin = 26;
int rojoPin = 25;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(titleccion);

  pinMode(verdePin,OUTPUT);
  pinMode(rojoPin,OUTPUT);
}  

void loop() {

  digitalWrite(verdePin, HIGH);
  digitalWrite(rojoPin, LOW);
  delay(1000);
  digitalWrite(verdePin, LOW);
  digitalWrite(rojoPin, HIGH);
  delay(1000);

}
