int sensorPin = 7; //The output of PIR sensor connected to pin 7
int sensor_value = 0; //variable to hold read sensor value

void setup()
{
  pinMode(sensorPin,INPUT); // configuring pin 7 as Input
  Serial.begin(9600); // To show output value of sensor in serial monitor
}

void loop()
{
  sensor_value=digitalRead(sensorPin); // Reading sensor value from pin 7
  if(sensor_value == 1)
  {
    Serial.println("Intruder alert"); // Printing output to serial monitor
  }
  else
  {
    Serial.println("...");
  }
  delay(100);
}
