#ifndef _ROS_dmp_DMPTraj_h
#define _ROS_dmp_DMPTraj_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dmp/DMPPoint.h"

namespace dmp
{

  class DMPTraj : public ros::Msg
  {
    public:
      uint8_t points_length;
      dmp::DMPPoint st_points;
      dmp::DMPPoint * points;
      uint8_t times_length;
      float st_times;
      float * times;

    DMPTraj():
      points_length(0), points(NULL),
      times_length(0), times(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = points_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = times_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < times_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->times[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t points_lengthT = *(inbuffer + offset++);
      if(points_lengthT > points_length)
        this->points = (dmp::DMPPoint*)realloc(this->points, points_lengthT * sizeof(dmp::DMPPoint));
      offset += 3;
      points_length = points_lengthT;
      for( uint8_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(dmp::DMPPoint));
      }
      uint8_t times_lengthT = *(inbuffer + offset++);
      if(times_lengthT > times_length)
        this->times = (float*)realloc(this->times, times_lengthT * sizeof(float));
      offset += 3;
      times_length = times_lengthT;
      for( uint8_t i = 0; i < times_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_times));
        memcpy( &(this->times[i]), &(this->st_times), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "dmp/DMPTraj"; };
    const char * getMD5(){ return "1d088d86ab60cf6a2671bc3c0e99932b"; };

  };

}
#endif