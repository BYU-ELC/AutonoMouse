# AutonoMouse
Lightweight and low cost autonomous robotics platform for students to gain skills and have fun!

There are two version to this project. 

V1: is built around Arduino Nano
V2: is build around ESP32

V1's objective is to build a small autonomous car using Arduino Nano as a controller. The car drives 
forward until sensing an object. When it senses an object it pivots to both sides to find both distances to 
the nearest object. It then chooses to travel the distance that is greater. 

V2's objective is to build a similiar autonomous car using ESP32 as a controller. However, this version
allow's the user to put the car into remote control mode where the user can control the car via bluetooth
using an Android smartphone. This doesn't work with an Iphone because there are not opensource bluetooth apps 
that I know of in the App Store. 