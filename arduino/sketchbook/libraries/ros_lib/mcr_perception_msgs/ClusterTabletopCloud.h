#ifndef _ROS_SERVICE_ClusterTabletopCloud_h
#define _ROS_SERVICE_ClusterTabletopCloud_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"
#include "mcr_perception_msgs/PlanarPolygon.h"

namespace mcr_perception_msgs
{

static const char CLUSTERTABLETOPCLOUD[] = "mcr_perception_msgs/ClusterTabletopCloud";

  class ClusterTabletopCloudRequest : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 cloud;
      mcr_perception_msgs::PlanarPolygon polygon;

    ClusterTabletopCloudRequest():
      cloud(),
      polygon()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->cloud.serialize(outbuffer + offset);
      offset += this->polygon.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->cloud.deserialize(inbuffer + offset);
      offset += this->polygon.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CLUSTERTABLETOPCLOUD; };
    const char * getMD5(){ return "7f429fc8a10b4ddbcb636be503dce54c"; };

  };

  class ClusterTabletopCloudResponse : public ros::Msg
  {
    public:
      uint8_t clusters_length;
      sensor_msgs::PointCloud2 st_clusters;
      sensor_msgs::PointCloud2 * clusters;

    ClusterTabletopCloudResponse():
      clusters_length(0), clusters(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = clusters_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < clusters_length; i++){
      offset += this->clusters[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t clusters_lengthT = *(inbuffer + offset++);
      if(clusters_lengthT > clusters_length)
        this->clusters = (sensor_msgs::PointCloud2*)realloc(this->clusters, clusters_lengthT * sizeof(sensor_msgs::PointCloud2));
      offset += 3;
      clusters_length = clusters_lengthT;
      for( uint8_t i = 0; i < clusters_length; i++){
      offset += this->st_clusters.deserialize(inbuffer + offset);
        memcpy( &(this->clusters[i]), &(this->st_clusters), sizeof(sensor_msgs::PointCloud2));
      }
     return offset;
    }

    const char * getType(){ return CLUSTERTABLETOPCLOUD; };
    const char * getMD5(){ return "f94e5e56fc7ff419809a40b3ff371b4c"; };

  };

  class ClusterTabletopCloud {
    public:
    typedef ClusterTabletopCloudRequest Request;
    typedef ClusterTabletopCloudResponse Response;
  };

}
#endif
