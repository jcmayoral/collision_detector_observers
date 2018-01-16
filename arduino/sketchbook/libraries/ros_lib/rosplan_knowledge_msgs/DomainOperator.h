#ifndef _ROS_rosplan_knowledge_msgs_DomainOperator_h
#define _ROS_rosplan_knowledge_msgs_DomainOperator_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosplan_knowledge_msgs/DomainFormula.h"

namespace rosplan_knowledge_msgs
{

  class DomainOperator : public ros::Msg
  {
    public:
      rosplan_knowledge_msgs::DomainFormula formula;
      uint8_t at_start_add_effects_length;
      rosplan_knowledge_msgs::DomainFormula st_at_start_add_effects;
      rosplan_knowledge_msgs::DomainFormula * at_start_add_effects;
      uint8_t at_start_del_effects_length;
      rosplan_knowledge_msgs::DomainFormula st_at_start_del_effects;
      rosplan_knowledge_msgs::DomainFormula * at_start_del_effects;
      uint8_t at_end_add_effects_length;
      rosplan_knowledge_msgs::DomainFormula st_at_end_add_effects;
      rosplan_knowledge_msgs::DomainFormula * at_end_add_effects;
      uint8_t at_end_del_effects_length;
      rosplan_knowledge_msgs::DomainFormula st_at_end_del_effects;
      rosplan_knowledge_msgs::DomainFormula * at_end_del_effects;
      uint8_t at_start_simple_condition_length;
      rosplan_knowledge_msgs::DomainFormula st_at_start_simple_condition;
      rosplan_knowledge_msgs::DomainFormula * at_start_simple_condition;
      uint8_t over_all_simple_condition_length;
      rosplan_knowledge_msgs::DomainFormula st_over_all_simple_condition;
      rosplan_knowledge_msgs::DomainFormula * over_all_simple_condition;
      uint8_t at_end_simple_condition_length;
      rosplan_knowledge_msgs::DomainFormula st_at_end_simple_condition;
      rosplan_knowledge_msgs::DomainFormula * at_end_simple_condition;
      uint8_t at_start_neg_condition_length;
      rosplan_knowledge_msgs::DomainFormula st_at_start_neg_condition;
      rosplan_knowledge_msgs::DomainFormula * at_start_neg_condition;
      uint8_t over_all_neg_condition_length;
      rosplan_knowledge_msgs::DomainFormula st_over_all_neg_condition;
      rosplan_knowledge_msgs::DomainFormula * over_all_neg_condition;
      uint8_t at_end_neg_condition_length;
      rosplan_knowledge_msgs::DomainFormula st_at_end_neg_condition;
      rosplan_knowledge_msgs::DomainFormula * at_end_neg_condition;

    DomainOperator():
      formula(),
      at_start_add_effects_length(0), at_start_add_effects(NULL),
      at_start_del_effects_length(0), at_start_del_effects(NULL),
      at_end_add_effects_length(0), at_end_add_effects(NULL),
      at_end_del_effects_length(0), at_end_del_effects(NULL),
      at_start_simple_condition_length(0), at_start_simple_condition(NULL),
      over_all_simple_condition_length(0), over_all_simple_condition(NULL),
      at_end_simple_condition_length(0), at_end_simple_condition(NULL),
      at_start_neg_condition_length(0), at_start_neg_condition(NULL),
      over_all_neg_condition_length(0), over_all_neg_condition(NULL),
      at_end_neg_condition_length(0), at_end_neg_condition(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->formula.serialize(outbuffer + offset);
      *(outbuffer + offset++) = at_start_add_effects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < at_start_add_effects_length; i++){
      offset += this->at_start_add_effects[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = at_start_del_effects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < at_start_del_effects_length; i++){
      offset += this->at_start_del_effects[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = at_end_add_effects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < at_end_add_effects_length; i++){
      offset += this->at_end_add_effects[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = at_end_del_effects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < at_end_del_effects_length; i++){
      offset += this->at_end_del_effects[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = at_start_simple_condition_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < at_start_simple_condition_length; i++){
      offset += this->at_start_simple_condition[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = over_all_simple_condition_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < over_all_simple_condition_length; i++){
      offset += this->over_all_simple_condition[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = at_end_simple_condition_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < at_end_simple_condition_length; i++){
      offset += this->at_end_simple_condition[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = at_start_neg_condition_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < at_start_neg_condition_length; i++){
      offset += this->at_start_neg_condition[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = over_all_neg_condition_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < over_all_neg_condition_length; i++){
      offset += this->over_all_neg_condition[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = at_end_neg_condition_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < at_end_neg_condition_length; i++){
      offset += this->at_end_neg_condition[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->formula.deserialize(inbuffer + offset);
      uint8_t at_start_add_effects_lengthT = *(inbuffer + offset++);
      if(at_start_add_effects_lengthT > at_start_add_effects_length)
        this->at_start_add_effects = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->at_start_add_effects, at_start_add_effects_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      at_start_add_effects_length = at_start_add_effects_lengthT;
      for( uint8_t i = 0; i < at_start_add_effects_length; i++){
      offset += this->st_at_start_add_effects.deserialize(inbuffer + offset);
        memcpy( &(this->at_start_add_effects[i]), &(this->st_at_start_add_effects), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
      uint8_t at_start_del_effects_lengthT = *(inbuffer + offset++);
      if(at_start_del_effects_lengthT > at_start_del_effects_length)
        this->at_start_del_effects = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->at_start_del_effects, at_start_del_effects_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      at_start_del_effects_length = at_start_del_effects_lengthT;
      for( uint8_t i = 0; i < at_start_del_effects_length; i++){
      offset += this->st_at_start_del_effects.deserialize(inbuffer + offset);
        memcpy( &(this->at_start_del_effects[i]), &(this->st_at_start_del_effects), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
      uint8_t at_end_add_effects_lengthT = *(inbuffer + offset++);
      if(at_end_add_effects_lengthT > at_end_add_effects_length)
        this->at_end_add_effects = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->at_end_add_effects, at_end_add_effects_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      at_end_add_effects_length = at_end_add_effects_lengthT;
      for( uint8_t i = 0; i < at_end_add_effects_length; i++){
      offset += this->st_at_end_add_effects.deserialize(inbuffer + offset);
        memcpy( &(this->at_end_add_effects[i]), &(this->st_at_end_add_effects), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
      uint8_t at_end_del_effects_lengthT = *(inbuffer + offset++);
      if(at_end_del_effects_lengthT > at_end_del_effects_length)
        this->at_end_del_effects = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->at_end_del_effects, at_end_del_effects_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      at_end_del_effects_length = at_end_del_effects_lengthT;
      for( uint8_t i = 0; i < at_end_del_effects_length; i++){
      offset += this->st_at_end_del_effects.deserialize(inbuffer + offset);
        memcpy( &(this->at_end_del_effects[i]), &(this->st_at_end_del_effects), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
      uint8_t at_start_simple_condition_lengthT = *(inbuffer + offset++);
      if(at_start_simple_condition_lengthT > at_start_simple_condition_length)
        this->at_start_simple_condition = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->at_start_simple_condition, at_start_simple_condition_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      at_start_simple_condition_length = at_start_simple_condition_lengthT;
      for( uint8_t i = 0; i < at_start_simple_condition_length; i++){
      offset += this->st_at_start_simple_condition.deserialize(inbuffer + offset);
        memcpy( &(this->at_start_simple_condition[i]), &(this->st_at_start_simple_condition), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
      uint8_t over_all_simple_condition_lengthT = *(inbuffer + offset++);
      if(over_all_simple_condition_lengthT > over_all_simple_condition_length)
        this->over_all_simple_condition = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->over_all_simple_condition, over_all_simple_condition_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      over_all_simple_condition_length = over_all_simple_condition_lengthT;
      for( uint8_t i = 0; i < over_all_simple_condition_length; i++){
      offset += this->st_over_all_simple_condition.deserialize(inbuffer + offset);
        memcpy( &(this->over_all_simple_condition[i]), &(this->st_over_all_simple_condition), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
      uint8_t at_end_simple_condition_lengthT = *(inbuffer + offset++);
      if(at_end_simple_condition_lengthT > at_end_simple_condition_length)
        this->at_end_simple_condition = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->at_end_simple_condition, at_end_simple_condition_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      at_end_simple_condition_length = at_end_simple_condition_lengthT;
      for( uint8_t i = 0; i < at_end_simple_condition_length; i++){
      offset += this->st_at_end_simple_condition.deserialize(inbuffer + offset);
        memcpy( &(this->at_end_simple_condition[i]), &(this->st_at_end_simple_condition), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
      uint8_t at_start_neg_condition_lengthT = *(inbuffer + offset++);
      if(at_start_neg_condition_lengthT > at_start_neg_condition_length)
        this->at_start_neg_condition = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->at_start_neg_condition, at_start_neg_condition_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      at_start_neg_condition_length = at_start_neg_condition_lengthT;
      for( uint8_t i = 0; i < at_start_neg_condition_length; i++){
      offset += this->st_at_start_neg_condition.deserialize(inbuffer + offset);
        memcpy( &(this->at_start_neg_condition[i]), &(this->st_at_start_neg_condition), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
      uint8_t over_all_neg_condition_lengthT = *(inbuffer + offset++);
      if(over_all_neg_condition_lengthT > over_all_neg_condition_length)
        this->over_all_neg_condition = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->over_all_neg_condition, over_all_neg_condition_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      over_all_neg_condition_length = over_all_neg_condition_lengthT;
      for( uint8_t i = 0; i < over_all_neg_condition_length; i++){
      offset += this->st_over_all_neg_condition.deserialize(inbuffer + offset);
        memcpy( &(this->over_all_neg_condition[i]), &(this->st_over_all_neg_condition), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
      uint8_t at_end_neg_condition_lengthT = *(inbuffer + offset++);
      if(at_end_neg_condition_lengthT > at_end_neg_condition_length)
        this->at_end_neg_condition = (rosplan_knowledge_msgs::DomainFormula*)realloc(this->at_end_neg_condition, at_end_neg_condition_lengthT * sizeof(rosplan_knowledge_msgs::DomainFormula));
      offset += 3;
      at_end_neg_condition_length = at_end_neg_condition_lengthT;
      for( uint8_t i = 0; i < at_end_neg_condition_length; i++){
      offset += this->st_at_end_neg_condition.deserialize(inbuffer + offset);
        memcpy( &(this->at_end_neg_condition[i]), &(this->st_at_end_neg_condition), sizeof(rosplan_knowledge_msgs::DomainFormula));
      }
     return offset;
    }

    const char * getType(){ return "rosplan_knowledge_msgs/DomainOperator"; };
    const char * getMD5(){ return "6b4ac8ffcff9013b3ca245e7579517fc"; };

  };

}
#endif