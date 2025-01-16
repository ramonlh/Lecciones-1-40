// Placa "ESP32 Dev Module"

#define titleccion "// Lección 1 Luz intermitente en la placa"

#define LED_PLACA 2

// Ésto se ejecuta una sola vez al arrancar
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PLACA, OUTPUT);
}

// Ésto se ejecuta indefinidamente
void loop() {
  digitalWrite(LED_PLACA, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_PLACA, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
