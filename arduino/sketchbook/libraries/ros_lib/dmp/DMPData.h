#ifndef _ROS_dmp_DMPData_h
#define _ROS_dmp_DMPData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dmp
{

  class DMPData : public ros::Msg
  {
    public:
      float k_gain;
      float d_gain;
      uint8_t weights_length;
      float st_weights;
      float * weights;
      uint8_t f_domain_length;
      float st_f_domain;
      float * f_domain;
      uint8_t f_targets_length;
      float st_f_targets;
      float * f_targets;

    DMPData():
      k_gain(0),
      d_gain(0),
      weights_length(0), weights(NULL),
      f_domain_length(0), f_domain(NULL),
      f_targets_length(0), f_targets(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->k_gain);
      offset += serializeAvrFloat64(outbuffer + offset, this->d_gain);
      *(outbuffer + offset++) = weights_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < weights_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->weights[i]);
      }
      *(outbuffer + offset++) = f_domain_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < f_domain_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->f_domain[i]);
      }
      *(outbuffer + offset++) = f_targets_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < f_targets_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->f_targets[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->k_gain));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d_gain));
      uint8_t weights_lengthT = *(inbuffer + offset++);
      if(weights_lengthT > weights_length)
        this->weights = (float*)realloc(this->weights, weights_lengthT * sizeof(float));
      offset += 3;
      weights_length = weights_lengthT;
      for( uint8_t i = 0; i < weights_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_weights));
        memcpy( &(this->weights[i]), &(this->st_weights), sizeof(float));
      }
      uint8_t f_domain_lengthT = *(inbuffer + offset++);
      if(f_domain_lengthT > f_domain_length)
        this->f_domain = (float*)realloc(this->f_domain, f_domain_lengthT * sizeof(float));
      offset += 3;
      f_domain_length = f_domain_lengthT;
      for( uint8_t i = 0; i < f_domain_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_f_domain));
        memcpy( &(this->f_domain[i]), &(this->st_f_domain), sizeof(float));
      }
      uint8_t f_targets_lengthT = *(inbuffer + offset++);
      if(f_targets_lengthT > f_targets_length)
        this->f_targets = (float*)realloc(this->f_targets, f_targets_lengthT * sizeof(float));
      offset += 3;
      f_targets_length = f_targets_lengthT;
      for( uint8_t i = 0; i < f_targets_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_f_targets));
        memcpy( &(this->f_targets[i]), &(this->st_f_targets), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "dmp/DMPData"; };
    const char * getMD5(){ return "dd2a2dd30705ac6b894c0c83b8081221"; };

  };

}
#endif