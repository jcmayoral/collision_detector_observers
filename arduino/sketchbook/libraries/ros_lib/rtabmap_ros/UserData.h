#ifndef _ROS_rtabmap_ros_UserData_h
#define _ROS_rtabmap_ros_UserData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rtabmap_ros
{

  class UserData : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t rows;
      uint32_t cols;
      uint32_t type;
      uint8_t data_length;
      uint8_t st_data;
      uint8_t * data;

    UserData():
      header(),
      rows(0),
      cols(0),
      type(0),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->rows >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rows >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rows >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rows >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rows);
      *(outbuffer + offset + 0) = (this->cols >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cols >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cols >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cols >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cols);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->rows =  ((uint32_t) (*(inbuffer + offset)));
      this->rows |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rows |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->rows |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->rows);
      this->cols =  ((uint32_t) (*(inbuffer + offset)));
      this->cols |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cols |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->cols |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->cols);
      this->type =  ((uint32_t) (*(inbuffer + offset)));
      this->type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->type);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (uint8_t*)realloc(this->data, data_lengthT * sizeof(uint8_t));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      this->st_data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "rtabmap_ros/UserData"; };
    const char * getMD5(){ return "e2b3ca3c96ccd4baa19ca1aeef9ec767"; };

  };

}
#endif