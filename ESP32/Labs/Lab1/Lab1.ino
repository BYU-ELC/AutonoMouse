/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com
*********/

// GPIO where LED is connected to
const int ledPin =  25;

// Handle received and sent messages
String message = "";
char incomingChar;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  digitalWrite(ledPin, LOW);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000.02245);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
