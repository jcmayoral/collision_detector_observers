#ifndef _ROS_cob_perception_msgs_PersonStamped_h
#define _ROS_cob_perception_msgs_PersonStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cob_perception_msgs/Person.h"

namespace cob_perception_msgs
{

  class PersonStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      cob_perception_msgs::Person person;

    PersonStamped():
      header(),
      person()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->person.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->person.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_perception_msgs/PersonStamped"; };
    const char * getMD5(){ return "08b504f30560aab069643e77a4cb4556"; };

  };

}
#endif