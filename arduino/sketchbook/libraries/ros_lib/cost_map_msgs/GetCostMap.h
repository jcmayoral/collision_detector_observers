#ifndef _ROS_SERVICE_GetCostMap_h
#define _ROS_SERVICE_GetCostMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cost_map_msgs/CostMap.h"

namespace cost_map_msgs
{

static const char GETCOSTMAP[] = "cost_map_msgs/GetCostMap";

  class GetCostMapRequest : public ros::Msg
  {
    public:
      float length_x;
      float length_y;

    GetCostMapRequest():
      length_x(0),
      length_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->length_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->length_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length_y));
     return offset;
    }

    const char * getType(){ return GETCOSTMAP; };
    const char * getMD5(){ return "028713d4b81b926f787351bfbf8edfd5"; };

  };

  class GetCostMapResponse : public ros::Msg
  {
    public:
      cost_map_msgs::CostMap map;

    GetCostMapResponse():
      map()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->map.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETCOSTMAP; };
    const char * getMD5(){ return "254eaf20ec507fecc981e9c7e14c736b"; };

  };

  class GetCostMap {
    public:
    typedef GetCostMapRequest Request;
    typedef GetCostMapResponse Response;
  };

}
#endif
