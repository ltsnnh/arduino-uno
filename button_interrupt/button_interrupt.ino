/*
 * Board UNO, digital pins (2, 3) usable for interrupts
 */

#define LED 13
#define BUTTON 2

volatile bool ledState = LOW;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON), blink, FALLING); // external interrupt

}

void loop() {
  // do nothing!

}

void blink() {
  if(ledState == LOW)
  {
    ledState = HIGH;
  }
  else
  {
    ledState = LOW;
  }

  digitalWrite(LED, ledState);
  
}
