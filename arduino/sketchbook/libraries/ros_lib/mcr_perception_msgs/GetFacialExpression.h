#ifndef _ROS_SERVICE_GetFacialExpression_h
#define _ROS_SERVICE_GetFacialExpression_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mcr_perception_msgs
{

static const char GETFACIALEXPRESSION[] = "mcr_perception_msgs/GetFacialExpression";

  class GetFacialExpressionRequest : public ros::Msg
  {
    public:

    GetFacialExpressionRequest()
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

    const char * getType(){ return GETFACIALEXPRESSION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetFacialExpressionResponse : public ros::Msg
  {
    public:
      const char* value;

    GetFacialExpressionResponse():
      value("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_value = strlen(this->value);
      memcpy(outbuffer + offset, &length_value, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_value;
      memcpy(&length_value, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
     return offset;
    }

    const char * getType(){ return GETFACIALEXPRESSION; };
    const char * getMD5(){ return "64e58419496c7248b4ef25731f88b8c3"; };

  };

  class GetFacialExpression {
    public:
    typedef GetFacialExpressionRequest Request;
    typedef GetFacialExpressionResponse Response;
  };

}
#endif
