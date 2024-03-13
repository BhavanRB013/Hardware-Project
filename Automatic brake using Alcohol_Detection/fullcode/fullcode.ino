const int sensorPin = 34;   // Analog pin (ADC) for MQ sensor
const int relayPin = 5;     

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);  
  Serial.begin(115200);  // Initialize serial communication for debugging
}

void loop() {
  // Read the sensor value
  int x = analogRead(sensorPin);

  if (x < 2600) {
    digitalWrite(relayPin, HIGH);
    Serial.println("Drunk");
    Serial.println(x);
    delay(5000);
  } else {
    digitalWrite(relayPin, LOW);
    Serial.println("NOT-Drunk");
    Serial.println(x);
    delay(10000);
  }


}