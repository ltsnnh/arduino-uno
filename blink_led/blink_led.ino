void setup() {
  pinMode(13, OUTPUT);  // Led is built-in onboard
  
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);

}
