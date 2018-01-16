#ifndef _ROS_cob_light_ColorRGBAArray_h
#define _ROS_cob_light_ColorRGBAArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace cob_light
{

  class ColorRGBAArray : public ros::Msg
  {
    public:
      uint8_t colors_length;
      std_msgs::ColorRGBA st_colors;
      std_msgs::ColorRGBA * colors;

    ColorRGBAArray():
      colors_length(0), colors(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = colors_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < colors_length; i++){
      offset += this->colors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t colors_lengthT = *(inbuffer + offset++);
      if(colors_lengthT > colors_length)
        this->colors = (std_msgs::ColorRGBA*)realloc(this->colors, colors_lengthT * sizeof(std_msgs::ColorRGBA));
      offset += 3;
      colors_length = colors_lengthT;
      for( uint8_t i = 0; i < colors_length; i++){
      offset += this->st_colors.deserialize(inbuffer + offset);
        memcpy( &(this->colors[i]), &(this->st_colors), sizeof(std_msgs::ColorRGBA));
      }
     return offset;
    }

    const char * getType(){ return "cob_light/ColorRGBAArray"; };
    const char * getMD5(){ return "8a8aae411a07648ba08dd6bedf519336"; };

  };

}
#endif