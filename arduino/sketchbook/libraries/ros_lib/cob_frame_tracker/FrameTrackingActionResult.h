#ifndef _ROS_cob_frame_tracker_FrameTrackingActionResult_h
#define _ROS_cob_frame_tracker_FrameTrackingActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_frame_tracker/FrameTrackingResult.h"

namespace cob_frame_tracker
{

  class FrameTrackingActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      cob_frame_tracker::FrameTrackingResult result;

    FrameTrackingActionResult():
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

    const char * getType(){ return "cob_frame_tracker/FrameTrackingActionResult"; };
    const char * getMD5(){ return "1471476fb0fc7d1ce25819ffcafc3f6d"; };

  };

}
#endif