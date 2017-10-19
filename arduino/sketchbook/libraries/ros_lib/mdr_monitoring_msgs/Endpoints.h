#ifndef _ROS_mdr_monitoring_msgs_Endpoints_h
#define _ROS_mdr_monitoring_msgs_Endpoints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mdr_monitoring_msgs/AudioEndpoint.h"

namespace mdr_monitoring_msgs
{

  class Endpoints : public ros::Msg
  {
    public:
      uint8_t endpoints_length;
      mdr_monitoring_msgs::AudioEndpoint st_endpoints;
      mdr_monitoring_msgs::AudioEndpoint * endpoints;

    Endpoints():
      endpoints_length(0), endpoints(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = endpoints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < endpoints_length; i++){
      offset += this->endpoints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t endpoints_lengthT = *(inbuffer + offset++);
      if(endpoints_lengthT > endpoints_length)
        this->endpoints = (mdr_monitoring_msgs::AudioEndpoint*)realloc(this->endpoints, endpoints_lengthT * sizeof(mdr_monitoring_msgs::AudioEndpoint));
      offset += 3;
      endpoints_length = endpoints_lengthT;
      for( uint8_t i = 0; i < endpoints_length; i++){
      offset += this->st_endpoints.deserialize(inbuffer + offset);
        memcpy( &(this->endpoints[i]), &(this->st_endpoints), sizeof(mdr_monitoring_msgs::AudioEndpoint));
      }
     return offset;
    }

    const char * getType(){ return "mdr_monitoring_msgs/Endpoints"; };
    const char * getMD5(){ return "4b683696d28e22d0a0a8aa315661f92b"; };

  };

}
#endif