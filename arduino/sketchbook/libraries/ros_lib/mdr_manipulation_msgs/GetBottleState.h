#ifndef _ROS_SERVICE_GetBottleState_h
#define _ROS_SERVICE_GetBottleState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mdr_manipulation_msgs
{

static const char GETBOTTLESTATE[] = "mdr_manipulation_msgs/GetBottleState";

  class GetBottleStateRequest : public ros::Msg
  {
    public:

    GetBottleStateRequest()
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

    const char * getType(){ return GETBOTTLESTATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetBottleStateResponse : public ros::Msg
  {
    public:
      int8_t state;
      enum { NO_BOTTLE_GRASPED =  1 };
      enum { EMPTY =  2 };
      enum { HALF_FULL =  3 };
      enum { FULL =  4 };

    GetBottleStateResponse():
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
     return offset;
    }

    const char * getType(){ return GETBOTTLESTATE; };
    const char * getMD5(){ return "4a10c2c0704469b0be3b4cce617b9ee3"; };

  };

  class GetBottleState {
    public:
    typedef GetBottleStateRequest Request;
    typedef GetBottleStateResponse Response;
  };

}
#endif
