#include <SharpIR.h>
#include<ros.h>
#include<rosserial_arduino/sharp.h>

rosserial_arduino::sharp sharp;
ros::NodeHandle nh;
ros::Publisher sharp_pub("sharp", &sharp);

SharpIR sharp0(0, 25, 93, 20150);                           //for n sharp sensors create n SharpIR objects sharpn(pin_no, 25, 93, model_no)
SharpIR sharp1(1, 25, 93, 20150);
SharpIR sharp2(2, 25, 93, 20150);
SharpIR sharp3(3, 25, 93, 20150);
SharpIR sharp4(4, 25, 93, 20150);
SharpIR sharp5(5, 25, 93, 20150);
SharpIR sharp6(6, 25, 93, 20150);
SharpIR sharp7(7, 25, 93, 20150);
void setup() {

  nh.initNode();
  nh.advertise(sharp_pub);
  Serial.begin(57600);// put your setup code here, to run once:

}

void loop() {
  sharp.sharp0 = sharp0.distance();
  sharp.sharp1 = sharp1.distance();
  sharp.sharp2 = sharp2.distance();
  sharp.sharp3 = sharp3.distance();
  sharp.sharp4 = sharp4.distance();
  sharp.sharp5 = sharp5.distance();
  sharp.sharp6 = sharp6.distance();
  sharp.sharp7 = sharp7.distance();
  sharp_pub.publish( &sharp );    
  nh.spinOnce();
  
  /*val0=dis;
  val1=dis1;
  val2=dis2;
  val3=dis3;
  val4=dis4;
  val5=dis5;
  val6=dis6;
  val7=dis7;*/
 /*Serial.print(dis0);
 Serial.print(" ");
 
 Serial.print(dis1);
 Serial.print(" ");
 
 Serial.print(dis2);
 Serial.print(" ");
 
 Serial.print(dis3);
 Serial.print(" ");
 
 Serial.print(dis4);
 Serial.print(" ");
 
 Serial.print(dis5);
 Serial.print(" ");
 
 Serial.print(dis6);
 Serial.print(" ");
 
 Serial.println(dis7);
 Serial.println(" ");// prints the value of the sensor to the serial monitor
  delay(100); // put your main code here, to run repeatedly:
*/
}
