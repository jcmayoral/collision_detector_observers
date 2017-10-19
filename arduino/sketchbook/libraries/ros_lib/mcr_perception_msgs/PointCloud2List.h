#ifndef _ROS_mcr_perception_msgs_PointCloud2List_h
#define _ROS_mcr_perception_msgs_PointCloud2List_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/PointCloud2.h"

namespace mcr_perception_msgs
{

  class PointCloud2List : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t pointclouds_length;
      sensor_msgs::PointCloud2 st_pointclouds;
      sensor_msgs::PointCloud2 * pointclouds;

    PointCloud2List():
      header(),
      pointclouds_length(0), pointclouds(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = pointclouds_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pointclouds_length; i++){
      offset += this->pointclouds[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t pointclouds_lengthT = *(inbuffer + offset++);
      if(pointclouds_lengthT > pointclouds_length)
        this->pointclouds = (sensor_msgs::PointCloud2*)realloc(this->pointclouds, pointclouds_lengthT * sizeof(sensor_msgs::PointCloud2));
      offset += 3;
      pointclouds_length = pointclouds_lengthT;
      for( uint8_t i = 0; i < pointclouds_length; i++){
      offset += this->st_pointclouds.deserialize(inbuffer + offset);
        memcpy( &(this->pointclouds[i]), &(this->st_pointclouds), sizeof(sensor_msgs::PointCloud2));
      }
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/PointCloud2List"; };
    const char * getMD5(){ return "4424777eb5869dbe56aa4b9575367e2d"; };

  };

}
#endif