#ifndef _ROS_naoqi_bridge_msgs_JointTrajectoryAction_h
#define _ROS_naoqi_bridge_msgs_JointTrajectoryAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/JointTrajectoryActionGoal.h"
#include "naoqi_bridge_msgs/JointTrajectoryActionResult.h"
#include "naoqi_bridge_msgs/JointTrajectoryActionFeedback.h"

namespace naoqi_bridge_msgs
{

  class JointTrajectoryAction : public ros::Msg
  {
    public:
      naoqi_bridge_msgs::JointTrajectoryActionGoal action_goal;
      naoqi_bridge_msgs::JointTrajectoryActionResult action_result;
      naoqi_bridge_msgs::JointTrajectoryActionFeedback action_feedback;

    JointTrajectoryAction():
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

    const char * getType(){ return "naoqi_bridge_msgs/JointTrajectoryAction"; };
    const char * getMD5(){ return "a88e50dd366fa304954dd433b5706bd8"; };

  };

}
#endif