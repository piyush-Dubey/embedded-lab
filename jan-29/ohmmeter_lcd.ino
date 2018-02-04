#include "LiquidCrystal.h"
// initialize the library by providing the number of pins to it
LiquidCrystal lcd(8,9,4,5,6,7);
int analogPin= 1;
int raw= 0;
float Vin= 5;
float Vout= 0;
float R1= 1000;
float R2= 0;
float temp= 0;
void setup() 
{
  lcd.begin(16,2);
}

void loop() 
{
  raw= analogRead(analogPin);
  if(raw)
  {
    temp= raw * Vin;
    Vout= (temp)/1024.0;
    temp= (Vin/Vout) -1;
    R2= R1 * temp;
    lcd.setCursor(0,0);
    lcd.print("Vout: ");
    lcd.println(Vout);
    lcd.setCursor(0,1);
    lcd.print("R2: ");
    lcd.println(R2);
    delay(1000);
}
}
