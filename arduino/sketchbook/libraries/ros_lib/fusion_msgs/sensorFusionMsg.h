#ifndef _ROS_fusion_msgs_sensorFusionMsg_h
#define _ROS_fusion_msgs_sensorFusionMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"

namespace fusion_msgs
{

  class sensorFusionMsg : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std_msgs::String sensor_id;
      int32_t window_size;
      int8_t msg;
      uint8_t data_length;
      float st_data;
      float * data;
      enum { OK = 0 };
      enum { WARN = 1 };
      enum { ERROR = 2 };

    sensorFusionMsg():
      header(),
      sensor_id(),
      window_size(0),
      msg(0),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->sensor_id.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_window_size;
      u_window_size.real = this->window_size;
      *(outbuffer + offset + 0) = (u_window_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_window_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_window_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_window_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->window_size);
      union {
        int8_t real;
        uint8_t base;
      } u_msg;
      u_msg.real = this->msg;
      *(outbuffer + offset + 0) = (u_msg.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->msg);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      union {
        float real;
        uint32_t base;
      } u_datai;
      u_datai.real = this->data[i];
      *(outbuffer + offset + 0) = (u_datai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_datai.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_datai.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_datai.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->sensor_id.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_window_size;
      u_window_size.base = 0;
      u_window_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_window_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_window_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_window_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->window_size = u_window_size.real;
      offset += sizeof(this->window_size);
      union {
        int8_t real;
        uint8_t base;
      } u_msg;
      u_msg.base = 0;
      u_msg.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->msg = u_msg.real;
      offset += sizeof(this->msg);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (float*)realloc(this->data, data_lengthT * sizeof(float));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_data;
      u_st_data.base = 0;
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_data = u_st_data.real;
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "fusion_msgs/sensorFusionMsg"; };
    const char * getMD5(){ return "fb73691af2681e9ba3fec7d5d9793c38"; };

  };

}
#endif