#ifndef _ROS_mdr_speech_msgs_RecognizedSpeech_h
#define _ROS_mdr_speech_msgs_RecognizedSpeech_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mdr_speech_msgs
{

  class RecognizedSpeech : public ros::Msg
  {
    public:
      const char* understood_phrase;
      const char* keyword;
      float confidence;
      uint8_t keyword_list_length;
      char* st_keyword_list;
      char* * keyword_list;
      uint8_t confidence_list_length;
      float st_confidence_list;
      float * confidence_list;

    RecognizedSpeech():
      understood_phrase(""),
      keyword(""),
      confidence(0),
      keyword_list_length(0), keyword_list(NULL),
      confidence_list_length(0), confidence_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_understood_phrase = strlen(this->understood_phrase);
      memcpy(outbuffer + offset, &length_understood_phrase, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->understood_phrase, length_understood_phrase);
      offset += length_understood_phrase;
      uint32_t length_keyword = strlen(this->keyword);
      memcpy(outbuffer + offset, &length_keyword, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->keyword, length_keyword);
      offset += length_keyword;
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.real = this->confidence;
      *(outbuffer + offset + 0) = (u_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence);
      *(outbuffer + offset++) = keyword_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < keyword_list_length; i++){
      uint32_t length_keyword_listi = strlen(this->keyword_list[i]);
      memcpy(outbuffer + offset, &length_keyword_listi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->keyword_list[i], length_keyword_listi);
      offset += length_keyword_listi;
      }
      *(outbuffer + offset++) = confidence_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < confidence_list_length; i++){
      union {
        float real;
        uint32_t base;
      } u_confidence_listi;
      u_confidence_listi.real = this->confidence_list[i];
      *(outbuffer + offset + 0) = (u_confidence_listi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence_listi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence_listi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence_listi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence_list[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_understood_phrase;
      memcpy(&length_understood_phrase, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_understood_phrase; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_understood_phrase-1]=0;
      this->understood_phrase = (char *)(inbuffer + offset-1);
      offset += length_understood_phrase;
      uint32_t length_keyword;
      memcpy(&length_keyword, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_keyword; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_keyword-1]=0;
      this->keyword = (char *)(inbuffer + offset-1);
      offset += length_keyword;
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.base = 0;
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence = u_confidence.real;
      offset += sizeof(this->confidence);
      uint8_t keyword_list_lengthT = *(inbuffer + offset++);
      if(keyword_list_lengthT > keyword_list_length)
        this->keyword_list = (char**)realloc(this->keyword_list, keyword_list_lengthT * sizeof(char*));
      offset += 3;
      keyword_list_length = keyword_list_lengthT;
      for( uint8_t i = 0; i < keyword_list_length; i++){
      uint32_t length_st_keyword_list;
      memcpy(&length_st_keyword_list, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_keyword_list; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_keyword_list-1]=0;
      this->st_keyword_list = (char *)(inbuffer + offset-1);
      offset += length_st_keyword_list;
        memcpy( &(this->keyword_list[i]), &(this->st_keyword_list), sizeof(char*));
      }
      uint8_t confidence_list_lengthT = *(inbuffer + offset++);
      if(confidence_list_lengthT > confidence_list_length)
        this->confidence_list = (float*)realloc(this->confidence_list, confidence_list_lengthT * sizeof(float));
      offset += 3;
      confidence_list_length = confidence_list_lengthT;
      for( uint8_t i = 0; i < confidence_list_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_confidence_list;
      u_st_confidence_list.base = 0;
      u_st_confidence_list.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_confidence_list.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_confidence_list.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_confidence_list.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_confidence_list = u_st_confidence_list.real;
      offset += sizeof(this->st_confidence_list);
        memcpy( &(this->confidence_list[i]), &(this->st_confidence_list), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "mdr_speech_msgs/RecognizedSpeech"; };
    const char * getMD5(){ return "13b3d10aa164bf50eebaafa001188953"; };

  };

}
#endif