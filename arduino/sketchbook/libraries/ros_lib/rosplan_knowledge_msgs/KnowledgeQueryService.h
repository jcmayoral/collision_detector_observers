#ifndef _ROS_SERVICE_KnowledgeQueryService_h
#define _ROS_SERVICE_KnowledgeQueryService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosplan_knowledge_msgs/KnowledgeItem.h"

namespace rosplan_knowledge_msgs
{

static const char KNOWLEDGEQUERYSERVICE[] = "rosplan_knowledge_msgs/KnowledgeQueryService";

  class KnowledgeQueryServiceRequest : public ros::Msg
  {
    public:
      uint8_t knowledge_length;
      rosplan_knowledge_msgs::KnowledgeItem st_knowledge;
      rosplan_knowledge_msgs::KnowledgeItem * knowledge;

    KnowledgeQueryServiceRequest():
      knowledge_length(0), knowledge(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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

    const char * getType(){ return KNOWLEDGEQUERYSERVICE; };
    const char * getMD5(){ return "fb995079ffa218067f095a81faeebec0"; };

  };

  class KnowledgeQueryServiceResponse : public ros::Msg
  {
    public:
      bool all_true;
      uint8_t results_length;
      bool st_results;
      bool * results;
      uint8_t false_knowledge_length;
      rosplan_knowledge_msgs::KnowledgeItem st_false_knowledge;
      rosplan_knowledge_msgs::KnowledgeItem * false_knowledge;

    KnowledgeQueryServiceResponse():
      all_true(0),
      results_length(0), results(NULL),
      false_knowledge_length(0), false_knowledge(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_all_true;
      u_all_true.real = this->all_true;
      *(outbuffer + offset + 0) = (u_all_true.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->all_true);
      *(outbuffer + offset++) = results_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < results_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_resultsi;
      u_resultsi.real = this->results[i];
      *(outbuffer + offset + 0) = (u_resultsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->results[i]);
      }
      *(outbuffer + offset++) = false_knowledge_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < false_knowledge_length; i++){
      offset += this->false_knowledge[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_all_true;
      u_all_true.base = 0;
      u_all_true.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->all_true = u_all_true.real;
      offset += sizeof(this->all_true);
      uint8_t results_lengthT = *(inbuffer + offset++);
      if(results_lengthT > results_length)
        this->results = (bool*)realloc(this->results, results_lengthT * sizeof(bool));
      offset += 3;
      results_length = results_lengthT;
      for( uint8_t i = 0; i < results_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_results;
      u_st_results.base = 0;
      u_st_results.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_results = u_st_results.real;
      offset += sizeof(this->st_results);
        memcpy( &(this->results[i]), &(this->st_results), sizeof(bool));
      }
      uint8_t false_knowledge_lengthT = *(inbuffer + offset++);
      if(false_knowledge_lengthT > false_knowledge_length)
        this->false_knowledge = (rosplan_knowledge_msgs::KnowledgeItem*)realloc(this->false_knowledge, false_knowledge_lengthT * sizeof(rosplan_knowledge_msgs::KnowledgeItem));
      offset += 3;
      false_knowledge_length = false_knowledge_lengthT;
      for( uint8_t i = 0; i < false_knowledge_length; i++){
      offset += this->st_false_knowledge.deserialize(inbuffer + offset);
        memcpy( &(this->false_knowledge[i]), &(this->st_false_knowledge), sizeof(rosplan_knowledge_msgs::KnowledgeItem));
      }
     return offset;
    }

    const char * getType(){ return KNOWLEDGEQUERYSERVICE; };
    const char * getMD5(){ return "7af7b898bbf855cc08a5d09e913b79c9"; };

  };

  class KnowledgeQueryService {
    public:
    typedef KnowledgeQueryServiceRequest Request;
    typedef KnowledgeQueryServiceResponse Response;
  };

}
#endif
