#ifndef _ROS_SERVICE_SetSensitivity_h
#define _ROS_SERVICE_SetSensitivity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

static const char SETSENSITIVITY[] = "naoqi_bridge_msgs/SetSensitivity";

  class SetSensitivityRequest : public ros::Msg
  {
    public:
      float sensitivity;

    SetSensitivityRequest():
      sensitivity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->sensitivity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sensitivity));
     return offset;
    }

    const char * getType(){ return SETSENSITIVITY; };
    const char * getMD5(){ return "078f85c75d4cc7e07e0ea4c63eada6f2"; };

  };

  class SetSensitivityResponse : public ros::Msg
  {
    public:
      bool success;

    SetSensitivityResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return SETSENSITIVITY; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetSensitivity {
    public:
    typedef SetSensitivityRequest Request;
    typedef SetSensitivityResponse Response;
  };

}
#endif
