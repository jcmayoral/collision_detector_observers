#ifndef _ROS_cob_android_msgs_orderGoal_h
#define _ROS_cob_android_msgs_orderGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_android_msgs
{

  class orderGoal : public ros::Msg
  {
    public:
      uint8_t object_ids_length;
      int16_t st_object_ids;
      int16_t * object_ids;
      uint8_t object_tags_length;
      char* st_object_tags;
      char* * object_tags;

    orderGoal():
      object_ids_length(0), object_ids(NULL),
      object_tags_length(0), object_tags(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = object_ids_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < object_ids_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_object_idsi;
      u_object_idsi.real = this->object_ids[i];
      *(outbuffer + offset + 0) = (u_object_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_object_idsi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->object_ids[i]);
      }
      *(outbuffer + offset++) = object_tags_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < object_tags_length; i++){
      uint32_t length_object_tagsi = strlen(this->object_tags[i]);
      memcpy(outbuffer + offset, &length_object_tagsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->object_tags[i], length_object_tagsi);
      offset += length_object_tagsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t object_ids_lengthT = *(inbuffer + offset++);
      if(object_ids_lengthT > object_ids_length)
        this->object_ids = (int16_t*)realloc(this->object_ids, object_ids_lengthT * sizeof(int16_t));
      offset += 3;
      object_ids_length = object_ids_lengthT;
      for( uint8_t i = 0; i < object_ids_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_object_ids;
      u_st_object_ids.base = 0;
      u_st_object_ids.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_object_ids.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_object_ids = u_st_object_ids.real;
      offset += sizeof(this->st_object_ids);
        memcpy( &(this->object_ids[i]), &(this->st_object_ids), sizeof(int16_t));
      }
      uint8_t object_tags_lengthT = *(inbuffer + offset++);
      if(object_tags_lengthT > object_tags_length)
        this->object_tags = (char**)realloc(this->object_tags, object_tags_lengthT * sizeof(char*));
      offset += 3;
      object_tags_length = object_tags_lengthT;
      for( uint8_t i = 0; i < object_tags_length; i++){
      uint32_t length_st_object_tags;
      memcpy(&length_st_object_tags, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_object_tags; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_object_tags-1]=0;
      this->st_object_tags = (char *)(inbuffer + offset-1);
      offset += length_st_object_tags;
        memcpy( &(this->object_tags[i]), &(this->st_object_tags), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "cob_android_msgs/orderGoal"; };
    const char * getMD5(){ return "1d82ae29408ac81d07bd3e524080bde5"; };

  };

}
#endif