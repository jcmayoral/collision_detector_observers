#ifndef _ROS_mir_knowledge_base_analyzer_ObjectsAtLocation_h
#define _ROS_mir_knowledge_base_analyzer_ObjectsAtLocation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mir_knowledge_base_analyzer
{

  class ObjectsAtLocation : public ros::Msg
  {
    public:
      const char* location;
      uint8_t objects_length;
      char* st_objects;
      char* * objects;

    ObjectsAtLocation():
      location(""),
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_location = strlen(this->location);
      memcpy(outbuffer + offset, &length_location, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->location, length_location);
      offset += length_location;
      *(outbuffer + offset++) = objects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < objects_length; i++){
      uint32_t length_objectsi = strlen(this->objects[i]);
      memcpy(outbuffer + offset, &length_objectsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->objects[i], length_objectsi);
      offset += length_objectsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_location;
      memcpy(&length_location, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_location; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_location-1]=0;
      this->location = (char *)(inbuffer + offset-1);
      offset += length_location;
      uint8_t objects_lengthT = *(inbuffer + offset++);
      if(objects_lengthT > objects_length)
        this->objects = (char**)realloc(this->objects, objects_lengthT * sizeof(char*));
      offset += 3;
      objects_length = objects_lengthT;
      for( uint8_t i = 0; i < objects_length; i++){
      uint32_t length_st_objects;
      memcpy(&length_st_objects, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_objects; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_objects-1]=0;
      this->st_objects = (char *)(inbuffer + offset-1);
      offset += length_st_objects;
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "mir_knowledge_base_analyzer/ObjectsAtLocation"; };
    const char * getMD5(){ return "392cb17a403b8100390ddd3e289c262e"; };

  };

}
#endif