#ifndef _ROS_mcr_perception_msgs_MatchingErrorStamped_h
#define _ROS_mcr_perception_msgs_MatchingErrorStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace mcr_perception_msgs
{

  class MatchingErrorStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float matching_error;

    MatchingErrorStamped():
      header(),
      matching_error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_matching_error;
      u_matching_error.real = this->matching_error;
      *(outbuffer + offset + 0) = (u_matching_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_matching_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_matching_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_matching_error.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->matching_error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_matching_error;
      u_matching_error.base = 0;
      u_matching_error.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_matching_error.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_matching_error.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_matching_error.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->matching_error = u_matching_error.real;
      offset += sizeof(this->matching_error);
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/MatchingErrorStamped"; };
    const char * getMD5(){ return "4c43126dba66349dc081c9fe004f4908"; };

  };

}
#endif