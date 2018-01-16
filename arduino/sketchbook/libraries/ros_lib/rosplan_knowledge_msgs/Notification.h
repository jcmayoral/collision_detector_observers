#ifndef _ROS_rosplan_knowledge_msgs_Notification_h
#define _ROS_rosplan_knowledge_msgs_Notification_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosplan_knowledge_msgs/KnowledgeItem.h"

namespace rosplan_knowledge_msgs
{

  class Notification : public ros::Msg
  {
    public:
      uint8_t function;
      rosplan_knowledge_msgs::KnowledgeItem knowledge_item;
      enum { ADDED =  0 };
      enum { REMOVED =  1 };

    Notification():
      function(0),
      knowledge_item()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->function >> (8 * 0)) & 0xFF;
      offset += sizeof(this->function);
      offset += this->knowledge_item.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->function =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->function);
      offset += this->knowledge_item.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "rosplan_knowledge_msgs/Notification"; };
    const char * getMD5(){ return "dc8b02687f0e69c5faf3b5fd16f19695"; };

  };

}
#endif