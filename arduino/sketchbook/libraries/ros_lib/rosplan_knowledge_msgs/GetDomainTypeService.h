#ifndef _ROS_SERVICE_GetDomainTypeService_h
#define _ROS_SERVICE_GetDomainTypeService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosplan_knowledge_msgs
{

static const char GETDOMAINTYPESERVICE[] = "rosplan_knowledge_msgs/GetDomainTypeService";

  class GetDomainTypeServiceRequest : public ros::Msg
  {
    public:

    GetDomainTypeServiceRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETDOMAINTYPESERVICE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetDomainTypeServiceResponse : public ros::Msg
  {
    public:
      uint8_t types_length;
      char* st_types;
      char* * types;

    GetDomainTypeServiceResponse():
      types_length(0), types(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = types_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < types_length; i++){
      uint32_t length_typesi = strlen(this->types[i]);
      memcpy(outbuffer + offset, &length_typesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->types[i], length_typesi);
      offset += length_typesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t types_lengthT = *(inbuffer + offset++);
      if(types_lengthT > types_length)
        this->types = (char**)realloc(this->types, types_lengthT * sizeof(char*));
      offset += 3;
      types_length = types_lengthT;
      for( uint8_t i = 0; i < types_length; i++){
      uint32_t length_st_types;
      memcpy(&length_st_types, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_types; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_types-1]=0;
      this->st_types = (char *)(inbuffer + offset-1);
      offset += length_st_types;
        memcpy( &(this->types[i]), &(this->st_types), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETDOMAINTYPESERVICE; };
    const char * getMD5(){ return "80aee506387f88339842e9a93044c959"; };

  };

  class GetDomainTypeService {
    public:
    typedef GetDomainTypeServiceRequest Request;
    typedef GetDomainTypeServiceResponse Response;
  };

}
#endif
