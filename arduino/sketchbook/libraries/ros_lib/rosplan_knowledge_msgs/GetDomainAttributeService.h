#ifndef _ROS_SERVICE_GetDomainAttributeService_h
#define _ROS_SERVICE_GetDomainAttributeService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosplan_knowledge_msgs/DomainFormula.h"

namespace rosplan_knowledge_msgs
{

static const char GETDOMAINATTRIBUTESERVICE[] = "rosplan_knowledge_msgs/GetDomainAttributeService";

  class GetDomainAttributeServiceRequest : public ros::Msg
  {
    public:

    GetDomainAttributeServiceRequest()
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

    const char * getType(){ return GETDOMAINATTRIBUTESERVICE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetDomainAttributeServiceResponse : public ros::Msg
  {
    public:
      uint8_t items_length;
      rosplan_knowledge_msgs::DomainFormula st_items;
      rosplan_knowledge_msgs::DomainFormula * items;

    GetDomainAttributeServiceResponse():
      items_length(0), items(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = items_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < items_length; i++){
      offset += this->items[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t items_lengthT = *(inbuffer + offset++);
      if(items_lengthT > items_length)
        this->items = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->items, items_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      items_length = items_lengthT;
      for( uint8_t i = 0; i < items_length; i++){
      offset += this->st_items.deserialize(inbuffer + offset);
        memcpy( &(this->items[i]), &(this->st_items), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
     return offset;
    }

    const char * getType(){ return GETDOMAINATTRIBUTESERVICE; };
    const char * getMD5(){ return "900aa034059a0ceeaa146f6ab4b7e066"; };

  };

  class GetDomainAttributeService {
    public:
    typedef GetDomainAttributeServiceRequest Request;
    typedef GetDomainAttributeServiceResponse Response;
  };

}
#endif
