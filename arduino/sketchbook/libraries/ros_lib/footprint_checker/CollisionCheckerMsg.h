#ifndef _ROS_SERVICE_CollisionCheckerMsg_h
#define _ROS_SERVICE_CollisionCheckerMsg_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseArray.h"

namespace footprint_checker
{

static const char COLLISIONCHECKERMSG[] = "footprint_checker/CollisionCheckerMsg";

  class CollisionCheckerMsgRequest : public ros::Msg
  {
    public:

    CollisionCheckerMsgRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return COLLISIONCHECKERMSG; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class CollisionCheckerMsgResponse : public ros::Msg
  {
    public:
      bool success;
      geometry_msgs::PoseArray potential_collisions;

    CollisionCheckerMsgResponse():
      success(0),
      potential_collisions()
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
      offset += this->potential_collisions.serialize(outbuffer + offset);
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
      offset += this->potential_collisions.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return COLLISIONCHECKERMSG; };
    const char * getMD5(){ return "0d27928e19244406a39cffd824837d90"; };

  };

  class CollisionCheckerMsg {
    public:
    typedef CollisionCheckerMsgRequest Request;
    typedef CollisionCheckerMsgResponse Response;
  };

}
#endif
