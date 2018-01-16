#ifndef _ROS_SERVICE_GenerateProblemService_h
#define _ROS_SERVICE_GenerateProblemService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosplan_knowledge_msgs
{

static const char GENERATEPROBLEMSERVICE[] = "rosplan_knowledge_msgs/GenerateProblemService";

  class GenerateProblemServiceRequest : public ros::Msg
  {
    public:
      const char* problem_path;
      bool contingent;

    GenerateProblemServiceRequest():
      problem_path(""),
      contingent(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_problem_path = strlen(this->problem_path);
      memcpy(outbuffer + offset, &length_problem_path, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->problem_path, length_problem_path);
      offset += length_problem_path;
      union {
        bool real;
        uint8_t base;
      } u_contingent;
      u_contingent.real = this->contingent;
      *(outbuffer + offset + 0) = (u_contingent.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contingent);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_problem_path;
      memcpy(&length_problem_path, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_problem_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_problem_path-1]=0;
      this->problem_path = (char *)(inbuffer + offset-1);
      offset += length_problem_path;
      union {
        bool real;
        uint8_t base;
      } u_contingent;
      u_contingent.base = 0;
      u_contingent.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contingent = u_contingent.real;
      offset += sizeof(this->contingent);
     return offset;
    }

    const char * getType(){ return GENERATEPROBLEMSERVICE; };
    const char * getMD5(){ return "dae78a0248c75ae0669c86950a3f99cf"; };

  };

  class GenerateProblemServiceResponse : public ros::Msg
  {
    public:
      const char* message;

    GenerateProblemServiceResponse():
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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

    const char * getType(){ return GENERATEPROBLEMSERVICE; };
    const char * getMD5(){ return "5f003d6bcc824cbd51361d66d8e4f76c"; };

  };

  class GenerateProblemService {
    public:
    typedef GenerateProblemServiceRequest Request;
    typedef GenerateProblemServiceResponse Response;
  };

}
#endif
