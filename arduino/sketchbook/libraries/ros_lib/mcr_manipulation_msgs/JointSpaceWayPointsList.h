#ifndef _ROS_mcr_manipulation_msgs_JointSpaceWayPointsList_h
#define _ROS_mcr_manipulation_msgs_JointSpaceWayPointsList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/String.h"

namespace mcr_manipulation_msgs
{

  class JointSpaceWayPointsList : public ros::Msg
  {
    public:
      uint8_t list_of_joint_values_lists_length;
      std_msgs::Float64MultiArray st_list_of_joint_values_lists;
      std_msgs::Float64MultiArray * list_of_joint_values_lists;
      uint8_t list_of_joint_positions_length;
      std_msgs::String st_list_of_joint_positions;
      std_msgs::String * list_of_joint_positions;

    JointSpaceWayPointsList():
      list_of_joint_values_lists_length(0), list_of_joint_values_lists(NULL),
      list_of_joint_positions_length(0), list_of_joint_positions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = list_of_joint_values_lists_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < list_of_joint_values_lists_length; i++){
      offset += this->list_of_joint_values_lists[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = list_of_joint_positions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < list_of_joint_positions_length; i++){
      offset += this->list_of_joint_positions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t list_of_joint_values_lists_lengthT = *(inbuffer + offset++);
      if(list_of_joint_values_lists_lengthT > list_of_joint_values_lists_length)
        this->list_of_joint_values_lists = (std_msgs::Float64MultiArray*)realloc(this->list_of_joint_values_lists, list_of_joint_values_lists_lengthT * sizeof(std_msgs::Float64MultiArray));
      offset += 3;
      list_of_joint_values_lists_length = list_of_joint_values_lists_lengthT;
      for( uint8_t i = 0; i < list_of_joint_values_lists_length; i++){
      offset += this->st_list_of_joint_values_lists.deserialize(inbuffer + offset);
        memcpy( &(this->list_of_joint_values_lists[i]), &(this->st_list_of_joint_values_lists), sizeof(std_msgs::Float64MultiArray));
      }
      uint8_t list_of_joint_positions_lengthT = *(inbuffer + offset++);
      if(list_of_joint_positions_lengthT > list_of_joint_positions_length)
        this->list_of_joint_positions = (std_msgs::String*)realloc(this->list_of_joint_positions, list_of_joint_positions_lengthT * sizeof(std_msgs::String));
      offset += 3;
      list_of_joint_positions_length = list_of_joint_positions_lengthT;
      for( uint8_t i = 0; i < list_of_joint_positions_length; i++){
      offset += this->st_list_of_joint_positions.deserialize(inbuffer + offset);
        memcpy( &(this->list_of_joint_positions[i]), &(this->st_list_of_joint_positions), sizeof(std_msgs::String));
      }
     return offset;
    }

    const char * getType(){ return "mcr_manipulation_msgs/JointSpaceWayPointsList"; };
    const char * getMD5(){ return "ee856daec9fc711792685fad2547394a"; };

  };

}
#endif