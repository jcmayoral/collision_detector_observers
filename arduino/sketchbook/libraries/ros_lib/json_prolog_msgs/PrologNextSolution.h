#ifndef _ROS_SERVICE_PrologNextSolution_h
#define _ROS_SERVICE_PrologNextSolution_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace json_prolog_msgs
{

static const char PROLOGNEXTSOLUTION[] = "json_prolog_msgs/PrologNextSolution";

  class PrologNextSolutionRequest : public ros::Msg
  {
    public:
      const char* id;

    PrologNextSolutionRequest():
      id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
     return offset;
    }

    const char * getType(){ return PROLOGNEXTSOLUTION; };
    const char * getMD5(){ return "bbfcda76036ebbe3d36caf7af80b260c"; };

  };

  class PrologNextSolutionResponse : public ros::Msg
  {
    public:
      int8_t status;
      const char* solution;
      enum { NO_SOLUTION =  0 };
      enum { WRONG_ID =  1 };
      enum { QUERY_FAILED =  2 };
      enum { OK =  3 };

    PrologNextSolutionResponse():
      status(0),
      solution("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      uint32_t length_solution = strlen(this->solution);
      memcpy(outbuffer + offset, &length_solution, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->solution, length_solution);
      offset += length_solution;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
      uint32_t length_solution;
      memcpy(&length_solution, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_solution; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_solution-1]=0;
      this->solution = (char *)(inbuffer + offset-1);
      offset += length_solution;
     return offset;
    }

    const char * getType(){ return PROLOGNEXTSOLUTION; };
    const char * getMD5(){ return "13aa54b7380a45414b5c48869ecbe7c8"; };

  };

  class PrologNextSolution {
    public:
    typedef PrologNextSolutionRequest Request;
    typedef PrologNextSolutionResponse Response;
  };

}
#endif
