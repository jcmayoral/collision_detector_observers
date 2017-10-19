#ifndef _ROS_SERVICE_PublishGoal_h
#define _ROS_SERVICE_PublishGoal_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace mcr_perception_msgs
{

static const char PUBLISHGOAL[] = "mcr_perception_msgs/PublishGoal";

  class PublishGoalRequest : public ros::Msg
  {
    public:
      const char* source_frame_id;
      const char* target_frame_id;
      const char* goal_frame_id;
      geometry_msgs::Vector3 displacement;

    PublishGoalRequest():
      source_frame_id(""),
      target_frame_id(""),
      goal_frame_id(""),
      displacement()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_source_frame_id = strlen(this->source_frame_id);
      memcpy(outbuffer + offset, &length_source_frame_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->source_frame_id, length_source_frame_id);
      offset += length_source_frame_id;
      uint32_t length_target_frame_id = strlen(this->target_frame_id);
      memcpy(outbuffer + offset, &length_target_frame_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->target_frame_id, length_target_frame_id);
      offset += length_target_frame_id;
      uint32_t length_goal_frame_id = strlen(this->goal_frame_id);
      memcpy(outbuffer + offset, &length_goal_frame_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->goal_frame_id, length_goal_frame_id);
      offset += length_goal_frame_id;
      offset += this->displacement.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_source_frame_id;
      memcpy(&length_source_frame_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source_frame_id-1]=0;
      this->source_frame_id = (char *)(inbuffer + offset-1);
      offset += length_source_frame_id;
      uint32_t length_target_frame_id;
      memcpy(&length_target_frame_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_frame_id-1]=0;
      this->target_frame_id = (char *)(inbuffer + offset-1);
      offset += length_target_frame_id;
      uint32_t length_goal_frame_id;
      memcpy(&length_goal_frame_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_goal_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_goal_frame_id-1]=0;
      this->goal_frame_id = (char *)(inbuffer + offset-1);
      offset += length_goal_frame_id;
      offset += this->displacement.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PUBLISHGOAL; };
    const char * getMD5(){ return "40c3ff951d7fa57e97dd80e4753f0db5"; };

  };

  class PublishGoalResponse : public ros::Msg
  {
    public:

    PublishGoalResponse()
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

    const char * getType(){ return PUBLISHGOAL; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class PublishGoal {
    public:
    typedef PublishGoalRequest Request;
    typedef PublishGoalResponse Response;
  };

}
#endif
