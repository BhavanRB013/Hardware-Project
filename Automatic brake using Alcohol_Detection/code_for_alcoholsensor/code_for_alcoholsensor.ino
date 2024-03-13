const int sensorPin = 34;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  
  int sensorValue = analogRead(sensorPin);

  
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // Add a delay for better readability
  delay(5000);
}

//2700 max