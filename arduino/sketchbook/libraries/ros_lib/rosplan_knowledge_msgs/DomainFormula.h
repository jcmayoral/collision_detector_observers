#ifndef _ROS_rosplan_knowledge_msgs_DomainFormula_h
#define _ROS_rosplan_knowledge_msgs_DomainFormula_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "diagnostic_msgs/KeyValue.h"

namespace rosplan_knowledge_msgs
{

  class DomainFormula : public ros::Msg
  {
    public:
      const char* name;
      uint8_t typed_parameters_length;
      diagnostic_msgs::KeyValue st_typed_parameters;
      diagnostic_msgs::KeyValue * typed_parameters;

    DomainFormula():
      name(""),
      typed_parameters_length(0), typed_parameters(NULL)
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
      *(outbuffer + offset++) = typed_parameters_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < typed_parameters_length; i++){
      offset += this->typed_parameters[i].serialize(outbuffer + offset);
      }
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
      uint8_t typed_parameters_lengthT = *(inbuffer + offset++);
      if(typed_parameters_lengthT > typed_parameters_length)
        this->typed_parameters = (diagnostic_msgs::KeyValue*)realloc(this->typed_parameters, typed_parameters_lengthT * sizeof(diagnostic_msgs::KeyValue));
      offset += 3;
      typed_parameters_length = typed_parameters_lengthT;
      for( uint8_t i = 0; i < typed_parameters_length; i++){
      offset += this->st_typed_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->typed_parameters[i]), &(this->st_typed_parameters), sizeof(diagnostic_msgs::KeyValue));
      }
     return offset;
    }

    const char * getType(){ return "rosplan_knowledge_msgs/DomainFormula"; };
    const char * getMD5(){ return "b9c7cfc3aa64764d3a82f96d3671bab1"; };

  };

}
#endif