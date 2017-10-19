#ifndef _ROS_SERVICE_Grasp_h
#define _ROS_SERVICE_Grasp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"

namespace mdr_manipulation_msgs
{

static const char GRASP[] = "mdr_manipulation_msgs/Grasp";

  class GraspRequest : public ros::Msg
  {
    public:
      geometry_msgs::PointStamped position;

    GraspRequest():
      position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GRASP; };
    const char * getMD5(){ return "1ed0e92ededc007c2e5729582f354ee1"; };

  };

  class GraspResponse : public ros::Msg
  {
    public:
      int64_t result;

    GraspResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_result.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_result.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_result.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_result.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_result.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_result.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_result.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_result.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_result.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_result.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_result.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_result.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_result.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_result.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return GRASP; };
    const char * getMD5(){ return "9b05623554ab950ed237d43d45f0b4dd"; };

  };

  class Grasp {
    public:
    typedef GraspRequest Request;
    typedef GraspResponse Response;
  };

}
#endif
