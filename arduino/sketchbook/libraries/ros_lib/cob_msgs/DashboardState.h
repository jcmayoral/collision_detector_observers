#ifndef _ROS_cob_msgs_DashboardState_h
#define _ROS_cob_msgs_DashboardState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "diagnostic_msgs/DiagnosticStatus.h"
#include "cob_msgs/PowerState.h"
#include "cob_msgs/EmergencyStopState.h"

namespace cob_msgs
{

  class DashboardState : public ros::Msg
  {
    public:
      diagnostic_msgs::DiagnosticStatus diagnostics_toplevel_state;
      cob_msgs::PowerState power_state;
      cob_msgs::EmergencyStopState emergency_stop_state;

    DashboardState():
      diagnostics_toplevel_state(),
      power_state(),
      emergency_stop_state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->diagnostics_toplevel_state.serialize(outbuffer + offset);
      offset += this->power_state.serialize(outbuffer + offset);
      offset += this->emergency_stop_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->diagnostics_toplevel_state.deserialize(inbuffer + offset);
      offset += this->power_state.deserialize(inbuffer + offset);
      offset += this->emergency_stop_state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_msgs/DashboardState"; };
    const char * getMD5(){ return "ac6926484e7f901e4a07c74a0bf08792"; };

  };

}
#endif