# onBoardROSArduino

Repository for arduino code running on-board the aerial robots.

Arduino Programs and ROS Arduino Package with added mg files

## Usage
-git clone the rosserial Package to your catkin Workspace.
-do a catkin_make.
-connect you ardunino through USB and note the PORT(eg. /dev/ttyACM0)
-run roscore
-to start communication with Arduino run the command
```sh
 $ rosrun rosserial_python serial_node.py /dev/PORT

```
replace PORT with your arduino port
-to see the topic 
```sh
 $ rostopic list
```

