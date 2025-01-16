// Placa "ESP32 Dev Module"

#define titleccion "Lección 27 Emiso Laser"

#define LED_PIN 13

// Ésto se ejecuta una sola vez al arrancar
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);
}

// Ésto se ejecuta indefinidamente
void loop() {
  digitalWrite(LED_PIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_PIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
