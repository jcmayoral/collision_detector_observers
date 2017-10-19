#ifndef _ROS_SERVICE_IsGripperClosed_h
#define _ROS_SERVICE_IsGripperClosed_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mir_manipulation_msgs
{

static const char ISGRIPPERCLOSED[] = "mir_manipulation_msgs/IsGripperClosed";

  class IsGripperClosedRequest : public ros::Msg
  {
    public:

    IsGripperClosedRequest()
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

    const char * getType(){ return ISGRIPPERCLOSED; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class IsGripperClosedResponse : public ros::Msg
  {
    public:
      const char* is_closed;

    IsGripperClosedResponse():
      is_closed("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_is_closed = strlen(this->is_closed);
      memcpy(outbuffer + offset, &length_is_closed, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->is_closed, length_is_closed);
      offset += length_is_closed;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_is_closed;
      memcpy(&length_is_closed, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_is_closed; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_is_closed-1]=0;
      this->is_closed = (char *)(inbuffer + offset-1);
      offset += length_is_closed;
     return offset;
    }

    const char * getType(){ return ISGRIPPERCLOSED; };
    const char * getMD5(){ return "825b17dc815c79fbfda36166ccc4602e"; };

  };

  class IsGripperClosed {
    public:
    typedef IsGripperClosedRequest Request;
    typedef IsGripperClosedResponse Response;
  };

}
#endif
