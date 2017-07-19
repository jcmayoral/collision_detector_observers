#ifndef _ROS_cob_sound_PlayAction_h
#define _ROS_cob_sound_PlayAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_sound/PlayActionGoal.h"
#include "cob_sound/PlayActionResult.h"
#include "cob_sound/PlayActionFeedback.h"

namespace cob_sound
{

  class PlayAction : public ros::Msg
  {
    public:
      cob_sound::PlayActionGoal action_goal;
      cob_sound::PlayActionResult action_result;
      cob_sound::PlayActionFeedback action_feedback;

    PlayAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_sound/PlayAction"; };
    const char * getMD5(){ return "698163f0203728812f2f985294225b09"; };

  };

}
#endif