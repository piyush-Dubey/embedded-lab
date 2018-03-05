#include <DHT.h>
#include <DHT_U.h>

DHT D;

#define DHT11_PIN 3

void setup() 
{
  Serial.begin(9600);
}

void loop()
{ // READ DATA
  int chk = D.read11(DHT11_PIN);
  Serial.print(" Humidity ");
  Serial.println(D.humidity, 1);
  Serial.print(" Temparature ");
  Serial.println(D.temperature, 1);
  delay(2000);
}
