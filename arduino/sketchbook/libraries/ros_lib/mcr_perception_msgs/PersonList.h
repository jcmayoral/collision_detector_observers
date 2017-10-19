#ifndef _ROS_mcr_perception_msgs_PersonList_h
#define _ROS_mcr_perception_msgs_PersonList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mcr_perception_msgs/Person.h"

namespace mcr_perception_msgs
{

  class PersonList : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t persons_length;
      mcr_perception_msgs::Person st_persons;
      mcr_perception_msgs::Person * persons;

    PersonList():
      header(),
      persons_length(0), persons(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = persons_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < persons_length; i++){
      offset += this->persons[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t persons_lengthT = *(inbuffer + offset++);
      if(persons_lengthT > persons_length)
        this->persons = (mcr_perception_msgs::Person*)realloc(this->persons, persons_lengthT * sizeof(mcr_perception_msgs::Person));
      offset += 3;
      persons_length = persons_lengthT;
      for( uint8_t i = 0; i < persons_length; i++){
      offset += this->st_persons.deserialize(inbuffer + offset);
        memcpy( &(this->persons[i]), &(this->st_persons), sizeof(mcr_perception_msgs::Person));
      }
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/PersonList"; };
    const char * getMD5(){ return "e87852aa7a0116cb77cb5b248239459a"; };

  };

}
#endif