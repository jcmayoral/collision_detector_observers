#ifndef _ROS_SERVICE_KnowledgeUpdateServiceArray_h
#define _ROS_SERVICE_KnowledgeUpdateServiceArray_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosplan_knowledge_msgs/KnowledgeItem.h"

namespace rosplan_knowledge_msgs
{

static const char KNOWLEDGEUPDATESERVICEARRAY[] = "rosplan_knowledge_msgs/KnowledgeUpdateServiceArray";

  class KnowledgeUpdateServiceArrayRequest : public ros::Msg
  {
    public:
      uint8_t update_type;
      uint8_t knowledge_length;
      rosplan_knowledge_msgs::KnowledgeItem st_knowledge;
      rosplan_knowledge_msgs::KnowledgeItem * knowledge;
      enum { ADD_KNOWLEDGE =  0 };
      enum { ADD_GOAL =  1 };
      enum { REMOVE_KNOWLEDGE =  2 };
      enum { REMOVE_GOAL =  3 };

    KnowledgeUpdateServiceArrayRequest():
      update_type(0),
      knowledge_length(0), knowledge(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->update_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->update_type);
      *(outbuffer + offset++) = knowledge_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < knowledge_length; i++){
      offset += this->knowledge[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->update_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->update_type);
      uint8_t knowledge_lengthT = *(inbuffer + offset++);
      if(knowledge_lengthT > knowledge_length)
        this->knowledge = (rosplan_knowledge_msgs::KnowledgeItem*)realloc(this->knowledge, knowledge_lengthT * sizeof(rosplan_knowledge_msgs::KnowledgeItem));
      offset += 3;
      knowledge_length = knowledge_lengthT;
      for( uint8_t i = 0; i < knowledge_length; i++){
      offset += this->st_knowledge.deserialize(inbuffer + offset);
        memcpy( &(this->knowledge[i]), &(this->st_knowledge), sizeof(rosplan_knowledge_msgs::KnowledgeItem));
      }
     return offset;
    }

    const char * getType(){ return KNOWLEDGEUPDATESERVICEARRAY; };
    const char * getMD5(){ return "84baa11f46067de28d0a200709674319"; };

  };

  class KnowledgeUpdateServiceArrayResponse : public ros::Msg
  {
    public:
      bool success;

    KnowledgeUpdateServiceArrayResponse():
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

    const char * getType(){ return KNOWLEDGEUPDATESERVICEARRAY; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class KnowledgeUpdateServiceArray {
    public:
    typedef KnowledgeUpdateServiceArrayRequest Request;
    typedef KnowledgeUpdateServiceArrayResponse Response;
  };

}
#endif
