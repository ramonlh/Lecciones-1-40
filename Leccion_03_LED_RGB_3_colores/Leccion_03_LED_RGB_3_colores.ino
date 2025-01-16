// Placa "ESP32 Dev Module"

#define titleccion "Lección 3 LED RGB tres colores"


int rojoPin = 21;
int verdePin = 22;
int azulPin = 25;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(titleccion);

  pinMode(verdePin,OUTPUT);
  pinMode(rojoPin,OUTPUT);
  pinMode(azulPin,OUTPUT);
}  

void loop() {

  digitalWrite(verdePin, HIGH);
  digitalWrite(rojoPin, LOW);
  digitalWrite(azulPin, LOW);
  delay(1000);
  digitalWrite(verdePin, LOW);
  digitalWrite(rojoPin, HIGH);
  digitalWrite(azulPin, LOW);
  delay(1000);
  digitalWrite(verdePin, LOW);
  digitalWrite(rojoPin, LOW);
  digitalWrite(azulPin, HIGH);
  delay(1000);

}
