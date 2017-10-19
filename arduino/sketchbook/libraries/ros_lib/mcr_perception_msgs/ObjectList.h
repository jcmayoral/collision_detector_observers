#ifndef _ROS_mcr_perception_msgs_ObjectList_h
#define _ROS_mcr_perception_msgs_ObjectList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mcr_perception_msgs/Object.h"

namespace mcr_perception_msgs
{

  class ObjectList : public ros::Msg
  {
    public:
      uint8_t objects_length;
      mcr_perception_msgs::Object st_objects;
      mcr_perception_msgs::Object * objects;

    ObjectList():
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = objects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t objects_lengthT = *(inbuffer + offset++);
      if(objects_lengthT > objects_length)
        this->objects = (mcr_perception_msgs::Object*)realloc(this->objects, objects_lengthT * sizeof(mcr_perception_msgs::Object));
      offset += 3;
      objects_length = objects_lengthT;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(mcr_perception_msgs::Object));
      }
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/ObjectList"; };
    const char * getMD5(){ return "6a2b117063d9179dd722a0691d739044"; };

  };

}
#endif