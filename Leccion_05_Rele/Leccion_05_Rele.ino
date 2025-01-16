// Placa "ESP32 Dev Module"

#define titleccion "Lección 5 Relé"

#define relePin 26

// Ésto se ejecuta una sola vez al arrancar
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(relePin, OUTPUT);
}

// Ésto se ejecuta indefinidamente
void loop() {
  digitalWrite(relePin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(relePin, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
