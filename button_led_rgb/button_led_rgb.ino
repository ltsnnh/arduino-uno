#define BUTTON 2
#define REDLED 9
#define BLUELED 10
#define GREENLED 11

volatile int mode = 0;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  pinMode(GREENLED, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON), changeMode, FALLING); // external interrupt

}

void loop() {
  setMode(mode);

}

void setMode(int mode) {
  switch(mode)
  {
    case 0:
    digitalWrite(REDLED, HIGH);
    digitalWrite(BLUELED, LOW);
    digitalWrite(GREENLED, LOW);
    break;
    case 1:
    digitalWrite(REDLED, LOW);
    digitalWrite(BLUELED, HIGH);
    digitalWrite(GREENLED, LOW);
    break;
    case 2:
    digitalWrite(REDLED, LOW);
    digitalWrite(BLUELED, LOW);
    digitalWrite(GREENLED, HIGH);
    break;
    case 3:
//    digitalWrite(REDLED, LOW);
//    digitalWrite(BLUELED, LOW);
//    digitalWrite(GREENLED, LOW);
    analogWrite(REDLED, brightness);
    analogWrite(BLUELED, brightness);
    analogWrite(GREENLED, brightness);
    brightness += fadeAmount;
    if(brightness <= 0 || brightness >= 255)
    {
      fadeAmount = -fadeAmount;
    }
    delay(30);
    break;
    default:
    ;
  }
}

void changeMode() {
  mode++;
  if(mode >= 4)
  {
    mode = 0;
  }
}
