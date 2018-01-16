#ifndef _ROS_rosplan_dispatch_msgs_ActionDispatch_h
#define _ROS_rosplan_dispatch_msgs_ActionDispatch_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "diagnostic_msgs/KeyValue.h"

namespace rosplan_dispatch_msgs
{

  class ActionDispatch : public ros::Msg
  {
    public:
      int32_t action_id;
      const char* name;
      uint8_t parameters_length;
      diagnostic_msgs::KeyValue st_parameters;
      diagnostic_msgs::KeyValue * parameters;
      float duration;
      float dispatch_time;

    ActionDispatch():
      action_id(0),
      name(""),
      parameters_length(0), parameters(NULL),
      duration(0),
      dispatch_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_action_id;
      u_action_id.real = this->action_id;
      *(outbuffer + offset + 0) = (u_action_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_action_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_action_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_action_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->action_id);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset++) = parameters_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < parameters_length; i++){
      offset += this->parameters[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_duration;
      u_duration.real = this->duration;
      *(outbuffer + offset + 0) = (u_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_duration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration);
      union {
        float real;
        uint32_t base;
      } u_dispatch_time;
      u_dispatch_time.real = this->dispatch_time;
      *(outbuffer + offset + 0) = (u_dispatch_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dispatch_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dispatch_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dispatch_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dispatch_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_action_id;
      u_action_id.base = 0;
      u_action_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_action_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_action_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_action_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->action_id = u_action_id.real;
      offset += sizeof(this->action_id);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint8_t parameters_lengthT = *(inbuffer + offset++);
      if(parameters_lengthT > parameters_length)
        this->parameters = (diagnostic_msgs::KeyValue*)realloc(this->parameters, parameters_lengthT * sizeof(diagnostic_msgs::KeyValue));
      offset += 3;
      parameters_length = parameters_lengthT;
      for( uint8_t i = 0; i < parameters_length; i++){
      offset += this->st_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->parameters[i]), &(this->st_parameters), sizeof(diagnostic_msgs::KeyValue));
      }
      union {
        float real;
        uint32_t base;
      } u_duration;
      u_duration.base = 0;
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->duration = u_duration.real;
      offset += sizeof(this->duration);
      union {
        float real;
        uint32_t base;
      } u_dispatch_time;
      u_dispatch_time.base = 0;
      u_dispatch_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dispatch_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dispatch_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dispatch_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dispatch_time = u_dispatch_time.real;
      offset += sizeof(this->dispatch_time);
     return offset;
    }

    const char * getType(){ return "rosplan_dispatch_msgs/ActionDispatch"; };
    const char * getMD5(){ return "80f1ebdf8c68451c7e598f98e7f12dba"; };

  };

}
#endif