#ifndef _ROS_SERVICE_AddWaypoint_h
#define _ROS_SERVICE_AddWaypoint_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace rosplan_knowledge_msgs
{

static const char ADDWAYPOINT[] = "rosplan_knowledge_msgs/AddWaypoint";

  class AddWaypointRequest : public ros::Msg
  {
    public:
      const char* id;
      geometry_msgs::PoseStamped waypoint;
      float connecting_distance;
      int8_t occupancy_threshold;

    AddWaypointRequest():
      id(""),
      waypoint(),
      connecting_distance(0),
      occupancy_threshold(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      offset += this->waypoint.serialize(outbuffer + offset);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      offset += this->waypoint.deserialize(inbuffer + offset);
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
     return offset;
    }

    const char * getType(){ return ADDWAYPOINT; };
    const char * getMD5(){ return "fbea0e8b407ac37bdef7686a7516a2fd"; };

  };

  class AddWaypointResponse : public ros::Msg
  {
    public:

    AddWaypointResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return ADDWAYPOINT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AddWaypoint {
    public:
    typedef AddWaypointRequest Request;
    typedef AddWaypointResponse Response;
  };

}
#endif
