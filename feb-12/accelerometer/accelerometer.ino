const int VCCPin = A0;
const int xPin   = A1;
const int yPin   = A2;
const int zPin   = A3;
const int GNDPin = A4;

// variables
int x = 0;
int y = 0;
int z = 0;

void setup() {
// pin A0 (pin14) is VCC and pin A4 (pin18) in GND to activate the GY-61-module
pinMode(A0, OUTPUT);
pinMode(A4, OUTPUT);
digitalWrite(14, HIGH);
digitalWrite(18, LOW);

// activating debugging for arduino UNO
Serial.begin(9600);
} // end setup

void loop() {
x = analogRead(xPin);
y = analogRead(yPin);
z = analogRead(zPin);
// show x, y and z-values
Serial.print("x = ");
Serial.print(x);
Serial.print("  y = ");
Serial.print(y);
Serial.print("  z = ");
Serial.print(z);
// show angle
Serial.print("  angle = ");
Serial.println(constrain(map(x,349,281,0,90),0,90));
}
