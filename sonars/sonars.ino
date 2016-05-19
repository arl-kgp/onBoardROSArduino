
#include <NewPing.h>
#include <ros.h>
#include <rosserial_arduino/sonar.h>

ros::NodeHandle nh;

rosserial_arduino::sonar sonar_msg;
ros::Publisher chatter("sonar_data", &sonar_msg);


#define SONAR_NUM     4 // Number or sensors.
#define MAX_DISTANCE 200 // Max distance in cm.
#define PING_INTERVAL 33 // Milliseconds between pings.

unsigned long pingTimer[SONAR_NUM]; // When each pings.
unsigned int cm[SONAR_NUM]; // Store ping distances.
uint8_t currentSensor = 0; // Which sensor is active.

NewPing sonar[SONAR_NUM] = { // Sensor object array.
  NewPing(41, 42, MAX_DISTANCE),
  NewPing(43, 44, MAX_DISTANCE),
  NewPing(45, 20, MAX_DISTANCE),
  NewPing(21, 22, MAX_DISTANCE),
//  NewPing(23, 24, MAX_DISTANCE),
//  NewPing(25, 26, MAX_DISTANCE),
//  NewPing(27, 28, MAX_DISTANCE),
//  NewPing(29, 30, MAX_DISTANCE),
//  NewPing(31, 32, MAX_DISTANCE),
//  NewPing(34, 33, MAX_DISTANCE),
//  NewPing(35, 36, MAX_DISTANCE),
//  NewPing(37, 38, MAX_DISTANCE),
//  NewPing(39, 40, MAX_DISTANCE),
//  NewPing(50, 51, MAX_DISTANCE),
//  NewPing(52, 53, MAX_DISTANCE)
};

void setup() {
  nh.initNode();
  nh.advertise(chatter);
  Serial.begin(52600);
  pingTimer[0] = millis() + 75; // First ping start in ms.
  for (uint8_t i = 1; i < SONAR_NUM; i++)
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;

}

void loop() {
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    if (millis() >= pingTimer[i]) {
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;
      if (i == 0 && currentSensor == SONAR_NUM - 1)
        oneSensorCycle(); // Do something with results.
      sonar[currentSensor].timer_stop();
      currentSensor = i;
      cm[currentSensor] = 0;
      sonar[currentSensor].ping_timer(echoCheck);
    }
  }
  // The rest of your code would go here.
}

void echoCheck() { // If ping echo, set distance to array.
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() { // Do something with the results.
sonar_msg.sonar0 = cm[0];
sonar_msg.sonar1 = cm[1];
sonar_msg.sonar2 = cm[2];
sonar_msg.sonar3 = cm[3];
nh.spinOnce();
 
}
