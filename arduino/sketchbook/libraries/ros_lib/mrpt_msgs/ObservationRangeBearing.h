#ifndef _ROS_mrpt_msgs_ObservationRangeBearing_h
#define _ROS_mrpt_msgs_ObservationRangeBearing_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "mrpt_msgs/SingleRangeBearingObservation.h"

namespace mrpt_msgs
{

  class ObservationRangeBearing : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Pose sensor_pose_on_robot;
      float min_sensor_distance;
      float max_sensor_distance;
      float sensor_std_range;
      float sensor_std_yaw;
      float sensor_std_pitch;
      uint8_t sensed_data_length;
      mrpt_msgs::SingleRangeBearingObservation st_sensed_data;
      mrpt_msgs::SingleRangeBearingObservation * sensed_data;

    ObservationRangeBearing():
      header(),
      sensor_pose_on_robot(),
      min_sensor_distance(0),
      max_sensor_distance(0),
      sensor_std_range(0),
      sensor_std_yaw(0),
      sensor_std_pitch(0),
      sensed_data_length(0), sensed_data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->sensor_pose_on_robot.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_sensor_distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_sensor_distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->sensor_std_range);
      offset += serializeAvrFloat64(outbuffer + offset, this->sensor_std_yaw);
      offset += serializeAvrFloat64(outbuffer + offset, this->sensor_std_pitch);
      *(outbuffer + offset++) = sensed_data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sensed_data_length; i++){
      offset += this->sensed_data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->sensor_pose_on_robot.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_sensor_distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_sensor_distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sensor_std_range));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sensor_std_yaw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sensor_std_pitch));
      uint8_t sensed_data_lengthT = *(inbuffer + offset++);
      if(sensed_data_lengthT > sensed_data_length)
        this->sensed_data = (mrpt_msgs::SingleRangeBearingObservation*)realloc(this->sensed_data, sensed_data_lengthT * sizeof(mrpt_msgs::SingleRangeBearingObservation));
      offset += 3;
      sensed_data_length = sensed_data_lengthT;
      for( uint8_t i = 0; i < sensed_data_length; i++){
      offset += this->st_sensed_data.deserialize(inbuffer + offset);
        memcpy( &(this->sensed_data[i]), &(this->st_sensed_data), sizeof(mrpt_msgs::SingleRangeBearingObservation));
      }
     return offset;
    }

    const char * getType(){ return "mrpt_msgs/ObservationRangeBearing"; };
    const char * getMD5(){ return "e1be50a05d6a766b374c80620f485049"; };

  };

}
#endif