#ifndef _ROS_SERVICE_AccumulateTabletopCloud_h
#define _ROS_SERVICE_AccumulateTabletopCloud_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"
#include "mcr_perception_msgs/PlanarPolygon.h"

namespace mcr_perception_msgs
{

static const char ACCUMULATETABLETOPCLOUD[] = "mcr_perception_msgs/AccumulateTabletopCloud";

  class AccumulateTabletopCloudRequest : public ros::Msg
  {
    public:
      mcr_perception_msgs::PlanarPolygon polygon;

    AccumulateTabletopCloudRequest():
      polygon()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->polygon.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->polygon.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ACCUMULATETABLETOPCLOUD; };
    const char * getMD5(){ return "48a24561fa131f5560e9536a71b82138"; };

  };

  class AccumulateTabletopCloudResponse : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 cloud;

    AccumulateTabletopCloudResponse():
      cloud()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->cloud.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->cloud.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ACCUMULATETABLETOPCLOUD; };
    const char * getMD5(){ return "96cec5374164b3b3d1d7ef5d7628a7ed"; };

  };

  class AccumulateTabletopCloud {
    public:
    typedef AccumulateTabletopCloudRequest Request;
    typedef AccumulateTabletopCloudResponse Response;
  };

}
#endif
