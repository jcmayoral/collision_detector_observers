#ifndef _ROS_cob_obstacle_distance_ObstacleDistance_h
#define _ROS_cob_obstacle_distance_ObstacleDistance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace cob_obstacle_distance
{

  class ObstacleDistance : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* link_of_interest;
      const char* obstacle_id;
      float distance;
      geometry_msgs::Vector3 frame_vector;
      geometry_msgs::Vector3 nearest_point_frame_vector;
      geometry_msgs::Vector3 nearest_point_obstacle_vector;

    ObstacleDistance():
      header(),
      link_of_interest(""),
      obstacle_id(""),
      distance(0),
      frame_vector(),
      nearest_point_frame_vector(),
      nearest_point_obstacle_vector()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_link_of_interest = strlen(this->link_of_interest);
      memcpy(outbuffer + offset, &length_link_of_interest, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_of_interest, length_link_of_interest);
      offset += length_link_of_interest;
      uint32_t length_obstacle_id = strlen(this->obstacle_id);
      memcpy(outbuffer + offset, &length_obstacle_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->obstacle_id, length_obstacle_id);
      offset += length_obstacle_id;
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      offset += this->frame_vector.serialize(outbuffer + offset);
      offset += this->nearest_point_frame_vector.serialize(outbuffer + offset);
      offset += this->nearest_point_obstacle_vector.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_link_of_interest;
      memcpy(&length_link_of_interest, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_of_interest; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_of_interest-1]=0;
      this->link_of_interest = (char *)(inbuffer + offset-1);
      offset += length_link_of_interest;
      uint32_t length_obstacle_id;
      memcpy(&length_obstacle_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_obstacle_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_obstacle_id-1]=0;
      this->obstacle_id = (char *)(inbuffer + offset-1);
      offset += length_obstacle_id;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
      offset += this->frame_vector.deserialize(inbuffer + offset);
      offset += this->nearest_point_frame_vector.deserialize(inbuffer + offset);
      offset += this->nearest_point_obstacle_vector.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_obstacle_distance/ObstacleDistance"; };
    const char * getMD5(){ return "fbbcad171002ad96c1fc44941d7a1bf1"; };

  };

}
#endif