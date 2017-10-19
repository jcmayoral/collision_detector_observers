#ifndef _ROS_SERVICE_SetActiveDMP_h
#define _ROS_SERVICE_SetActiveDMP_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dmp/DMPData.h"

namespace dmp
{

static const char SETACTIVEDMP[] = "dmp/SetActiveDMP";

  class SetActiveDMPRequest : public ros::Msg
  {
    public:
      uint8_t dmp_list_length;
      dmp::DMPData st_dmp_list;
      dmp::DMPData * dmp_list;

    SetActiveDMPRequest():
      dmp_list_length(0), dmp_list(NULL)
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
     return offset;
    }

    const char * getType(){ return SETACTIVEDMP; };
    const char * getMD5(){ return "ec873fb8fce06b1431bf639280c06e64"; };

  };

  class SetActiveDMPResponse : public ros::Msg
  {
    public:
      bool success;

    SetActiveDMPResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return SETACTIVEDMP; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetActiveDMP {
    public:
    typedef SetActiveDMPRequest Request;
    typedef SetActiveDMPResponse Response;
  };

}
#endif
