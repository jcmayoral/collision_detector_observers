#ifndef _ROS_SERVICE_MakeBoundingBoxes_h
#define _ROS_SERVICE_MakeBoundingBoxes_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mcr_perception_msgs/BoundingBox.h"
#include "sensor_msgs/PointCloud2.h"
#include "geometry_msgs/Vector3.h"

namespace mcr_perception_msgs
{

static const char MAKEBOUNDINGBOXES[] = "mcr_perception_msgs/MakeBoundingBoxes";

  class MakeBoundingBoxesRequest : public ros::Msg
  {
    public:
      uint8_t clouds_length;
      sensor_msgs::PointCloud2 st_clouds;
      sensor_msgs::PointCloud2 * clouds;
      geometry_msgs::Vector3 axis;

    MakeBoundingBoxesRequest():
      clouds_length(0), clouds(NULL),
      axis()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = clouds_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < clouds_length; i++){
      offset += this->clouds[i].serialize(outbuffer + offset);
      }
      offset += this->axis.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t clouds_lengthT = *(inbuffer + offset++);
      if(clouds_lengthT > clouds_length)
        this->clouds = (sensor_msgs::PointCloud2*)realloc(this->clouds, clouds_lengthT * sizeof(sensor_msgs::PointCloud2));
      offset += 3;
      clouds_length = clouds_lengthT;
      for( uint8_t i = 0; i < clouds_length; i++){
      offset += this->st_clouds.deserialize(inbuffer + offset);
        memcpy( &(this->clouds[i]), &(this->st_clouds), sizeof(sensor_msgs::PointCloud2));
      }
      offset += this->axis.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MAKEBOUNDINGBOXES; };
    const char * getMD5(){ return "00d7485024fad914b8246693379adc6c"; };

  };

  class MakeBoundingBoxesResponse : public ros::Msg
  {
    public:
      uint8_t bounding_boxes_length;
      mcr_perception_msgs::BoundingBox st_bounding_boxes;
      mcr_perception_msgs::BoundingBox * bounding_boxes;

    MakeBoundingBoxesResponse():
      bounding_boxes_length(0), bounding_boxes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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

    const char * getType(){ return MAKEBOUNDINGBOXES; };
    const char * getMD5(){ return "be63947400421198010472eec2e89279"; };

  };

  class MakeBoundingBoxes {
    public:
    typedef MakeBoundingBoxesRequest Request;
    typedef MakeBoundingBoxesResponse Response;
  };

}
#endif
