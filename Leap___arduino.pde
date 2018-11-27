import processing.serial.*; 
import de.voidplus.leapmotion.*; 
LeapMotion leap;
Serial myPort; 
void setup() {
  leap = new LeapMotion(this);  
  println(Serial.list());  
  // initializing the port //myPort = new Serial(this,Serial.list()[0], 9600);
} 
void draw() { //

  background(0); //


  for (Hand hand : leap.getHands()) {     
    pushMatrix();     
    float handSize = hand.getSphereRadius();   
    int handSize2 = int(handSize);     
    myPort.write(handSize2);     
    println(handSize2);      
    popMatrix();
  }
} 