#ifndef _ROS_SERVICE_GetNearestObject_h
#define _ROS_SERVICE_GetNearestObject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace mcr_perception_msgs
{

static const char GETNEARESTOBJECT[] = "mcr_perception_msgs/GetNearestObject";

  class GetNearestObjectRequest : public ros::Msg
  {
    public:

    GetNearestObjectRequest()
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

    const char * getType(){ return GETNEARESTOBJECT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetNearestObjectResponse : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose;

    GetNearestObjectResponse():
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETNEARESTOBJECT; };
    const char * getMD5(){ return "f192399f711a48924df9a394d37edd67"; };

  };

  class GetNearestObject {
    public:
    typedef GetNearestObjectRequest Request;
    typedef GetNearestObjectResponse Response;
  };

}
#endif
