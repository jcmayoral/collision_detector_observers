#ifndef _ROS_cob_cartesian_controller_MoveCirc_h
#define _ROS_cob_cartesian_controller_MoveCirc_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace cob_cartesian_controller
{

  class MoveCirc : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose_center;
      const char* frame_id;
      float start_angle;
      float end_angle;
      float radius;

    MoveCirc():
      pose_center(),
      frame_id(""),
      start_angle(0),
      end_angle(0),
      radius(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose_center.serialize(outbuffer + offset);
      uint32_t length_frame_id = strlen(this->frame_id);
      memcpy(outbuffer + offset, &length_frame_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      offset += serializeAvrFloat64(outbuffer + offset, this->start_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->end_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->radius);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose_center.deserialize(inbuffer + offset);
      uint32_t length_frame_id;
      memcpy(&length_frame_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->start_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->end_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->radius));
     return offset;
    }

    const char * getType(){ return "cob_cartesian_controller/MoveCirc"; };
    const char * getMD5(){ return "803efebbec7e0afea7443ebc778555f3"; };

  };

}
#endif