#ifndef _ROS_katana_msgs_JointMovementGoal_h
#define _ROS_katana_msgs_JointMovementGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"

namespace katana_msgs
{

  class JointMovementGoal : public ros::Msg
  {
    public:
      sensor_msgs::JointState jointGoal;

    JointMovementGoal():
      jointGoal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->jointGoal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->jointGoal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "katana_msgs/JointMovementGoal"; };
    const char * getMD5(){ return "03f8456b346613dcdf3d0e35b6b1a281"; };

  };

}
#endif