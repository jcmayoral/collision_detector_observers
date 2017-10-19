#ifndef _ROS_SERVICE_KineticEnergyMonitorMsg_h
#define _ROS_SERVICE_KineticEnergyMonitorMsg_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace kinetic_energy_monitor
{

static const char KINETICENERGYMONITORMSG[] = "kinetic_energy_monitor/KineticEnergyMonitorMsg";

  class KineticEnergyMonitorMsgRequest : public ros::Msg
  {
    public:
      std_msgs::Header collision_time;

    KineticEnergyMonitorMsgRequest():
      collision_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->collision_time.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->collision_time.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return KINETICENERGYMONITORMSG; };
    const char * getMD5(){ return "59857b4a5006208c585e72b38af77d5a"; };

  };

  class KineticEnergyMonitorMsgResponse : public ros::Msg
  {
    public:
      bool success;
      float energy_lost;

    KineticEnergyMonitorMsgResponse():
      success(0),
      energy_lost(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      offset += serializeAvrFloat64(outbuffer + offset, this->energy_lost);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->energy_lost));
     return offset;
    }

    const char * getType(){ return KINETICENERGYMONITORMSG; };
    const char * getMD5(){ return "9d3449cdb109b0617f17a40a9cbb462b"; };

  };

  class KineticEnergyMonitorMsg {
    public:
    typedef KineticEnergyMonitorMsgRequest Request;
    typedef KineticEnergyMonitorMsgResponse Response;
  };

}
#endif
