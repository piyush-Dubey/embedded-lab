const int switchPin = 3; // The input pin where the pushbutton is connected
const int ledPin = 11; // The pin for the LED
int buttonStatus = 0; // buttonStatus is used to store the state of the system

void setup()
{
  pinMode(switchPin, INPUT); // Input is pin 3
  pinMode(ledPin, OUTPUT); // Output is pin 11
}

void loop()
{
  buttonStatus = digitalRead(switchPin); // Read input value and store it

  // Check whether the input is high (button pressed)
  if (buttonStatus == HIGH)
  {
    digitalWrite(ledPin, HIGH); // Turn LED on
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
