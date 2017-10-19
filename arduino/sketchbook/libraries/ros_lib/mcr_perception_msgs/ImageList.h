#ifndef _ROS_mcr_perception_msgs_ImageList_h
#define _ROS_mcr_perception_msgs_ImageList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/Image.h"

namespace mcr_perception_msgs
{

  class ImageList : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t images_length;
      sensor_msgs::Image st_images;
      sensor_msgs::Image * images;

    ImageList():
      header(),
      images_length(0), images(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = images_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < images_length; i++){
      offset += this->images[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t images_lengthT = *(inbuffer + offset++);
      if(images_lengthT > images_length)
        this->images = (sensor_msgs::Image*)realloc(this->images, images_lengthT * sizeof(sensor_msgs::Image));
      offset += 3;
      images_length = images_lengthT;
      for( uint8_t i = 0; i < images_length; i++){
      offset += this->st_images.deserialize(inbuffer + offset);
        memcpy( &(this->images[i]), &(this->st_images), sizeof(sensor_msgs::Image));
      }
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/ImageList"; };
    const char * getMD5(){ return "b3ef08c9cff052c83f5039d098add069"; };

  };

}
#endif