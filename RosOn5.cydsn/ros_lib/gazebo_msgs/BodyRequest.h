#ifndef _ROS_SERVICE_BodyRequest_h
#define _ROS_SERVICE_BodyRequest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace gazebo_msgs
{

static const char BODYREQUEST[] = "gazebo_msgs/BodyRequest";

  class BodyRequestRequest : public ros::Msg
  {
    public:
      const char* body_name;

    BodyRequestRequest():
      body_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_SERIALIZE
      uint32_t length_body_name = strlen( (const char*) this->body_name);
      memcpy(outbuffer + offset, &length_body_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->body_name, length_body_name);
      offset += length_body_name;
#endif
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_DESERIALIZE
      uint32_t length_body_name;
      memcpy(&length_body_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_body_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_body_name-1]=0;
      this->body_name = (char *)(inbuffer + offset-1);
      offset += length_body_name;
#endif
     return offset;
    }

    const char * getType(){ return BODYREQUEST; };
    const char * getMD5(){ return "5eade9afe7f232d78005bd0cafeab755"; };

  };

  class BodyRequestResponse : public ros::Msg
  {
    public:

    BodyRequestResponse()
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

    const char * getType(){ return BODYREQUEST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class BodyRequest {
    public:
    typedef BodyRequestRequest Request;
    typedef BodyRequestResponse Response;
  };

}
#endif
