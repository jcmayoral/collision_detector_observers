#ifndef _ROS_data_vis_msgs_DataVis_h
#define _ROS_data_vis_msgs_DataVis_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "data_vis_msgs/ValueList.h"

namespace data_vis_msgs
{

  class DataVis : public ros::Msg
  {
    public:
      const char* id;
      int32_t type;
      const char* title;
      const char* xlabel;
      const char* ylabel;
      int32_t width;
      int32_t height;
      const char* fontsize;
      uint8_t values_length;
      data_vis_msgs::ValueList st_values;
      data_vis_msgs::ValueList * values;
      enum { TYPE_PIECHART = 0 };
      enum { TYPE_BARCHART = 1 };
      enum { TYPE_TREECHART = 2 };
      enum { TYPE_TIMELINE = 3 };
      enum { TYPE_LINECHART = 4 };

    DataVis():
      id(""),
      type(0),
      title(""),
      xlabel(""),
      ylabel(""),
      width(0),
      height(0),
      fontsize(""),
      values_length(0), values(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_title = strlen(this->title);
      memcpy(outbuffer + offset, &length_title, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->title, length_title);
      offset += length_title;
      uint32_t length_xlabel = strlen(this->xlabel);
      memcpy(outbuffer + offset, &length_xlabel, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->xlabel, length_xlabel);
      offset += length_xlabel;
      uint32_t length_ylabel = strlen(this->ylabel);
      memcpy(outbuffer + offset, &length_ylabel, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ylabel, length_ylabel);
      offset += length_ylabel;
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      uint32_t length_fontsize = strlen(this->fontsize);
      memcpy(outbuffer + offset, &length_fontsize, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fontsize, length_fontsize);
      offset += length_fontsize;
      *(outbuffer + offset++) = values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < values_length; i++){
      offset += this->values[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      uint32_t length_title;
      memcpy(&length_title, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_title; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_title-1]=0;
      this->title = (char *)(inbuffer + offset-1);
      offset += length_title;
      uint32_t length_xlabel;
      memcpy(&length_xlabel, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_xlabel; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_xlabel-1]=0;
      this->xlabel = (char *)(inbuffer + offset-1);
      offset += length_xlabel;
      uint32_t length_ylabel;
      memcpy(&length_ylabel, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ylabel; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ylabel-1]=0;
      this->ylabel = (char *)(inbuffer + offset-1);
      offset += length_ylabel;
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->width = u_width.real;
      offset += sizeof(this->width);
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height = u_height.real;
      offset += sizeof(this->height);
      uint32_t length_fontsize;
      memcpy(&length_fontsize, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_fontsize; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_fontsize-1]=0;
      this->fontsize = (char *)(inbuffer + offset-1);
      offset += length_fontsize;
      uint8_t values_lengthT = *(inbuffer + offset++);
      if(values_lengthT > values_length)
        this->values = (data_vis_msgs::ValueList*)realloc(this->values, values_lengthT * sizeof(data_vis_msgs::ValueList));
      offset += 3;
      values_length = values_lengthT;
      for( uint8_t i = 0; i < values_length; i++){
      offset += this->st_values.deserialize(inbuffer + offset);
        memcpy( &(this->values[i]), &(this->st_values), sizeof(data_vis_msgs::ValueList));
      }
     return offset;
    }

    const char * getType(){ return "data_vis_msgs/DataVis"; };
    const char * getMD5(){ return "54fc13c6e72b87a9c5ab7e772c90e8f2"; };

  };

}
#endif