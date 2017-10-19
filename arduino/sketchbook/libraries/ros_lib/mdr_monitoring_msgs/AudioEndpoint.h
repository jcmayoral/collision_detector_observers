#ifndef _ROS_mdr_monitoring_msgs_AudioEndpoint_h
#define _ROS_mdr_monitoring_msgs_AudioEndpoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mdr_monitoring_msgs
{

  class AudioEndpoint : public ros::Msg
  {
    public:
      const char* Id;
      const char* State;
      bool Mute;
      float MasterVolumeLevelScalar;

    AudioEndpoint():
      Id(""),
      State(""),
      Mute(0),
      MasterVolumeLevelScalar(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_Id = strlen(this->Id);
      memcpy(outbuffer + offset, &length_Id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->Id, length_Id);
      offset += length_Id;
      uint32_t length_State = strlen(this->State);
      memcpy(outbuffer + offset, &length_State, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->State, length_State);
      offset += length_State;
      union {
        bool real;
        uint8_t base;
      } u_Mute;
      u_Mute.real = this->Mute;
      *(outbuffer + offset + 0) = (u_Mute.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Mute);
      union {
        float real;
        uint32_t base;
      } u_MasterVolumeLevelScalar;
      u_MasterVolumeLevelScalar.real = this->MasterVolumeLevelScalar;
      *(outbuffer + offset + 0) = (u_MasterVolumeLevelScalar.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_MasterVolumeLevelScalar.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_MasterVolumeLevelScalar.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_MasterVolumeLevelScalar.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->MasterVolumeLevelScalar);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_Id;
      memcpy(&length_Id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_Id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_Id-1]=0;
      this->Id = (char *)(inbuffer + offset-1);
      offset += length_Id;
      uint32_t length_State;
      memcpy(&length_State, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_State; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_State-1]=0;
      this->State = (char *)(inbuffer + offset-1);
      offset += length_State;
      union {
        bool real;
        uint8_t base;
      } u_Mute;
      u_Mute.base = 0;
      u_Mute.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Mute = u_Mute.real;
      offset += sizeof(this->Mute);
      union {
        float real;
        uint32_t base;
      } u_MasterVolumeLevelScalar;
      u_MasterVolumeLevelScalar.base = 0;
      u_MasterVolumeLevelScalar.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_MasterVolumeLevelScalar.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_MasterVolumeLevelScalar.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_MasterVolumeLevelScalar.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->MasterVolumeLevelScalar = u_MasterVolumeLevelScalar.real;
      offset += sizeof(this->MasterVolumeLevelScalar);
     return offset;
    }

    const char * getType(){ return "mdr_monitoring_msgs/AudioEndpoint"; };
    const char * getMD5(){ return "798abc9d07349ce6c6f8a27bef0e3353"; };

  };

}
#endif