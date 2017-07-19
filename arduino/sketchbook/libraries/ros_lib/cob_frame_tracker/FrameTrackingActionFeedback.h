#ifndef _ROS_cob_frame_tracker_FrameTrackingActionFeedback_h
#define _ROS_cob_frame_tracker_FrameTrackingActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_frame_tracker/FrameTrackingFeedback.h"

namespace cob_frame_tracker
{

  class FrameTrackingActionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      cob_frame_tracker::FrameTrackingFeedback feedback;

    FrameTrackingActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_frame_tracker/FrameTrackingActionFeedback"; };
    const char * getMD5(){ return "573aea66953e661a14108f1ca29d7710"; };

  };

}
#endif