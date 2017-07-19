#ifndef _ROS_cob_frame_tracker_FrameTrackingFeedback_h
#define _ROS_cob_frame_tracker_FrameTrackingFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Twist.h"

namespace cob_frame_tracker
{

  class FrameTrackingFeedback : public ros::Msg
  {
    public:
      geometry_msgs::Twist twist;
      float distance;

    FrameTrackingFeedback():
      twist(),
      distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->twist.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->twist.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
     return offset;
    }

    const char * getType(){ return "cob_frame_tracker/FrameTrackingFeedback"; };
    const char * getMD5(){ return "fe81003ede0829d7392b5d1210ebd6ad"; };

  };

}
#endif