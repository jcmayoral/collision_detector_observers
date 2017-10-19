#ifndef _ROS_mcr_perception_msgs_Face_h
#define _ROS_mcr_perception_msgs_Face_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/Image.h"

namespace mcr_perception_msgs
{

  class Face : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t ID;
      const char* name;
      float leftEyeCenterX;
      float leftEyeCenterY;
      float rightEyeCenterX;
      float rightEyeCenterY;
      sensor_msgs::Image image;

    Face():
      header(),
      ID(0),
      name(""),
      leftEyeCenterX(0),
      leftEyeCenterY(0),
      rightEyeCenterX(0),
      rightEyeCenterY(0),
      image()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->ID >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ID >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ID >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ID >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ID);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        float real;
        uint32_t base;
      } u_leftEyeCenterX;
      u_leftEyeCenterX.real = this->leftEyeCenterX;
      *(outbuffer + offset + 0) = (u_leftEyeCenterX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftEyeCenterX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftEyeCenterX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftEyeCenterX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->leftEyeCenterX);
      union {
        float real;
        uint32_t base;
      } u_leftEyeCenterY;
      u_leftEyeCenterY.real = this->leftEyeCenterY;
      *(outbuffer + offset + 0) = (u_leftEyeCenterY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftEyeCenterY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftEyeCenterY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftEyeCenterY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->leftEyeCenterY);
      union {
        float real;
        uint32_t base;
      } u_rightEyeCenterX;
      u_rightEyeCenterX.real = this->rightEyeCenterX;
      *(outbuffer + offset + 0) = (u_rightEyeCenterX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightEyeCenterX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightEyeCenterX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightEyeCenterX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rightEyeCenterX);
      union {
        float real;
        uint32_t base;
      } u_rightEyeCenterY;
      u_rightEyeCenterY.real = this->rightEyeCenterY;
      *(outbuffer + offset + 0) = (u_rightEyeCenterY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightEyeCenterY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightEyeCenterY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightEyeCenterY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rightEyeCenterY);
      offset += this->image.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->ID =  ((uint32_t) (*(inbuffer + offset)));
      this->ID |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ID |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->ID |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->ID);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        float real;
        uint32_t base;
      } u_leftEyeCenterX;
      u_leftEyeCenterX.base = 0;
      u_leftEyeCenterX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftEyeCenterX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftEyeCenterX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftEyeCenterX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->leftEyeCenterX = u_leftEyeCenterX.real;
      offset += sizeof(this->leftEyeCenterX);
      union {
        float real;
        uint32_t base;
      } u_leftEyeCenterY;
      u_leftEyeCenterY.base = 0;
      u_leftEyeCenterY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftEyeCenterY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftEyeCenterY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftEyeCenterY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->leftEyeCenterY = u_leftEyeCenterY.real;
      offset += sizeof(this->leftEyeCenterY);
      union {
        float real;
        uint32_t base;
      } u_rightEyeCenterX;
      u_rightEyeCenterX.base = 0;
      u_rightEyeCenterX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightEyeCenterX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightEyeCenterX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightEyeCenterX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rightEyeCenterX = u_rightEyeCenterX.real;
      offset += sizeof(this->rightEyeCenterX);
      union {
        float real;
        uint32_t base;
      } u_rightEyeCenterY;
      u_rightEyeCenterY.base = 0;
      u_rightEyeCenterY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightEyeCenterY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightEyeCenterY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightEyeCenterY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rightEyeCenterY = u_rightEyeCenterY.real;
      offset += sizeof(this->rightEyeCenterY);
      offset += this->image.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/Face"; };
    const char * getMD5(){ return "b610e168598bb28f43d80530aae0b9fb"; };

  };

}
#endif