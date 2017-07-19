#ifndef _ROS_katana_msgs_JointMovementAction_h
#define _ROS_katana_msgs_JointMovementAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "katana_msgs/JointMovementActionGoal.h"
#include "katana_msgs/JointMovementActionResult.h"
#include "katana_msgs/JointMovementActionFeedback.h"

namespace katana_msgs
{

  class JointMovementAction : public ros::Msg
  {
    public:
      katana_msgs::JointMovementActionGoal action_goal;
      katana_msgs::JointMovementActionResult action_result;
      katana_msgs::JointMovementActionFeedback action_feedback;

    JointMovementAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "katana_msgs/JointMovementAction"; };
    const char * getMD5(){ return "729d616fa544da9079d58e0ecde6ca21"; };

  };

}
#endif