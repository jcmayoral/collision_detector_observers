#ifndef _ROS_cob_android_msgs_orderActionResult_h
#define _ROS_cob_android_msgs_orderActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_android_msgs/orderResult.h"

namespace cob_android_msgs
{

  class orderActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      cob_android_msgs::orderResult result;

    orderActionResult():
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

    const char * getType(){ return "cob_android_msgs/orderActionResult"; };
    const char * getMD5(){ return "e3afff8a8c82fc8b380fb0e0e00a1ba5"; };

  };

}
#endif