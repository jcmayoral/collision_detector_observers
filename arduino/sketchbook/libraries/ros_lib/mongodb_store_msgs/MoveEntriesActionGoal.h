#ifndef _ROS_mongodb_store_msgs_MoveEntriesActionGoal_h
#define _ROS_mongodb_store_msgs_MoveEntriesActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "mongodb_store_msgs/MoveEntriesGoal.h"

namespace mongodb_store_msgs
{

  class MoveEntriesActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      mongodb_store_msgs::MoveEntriesGoal goal;

    MoveEntriesActionGoal():
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

    const char * getType(){ return "mongodb_store_msgs/MoveEntriesActionGoal"; };
    const char * getMD5(){ return "4b85bcc1d06680df0b82d7e9b48e4f88"; };

  };

}
#endif