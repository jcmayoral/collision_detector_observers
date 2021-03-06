#ifndef _ROS_rosjava_test_msgs_CompositeA_h
#define _ROS_rosjava_test_msgs_CompositeA_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosjava_test_msgs
{

  class CompositeA : public ros::Msg
  {
    public:
      float x;
      float y;
      float z;
      float w;

    CompositeA():
      x(0),
      y(0),
      z(0),
      w(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->z);
      offset += serializeAvrFloat64(outbuffer + offset, this->w);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->w));
     return offset;
    }

    const char * getType(){ return "rosjava_test_msgs/CompositeA"; };
    const char * getMD5(){ return "a779879fadf0160734f906b8c19c7004"; };

  };

}
#endif