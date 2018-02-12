void setup()
{
  size(400,400);
  background(255);
  smooth();
}

void draw()
{
  noStroke();
  fill(140);
  ellipse(190,256,40,40);
  fill(224,131,131);
  rect(width/2,height/2,40,90);
  arc(190,200,90,90,0,radians(270));
}