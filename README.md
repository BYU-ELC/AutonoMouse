# AutonoMouse

## Introduction
Lightweight and low cost autonomous robotics platform for students to gain skills and have fun!

There are two version to this project. 

V1's objective is to build a small autonomous car using Arduino Nano as a controller. The car drives forward until sensing an object. When it senses an object it pivots to both sides to find both distances to the nearest object. It then chooses to travel the distance that is greater. 

V2's objective is to build a similiar autonomous car using ESP32 as a controller. However, this version
allow's the user to put the car into remote control mode where the user can control the car via bluetooth
using an Android smartphone. This doesn't work with an IPhone because there are no opensource bluetooth apps 
that in the App Store. 

## V1 Things to Change
When Arduino is plugged into the computer and placed inside the pcb the AMS1117 voltage regulator on the Arduino gets really hot.
This is because the VIN Pin has a direct path to ground through the switch so it's passing a lot of current and gets hot to let off the energy converted. 
There is a new PCB named Chassis1.1 in the build files that includes a reverse power diode. However it was not used for the project because it would be more complex. 

VERY IMPORTANT: To run AutonoMouse using Arduino Nano Chassis1.0 the user needs to take out the Arduino Nano to program. (Take it out, program it, reinsert, test using battery power) 

More accessibility for Linux and Apple users. Document how to download Arduino IDE and how to interfaces with Arduino devices.

## V2 Things to Change
Finish development for V2. Mostly needs work with the servos. If the ultrasonic sensor was 
and servos were removed from the build it wouldn't be much more expensive to include a 
motor driver and cheap motors, this is a assuming that BYU's ECE shop provides them. 





