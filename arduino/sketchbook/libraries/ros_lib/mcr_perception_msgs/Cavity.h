#ifndef _ROS_mcr_perception_msgs_Cavity_h
#define _ROS_mcr_perception_msgs_Cavity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Vector3Stamped.h"
#include "mcr_perception_msgs/MatchingErrorStamped.h"
#include "sensor_msgs/PointCloud2.h"

namespace mcr_perception_msgs
{

  class Cavity : public ros::Msg
  {
    public:
      const char* name;
      const char* object_name;
      uint8_t placement_orientation;
      geometry_msgs::PoseStamped pose;
      geometry_msgs::Vector3Stamped dimensions;
      mcr_perception_msgs::MatchingErrorStamped template_matching_error;
      sensor_msgs::PointCloud2 pointcloud;
      enum { PLACEMENT_HORIZONTAL = 0 };
      enum { PLACEMENT_VERTICAL = 1 };
      enum { PLACEMENT_HORIZONTAL_OR_VERTICAL = 2 };

    Cavity():
      name(""),
      object_name(""),
      placement_orientation(0),
      pose(),
      dimensions(),
      template_matching_error(),
      pointcloud()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_object_name = strlen(this->object_name);
      memcpy(outbuffer + offset, &length_object_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->object_name, length_object_name);
      offset += length_object_name;
      *(outbuffer + offset + 0) = (this->placement_orientation >> (8 * 0)) & 0xFF;
      offset += sizeof(this->placement_orientation);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->dimensions.serialize(outbuffer + offset);
      offset += this->template_matching_error.serialize(outbuffer + offset);
      offset += this->pointcloud.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_object_name;
      memcpy(&length_object_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_name-1]=0;
      this->object_name = (char *)(inbuffer + offset-1);
      offset += length_object_name;
      this->placement_orientation =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->placement_orientation);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->dimensions.deserialize(inbuffer + offset);
      offset += this->template_matching_error.deserialize(inbuffer + offset);
      offset += this->pointcloud.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/Cavity"; };
    const char * getMD5(){ return "08a52fd7bbaef3bdce0cf124fb8ec409"; };

  };

}
#endif