/*
    Project name : Soil Moisture Sensor
    Modified Date: 12-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-soil-moisture-sensor
*/

const int soilSensorPin = A0; // Analog pin connected to the soil moisture sensor

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read the soil moisture value
  int soilMoisture = analogRead(soilSensorPin);

  // Map the sensor value to a specific range
  int moistureLevel = map(soilMoisture, 0, 1023, 0, 100);

  // Print the soil moisture level
  Serial.print("Soil Moisture Level: ");
  Serial.print(moistureLevel);
  Serial.println("%");

  // Print a message indicating the soil moisture level
  if (moistureLevel >= 70) {
    Serial.println("Soil is Wet");
  } else if (moistureLevel >= 40) {
    Serial.println("Soil is Moist");
  } else {
    Serial.println("Soil is Dry");
  }

  // Add a small delay before reading the sensor again
  delay(1000); // Adjust delay as needed
}
