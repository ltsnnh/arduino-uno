#define LED 13
#define BUTTON 8

bool ledState = HIGH;
bool buttonState = HIGH;
bool lastButtonState = HIGH;

bool reading = HIGH;

unsigned long lastDebouncTime = 0;
unsigned long debouncDelay = 50;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(LED, ledState);

}

void loop() {
  reading = digitalRead(BUTTON);
  if(reading != lastButtonState)
  {
    lastDebouncTime = millis();
  }
  if((millis() - lastDebouncTime) > debouncDelay)
  {
    if(reading != buttonState)
    {
      buttonState = reading;
      if(buttonState == LOW)
      {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(LED, ledState);
  lastButtonState = reading;  // save the reading. Next time through the loop, it'll be the lastButtonState
  
}
