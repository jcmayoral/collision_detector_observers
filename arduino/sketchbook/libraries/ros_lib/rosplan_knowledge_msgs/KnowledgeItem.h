#ifndef _ROS_rosplan_knowledge_msgs_KnowledgeItem_h
#define _ROS_rosplan_knowledge_msgs_KnowledgeItem_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "diagnostic_msgs/KeyValue.h"

namespace rosplan_knowledge_msgs
{

  class KnowledgeItem : public ros::Msg
  {
    public:
      uint8_t knowledge_type;
      const char* instance_type;
      const char* instance_name;
      const char* attribute_name;
      uint8_t values_length;
      diagnostic_msgs::KeyValue st_values;
      diagnostic_msgs::KeyValue * values;
      float function_value;
      bool is_negative;
      enum { INSTANCE =  0 };
      enum { FACT =  1 };
      enum { FUNCTION =  2 };

    KnowledgeItem():
      knowledge_type(0),
      instance_type(""),
      instance_name(""),
      attribute_name(""),
      values_length(0), values(NULL),
      function_value(0),
      is_negative(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->knowledge_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->knowledge_type);
      uint32_t length_instance_type = strlen(this->instance_type);
      memcpy(outbuffer + offset, &length_instance_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->instance_type, length_instance_type);
      offset += length_instance_type;
      uint32_t length_instance_name = strlen(this->instance_name);
      memcpy(outbuffer + offset, &length_instance_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->instance_name, length_instance_name);
      offset += length_instance_name;
      uint32_t length_attribute_name = strlen(this->attribute_name);
      memcpy(outbuffer + offset, &length_attribute_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->attribute_name, length_attribute_name);
      offset += length_attribute_name;
      *(outbuffer + offset++) = values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < values_length; i++){
      offset += this->values[i].serialize(outbuffer + offset);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->function_value);
      union {
        bool real;
        uint8_t base;
      } u_is_negative;
      u_is_negative.real = this->is_negative;
      *(outbuffer + offset + 0) = (u_is_negative.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_negative);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->knowledge_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->knowledge_type);
      uint32_t length_instance_type;
      memcpy(&length_instance_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_instance_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_instance_type-1]=0;
      this->instance_type = (char *)(inbuffer + offset-1);
      offset += length_instance_type;
      uint32_t length_instance_name;
      memcpy(&length_instance_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_instance_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_instance_name-1]=0;
      this->instance_name = (char *)(inbuffer + offset-1);
      offset += length_instance_name;
      uint32_t length_attribute_name;
      memcpy(&length_attribute_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_attribute_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_attribute_name-1]=0;
      this->attribute_name = (char *)(inbuffer + offset-1);
      offset += length_attribute_name;
      uint8_t values_lengthT = *(inbuffer + offset++);
      if(values_lengthT > values_length)
        this->values = (diagnostic_msgs::KeyValue*)realloc(this->values, values_lengthT * sizeof(diagnostic_msgs::KeyValue));
      offset += 3;
      values_length = values_lengthT;
      for( uint8_t i = 0; i < values_length; i++){
      offset += this->st_values.deserialize(inbuffer + offset);
        memcpy( &(this->values[i]), &(this->st_values), sizeof(diagnostic_msgs::KeyValue));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->function_value));
      union {
        bool real;
        uint8_t base;
      } u_is_negative;
      u_is_negative.base = 0;
      u_is_negative.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_negative = u_is_negative.real;
      offset += sizeof(this->is_negative);
     return offset;
    }

    const char * getType(){ return "rosplan_knowledge_msgs/KnowledgeItem"; };
    const char * getMD5(){ return "a4264640d228a4b57e9b41de1d4d7474"; };

  };

}
#endif