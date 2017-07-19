#ifndef _ROS_cob_android_msgs_orderAction_h
#define _ROS_cob_android_msgs_orderAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_android_msgs/orderActionGoal.h"
#include "cob_android_msgs/orderActionResult.h"
#include "cob_android_msgs/orderActionFeedback.h"

namespace cob_android_msgs
{

  class orderAction : public ros::Msg
  {
    public:
      cob_android_msgs::orderActionGoal action_goal;
      cob_android_msgs::orderActionResult action_result;
      cob_android_msgs::orderActionFeedback action_feedback;

    orderAction():
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

    const char * getType(){ return "cob_android_msgs/orderAction"; };
    const char * getMD5(){ return "718b4e9dc9c39a6f66a3279041d454d5"; };

  };

}
#endif