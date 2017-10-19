#ifndef _ROS_mcr_perception_msgs_Blob_h
#define _ROS_mcr_perception_msgs_Blob_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose2D.h"

namespace mcr_perception_msgs
{

  class Blob : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Pose2D blob_pose;
      float blob_area;

    Blob():
      header(),
      blob_pose(),
      blob_area(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->blob_pose.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->blob_area);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->blob_pose.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->blob_area));
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/Blob"; };
    const char * getMD5(){ return "39fa1e9cf20a6c97d5c82326d42110d9"; };

  };

}
#endif