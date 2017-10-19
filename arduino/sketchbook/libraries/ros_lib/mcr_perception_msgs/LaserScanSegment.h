#ifndef _ROS_mcr_perception_msgs_LaserScanSegment_h
#define _ROS_mcr_perception_msgs_LaserScanSegment_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace mcr_perception_msgs
{

  class LaserScanSegment : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Point center;
      uint8_t data_points_length;
      geometry_msgs::Point st_data_points;
      geometry_msgs::Point * data_points;

    LaserScanSegment():
      header(),
      center(),
      data_points_length(0), data_points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->center.serialize(outbuffer + offset);
      *(outbuffer + offset++) = data_points_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_points_length; i++){
      offset += this->data_points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->center.deserialize(inbuffer + offset);
      uint8_t data_points_lengthT = *(inbuffer + offset++);
      if(data_points_lengthT > data_points_length)
        this->data_points = (geometry_msgs::Point*)realloc(this->data_points, data_points_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      data_points_length = data_points_lengthT;
      for( uint8_t i = 0; i < data_points_length; i++){
      offset += this->st_data_points.deserialize(inbuffer + offset);
        memcpy( &(this->data_points[i]), &(this->st_data_points), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/LaserScanSegment"; };
    const char * getMD5(){ return "8d7619852566ce317bf5ab32ab3f3fc8"; };

  };

}
#endif