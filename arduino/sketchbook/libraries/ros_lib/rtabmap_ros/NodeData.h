#ifndef _ROS_rtabmap_ros_NodeData_h
#define _ROS_rtabmap_ros_NodeData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Transform.h"
#include "rtabmap_ros/Point3f.h"
#include "rtabmap_ros/KeyPoint.h"
#include "sensor_msgs/PointCloud2.h"

namespace rtabmap_ros
{

  class NodeData : public ros::Msg
  {
    public:
      int32_t id;
      int32_t mapId;
      int32_t weight;
      float stamp;
      const char* label;
      geometry_msgs::Pose pose;
      geometry_msgs::Pose groundTruthPose;
      uint8_t image_length;
      uint8_t st_image;
      uint8_t * image;
      uint8_t depth_length;
      uint8_t st_depth;
      uint8_t * depth;
      uint8_t fx_length;
      float st_fx;
      float * fx;
      uint8_t fy_length;
      float st_fy;
      float * fy;
      uint8_t cx_length;
      float st_cx;
      float * cx;
      uint8_t cy_length;
      float st_cy;
      float * cy;
      uint8_t width_length;
      float st_width;
      float * width;
      uint8_t height_length;
      float st_height;
      float * height;
      float baseline;
      uint8_t localTransform_length;
      geometry_msgs::Transform st_localTransform;
      geometry_msgs::Transform * localTransform;
      uint8_t laserScan_length;
      uint8_t st_laserScan;
      uint8_t * laserScan;
      int32_t laserScanMaxPts;
      float laserScanMaxRange;
      geometry_msgs::Transform laserScanLocalTransform;
      uint8_t userData_length;
      uint8_t st_userData;
      uint8_t * userData;
      uint8_t grid_ground_length;
      uint8_t st_grid_ground;
      uint8_t * grid_ground;
      uint8_t grid_obstacles_length;
      uint8_t st_grid_obstacles;
      uint8_t * grid_obstacles;
      float grid_cell_size;
      rtabmap_ros::Point3f grid_view_point;
      uint8_t wordIds_length;
      int32_t st_wordIds;
      int32_t * wordIds;
      uint8_t wordKpts_length;
      rtabmap_ros::KeyPoint st_wordKpts;
      rtabmap_ros::KeyPoint * wordKpts;
      sensor_msgs::PointCloud2 wordPts;
      uint8_t descriptors_length;
      uint8_t st_descriptors;
      uint8_t * descriptors;

    NodeData():
      id(0),
      mapId(0),
      weight(0),
      stamp(0),
      label(""),
      pose(),
      groundTruthPose(),
      image_length(0), image(NULL),
      depth_length(0), depth(NULL),
      fx_length(0), fx(NULL),
      fy_length(0), fy(NULL),
      cx_length(0), cx(NULL),
      cy_length(0), cy(NULL),
      width_length(0), width(NULL),
      height_length(0), height(NULL),
      baseline(0),
      localTransform_length(0), localTransform(NULL),
      laserScan_length(0), laserScan(NULL),
      laserScanMaxPts(0),
      laserScanMaxRange(0),
      laserScanLocalTransform(),
      userData_length(0), userData(NULL),
      grid_ground_length(0), grid_ground(NULL),
      grid_obstacles_length(0), grid_obstacles(NULL),
      grid_cell_size(0),
      grid_view_point(),
      wordIds_length(0), wordIds(NULL),
      wordKpts_length(0), wordKpts(NULL),
      wordPts(),
      descriptors_length(0), descriptors(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_mapId;
      u_mapId.real = this->mapId;
      *(outbuffer + offset + 0) = (u_mapId.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mapId.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mapId.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mapId.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mapId);
      union {
        int32_t real;
        uint32_t base;
      } u_weight;
      u_weight.real = this->weight;
      *(outbuffer + offset + 0) = (u_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_weight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->weight);
      offset += serializeAvrFloat64(outbuffer + offset, this->stamp);
      uint32_t length_label = strlen(this->label);
      memcpy(outbuffer + offset, &length_label, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->label, length_label);
      offset += length_label;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->groundTruthPose.serialize(outbuffer + offset);
      *(outbuffer + offset++) = image_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < image_length; i++){
      *(outbuffer + offset + 0) = (this->image[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->image[i]);
      }
      *(outbuffer + offset++) = depth_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < depth_length; i++){
      *(outbuffer + offset + 0) = (this->depth[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->depth[i]);
      }
      *(outbuffer + offset++) = fx_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fx_length; i++){
      union {
        float real;
        uint32_t base;
      } u_fxi;
      u_fxi.real = this->fx[i];
      *(outbuffer + offset + 0) = (u_fxi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fxi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fxi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fxi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fx[i]);
      }
      *(outbuffer + offset++) = fy_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fy_length; i++){
      union {
        float real;
        uint32_t base;
      } u_fyi;
      u_fyi.real = this->fy[i];
      *(outbuffer + offset + 0) = (u_fyi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fyi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fyi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fyi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fy[i]);
      }
      *(outbuffer + offset++) = cx_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < cx_length; i++){
      union {
        float real;
        uint32_t base;
      } u_cxi;
      u_cxi.real = this->cx[i];
      *(outbuffer + offset + 0) = (u_cxi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cxi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cxi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cxi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cx[i]);
      }
      *(outbuffer + offset++) = cy_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < cy_length; i++){
      union {
        float real;
        uint32_t base;
      } u_cyi;
      u_cyi.real = this->cy[i];
      *(outbuffer + offset + 0) = (u_cyi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cyi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cyi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cyi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cy[i]);
      }
      *(outbuffer + offset++) = width_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < width_length; i++){
      union {
        float real;
        uint32_t base;
      } u_widthi;
      u_widthi.real = this->width[i];
      *(outbuffer + offset + 0) = (u_widthi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_widthi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_widthi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_widthi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width[i]);
      }
      *(outbuffer + offset++) = height_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < height_length; i++){
      union {
        float real;
        uint32_t base;
      } u_heighti;
      u_heighti.real = this->height[i];
      *(outbuffer + offset + 0) = (u_heighti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heighti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heighti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heighti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_baseline;
      u_baseline.real = this->baseline;
      *(outbuffer + offset + 0) = (u_baseline.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_baseline.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_baseline.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_baseline.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->baseline);
      *(outbuffer + offset++) = localTransform_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < localTransform_length; i++){
      offset += this->localTransform[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = laserScan_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < laserScan_length; i++){
      *(outbuffer + offset + 0) = (this->laserScan[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->laserScan[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_laserScanMaxPts;
      u_laserScanMaxPts.real = this->laserScanMaxPts;
      *(outbuffer + offset + 0) = (u_laserScanMaxPts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_laserScanMaxPts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_laserScanMaxPts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_laserScanMaxPts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->laserScanMaxPts);
      union {
        float real;
        uint32_t base;
      } u_laserScanMaxRange;
      u_laserScanMaxRange.real = this->laserScanMaxRange;
      *(outbuffer + offset + 0) = (u_laserScanMaxRange.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_laserScanMaxRange.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_laserScanMaxRange.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_laserScanMaxRange.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->laserScanMaxRange);
      offset += this->laserScanLocalTransform.serialize(outbuffer + offset);
      *(outbuffer + offset++) = userData_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < userData_length; i++){
      *(outbuffer + offset + 0) = (this->userData[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->userData[i]);
      }
      *(outbuffer + offset++) = grid_ground_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < grid_ground_length; i++){
      *(outbuffer + offset + 0) = (this->grid_ground[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->grid_ground[i]);
      }
      *(outbuffer + offset++) = grid_obstacles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < grid_obstacles_length; i++){
      *(outbuffer + offset + 0) = (this->grid_obstacles[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->grid_obstacles[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_grid_cell_size;
      u_grid_cell_size.real = this->grid_cell_size;
      *(outbuffer + offset + 0) = (u_grid_cell_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_grid_cell_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_grid_cell_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_grid_cell_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grid_cell_size);
      offset += this->grid_view_point.serialize(outbuffer + offset);
      *(outbuffer + offset++) = wordIds_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < wordIds_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_wordIdsi;
      u_wordIdsi.real = this->wordIds[i];
      *(outbuffer + offset + 0) = (u_wordIdsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wordIdsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wordIdsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wordIdsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wordIds[i]);
      }
      *(outbuffer + offset++) = wordKpts_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < wordKpts_length; i++){
      offset += this->wordKpts[i].serialize(outbuffer + offset);
      }
      offset += this->wordPts.serialize(outbuffer + offset);
      *(outbuffer + offset++) = descriptors_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < descriptors_length; i++){
      *(outbuffer + offset + 0) = (this->descriptors[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->descriptors[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_mapId;
      u_mapId.base = 0;
      u_mapId.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mapId.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mapId.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mapId.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mapId = u_mapId.real;
      offset += sizeof(this->mapId);
      union {
        int32_t real;
        uint32_t base;
      } u_weight;
      u_weight.base = 0;
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_weight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->weight = u_weight.real;
      offset += sizeof(this->weight);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->stamp));
      uint32_t length_label;
      memcpy(&length_label, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_label-1]=0;
      this->label = (char *)(inbuffer + offset-1);
      offset += length_label;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->groundTruthPose.deserialize(inbuffer + offset);
      uint8_t image_lengthT = *(inbuffer + offset++);
      if(image_lengthT > image_length)
        this->image = (uint8_t*)realloc(this->image, image_lengthT * sizeof(uint8_t));
      offset += 3;
      image_length = image_lengthT;
      for( uint8_t i = 0; i < image_length; i++){
      this->st_image =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_image);
        memcpy( &(this->image[i]), &(this->st_image), sizeof(uint8_t));
      }
      uint8_t depth_lengthT = *(inbuffer + offset++);
      if(depth_lengthT > depth_length)
        this->depth = (uint8_t*)realloc(this->depth, depth_lengthT * sizeof(uint8_t));
      offset += 3;
      depth_length = depth_lengthT;
      for( uint8_t i = 0; i < depth_length; i++){
      this->st_depth =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_depth);
        memcpy( &(this->depth[i]), &(this->st_depth), sizeof(uint8_t));
      }
      uint8_t fx_lengthT = *(inbuffer + offset++);
      if(fx_lengthT > fx_length)
        this->fx = (float*)realloc(this->fx, fx_lengthT * sizeof(float));
      offset += 3;
      fx_length = fx_lengthT;
      for( uint8_t i = 0; i < fx_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_fx;
      u_st_fx.base = 0;
      u_st_fx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_fx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_fx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_fx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_fx = u_st_fx.real;
      offset += sizeof(this->st_fx);
        memcpy( &(this->fx[i]), &(this->st_fx), sizeof(float));
      }
      uint8_t fy_lengthT = *(inbuffer + offset++);
      if(fy_lengthT > fy_length)
        this->fy = (float*)realloc(this->fy, fy_lengthT * sizeof(float));
      offset += 3;
      fy_length = fy_lengthT;
      for( uint8_t i = 0; i < fy_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_fy;
      u_st_fy.base = 0;
      u_st_fy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_fy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_fy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_fy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_fy = u_st_fy.real;
      offset += sizeof(this->st_fy);
        memcpy( &(this->fy[i]), &(this->st_fy), sizeof(float));
      }
      uint8_t cx_lengthT = *(inbuffer + offset++);
      if(cx_lengthT > cx_length)
        this->cx = (float*)realloc(this->cx, cx_lengthT * sizeof(float));
      offset += 3;
      cx_length = cx_lengthT;
      for( uint8_t i = 0; i < cx_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_cx;
      u_st_cx.base = 0;
      u_st_cx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_cx = u_st_cx.real;
      offset += sizeof(this->st_cx);
        memcpy( &(this->cx[i]), &(this->st_cx), sizeof(float));
      }
      uint8_t cy_lengthT = *(inbuffer + offset++);
      if(cy_lengthT > cy_length)
        this->cy = (float*)realloc(this->cy, cy_lengthT * sizeof(float));
      offset += 3;
      cy_length = cy_lengthT;
      for( uint8_t i = 0; i < cy_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_cy;
      u_st_cy.base = 0;
      u_st_cy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_cy = u_st_cy.real;
      offset += sizeof(this->st_cy);
        memcpy( &(this->cy[i]), &(this->st_cy), sizeof(float));
      }
      uint8_t width_lengthT = *(inbuffer + offset++);
      if(width_lengthT > width_length)
        this->width = (float*)realloc(this->width, width_lengthT * sizeof(float));
      offset += 3;
      width_length = width_lengthT;
      for( uint8_t i = 0; i < width_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_width;
      u_st_width.base = 0;
      u_st_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_width = u_st_width.real;
      offset += sizeof(this->st_width);
        memcpy( &(this->width[i]), &(this->st_width), sizeof(float));
      }
      uint8_t height_lengthT = *(inbuffer + offset++);
      if(height_lengthT > height_length)
        this->height = (float*)realloc(this->height, height_lengthT * sizeof(float));
      offset += 3;
      height_length = height_lengthT;
      for( uint8_t i = 0; i < height_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_height;
      u_st_height.base = 0;
      u_st_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_height = u_st_height.real;
      offset += sizeof(this->st_height);
        memcpy( &(this->height[i]), &(this->st_height), sizeof(float));
      }
      union {
        float real;
        uint32_t base;
      } u_baseline;
      u_baseline.base = 0;
      u_baseline.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_baseline.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_baseline.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_baseline.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->baseline = u_baseline.real;
      offset += sizeof(this->baseline);
      uint8_t localTransform_lengthT = *(inbuffer + offset++);
      if(localTransform_lengthT > localTransform_length)
        this->localTransform = (geometry_msgs::Transform*)realloc(this->localTransform, localTransform_lengthT * sizeof(geometry_msgs::Transform));
      offset += 3;
      localTransform_length = localTransform_lengthT;
      for( uint8_t i = 0; i < localTransform_length; i++){
      offset += this->st_localTransform.deserialize(inbuffer + offset);
        memcpy( &(this->localTransform[i]), &(this->st_localTransform), sizeof(geometry_msgs::Transform));
      }
      uint8_t laserScan_lengthT = *(inbuffer + offset++);
      if(laserScan_lengthT > laserScan_length)
        this->laserScan = (uint8_t*)realloc(this->laserScan, laserScan_lengthT * sizeof(uint8_t));
      offset += 3;
      laserScan_length = laserScan_lengthT;
      for( uint8_t i = 0; i < laserScan_length; i++){
      this->st_laserScan =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_laserScan);
        memcpy( &(this->laserScan[i]), &(this->st_laserScan), sizeof(uint8_t));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_laserScanMaxPts;
      u_laserScanMaxPts.base = 0;
      u_laserScanMaxPts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_laserScanMaxPts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_laserScanMaxPts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_laserScanMaxPts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->laserScanMaxPts = u_laserScanMaxPts.real;
      offset += sizeof(this->laserScanMaxPts);
      union {
        float real;
        uint32_t base;
      } u_laserScanMaxRange;
      u_laserScanMaxRange.base = 0;
      u_laserScanMaxRange.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_laserScanMaxRange.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_laserScanMaxRange.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_laserScanMaxRange.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->laserScanMaxRange = u_laserScanMaxRange.real;
      offset += sizeof(this->laserScanMaxRange);
      offset += this->laserScanLocalTransform.deserialize(inbuffer + offset);
      uint8_t userData_lengthT = *(inbuffer + offset++);
      if(userData_lengthT > userData_length)
        this->userData = (uint8_t*)realloc(this->userData, userData_lengthT * sizeof(uint8_t));
      offset += 3;
      userData_length = userData_lengthT;
      for( uint8_t i = 0; i < userData_length; i++){
      this->st_userData =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_userData);
        memcpy( &(this->userData[i]), &(this->st_userData), sizeof(uint8_t));
      }
      uint8_t grid_ground_lengthT = *(inbuffer + offset++);
      if(grid_ground_lengthT > grid_ground_length)
        this->grid_ground = (uint8_t*)realloc(this->grid_ground, grid_ground_lengthT * sizeof(uint8_t));
      offset += 3;
      grid_ground_length = grid_ground_lengthT;
      for( uint8_t i = 0; i < grid_ground_length; i++){
      this->st_grid_ground =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_grid_ground);
        memcpy( &(this->grid_ground[i]), &(this->st_grid_ground), sizeof(uint8_t));
      }
      uint8_t grid_obstacles_lengthT = *(inbuffer + offset++);
      if(grid_obstacles_lengthT > grid_obstacles_length)
        this->grid_obstacles = (uint8_t*)realloc(this->grid_obstacles, grid_obstacles_lengthT * sizeof(uint8_t));
      offset += 3;
      grid_obstacles_length = grid_obstacles_lengthT;
      for( uint8_t i = 0; i < grid_obstacles_length; i++){
      this->st_grid_obstacles =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_grid_obstacles);
        memcpy( &(this->grid_obstacles[i]), &(this->st_grid_obstacles), sizeof(uint8_t));
      }
      union {
        float real;
        uint32_t base;
      } u_grid_cell_size;
      u_grid_cell_size.base = 0;
      u_grid_cell_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_grid_cell_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_grid_cell_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_grid_cell_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->grid_cell_size = u_grid_cell_size.real;
      offset += sizeof(this->grid_cell_size);
      offset += this->grid_view_point.deserialize(inbuffer + offset);
      uint8_t wordIds_lengthT = *(inbuffer + offset++);
      if(wordIds_lengthT > wordIds_length)
        this->wordIds = (int32_t*)realloc(this->wordIds, wordIds_lengthT * sizeof(int32_t));
      offset += 3;
      wordIds_length = wordIds_lengthT;
      for( uint8_t i = 0; i < wordIds_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_wordIds;
      u_st_wordIds.base = 0;
      u_st_wordIds.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_wordIds.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_wordIds.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_wordIds.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_wordIds = u_st_wordIds.real;
      offset += sizeof(this->st_wordIds);
        memcpy( &(this->wordIds[i]), &(this->st_wordIds), sizeof(int32_t));
      }
      uint8_t wordKpts_lengthT = *(inbuffer + offset++);
      if(wordKpts_lengthT > wordKpts_length)
        this->wordKpts = (rtabmap_ros::KeyPoint*)realloc(this->wordKpts, wordKpts_lengthT * sizeof(rtabmap_ros::KeyPoint));
      offset += 3;
      wordKpts_length = wordKpts_lengthT;
      for( uint8_t i = 0; i < wordKpts_length; i++){
      offset += this->st_wordKpts.deserialize(inbuffer + offset);
        memcpy( &(this->wordKpts[i]), &(this->st_wordKpts), sizeof(rtabmap_ros::KeyPoint));
      }
      offset += this->wordPts.deserialize(inbuffer + offset);
      uint8_t descriptors_lengthT = *(inbuffer + offset++);
      if(descriptors_lengthT > descriptors_length)
        this->descriptors = (uint8_t*)realloc(this->descriptors, descriptors_lengthT * sizeof(uint8_t));
      offset += 3;
      descriptors_length = descriptors_lengthT;
      for( uint8_t i = 0; i < descriptors_length; i++){
      this->st_descriptors =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_descriptors);
        memcpy( &(this->descriptors[i]), &(this->st_descriptors), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "rtabmap_ros/NodeData"; };
    const char * getMD5(){ return "934677666129185759cc518495d0b6cb"; };

  };

}
#endif