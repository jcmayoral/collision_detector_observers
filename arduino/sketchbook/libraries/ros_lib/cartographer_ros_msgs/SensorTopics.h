#ifndef _ROS_cartographer_ros_msgs_SensorTopics_h
#define _ROS_cartographer_ros_msgs_SensorTopics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cartographer_ros_msgs
{

  class SensorTopics : public ros::Msg
  {
    public:
      const char* laser_scan_topic;
      const char* multi_echo_laser_scan_topic;
      const char* point_cloud2_topic;
      const char* imu_topic;
      const char* odometry_topic;

    SensorTopics():
      laser_scan_topic(""),
      multi_echo_laser_scan_topic(""),
      point_cloud2_topic(""),
      imu_topic(""),
      odometry_topic("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_laser_scan_topic = strlen(this->laser_scan_topic);
      memcpy(outbuffer + offset, &length_laser_scan_topic, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->laser_scan_topic, length_laser_scan_topic);
      offset += length_laser_scan_topic;
      uint32_t length_multi_echo_laser_scan_topic = strlen(this->multi_echo_laser_scan_topic);
      memcpy(outbuffer + offset, &length_multi_echo_laser_scan_topic, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->multi_echo_laser_scan_topic, length_multi_echo_laser_scan_topic);
      offset += length_multi_echo_laser_scan_topic;
      uint32_t length_point_cloud2_topic = strlen(this->point_cloud2_topic);
      memcpy(outbuffer + offset, &length_point_cloud2_topic, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->point_cloud2_topic, length_point_cloud2_topic);
      offset += length_point_cloud2_topic;
      uint32_t length_imu_topic = strlen(this->imu_topic);
      memcpy(outbuffer + offset, &length_imu_topic, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->imu_topic, length_imu_topic);
      offset += length_imu_topic;
      uint32_t length_odometry_topic = strlen(this->odometry_topic);
      memcpy(outbuffer + offset, &length_odometry_topic, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->odometry_topic, length_odometry_topic);
      offset += length_odometry_topic;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_laser_scan_topic;
      memcpy(&length_laser_scan_topic, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_laser_scan_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_laser_scan_topic-1]=0;
      this->laser_scan_topic = (char *)(inbuffer + offset-1);
      offset += length_laser_scan_topic;
      uint32_t length_multi_echo_laser_scan_topic;
      memcpy(&length_multi_echo_laser_scan_topic, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_multi_echo_laser_scan_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_multi_echo_laser_scan_topic-1]=0;
      this->multi_echo_laser_scan_topic = (char *)(inbuffer + offset-1);
      offset += length_multi_echo_laser_scan_topic;
      uint32_t length_point_cloud2_topic;
      memcpy(&length_point_cloud2_topic, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_point_cloud2_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_point_cloud2_topic-1]=0;
      this->point_cloud2_topic = (char *)(inbuffer + offset-1);
      offset += length_point_cloud2_topic;
      uint32_t length_imu_topic;
      memcpy(&length_imu_topic, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_imu_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_imu_topic-1]=0;
      this->imu_topic = (char *)(inbuffer + offset-1);
      offset += length_imu_topic;
      uint32_t length_odometry_topic;
      memcpy(&length_odometry_topic, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_odometry_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_odometry_topic-1]=0;
      this->odometry_topic = (char *)(inbuffer + offset-1);
      offset += length_odometry_topic;
     return offset;
    }

    const char * getType(){ return "cartographer_ros_msgs/SensorTopics"; };
    const char * getMD5(){ return "08e3bbb2adcdea478d2cec7f82a52e90"; };

  };

}
#endif