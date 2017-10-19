#ifndef _ROS_SERVICE_GetDMPPlan_h
#define _ROS_SERVICE_GetDMPPlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dmp/DMPTraj.h"

namespace dmp
{

static const char GETDMPPLAN[] = "dmp/GetDMPPlan";

  class GetDMPPlanRequest : public ros::Msg
  {
    public:
      uint8_t x_0_length;
      float st_x_0;
      float * x_0;
      uint8_t x_dot_0_length;
      float st_x_dot_0;
      float * x_dot_0;
      float t_0;
      uint8_t goal_length;
      float st_goal;
      float * goal;
      uint8_t goal_thresh_length;
      float st_goal_thresh;
      float * goal_thresh;
      float seg_length;
      float tau;
      float dt;
      int32_t integrate_iter;

    GetDMPPlanRequest():
      x_0_length(0), x_0(NULL),
      x_dot_0_length(0), x_dot_0(NULL),
      t_0(0),
      goal_length(0), goal(NULL),
      goal_thresh_length(0), goal_thresh(NULL),
      seg_length(0),
      tau(0),
      dt(0),
      integrate_iter(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = x_0_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < x_0_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->x_0[i]);
      }
      *(outbuffer + offset++) = x_dot_0_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < x_dot_0_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->x_dot_0[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->t_0);
      *(outbuffer + offset++) = goal_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < goal_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->goal[i]);
      }
      *(outbuffer + offset++) = goal_thresh_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < goal_thresh_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->goal_thresh[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->seg_length);
      offset += serializeAvrFloat64(outbuffer + offset, this->tau);
      offset += serializeAvrFloat64(outbuffer + offset, this->dt);
      union {
        int32_t real;
        uint32_t base;
      } u_integrate_iter;
      u_integrate_iter.real = this->integrate_iter;
      *(outbuffer + offset + 0) = (u_integrate_iter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_integrate_iter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_integrate_iter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_integrate_iter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->integrate_iter);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t x_0_lengthT = *(inbuffer + offset++);
      if(x_0_lengthT > x_0_length)
        this->x_0 = (float*)realloc(this->x_0, x_0_lengthT * sizeof(float));
      offset += 3;
      x_0_length = x_0_lengthT;
      for( uint8_t i = 0; i < x_0_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_x_0));
        memcpy( &(this->x_0[i]), &(this->st_x_0), sizeof(float));
      }
      uint8_t x_dot_0_lengthT = *(inbuffer + offset++);
      if(x_dot_0_lengthT > x_dot_0_length)
        this->x_dot_0 = (float*)realloc(this->x_dot_0, x_dot_0_lengthT * sizeof(float));
      offset += 3;
      x_dot_0_length = x_dot_0_lengthT;
      for( uint8_t i = 0; i < x_dot_0_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_x_dot_0));
        memcpy( &(this->x_dot_0[i]), &(this->st_x_dot_0), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->t_0));
      uint8_t goal_lengthT = *(inbuffer + offset++);
      if(goal_lengthT > goal_length)
        this->goal = (float*)realloc(this->goal, goal_lengthT * sizeof(float));
      offset += 3;
      goal_length = goal_lengthT;
      for( uint8_t i = 0; i < goal_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_goal));
        memcpy( &(this->goal[i]), &(this->st_goal), sizeof(float));
      }
      uint8_t goal_thresh_lengthT = *(inbuffer + offset++);
      if(goal_thresh_lengthT > goal_thresh_length)
        this->goal_thresh = (float*)realloc(this->goal_thresh, goal_thresh_lengthT * sizeof(float));
      offset += 3;
      goal_thresh_length = goal_thresh_lengthT;
      for( uint8_t i = 0; i < goal_thresh_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_goal_thresh));
        memcpy( &(this->goal_thresh[i]), &(this->st_goal_thresh), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->seg_length));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tau));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dt));
      union {
        int32_t real;
        uint32_t base;
      } u_integrate_iter;
      u_integrate_iter.base = 0;
      u_integrate_iter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_integrate_iter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_integrate_iter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_integrate_iter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->integrate_iter = u_integrate_iter.real;
      offset += sizeof(this->integrate_iter);
     return offset;
    }

    const char * getType(){ return GETDMPPLAN; };
    const char * getMD5(){ return "bae6b051e2f7b80225be1fd25b5b705a"; };

  };

  class GetDMPPlanResponse : public ros::Msg
  {
    public:
      dmp::DMPTraj plan;
      uint8_t at_goal;

    GetDMPPlanResponse():
      plan(),
      at_goal(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->plan.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->at_goal >> (8 * 0)) & 0xFF;
      offset += sizeof(this->at_goal);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->plan.deserialize(inbuffer + offset);
      this->at_goal =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->at_goal);
     return offset;
    }

    const char * getType(){ return GETDMPPLAN; };
    const char * getMD5(){ return "dcf9f84a71b2617cf4bbc301a97c05cd"; };

  };

  class GetDMPPlan {
    public:
    typedef GetDMPPlanRequest Request;
    typedef GetDMPPlanResponse Response;
  };

}
#endif
