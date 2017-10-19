#ifndef _ROS_mcr_perception_msgs_Person_h
#define _ROS_mcr_perception_msgs_Person_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseStamped.h"

namespace mcr_perception_msgs
{

  class Person : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t id;
      geometry_msgs::PoseStamped pose;
      geometry_msgs::PoseStamped safe_pose;
      float height;
      float width;
      float depth;
      bool is_tracked;
      bool is_occluded;
      float probability;

    Person():
      header(),
      id(0),
      pose(),
      safe_pose(),
      height(0),
      width(0),
      depth(0),
      is_tracked(0),
      is_occluded(0),
      probability(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->safe_pose.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      union {
        float real;
        uint32_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      union {
        float real;
        uint32_t base;
      } u_depth;
      u_depth.real = this->depth;
      *(outbuffer + offset + 0) = (u_depth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_depth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_depth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_depth.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->depth);
      union {
        bool real;
        uint8_t base;
      } u_is_tracked;
      u_is_tracked.real = this->is_tracked;
      *(outbuffer + offset + 0) = (u_is_tracked.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_tracked);
      union {
        bool real;
        uint8_t base;
      } u_is_occluded;
      u_is_occluded.real = this->is_occluded;
      *(outbuffer + offset + 0) = (u_is_occluded.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_occluded);
      union {
        float real;
        uint32_t base;
      } u_probability;
      u_probability.real = this->probability;
      *(outbuffer + offset + 0) = (u_probability.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_probability.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_probability.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_probability.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->probability);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->safe_pose.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height = u_height.real;
      offset += sizeof(this->height);
      union {
        float real;
        uint32_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->width = u_width.real;
      offset += sizeof(this->width);
      union {
        float real;
        uint32_t base;
      } u_depth;
      u_depth.base = 0;
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_depth.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->depth = u_depth.real;
      offset += sizeof(this->depth);
      union {
        bool real;
        uint8_t base;
      } u_is_tracked;
      u_is_tracked.base = 0;
      u_is_tracked.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_tracked = u_is_tracked.real;
      offset += sizeof(this->is_tracked);
      union {
        bool real;
        uint8_t base;
      } u_is_occluded;
      u_is_occluded.base = 0;
      u_is_occluded.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_occluded = u_is_occluded.real;
      offset += sizeof(this->is_occluded);
      union {
        float real;
        uint32_t base;
      } u_probability;
      u_probability.base = 0;
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->probability = u_probability.real;
      offset += sizeof(this->probability);
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/Person"; };
    const char * getMD5(){ return "2ad47894be8c58acf6f33abc90ab14ea"; };

  };

}
#endif