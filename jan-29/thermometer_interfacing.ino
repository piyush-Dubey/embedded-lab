float temperature = 0;
int temperaturePin = 0;
float inputVoltage = 5.0;
float sensitivity = 10; // sensitivity of LM35 = 10mV per degree C
int outputPin = 13;

void setup()
{
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(outputPin, LOW);
  temperature = analogRead(temperaturePin);
  float a2d = inputVoltage / 1024 * 1000; // Voltage in mV
  temperature = temperature * a2d / sensitivity;
  Serial.print("TEMPERATURE = ");
  Serial.print(temperature);
  Serial.print("*C");
  Serial.println();
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
