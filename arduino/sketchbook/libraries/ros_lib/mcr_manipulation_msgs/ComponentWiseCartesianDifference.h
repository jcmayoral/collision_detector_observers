#ifndef _ROS_mcr_manipulation_msgs_ComponentWiseCartesianDifference_h
#define _ROS_mcr_manipulation_msgs_ComponentWiseCartesianDifference_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace mcr_manipulation_msgs
{

  class ComponentWiseCartesianDifference : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Vector3 linear;
      geometry_msgs::Vector3 angular;

    ComponentWiseCartesianDifference():
      header(),
      linear(),
      angular()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->linear.serialize(outbuffer + offset);
      offset += this->angular.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->linear.deserialize(inbuffer + offset);
      offset += this->angular.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "mcr_manipulation_msgs/ComponentWiseCartesianDifference"; };
    const char * getMD5(){ return "09119d3b0067bd05b1a6696c168cebb3"; };

  };

}
#endif