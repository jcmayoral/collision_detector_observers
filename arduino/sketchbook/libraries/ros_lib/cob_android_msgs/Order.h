#ifndef _ROS_SERVICE_Order_h
#define _ROS_SERVICE_Order_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_android_msgs
{

static const char ORDER[] = "cob_android_msgs/Order";

  class OrderRequest : public ros::Msg
  {
    public:
      uint8_t object_tags_length;
      char* st_object_tags;
      char* * object_tags;
      uint8_t object_ids_length;
      int32_t st_object_ids;
      int32_t * object_ids;

    OrderRequest():
      object_tags_length(0), object_tags(NULL),
      object_ids_length(0), object_ids(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      *(outbuffer + offset++) = object_ids_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < object_ids_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_object_idsi;
      u_object_idsi.real = this->object_ids[i];
      *(outbuffer + offset + 0) = (u_object_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_object_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_object_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_object_idsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->object_ids[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      uint8_t object_ids_lengthT = *(inbuffer + offset++);
      if(object_ids_lengthT > object_ids_length)
        this->object_ids = (int32_t*)realloc(this->object_ids, object_ids_lengthT * sizeof(int32_t));
      offset += 3;
      object_ids_length = object_ids_lengthT;
      for( uint8_t i = 0; i < object_ids_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_object_ids;
      u_st_object_ids.base = 0;
      u_st_object_ids.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_object_ids.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_object_ids.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_object_ids.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_object_ids = u_st_object_ids.real;
      offset += sizeof(this->st_object_ids);
        memcpy( &(this->object_ids[i]), &(this->st_object_ids), sizeof(int32_t));
      }
     return offset;
    }

    const char * getType(){ return ORDER; };
    const char * getMD5(){ return "b2a1b1dbba2b2ae5d6429135e93c5c9f"; };

  };

  class OrderResponse : public ros::Msg
  {
    public:
      bool success;
      const char* error_message;

    OrderResponse():
      success(0),
      error_message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_error_message = strlen(this->error_message);
      memcpy(outbuffer + offset, &length_error_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_message, length_error_message);
      offset += length_error_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_error_message;
      memcpy(&length_error_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_message-1]=0;
      this->error_message = (char *)(inbuffer + offset-1);
      offset += length_error_message;
     return offset;
    }

    const char * getType(){ return ORDER; };
    const char * getMD5(){ return "6fe914479ce03184a758c3f6990c928f"; };

  };

  class Order {
    public:
    typedef OrderRequest Request;
    typedef OrderResponse Response;
  };

}
#endif
