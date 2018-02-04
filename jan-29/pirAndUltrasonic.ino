int pirPin = 7; //The output of PIR pir connected to pin 7
int pir_value = 0; //variable to hold read pir value
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup()
{
  pinMode(pirPin,INPUT); // configuring pin 7 as Input
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600); // To show output value of pir in serial monitor
}

void loop()
{
  pir_value = digitalRead(pirPin); // Reading pir value from pin 7
  if(pir_value == HIGH)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    float speedSound = 0.034;
    distance = duration * speedSound / 2;
    Serial.print("Intruder at:"); // Printing output to serial monitor
    Serial.println(distance);
  }
  else
  {
    Serial.println("...");
  }
  delay(100);
}
