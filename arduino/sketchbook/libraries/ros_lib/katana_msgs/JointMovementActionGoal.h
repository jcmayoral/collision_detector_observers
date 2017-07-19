#ifndef _ROS_katana_msgs_JointMovementActionGoal_h
#define _ROS_katana_msgs_JointMovementActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "katana_msgs/JointMovementGoal.h"

namespace katana_msgs
{

  class JointMovementActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      katana_msgs::JointMovementGoal goal;

    JointMovementActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "katana_msgs/JointMovementActionGoal"; };
    const char * getMD5(){ return "2b6e9b9692b7ab0a124ca0558966f79a"; };

  };

}
#endif