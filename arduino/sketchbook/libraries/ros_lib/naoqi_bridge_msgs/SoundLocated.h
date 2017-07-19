#ifndef _ROS_naoqi_bridge_msgs_SoundLocated_h
#define _ROS_naoqi_bridge_msgs_SoundLocated_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Twist.h"

namespace naoqi_bridge_msgs
{

  class SoundLocated : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float azimuth;
      float elevation;
      float confidence;
      float energy;
      geometry_msgs::Twist head_position_frame_torso;
      geometry_msgs::Twist head_position_frame_robot;

    SoundLocated():
      header(),
      azimuth(0),
      elevation(0),
      confidence(0),
      energy(0),
      head_position_frame_torso(),
      head_position_frame_robot()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->azimuth);
      offset += serializeAvrFloat64(outbuffer + offset, this->elevation);
      offset += serializeAvrFloat64(outbuffer + offset, this->confidence);
      offset += serializeAvrFloat64(outbuffer + offset, this->energy);
      offset += this->head_position_frame_torso.serialize(outbuffer + offset);
      offset += this->head_position_frame_robot.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->azimuth));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->elevation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->confidence));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->energy));
      offset += this->head_position_frame_torso.deserialize(inbuffer + offset);
      offset += this->head_position_frame_robot.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/SoundLocated"; };
    const char * getMD5(){ return "884a2810157403bbdabfb1011c851b42"; };

  };

}
#endif