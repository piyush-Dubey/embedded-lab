float temperature = 0;
int temperaturePin = 0;
float inputVoltage = 5.0;
float sensitivity = 10; // sensitivity of LM35 = 10mV per degree Celsius
int outputPin = 13;

void setup()
{
  pinMode(outputPin, OUTPUT); // Set pin 13 as a digital output
  Serial.begin(9600); // Begin serial communication at 9600 bits per second
}

void loop()
{
  digitalWrite(outputPin, LOW); // Set pin 13 to digital LOW
  temperature = analogRead(temperaturePin); // Read temperature from analog pin 0
  float a2d = inputVoltage / 1024 * 1000; // Convert input analog voltage to digital output
  // Since the ADC has 10 pins we have a sensitivity of 2 raised to the 10 i.e. 1 / 1024
  temperature = temperature * a2d / sensitivity;
  Serial.print("TEMPERATURE = ");
  Serial.print(temperature); // print temperature on serial monitor
  Serial.print("*C");
  Serial.println();
  // If temperature is greater than 30 degree celsius, set pin 13 as digital HIGH
  // Else set it as LOW
  if(temperature > 30.0)
  {
    digitalWrite(outputPin, HIGH);
  }
  else
  {
    digitalWrite(outputPin, LOW);
  }
  delay(1000);
}
