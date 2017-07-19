#ifndef _ROS_katana_msgs_JointMovementActionResult_h
#define _ROS_katana_msgs_JointMovementActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "katana_msgs/JointMovementResult.h"

namespace katana_msgs
{

  class JointMovementActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      katana_msgs::JointMovementResult result;

    JointMovementActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "katana_msgs/JointMovementActionResult"; };
    const char * getMD5(){ return "1eb06eeff08fa7ea874431638cb52332"; };

  };

}
#endif