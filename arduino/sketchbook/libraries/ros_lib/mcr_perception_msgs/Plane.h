#ifndef _ROS_mcr_perception_msgs_Plane_h
#define _ROS_mcr_perception_msgs_Plane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/Vector3Stamped.h"

namespace mcr_perception_msgs
{

  class Plane : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose;
      geometry_msgs::PointStamped plane_point;
      geometry_msgs::Vector3Stamped normal;
      float min_x;
      float max_x;
      float min_y;
      float max_y;

    Plane():
      pose(),
      plane_point(),
      normal(),
      min_x(0),
      max_x(0),
      min_y(0),
      max_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->plane_point.serialize(outbuffer + offset);
      offset += this->normal.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_min_x;
      u_min_x.real = this->min_x;
      *(outbuffer + offset + 0) = (u_min_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_x);
      union {
        float real;
        uint32_t base;
      } u_max_x;
      u_max_x.real = this->max_x;
      *(outbuffer + offset + 0) = (u_max_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_x);
      union {
        float real;
        uint32_t base;
      } u_min_y;
      u_min_y.real = this->min_y;
      *(outbuffer + offset + 0) = (u_min_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_y);
      union {
        float real;
        uint32_t base;
      } u_max_y;
      u_max_y.real = this->max_y;
      *(outbuffer + offset + 0) = (u_max_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->plane_point.deserialize(inbuffer + offset);
      offset += this->normal.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_min_x;
      u_min_x.base = 0;
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_x = u_min_x.real;
      offset += sizeof(this->min_x);
      union {
        float real;
        uint32_t base;
      } u_max_x;
      u_max_x.base = 0;
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_x = u_max_x.real;
      offset += sizeof(this->max_x);
      union {
        float real;
        uint32_t base;
      } u_min_y;
      u_min_y.base = 0;
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_y = u_min_y.real;
      offset += sizeof(this->min_y);
      union {
        float real;
        uint32_t base;
      } u_max_y;
      u_max_y.base = 0;
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_y = u_max_y.real;
      offset += sizeof(this->max_y);
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/Plane"; };
    const char * getMD5(){ return "05b37e43f9417e442406edde209e1a21"; };

  };

}
#endif