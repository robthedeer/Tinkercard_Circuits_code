int dummy = 0;

static int cathodePin[] = {0,0,0,1,1,1,2,2,2,3};
static int anodePin[] =   {1,2,3,0,2,3,0,1,3,0};

void setup()
{
  turnLightsOff();
}

void turnLightsOff() {
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void turnLightOn(int index) {
  turnLightsOff();
  
  digitalWrite(cathodePin[index], LOW);
  digitalWrite(anodePin[index], HIGH);
  
  pinMode(cathodePin[index], OUTPUT);
  pinMode(anodePin[index], OUTPUT);
};

void loop()
{
  int i;
  for (i = 0; i < 9; ++i) { turnLightOn(i); delay(100); }
  for (i = 9; i >= 0; --i) { turnLightOn(i); delay(100); }
  for (i = 9; i > 0; --i) { turnLightOn(i); delay(100); }
  for (i = 0; i < 10; ++i) { turnLightOn(i); delay(100); }

  for (int i = 0; i < 200; ++i) {
    turnLightOn(random(10));
    delay(25);
  }
}
