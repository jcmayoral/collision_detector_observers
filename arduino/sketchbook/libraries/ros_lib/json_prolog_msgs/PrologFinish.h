#ifndef _ROS_SERVICE_PrologFinish_h
#define _ROS_SERVICE_PrologFinish_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace json_prolog_msgs
{

static const char PROLOGFINISH[] = "json_prolog_msgs/PrologFinish";

  class PrologFinishRequest : public ros::Msg
  {
    public:
      const char* id;

    PrologFinishRequest():
      id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
     return offset;
    }

    const char * getType(){ return PROLOGFINISH; };
    const char * getMD5(){ return "bbfcda76036ebbe3d36caf7af80b260c"; };

  };

  class PrologFinishResponse : public ros::Msg
  {
    public:

    PrologFinishResponse()
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

    const char * getType(){ return PROLOGFINISH; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class PrologFinish {
    public:
    typedef PrologFinishRequest Request;
    typedef PrologFinishResponse Response;
  };

}
#endif
