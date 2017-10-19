#ifndef _ROS_SERVICE_Pickup_h
#define _ROS_SERVICE_Pickup_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"

namespace mdr_behavior_msgs
{

static const char PICKUP[] = "mdr_behavior_msgs/Pickup";

  class PickupRequest : public ros::Msg
  {
    public:
      geometry_msgs::PointStamped position;

    PickupRequest():
      position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PICKUP; };
    const char * getMD5(){ return "1ed0e92ededc007c2e5729582f354ee1"; };

  };

  class PickupResponse : public ros::Msg
  {
    public:
      bool success;

    PickupResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return PICKUP; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class Pickup {
    public:
    typedef PickupRequest Request;
    typedef PickupResponse Response;
  };

}
#endif
