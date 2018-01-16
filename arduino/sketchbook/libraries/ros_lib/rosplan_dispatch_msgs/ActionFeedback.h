#ifndef _ROS_rosplan_dispatch_msgs_ActionFeedback_h
#define _ROS_rosplan_dispatch_msgs_ActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "diagnostic_msgs/KeyValue.h"

namespace rosplan_dispatch_msgs
{

  class ActionFeedback : public ros::Msg
  {
    public:
      int32_t action_id;
      const char* status;
      uint8_t information_length;
      diagnostic_msgs::KeyValue st_information;
      diagnostic_msgs::KeyValue * information;

    ActionFeedback():
      action_id(0),
      status(""),
      information_length(0), information(NULL)
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
      uint32_t length_status = strlen(this->status);
      memcpy(outbuffer + offset, &length_status, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
      *(outbuffer + offset++) = information_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < information_length; i++){
      offset += this->information[i].serialize(outbuffer + offset);
      }
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
      uint32_t length_status;
      memcpy(&length_status, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
      uint8_t information_lengthT = *(inbuffer + offset++);
      if(information_lengthT > information_length)
        this->information = (diagnostic_msgs::KeyValue*)realloc(this->information, information_lengthT * sizeof(diagnostic_msgs::KeyValue));
      offset += 3;
      information_length = information_lengthT;
      for( uint8_t i = 0; i < information_length; i++){
      offset += this->st_information.deserialize(inbuffer + offset);
        memcpy( &(this->information[i]), &(this->st_information), sizeof(diagnostic_msgs::KeyValue));
      }
     return offset;
    }

    const char * getType(){ return "rosplan_dispatch_msgs/ActionFeedback"; };
    const char * getMD5(){ return "e28991799802dd700e1390bf56614b89"; };

  };

}
#endif