#ifndef _ROS_mcr_perception_msgs_BlobList_h
#define _ROS_mcr_perception_msgs_BlobList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mcr_perception_msgs/Blob.h"

namespace mcr_perception_msgs
{

  class BlobList : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t blobs_length;
      mcr_perception_msgs::Blob st_blobs;
      mcr_perception_msgs::Blob * blobs;

    BlobList():
      header(),
      blobs_length(0), blobs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = blobs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < blobs_length; i++){
      offset += this->blobs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t blobs_lengthT = *(inbuffer + offset++);
      if(blobs_lengthT > blobs_length)
        this->blobs = (mcr_perception_msgs::Blob*)realloc(this->blobs, blobs_lengthT * sizeof(mcr_perception_msgs::Blob));
      offset += 3;
      blobs_length = blobs_lengthT;
      for( uint8_t i = 0; i < blobs_length; i++){
      offset += this->st_blobs.deserialize(inbuffer + offset);
        memcpy( &(this->blobs[i]), &(this->st_blobs), sizeof(mcr_perception_msgs::Blob));
      }
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/BlobList"; };
    const char * getMD5(){ return "061775e4256e33a3e8a40bc980be9a39"; };

  };

}
#endif