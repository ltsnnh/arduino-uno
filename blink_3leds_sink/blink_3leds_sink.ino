/*
 * NOTE: millis() function returns number of milliseconds passed since the program started
 * This number will overflow (go back to zero), after approximately 50 days
 * When it comes, LED capably will take longer than 1s (interval) to change its state, due to arithmetic limit 
*/

#define LED1 8
#define LED2 9
#define LED3 10

int LEDsState = 0;

const unsigned long interval = 1000;  // [ms]
unsigned long currentTime = 0;
unsigned long previousTime = currentTime;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

}

void loop() {
  currentTime = millis();
  if((currentTime - previousTime) >= interval)
  {
    LEDsState++;
    if(LEDsState == 3)
    {
      LEDsState = 0;
    }
    previousTime = currentTime;
    switch(LEDsState)
    {
      case 0:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      break;
      case 1:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      break;
      case 2:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      break;
      default:
      ;
    }
  }

}
