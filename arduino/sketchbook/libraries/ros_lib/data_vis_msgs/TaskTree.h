#ifndef _ROS_data_vis_msgs_TaskTree_h
#define _ROS_data_vis_msgs_TaskTree_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "data_vis_msgs/Task.h"

namespace data_vis_msgs
{

  class TaskTree : public ros::Msg
  {
    public:
      int32_t height;
      int32_t width;
      uint8_t tree_length;
      data_vis_msgs::Task st_tree;
      data_vis_msgs::Task * tree;

    TaskTree():
      height(0),
      width(0),
      tree_length(0), tree(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      *(outbuffer + offset++) = tree_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tree_length; i++){
      offset += this->tree[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height = u_height.real;
      offset += sizeof(this->height);
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->width = u_width.real;
      offset += sizeof(this->width);
      uint8_t tree_lengthT = *(inbuffer + offset++);
      if(tree_lengthT > tree_length)
        this->tree = (data_vis_msgs::Task*)realloc(this->tree, tree_lengthT * sizeof(data_vis_msgs::Task));
      offset += 3;
      tree_length = tree_lengthT;
      for( uint8_t i = 0; i < tree_length; i++){
      offset += this->st_tree.deserialize(inbuffer + offset);
        memcpy( &(this->tree[i]), &(this->st_tree), sizeof(data_vis_msgs::Task));
      }
     return offset;
    }

    const char * getType(){ return "data_vis_msgs/TaskTree"; };
    const char * getMD5(){ return "a4447319272190b864fdbc5675f1daae"; };

  };

}
#endif