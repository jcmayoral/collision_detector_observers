#ifndef _ROS_SERVICE_GetPersonList_h
#define _ROS_SERVICE_GetPersonList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mcr_perception_msgs/PersonList.h"

namespace mcr_perception_msgs
{

static const char GETPERSONLIST[] = "mcr_perception_msgs/GetPersonList";

  class GetPersonListRequest : public ros::Msg
  {
    public:

    GetPersonListRequest()
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

    const char * getType(){ return GETPERSONLIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetPersonListResponse : public ros::Msg
  {
    public:
      mcr_perception_msgs::PersonList person_list;

    GetPersonListResponse():
      person_list()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->person_list.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->person_list.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETPERSONLIST; };
    const char * getMD5(){ return "ba0a6d4b8589c583d657d04cce62d50a"; };

  };

  class GetPersonList {
    public:
    typedef GetPersonListRequest Request;
    typedef GetPersonListResponse Response;
  };

}
#endif
