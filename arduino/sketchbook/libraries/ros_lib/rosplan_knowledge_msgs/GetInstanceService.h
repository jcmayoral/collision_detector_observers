#ifndef _ROS_SERVICE_GetInstanceService_h
#define _ROS_SERVICE_GetInstanceService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosplan_knowledge_msgs
{

static const char GETINSTANCESERVICE[] = "rosplan_knowledge_msgs/GetInstanceService";

  class GetInstanceServiceRequest : public ros::Msg
  {
    public:
      const char* type_name;

    GetInstanceServiceRequest():
      type_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type_name = strlen(this->type_name);
      memcpy(outbuffer + offset, &length_type_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type_name, length_type_name);
      offset += length_type_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type_name;
      memcpy(&length_type_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type_name-1]=0;
      this->type_name = (char *)(inbuffer + offset-1);
      offset += length_type_name;
     return offset;
    }

    const char * getType(){ return GETINSTANCESERVICE; };
    const char * getMD5(){ return "569d316f820d7b7abfa7db96b2ecffae"; };

  };

  class GetInstanceServiceResponse : public ros::Msg
  {
    public:
      uint8_t instances_length;
      char* st_instances;
      char* * instances;

    GetInstanceServiceResponse():
      instances_length(0), instances(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = instances_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < instances_length; i++){
      uint32_t length_instancesi = strlen(this->instances[i]);
      memcpy(outbuffer + offset, &length_instancesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->instances[i], length_instancesi);
      offset += length_instancesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t instances_lengthT = *(inbuffer + offset++);
      if(instances_lengthT > instances_length)
        this->instances = (char**)realloc(this->instances, instances_lengthT * sizeof(char*));
      offset += 3;
      instances_length = instances_lengthT;
      for( uint8_t i = 0; i < instances_length; i++){
      uint32_t length_st_instances;
      memcpy(&length_st_instances, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_instances; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_instances-1]=0;
      this->st_instances = (char *)(inbuffer + offset-1);
      offset += length_st_instances;
        memcpy( &(this->instances[i]), &(this->st_instances), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETINSTANCESERVICE; };
    const char * getMD5(){ return "c37cf4d14d6c5bfa6fbe319c1865eb5a"; };

  };

  class GetInstanceService {
    public:
    typedef GetInstanceServiceRequest Request;
    typedef GetInstanceServiceResponse Response;
  };

}
#endif
