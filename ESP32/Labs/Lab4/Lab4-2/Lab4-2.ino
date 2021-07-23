// ------------------------------------------------------------ //
// ESP32 Ultrasonic Sensor HC-SR04
// Re-writen by Joshua Miller
// Adapted from Arbi Abdul Jabbar
// Using Arduino IDE 1.8.15
// Using DOIT DEVIT V1 ESP32-WROOM-32
// Using HC-SR04 Module
// Tested on 7 July 2021
// ------------------------------------------------------------ //

// Load libraries
#include "BluetoothSerial.h"

// Check if Bluetooth configs are enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Bluetooth Serial object
BluetoothSerial SerialBT;

// Handle received and sent messages
String message = "";
char incomingChar;
String defaultMsg = "";

// defines pin numbers
#define trigPin 2 // attach pin D2 esp32 to pin Echo of HC-SR04
#define echoPin 5 // attach pin D5 esp32 to pin Trig of HC-SR04

// defines variables
long duration;
int distance;

// TODO: change what is outputed to the console so it outputs the whole word not characters by line

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Set the echoPin as an Input
  // Bluetooth device name
  SerialBT.begin("ESP32");
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.begin(115200); // Starts the serial communication
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

void loop() {
  while(SerialBT.available()){
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
        // Check received message and control output accordingly
      if (message == "HC-SR04_on"){
        // set default message to empty
        defaultMsg = "HC-SR04_on";
        Ping(); // Ping the sensor over and over through the loop
      }
      else if (message =="HC-SR04_off"){
        // do nothing
        defaultMsg = "HC-SR04_off";
      }
      else if (message == "HC-SR04_ping"){
        // set default message to HC-SR04_ping
        defaultMsg = "HC-SR04_ping";
        Ping(); // Ping the sensor once
      }
      delay(20);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);
    SerialBT.write(incomingChar);  
    if (defaultMsg == "HC-SR04_on"){
      Ping();
    }
  }
}

void Ping(){
  // this function pings the ultrasonic sensor and outputs data to the serial monitor
  
  // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculating the distance
    distance = duration*0.034/2; // Speed of sound wave divided by 2 (go and back)
    
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    SerialBT.print("Distance: ");
    Serial.print(distance);
    SerialBT.print(distance);
    Serial.println(" cm");
    SerialBT.println(" cm");
    delay(100);
}
