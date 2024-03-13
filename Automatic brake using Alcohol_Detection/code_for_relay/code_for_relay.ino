int pin=5;

void setup() {
  Serial.begin(115200);
  pinMode(pin,OUTPUT);
  

}

void loop() {
  digitalWrite(pin,1);
  Serial.println("On");
  delay(5000);
  digitalWrite(pin,0);
  Serial.println("Off");
  delay(5000);

}
