
#define BLYNK_PRINT Serial


#include <BlynkSimpleStream.h>
#include <SoftwareSerial.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "022182f8c0a04db6805b04549a5fbd01";
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin 1


SoftwareSerial SwSerial(0, 1); // RX, TX

void setup()
{
  // Debug console
  Serial.begin(9600);

  // Blynk will work through SoftwareSerial
  // Do not read or write this serial manually in your sketch
  SwSerial.begin(9600);
  Blynk.begin(SwSerial, auth);
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
}

void loop()
{
  Blynk.run();
}

