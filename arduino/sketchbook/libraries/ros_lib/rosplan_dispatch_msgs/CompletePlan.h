#ifndef _ROS_rosplan_dispatch_msgs_CompletePlan_h
#define _ROS_rosplan_dispatch_msgs_CompletePlan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rosplan_dispatch_msgs/ActionDispatch.h"

namespace rosplan_dispatch_msgs
{

  class CompletePlan : public ros::Msg
  {
    public:
      uint8_t plan_length;
      rosplan_dispatch_msgs::ActionDispatch st_plan;
      rosplan_dispatch_msgs::ActionDispatch * plan;

    CompletePlan():
      plan_length(0), plan(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = plan_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < plan_length; i++){
      offset += this->plan[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t plan_lengthT = *(inbuffer + offset++);
      if(plan_lengthT > plan_length)
        this->plan = (rosplan_dispatch_msgs::ActionDispatch*)realloc(this->plan, plan_lengthT * sizeof(rosplan_dispatch_msgs::ActionDispatch));
      offset += 3;
      plan_length = plan_lengthT;
      for( uint8_t i = 0; i < plan_length; i++){
      offset += this->st_plan.deserialize(inbuffer + offset);
        memcpy( &(this->plan[i]), &(this->st_plan), sizeof(rosplan_dispatch_msgs::ActionDispatch));
      }
     return offset;
    }

    const char * getType(){ return "rosplan_dispatch_msgs/CompletePlan"; };
    const char * getMD5(){ return "7e1d10b4d2f9481e13d9d30c7a8045ff"; };

  };

}
#endif