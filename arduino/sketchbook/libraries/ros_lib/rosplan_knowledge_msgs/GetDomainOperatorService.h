#ifndef _ROS_SERVICE_GetDomainOperatorService_h
#define _ROS_SERVICE_GetDomainOperatorService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosplan_knowledge_msgs/DomainFormula.h"

namespace rosplan_knowledge_msgs
{

static const char GETDOMAINOPERATORSERVICE[] = "rosplan_knowledge_msgs/GetDomainOperatorService";

  class GetDomainOperatorServiceRequest : public ros::Msg
  {
    public:

    GetDomainOperatorServiceRequest()
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

    const char * getType(){ return GETDOMAINOPERATORSERVICE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetDomainOperatorServiceResponse : public ros::Msg
  {
    public:
      uint8_t operators_length;
      rosplan_knowledge_msgs::DomainFormula st_operators;
      rosplan_knowledge_msgs::DomainFormula * operators;

    GetDomainOperatorServiceResponse():
      operators_length(0), operators(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = operators_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < operators_length; i++){
      offset += this->operators[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t operators_lengthT = *(inbuffer + offset++);
      if(operators_lengthT > operators_length)
        this->operators = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->operators, operators_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      operators_length = operators_lengthT;
      for( uint8_t i = 0; i < operators_length; i++){
      offset += this->st_operators.deserialize(inbuffer + offset);
        memcpy( &(this->operators[i]), &(this->st_operators), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
     return offset;
    }

    const char * getType(){ return GETDOMAINOPERATORSERVICE; };
    const char * getMD5(){ return "01315931b687093b9f4ca53107f02d57"; };

  };

  class GetDomainOperatorService {
    public:
    typedef GetDomainOperatorServiceRequest Request;
    typedef GetDomainOperatorServiceResponse Response;
  };

}
#endif
