#ifndef _ROS_SERVICE_StartVisualServoing_h
#define _ROS_SERVICE_StartVisualServoing_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mir_controller_msgs/VisualServoingState.h"

namespace mir_controller_msgs
{

static const char STARTVISUALSERVOING[] = "mir_controller_msgs/StartVisualServoing";

  class StartVisualServoingRequest : public ros::Msg
  {
    public:

    StartVisualServoingRequest()
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

    const char * getType(){ return STARTVISUALSERVOING; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StartVisualServoingResponse : public ros::Msg
  {
    public:
      mir_controller_msgs::VisualServoingState return_value;

    StartVisualServoingResponse():
      return_value()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->return_value.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->return_value.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return STARTVISUALSERVOING; };
    const char * getMD5(){ return "24c17a7517b47e3a75112b3336149a5f"; };

  };

  class StartVisualServoing {
    public:
    typedef StartVisualServoingRequest Request;
    typedef StartVisualServoingResponse Response;
  };

}
#endif
