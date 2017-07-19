#ifndef _ROS_cob_perception_msgs_Float64ArrayStamped_h
#define _ROS_cob_perception_msgs_Float64ArrayStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cob_perception_msgs
{

  class Float64ArrayStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t data_length;
      float st_data;
      float * data;

    Float64ArrayStamped():
      header(),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (float*)realloc(this->data, data_lengthT * sizeof(float));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_data));
        memcpy( &(this->data[i]), &(this->st_data), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "cob_perception_msgs/Float64ArrayStamped"; };
    const char * getMD5(){ return "fb60495edd59d3fcf90e173153ae8a9a"; };

  };

}
#endif