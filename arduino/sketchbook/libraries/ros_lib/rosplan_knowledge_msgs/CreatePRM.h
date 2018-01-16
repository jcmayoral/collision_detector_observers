#ifndef _ROS_SERVICE_CreatePRM_h
#define _ROS_SERVICE_CreatePRM_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosplan_knowledge_msgs
{

static const char CREATEPRM[] = "rosplan_knowledge_msgs/CreatePRM";

  class CreatePRMRequest : public ros::Msg
  {
    public:
      int32_t nr_waypoints;
      float min_distance;
      float casting_distance;
      float connecting_distance;
      int8_t occupancy_threshold;
      int32_t total_attempts;

    CreatePRMRequest():
      nr_waypoints(0),
      min_distance(0),
      casting_distance(0),
      connecting_distance(0),
      occupancy_threshold(0),
      total_attempts(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_nr_waypoints;
      u_nr_waypoints.real = this->nr_waypoints;
      *(outbuffer + offset + 0) = (u_nr_waypoints.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nr_waypoints.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nr_waypoints.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nr_waypoints.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nr_waypoints);
      union {
        float real;
        uint32_t base;
      } u_min_distance;
      u_min_distance.real = this->min_distance;
      *(outbuffer + offset + 0) = (u_min_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_distance);
      union {
        float real;
        uint32_t base;
      } u_casting_distance;
      u_casting_distance.real = this->casting_distance;
      *(outbuffer + offset + 0) = (u_casting_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_casting_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_casting_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_casting_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->casting_distance);
      union {
        float real;
        uint32_t base;
      } u_connecting_distance;
      u_connecting_distance.real = this->connecting_distance;
      *(outbuffer + offset + 0) = (u_connecting_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_connecting_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_connecting_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_connecting_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->connecting_distance);
      union {
        int8_t real;
        uint8_t base;
      } u_occupancy_threshold;
      u_occupancy_threshold.real = this->occupancy_threshold;
      *(outbuffer + offset + 0) = (u_occupancy_threshold.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->occupancy_threshold);
      union {
        int32_t real;
        uint32_t base;
      } u_total_attempts;
      u_total_attempts.real = this->total_attempts;
      *(outbuffer + offset + 0) = (u_total_attempts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_attempts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_attempts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_attempts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total_attempts);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_nr_waypoints;
      u_nr_waypoints.base = 0;
      u_nr_waypoints.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nr_waypoints.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nr_waypoints.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nr_waypoints.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nr_waypoints = u_nr_waypoints.real;
      offset += sizeof(this->nr_waypoints);
      union {
        float real;
        uint32_t base;
      } u_min_distance;
      u_min_distance.base = 0;
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_distance = u_min_distance.real;
      offset += sizeof(this->min_distance);
      union {
        float real;
        uint32_t base;
      } u_casting_distance;
      u_casting_distance.base = 0;
      u_casting_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_casting_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_casting_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_casting_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->casting_distance = u_casting_distance.real;
      offset += sizeof(this->casting_distance);
      union {
        float real;
        uint32_t base;
      } u_connecting_distance;
      u_connecting_distance.base = 0;
      u_connecting_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_connecting_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_connecting_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_connecting_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->connecting_distance = u_connecting_distance.real;
      offset += sizeof(this->connecting_distance);
      union {
        int8_t real;
        uint8_t base;
      } u_occupancy_threshold;
      u_occupancy_threshold.base = 0;
      u_occupancy_threshold.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->occupancy_threshold = u_occupancy_threshold.real;
      offset += sizeof(this->occupancy_threshold);
      union {
        int32_t real;
        uint32_t base;
      } u_total_attempts;
      u_total_attempts.base = 0;
      u_total_attempts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_attempts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_attempts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_attempts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->total_attempts = u_total_attempts.real;
      offset += sizeof(this->total_attempts);
     return offset;
    }

    const char * getType(){ return CREATEPRM; };
    const char * getMD5(){ return "5f7c217e90f8fff8f615b66b6e7c4601"; };

  };

  class CreatePRMResponse : public ros::Msg
  {
    public:
      uint8_t waypoints_length;
      char* st_waypoints;
      char* * waypoints;

    CreatePRMResponse():
      waypoints_length(0), waypoints(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = waypoints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < waypoints_length; i++){
      uint32_t length_waypointsi = strlen(this->waypoints[i]);
      memcpy(outbuffer + offset, &length_waypointsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->waypoints[i], length_waypointsi);
      offset += length_waypointsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t waypoints_lengthT = *(inbuffer + offset++);
      if(waypoints_lengthT > waypoints_length)
        this->waypoints = (char**)realloc(this->waypoints, waypoints_lengthT * sizeof(char*));
      offset += 3;
      waypoints_length = waypoints_lengthT;
      for( uint8_t i = 0; i < waypoints_length; i++){
      uint32_t length_st_waypoints;
      memcpy(&length_st_waypoints, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_waypoints; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_waypoints-1]=0;
      this->st_waypoints = (char *)(inbuffer + offset-1);
      offset += length_st_waypoints;
        memcpy( &(this->waypoints[i]), &(this->st_waypoints), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return CREATEPRM; };
    const char * getMD5(){ return "49708eee94ad052e2e6e0398654eb86a"; };

  };

  class CreatePRM {
    public:
    typedef CreatePRMRequest Request;
    typedef CreatePRMResponse Response;
  };

}
#endif
