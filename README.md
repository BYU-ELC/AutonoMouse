# AutonoMouse
Lightweight and low cost autonomous robotics platform for students to gain skills and have fun!

There are two version to this project. 

V1's objective is to build a small autonomous car using Arduino Nano as a controller. The car drives forward until sensing an object. When it senses an object it pivots to both sides to find both distances to the nearest object. It then chooses to travel the distance that is greater. 

V2's objective is to build a similiar autonomous car using ESP32 as a controller. However, this version
allow's the user to put the car into remote control mode where the user can control the car via bluetooth
using an Android smartphone. This doesn't work with an IPhone because there are not opensource bluetooth apps 
that I know of in the App Store. 

# Things to Change
Fix the circuit. When Arduino is plugged into the computer placed inside the pcb the AMS1117 voltage regulator on the Arduino gets really hot.
It's because the VIN Pin has a direct path to ground through the switch so it's passing a lot of current and gets hot to let off the energy converted. 
Is there way to fix this with a diode? I'm not the best with circuits.
Right now I have to take out the Nano to program it, place it back in, and then power it with the battery. The switch is flipped with the battery activated so there's not the problem with the voltage regulator. 

More accessibility for linux and Apple users. Document how to download Arduino IDE and how to interfaces with Arduino devices.

Finish development for V2. 


