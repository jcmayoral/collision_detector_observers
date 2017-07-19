#ifndef _ROS_cartographer_ros_msgs_TrajectoryOptions_h
#define _ROS_cartographer_ros_msgs_TrajectoryOptions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cartographer_ros_msgs
{

  class TrajectoryOptions : public ros::Msg
  {
    public:
      const char* tracking_frame;
      const char* published_frame;
      const char* odom_frame;
      bool provide_odom_frame;
      bool use_odometry;
      bool use_laser_scan;
      bool use_multi_echo_laser_scan;
      int32_t num_point_clouds;
      const char* trajectory_builder_options_proto;

    TrajectoryOptions():
      tracking_frame(""),
      published_frame(""),
      odom_frame(""),
      provide_odom_frame(0),
      use_odometry(0),
      use_laser_scan(0),
      use_multi_echo_laser_scan(0),
      num_point_clouds(0),
      trajectory_builder_options_proto("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_tracking_frame = strlen(this->tracking_frame);
      memcpy(outbuffer + offset, &length_tracking_frame, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->tracking_frame, length_tracking_frame);
      offset += length_tracking_frame;
      uint32_t length_published_frame = strlen(this->published_frame);
      memcpy(outbuffer + offset, &length_published_frame, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->published_frame, length_published_frame);
      offset += length_published_frame;
      uint32_t length_odom_frame = strlen(this->odom_frame);
      memcpy(outbuffer + offset, &length_odom_frame, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->odom_frame, length_odom_frame);
      offset += length_odom_frame;
      union {
        bool real;
        uint8_t base;
      } u_provide_odom_frame;
      u_provide_odom_frame.real = this->provide_odom_frame;
      *(outbuffer + offset + 0) = (u_provide_odom_frame.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->provide_odom_frame);
      union {
        bool real;
        uint8_t base;
      } u_use_odometry;
      u_use_odometry.real = this->use_odometry;
      *(outbuffer + offset + 0) = (u_use_odometry.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_odometry);
      union {
        bool real;
        uint8_t base;
      } u_use_laser_scan;
      u_use_laser_scan.real = this->use_laser_scan;
      *(outbuffer + offset + 0) = (u_use_laser_scan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_laser_scan);
      union {
        bool real;
        uint8_t base;
      } u_use_multi_echo_laser_scan;
      u_use_multi_echo_laser_scan.real = this->use_multi_echo_laser_scan;
      *(outbuffer + offset + 0) = (u_use_multi_echo_laser_scan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_multi_echo_laser_scan);
      union {
        int32_t real;
        uint32_t base;
      } u_num_point_clouds;
      u_num_point_clouds.real = this->num_point_clouds;
      *(outbuffer + offset + 0) = (u_num_point_clouds.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_point_clouds.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_point_clouds.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_point_clouds.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_point_clouds);
      uint32_t length_trajectory_builder_options_proto = strlen(this->trajectory_builder_options_proto);
      memcpy(outbuffer + offset, &length_trajectory_builder_options_proto, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->trajectory_builder_options_proto, length_trajectory_builder_options_proto);
      offset += length_trajectory_builder_options_proto;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_tracking_frame;
      memcpy(&length_tracking_frame, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tracking_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tracking_frame-1]=0;
      this->tracking_frame = (char *)(inbuffer + offset-1);
      offset += length_tracking_frame;
      uint32_t length_published_frame;
      memcpy(&length_published_frame, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_published_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_published_frame-1]=0;
      this->published_frame = (char *)(inbuffer + offset-1);
      offset += length_published_frame;
      uint32_t length_odom_frame;
      memcpy(&length_odom_frame, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_odom_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_odom_frame-1]=0;
      this->odom_frame = (char *)(inbuffer + offset-1);
      offset += length_odom_frame;
      union {
        bool real;
        uint8_t base;
      } u_provide_odom_frame;
      u_provide_odom_frame.base = 0;
      u_provide_odom_frame.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->provide_odom_frame = u_provide_odom_frame.real;
      offset += sizeof(this->provide_odom_frame);
      union {
        bool real;
        uint8_t base;
      } u_use_odometry;
      u_use_odometry.base = 0;
      u_use_odometry.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_odometry = u_use_odometry.real;
      offset += sizeof(this->use_odometry);
      union {
        bool real;
        uint8_t base;
      } u_use_laser_scan;
      u_use_laser_scan.base = 0;
      u_use_laser_scan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_laser_scan = u_use_laser_scan.real;
      offset += sizeof(this->use_laser_scan);
      union {
        bool real;
        uint8_t base;
      } u_use_multi_echo_laser_scan;
      u_use_multi_echo_laser_scan.base = 0;
      u_use_multi_echo_laser_scan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_multi_echo_laser_scan = u_use_multi_echo_laser_scan.real;
      offset += sizeof(this->use_multi_echo_laser_scan);
      union {
        int32_t real;
        uint32_t base;
      } u_num_point_clouds;
      u_num_point_clouds.base = 0;
      u_num_point_clouds.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_point_clouds.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_point_clouds.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_point_clouds.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_point_clouds = u_num_point_clouds.real;
      offset += sizeof(this->num_point_clouds);
      uint32_t length_trajectory_builder_options_proto;
      memcpy(&length_trajectory_builder_options_proto, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_trajectory_builder_options_proto; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_trajectory_builder_options_proto-1]=0;
      this->trajectory_builder_options_proto = (char *)(inbuffer + offset-1);
      offset += length_trajectory_builder_options_proto;
     return offset;
    }

    const char * getType(){ return "cartographer_ros_msgs/TrajectoryOptions"; };
    const char * getMD5(){ return "622757fb530c57575d011a4b63ad3b48"; };

  };

}
#endif