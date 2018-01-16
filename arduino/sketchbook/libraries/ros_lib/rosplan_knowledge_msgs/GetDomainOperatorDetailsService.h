#ifndef _ROS_SERVICE_GetDomainOperatorDetailsService_h
#define _ROS_SERVICE_GetDomainOperatorDetailsService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosplan_knowledge_msgs/DomainOperator.h"

namespace rosplan_knowledge_msgs
{

static const char GETDOMAINOPERATORDETAILSSERVICE[] = "rosplan_knowledge_msgs/GetDomainOperatorDetailsService";

  class GetDomainOperatorDetailsServiceRequest : public ros::Msg
  {
    public:
      const char* name;

    GetDomainOperatorDetailsServiceRequest():
      name("")
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
     return offset;
    }

    const char * getType(){ return GETDOMAINOPERATORDETAILSSERVICE; };
    const char * getMD5(){ return "c1f3d28f1b044c871e6eff2e9fc3c667"; };

  };

  class GetDomainOperatorDetailsServiceResponse : public ros::Msg
  {
    public:
      rosplan_knowledge_msgs::DomainOperator op;

    GetDomainOperatorDetailsServiceResponse():
      op()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->op.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->op.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETDOMAINOPERATORDETAILSSERVICE; };
    const char * getMD5(){ return "052890ba8f53a90bccc7aeb79087a057"; };

  };

  class GetDomainOperatorDetailsService {
    public:
    typedef GetDomainOperatorDetailsServiceRequest Request;
    typedef GetDomainOperatorDetailsServiceResponse Response;
  };

}
#endif
