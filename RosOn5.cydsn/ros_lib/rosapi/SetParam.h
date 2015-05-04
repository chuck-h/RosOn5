#ifndef _ROS_SERVICE_SetParam_h
#define _ROS_SERVICE_SetParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosapi
{

static const char SETPARAM[] = "rosapi/SetParam";

  class SetParamRequest : public ros::Msg
  {
    public:
      const char* name;
      const char* value;

    SetParamRequest():
      name(""),
      value("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_SERIALIZE
      uint32_t length_name = strlen( (const char*) this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_value = strlen( (const char*) this->value);
      memcpy(outbuffer + offset, &length_value, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
#endif
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_DESERIALIZE
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_value;
      memcpy(&length_value, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
#endif
     return offset;
    }

    const char * getType(){ return SETPARAM; };
    const char * getMD5(){ return "bc6ccc4a57f61779c8eaae61e9f422e0"; };

  };

  class SetParamResponse : public ros::Msg
  {
    public:

    SetParamResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_SERIALIZE
#endif
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_DESERIALIZE
#endif
     return offset;
    }

    const char * getType(){ return SETPARAM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetParam {
    public:
    typedef SetParamRequest Request;
    typedef SetParamResponse Response;
  };

}
#endif
