#include <LiquidCrystal.h> // include the LiquidCrystal Library

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Create an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;

void setup()
{
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(trigPin, OUTPUT); // set pin 9 as trigger pin
  pinMode(echoPin, INPUT); // set pin 10 as echo pin
}

void loop()
{
  // clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in micro seconds
  duration = pulseIn(echoPin, HIGH);
  distanceCm= duration*0.034/2;
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: ");
  lcd.print(distanceCm); // Prints the distance value from the sensor
  lcd.print(" cm");
  delay(10);
}