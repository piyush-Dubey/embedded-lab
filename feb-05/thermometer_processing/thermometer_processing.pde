// at the top of the program:
float xPos = 0; // horizontal position of the graph
float yPos = 0; // vertical position of the graph
 
import processing.serial.*;
Serial myPort;        // The serial port
  
void setup () {
  size(800, 600);        // (Width, Height) window size
  
  // List all the available serial ports
  printArray(Serial.list());
  
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  
  background(0);
}
  
void draw () {
   // draw the line in a pretty color:
  stroke(#A8D9A7);
  line(xPos, height, xPos, yPos); // (x1,y1,x2,y2) Origin located at top left corner
  
  // at the edge of the screen, go back to the beginning:
  if (xPos >= width) {
    xPos = 0;
    // clear the screen by resetting the background:
    background(0);
  }
  else {
    // increment the horizontal position for the next reading:
    xPos++;
  }
  while(myPort.available() > 0)
  {
    delay(10);
    String val = myPort.readStringUntil('\n');
    println(val);
    if(val != null && val != "")
    {
      float flByte = float(val);
      int inByte = int(flByte);
      println(inByte);
      yPos = height - inByte;
    }
  }
  // int inByte = myPort.read();
  // println(inByte);
  // yPos = height - 2*inByte;
}
/*  
void serialEvent (Serial myPort) {
  // get the byte:
  int inByte = myPort.read();
  // print it:
  println(inByte);
  
  yPos = height - inByte;
}
*/