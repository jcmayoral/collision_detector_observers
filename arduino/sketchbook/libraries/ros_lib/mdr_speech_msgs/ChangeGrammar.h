#ifndef _ROS_SERVICE_ChangeGrammar_h
#define _ROS_SERVICE_ChangeGrammar_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mdr_speech_msgs
{

static const char CHANGEGRAMMAR[] = "mdr_speech_msgs/ChangeGrammar";

  class ChangeGrammarRequest : public ros::Msg
  {
    public:
      const char* grammar;

    ChangeGrammarRequest():
      grammar("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_grammar = strlen(this->grammar);
      memcpy(outbuffer + offset, &length_grammar, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->grammar, length_grammar);
      offset += length_grammar;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_grammar;
      memcpy(&length_grammar, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_grammar; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_grammar-1]=0;
      this->grammar = (char *)(inbuffer + offset-1);
      offset += length_grammar;
     return offset;
    }

    const char * getType(){ return CHANGEGRAMMAR; };
    const char * getMD5(){ return "a89e17113039052195c869cb16d71170"; };

  };

  class ChangeGrammarResponse : public ros::Msg
  {
    public:
      int64_t result;

    ChangeGrammarResponse():
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

    const char * getType(){ return CHANGEGRAMMAR; };
    const char * getMD5(){ return "9b05623554ab950ed237d43d45f0b4dd"; };

  };

  class ChangeGrammar {
    public:
    typedef ChangeGrammarRequest Request;
    typedef ChangeGrammarResponse Response;
  };

}
#endif
