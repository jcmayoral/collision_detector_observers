#ifndef _ROS_mcr_perception_msgs_FaceList_h
#define _ROS_mcr_perception_msgs_FaceList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mcr_perception_msgs/Face.h"

namespace mcr_perception_msgs
{

  class FaceList : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t num_faces;
      uint8_t faces_length;
      mcr_perception_msgs::Face st_faces;
      mcr_perception_msgs::Face * faces;

    FaceList():
      header(),
      num_faces(0),
      faces_length(0), faces(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->num_faces >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_faces >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_faces >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_faces >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_faces);
      *(outbuffer + offset++) = faces_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < faces_length; i++){
      offset += this->faces[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->num_faces =  ((uint32_t) (*(inbuffer + offset)));
      this->num_faces |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_faces |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_faces |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_faces);
      uint8_t faces_lengthT = *(inbuffer + offset++);
      if(faces_lengthT > faces_length)
        this->faces = (mcr_perception_msgs::Face*)realloc(this->faces, faces_lengthT * sizeof(mcr_perception_msgs::Face));
      offset += 3;
      faces_length = faces_lengthT;
      for( uint8_t i = 0; i < faces_length; i++){
      offset += this->st_faces.deserialize(inbuffer + offset);
        memcpy( &(this->faces[i]), &(this->st_faces), sizeof(mcr_perception_msgs::Face));
      }
     return offset;
    }

    const char * getType(){ return "mcr_perception_msgs/FaceList"; };
    const char * getMD5(){ return "9588a2ca312ec4d78ddb82bc8c1a275d"; };

  };

}
#endif