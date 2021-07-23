#include <NewPing.h>
#include <Servo.h>

#define LEFTSERVO_PIN 13
#define RIGHTSERVO_PIN 33

#define TRIGGER_PIN 14
#define ECHO_PIN 12
#define MAX_DISTANCE 200

#define LeftServoStop 106
#define LeftServoBackward 80
#define LeftServoForward 135

#define RightServoStop 111
#define RightServoBackward 180
#define RightServoForward 0


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo LeftServo;
Servo RightServo;

unsigned int distance = 0;
unsigned int DistanceLeft = 0;
unsigned int DistanceRight = 0;


void setup() {
  LeftServo.attach(LEFTSERVO_PIN);
  RightServo.attach(RIGHTSERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  do {
    delay(100);
    distance = sonar.ping_cm();
    Serial.println(distance);
    DriveStraight(0);
  }  while (distance > 10 || distance == 0);
  Stop();
  DriveBackward(200);
  PivotLeft(900);
  DistanceLeft = sonar.ping_cm();
  Serial.println(DistanceLeft);
  PivotRight(1800);
  DistanceRight = sonar.ping_cm();
  Serial.println(DistanceRight);
  if (DistanceLeft > DistanceRight) {
    PivotLeft(1800);
  }
}

int DriveStraight(int time) {
  LeftServo.write(LeftServoForward);
  RightServo.write(RightServoForward);
  Serial.println("Driving Forward");
  delay(time);
  if (time != 0) {
    Stop();
  }
}

int Stop() {
  LeftServo.write(LeftServoStop);
  RightServo.write(RightServoStop);
  Serial.println("Stopping");
}

int DriveBackward(int time) {
  LeftServo.write(LeftServoBackward);
  RightServo.write(RightServoBackward);
  Serial.println("Driving Backward");
  delay(time);
  if (time != 0) {
    Stop();
  }
}

int PivotLeft(int time) {
  LeftServo.write(LeftServoBackward);
  RightServo.write(RightServoForward);
  Serial.println("Driving Left");
  delay(time);
  if (time != 0) {
    Stop();
  }
}

int PivotRight(int time) {
  LeftServo.write(LeftServoForward);
  RightServo.write(RightServoBackward);
  Serial.println("Driving Right");
  delay(time);
  if (time != 0) {
    Stop();
  }
}
