#ifndef _ROS_mcr_perception_msgs_LaserScanSegmentList_h
#define _ROS_mcr_perception_msgs_LaserScanSegmentList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mcr_perception_msgs/LaserScanSegment.h"

namespace mcr_perception_msgs
{

  class LaserScanSegmentList : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t num_segments;
      uint8_t segments_length;
      mcr_perception_msgs::LaserScanSegment st_segments;
      mcr_perception_msgs::LaserScanSegment * segments;

    LaserScanSegmentList():
      header(),
      num_segments(0),
      segments_length(0), segments(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->num_segments >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_segments >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_segments >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_segments >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_segments);
      *(outbuffer + offset++) = segments_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < segments_length; i++){
      offset += this->segments[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->num_segments =  ((uint32_t) (*(inbuffer + offset)));
      this->num_segments |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_segments |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_segments |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_segments);
      uint8_t segments_lengthT = *(inbuffer + offset++);
      if(segments_lengthT > segments_length)
        this->segments = (mcr_perception_msgs::LaserScanSegment*)realloc(this->segments, segments_lengthT * sizeof(mcr_perception_msgs::LaserScanSegment));
      offset += 3;
      segments_length = segments_lengthT;
      for( uint8_t i = 0; i < segments_length; i++){
      offset += this->st_segments.deserialize(inbuffer + offset);
        memcpy( &(this->segments[i]), &(this->st_segments), sizeof(mcr_perception_msgs::LaserScanSegment));
      }
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/LaserScanSegmentList"; };
    const char * getMD5(){ return "62fd0174d9cc065690b5238dac4cba1a"; };

  };

}
#endif