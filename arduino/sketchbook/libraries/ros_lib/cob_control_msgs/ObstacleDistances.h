#ifndef _ROS_cob_control_msgs_ObstacleDistances_h
#define _ROS_cob_control_msgs_ObstacleDistances_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_control_msgs/ObstacleDistance.h"

namespace cob_control_msgs
{

  class ObstacleDistances : public ros::Msg
  {
    public:
      uint8_t distances_length;
      cob_control_msgs::ObstacleDistance st_distances;
      cob_control_msgs::ObstacleDistance * distances;

    ObstacleDistances():
      distances_length(0), distances(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = distances_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < distances_length; i++){
      offset += this->distances[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t distances_lengthT = *(inbuffer + offset++);
      if(distances_lengthT > distances_length)
        this->distances = (cob_control_msgs::ObstacleDistance*)realloc(this->distances, distances_lengthT * sizeof(cob_control_msgs::ObstacleDistance));
      offset += 3;
      distances_length = distances_lengthT;
      for( uint8_t i = 0; i < distances_length; i++){
      offset += this->st_distances.deserialize(inbuffer + offset);
        memcpy( &(this->distances[i]), &(this->st_distances), sizeof(cob_control_msgs::ObstacleDistance));
      }
     return offset;
    }

    const char * getType(){ return "cob_control_msgs/ObstacleDistances"; };
    const char * getMD5(){ return "58f6b8a2511da851588441c695d51807"; };

  };

}
#endif