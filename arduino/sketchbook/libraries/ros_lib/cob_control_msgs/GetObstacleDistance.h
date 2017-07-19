#ifndef _ROS_SERVICE_GetObstacleDistance_h
#define _ROS_SERVICE_GetObstacleDistance_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_control_msgs
{

static const char GETOBSTACLEDISTANCE[] = "cob_control_msgs/GetObstacleDistance";

  class GetObstacleDistanceRequest : public ros::Msg
  {
    public:
      uint8_t links_length;
      char* st_links;
      char* * links;
      uint8_t objects_length;
      char* st_objects;
      char* * objects;

    GetObstacleDistanceRequest():
      links_length(0), links(NULL),
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = links_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < links_length; i++){
      uint32_t length_linksi = strlen(this->links[i]);
      memcpy(outbuffer + offset, &length_linksi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->links[i], length_linksi);
      offset += length_linksi;
      }
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
      uint8_t links_lengthT = *(inbuffer + offset++);
      if(links_lengthT > links_length)
        this->links = (char**)realloc(this->links, links_lengthT * sizeof(char*));
      offset += 3;
      links_length = links_lengthT;
      for( uint8_t i = 0; i < links_length; i++){
      uint32_t length_st_links;
      memcpy(&length_st_links, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_links; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_links-1]=0;
      this->st_links = (char *)(inbuffer + offset-1);
      offset += length_st_links;
        memcpy( &(this->links[i]), &(this->st_links), sizeof(char*));
      }
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

    const char * getType(){ return GETOBSTACLEDISTANCE; };
    const char * getMD5(){ return "26a63930cc171dbad7ae747d5d9efb00"; };

  };

  class GetObstacleDistanceResponse : public ros::Msg
  {
    public:
      uint8_t link_to_object_length;
      char* st_link_to_object;
      char* * link_to_object;
      uint8_t distances_length;
      float st_distances;
      float * distances;

    GetObstacleDistanceResponse():
      link_to_object_length(0), link_to_object(NULL),
      distances_length(0), distances(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = link_to_object_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < link_to_object_length; i++){
      uint32_t length_link_to_objecti = strlen(this->link_to_object[i]);
      memcpy(outbuffer + offset, &length_link_to_objecti, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_to_object[i], length_link_to_objecti);
      offset += length_link_to_objecti;
      }
      *(outbuffer + offset++) = distances_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < distances_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->distances[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t link_to_object_lengthT = *(inbuffer + offset++);
      if(link_to_object_lengthT > link_to_object_length)
        this->link_to_object = (char**)realloc(this->link_to_object, link_to_object_lengthT * sizeof(char*));
      offset += 3;
      link_to_object_length = link_to_object_lengthT;
      for( uint8_t i = 0; i < link_to_object_length; i++){
      uint32_t length_st_link_to_object;
      memcpy(&length_st_link_to_object, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_link_to_object; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_link_to_object-1]=0;
      this->st_link_to_object = (char *)(inbuffer + offset-1);
      offset += length_st_link_to_object;
        memcpy( &(this->link_to_object[i]), &(this->st_link_to_object), sizeof(char*));
      }
      uint8_t distances_lengthT = *(inbuffer + offset++);
      if(distances_lengthT > distances_length)
        this->distances = (float*)realloc(this->distances, distances_lengthT * sizeof(float));
      offset += 3;
      distances_length = distances_lengthT;
      for( uint8_t i = 0; i < distances_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_distances));
        memcpy( &(this->distances[i]), &(this->st_distances), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return GETOBSTACLEDISTANCE; };
    const char * getMD5(){ return "0f350045e25a569fa591e752a415419b"; };

  };

  class GetObstacleDistance {
    public:
    typedef GetObstacleDistanceRequest Request;
    typedef GetObstacleDistanceResponse Response;
  };

}
#endif
