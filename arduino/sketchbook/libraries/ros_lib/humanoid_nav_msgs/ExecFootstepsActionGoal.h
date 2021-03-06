#ifndef _ROS_humanoid_nav_msgs_ExecFootstepsActionGoal_h
#define _ROS_humanoid_nav_msgs_ExecFootstepsActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "humanoid_nav_msgs/ExecFootstepsGoal.h"

namespace humanoid_nav_msgs
{

  class ExecFootstepsActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      humanoid_nav_msgs::ExecFootstepsGoal goal;

    ExecFootstepsActionGoal():
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

    const char * getType(){ return "humanoid_nav_msgs/ExecFootstepsActionGoal"; };
    const char * getMD5(){ return "c460c01f665b894cf2e45a340e1a98a9"; };

  };

}
#endif