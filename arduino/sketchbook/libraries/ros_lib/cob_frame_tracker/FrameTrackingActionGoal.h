#ifndef _ROS_cob_frame_tracker_FrameTrackingActionGoal_h
#define _ROS_cob_frame_tracker_FrameTrackingActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "cob_frame_tracker/FrameTrackingGoal.h"

namespace cob_frame_tracker
{

  class FrameTrackingActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      cob_frame_tracker::FrameTrackingGoal goal;

    FrameTrackingActionGoal():
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

    const char * getType(){ return "cob_frame_tracker/FrameTrackingActionGoal"; };
    const char * getMD5(){ return "152fb0b7b7eba5094fe7a58eef570e20"; };

  };

}
#endif