//L293D
//Motor A
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B
// const int motorPin3  = 10; // Pin  7 of L293
// const int motorPin4  = 9;  // Pin  2 of L293

//This will run only one time.
void setup(){
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    // pinMode(motorPin3, OUTPUT);
    // pinMode(motorPin4, OUTPUT);
//    digitalWrite(motorPin1, HIGH);
//    digitalWrite(motorPin2, LOW);
//    analogWrite(motorPin1, 255);
//    delay(5000);
//    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4
//
//    //This code  will turn Motor A clockwise for 2 sec.
//    
//    // digitalWrite(motorPin3, LOW);
//    // digitalWrite(motorPin4, LOW); 
//    //This code will turn Motor A counter-clockwise for 2 sec.
//    digitalWrite(motorPin1, LOW);
//    digitalWrite(motorPin2, HIGH);
//    analogWrite(motorPin1, 128);
//    // digitalWrite(motorPin3, LOW);
//    // digitalWrite(motorPin4, LOW);
//    delay(5000);
//    
//    //This code will turn Motor B clockwise for 2 sec.
//    digitalWrite(motorPin1, LOW);
//    digitalWrite(motorPin2, LOW);
//    // digitalWrite(motorPin3, HIGH);
//    // digitalWrite(motorPin4, LOW);
//    delay(5000); 
//    //This code will turn Motor B counter-clockwise for 2 sec.
//    digitalWrite(motorPin1, LOW);
//    digitalWrite(motorPin2, HIGH);
//    analogWrite(motorPin1, 128);
//    // digitalWrite(motorPin3, LOW);
//    // digitalWrite(motorPin4, HIGH);
//    delay(5000);    
//    
//    //And this code will stop motors
//    digitalWrite(motorPin1, LOW);
//    digitalWrite(motorPin2, LOW);
//    // digitalWrite(motorPin3, LOW);
//    // digitalWrite(motorPin4, LOW);
  
}


void loop(){
  analogWrite(motorPin1, 128);
  delay(5000);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorPin1, 255);
  delay(5000);
}

