#ifndef _ROS_SERVICE_AnalyzeCloudColor_h
#define _ROS_SERVICE_AnalyzeCloudColor_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"

namespace mcr_perception_msgs
{

static const char ANALYZECLOUDCOLOR[] = "mcr_perception_msgs/AnalyzeCloudColor";

  class AnalyzeCloudColorRequest : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 cloud;

    AnalyzeCloudColorRequest():
      cloud()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->cloud.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->cloud.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ANALYZECLOUDCOLOR; };
    const char * getMD5(){ return "96cec5374164b3b3d1d7ef5d7628a7ed"; };

  };

  class AnalyzeCloudColorResponse : public ros::Msg
  {
    public:
      float mean;
      float median;
      uint64_t points;

    AnalyzeCloudColorResponse():
      mean(0),
      median(0),
      points(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_mean;
      u_mean.real = this->mean;
      *(outbuffer + offset + 0) = (u_mean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mean.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mean);
      union {
        float real;
        uint32_t base;
      } u_median;
      u_median.real = this->median;
      *(outbuffer + offset + 0) = (u_median.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_median.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_median.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_median.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->median);
      union {
        uint64_t real;
        uint32_t base;
      } u_points;
      u_points.real = this->points;
      *(outbuffer + offset + 0) = (u_points.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_points.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_points.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_points.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_mean;
      u_mean.base = 0;
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mean = u_mean.real;
      offset += sizeof(this->mean);
      union {
        float real;
        uint32_t base;
      } u_median;
      u_median.base = 0;
      u_median.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_median.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_median.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_median.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->median = u_median.real;
      offset += sizeof(this->median);
      union {
        uint64_t real;
        uint32_t base;
      } u_points;
      u_points.base = 0;
      u_points.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_points.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_points.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_points.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->points = u_points.real;
      offset += sizeof(this->points);
     return offset;
    }

    const char * getType(){ return ANALYZECLOUDCOLOR; };
    const char * getMD5(){ return "b73a456e20e2543281b5f8315a5249d8"; };

  };

  class AnalyzeCloudColor {
    public:
    typedef AnalyzeCloudColorRequest Request;
    typedef AnalyzeCloudColorResponse Response;
  };

}
#endif
