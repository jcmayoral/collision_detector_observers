#ifndef _ROS_SERVICE_RecognizeObject_h
#define _ROS_SERVICE_RecognizeObject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"
#include "geometry_msgs/Vector3.h"

namespace mcr_perception_msgs
{

static const char RECOGNIZEOBJECT[] = "mcr_perception_msgs/RecognizeObject";

  class RecognizeObjectRequest : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 cloud;
      geometry_msgs::Vector3 dimensions;

    RecognizeObjectRequest():
      cloud(),
      dimensions()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->cloud.serialize(outbuffer + offset);
      offset += this->dimensions.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->cloud.deserialize(inbuffer + offset);
      offset += this->dimensions.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return RECOGNIZEOBJECT; };
    const char * getMD5(){ return "a314d8ed62f931bb7e705487a5ebef13"; };

  };

  class RecognizeObjectResponse : public ros::Msg
  {
    public:
      const char* name;
      float probability;

    RecognizeObjectResponse():
      name(""),
      probability(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        float real;
        uint32_t base;
      } u_probability;
      u_probability.real = this->probability;
      *(outbuffer + offset + 0) = (u_probability.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_probability.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_probability.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_probability.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->probability);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        float real;
        uint32_t base;
      } u_probability;
      u_probability.base = 0;
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->probability = u_probability.real;
      offset += sizeof(this->probability);
     return offset;
    }

    const char * getType(){ return RECOGNIZEOBJECT; };
    const char * getMD5(){ return "eefea90601ad4fc7c9d8cf72a137d8b7"; };

  };

  class RecognizeObject {
    public:
    typedef RecognizeObjectRequest Request;
    typedef RecognizeObjectResponse Response;
  };

}
#endif
