#ifndef _ROS_mcr_perception_msgs_PlanarPolygon_h
#define _ROS_mcr_perception_msgs_PlanarPolygon_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point32.h"

namespace mcr_perception_msgs
{

  class PlanarPolygon : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float coefficients[4];
      uint8_t contour_length;
      geometry_msgs::Point32 st_contour;
      geometry_msgs::Point32 * contour;

    PlanarPolygon():
      header(),
      coefficients(),
      contour_length(0), contour(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_coefficientsi;
      u_coefficientsi.real = this->coefficients[i];
      *(outbuffer + offset + 0) = (u_coefficientsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coefficientsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coefficientsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coefficientsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coefficients[i]);
      }
      *(outbuffer + offset++) = contour_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < contour_length; i++){
      offset += this->contour[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_coefficientsi;
      u_coefficientsi.base = 0;
      u_coefficientsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_coefficientsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_coefficientsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_coefficientsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->coefficients[i] = u_coefficientsi.real;
      offset += sizeof(this->coefficients[i]);
      }
      uint8_t contour_lengthT = *(inbuffer + offset++);
      if(contour_lengthT > contour_length)
        this->contour = (geometry_msgs::Point32*)realloc(this->contour, contour_lengthT * sizeof(geometry_msgs::Point32));
      offset += 3;
      contour_length = contour_lengthT;
      for( uint8_t i = 0; i < contour_length; i++){
      offset += this->st_contour.deserialize(inbuffer + offset);
        memcpy( &(this->contour[i]), &(this->st_contour), sizeof(geometry_msgs::Point32));
      }
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/PlanarPolygon"; };
    const char * getMD5(){ return "80c22c9f863c50f724f416b059bda863"; };

  };

}
#endif