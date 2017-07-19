#ifndef _ROS_katana_msgs_JointMovementFeedback_h
#define _ROS_katana_msgs_JointMovementFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace katana_msgs
{

  class JointMovementFeedback : public ros::Msg
  {
    public:

    JointMovementFeedback()
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

    const char * getType(){ return "katana_msgs/JointMovementFeedback"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif