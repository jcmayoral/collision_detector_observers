#ifndef _ROS_data_vis_msgs_ValueList_h
#define _ROS_data_vis_msgs_ValueList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace data_vis_msgs
{

  class ValueList : public ros::Msg
  {
    public:
      const char* label;
      uint8_t value1_length;
      char* st_value1;
      char* * value1;
      uint8_t value2_length;
      char* st_value2;
      char* * value2;

    ValueList():
      label(""),
      value1_length(0), value1(NULL),
      value2_length(0), value2(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_label = strlen(this->label);
      memcpy(outbuffer + offset, &length_label, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->label, length_label);
      offset += length_label;
      *(outbuffer + offset++) = value1_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < value1_length; i++){
      uint32_t length_value1i = strlen(this->value1[i]);
      memcpy(outbuffer + offset, &length_value1i, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->value1[i], length_value1i);
      offset += length_value1i;
      }
      *(outbuffer + offset++) = value2_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < value2_length; i++){
      uint32_t length_value2i = strlen(this->value2[i]);
      memcpy(outbuffer + offset, &length_value2i, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->value2[i], length_value2i);
      offset += length_value2i;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_label;
      memcpy(&length_label, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_label-1]=0;
      this->label = (char *)(inbuffer + offset-1);
      offset += length_label;
      uint8_t value1_lengthT = *(inbuffer + offset++);
      if(value1_lengthT > value1_length)
        this->value1 = (char**)realloc(this->value1, value1_lengthT * sizeof(char*));
      offset += 3;
      value1_length = value1_lengthT;
      for( uint8_t i = 0; i < value1_length; i++){
      uint32_t length_st_value1;
      memcpy(&length_st_value1, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_value1; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_value1-1]=0;
      this->st_value1 = (char *)(inbuffer + offset-1);
      offset += length_st_value1;
        memcpy( &(this->value1[i]), &(this->st_value1), sizeof(char*));
      }
      uint8_t value2_lengthT = *(inbuffer + offset++);
      if(value2_lengthT > value2_length)
        this->value2 = (char**)realloc(this->value2, value2_lengthT * sizeof(char*));
      offset += 3;
      value2_length = value2_lengthT;
      for( uint8_t i = 0; i < value2_length; i++){
      uint32_t length_st_value2;
      memcpy(&length_st_value2, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_value2; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_value2-1]=0;
      this->st_value2 = (char *)(inbuffer + offset-1);
      offset += length_st_value2;
        memcpy( &(this->value2[i]), &(this->st_value2), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "data_vis_msgs/ValueList"; };
    const char * getMD5(){ return "93606cae4b5c86869b7aa221cf2b0b01"; };

  };

}
#endif