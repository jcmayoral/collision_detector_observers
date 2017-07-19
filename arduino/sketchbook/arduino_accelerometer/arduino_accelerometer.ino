/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/AccelStamped.h>

ros::NodeHandle nh;

std_msgs::String str_msg;
geometry_msgs::AccelStamped acc_msg;
ros::Publisher chatter("chatter", &str_msg);
ros::Publisher acc_pub("accel", &acc_msg);


char hello[13] = "hello world!";

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  nh.advertise(acc_pub);

}

void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  acc_pub.publish( &acc_msg );
  nh.spinOnce();
  delay(10);
}
