/*
 * Code created by Joshua Miller
 * 23 July 2021 for BYU's ECEN 191 course
 * 
 * modified code from John Bennett 
 * https://dronebotworkshop.com/esp32-servo/
 * 
 * modified code from Rui Santos
 * Complete project detials at https://randomnerdtutorials.com
 * 
 */

// Load libraries
#include <ESP32Servo.h>
#include "BluetoothSerial.h"
#include <NewPing.h>

// Check if Bluetooth configs are enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Ultrasonic Parmeters
#define TRIGGER_PIN 6
#define ECHO_PIN 7
#define MAX_DISTANCE 200

// Servo objects
Servo myRservo; // create servo object to control the right servo
Servo myLservo; // create servo object to control the left servo
// 16 servo objects can be created on the ESP32

//Ultrasonic Object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
unsigned int distance = 0;

// Bluetooth Serial object
BluetoothSerial SerialBT;

// Handle received and sent messages
String message = "";
char incomingChar;

// State control variable. 0 is autonomous control, 1 is RC
int state = 0;

// Recommended PWM GPIO pins on the ESP32 include 2,7,12-19,21-23,25-27,32-33
// motor pins 13, 12
int rServoPin = 13;
int lServoPin = 12;

// Speed variable for the servos. 0<=speed<=90, 90 fastest
int speed = 10;

void setup() {
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myRservo.setPeriodHertz(50);
  myLservo.setPeriodHertz(50);
  myRservo.attach(rServoPin, 500, 2400); // attaches the right servo on pin 13
  myLservo.attach(lServoPin, 500, 2400); // attaches the left servo on pin 12
  // using default min/max of 1000us and 2000us
  // different servos may require different min/max settings

  Serial.begin(115200);
  // Bluetooth device name
  SerialBT.begin("ESP32");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  while (SerialBT.available()){
    char incomingChar = SerialBT.read();
    Serial.println(incomingChar);

    if (incomingChar == 'x') {
      ChangeState();
    }
    // Check recieved message and control output accordingly
    if (state == 1) {
        // RC control
      switch(incomingChar){
        // G F I
        // L S R
        // H B J
        case 'S':
          // Do nothing
          RightServoStop();
          LeftServoStop();
          break;
        case 'F':
          // Forwards
          RightServoForward(speed);
          LeftServoForward(speed);
          break;
        case 'B':
          // Backwards
          RightServoBackward(speed);
          LeftServoBackward(speed);
          break;
        case 'L':
          // Turn left
          RightServoForward(speed);
          LeftServoBackward(speed);
          break;
        case 'R':
          // turn right
          RightServoBackward(speed);
          LeftServoForward(speed);
          break;
        case 'G':
          // slight forward left
          RightServoForward(speed);
          LeftServoForward(speed/2);
          break;
        case 'I':
          // slight forward right
          RightServoForward(speed/2);
          LeftServoForward(speed);
          break;
        case 'H':
          // slight backward left
          RightServoBackward(speed);
          LeftServoBackward(speed/2);
          break;
        case 'J':
          // slight backward right
          RightServoBackward(speed/2);
          LeftServoBackward(speed);
          break;
        case '1':
          speed = 10;
          break;
        case '2':
          speed = 20;
          break;
        case '3':
          speed = 30;
          break;
        case '4':
          speed = 40;
          break;
        case '5':
          speed = 50;
          break;
        case '6':
          speed = 60;
          break;
        case '7':
          speed = 70;
          break;
        case '8':
          speed = 80;
          break;
        case '9':
          speed = 90;
          break;
      }
    }
    else if (state == 0){
      // Autonomous control
      delay(250);
      distance = sonar.ping_cm();
      Serial.print(distance);
      Serial.println("cm");
      if (distance < 10 && distance != 0){ // sensor registers 0 if longer than 200cm
        Serial.print("Obstacle");
        delay(500);
        RightServoBackward(speed);
        LeftServoBackward(speed);
        delay(500);
        // pivot left
        RightServoForward(speed);
        LeftServoBackward(speed);
        delay(500);
        // check distance
        distance = sonar.ping_cm();
        Serial.print(distance);
        Serial.println("cm");
        int leftDist = distance;
        // pivot right
        RightServoBackward(speed);
        LeftServoForward(speed);
        delay(1000);
        int rightDist = distance;
        // check distance
        if (leftDist > rightDist){
          RightServoForward(speed);
          LeftServoBackward(speed);
          delay(1000);
        }
        // drive the longer of the two
      }      
      RightServoForward(speed);
      LeftServoForward(speed);
    }
    else{
      Serial.println("ERROR!!!");
    }
  }
}

void ChangeState(){
  // This only works if there are 2 states
  if (state == 0){
    state = 1;
  }
  else{
    state = 0;
  }
}

void LeftServoStop(){
  myLservo.write(90);
}

void RightServoStop(){
  myRservo.write(90);
}

void LeftServoForward(int speed){
  myLservo.write(90+speed);
}

void RightServoForward(int speed){
  myRservo.write(90-speed);
}

void LeftServoBackward(int speed){
  myLservo.write(90-speed);
}

void RightServoBackward(int speed){
  myRservo.write(90+speed);
}
