#ifndef _ROS_mcr_common_msgs_PoseStampedList_h
#define _ROS_mcr_common_msgs_PoseStampedList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace mcr_common_msgs
{

  class PoseStampedList : public ros::Msg
  {
    public:
      uint8_t poses_length;
      geometry_msgs::PoseStamped st_poses;
      geometry_msgs::PoseStamped * poses;

    PoseStampedList():
      poses_length(0), poses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = poses_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t poses_lengthT = *(inbuffer + offset++);
      if(poses_lengthT > poses_length)
        this->poses = (geometry_msgs::PoseStamped*)realloc(this->poses, poses_lengthT * sizeof(geometry_msgs::PoseStamped));
      offset += 3;
      poses_length = poses_lengthT;
      for( uint8_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(geometry_msgs::PoseStamped));
      }
     return offset;
    }

    const char * getType(){ return "mcr_common_msgs/PoseStampedList"; };
    const char * getMD5(){ return "f4bbbec105a3dc69d6c5974def547813"; };

  };

}
#endif