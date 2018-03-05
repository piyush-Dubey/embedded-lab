import processing.serial.*;
float brightness;
Serial port;

void setup()
{
  size(500, 500);
  printArray(Serial.list());
  
  String portName = Serial.list()[32];
  port = new Serial(this, portName, 9600);
  port.bufferUntil('\n');
}

void draw()
{
  background(0, 0, brightness);
  println(brightness);
}

void serialEvent(Serial port)
{
  brightness = 100 * float(port.readStringUntil('\n')); // Display blue when object detected and display black color when no object detected
}