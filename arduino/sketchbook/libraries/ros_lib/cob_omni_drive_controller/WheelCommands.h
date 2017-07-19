#ifndef _ROS_cob_omni_drive_controller_WheelCommands_h
#define _ROS_cob_omni_drive_controller_WheelCommands_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cob_omni_drive_controller
{

  class WheelCommands : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t drive_target_velocity_length;
      float st_drive_target_velocity;
      float * drive_target_velocity;
      uint8_t steer_target_velocity_length;
      float st_steer_target_velocity;
      float * steer_target_velocity;
      uint8_t steer_target_position_length;
      float st_steer_target_position;
      float * steer_target_position;
      uint8_t steer_target_error_length;
      float st_steer_target_error;
      float * steer_target_error;

    WheelCommands():
      header(),
      drive_target_velocity_length(0), drive_target_velocity(NULL),
      steer_target_velocity_length(0), steer_target_velocity(NULL),
      steer_target_position_length(0), steer_target_position(NULL),
      steer_target_error_length(0), steer_target_error(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = drive_target_velocity_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < drive_target_velocity_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->drive_target_velocity[i]);
      }
      *(outbuffer + offset++) = steer_target_velocity_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < steer_target_velocity_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->steer_target_velocity[i]);
      }
      *(outbuffer + offset++) = steer_target_position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < steer_target_position_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->steer_target_position[i]);
      }
      *(outbuffer + offset++) = steer_target_error_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < steer_target_error_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->steer_target_error[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t drive_target_velocity_lengthT = *(inbuffer + offset++);
      if(drive_target_velocity_lengthT > drive_target_velocity_length)
        this->drive_target_velocity = (float*)realloc(this->drive_target_velocity, drive_target_velocity_lengthT * sizeof(float));
      offset += 3;
      drive_target_velocity_length = drive_target_velocity_lengthT;
      for( uint8_t i = 0; i < drive_target_velocity_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_drive_target_velocity));
        memcpy( &(this->drive_target_velocity[i]), &(this->st_drive_target_velocity), sizeof(float));
      }
      uint8_t steer_target_velocity_lengthT = *(inbuffer + offset++);
      if(steer_target_velocity_lengthT > steer_target_velocity_length)
        this->steer_target_velocity = (float*)realloc(this->steer_target_velocity, steer_target_velocity_lengthT * sizeof(float));
      offset += 3;
      steer_target_velocity_length = steer_target_velocity_lengthT;
      for( uint8_t i = 0; i < steer_target_velocity_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_steer_target_velocity));
        memcpy( &(this->steer_target_velocity[i]), &(this->st_steer_target_velocity), sizeof(float));
      }
      uint8_t steer_target_position_lengthT = *(inbuffer + offset++);
      if(steer_target_position_lengthT > steer_target_position_length)
        this->steer_target_position = (float*)realloc(this->steer_target_position, steer_target_position_lengthT * sizeof(float));
      offset += 3;
      steer_target_position_length = steer_target_position_lengthT;
      for( uint8_t i = 0; i < steer_target_position_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_steer_target_position));
        memcpy( &(this->steer_target_position[i]), &(this->st_steer_target_position), sizeof(float));
      }
      uint8_t steer_target_error_lengthT = *(inbuffer + offset++);
      if(steer_target_error_lengthT > steer_target_error_length)
        this->steer_target_error = (float*)realloc(this->steer_target_error, steer_target_error_lengthT * sizeof(float));
      offset += 3;
      steer_target_error_length = steer_target_error_lengthT;
      for( uint8_t i = 0; i < steer_target_error_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_steer_target_error));
        memcpy( &(this->steer_target_error[i]), &(this->st_steer_target_error), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "cob_omni_drive_controller/WheelCommands"; };
    const char * getMD5(){ return "77ff79ee11678be45d9ecbc2cb9d23dd"; };

  };

}
#endif