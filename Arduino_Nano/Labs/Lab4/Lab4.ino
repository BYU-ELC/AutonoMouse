// Lab_04 code
// Arduino Ultrasoninc Sensor HC-SR04
// This program measures the time it takes a sound wave to travel to, and bounce back from an object in front of the sensor,
// and calculates the distance (in cm) that object is, based on the speed of sound

#define echoPin 7 // attach pin D7 Arduino to pin Echo of HC-SR04
#define trigPin 6 // attach pin D6 Arduino to pin Trig of HC-SR04

// variables
long duration; // variable for the duration of sound wave travel
int distance;  // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);  // Sets the echoPin as an INPUT
  Serial.begin(9600);       // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
