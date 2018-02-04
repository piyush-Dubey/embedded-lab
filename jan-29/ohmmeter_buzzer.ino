int analogPin= 0;
int raw= 0;
int Vin= 5;
float Vout= 0;
float R1= 1000;
float R2= 0;
float temp= 0;
const int buzzer = 3; //buzzer to arduino pin 3
void setup()
{
  Serial.begin(9600);
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
    Serial.print("Vout: ");
    Serial.println(Vout);
    Serial.print("R2: ");
    Serial.println(R2);
    delay(1000);
    if (R2>300)
    {
      tone(buzzer, 1000); // Send 1KHz sound signal...
    }
    else
    {
      noTone(buzzer); // Stop sound...
    }
   }
}

