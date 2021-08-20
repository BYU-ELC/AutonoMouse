# AutonoMouse
Lightweight and low cost autonomous robotics platform for students to gain skills and have fun!

There are two version to this project. 

V1's objective is to build a small autonomous car using Arduino Nano as a controller. The car drives forward until sensing an object. When it senses an object it pivots to both sides to find both distances to the nearest object. It then chooses to travel the distance that is greater. 

V2's objective is to build a similiar autonomous car using ESP32 as a controller. However, this version
allow's the user to put the car into remote control mode where the user can control the car via bluetooth
using an Android smartphone. This doesn't work with an IPhone because there are not opensource bluetooth apps 
that I know of in the App Store. 

# Things to Change
Fix the circuit: When Arduino is plugged into the computer placed inside the pcb the AMS1117 voltage regulator on the Arduino gets really hot.
I think it's because the VIN Pin has a direct path to ground through the switch so it's passing a lot of current and gets hot to let off the energy converted. 
I've made a new PCB named Chassis1.1 in the build files that includes a reverse power diode. 
To run with Chassis1.0 the user needs to take out the Arduino to program it and then reinsert it into the PCB.

Clean up the circuity more.

More accessibility for linux and Apple users. Document how to download Arduino IDE and how to interfaces with Arduino devices.

Finish development for V2. Mostly needs work with the servos. I would also suggest removing the ultrasonic sensor and servos and replacing 
them with a cheap motor driver and simple motors to make a faster rc car. 


