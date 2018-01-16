#ifndef _ROS_SERVICE_PlanningService_h
#define _ROS_SERVICE_PlanningService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosplan_dispatch_msgs
{

static const char PLANNINGSERVICE[] = "rosplan_dispatch_msgs/PlanningService";

  class PlanningServiceRequest : public ros::Msg
  {
    public:
      const char* domain_path;
      const char* problem_path;
      const char* data_path;
      const char* planner_command;

    PlanningServiceRequest():
      domain_path(""),
      problem_path(""),
      data_path(""),
      planner_command("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_domain_path = strlen(this->domain_path);
      memcpy(outbuffer + offset, &length_domain_path, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->domain_path, length_domain_path);
      offset += length_domain_path;
      uint32_t length_problem_path = strlen(this->problem_path);
      memcpy(outbuffer + offset, &length_problem_path, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->problem_path, length_problem_path);
      offset += length_problem_path;
      uint32_t length_data_path = strlen(this->data_path);
      memcpy(outbuffer + offset, &length_data_path, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->data_path, length_data_path);
      offset += length_data_path;
      uint32_t length_planner_command = strlen(this->planner_command);
      memcpy(outbuffer + offset, &length_planner_command, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->planner_command, length_planner_command);
      offset += length_planner_command;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_domain_path;
      memcpy(&length_domain_path, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_domain_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_domain_path-1]=0;
      this->domain_path = (char *)(inbuffer + offset-1);
      offset += length_domain_path;
      uint32_t length_problem_path;
      memcpy(&length_problem_path, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_problem_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_problem_path-1]=0;
      this->problem_path = (char *)(inbuffer + offset-1);
      offset += length_problem_path;
      uint32_t length_data_path;
      memcpy(&length_data_path, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_data_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_data_path-1]=0;
      this->data_path = (char *)(inbuffer + offset-1);
      offset += length_data_path;
      uint32_t length_planner_command;
      memcpy(&length_planner_command, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_planner_command; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_planner_command-1]=0;
      this->planner_command = (char *)(inbuffer + offset-1);
      offset += length_planner_command;
     return offset;
    }

    const char * getType(){ return PLANNINGSERVICE; };
    const char * getMD5(){ return "b7b29f3dae421b04c9202694bb71079b"; };

  };

  class PlanningServiceResponse : public ros::Msg
  {
    public:

    PlanningServiceResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return PLANNINGSERVICE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class PlanningService {
    public:
    typedef PlanningServiceRequest Request;
    typedef PlanningServiceResponse Response;
  };

}
#endif
