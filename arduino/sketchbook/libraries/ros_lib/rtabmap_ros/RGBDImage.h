#ifndef _ROS_rtabmap_ros_RGBDImage_h
#define _ROS_rtabmap_ros_RGBDImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/CameraInfo.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CompressedImage.h"

namespace rtabmap_ros
{

  class RGBDImage : public ros::Msg
  {
    public:
      std_msgs::Header header;
      sensor_msgs::CameraInfo cameraInfo;
      sensor_msgs::Image rgb;
      sensor_msgs::Image depth;
      sensor_msgs::CompressedImage rgbCompressed;
      sensor_msgs::CompressedImage depthCompressed;

    RGBDImage():
      header(),
      cameraInfo(),
      rgb(),
      depth(),
      rgbCompressed(),
      depthCompressed()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->cameraInfo.serialize(outbuffer + offset);
      offset += this->rgb.serialize(outbuffer + offset);
      offset += this->depth.serialize(outbuffer + offset);
      offset += this->rgbCompressed.serialize(outbuffer + offset);
      offset += this->depthCompressed.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->cameraInfo.deserialize(inbuffer + offset);
      offset += this->rgb.deserialize(inbuffer + offset);
      offset += this->depth.deserialize(inbuffer + offset);
      offset += this->rgbCompressed.deserialize(inbuffer + offset);
      offset += this->depthCompressed.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "rtabmap_ros/RGBDImage"; };
    const char * getMD5(){ return "e2918ceee8cb5b4c4b0007166508b871"; };

  };

}
#endif