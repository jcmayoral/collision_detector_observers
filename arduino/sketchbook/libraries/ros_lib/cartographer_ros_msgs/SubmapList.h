#ifndef _ROS_cartographer_ros_msgs_SubmapList_h
#define _ROS_cartographer_ros_msgs_SubmapList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cartographer_ros_msgs/SubmapEntry.h"

namespace cartographer_ros_msgs
{

  class SubmapList : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t submap_length;
      cartographer_ros_msgs::SubmapEntry st_submap;
      cartographer_ros_msgs::SubmapEntry * submap;

    SubmapList():
      header(),
      submap_length(0), submap(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = submap_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < submap_length; i++){
      offset += this->submap[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t submap_lengthT = *(inbuffer + offset++);
      if(submap_lengthT > submap_length)
        this->submap = (cartographer_ros_msgs::SubmapEntry*)realloc(this->submap, submap_lengthT * sizeof(cartographer_ros_msgs::SubmapEntry));
      offset += 3;
      submap_length = submap_lengthT;
      for( uint8_t i = 0; i < submap_length; i++){
      offset += this->st_submap.deserialize(inbuffer + offset);
        memcpy( &(this->submap[i]), &(this->st_submap), sizeof(cartographer_ros_msgs::SubmapEntry));
      }
     return offset;
    }

    const char * getType(){ return "cartographer_ros_msgs/SubmapList"; };
    const char * getMD5(){ return "6efe809c4a0e69266aa99b3bea531f2a"; };

  };

}
#endif