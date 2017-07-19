#ifndef _ROS_cob_android_msgs_orderFeedback_h
#define _ROS_cob_android_msgs_orderFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_android_msgs
{

  class orderFeedback : public ros::Msg
  {
    public:
      const char* current_state;

    orderFeedback():
      current_state("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_current_state = strlen(this->current_state);
      memcpy(outbuffer + offset, &length_current_state, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->current_state, length_current_state);
      offset += length_current_state;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_current_state;
      memcpy(&length_current_state, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_current_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_current_state-1]=0;
      this->current_state = (char *)(inbuffer + offset-1);
      offset += length_current_state;
     return offset;
    }

    const char * getType(){ return "cob_android_msgs/orderFeedback"; };
    const char * getMD5(){ return "6b3c1b68b57cc9263bf79fc4ad6ec8c7"; };

  };

}
#endif