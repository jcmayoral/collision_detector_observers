#ifndef _ROS_mcr_perception_msgs_BoundingBox_h
#define _ROS_mcr_perception_msgs_BoundingBox_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"

namespace mcr_perception_msgs
{

  class BoundingBox : public ros::Msg
  {
    public:
      geometry_msgs::Point center;
      geometry_msgs::Vector3 dimensions;
      uint8_t vertices_length;
      geometry_msgs::Point st_vertices;
      geometry_msgs::Point * vertices;

    BoundingBox():
      center(),
      dimensions(),
      vertices_length(0), vertices(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->center.serialize(outbuffer + offset);
      offset += this->dimensions.serialize(outbuffer + offset);
      *(outbuffer + offset++) = vertices_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < vertices_length; i++){
      offset += this->vertices[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->center.deserialize(inbuffer + offset);
      offset += this->dimensions.deserialize(inbuffer + offset);
      uint8_t vertices_lengthT = *(inbuffer + offset++);
      if(vertices_lengthT > vertices_length)
        this->vertices = (geometry_msgs::Point*)realloc(this->vertices, vertices_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      vertices_length = vertices_lengthT;
      for( uint8_t i = 0; i < vertices_length; i++){
      offset += this->st_vertices.deserialize(inbuffer + offset);
        memcpy( &(this->vertices[i]), &(this->st_vertices), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/BoundingBox"; };
    const char * getMD5(){ return "b9b98e3939e5a8f5b51b326bdc17eed8"; };

  };

}
#endif