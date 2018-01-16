#ifndef _ROS_cob_light_LightMode_h
#define _ROS_cob_light_LightMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"
#include "cob_light/Sequence.h"

namespace cob_light
{

  class LightMode : public ros::Msg
  {
    public:
      uint8_t mode;
      float frequency;
      float timeout;
      int32_t pulses;
      int8_t priority;
      uint8_t colors_length;
      std_msgs::ColorRGBA st_colors;
      std_msgs::ColorRGBA * colors;
      uint8_t sequences_length;
      cob_light::Sequence st_sequences;
      cob_light::Sequence * sequences;

    LightMode():
      mode(0),
      frequency(0),
      timeout(0),
      pulses(0),
      priority(0),
      colors_length(0), colors(NULL),
      sequences_length(0), sequences(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_frequency;
      u_frequency.real = this->frequency;
      *(outbuffer + offset + 0) = (u_frequency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frequency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frequency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frequency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequency);
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.real = this->timeout;
      *(outbuffer + offset + 0) = (u_timeout.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeout.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeout.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeout.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout);
      union {
        int32_t real;
        uint32_t base;
      } u_pulses;
      u_pulses.real = this->pulses;
      *(outbuffer + offset + 0) = (u_pulses.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pulses.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pulses.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pulses.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pulses);
      union {
        int8_t real;
        uint8_t base;
      } u_priority;
      u_priority.real = this->priority;
      *(outbuffer + offset + 0) = (u_priority.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->priority);
      *(outbuffer + offset++) = colors_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < colors_length; i++){
      offset += this->colors[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = sequences_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sequences_length; i++){
      offset += this->sequences[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_frequency;
      u_frequency.base = 0;
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->frequency = u_frequency.real;
      offset += sizeof(this->frequency);
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.base = 0;
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeout = u_timeout.real;
      offset += sizeof(this->timeout);
      union {
        int32_t real;
        uint32_t base;
      } u_pulses;
      u_pulses.base = 0;
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pulses = u_pulses.real;
      offset += sizeof(this->pulses);
      union {
        int8_t real;
        uint8_t base;
      } u_priority;
      u_priority.base = 0;
      u_priority.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->priority = u_priority.real;
      offset += sizeof(this->priority);
      uint8_t colors_lengthT = *(inbuffer + offset++);
      if(colors_lengthT > colors_length)
        this->colors = (std_msgs::ColorRGBA*)realloc(this->colors, colors_lengthT * sizeof(std_msgs::ColorRGBA));
      offset += 3;
      colors_length = colors_lengthT;
      for( uint8_t i = 0; i < colors_length; i++){
      offset += this->st_colors.deserialize(inbuffer + offset);
        memcpy( &(this->colors[i]), &(this->st_colors), sizeof(std_msgs::ColorRGBA));
      }
      uint8_t sequences_lengthT = *(inbuffer + offset++);
      if(sequences_lengthT > sequences_length)
        this->sequences = (cob_light::Sequence*)realloc(this->sequences, sequences_lengthT * sizeof(cob_light::Sequence));
      offset += 3;
      sequences_length = sequences_lengthT;
      for( uint8_t i = 0; i < sequences_length; i++){
      offset += this->st_sequences.deserialize(inbuffer + offset);
        memcpy( &(this->sequences[i]), &(this->st_sequences), sizeof(cob_light::Sequence));
      }
     return offset;
    }

    const char * getType(){ return "cob_light/LightMode"; };
    const char * getMD5(){ return "7aecb45b0da2ee8d387f2bec4ee2faf9"; };

  };

}
#endif