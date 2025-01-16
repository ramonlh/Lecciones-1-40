const int heartbeatSensorPin = 13; // Analog pin connected to the Heartbeat Sensor module

void setup() {
  pinMode(heartbeatSensorPin, INPUT); // Set the Heartbeat Sensor pin as INPUT
  Serial.begin(115200); // Initialize serial communication for debugging (optional)
}

void loop() {
  int heartbeatValue = analogRead(heartbeatSensorPin); // Read the analog value from the Heartbeat Sensor
  int heartbeatRate = map(heartbeatValue, 0, 1023, 40, 220); // Map the sensor value to a heartbeat rate range (40 to 220 BPM)

//  Serial.print("Heartbeat Rate (BPM): ");
//  Serial.println(heartbeatValue); // Display the heartbeat rate in BPM
  Serial.println(heartbeatRate); // Display the heartbeat rate in BPM

  // If using an LED, blink the LED based on the heartbeat rate

  delay(100); // Add a small delay to avoid rapid repeated readings
}