import processing.serial.*;
Serial port;
float brightness = 0;

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
  println(brightness/2.5);
}

void serialEvent(Serial port)
{
  brightness = 25 * float(port.readStringUntil('\n'));
}