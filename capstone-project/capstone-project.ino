#include <Wire.h>
#include <math.h>
//--- Accelerometer Register Addresses
#define Power_Register 0x2D
#define X_Axis_Register_DATAX0 0x32 // Hexadecimal address for the DATAX0 internal register.
#define X_Axis_Register_DATAX1 0x33 // Hexadecimal address for the DATAX1 internal register.
#define Y_Axis_Register_DATAY0 0x34 
#define Y_Axis_Register_DATAY1 0x35
#define Z_Axis_Register_DATAZ0 0x36
#define Z_Axis_Register_DATAZ1 0x37
int ADXAddress = 0x53;  //Accelerometer Device address 
// Ultrasonic sensor pins
const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 12;
const int echoPin2 = 11;
// Buzzer pins
const int buzzer1 = 3;
const int buzzer2 = 6;

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
 
const int ledPin1 = 8;
const int ledPin2 = 13;
const int GND = 7;
int counter = 0;

long val1;
long val2;

void setup()
{
  Wire.begin(); // Initiate the Wire library    
  pinMode(trigPin1, OUTPUT); // Set trigPin1 as Output
  pinMode(echoPin1, INPUT); // Set echoPin1 as Input
  pinMode(trigPin2, OUTPUT); // Set trigPin2 as Output
  pinMode(echoPin2, INPUT); // Set echoPin2 as Input
  pinMode(buzzer1, OUTPUT); // Set buzzer1 as Output
  pinMode(buzzer2, OUTPUT); // Set buzzer2 as Output
  pinMode(ledPin1, OUTPUT); // Set ledPin1 as Output
  pinMode(ledPin2, OUTPUT); // Set ledPin2 as Output
  pinMode(GND, OUTPUT);
  digitalWrite(GND, LOW);
  buzzerStop(buzzer1);
  buzzerStop(buzzer2);
  Serial.begin(9600); // Start serial communication
  delay(100);
  Wire.beginTransmission(ADXAddress);
  Wire.write(Power_Register); // Power_CTL Register
  // Enable measurement
  Wire.write(8); // Bit D3 High for measuring enable (0000 1000)
  Wire.endTransmission();
}

void loop() 
{
  buzzerStop(buzzer1);
  buzzerStop(buzzer2);
  val1 = ultrasonic(trigPin1, echoPin1);
  //delay(100);
  val2 = ultrasonic(trigPin2, echoPin2);
  buzzerStart(buzzer1, val1, buzzer2, val2);
  printDistance(val1, val2);
  jerk();
}


void jerk(){
  float jerkX = jerkDirection(X_Axis_Register_DATAX0, X_Axis_Register_DATAX1);
  Serial.print("X jerk ");
  Serial.print(jerkX);
  Serial.println();
  
  float jerkY = jerkDirection(Y_Axis_Register_DATAY0, Y_Axis_Register_DATAY1);
  Serial.print("Y jerk ");
  Serial.print(jerkY);
  Serial.println();
  
  float jerkZ = jerkDirection(Z_Axis_Register_DATAZ0, Z_Axis_Register_DATAZ1);
  Serial.print("Z jerk ");
  Serial.print(jerkZ);
  Serial.println();
  float netJerk = sqrt(square(jerkX) + square(jerkY) + square(jerkZ));
  Serial.print("Net jerk ");
  Serial.print(netJerk);
  Serial.println();
  if(netJerk > 100.0) {
    buzzerStop(buzzer1);
    buzzerStop(buzzer2);
    StarWars();
  }
}

/*
 * Function to calculate jerk along a particular direction (X, Y or Z)
 * by calculating difference in acceleration at two different times.
 * Inputs: Hexadecimal addresses for the particular DATA internal registers of accelerometer (GY-80 module)
 * Output: Absolute value of jerk along the direction
 */
float jerkDirection(long addr0, long addr1){
  // Get the number of microseconds since Arduino board began running
  unsigned long t1 = micros();
  float accPrev = acc(addr0, addr1) * 9.8;
  delay(100);
  float accNext = acc(addr0, addr1) * 9.8;
  unsigned long t2 = micros();
  return abs(accNext - accPrev)/ (t2 - t1) * 1000000; // Calculate jerk in SI units
}

/*
 * Function to calculate distance of an object from the person in centimetres.
 * Input values: trigger pin and echo pin respectively.
 * Returns the distance of an object in centimetres.
 */
long ultrasonic(int trigPin, int echoPin){
  // Clear trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Set trigPin to HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  float speedSound = 0.034;
  // Calculate distance
  float distance = duration * speedSound / 2;
  return (long)distance;
}

/*
 * Function to sound buzzer1 and buzzer2 when 
 * distance of person from Ultrasonic sensor 1 and 2 is 
 * less than 60 centimetres and change volume according to the distance.
 * Inputs: buzzer1 pin, distance1, buzzer2 pin, distance2
 */

void buzzerStart(int buzzerPin1, long dist1, int buzzerPin2, long dist2){
  if(dist1 <= 60){
    // Re-map dist1 from 0 to 60 centimetres distance to 255 to 0 buzzer volume
    long volume1 = map(dist1, 0, 60, 255, 0);
    analogWrite(buzzerPin1, volume1);
  }
  if(dist2 <= 60){
    // Re-map dist2 from 0 to 60 centimetres distance to 255 to 0 buzzer volume
    long volume2 = map(dist2, 0, 60, 255, 0);
    analogWrite(buzzerPin2, volume2);
  }
}

/*
 * Function to stop buzzer
 * Input: buzzer pin
 */
void buzzerStop(int buzzerPin){
  noTone(buzzerPin);
}

void printDistance(long val1, long v2){
  
  Serial.print("Distance of 1st: ");
  Serial.print(val1);
  Serial.println();
  Serial.print("Distance of 2nd: ");
  Serial.print(val2);
  Serial.println();
}

float acc(long addr0, long addr1){
  int X0,X1,X_out;
  float Xa;
  Wire.beginTransmission(ADXAddress); // Begin transmission to the Sensor 
  //Ask the particular registers for data
  Wire.write(addr0);
  Wire.write(addr1);  
  Wire.endTransmission(); // Ends the transmission and transmits the data from the two registers
  Wire.requestFrom(ADXAddress,2); // Request the transmitted two bytes from the two registers
  if(Wire.available()<=2) {  // 
    X0 = Wire.read(); // Reads the data from the register
    X1 = Wire.read();
    /* Converting the raw data of the X-Axis into X-Axis Acceleration */ 
    X1=X1<<8;
    X_out =X0+X1;
    Xa=X_out/256.0; // Xa = output value from -1 to +1, Gravity acceleration acting on the X-Axis
  }
  return Xa;
}


void StarWars(){
  //Play first section
  firstSection();
 
  //Play second section
  secondSection();
 
  delay(650);
}

void beep(int note, int duration){
  //Play tone on buzzerPin
  tone(buzzer1, note, duration);
  tone(buzzer2, note, duration);
 
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0){
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }
  else{
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }
 
  //Stop tone on buzzerPin
  noTone(buzzer1);
  noTone(buzzer2);
  delay(50);
 
  //Increment counter
  counter++;
}
 
void firstSection(){
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
}
 
void secondSection(){
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
 
  delay(325);
 
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
 
  delay(350);
}
