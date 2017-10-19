#ifndef _ROS_SERVICE_LearnDMPFromDemo_h
#define _ROS_SERVICE_LearnDMPFromDemo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dmp/DMPTraj.h"
#include "dmp/DMPData.h"

namespace dmp
{

static const char LEARNDMPFROMDEMO[] = "dmp/LearnDMPFromDemo";

  class LearnDMPFromDemoRequest : public ros::Msg
  {
    public:
      dmp::DMPTraj demo;
      uint8_t k_gains_length;
      float st_k_gains;
      float * k_gains;
      uint8_t d_gains_length;
      float st_d_gains;
      float * d_gains;
      int32_t num_bases;

    LearnDMPFromDemoRequest():
      demo(),
      k_gains_length(0), k_gains(NULL),
      d_gains_length(0), d_gains(NULL),
      num_bases(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->demo.serialize(outbuffer + offset);
      *(outbuffer + offset++) = k_gains_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < k_gains_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->k_gains[i]);
      }
      *(outbuffer + offset++) = d_gains_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < d_gains_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->d_gains[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_num_bases;
      u_num_bases.real = this->num_bases;
      *(outbuffer + offset + 0) = (u_num_bases.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_bases.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_bases.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_bases.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_bases);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->demo.deserialize(inbuffer + offset);
      uint8_t k_gains_lengthT = *(inbuffer + offset++);
      if(k_gains_lengthT > k_gains_length)
        this->k_gains = (float*)realloc(this->k_gains, k_gains_lengthT * sizeof(float));
      offset += 3;
      k_gains_length = k_gains_lengthT;
      for( uint8_t i = 0; i < k_gains_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_k_gains));
        memcpy( &(this->k_gains[i]), &(this->st_k_gains), sizeof(float));
      }
      uint8_t d_gains_lengthT = *(inbuffer + offset++);
      if(d_gains_lengthT > d_gains_length)
        this->d_gains = (float*)realloc(this->d_gains, d_gains_lengthT * sizeof(float));
      offset += 3;
      d_gains_length = d_gains_lengthT;
      for( uint8_t i = 0; i < d_gains_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_d_gains));
        memcpy( &(this->d_gains[i]), &(this->st_d_gains), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_num_bases;
      u_num_bases.base = 0;
      u_num_bases.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_bases.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_bases.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_bases.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_bases = u_num_bases.real;
      offset += sizeof(this->num_bases);
     return offset;
    }

    const char * getType(){ return LEARNDMPFROMDEMO; };
    const char * getMD5(){ return "d7c68a7f789c246aea188ade43175b30"; };

  };

  class LearnDMPFromDemoResponse : public ros::Msg
  {
    public:
      uint8_t dmp_list_length;
      dmp::DMPData st_dmp_list;
      dmp::DMPData * dmp_list;
      float tau;

    LearnDMPFromDemoResponse():
      dmp_list_length(0), dmp_list(NULL),
      tau(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = dmp_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < dmp_list_length; i++){
      offset += this->dmp_list[i].serialize(outbuffer + offset);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->tau);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t dmp_list_lengthT = *(inbuffer + offset++);
      if(dmp_list_lengthT > dmp_list_length)
        this->dmp_list = (dmp::DMPData*)realloc(this->dmp_list, dmp_list_lengthT * sizeof(dmp::DMPData));
      offset += 3;
      dmp_list_length = dmp_list_lengthT;
      for( uint8_t i = 0; i < dmp_list_length; i++){
      offset += this->st_dmp_list.deserialize(inbuffer + offset);
        memcpy( &(this->dmp_list[i]), &(this->st_dmp_list), sizeof(dmp::DMPData));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tau));
     return offset;
    }

    const char * getType(){ return LEARNDMPFROMDEMO; };
    const char * getMD5(){ return "d2dccae00aae58574694dfa33e62fac1"; };

  };

  class LearnDMPFromDemo {
    public:
    typedef LearnDMPFromDemoRequest Request;
    typedef LearnDMPFromDemoResponse Response;
  };

}
#endif
