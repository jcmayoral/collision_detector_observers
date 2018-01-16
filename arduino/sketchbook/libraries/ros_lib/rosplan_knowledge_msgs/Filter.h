#ifndef _ROS_rosplan_knowledge_msgs_Filter_h
#define _ROS_rosplan_knowledge_msgs_Filter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosplan_knowledge_msgs/KnowledgeItem.h"

namespace rosplan_knowledge_msgs
{

  class Filter : public ros::Msg
  {
    public:
      uint8_t function;
      uint8_t knowledge_items_length;
      rosplan_knowledge_msgs::KnowledgeItem st_knowledge_items;
      rosplan_knowledge_msgs::KnowledgeItem * knowledge_items;
      enum { CLEAR =  0 };
      enum { ADD =  1 };
      enum { REMOVE =  2 };

    Filter():
      function(0),
      knowledge_items_length(0), knowledge_items(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->function >> (8 * 0)) & 0xFF;
      offset += sizeof(this->function);
      *(outbuffer + offset++) = knowledge_items_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < knowledge_items_length; i++){
      offset += this->knowledge_items[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->function =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->function);
      uint8_t knowledge_items_lengthT = *(inbuffer + offset++);
      if(knowledge_items_lengthT > knowledge_items_length)
        this->knowledge_items = (rosplan_knowledge_msgs::KnowledgeItem*)realloc(this->knowledge_items, knowledge_items_lengthT * sizeof(rosplan_knowledge_msgs::KnowledgeItem));
      offset += 3;
      knowledge_items_length = knowledge_items_lengthT;
      for( uint8_t i = 0; i < knowledge_items_length; i++){
      offset += this->st_knowledge_items.deserialize(inbuffer + offset);
        memcpy( &(this->knowledge_items[i]), &(this->st_knowledge_items), sizeof(rosplan_knowledge_msgs::KnowledgeItem));
      }
     return offset;
    }

    const char * getType(){ return "rosplan_knowledge_msgs/Filter"; };
    const char * getMD5(){ return "ffaa5312f028f19664069486a077b599"; };

  };

}
#endif