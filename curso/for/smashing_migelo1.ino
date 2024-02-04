int pinLed[9] = {12,11,10,9,8,7,6,5,4};

void setup()
{
  int x;

  for (x = 0; x < 9; x++) {
    pinMode(pinLed[x], OUTPUT);
  }
  
  
}

void loop()
{

  for (int nled = 0; nled < 9; nled = nled + 1) {
  	digitalWrite(pinLed[nled], HIGH);
  	delay(150);
  }
  
  for (int nled = 8; nled >= 0; nled--) {
  	digitalWrite(pinLed[nled], LOW);
  	delay(200);
  }
  
}