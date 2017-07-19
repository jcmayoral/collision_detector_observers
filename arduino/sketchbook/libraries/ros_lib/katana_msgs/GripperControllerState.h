#ifndef _ROS_katana_msgs_GripperControllerState_h
#define _ROS_katana_msgs_GripperControllerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace katana_msgs
{

  class GripperControllerState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t name_length;
      char* st_name;
      char* * name;
      uint8_t actual_length;
      float st_actual;
      float * actual;
      uint8_t desired_length;
      float st_desired;
      float * desired;
      uint8_t error_length;
      float st_error;
      float * error;

    GripperControllerState():
      header(),
      name_length(0), name(NULL),
      actual_length(0), actual(NULL),
      desired_length(0), desired(NULL),
      error_length(0), error(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = name_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < name_length; i++){
      uint32_t length_namei = strlen(this->name[i]);
      memcpy(outbuffer + offset, &length_namei, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset++) = actual_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < actual_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->actual[i]);
      }
      *(outbuffer + offset++) = desired_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < desired_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->desired[i]);
      }
      *(outbuffer + offset++) = error_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < error_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->error[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t name_lengthT = *(inbuffer + offset++);
      if(name_lengthT > name_length)
        this->name = (char**)realloc(this->name, name_lengthT * sizeof(char*));
      offset += 3;
      name_length = name_lengthT;
      for( uint8_t i = 0; i < name_length; i++){
      uint32_t length_st_name;
      memcpy(&length_st_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_name-1]=0;
      this->st_name = (char *)(inbuffer + offset-1);
      offset += length_st_name;
        memcpy( &(this->name[i]), &(this->st_name), sizeof(char*));
      }
      uint8_t actual_lengthT = *(inbuffer + offset++);
      if(actual_lengthT > actual_length)
        this->actual = (float*)realloc(this->actual, actual_lengthT * sizeof(float));
      offset += 3;
      actual_length = actual_lengthT;
      for( uint8_t i = 0; i < actual_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_actual));
        memcpy( &(this->actual[i]), &(this->st_actual), sizeof(float));
      }
      uint8_t desired_lengthT = *(inbuffer + offset++);
      if(desired_lengthT > desired_length)
        this->desired = (float*)realloc(this->desired, desired_lengthT * sizeof(float));
      offset += 3;
      desired_length = desired_lengthT;
      for( uint8_t i = 0; i < desired_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_desired));
        memcpy( &(this->desired[i]), &(this->st_desired), sizeof(float));
      }
      uint8_t error_lengthT = *(inbuffer + offset++);
      if(error_lengthT > error_length)
        this->error = (float*)realloc(this->error, error_lengthT * sizeof(float));
      offset += 3;
      error_length = error_lengthT;
      for( uint8_t i = 0; i < error_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_error));
        memcpy( &(this->error[i]), &(this->st_error), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "katana_msgs/GripperControllerState"; };
    const char * getMD5(){ return "57ba9ed166f48062eddf3c6e509f2dc0"; };

  };

}
#endif