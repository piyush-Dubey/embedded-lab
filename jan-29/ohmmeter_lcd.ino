#include "LiquidCrystal.h"
// initialize the library by providing the number of pins to it
LiquidCrystal lcd(8,9,4,5,6,7);
const int analogPin= 1;
int raw= 0;
float Vin= 5; // Input voltage
float Vout= 0; // Initialize output voltage as 0 V
float R1= 1000; // Set standard resistor value as 1 kilo-ohms
float R2= 0; // Initialize unknown resistor value as 0 ohms
float temp= 0;

void setup() 
{
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
}

void loop() 
{
  raw = analogRead(analogPin); // Read from analog pin 1
  if(raw)
  {
    temp = raw * Vin;
    Vout = (temp)/1024.0; // Converting analog input to digital using 10 bit ADC
    temp = (Vin/Vout) -1; // Voltage divider formula
    R2 = R1 * temp;
    lcd.setCursor(0,0); // Set cursor at row 0 and column 0
    lcd.print("Vout: ");
    lcd.println(Vout);
    lcd.setCursor(0,1); // Set cursor at row 1 and column 0
    lcd.print("R2: ");
    lcd.println(R2);
    delay(1000);
  }
}
