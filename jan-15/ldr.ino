const int led = 9;

int val = 0;

void setup()
{
  pinMode(led, OUTPUT);
}
void loop()
{
  val = analogRead(A0);
  analogWrite(led, val/4);
  delay(10);
}

