// ------------------------------------------------------------ //
// ESP32 Ultrasonic Sensor HC-SR04
// Re-writen by Joshua Miller
// Adapted from Arbi Abdul Jabbar
// Using Arduino IDE 1.8.15
// Using DOIT DEVIT V1 ESP32-WROOM-32
// Using HC-SR04 Module
// Tested on 7 July 2021
// ------------------------------------------------------------ //

// defines pin numbers
#define trigPin 2 // attach pin D2 esp32 to pin Echo of HC-SR04
#define echoPin 5 // attach pin D5 esp32 to pin Trig of HC-SR04

// defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Set the echoPin as an Input
  Serial.begin(115200); // Starts the serial communication
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

void loop() {
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
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}
