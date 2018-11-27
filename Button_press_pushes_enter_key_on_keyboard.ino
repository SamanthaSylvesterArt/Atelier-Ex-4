//Samantha, Salisa, Melissa, Mannie
//November 28, 2018
//Atellier 1
//final project


#include <WebUSB.h>
#include "Keyboard.h"


WebUSB WebUSBSerial(1, "drart.github.io/TEI2018/");

#define Serial WebUSBSerial


const int buttonPin = 4;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton
int counter = 0;                  // button push counter

void setup() {
  while (!Serial) {
    ;
  }
  pinMode(4, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.setTimeout(30);
  Serial.write("Sketch begins.\r\n> ");
  Serial.flush();

  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  int buttonState = digitalRead(4);  // read the pushbutton:
  String strval = String(!buttonState);
  Serial.write(strval[0]);
  Serial.write("\r\n");
  Serial.flush();

 
  // if the button state has changed,
  if ((buttonState != previousButtonState)
      // and it's currently pressed:
      && (buttonState == HIGH)) {
    // increment the button counter
    counter++;
    Keyboard.write(KEY_RETURN);
    // type out a message
    Keyboard.print("You pressed the button ");
    Keyboard.print(counter);
    Keyboard.println(" times.");
  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState;
}

