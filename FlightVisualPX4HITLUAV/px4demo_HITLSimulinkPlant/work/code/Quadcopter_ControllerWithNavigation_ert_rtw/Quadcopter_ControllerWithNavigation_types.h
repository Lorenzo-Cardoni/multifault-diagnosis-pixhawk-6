//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Quadcopter_ControllerWithNavigation_types.h
//
// Code generated for Simulink model 'Quadcopter_ControllerWithNavigation'.
//
// Model version                  : 4.31
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Feb  5 16:24:46 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Quadcopter_ControllerWithNavigation_types_h_
#define RTW_HEADER_Quadcopter_ControllerWithNavigation_types_h_
#include "rtwtypes.h"
#include "MW_Parameter.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/actuator_armed.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/vehicle_trajectory_waypoint.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/position_setpoint.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/vehicle_gps_position.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/sensor_mag.h>
#ifndef struct_px4_internal_block_LLA2LocalCoordinatesNED_Quadcopter_Control_T
#define struct_px4_internal_block_LLA2LocalCoordinatesNED_Quadcopter_Control_T

struct px4_internal_block_LLA2LocalCoordinatesNED_Quadcopter_Control_T
{
  boolean_T matlabCodegenIsDeleted;
  boolean_T isSetupComplete;
};

#endif
      // struct_px4_internal_block_LLA2LocalCoordinatesNED_Quadcopter_Control_T

#ifndef struct_px4_internal_block_PWM_Quadcopter_ControllerWithNavigation_T
#define struct_px4_internal_block_PWM_Quadcopter_ControllerWithNavigation_T

struct px4_internal_block_PWM_Quadcopter_ControllerWithNavigation_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  int pwmDevHandler;
  const char * pwmDevObj;
  unsigned int servoCount;
  int channelMask;
  boolean_T isMain;
  uint16_T errorStatus;
  orb_advert_t armAdvertiseObj;
  orb_advert_t actuatorAdvertiseObj;
  boolean_T isArmed;
};

#endif   // struct_px4_internal_block_PWM_Quadcopter_ControllerWithNavigation_T

#ifndef struct_b_px4_internal_block_SampleTimeImpl_Quadcopter_ControllerWith_T
#define struct_b_px4_internal_block_SampleTimeImpl_Quadcopter_ControllerWith_T

struct b_px4_internal_block_SampleTimeImpl_Quadcopter_ControllerWith_T
{
  int32_T __dummy;
};

#endif
      // struct_b_px4_internal_block_SampleTimeImpl_Quadcopter_ControllerWith_T

#ifndef struct_px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T
#define struct_px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T

struct px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_px4_internal_block_SampleTimeImpl_Quadcopter_ControllerWith_T
    SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif
      // struct_px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T

#ifndef struct_px4_internal_block_LLA2LocalCoordinates_Quadcopter_Controller_T
#define struct_px4_internal_block_LLA2LocalCoordinates_Quadcopter_Controller_T

struct px4_internal_block_LLA2LocalCoordinates_Quadcopter_Controller_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T previousValidReceived;
  boolean_T nextValidReceived;
};

#endif
      // struct_px4_internal_block_LLA2LocalCoordinates_Quadcopter_Controller_T

// Custom Type definition for MATLABSystem: '<S48>/Read Parameter'
#include "MW_Parameter.h"
#ifndef struct_px4_internal_block_ParameterUpdate_Quadcopter_ControllerWithN_T
#define struct_px4_internal_block_ParameterUpdate_Quadcopter_ControllerWithN_T

struct px4_internal_block_ParameterUpdate_Quadcopter_ControllerWithN_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  MW_Param_Handle MW_PARAMHANDLE;
};

#endif
      // struct_px4_internal_block_ParameterUpdate_Quadcopter_ControllerWithN_T

#ifndef struct_px4_internal_block_getPX4AbsoluteTime_Quadcopter_ControllerWi_T
#define struct_px4_internal_block_getPX4AbsoluteTime_Quadcopter_ControllerWi_T

struct px4_internal_block_getPX4AbsoluteTime_Quadcopter_ControllerWi_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_px4_internal_block_SampleTimeImpl_Quadcopter_ControllerWith_T
    SampleTimeHandler;
};

#endif
      // struct_px4_internal_block_getPX4AbsoluteTime_Quadcopter_ControllerWi_T

#ifndef struct_px4_internal_block_Publisher_Quadcopter_ControllerWithNavigat_T
#define struct_px4_internal_block_Publisher_Quadcopter_ControllerWithNavigat_T

struct px4_internal_block_Publisher_Quadcopter_ControllerWithNavigat_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  orb_advert_t orbAdvertiseObj;
  orb_metadata_t * orbMetadataObj;
};

#endif
      // struct_px4_internal_block_Publisher_Quadcopter_ControllerWithNavigat_T

#ifndef struct_cell_wrap_Quadcopter_ControllerWithNavigation_T
#define struct_cell_wrap_Quadcopter_ControllerWithNavigation_T

struct cell_wrap_Quadcopter_ControllerWithNavigation_T
{
  uint32_T f1[8];
};

#endif                // struct_cell_wrap_Quadcopter_ControllerWithNavigation_T

#ifndef struct_uav_sluav_internal_system_WaypointFollower_Quadcopter_Control_T
#define struct_uav_sluav_internal_system_WaypointFollower_Quadcopter_Control_T

struct uav_sluav_internal_system_WaypointFollower_Quadcopter_Control_T
{
  int32_T isInitialized;
  cell_wrap_Quadcopter_ControllerWithNavigation_T inputVarSize[3];
  real_T LookaheadDistance;
  real_T WaypointIndex;
  real_T NumWaypoints;
  real_T WaypointsInternal[9];
  boolean_T LastWaypointFlag;
  boolean_T StartFlag;
  real_T InitialPose[4];
  real_T LookaheadFactor;
  uint8_T LookaheadDistFlag;
};

#endif
      // struct_uav_sluav_internal_system_WaypointFollower_Quadcopter_Control_T

// Parameters (default storage)
typedef struct P_Quadcopter_ControllerWithNavigation_T_
  P_Quadcopter_ControllerWithNavigation_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Quadcopter_ControllerWithNavigation_T
  RT_MODEL_Quadcopter_ControllerWithNavigation_T;

#endif               // RTW_HEADER_Quadcopter_ControllerWithNavigation_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
