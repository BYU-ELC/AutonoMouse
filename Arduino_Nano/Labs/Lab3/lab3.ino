// Lab_03 code
// This program allows you to control a continuous servo through the command line from the Serial Monitor
// Resources
  // video tutorial: https://youtu.be/b_xvu6wWafA
  // original code by BARRAGAN <http://barraganstudio.com> and Scott Fitzgerald
  // servo sweep tutorial: http://www.arduino.cc/en/Tutorial/Sweep

// include servo library
#include <Servo.h>

// create servo object (twelve servo objects can be created on most boards)
Servo myservo;  

void setup() {
  Serial.begin(9600);  // start serial monitor
  myservo.attach(9);  // attaches the servo control wire to pin 9
}

// spin clockwise (to comment, use "/*" and "*/" or "//")
void loop() {
  myservo.write(0);    // moves servo at max speed
} 

// spin counter-clockwise (to uncomment, delete "/*" and "*/"
/*void loop() {
  myservo.write(180);  // moves servo in opposite direction at max speed
}*/
