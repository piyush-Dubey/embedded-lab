int analogPin = 1; // Reads the resistance of R2
int raw = 0; // Raw input value
float Vin = 5; // Input voltage
float Vout = 0; // Output voltage
float R1 = 10000; // Standard resistor value
float R2 = 0;
float temp = 0; // Temporary variable for calculation
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600); // Setup serial
}

void loop() {
  // put your main code here, to run repeatedly:
  raw = analogRead(analogPin); // Read the input pin
  if(raw)
  {
    float Vin_digital = Vin / 1024.0;
    Vout = raw * Vin_digital;
    temp = Vin / Vout - 1;
    R2 = R1 / temp;
    double I = Vout / R2 * 1000;
    delay(100);
    Serial.print("Vout: ");
    Serial.println(Vout);
    Serial.print("R2: ");
    Serial.println(R2);
    Serial.print("I(in mA): ");
    Serial.println(I);
    delay(1000);
  }
}
