#ifndef _ROS_mcr_common_msgs_ClosedInterval_h
#define _ROS_mcr_common_msgs_ClosedInterval_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mcr_common_msgs
{

  class ClosedInterval : public ros::Msg
  {
    public:
      float minimum;
      float maximum;

    ClosedInterval():
      minimum(0),
      maximum(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->minimum);
      offset += serializeAvrFloat64(outbuffer + offset, this->maximum);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->minimum));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->maximum));
     return offset;
    }

    const char * getType(){ return "mcr_common_msgs/ClosedInterval"; };
    const char * getMD5(){ return "1c1f9dd515a98b17a631b4ef7a53fcce"; };

  };

}
#endif