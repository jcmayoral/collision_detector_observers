#ifndef _ROS_mcr_manipulation_msgs_JointDistance_h
#define _ROS_mcr_manipulation_msgs_JointDistance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mcr_manipulation_msgs
{

  class JointDistance : public ros::Msg
  {
    public:
      uint8_t name_length;
      char* st_name;
      char* * name;
      uint8_t distance_length;
      float st_distance;
      float * distance;

    JointDistance():
      name_length(0), name(NULL),
      distance_length(0), distance(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      *(outbuffer + offset++) = distance_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < distance_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->distance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      uint8_t distance_lengthT = *(inbuffer + offset++);
      if(distance_lengthT > distance_length)
        this->distance = (float*)realloc(this->distance, distance_lengthT * sizeof(float));
      offset += 3;
      distance_length = distance_lengthT;
      for( uint8_t i = 0; i < distance_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_distance));
        memcpy( &(this->distance[i]), &(this->st_distance), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "mcr_manipulation_msgs/JointDistance"; };
    const char * getMD5(){ return "dfd6792a120795e0daea7b2ae6602a5f"; };

  };

}
#endif