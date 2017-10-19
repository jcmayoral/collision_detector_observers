#ifndef _ROS_mir_controller_msgs_VisualServoingState_h
#define _ROS_mir_controller_msgs_VisualServoingState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mir_controller_msgs
{

  class VisualServoingState : public ros::Msg
  {
    public:
      int8_t error_code;
      enum { SUCCESS = 0 };
      enum { FAILED = -1 };
      enum { TIMEOUT = -2 };
      enum { LOST_OBJ = -3 };

    VisualServoingState():
      error_code(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_error_code;
      u_error_code.real = this->error_code;
      *(outbuffer + offset + 0) = (u_error_code.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error_code);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_error_code;
      u_error_code.base = 0;
      u_error_code.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->error_code = u_error_code.real;
      offset += sizeof(this->error_code);
     return offset;
    }

    const char * getType(){ return "mir_controller_msgs/VisualServoingState"; };
    const char * getMD5(){ return "27f39bfb2268bbfd5f0f4ba0e74f0756"; };

  };

}
#endif