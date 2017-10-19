#ifndef _ROS_mcr_perception_msgs_BoundingBoxList_h
#define _ROS_mcr_perception_msgs_BoundingBoxList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mcr_perception_msgs/BoundingBox.h"

namespace mcr_perception_msgs
{

  class BoundingBoxList : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t bounding_boxes_length;
      mcr_perception_msgs::BoundingBox st_bounding_boxes;
      mcr_perception_msgs::BoundingBox * bounding_boxes;

    BoundingBoxList():
      header(),
      bounding_boxes_length(0), bounding_boxes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = bounding_boxes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < bounding_boxes_length; i++){
      offset += this->bounding_boxes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t bounding_boxes_lengthT = *(inbuffer + offset++);
      if(bounding_boxes_lengthT > bounding_boxes_length)
        this->bounding_boxes = (mcr_perception_msgs::BoundingBox*)realloc(this->bounding_boxes, bounding_boxes_lengthT * sizeof(mcr_perception_msgs::BoundingBox));
      offset += 3;
      bounding_boxes_length = bounding_boxes_lengthT;
      for( uint8_t i = 0; i < bounding_boxes_length; i++){
      offset += this->st_bounding_boxes.deserialize(inbuffer + offset);
        memcpy( &(this->bounding_boxes[i]), &(this->st_bounding_boxes), sizeof(mcr_perception_msgs::BoundingBox));
      }
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/BoundingBoxList"; };
    const char * getMD5(){ return "c171c00c5f25e354ffdc3cb5fb686e8c"; };

  };

}
#endif