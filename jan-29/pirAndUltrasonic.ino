int pirPin = 7; //The output of PIR connected to pin 7
int pir_value = 0; //variable to hold read pir value
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup()
{
  pinMode(pirPin,INPUT); // set pin 7 as Input
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600); // To show output value of pir in serial monitor
}

void loop()
{
  pir_value = digitalRead(pirPin); // Reading pir value from pin 7
  if(pir_value == HIGH)
  {
    // clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin as digital HIGH for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in micro seconds
    duration = pulseIn(echoPin, HIGH);
    float speedSound = 0.034; // Speed of sound in mm per micro seconds
    // Calculating the distance
    distance = duration * speedSound / 2;
    Serial.print("Intruder at:"); // Prints distance of intruder on serial monitor if intruder observed
    Serial.println(distance);
  }
  else
  {
    Serial.println("...");
  }
  delay(100);
}
