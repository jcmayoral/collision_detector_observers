#ifndef _ROS_data_vis_msgs_Task_h
#define _ROS_data_vis_msgs_Task_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace data_vis_msgs
{

  class Task : public ros::Msg
  {
    public:
      int32_t id;
      int32_t parent;
      const char* color;
      const char* info;
      const char* type;

    Task():
      id(0),
      parent(0),
      color(""),
      info(""),
      type("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_parent;
      u_parent.real = this->parent;
      *(outbuffer + offset + 0) = (u_parent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_parent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_parent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_parent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parent);
      uint32_t length_color = strlen(this->color);
      memcpy(outbuffer + offset, &length_color, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->color, length_color);
      offset += length_color;
      uint32_t length_info = strlen(this->info);
      memcpy(outbuffer + offset, &length_info, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->info, length_info);
      offset += length_info;
      uint32_t length_type = strlen(this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_parent;
      u_parent.base = 0;
      u_parent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_parent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_parent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_parent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->parent = u_parent.real;
      offset += sizeof(this->parent);
      uint32_t length_color;
      memcpy(&length_color, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_color; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_color-1]=0;
      this->color = (char *)(inbuffer + offset-1);
      offset += length_color;
      uint32_t length_info;
      memcpy(&length_info, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info-1]=0;
      this->info = (char *)(inbuffer + offset-1);
      offset += length_info;
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
     return offset;
    }

    const char * getType(){ return "data_vis_msgs/Task"; };
    const char * getMD5(){ return "18773c45de1fab119cc96f82a8cb92ae"; };

  };

}
#endif