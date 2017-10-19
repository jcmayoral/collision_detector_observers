#ifndef _ROS_SERVICE_BaseScanLinearRegression_h
#define _ROS_SERVICE_BaseScanLinearRegression_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mcr_perception_msgs
{

static const char BASESCANLINEARREGRESSION[] = "mcr_perception_msgs/BaseScanLinearRegression";

  class BaseScanLinearRegressionRequest : public ros::Msg
  {
    public:
      float filter_minDistance;
      float filter_maxDistance;
      float filter_minAngle;
      float filter_maxAngle;

    BaseScanLinearRegressionRequest():
      filter_minDistance(0),
      filter_maxDistance(0),
      filter_minAngle(0),
      filter_maxAngle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_filter_minDistance;
      u_filter_minDistance.real = this->filter_minDistance;
      *(outbuffer + offset + 0) = (u_filter_minDistance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filter_minDistance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filter_minDistance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filter_minDistance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->filter_minDistance);
      union {
        float real;
        uint32_t base;
      } u_filter_maxDistance;
      u_filter_maxDistance.real = this->filter_maxDistance;
      *(outbuffer + offset + 0) = (u_filter_maxDistance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filter_maxDistance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filter_maxDistance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filter_maxDistance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->filter_maxDistance);
      union {
        float real;
        uint32_t base;
      } u_filter_minAngle;
      u_filter_minAngle.real = this->filter_minAngle;
      *(outbuffer + offset + 0) = (u_filter_minAngle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filter_minAngle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filter_minAngle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filter_minAngle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->filter_minAngle);
      union {
        float real;
        uint32_t base;
      } u_filter_maxAngle;
      u_filter_maxAngle.real = this->filter_maxAngle;
      *(outbuffer + offset + 0) = (u_filter_maxAngle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filter_maxAngle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filter_maxAngle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filter_maxAngle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->filter_maxAngle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_filter_minDistance;
      u_filter_minDistance.base = 0;
      u_filter_minDistance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filter_minDistance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filter_minDistance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filter_minDistance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->filter_minDistance = u_filter_minDistance.real;
      offset += sizeof(this->filter_minDistance);
      union {
        float real;
        uint32_t base;
      } u_filter_maxDistance;
      u_filter_maxDistance.base = 0;
      u_filter_maxDistance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filter_maxDistance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filter_maxDistance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filter_maxDistance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->filter_maxDistance = u_filter_maxDistance.real;
      offset += sizeof(this->filter_maxDistance);
      union {
        float real;
        uint32_t base;
      } u_filter_minAngle;
      u_filter_minAngle.base = 0;
      u_filter_minAngle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filter_minAngle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filter_minAngle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filter_minAngle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->filter_minAngle = u_filter_minAngle.real;
      offset += sizeof(this->filter_minAngle);
      union {
        float real;
        uint32_t base;
      } u_filter_maxAngle;
      u_filter_maxAngle.base = 0;
      u_filter_maxAngle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filter_maxAngle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filter_maxAngle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filter_maxAngle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->filter_maxAngle = u_filter_maxAngle.real;
      offset += sizeof(this->filter_maxAngle);
     return offset;
    }

    const char * getType(){ return BASESCANLINEARREGRESSION; };
    const char * getMD5(){ return "9ac1be4fcb6a1b9bdf3735639924f4f4"; };

  };

  class BaseScanLinearRegressionResponse : public ros::Msg
  {
    public:
      float center;
      float a;
      float b;

    BaseScanLinearRegressionResponse():
      center(0),
      a(0),
      b(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_center;
      u_center.real = this->center;
      *(outbuffer + offset + 0) = (u_center.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_center.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_center.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_center.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->center);
      union {
        float real;
        uint32_t base;
      } u_a;
      u_a.real = this->a;
      *(outbuffer + offset + 0) = (u_a.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_a.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_a.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_a.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->a);
      union {
        float real;
        uint32_t base;
      } u_b;
      u_b.real = this->b;
      *(outbuffer + offset + 0) = (u_b.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_b.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_b.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_b.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->b);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_center;
      u_center.base = 0;
      u_center.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_center.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_center.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_center.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->center = u_center.real;
      offset += sizeof(this->center);
      union {
        float real;
        uint32_t base;
      } u_a;
      u_a.base = 0;
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->a = u_a.real;
      offset += sizeof(this->a);
      union {
        float real;
        uint32_t base;
      } u_b;
      u_b.base = 0;
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->b = u_b.real;
      offset += sizeof(this->b);
     return offset;
    }

    const char * getType(){ return BASESCANLINEARREGRESSION; };
    const char * getMD5(){ return "a61f4296e5bca669bfe75a5182eaf165"; };

  };

  class BaseScanLinearRegression {
    public:
    typedef BaseScanLinearRegressionRequest Request;
    typedef BaseScanLinearRegressionResponse Response;
  };

}
#endif
