#ifndef _ROS_SERVICE_PrologQuery_h
#define _ROS_SERVICE_PrologQuery_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace json_prolog_msgs
{

static const char PROLOGQUERY[] = "json_prolog_msgs/PrologQuery";

  class PrologQueryRequest : public ros::Msg
  {
    public:
      int8_t mode;
      const char* id;
      const char* query;
      enum { ALL_SOLUTIONS = 0 };
      enum { INCREMENTAL = 1 };

    PrologQueryRequest():
      mode(0),
      id(""),
      query("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      uint32_t length_query = strlen(this->query);
      memcpy(outbuffer + offset, &length_query, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->query, length_query);
      offset += length_query;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t length_query;
      memcpy(&length_query, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_query; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_query-1]=0;
      this->query = (char *)(inbuffer + offset-1);
      offset += length_query;
     return offset;
    }

    const char * getType(){ return PROLOGQUERY; };
    const char * getMD5(){ return "ae1d940ff32be0f4c9af16fc85baab7a"; };

  };

  class PrologQueryResponse : public ros::Msg
  {
    public:
      bool ok;
      const char* message;

    PrologQueryResponse():
      ok(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      uint32_t length_message = strlen(this->message);
      memcpy(outbuffer + offset, &length_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
      uint32_t length_message;
      memcpy(&length_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    const char * getType(){ return PROLOGQUERY; };
    const char * getMD5(){ return "f6fcb3b1ed8c7743c7fb7d5bcca28513"; };

  };

  class PrologQuery {
    public:
    typedef PrologQueryRequest Request;
    typedef PrologQueryResponse Response;
  };

}
#endif
