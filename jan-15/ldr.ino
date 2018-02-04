const int led = 9;

int val = 0;

void setup()
{
  pinMode(led, OUTPUT); // Set pin 9 as led output
}
void loop()
{
  val = analogRead(A0); // Read from Analog pin
  analogWrite(led, val/4); // Reduce brightness by four times on each iteration of the loop
  delay(10);
}

