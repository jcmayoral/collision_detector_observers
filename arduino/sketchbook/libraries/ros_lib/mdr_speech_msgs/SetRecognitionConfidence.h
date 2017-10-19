#ifndef _ROS_SERVICE_SetRecognitionConfidence_h
#define _ROS_SERVICE_SetRecognitionConfidence_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mdr_speech_msgs
{

static const char SETRECOGNITIONCONFIDENCE[] = "mdr_speech_msgs/SetRecognitionConfidence";

  class SetRecognitionConfidenceRequest : public ros::Msg
  {
    public:
      float threshold;

    SetRecognitionConfidenceRequest():
      threshold(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_threshold;
      u_threshold.real = this->threshold;
      *(outbuffer + offset + 0) = (u_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->threshold);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_threshold;
      u_threshold.base = 0;
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->threshold = u_threshold.real;
      offset += sizeof(this->threshold);
     return offset;
    }

    const char * getType(){ return SETRECOGNITIONCONFIDENCE; };
    const char * getMD5(){ return "762b8eff81569601a12f7a5cd61b8c26"; };

  };

  class SetRecognitionConfidenceResponse : public ros::Msg
  {
    public:

    SetRecognitionConfidenceResponse()
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

    const char * getType(){ return SETRECOGNITIONCONFIDENCE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetRecognitionConfidence {
    public:
    typedef SetRecognitionConfidenceRequest Request;
    typedef SetRecognitionConfidenceResponse Response;
  };

}
#endif
