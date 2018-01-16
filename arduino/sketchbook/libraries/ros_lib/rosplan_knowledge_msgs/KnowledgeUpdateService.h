#ifndef _ROS_SERVICE_KnowledgeUpdateService_h
#define _ROS_SERVICE_KnowledgeUpdateService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosplan_knowledge_msgs/KnowledgeItem.h"

namespace rosplan_knowledge_msgs
{

static const char KNOWLEDGEUPDATESERVICE[] = "rosplan_knowledge_msgs/KnowledgeUpdateService";

  class KnowledgeUpdateServiceRequest : public ros::Msg
  {
    public:
      uint8_t update_type;
      rosplan_knowledge_msgs::KnowledgeItem knowledge;
      enum { ADD_KNOWLEDGE =  0 };
      enum { ADD_GOAL =  1 };
      enum { REMOVE_KNOWLEDGE =  2 };
      enum { REMOVE_GOAL =  3 };

    KnowledgeUpdateServiceRequest():
      update_type(0),
      knowledge()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->update_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->update_type);
      offset += this->knowledge.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->update_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->update_type);
      offset += this->knowledge.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return KNOWLEDGEUPDATESERVICE; };
    const char * getMD5(){ return "84baa11f46067de28d0a200709674319"; };

  };

  class KnowledgeUpdateServiceResponse : public ros::Msg
  {
    public:
      bool success;

    KnowledgeUpdateServiceResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return KNOWLEDGEUPDATESERVICE; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class KnowledgeUpdateService {
    public:
    typedef KnowledgeUpdateServiceRequest Request;
    typedef KnowledgeUpdateServiceResponse Response;
  };

}
#endif
