#include <Servo.h>

// 0 is forward 

#define ServoForward 180
#define ServoBackward 0
#define ServoStop 90

Servo myservo;
int i=0;

void setup() {
  myservo.attach(11);
  myservo.write(180);
  //myservo.write(180);
}

void loop() { 
}
