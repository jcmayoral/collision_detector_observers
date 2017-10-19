#ifndef _ROS_mcr_manipulation_msgs_SphericalSamplerParameters_h
#define _ROS_mcr_manipulation_msgs_SphericalSamplerParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mcr_common_msgs/ClosedInterval.h"

namespace mcr_manipulation_msgs
{

  class SphericalSamplerParameters : public ros::Msg
  {
    public:
      mcr_common_msgs::ClosedInterval height;
      mcr_common_msgs::ClosedInterval zenith;
      mcr_common_msgs::ClosedInterval azimuth;
      mcr_common_msgs::ClosedInterval yaw;
      mcr_common_msgs::ClosedInterval radial_distance;

    SphericalSamplerParameters():
      height(),
      zenith(),
      azimuth(),
      yaw(),
      radial_distance()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->height.serialize(outbuffer + offset);
      offset += this->zenith.serialize(outbuffer + offset);
      offset += this->azimuth.serialize(outbuffer + offset);
      offset += this->yaw.serialize(outbuffer + offset);
      offset += this->radial_distance.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->height.deserialize(inbuffer + offset);
      offset += this->zenith.deserialize(inbuffer + offset);
      offset += this->azimuth.deserialize(inbuffer + offset);
      offset += this->yaw.deserialize(inbuffer + offset);
      offset += this->radial_distance.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "mcr_manipulation_msgs/SphericalSamplerParameters"; };
    const char * getMD5(){ return "e295ad05a99e6ffc20dfa96d32e2c6a3"; };

  };

}
#endif