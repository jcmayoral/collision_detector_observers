#ifndef _ROS_SERVICE_IsPersonInFront_h
#define _ROS_SERVICE_IsPersonInFront_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mcr_perception_msgs
{

static const char ISPERSONINFRONT[] = "mcr_perception_msgs/IsPersonInFront";

  class IsPersonInFrontRequest : public ros::Msg
  {
    public:

    IsPersonInFrontRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return ISPERSONINFRONT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class IsPersonInFrontResponse : public ros::Msg
  {
    public:
      bool value;

    IsPersonInFrontResponse():
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return ISPERSONINFRONT; };
    const char * getMD5(){ return "e431d687bf4b2c65fbd94b12ae0cb5d9"; };

  };

  class IsPersonInFront {
    public:
    typedef IsPersonInFrontRequest Request;
    typedef IsPersonInFrontResponse Response;
  };

}
#endif
