// Lab_06 code
// AutonoMouse control

// libraries ...if there is an error saying it doesn't exist... you will need to add the libraries to your arduino IDE
// ... tools -> Manage Libraries -> enter library name -> install
#include <NewPing.h> // makes ultrasonic sensor easier to use
#include <Servo.h>   // for servos

// constants for...
// ...ultrasonic sensor
#define TRIGGER_PIN 6
#define ECHO_PIN 7
#define MAX_DISTANCE 200

// ...left servo
#define LeftServoStop 90 //was 106
#define LeftServoBackward 0
#define LeftServoForward 180 //was 140

// ...right servo
#define RightServoStop 90 //was 111
#define RightServoBackward 180
#define RightServoForward 0 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo LeftServo;
Servo RightServo;
unsigned int distance = 0;

void setup() {
  LeftServo.attach(11);
  RightServo.attach(3);
  Serial.begin(9600);
}

void loop() {
  do{
   delay(250);
    distance = sonar.ping_cm();
    Serial.print(distance);
    Serial.println("cm");
    DriveStraight(0);
  }  while (distance > 10 || distance == 0);
  delay(500);
  DriveBackward(500);
}

// various and (optional) functions used in the main "void loop" loop
int DriveStraight(int time){
  LeftServo.write(LeftServoForward);
  RightServo.write(RightServoForward);
  delay(time);
}

int DriveBackward(int time){
  LeftServo.write(LeftServoBackward);
  RightServo.write(RightServoBackward);
  delay(time);
}

int PivotLeft(int time){
  LeftServo.write(LeftServoBackward);
  RightServo.write(RightServoForward);
  delay(time);
}

int PivotRight(int time){
  LeftServo.write(LeftServoForward);
  RightServo.write(RightServoBackward);
  delay(time);
}
