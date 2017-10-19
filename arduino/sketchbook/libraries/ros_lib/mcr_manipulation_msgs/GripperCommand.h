#ifndef _ROS_mcr_manipulation_msgs_GripperCommand_h
#define _ROS_mcr_manipulation_msgs_GripperCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mcr_manipulation_msgs
{

  class GripperCommand : public ros::Msg
  {
    public:
      int32_t command;
      enum { OPEN =  0 };
      enum { CLOSE =  1 };

    GripperCommand():
      command(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_command;
      u_command.real = this->command;
      *(outbuffer + offset + 0) = (u_command.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_command.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_command.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_command.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->command);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_command;
      u_command.base = 0;
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->command = u_command.real;
      offset += sizeof(this->command);
     return offset;
    }

    const char * getType(){ return "mcr_manipulation_msgs/GripperCommand"; };
    const char * getMD5(){ return "66cc2e459a9e7908ce52dd06f60fe935"; };

  };

}
#endif