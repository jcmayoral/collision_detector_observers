#ifndef _ROS_dmp_DMPPoint_h
#define _ROS_dmp_DMPPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dmp
{

  class DMPPoint : public ros::Msg
  {
    public:
      uint8_t positions_length;
      float st_positions;
      float * positions;
      uint8_t velocities_length;
      float st_velocities;
      float * velocities;

    DMPPoint():
      positions_length(0), positions(NULL),
      velocities_length(0), velocities(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = positions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < positions_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->positions[i]);
      }
      *(outbuffer + offset++) = velocities_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < velocities_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->velocities[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t positions_lengthT = *(inbuffer + offset++);
      if(positions_lengthT > positions_length)
        this->positions = (float*)realloc(this->positions, positions_lengthT * sizeof(float));
      offset += 3;
      positions_length = positions_lengthT;
      for( uint8_t i = 0; i < positions_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_positions));
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(float));
      }
      uint8_t velocities_lengthT = *(inbuffer + offset++);
      if(velocities_lengthT > velocities_length)
        this->velocities = (float*)realloc(this->velocities, velocities_lengthT * sizeof(float));
      offset += 3;
      velocities_length = velocities_lengthT;
      for( uint8_t i = 0; i < velocities_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_velocities));
        memcpy( &(this->velocities[i]), &(this->st_velocities), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "dmp/DMPPoint"; };
    const char * getMD5(){ return "f32a98450510f8ae05fae28f45d6e99a"; };

  };

}
#endif