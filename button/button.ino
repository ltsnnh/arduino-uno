#define LED 13
#define BUTTON 8

bool buttonState = LOW;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(115200);
  Serial.println("init serial");

}

void loop() {
  buttonState = digitalRead(BUTTON);
  if(buttonState == LOW)
  {
    digitalWrite(LED, HIGH);
    Serial.println("PRESSED, LED ON");
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println("NOTHING, LED OFF");
  }
  
}
