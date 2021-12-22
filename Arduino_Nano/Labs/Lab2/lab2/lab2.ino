//Lab_02 
//Blinking Light Code
//This program blinks pin 13 (the built-in LED) on the Arduino

void setup()
{
  pinMode(13, OUTPUT); //sets pin 13 to output power
}

void loop()
{
  digitalWrite(13, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);             // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);             // Wait for 1000 millisecond(s)
}
