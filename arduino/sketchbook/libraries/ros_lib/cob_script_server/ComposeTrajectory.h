#ifndef _ROS_SERVICE_ComposeTrajectory_h
#define _ROS_SERVICE_ComposeTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"

namespace cob_script_server
{

static const char COMPOSETRAJECTORY[] = "cob_script_server/ComposeTrajectory";

  class ComposeTrajectoryRequest : public ros::Msg
  {
    public:
      const char* component_name;
      const char* parameter_name;

    ComposeTrajectoryRequest():
      component_name(""),
      parameter_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_component_name = strlen(this->component_name);
      memcpy(outbuffer + offset, &length_component_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->component_name, length_component_name);
      offset += length_component_name;
      uint32_t length_parameter_name = strlen(this->parameter_name);
      memcpy(outbuffer + offset, &length_parameter_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->parameter_name, length_parameter_name);
      offset += length_parameter_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_component_name;
      memcpy(&length_component_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_component_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_component_name-1]=0;
      this->component_name = (char *)(inbuffer + offset-1);
      offset += length_component_name;
      uint32_t length_parameter_name;
      memcpy(&length_parameter_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parameter_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parameter_name-1]=0;
      this->parameter_name = (char *)(inbuffer + offset-1);
      offset += length_parameter_name;
     return offset;
    }

    const char * getType(){ return COMPOSETRAJECTORY; };
    const char * getMD5(){ return "76372377a1482b46491653676d8d40f4"; };

  };

  class ComposeTrajectoryResponse : public ros::Msg
  {
    public:
      trajectory_msgs::JointTrajectory trajectory;

    ComposeTrajectoryResponse():
      trajectory()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return COMPOSETRAJECTORY; };
    const char * getMD5(){ return "2a0eff76c870e8595636c2a562ca298e"; };

  };

  class ComposeTrajectory {
    public:
    typedef ComposeTrajectoryRequest Request;
    typedef ComposeTrajectoryResponse Response;
  };

}
#endif
