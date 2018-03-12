float temp;
int tempPin = A0; //arduino pin used for temperature sensor
int tempMin = 28;
int tempMax = 40;
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293

// int fan = 6; // the pin where fan is connected

int fanSpeed = 0;

void setup() 
{
  pinMode(tempPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  temp = analogRead(tempPin);
  temp = (temp * 5.0 * 100.0) / 1024.0; //calculate the temperature in Celsius
  Serial.println(temp);
  delay(1000); // delay in between reads for stability
  
  if(temp < tempMin) 
  { 
    // if temp is lower than minimum temp
    fanSpeed = 0; // fan is not spinning
    digitalWrite(motorPin1, LOW);
  }
  
  if((temp >= tempMin) && (temp <= tempMax)) //if temperature is higher than the minimum range
  {
    fanSpeed = map(temp, tempMin, tempMax, 128, 255); // the actual speed of fan
    analogWrite(motorPin1, fanSpeed); // spin the fan at the fanSpeed speed
  }
}
