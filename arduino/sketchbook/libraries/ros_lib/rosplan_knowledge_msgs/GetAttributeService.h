#ifndef _ROS_SERVICE_GetAttributeService_h
#define _ROS_SERVICE_GetAttributeService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosplan_knowledge_msgs/KnowledgeItem.h"

namespace rosplan_knowledge_msgs
{

static const char GETATTRIBUTESERVICE[] = "rosplan_knowledge_msgs/GetAttributeService";

  class GetAttributeServiceRequest : public ros::Msg
  {
    public:
      const char* predicate_name;

    GetAttributeServiceRequest():
      predicate_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_predicate_name = strlen(this->predicate_name);
      memcpy(outbuffer + offset, &length_predicate_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->predicate_name, length_predicate_name);
      offset += length_predicate_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_predicate_name;
      memcpy(&length_predicate_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_predicate_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_predicate_name-1]=0;
      this->predicate_name = (char *)(inbuffer + offset-1);
      offset += length_predicate_name;
     return offset;
    }

    const char * getType(){ return GETATTRIBUTESERVICE; };
    const char * getMD5(){ return "130dad30028f4055312b63b35c17d1c3"; };

  };

  class GetAttributeServiceResponse : public ros::Msg
  {
    public:
      uint8_t attributes_length;
      rosplan_knowledge_msgs::KnowledgeItem st_attributes;
      rosplan_knowledge_msgs::KnowledgeItem * attributes;

    GetAttributeServiceResponse():
      attributes_length(0), attributes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = attributes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < attributes_length; i++){
      offset += this->attributes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t attributes_lengthT = *(inbuffer + offset++);
      if(attributes_lengthT > attributes_length)
        this->attributes = (rosplan_knowledge_msgs::KnowledgeItem*)realloc(this->attributes, attributes_lengthT * sizeof(rosplan_knowledge_msgs::KnowledgeItem));
      offset += 3;
      attributes_length = attributes_lengthT;
      for( uint8_t i = 0; i < attributes_length; i++){
      offset += this->st_attributes.deserialize(inbuffer + offset);
        memcpy( &(this->attributes[i]), &(this->st_attributes), sizeof(rosplan_knowledge_msgs::KnowledgeItem));
      }
     return offset;
    }

    const char * getType(){ return GETATTRIBUTESERVICE; };
    const char * getMD5(){ return "4346d5c15a13ae8ec3736496416e2ac4"; };

  };

  class GetAttributeService {
    public:
    typedef GetAttributeServiceRequest Request;
    typedef GetAttributeServiceResponse Response;
  };

}
#endif
