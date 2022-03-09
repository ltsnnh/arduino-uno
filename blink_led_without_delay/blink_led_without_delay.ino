/*
 * NOTE: millis() function returns number of milliseconds passed since the program started
 * This number will overflow (go back to zero), after approximately 50 days
 * When it comes, LED capably will take longer than 1s (interval) to change its state, due to arithmetic limit 
*/

#define LED 13

bool LEDstate = LOW;
const unsigned long interval = 1000;  // [ms]
unsigned long currentTime = 0;
unsigned long previousTime = currentTime;

void setup() {
  pinMode(LED, OUTPUT);  // Led is built-in onboard

}

void loop() {
  currentTime = millis();
  if((currentTime - previousTime) >= interval)
  {
    previousTime = currentTime;
    if(LEDstate == LOW)
    {
      LEDstate = HIGH;
    }
    else
    {
      LEDstate = LOW;
    }
    digitalWrite(LED, LEDstate);
  }

}
