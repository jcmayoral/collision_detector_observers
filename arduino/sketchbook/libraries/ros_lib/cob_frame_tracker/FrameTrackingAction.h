#ifndef _ROS_cob_frame_tracker_FrameTrackingAction_h
#define _ROS_cob_frame_tracker_FrameTrackingAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_frame_tracker/FrameTrackingActionGoal.h"
#include "cob_frame_tracker/FrameTrackingActionResult.h"
#include "cob_frame_tracker/FrameTrackingActionFeedback.h"

namespace cob_frame_tracker
{

  class FrameTrackingAction : public ros::Msg
  {
    public:
      cob_frame_tracker::FrameTrackingActionGoal action_goal;
      cob_frame_tracker::FrameTrackingActionResult action_result;
      cob_frame_tracker::FrameTrackingActionFeedback action_feedback;

    FrameTrackingAction():
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

    const char * getType(){ return "cob_frame_tracker/FrameTrackingAction"; };
    const char * getMD5(){ return "16582ddc5d15eb6f94e19f890cd956ff"; };

  };

}
#endif