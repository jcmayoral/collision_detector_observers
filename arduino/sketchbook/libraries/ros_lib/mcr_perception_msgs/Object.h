#ifndef _ROS_mcr_perception_msgs_Object_h
#define _ROS_mcr_perception_msgs_Object_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Vector3Stamped.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/PointCloud2.h"
#include "mcr_perception_msgs/BoundingBox.h"
#include "mcr_perception_msgs/Plane.h"

namespace mcr_perception_msgs
{

  class Object : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose;
      geometry_msgs::Vector3Stamped dimensions;
      const char* name;
      const char* category;
      int32_t database_id;
      float probability;
      sensor_msgs::Image rgb_image;
      sensor_msgs::PointCloud2 pointcloud;
      mcr_perception_msgs::BoundingBox bounding_box;
      mcr_perception_msgs::Plane related_surface;

    Object():
      pose(),
      dimensions(),
      name(""),
      category(""),
      database_id(0),
      probability(0),
      rgb_image(),
      pointcloud(),
      bounding_box(),
      related_surface()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->dimensions.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_category = strlen(this->category);
      memcpy(outbuffer + offset, &length_category, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->category, length_category);
      offset += length_category;
      union {
        int32_t real;
        uint32_t base;
      } u_database_id;
      u_database_id.real = this->database_id;
      *(outbuffer + offset + 0) = (u_database_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_database_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_database_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_database_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->database_id);
      union {
        float real;
        uint32_t base;
      } u_probability;
      u_probability.real = this->probability;
      *(outbuffer + offset + 0) = (u_probability.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_probability.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_probability.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_probability.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->probability);
      offset += this->rgb_image.serialize(outbuffer + offset);
      offset += this->pointcloud.serialize(outbuffer + offset);
      offset += this->bounding_box.serialize(outbuffer + offset);
      offset += this->related_surface.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->dimensions.deserialize(inbuffer + offset);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_category;
      memcpy(&length_category, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_category; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_category-1]=0;
      this->category = (char *)(inbuffer + offset-1);
      offset += length_category;
      union {
        int32_t real;
        uint32_t base;
      } u_database_id;
      u_database_id.base = 0;
      u_database_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_database_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_database_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_database_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->database_id = u_database_id.real;
      offset += sizeof(this->database_id);
      union {
        float real;
        uint32_t base;
      } u_probability;
      u_probability.base = 0;
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->probability = u_probability.real;
      offset += sizeof(this->probability);
      offset += this->rgb_image.deserialize(inbuffer + offset);
      offset += this->pointcloud.deserialize(inbuffer + offset);
      offset += this->bounding_box.deserialize(inbuffer + offset);
      offset += this->related_surface.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/Object"; };
    const char * getMD5(){ return "342b234c4814b3585e26c3db70949ad1"; };

  };

}
#endif