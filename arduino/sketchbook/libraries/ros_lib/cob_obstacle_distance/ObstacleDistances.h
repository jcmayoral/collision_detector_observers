#ifndef _ROS_cob_obstacle_distance_ObstacleDistances_h
#define _ROS_cob_obstacle_distance_ObstacleDistances_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_obstacle_distance/ObstacleDistance.h"

namespace cob_obstacle_distance
{

  class ObstacleDistances : public ros::Msg
  {
    public:
      uint8_t distances_length;
      cob_obstacle_distance::ObstacleDistance st_distances;
      cob_obstacle_distance::ObstacleDistance * distances;

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
        this->distances = (cob_obstacle_distance::ObstacleDistance*)realloc(this->distances, distances_lengthT * sizeof(cob_obstacle_distance::ObstacleDistance));
      offset += 3;
      distances_length = distances_lengthT;
      for( uint8_t i = 0; i < distances_length; i++){
      offset += this->st_distances.deserialize(inbuffer + offset);
        memcpy( &(this->distances[i]), &(this->st_distances), sizeof(cob_obstacle_distance::ObstacleDistance));
      }
     return offset;
    }

    const char * getType(){ return "cob_obstacle_distance/ObstacleDistances"; };
    const char * getMD5(){ return "58f6b8a2511da851588441c695d51807"; };

  };

}
#endif