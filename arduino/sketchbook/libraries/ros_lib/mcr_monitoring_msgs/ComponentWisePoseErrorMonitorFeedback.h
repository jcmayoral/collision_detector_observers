#ifndef _ROS_mcr_monitoring_msgs_ComponentWisePoseErrorMonitorFeedback_h
#define _ROS_mcr_monitoring_msgs_ComponentWisePoseErrorMonitorFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace mcr_monitoring_msgs
{

  class ComponentWisePoseErrorMonitorFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      bool is_linear_x_within_tolerance;
      bool is_linear_y_within_tolerance;
      bool is_linear_z_within_tolerance;
      bool is_angular_x_within_tolerance;
      bool is_angular_y_within_tolerance;
      bool is_angular_z_within_tolerance;

    ComponentWisePoseErrorMonitorFeedback():
      header(),
      is_linear_x_within_tolerance(0),
      is_linear_y_within_tolerance(0),
      is_linear_z_within_tolerance(0),
      is_angular_x_within_tolerance(0),
      is_angular_y_within_tolerance(0),
      is_angular_z_within_tolerance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_linear_x_within_tolerance;
      u_is_linear_x_within_tolerance.real = this->is_linear_x_within_tolerance;
      *(outbuffer + offset + 0) = (u_is_linear_x_within_tolerance.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_linear_x_within_tolerance);
      union {
        bool real;
        uint8_t base;
      } u_is_linear_y_within_tolerance;
      u_is_linear_y_within_tolerance.real = this->is_linear_y_within_tolerance;
      *(outbuffer + offset + 0) = (u_is_linear_y_within_tolerance.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_linear_y_within_tolerance);
      union {
        bool real;
        uint8_t base;
      } u_is_linear_z_within_tolerance;
      u_is_linear_z_within_tolerance.real = this->is_linear_z_within_tolerance;
      *(outbuffer + offset + 0) = (u_is_linear_z_within_tolerance.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_linear_z_within_tolerance);
      union {
        bool real;
        uint8_t base;
      } u_is_angular_x_within_tolerance;
      u_is_angular_x_within_tolerance.real = this->is_angular_x_within_tolerance;
      *(outbuffer + offset + 0) = (u_is_angular_x_within_tolerance.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_angular_x_within_tolerance);
      union {
        bool real;
        uint8_t base;
      } u_is_angular_y_within_tolerance;
      u_is_angular_y_within_tolerance.real = this->is_angular_y_within_tolerance;
      *(outbuffer + offset + 0) = (u_is_angular_y_within_tolerance.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_angular_y_within_tolerance);
      union {
        bool real;
        uint8_t base;
      } u_is_angular_z_within_tolerance;
      u_is_angular_z_within_tolerance.real = this->is_angular_z_within_tolerance;
      *(outbuffer + offset + 0) = (u_is_angular_z_within_tolerance.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_angular_z_within_tolerance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_linear_x_within_tolerance;
      u_is_linear_x_within_tolerance.base = 0;
      u_is_linear_x_within_tolerance.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_linear_x_within_tolerance = u_is_linear_x_within_tolerance.real;
      offset += sizeof(this->is_linear_x_within_tolerance);
      union {
        bool real;
        uint8_t base;
      } u_is_linear_y_within_tolerance;
      u_is_linear_y_within_tolerance.base = 0;
      u_is_linear_y_within_tolerance.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_linear_y_within_tolerance = u_is_linear_y_within_tolerance.real;
      offset += sizeof(this->is_linear_y_within_tolerance);
      union {
        bool real;
        uint8_t base;
      } u_is_linear_z_within_tolerance;
      u_is_linear_z_within_tolerance.base = 0;
      u_is_linear_z_within_tolerance.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_linear_z_within_tolerance = u_is_linear_z_within_tolerance.real;
      offset += sizeof(this->is_linear_z_within_tolerance);
      union {
        bool real;
        uint8_t base;
      } u_is_angular_x_within_tolerance;
      u_is_angular_x_within_tolerance.base = 0;
      u_is_angular_x_within_tolerance.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_angular_x_within_tolerance = u_is_angular_x_within_tolerance.real;
      offset += sizeof(this->is_angular_x_within_tolerance);
      union {
        bool real;
        uint8_t base;
      } u_is_angular_y_within_tolerance;
      u_is_angular_y_within_tolerance.base = 0;
      u_is_angular_y_within_tolerance.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_angular_y_within_tolerance = u_is_angular_y_within_tolerance.real;
      offset += sizeof(this->is_angular_y_within_tolerance);
      union {
        bool real;
        uint8_t base;
      } u_is_angular_z_within_tolerance;
      u_is_angular_z_within_tolerance.base = 0;
      u_is_angular_z_within_tolerance.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_angular_z_within_tolerance = u_is_angular_z_within_tolerance.real;
      offset += sizeof(this->is_angular_z_within_tolerance);
     return offset;
    }

    const char * getType(){ return "mcr_monitoring_msgs/ComponentWisePoseErrorMonitorFeedback"; };
    const char * getMD5(){ return "c25b22ed6fd0e9ae07864c8107b8793b"; };

  };

}
#endif