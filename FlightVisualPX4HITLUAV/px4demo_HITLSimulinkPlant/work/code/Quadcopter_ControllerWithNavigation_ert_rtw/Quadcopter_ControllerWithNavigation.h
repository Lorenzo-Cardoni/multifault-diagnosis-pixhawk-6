//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Quadcopter_ControllerWithNavigation.h
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
#ifndef RTW_HEADER_Quadcopter_ControllerWithNavigation_h_
#define RTW_HEADER_Quadcopter_ControllerWithNavigation_h_
#include <poll.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "MW_uORB_Write.h"
#include "Quadcopter_ControllerWithNavigation_types.h"
#include <uORB/topics/vehicle_trajectory_waypoint.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/position_setpoint_triplet.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_gps_position.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/sensor_mag.h>
#include <uORB/topics/actuator_armed.h>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

// Block signals for system '<S40>/MATLAB System'
struct B_MATLABSystem_Quadcopter_ControllerWithNavigation_T {
  real32_T MATLABSystem[3];            // '<S40>/MATLAB System'
  real_T dLat;
};

// Block states (default storage) for system '<S40>/MATLAB System'
struct DW_MATLABSystem_Quadcopter_ControllerWithNavigation_T {
  px4_internal_block_LLA2LocalCoordinatesNED_Quadcopter_Control_T obj;// '<S40>/MATLAB System' 
  boolean_T objisempty;                // '<S40>/MATLAB System'
};

// Block states (default storage) for system '<S55>/MATLAB Function2'
struct DW_MATLABFunction2_Quadcopter_ControllerWithNavigation_T {
  int32_T sfEvent;                     // '<S55>/MATLAB Function2'
  uint8_T is_active_c4_Quadcopter_ControllerWithNavigation;// '<S55>/MATLAB Function2' 
  boolean_T doneDoubleBufferReInit;    // '<S55>/MATLAB Function2'
};

// Block states (default storage) for system '<S56>/MATLAB Function'
struct DW_MATLABFunction_Quadcopter_ControllerWithNavigation_T {
  int32_T sfEvent;                     // '<S56>/MATLAB Function'
  uint8_T is_active_c1_Quadcopter_ControllerWithNavigation;// '<S56>/MATLAB Function' 
  boolean_T doneDoubleBufferReInit;    // '<S56>/MATLAB Function'
};

// Block states (default storage) for system '<S58>/MATLAB Function'
struct DW_MATLABFunction_Quadcopter_ControllerWithNavigation_g_T {
  int32_T sfEvent;                     // '<S58>/MATLAB Function'
  uint8_T is_active_c7_Quadcopter_ControllerWithNavigation;// '<S58>/MATLAB Function' 
  boolean_T doneDoubleBufferReInit;    // '<S58>/MATLAB Function'
};

// Block signals (default storage)
struct B_Quadcopter_ControllerWithNavigation_T {
  creal_T fy[256];
  creal_T fv[256];
  creal_T yCol[130];
  creal_T ytmp[65];
  real_T varargin_1[130];
  real_T c_y[130];
  real_T orderedBuffer_a[130];
  real_T orderedBuffer_c[130];
  real_T orderedBuffer_am[130];
  real_T orderedBuffer[130];
  real_T orderedBuffer_e[130];
  real_T hcostab[128];
  real_T hsintab[128];
  real_T hcostabinv[128];
  real_T hsintabinv[128];
  real_T dv[99];
  real_T b_x[99];
  px4_Bus_vehicle_trajectory_waypoint In1;// '<S39>/In1'
  px4_Bus_vehicle_trajectory_waypoint b_varargout_2;
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1;// '<S34>/Bus Assignment1'
  px4_Bus_vehicle_trajectory_waypoint BusAssignment1_m;// '<S34>/Bus Assignment1' 
  px4_Bus_vehicle_odometry In1_l;      // '<S10>/In1'
  px4_Bus_vehicle_odometry b_varargout_2_c;
  px4_Bus_position_setpoint_triplet In1_p;// '<S51>/In1'
  px4_Bus_position_setpoint_triplet b_varargout_2_k;
  px4_Bus_vehicle_local_position In1_c;// '<S13>/In1'
  px4_Bus_vehicle_local_position b_varargout_2_cx;
  px4_Bus_vehicle_gps_position In1_n;  // '<S383>/In1'
  px4_Bus_vehicle_gps_position b_varargout_2_b;
  real_T b_waypointsIn_data[9];
  real_T MatrixConcatenate_p[9];       // '<S21>/Matrix Concatenate'
  px4_Bus_vehicle_attitude In1_m;      // '<S12>/In1'
  px4_Bus_vehicle_attitude b_varargout_2_p;
  px4_Bus_trajectory_waypoint BusAssignment1_f;// '<S42>/Bus Assignment1'
  px4_Bus_home_position b_varargout_2_cv;
  px4_Bus_sensor_accel In1_a;          // '<S70>/In1'
  px4_Bus_home_position In1_f;         // '<S50>/In1'
  real_T DataTypeConversion1[7];       // '<S2>/Data Type Conversion1'
  px4_Bus_sensor_accel b_varargout_2_f;
  px4_Bus_sensor_gyro b_varargout_2_g;
  px4_Bus_sensor_mag In1_j;            // '<S387>/In1'
  px4_Bus_sensor_gyro In1_m2;          // '<S385>/In1'
  px4_Bus_sensor_mag b_varargout_2_g1;
  real_T Merge[4];                     // '<S16>/Merge'
  real_T b_varargout_3[3];
  real_T lla0[3];
  real_T MatrixConcatenate1[3];        // '<S40>/Matrix Concatenate1'
  real_T MatrixConcatenate1_k[3];      // '<S34>/Matrix Concatenate1'
  real_T rtb_Reshape1_m[3];
  uint16_T pwmValue[8];
  px4_Bus_actuator_armed In1_b;        // '<S11>/In1'
  px4_Bus_actuator_armed b_varargout_2_n;
  real_T desiredZ;                     // '<S52>/Gain'
  real_T VectorConcatenate[3];         // '<S592>/Vector Concatenate'
  real_T DataTypeConversion2[3];       // '<S2>/Data Type Conversion2'
  real_T TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport[18];
  // '<S52>/TmpSignal ConversionAt_asyncqueue_inserted_for_To WorkspaceInport1'
  real_T Saturation;                   // '<S581>/Saturation'
  real_T Saturation_n[2];              // '<S433>/Saturation'
  real_T Gain1;                        // '<S66>/Gain1'
  real_T label;                        // '<S52>/MATLAB Function3'
  real_T filteredLabel;                // '<S52>/MATLAB Function'
  real_T Saturation_h;                 // '<S118>/Saturation'
  real_T Saturation_c;                 // '<S168>/Saturation'
  real_T Saturation_d;                 // '<S218>/Saturation'
  real_T yaw_In;                       // '<S23>/yaw_In'
  real_T yaw_In_i;                     // '<S27>/yaw_In'
  real_T In;                           // '<S26>/In'
  real_T yaw_In_ik;                    // '<S30>/yaw_In'
  real32_T TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspace3Inpor[3];
  // '<S52>/TmpSignal ConversionAt_asyncqueue_inserted_for_To Workspace3Inport1' 
  real_T r;
  real_T q;
  real_T bufferStd;
  real_T j_y;
  real_T v_y;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T orderedBuffer_e_p;
  real_T varargin_1_tmp;
  real_T featuresVector_idx_7;
  real_T featuresVector_idx_23;
  real_T temp_re;
  real_T temp_im;
  real_T twid_re;
  real_T twid_im;
  real_T d4;
  real_T d5;
  real_T ytmp_re_tmp;
  real_T ytmp_im_tmp;
  real_T lambda;
  real_T b;
  real_T y_l;
  real_T Gain_i;                       // '<S28>/Gain'
  real_T Filter;                       // '<S106>/Filter'
  real_T FilterCoefficient_k;          // '<S577>/Filter Coefficient'
  real_T Filter_o;                     // '<S206>/Filter'
  real_T VectorConcatenate_tmp;
  real_T VectorConcatenate_tmp_j;
  real_T dLat;
  real_T dLon;
  real_T Rn;
  real_T flat;
  real_T b_x_d;
  real_T absx;
  real_T absx_g;
  real_T q_l;
  real_T scale;
  real_T absxk;
  real_T t;
  uint16_T Saturation_dh[4];           // '<S5>/Saturation'
  boolean_T x_d[6];
  real32_T x;
  real32_T y;
  real32_T z;
  real32_T ParamStep;
  int32_T k;
  int32_T iindx;
  int32_T ParamStep_l;
  int32_T i2;
  int32_T i1;
  int32_T j;
  int32_T ix;
  int32_T b_exponent;
  int32_T b_exponent_o;
  int32_T waypoints_size_idx_0;
  int32_T b_k;
  int32_T i;
  int32_T i1_b;
  int8_T tmp_data[3];
  boolean_T distinctWptsIdx[3];
  boolean_T b_n[3];
  uint16_T status;
  boolean_T IsNaN_l[2];                // '<S19>/IsNaN'
  int8_T rtPrevAction;
  int8_T i2_b;
  boolean_T latp2;
  boolean_T p;
  boolean_T latp2_l;
  B_MATLABSystem_Quadcopter_ControllerWithNavigation_T MATLABSystem_b;// '<S40>/MATLAB System' 
  B_MATLABSystem_Quadcopter_ControllerWithNavigation_T MATLABSystem;// '<S40>/MATLAB System' 
};

// Block states (default storage) for system '<Root>'
struct DW_Quadcopter_ControllerWithNavigation_T {
  uav_sluav_internal_system_WaypointFollower_Quadcopter_Control_T obj;// '<S21>/UAV Waypoint Follower' 
  px4_internal_block_ParameterUpdate_Quadcopter_ControllerWithN_T obj_b;// '<S48>/Read Parameter' 
  px4_internal_block_ParameterUpdate_Quadcopter_ControllerWithN_T obj_g;// '<S49>/Read Parameter' 
  px4_internal_block_ParameterUpdate_Quadcopter_ControllerWithN_T obj_k;// '<S17>/Read Parameter' 
  px4_internal_block_PWM_Quadcopter_ControllerWithNavigation_T obj_p;// '<S5>/PX4 PWM Output' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_h;// '<S386>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_c;// '<S384>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_n;// '<S382>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_f;// '<S69>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_kz;// '<S36>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_gf;// '<S35>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_e;// '<S38>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_m;// '<S9>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_gv;// '<S8>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_d;// '<S7>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_po;// '<S6>/SourceBlock' 
  px4_internal_block_getPX4AbsoluteTime_Quadcopter_ControllerWi_T obj_np;// '<S33>/PX4 Timestamp' 
  px4_internal_block_LLA2LocalCoordinates_Quadcopter_Controller_T obj_mr;// '<S17>/LLA2LocalCoordinates' 
  px4_internal_block_Publisher_Quadcopter_ControllerWithNavigat_T obj_mc;// '<S45>/SinkBlock' 
  real_T Delay1_DSTATE[130];           // '<S55>/Delay1'
  real_T Delay_DSTATE;                 // '<S55>/Delay'
  real_T Delay1_DSTATE_k[130];         // '<S56>/Delay1'
  real_T Delay_DSTATE_e;               // '<S56>/Delay'
  real_T Delay1_DSTATE_f[130];         // '<S57>/Delay1'
  real_T Delay_DSTATE_h;               // '<S57>/Delay'
  real_T Delay1_DSTATE_e[130];         // '<S58>/Delay1'
  real_T Delay_DSTATE_hd;              // '<S58>/Delay'
  real_T Delay1_DSTATE_j[130];         // '<S59>/Delay1'
  real_T Delay_DSTATE_p;               // '<S59>/Delay'
  real_T Filter_DSTATE;                // '<S519>/Filter'
  real_T Integrator_DSTATE;            // '<S524>/Integrator'
  real_T Filter_DSTATE_m;              // '<S569>/Filter'
  real_T Integrator_DSTATE_c;          // '<S574>/Integrator'
  real_T Integrator_DSTATE_h;          // '<S111>/Integrator'
  real_T Filter_DSTATE_f;              // '<S106>/Filter'
  real_T Integrator_DSTATE_o;          // '<S161>/Integrator'
  real_T Filter_DSTATE_n;              // '<S156>/Filter'
  real_T Integrator_DSTATE_i;          // '<S211>/Integrator'
  real_T Filter_DSTATE_k;              // '<S206>/Filter'
  real_T Delay_DSTATE_i;               // '<S22>/Delay'
  real_T Delay_DSTATE_l[2];            // '<S19>/Delay'
  real_T Delay_DSTATE_n;               // '<S24>/Delay'
  real_T Delay_DSTATE_b;               // '<S25>/Delay'
  real_T Delay_DSTATE_c;               // '<S28>/Delay'
  real_T Delay_DSTATE_d;               // '<S29>/Delay'
  real_T labelBuffer[333];             // '<S52>/MATLAB Function'
  real_T bufferIndex;                  // '<S52>/MATLAB Function'
  real_T labelCounts[5];               // '<S52>/MATLAB Function'
  real_T PrevY;                        // '<S54>/Rate Limiter2'
  real_T PrevY_b;                      // '<S54>/Rate Limiter1'
  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<S52>/Scope'

  px4_internal_block_LLA2LocalCoordinatesNED_Quadcopter_Control_T obj_mu;// '<S43>/MATLAB System' 
  int8_T If_ActiveSubsystem;           // '<S16>/If'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S594>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S594>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S594>/If Action Subsystem'
  int8_T PositionAltitudecontroller_SubsysRanBC;
                                      // '<S52>/Position & Altitude controller'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S386>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_m;// '<S384>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_e;// '<S382>/Enabled Subsystem'
  int8_T Attitudecontroller_SubsysRanBC;// '<S52>/Attitude controller'
  int8_T EnabledSubsystem_SubsysRanBC_j;// '<S69>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_n;// '<S36>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_l;// '<S35>/Enabled Subsystem'
  int8_T SendwaypointstoOBC_SubsysRanBC;// '<S17>/Send waypoints to OBC'
  int8_T IfActionSubsystem_SubsysRanBC_g;// '<S46>/If Action Subsystem'
  int8_T IfActionSubsystem1_SubsysRanBC_m;// '<S46>/If Action Subsystem1'
  int8_T IfActionSubsystem2_SubsysRanBC_k;// '<S46>/If Action Subsystem2'
  int8_T EnabledSubsystem_SubsysRanBC_h;// '<S38>/Enabled Subsystem'
  int8_T IDLE_SubsysRanBC;             // '<S16>/IDLE'
  int8_T EnabledSubsystem2_SubsysRanBC;// '<S22>/Enabled Subsystem2'
  int8_T Waypoint_SubsysRanBC;         // '<S16>/Waypoint'
  int8_T Land_SubsysRanBC;             // '<S16>/Land'
  int8_T EnabledSubsystem2_SubsysRanBC_d;// '<S25>/Enabled Subsystem2'
  int8_T EnabledSubsystem_SubsysRanBC_d;// '<S24>/Enabled Subsystem'
  int8_T Takeoff_SubsysRanBC;          // '<S16>/Take-off'
  int8_T EnabledSubsystem2_SubsysRanBC_b;// '<S29>/Enabled Subsystem2'
  int8_T EnabledSubsystem_SubsysRanBC_eq;// '<S9>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_d3;// '<S8>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_f;// '<S7>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_a;// '<S6>/Enabled Subsystem'
  uint8_T is_active_c8_Quadcopter_ControllerWithNavigation;// '<S52>/MATLAB Function3' 
  uint8_T is_active_c9_Quadcopter_ControllerWithNavigation;// '<S52>/MATLAB Function1' 
  uint8_T is_active_c20_Quadcopter_ControllerWithNavigation;// '<S52>/MATLAB Function' 
  uint8_T is_active_c3_Quadcopter_ControllerWithNavigation;// '<S55>/MATLAB Function' 
  DW_MATLABFunction2_Quadcopter_ControllerWithNavigation_T sf_MATLABFunction2_a;// '<S59>/MATLAB Function2' 
  DW_MATLABFunction_Quadcopter_ControllerWithNavigation_g_T sf_MATLABFunction_o2;// '<S59>/MATLAB Function' 
  DW_MATLABFunction2_Quadcopter_ControllerWithNavigation_T sf_MATLABFunction2_h;// '<S58>/MATLAB Function2' 
  DW_MATLABFunction_Quadcopter_ControllerWithNavigation_g_T sf_MATLABFunction_i;// '<S58>/MATLAB Function' 
  DW_MATLABFunction2_Quadcopter_ControllerWithNavigation_T sf_MATLABFunction2_k;// '<S57>/MATLAB Function2' 
  DW_MATLABFunction_Quadcopter_ControllerWithNavigation_T sf_MATLABFunction_o;// '<S57>/MATLAB Function' 
  DW_MATLABFunction2_Quadcopter_ControllerWithNavigation_T sf_MATLABFunction2_o;// '<S56>/MATLAB Function2' 
  DW_MATLABFunction_Quadcopter_ControllerWithNavigation_T sf_MATLABFunction_p;// '<S56>/MATLAB Function' 
  DW_MATLABFunction2_Quadcopter_ControllerWithNavigation_T sf_MATLABFunction2;// '<S55>/MATLAB Function2' 
  DW_MATLABSystem_Quadcopter_ControllerWithNavigation_T MATLABSystem_b;// '<S40>/MATLAB System' 
  DW_MATLABSystem_Quadcopter_ControllerWithNavigation_T MATLABSystem;// '<S40>/MATLAB System' 
};

// Parameters (default storage)
struct P_Quadcopter_ControllerWithNavigation_T_ {
  real_T PIDController_D;              // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S105>/Derivative Gain'

  real_T PIDController1_D;             // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S155>/Derivative Gain'

  real_T PIDController2_D;             // Mask Parameter: PIDController2_D
                                          //  Referenced by: '<S205>/Derivative Gain'

  real_T PID_Altitude_D;               // Mask Parameter: PID_Altitude_D
                                          //  Referenced by: '<S518>/Derivative Gain'

  real_T PID_vz_D;                     // Mask Parameter: PID_vz_D
                                          //  Referenced by: '<S568>/Derivative Gain'

  real_T PIDController_I;              // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S108>/Integral Gain'

  real_T PIDController1_I;             // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S158>/Integral Gain'

  real_T PIDController2_I;             // Mask Parameter: PIDController2_I
                                          //  Referenced by: '<S208>/Integral Gain'

  real_T PID_Altitude_I;               // Mask Parameter: PID_Altitude_I
                                          //  Referenced by: '<S521>/Integral Gain'

  real_T PID_vz_I;                     // Mask Parameter: PID_vz_I
                                          //  Referenced by: '<S571>/Integral Gain'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S106>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S156>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S206>/Filter'

  real_T PID_Altitude_InitialConditionForFilter;
                       // Mask Parameter: PID_Altitude_InitialConditionForFilter
                          //  Referenced by: '<S519>/Filter'

  real_T PID_vz_InitialConditionForFilter;
                             // Mask Parameter: PID_vz_InitialConditionForFilter
                                //  Referenced by: '<S569>/Filter'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S111>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S161>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S211>/Integrator'

  real_T PID_Altitude_InitialConditionForIntegrator;
                   // Mask Parameter: PID_Altitude_InitialConditionForIntegrator
                      //  Referenced by: '<S524>/Integrator'

  real_T PID_vz_InitialConditionForIntegrator;
                         // Mask Parameter: PID_vz_InitialConditionForIntegrator
                            //  Referenced by: '<S574>/Integrator'

  real_T PIDController5_LowerSaturationLimit;
                          // Mask Parameter: PIDController5_LowerSaturationLimit
                             //  Referenced by: '<S362>/Saturation'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by:
                              //    '<S118>/Saturation'
                              //    '<S104>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S168>/Saturation'
                             //    '<S154>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S218>/Saturation'
                             //    '<S204>/DeadZone'

  real_T PID_Altitude_LowerSaturationLimit;
                            // Mask Parameter: PID_Altitude_LowerSaturationLimit
                               //  Referenced by:
                               //    '<S531>/Saturation'
                               //    '<S517>/DeadZone'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by:
                                     //    '<S581>/Saturation'
                                     //    '<S567>/DeadZone'

  real_T PIDController1_LowerSaturationLimit_j;
                        // Mask Parameter: PIDController1_LowerSaturationLimit_j
                           //  Referenced by: '<S481>/Saturation'

  real_T PIDController_LowerSaturationLimit_f;
                         // Mask Parameter: PIDController_LowerSaturationLimit_f
                            //  Referenced by: '<S433>/Saturation'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S114>/Filter Coefficient'

  real_T PIDController1_N;             // Mask Parameter: PIDController1_N
                                          //  Referenced by: '<S164>/Filter Coefficient'

  real_T PIDController2_N;             // Mask Parameter: PIDController2_N
                                          //  Referenced by: '<S214>/Filter Coefficient'

  real_T PID_Altitude_N;               // Mask Parameter: PID_Altitude_N
                                          //  Referenced by: '<S527>/Filter Coefficient'

  real_T PID_vz_N;                     // Mask Parameter: PID_vz_N
                                          //  Referenced by: '<S577>/Filter Coefficient'

  real_T PIDController5_P;             // Mask Parameter: PIDController5_P
                                          //  Referenced by: '<S360>/Proportional Gain'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S116>/Proportional Gain'

  real_T PIDController3_P;             // Mask Parameter: PIDController3_P
                                          //  Referenced by: '<S264>/Proportional Gain'

  real_T PIDController1_P;             // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S166>/Proportional Gain'

  real_T PIDController4_P;             // Mask Parameter: PIDController4_P
                                          //  Referenced by: '<S312>/Proportional Gain'

  real_T PIDController2_P;             // Mask Parameter: PIDController2_P
                                          //  Referenced by: '<S216>/Proportional Gain'

  real_T PID_Altitude_P;               // Mask Parameter: PID_Altitude_P
                                          //  Referenced by: '<S529>/Proportional Gain'

  real_T PID_vz_P;                     // Mask Parameter: PID_vz_P
                                          //  Referenced by: '<S579>/Proportional Gain'

  real_T PIDController1_P_f;           // Mask Parameter: PIDController1_P_f
                                          //  Referenced by: '<S479>/Proportional Gain'

  real_T PIDController_P_n;            // Mask Parameter: PIDController_P_n
                                          //  Referenced by: '<S431>/Proportional Gain'

  real_T PIDController5_UpperSaturationLimit;
                          // Mask Parameter: PIDController5_UpperSaturationLimit
                             //  Referenced by: '<S362>/Saturation'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by:
                              //    '<S118>/Saturation'
                              //    '<S104>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S168>/Saturation'
                             //    '<S154>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S218>/Saturation'
                             //    '<S204>/DeadZone'

  real_T PID_Altitude_UpperSaturationLimit;
                            // Mask Parameter: PID_Altitude_UpperSaturationLimit
                               //  Referenced by:
                               //    '<S531>/Saturation'
                               //    '<S517>/DeadZone'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by:
                                     //    '<S581>/Saturation'
                                     //    '<S567>/DeadZone'

  real_T PIDController1_UpperSaturationLimit_h;
                        // Mask Parameter: PIDController1_UpperSaturationLimit_h
                           //  Referenced by: '<S481>/Saturation'

  real_T PIDController_UpperSaturationLimit_i;
                         // Mask Parameter: PIDController_UpperSaturationLimit_i
                            //  Referenced by: '<S433>/Saturation'

  uint8_T CompareToConstant_const;    // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S32>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Out1_Y0;// Computed Parameter: Out1_Y0
                                                 //  Referenced by: '<S39>/Out1'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value;// Computed Parameter: Constant_Value
                                                        //  Referenced by: '<S44>/Constant'

  px4_Bus_vehicle_trajectory_waypoint Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                          //  Referenced by: '<S38>/Constant'

  px4_Bus_vehicle_odometry Out1_Y0_e;  // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S10>/Out1'

  px4_Bus_vehicle_odometry Constant_Value_n;// Computed Parameter: Constant_Value_n
                                               //  Referenced by: '<S6>/Constant'

  px4_Bus_position_setpoint_triplet Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                 //  Referenced by: '<S51>/Out1'

  px4_Bus_position_setpoint_triplet Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                        //  Referenced by: '<S36>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                              //  Referenced by: '<S13>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                     //  Referenced by: '<S9>/Constant'

  px4_Bus_vehicle_gps_position Out1_Y0_j;// Computed Parameter: Out1_Y0_j
                                            //  Referenced by: '<S383>/Out1'

  px4_Bus_vehicle_gps_position Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                   //  Referenced by: '<S382>/Constant'

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S12>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_l;// Computed Parameter: Constant_Value_l
                                               //  Referenced by: '<S8>/Constant'

  px4_Bus_home_position Out1_Y0_o;     // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S50>/Out1'

  px4_Bus_home_position Constant_Value_b;// Computed Parameter: Constant_Value_b
                                            //  Referenced by: '<S35>/Constant'

  px4_Bus_sensor_accel Out1_Y0_g;      // Computed Parameter: Out1_Y0_g
                                          //  Referenced by: '<S70>/Out1'

  px4_Bus_sensor_accel Constant_Value_c;// Computed Parameter: Constant_Value_c
                                           //  Referenced by: '<S69>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_eg;      // Computed Parameter: Out1_Y0_eg
                                          //  Referenced by: '<S385>/Out1'

  px4_Bus_sensor_gyro Constant_Value_e5;// Computed Parameter: Constant_Value_e5
                                           //  Referenced by: '<S384>/Constant'

  px4_Bus_sensor_mag Out1_Y0_m;        // Computed Parameter: Out1_Y0_m
                                          //  Referenced by: '<S387>/Out1'

  px4_Bus_sensor_mag Constant_Value_na;// Computed Parameter: Constant_Value_na
                                          //  Referenced by: '<S386>/Constant'

  px4_Bus_actuator_armed Out1_Y0_d;    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S11>/Out1'

  px4_Bus_actuator_armed Constant_Value_jl;// Computed Parameter: Constant_Value_jl
                                              //  Referenced by: '<S7>/Constant'

  real_T yaw_Out_Y0;                   // Computed Parameter: yaw_Out_Y0
                                          //  Referenced by: '<S30>/yaw_Out'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S28>/Delay'

  real_T Rate_Value;                   // Expression: 0.01
                                          //  Referenced by: '<S28>/Rate'

  real_T Gain1_Gain;                   // Expression: -1
                                          //  Referenced by: '<S28>/Gain1'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S28>/Gain'

  real_T Delay_InitialCondition_g;     // Expression: 1
                                          //  Referenced by: '<S29>/Delay'

  real_T Constant_Value_f;             // Expression: 0
                                          //  Referenced by: '<S29>/Constant'

  real_T Out_Y0;                       // Computed Parameter: Out_Y0
                                          //  Referenced by: '<S26>/Out'

  real_T Gain_Gain_l;                  // Expression: -1
                                          //  Referenced by: '<S24>/Gain'

  real_T yaw_Out_Y0_f;                 // Computed Parameter: yaw_Out_Y0_f
                                          //  Referenced by: '<S27>/yaw_Out'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S19>/Delay'

  real_T Delay_InitialCondition_m;     // Expression: 0.0
                                          //  Referenced by: '<S24>/Delay'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<S24>/Switch'

  real_T Rateofdescent_Value;          // Expression: 0.02
                                          //  Referenced by: '<S24>/Rate of descent'

  real_T Gain2_Gain;                   // Expression: -1
                                          //  Referenced by: '<S24>/Gain2'

  real_T Gain1_Gain_a;                 // Expression: -1
                                          //  Referenced by: '<S24>/Gain1'

  real_T Delay_InitialCondition_j;     // Expression: 1
                                          //  Referenced by: '<S25>/Delay'

  real_T Constant_Value_nn;            // Expression: 0
                                          //  Referenced by: '<S25>/Constant'

  real_T Constant_Value_jd;            // Expression: 0
                                          //  Referenced by: '<S31>/Constant'

  real_T Constant_Value_gw;            // Expression: 6
                                          //  Referenced by: '<S21>/Constant'

  real_T yaw_Out_Y0_p;                 // Computed Parameter: yaw_Out_Y0_p
                                          //  Referenced by: '<S23>/yaw_Out'

  real_T Delay_InitialCondition_g0;    // Expression: 1
                                          //  Referenced by: '<S22>/Delay'

  real_T Constant_Value_i;             // Expression: 0
                                          //  Referenced by: '<S22>/Constant'

  real_T ReadParameter_SampleTime;     // Expression: -1
                                          //  Referenced by: '<S17>/Read Parameter'

  real_T ReadParameter_SampleTime_c;   // Expression: -1
                                          //  Referenced by: '<S49>/Read Parameter'

  real_T ReadParameter_SampleTime_g;   // Expression: -1
                                          //  Referenced by: '<S48>/Read Parameter'

  real_T Switch1_Threshold;            // Expression: 0
                                          //  Referenced by: '<S71>/Switch1'

  real_T tau_Yaw_Y0;                   // Computed Parameter: tau_Yaw_Y0
                                          //  Referenced by: '<S54>/tau_Yaw'

  real_T tau_Pitch_Y0;                 // Computed Parameter: tau_Pitch_Y0
                                          //  Referenced by: '<S54>/tau_Pitch'

  real_T tau_Roll_Y0;                  // Computed Parameter: tau_Roll_Y0
                                          //  Referenced by: '<S54>/tau_Roll'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S102>/Constant1'

  real_T Constant1_Value_e;            // Expression: 0
                                          //  Referenced by: '<S152>/Constant1'

  real_T Constant1_Value_a;            // Expression: 0
                                          //  Referenced by: '<S202>/Constant1'

  real_T Constant_Value_p;             // Expression: 2*pi
                                          //  Referenced by: '<S71>/Constant'

  real_T Switch_Threshold_e;           // Expression: pi
                                          //  Referenced by: '<S71>/Switch'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S111>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S106>/Filter'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S102>/Clamping_zero'

  real_T RateLimiter2_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S54>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S54>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                          //  Referenced by: '<S54>/Rate Limiter2'

  real_T Saturation1_UpperSat;         // Expression: 20*pi/180
                                          //  Referenced by: '<S54>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -20*pi/180
                                          //  Referenced by: '<S54>/Saturation1'

  real_T Clamping_zero_Value_e;        // Expression: 0
                                          //  Referenced by: '<S152>/Clamping_zero'

  real_T Integrator_gainval_k;       // Computed Parameter: Integrator_gainval_k
                                        //  Referenced by: '<S161>/Integrator'

  real_T Filter_gainval_p;             // Computed Parameter: Filter_gainval_p
                                          //  Referenced by: '<S156>/Filter'

  real_T RateLimiter1_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S54>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S54>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                          //  Referenced by: '<S54>/Rate Limiter1'

  real_T Saturation_UpperSat;          // Expression: 20*pi/180
                                          //  Referenced by: '<S54>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -20*pi/180
                                          //  Referenced by: '<S54>/Saturation'

  real_T Clamping_zero_Value_p;        // Expression: 0
                                          //  Referenced by: '<S202>/Clamping_zero'

  real_T Integrator_gainval_i;       // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S211>/Integrator'

  real_T Filter_gainval_h;             // Computed Parameter: Filter_gainval_h
                                          //  Referenced by: '<S206>/Filter'

  real_T Constant_Value_j4;            // Expression: 0
                                          //  Referenced by: '<S388>/Constant'

  real_T tau_Thrust_Y0;                // Computed Parameter: tau_Thrust_Y0
                                          //  Referenced by: '<S66>/tau_Thrust'

  real_T des_pitch_Y0;                 // Computed Parameter: des_pitch_Y0
                                          //  Referenced by: '<S66>/des_pitch'

  real_T des_roll_Y0;                  // Computed Parameter: des_roll_Y0
                                          //  Referenced by: '<S66>/des_roll'

  real_T Constant1_Value_f;            // Expression: 0
                                          //  Referenced by: '<S515>/Constant1'

  real_T Constant1_Value_o;            // Expression: 0
                                          //  Referenced by: '<S565>/Constant1'

  real_T Gain1_Gain_o;                 // Expression: -1
                                          //  Referenced by: '<S388>/Gain1'

  real_T Clamping_zero_Value_m;        // Expression: 0
                                          //  Referenced by: '<S515>/Clamping_zero'

  real_T Filter_gainval_g;             // Computed Parameter: Filter_gainval_g
                                          //  Referenced by: '<S519>/Filter'

  real_T Integrator_gainval_a;       // Computed Parameter: Integrator_gainval_a
                                        //  Referenced by: '<S524>/Integrator'

  real_T Clamping_zero_Value_et;       // Expression: 0
                                          //  Referenced by: '<S565>/Clamping_zero'

  real_T Filter_gainval_k;             // Computed Parameter: Filter_gainval_k
                                          //  Referenced by: '<S569>/Filter'

  real_T Integrator_gainval_g;       // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S574>/Integrator'

  real_T Gain_Gain_l2;                 // Expression: -1
                                          //  Referenced by: '<S389>/Gain'

  real_T Gain1_Gain_f;                 // Expression: -1
                                          //  Referenced by: '<S66>/Gain1'

  real_T Constant_Value_im[4];         // Expression: [1 0 0 0]
                                          //  Referenced by: '<S67>/Constant'

  real_T Constant_Value_be;            // Expression: 1
                                          //  Referenced by: '<S595>/Constant'

  real_T Constant_Value_m;             // Expression: 1
                                          //  Referenced by: '<S596>/Constant'

  real_T Mixermatrix_Value[16];
                          // Expression: [1 1 -1 1;1 -1 1 1;1 1 1 -1;1 -1 -1 -1]
                             //  Referenced by: '<S5>/Mixer matrix'

  real_T Gain_Gain_c;                  // Expression: -1
                                          //  Referenced by: '<S52>/Gain'

  real_T Switch_Threshold_l;           // Expression: 0
                                          //  Referenced by: '<S67>/Switch'

  real_T Bias_Bias;                    // Expression: 1
                                          //  Referenced by: '<S5>/Bias'

  real_T Gain1_Gain_p;                 // Expression: 1000
                                          //  Referenced by: '<S5>/Gain1'

  real_T Delay1_InitialCondition[130]; // Expression: zeros(130,1)
                                          //  Referenced by: '<S55>/Delay1'

  real_T Constant_Value_o;             // Expression: 130
                                          //  Referenced by: '<S52>/Constant'

  real_T Delay_InitialCondition_p;     // Expression: 1
                                          //  Referenced by: '<S55>/Delay'

  real_T Delay1_InitialCondition_a[130];// Expression: zeros(130,1)
                                           //  Referenced by: '<S56>/Delay1'

  real_T Delay_InitialCondition_jz;    // Expression: 1
                                          //  Referenced by: '<S56>/Delay'

  real_T Delay1_InitialCondition_h[130];// Expression: zeros(130,1)
                                           //  Referenced by: '<S57>/Delay1'

  real_T Delay_InitialCondition_o;     // Expression: 1
                                          //  Referenced by: '<S57>/Delay'

  real_T Delay1_InitialCondition_f[130];// Expression: zeros(130,1)
                                           //  Referenced by: '<S58>/Delay1'

  real_T Delay_InitialCondition_h;     // Expression: 1
                                          //  Referenced by: '<S58>/Delay'

  real_T Delay1_InitialCondition_b[130];// Expression: zeros(130,1)
                                           //  Referenced by: '<S59>/Delay1'

  real_T Delay_InitialCondition_b;     // Expression: 1
                                          //  Referenced by: '<S59>/Delay'

  uint64_T Constant7_Value;            // Computed Parameter: Constant7_Value
                                          //  Referenced by: '<S42>/Constant7'

  real32_T Constant1_Value_d[2];       // Computed Parameter: Constant1_Value_d
                                          //  Referenced by: '<S49>/Constant1'

  real32_T Constant_Value_f2;          // Computed Parameter: Constant_Value_f2
                                          //  Referenced by: '<S49>/Constant'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S48>/Gain'

  real32_T Constant1_Value_k[2];       // Computed Parameter: Constant1_Value_k
                                          //  Referenced by: '<S48>/Constant1'

  real32_T Constant_Value_l4;          // Computed Parameter: Constant_Value_l4
                                          //  Referenced by: '<S48>/Constant'

  real32_T Constant_Value_fh[3];       // Computed Parameter: Constant_Value_fh
                                          //  Referenced by: '<S42>/Constant'

  real32_T Constant1_Value_h[3];       // Computed Parameter: Constant1_Value_h
                                          //  Referenced by: '<S42>/Constant1'

  real32_T Constant3_Value;            // Computed Parameter: Constant3_Value
                                          //  Referenced by: '<S42>/Constant3'

  real32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                          //  Referenced by: '<S42>/Constant4'

  real32_T Constant2_Value[3];         // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<S42>/Constant2'

  uint16_T Saturation_UpperSat_g;   // Computed Parameter: Saturation_UpperSat_g
                                       //  Referenced by: '<S5>/Saturation'

  uint16_T Saturation_LowerSat_j;   // Computed Parameter: Saturation_LowerSat_j
                                       //  Referenced by: '<S5>/Saturation'

  boolean_T Constant5_Value;           // Computed Parameter: Constant5_Value
                                          //  Referenced by: '<S40>/Constant5'

  boolean_T Constant5_Value_k;         // Computed Parameter: Constant5_Value_k
                                          //  Referenced by: '<S41>/Constant5'

  boolean_T Constant1_Value_dl;        // Computed Parameter: Constant1_Value_dl
                                          //  Referenced by: '<S43>/Constant1'

  boolean_T Constant5_Value_h;         // Computed Parameter: Constant5_Value_h
                                          //  Referenced by: '<S43>/Constant5'

  boolean_T Constant5_Value_l;         // Computed Parameter: Constant5_Value_l
                                          //  Referenced by: '<S42>/Constant5'

  boolean_T Constant1_Value_c;         // Expression: false
                                          //  Referenced by: '<S5>/Constant1'

  int8_T Constant_Value_k;             // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S102>/Constant'

  int8_T Constant2_Value_e;            // Computed Parameter: Constant2_Value_e
                                          //  Referenced by: '<S102>/Constant2'

  int8_T Constant3_Value_g;            // Computed Parameter: Constant3_Value_g
                                          //  Referenced by: '<S102>/Constant3'

  int8_T Constant4_Value_j;            // Computed Parameter: Constant4_Value_j
                                          //  Referenced by: '<S102>/Constant4'

  int8_T Constant_Value_h;             // Computed Parameter: Constant_Value_h
                                          //  Referenced by: '<S152>/Constant'

  int8_T Constant2_Value_f;            // Computed Parameter: Constant2_Value_f
                                          //  Referenced by: '<S152>/Constant2'

  int8_T Constant3_Value_c;            // Computed Parameter: Constant3_Value_c
                                          //  Referenced by: '<S152>/Constant3'

  int8_T Constant4_Value_e;            // Computed Parameter: Constant4_Value_e
                                          //  Referenced by: '<S152>/Constant4'

  int8_T Constant_Value_is;            // Computed Parameter: Constant_Value_is
                                          //  Referenced by: '<S202>/Constant'

  int8_T Constant2_Value_a;            // Computed Parameter: Constant2_Value_a
                                          //  Referenced by: '<S202>/Constant2'

  int8_T Constant3_Value_b;            // Computed Parameter: Constant3_Value_b
                                          //  Referenced by: '<S202>/Constant3'

  int8_T Constant4_Value_k;            // Computed Parameter: Constant4_Value_k
                                          //  Referenced by: '<S202>/Constant4'

  int8_T Constant_Value_hk;            // Computed Parameter: Constant_Value_hk
                                          //  Referenced by: '<S515>/Constant'

  int8_T Constant2_Value_l;            // Computed Parameter: Constant2_Value_l
                                          //  Referenced by: '<S515>/Constant2'

  int8_T Constant3_Value_gn;           // Computed Parameter: Constant3_Value_gn
                                          //  Referenced by: '<S515>/Constant3'

  int8_T Constant4_Value_g;            // Computed Parameter: Constant4_Value_g
                                          //  Referenced by: '<S515>/Constant4'

  int8_T Constant_Value_mp;            // Computed Parameter: Constant_Value_mp
                                          //  Referenced by: '<S565>/Constant'

  int8_T Constant2_Value_k;            // Computed Parameter: Constant2_Value_k
                                          //  Referenced by: '<S565>/Constant2'

  int8_T Constant3_Value_i;            // Computed Parameter: Constant3_Value_i
                                          //  Referenced by: '<S565>/Constant3'

  int8_T Constant4_Value_ja;           // Computed Parameter: Constant4_Value_ja
                                          //  Referenced by: '<S565>/Constant4'

  uint8_T Constant_Value_fm;           // Computed Parameter: Constant_Value_fm
                                          //  Referenced by: '<S34>/Constant'

  uint8_T Constant6_Value;             // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<S42>/Constant6'

};

// Real-time Model Data Structure
struct tag_RTM_Quadcopter_ControllerWithNavigation_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_Quadcopter_ControllerWithNavigation_T
    Quadcopter_ControllerWithNavigation_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_Quadcopter_ControllerWithNavigation_T
    Quadcopter_ControllerWithNavigation_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_Quadcopter_ControllerWithNavigation_T
  Quadcopter_ControllerWithNavigation_DW;

// External function called from main
#ifdef __cplusplus

extern "C"
{

#endif

  extern void Quadcopter_ControllerWithNavigation_SetEventsForThisBaseStep
    (boolean_T *eventFlags);

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void Quadcopter_ControllerWithNavigation_initialize(void);
  extern void Quadcopter_ControllerWithNavigation_step0(void);
  extern void Quadcopter_ControllerWithNavigation_step1(void);
  extern void Quadcopter_ControllerWithNavigation_step2(void);
  extern void Quadcopter_ControllerWithNavigation_step(int_T tid);
  extern void Quadcopter_ControllerWithNavigation_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_Quadcopter_ControllerWithNavigation_T *const
    Quadcopter_ControllerWithNavigation_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S7>/NOT' : Unused code path elimination
//  Block '<S8>/NOT' : Unused code path elimination
//  Block '<S9>/NOT' : Unused code path elimination
//  Block '<S37>/Compare' : Unused code path elimination
//  Block '<S37>/Constant' : Unused code path elimination
//  Block '<S38>/NOT' : Unused code path elimination
//  Block '<S33>/Subtract' : Unused code path elimination
//  Block '<S35>/NOT' : Unused code path elimination
//  Block '<S36>/NOT' : Unused code path elimination
//  Block '<S69>/NOT' : Unused code path elimination
//  Block '<S382>/NOT' : Unused code path elimination
//  Block '<S384>/NOT' : Unused code path elimination
//  Block '<S386>/NOT' : Unused code path elimination
//  Block '<S394>/Data Type Duplicate' : Unused code path elimination
//  Block '<S394>/Data Type Propagation' : Unused code path elimination
//  Block '<S19>/Reshape1' : Reshape block reduction
//  Block '<S52>/Data Type Conversion' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Quadcopter_ControllerWithNavigation'
//  '<S1>'   : 'Quadcopter_ControllerWithNavigation/Actuator'
//  '<S2>'   : 'Quadcopter_ControllerWithNavigation/Estimator Output'
//  '<S3>'   : 'Quadcopter_ControllerWithNavigation/Navigation'
//  '<S4>'   : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller'
//  '<S5>'   : 'Quadcopter_ControllerWithNavigation/Actuator/Custom Mixer and PWM Output Block'
//  '<S6>'   : 'Quadcopter_ControllerWithNavigation/Estimator Output/PX4 uORB Read1'
//  '<S7>'   : 'Quadcopter_ControllerWithNavigation/Estimator Output/PX4 uORB Read2'
//  '<S8>'   : 'Quadcopter_ControllerWithNavigation/Estimator Output/vehicle_attitude'
//  '<S9>'   : 'Quadcopter_ControllerWithNavigation/Estimator Output/vehicle_local_pos'
//  '<S10>'  : 'Quadcopter_ControllerWithNavigation/Estimator Output/PX4 uORB Read1/Enabled Subsystem'
//  '<S11>'  : 'Quadcopter_ControllerWithNavigation/Estimator Output/PX4 uORB Read2/Enabled Subsystem'
//  '<S12>'  : 'Quadcopter_ControllerWithNavigation/Estimator Output/vehicle_attitude/Enabled Subsystem'
//  '<S13>'  : 'Quadcopter_ControllerWithNavigation/Estimator Output/vehicle_local_pos/Enabled Subsystem'
//  '<S14>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm'
//  '<S15>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission'
//  '<S16>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem'
//  '<S17>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC'
//  '<S18>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE'
//  '<S19>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land'
//  '<S20>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off'
//  '<S21>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint'
//  '<S22>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE'
//  '<S23>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/IDLE/Maintain Current Yaw during IDLE/Enabled Subsystem2'
//  '<S24>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land'
//  '<S25>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land'
//  '<S26>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Ensure Smooth descend during Land/Enabled Subsystem'
//  '<S27>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Land/Maintain Current Yaw during Land/Enabled Subsystem2'
//  '<S28>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Ensure smooth ascend during Takeoff'
//  '<S29>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff'
//  '<S30>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Take-off/Maintain Current Yaw during TakeOff/Enabled Subsystem2'
//  '<S31>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning'
//  '<S32>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Guidance Subsystem/Waypoint/Output signal conditioning/Compare To Constant'
//  '<S33>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC'
//  '<S34>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC'
//  '<S35>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead'
//  '<S36>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead'
//  '<S37>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/Compare To Constant'
//  '<S38>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read'
//  '<S39>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Read waypoints from OBC/PX4 uORB Read/Enabled Subsystem'
//  '<S40>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint'
//  '<S41>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_WayPoint'
//  '<S42>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Empty_WayPoint'
//  '<S43>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Next_WayPoint'
//  '<S44>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Message'
//  '<S45>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/PX4 uORB Write'
//  '<S46>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP'
//  '<S47>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem'
//  '<S48>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem1'
//  '<S49>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/Send waypoints to OBC/Current_Type_Adapted_WayPoint/Convert_to_type_adapted_WP/If Action Subsystem2'
//  '<S50>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/homePositionRead/Enabled Subsystem'
//  '<S51>'  : 'Quadcopter_ControllerWithNavigation/Navigation/Quadcopter Navigation Algorithm/Read waypoint from QGroundControl Mission/Read Position Setpoint from Mission set in QGC/positionSetpointRead/Enabled Subsystem'
//  '<S52>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller'
//  '<S53>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Accelerometer'
//  '<S54>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller'
//  '<S55>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer1'
//  '<S56>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer2'
//  '<S57>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer3'
//  '<S58>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer4'
//  '<S59>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer5'
//  '<S60>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/GPS'
//  '<S61>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Gyroscope'
//  '<S62>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/MATLAB Function'
//  '<S63>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/MATLAB Function1'
//  '<S64>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/MATLAB Function3'
//  '<S65>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Magnetometer'
//  '<S66>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller'
//  '<S67>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternion Validity Check'
//  '<S68>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles'
//  '<S69>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Accelerometer/PX4 uORB Read'
//  '<S70>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S71>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/Calculate minimum Turn'
//  '<S72>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller'
//  '<S73>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1'
//  '<S74>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2'
//  '<S75>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3'
//  '<S76>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4'
//  '<S77>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5'
//  '<S78>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Anti-windup'
//  '<S79>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/D Gain'
//  '<S80>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Filter'
//  '<S81>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Filter ICs'
//  '<S82>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/I Gain'
//  '<S83>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Ideal P Gain'
//  '<S84>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S85>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Integrator'
//  '<S86>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Integrator ICs'
//  '<S87>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/N Copy'
//  '<S88>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/N Gain'
//  '<S89>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/P Copy'
//  '<S90>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Parallel P Gain'
//  '<S91>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Reset Signal'
//  '<S92>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Saturation'
//  '<S93>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Saturation Fdbk'
//  '<S94>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Sum'
//  '<S95>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Sum Fdbk'
//  '<S96>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tracking Mode'
//  '<S97>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tracking Mode Sum'
//  '<S98>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tsamp - Integral'
//  '<S99>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tsamp - Ngain'
//  '<S100>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/postSat Signal'
//  '<S101>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/preSat Signal'
//  '<S102>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S103>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S104>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S105>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/D Gain/Internal Parameters'
//  '<S106>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S107>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S108>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/I Gain/Internal Parameters'
//  '<S109>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S110>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S111>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Integrator/Discrete'
//  '<S112>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Integrator ICs/Internal IC'
//  '<S113>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/N Copy/Disabled'
//  '<S114>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/N Gain/Internal Parameters'
//  '<S115>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/P Copy/Disabled'
//  '<S116>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S117>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Reset Signal/Disabled'
//  '<S118>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Saturation/Enabled'
//  '<S119>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S120>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Sum/Sum_PID'
//  '<S121>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S122>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S123>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S124>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S125>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S126>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S127>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S128>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Anti-windup'
//  '<S129>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/D Gain'
//  '<S130>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Filter'
//  '<S131>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Filter ICs'
//  '<S132>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/I Gain'
//  '<S133>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Ideal P Gain'
//  '<S134>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S135>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Integrator'
//  '<S136>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Integrator ICs'
//  '<S137>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/N Copy'
//  '<S138>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/N Gain'
//  '<S139>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/P Copy'
//  '<S140>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Parallel P Gain'
//  '<S141>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Reset Signal'
//  '<S142>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Saturation'
//  '<S143>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Saturation Fdbk'
//  '<S144>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Sum'
//  '<S145>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Sum Fdbk'
//  '<S146>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tracking Mode'
//  '<S147>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tracking Mode Sum'
//  '<S148>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tsamp - Integral'
//  '<S149>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tsamp - Ngain'
//  '<S150>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/postSat Signal'
//  '<S151>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/preSat Signal'
//  '<S152>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S153>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S154>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S155>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/D Gain/Internal Parameters'
//  '<S156>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S157>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S158>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/I Gain/Internal Parameters'
//  '<S159>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S160>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S161>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Integrator/Discrete'
//  '<S162>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S163>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/N Copy/Disabled'
//  '<S164>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/N Gain/Internal Parameters'
//  '<S165>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/P Copy/Disabled'
//  '<S166>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S167>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S168>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Saturation/Enabled'
//  '<S169>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S170>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Sum/Sum_PID'
//  '<S171>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S172>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S173>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S174>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S175>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S176>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S177>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S178>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Anti-windup'
//  '<S179>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/D Gain'
//  '<S180>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Filter'
//  '<S181>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Filter ICs'
//  '<S182>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/I Gain'
//  '<S183>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Ideal P Gain'
//  '<S184>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S185>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Integrator'
//  '<S186>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Integrator ICs'
//  '<S187>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/N Copy'
//  '<S188>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/N Gain'
//  '<S189>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/P Copy'
//  '<S190>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Parallel P Gain'
//  '<S191>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Reset Signal'
//  '<S192>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Saturation'
//  '<S193>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Saturation Fdbk'
//  '<S194>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Sum'
//  '<S195>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Sum Fdbk'
//  '<S196>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tracking Mode'
//  '<S197>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tracking Mode Sum'
//  '<S198>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tsamp - Integral'
//  '<S199>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tsamp - Ngain'
//  '<S200>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/postSat Signal'
//  '<S201>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/preSat Signal'
//  '<S202>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S203>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S204>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S205>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/D Gain/Internal Parameters'
//  '<S206>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S207>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S208>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/I Gain/Internal Parameters'
//  '<S209>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S210>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S211>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Integrator/Discrete'
//  '<S212>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S213>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/N Copy/Disabled'
//  '<S214>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/N Gain/Internal Parameters'
//  '<S215>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/P Copy/Disabled'
//  '<S216>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S217>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Reset Signal/Disabled'
//  '<S218>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Saturation/Enabled'
//  '<S219>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S220>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Sum/Sum_PID'
//  '<S221>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S222>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tracking Mode/Disabled'
//  '<S223>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S224>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S225>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S226>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S227>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S228>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Anti-windup'
//  '<S229>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/D Gain'
//  '<S230>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Filter'
//  '<S231>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Filter ICs'
//  '<S232>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/I Gain'
//  '<S233>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Ideal P Gain'
//  '<S234>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S235>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Integrator'
//  '<S236>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Integrator ICs'
//  '<S237>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/N Copy'
//  '<S238>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/N Gain'
//  '<S239>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/P Copy'
//  '<S240>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Parallel P Gain'
//  '<S241>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Reset Signal'
//  '<S242>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Saturation'
//  '<S243>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Saturation Fdbk'
//  '<S244>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Sum'
//  '<S245>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Sum Fdbk'
//  '<S246>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tracking Mode'
//  '<S247>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tracking Mode Sum'
//  '<S248>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tsamp - Integral'
//  '<S249>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tsamp - Ngain'
//  '<S250>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/postSat Signal'
//  '<S251>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/preSat Signal'
//  '<S252>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Anti-windup/Disabled'
//  '<S253>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/D Gain/Disabled'
//  '<S254>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Filter/Disabled'
//  '<S255>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Filter ICs/Disabled'
//  '<S256>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/I Gain/Disabled'
//  '<S257>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S258>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S259>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Integrator/Disabled'
//  '<S260>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Integrator ICs/Disabled'
//  '<S261>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S262>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/N Gain/Disabled'
//  '<S263>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/P Copy/Disabled'
//  '<S264>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S265>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Reset Signal/Disabled'
//  '<S266>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Saturation/Passthrough'
//  '<S267>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S268>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Sum/Passthrough_P'
//  '<S269>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S270>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tracking Mode/Disabled'
//  '<S271>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S272>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S273>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S274>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S275>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S276>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Anti-windup'
//  '<S277>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/D Gain'
//  '<S278>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Filter'
//  '<S279>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Filter ICs'
//  '<S280>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/I Gain'
//  '<S281>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Ideal P Gain'
//  '<S282>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S283>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Integrator'
//  '<S284>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Integrator ICs'
//  '<S285>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/N Copy'
//  '<S286>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/N Gain'
//  '<S287>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/P Copy'
//  '<S288>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Parallel P Gain'
//  '<S289>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Reset Signal'
//  '<S290>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Saturation'
//  '<S291>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Saturation Fdbk'
//  '<S292>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Sum'
//  '<S293>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Sum Fdbk'
//  '<S294>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tracking Mode'
//  '<S295>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tracking Mode Sum'
//  '<S296>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tsamp - Integral'
//  '<S297>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tsamp - Ngain'
//  '<S298>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/postSat Signal'
//  '<S299>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/preSat Signal'
//  '<S300>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Anti-windup/Disabled'
//  '<S301>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/D Gain/Disabled'
//  '<S302>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Filter/Disabled'
//  '<S303>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Filter ICs/Disabled'
//  '<S304>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/I Gain/Disabled'
//  '<S305>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S306>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S307>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Integrator/Disabled'
//  '<S308>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Integrator ICs/Disabled'
//  '<S309>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S310>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/N Gain/Disabled'
//  '<S311>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/P Copy/Disabled'
//  '<S312>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S313>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Reset Signal/Disabled'
//  '<S314>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Saturation/Passthrough'
//  '<S315>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S316>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Sum/Passthrough_P'
//  '<S317>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S318>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tracking Mode/Disabled'
//  '<S319>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S320>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S321>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S322>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S323>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S324>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Anti-windup'
//  '<S325>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/D Gain'
//  '<S326>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Filter'
//  '<S327>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Filter ICs'
//  '<S328>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/I Gain'
//  '<S329>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Ideal P Gain'
//  '<S330>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S331>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Integrator'
//  '<S332>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Integrator ICs'
//  '<S333>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/N Copy'
//  '<S334>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/N Gain'
//  '<S335>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/P Copy'
//  '<S336>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Parallel P Gain'
//  '<S337>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Reset Signal'
//  '<S338>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Saturation'
//  '<S339>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Saturation Fdbk'
//  '<S340>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Sum'
//  '<S341>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Sum Fdbk'
//  '<S342>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tracking Mode'
//  '<S343>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tracking Mode Sum'
//  '<S344>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tsamp - Integral'
//  '<S345>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tsamp - Ngain'
//  '<S346>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/postSat Signal'
//  '<S347>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/preSat Signal'
//  '<S348>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Anti-windup/Disabled'
//  '<S349>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/D Gain/Disabled'
//  '<S350>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Filter/Disabled'
//  '<S351>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Filter ICs/Disabled'
//  '<S352>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/I Gain/Disabled'
//  '<S353>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S354>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S355>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Integrator/Disabled'
//  '<S356>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Integrator ICs/Disabled'
//  '<S357>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S358>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/N Gain/Disabled'
//  '<S359>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/P Copy/Disabled'
//  '<S360>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Parallel P Gain/Internal Parameters'
//  '<S361>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Reset Signal/Disabled'
//  '<S362>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Saturation/Enabled'
//  '<S363>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S364>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Sum/Passthrough_P'
//  '<S365>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S366>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tracking Mode/Disabled'
//  '<S367>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S368>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S369>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S370>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S371>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S372>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer1/MATLAB Function'
//  '<S373>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer1/MATLAB Function2'
//  '<S374>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer2/MATLAB Function'
//  '<S375>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer2/MATLAB Function2'
//  '<S376>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer3/MATLAB Function'
//  '<S377>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer3/MATLAB Function2'
//  '<S378>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer4/MATLAB Function'
//  '<S379>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer4/MATLAB Function2'
//  '<S380>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer5/MATLAB Function'
//  '<S381>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Buffer5/MATLAB Function2'
//  '<S382>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/GPS/PX4 uORB Read'
//  '<S383>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/GPS/PX4 uORB Read/Enabled Subsystem'
//  '<S384>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Gyroscope/PX4 uORB Read'
//  '<S385>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S386>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Magnetometer/PX4 uORB Read'
//  '<S387>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Magnetometer/PX4 uORB Read/Enabled Subsystem'
//  '<S388>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/Altitude Signal conditioning'
//  '<S389>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/Calculate Transformation Matrix'
//  '<S390>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller'
//  '<S391>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1'
//  '<S392>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude'
//  '<S393>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz'
//  '<S394>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/Altitude Signal conditioning/Saturation Dynamic'
//  '<S395>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Anti-windup'
//  '<S396>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/D Gain'
//  '<S397>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Filter'
//  '<S398>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Filter ICs'
//  '<S399>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/I Gain'
//  '<S400>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Ideal P Gain'
//  '<S401>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S402>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Integrator'
//  '<S403>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Integrator ICs'
//  '<S404>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/N Copy'
//  '<S405>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/N Gain'
//  '<S406>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/P Copy'
//  '<S407>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Parallel P Gain'
//  '<S408>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Reset Signal'
//  '<S409>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Saturation'
//  '<S410>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Saturation Fdbk'
//  '<S411>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Sum'
//  '<S412>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Sum Fdbk'
//  '<S413>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tracking Mode'
//  '<S414>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tracking Mode Sum'
//  '<S415>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tsamp - Integral'
//  '<S416>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tsamp - Ngain'
//  '<S417>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/postSat Signal'
//  '<S418>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/preSat Signal'
//  '<S419>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Anti-windup/Disabled'
//  '<S420>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/D Gain/Disabled'
//  '<S421>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Filter/Disabled'
//  '<S422>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Filter ICs/Disabled'
//  '<S423>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/I Gain/Disabled'
//  '<S424>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S425>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S426>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Integrator/Disabled'
//  '<S427>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Integrator ICs/Disabled'
//  '<S428>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S429>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/N Gain/Disabled'
//  '<S430>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/P Copy/Disabled'
//  '<S431>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S432>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Reset Signal/Disabled'
//  '<S433>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Saturation/Enabled'
//  '<S434>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S435>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Sum/Passthrough_P'
//  '<S436>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S437>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S438>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S439>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S440>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S441>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S442>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S443>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Anti-windup'
//  '<S444>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/D Gain'
//  '<S445>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Filter'
//  '<S446>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Filter ICs'
//  '<S447>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/I Gain'
//  '<S448>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Ideal P Gain'
//  '<S449>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S450>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Integrator'
//  '<S451>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Integrator ICs'
//  '<S452>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/N Copy'
//  '<S453>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/N Gain'
//  '<S454>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/P Copy'
//  '<S455>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Parallel P Gain'
//  '<S456>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Reset Signal'
//  '<S457>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Saturation'
//  '<S458>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Saturation Fdbk'
//  '<S459>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Sum'
//  '<S460>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Sum Fdbk'
//  '<S461>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tracking Mode'
//  '<S462>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tracking Mode Sum'
//  '<S463>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tsamp - Integral'
//  '<S464>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tsamp - Ngain'
//  '<S465>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/postSat Signal'
//  '<S466>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/preSat Signal'
//  '<S467>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Anti-windup/Disabled'
//  '<S468>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/D Gain/Disabled'
//  '<S469>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Filter/Disabled'
//  '<S470>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Filter ICs/Disabled'
//  '<S471>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/I Gain/Disabled'
//  '<S472>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S473>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S474>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Integrator/Disabled'
//  '<S475>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Integrator ICs/Disabled'
//  '<S476>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S477>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/N Gain/Disabled'
//  '<S478>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/P Copy/Disabled'
//  '<S479>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S480>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S481>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Saturation/Enabled'
//  '<S482>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S483>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Sum/Passthrough_P'
//  '<S484>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S485>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S486>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S487>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S488>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S489>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S490>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S491>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Anti-windup'
//  '<S492>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/D Gain'
//  '<S493>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Filter'
//  '<S494>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Filter ICs'
//  '<S495>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/I Gain'
//  '<S496>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain'
//  '<S497>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S498>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Integrator'
//  '<S499>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Integrator ICs'
//  '<S500>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/N Copy'
//  '<S501>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/N Gain'
//  '<S502>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/P Copy'
//  '<S503>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain'
//  '<S504>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Reset Signal'
//  '<S505>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Saturation'
//  '<S506>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk'
//  '<S507>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Sum'
//  '<S508>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk'
//  '<S509>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode'
//  '<S510>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum'
//  '<S511>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral'
//  '<S512>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain'
//  '<S513>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/postSat Signal'
//  '<S514>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/preSat Signal'
//  '<S515>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel'
//  '<S516>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S517>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S518>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/D Gain/Internal Parameters'
//  '<S519>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Filter/Disc. Forward Euler Filter'
//  '<S520>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Filter ICs/Internal IC - Filter'
//  '<S521>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/I Gain/Internal Parameters'
//  '<S522>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S523>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk/Passthrough'
//  '<S524>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Integrator/Discrete'
//  '<S525>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Integrator ICs/Internal IC'
//  '<S526>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/N Copy/Disabled'
//  '<S527>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/N Gain/Internal Parameters'
//  '<S528>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/P Copy/Disabled'
//  '<S529>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain/Internal Parameters'
//  '<S530>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Reset Signal/Disabled'
//  '<S531>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Saturation/Enabled'
//  '<S532>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk/Passthrough'
//  '<S533>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Sum/Sum_PID'
//  '<S534>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk/Enabled'
//  '<S535>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S536>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S537>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S538>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S539>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/postSat Signal/Feedback_Path'
//  '<S540>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/preSat Signal/Feedback_Path'
//  '<S541>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Anti-windup'
//  '<S542>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/D Gain'
//  '<S543>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Filter'
//  '<S544>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Filter ICs'
//  '<S545>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/I Gain'
//  '<S546>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Ideal P Gain'
//  '<S547>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk'
//  '<S548>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Integrator'
//  '<S549>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Integrator ICs'
//  '<S550>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/N Copy'
//  '<S551>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/N Gain'
//  '<S552>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/P Copy'
//  '<S553>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Parallel P Gain'
//  '<S554>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Reset Signal'
//  '<S555>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Saturation'
//  '<S556>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Saturation Fdbk'
//  '<S557>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Sum'
//  '<S558>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Sum Fdbk'
//  '<S559>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tracking Mode'
//  '<S560>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum'
//  '<S561>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tsamp - Integral'
//  '<S562>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain'
//  '<S563>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/postSat Signal'
//  '<S564>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/preSat Signal'
//  '<S565>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel'
//  '<S566>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S567>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S568>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/D Gain/Internal Parameters'
//  '<S569>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S570>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S571>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/I Gain/Internal Parameters'
//  '<S572>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S573>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk/Passthrough'
//  '<S574>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Integrator/Discrete'
//  '<S575>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Integrator ICs/Internal IC'
//  '<S576>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/N Copy/Disabled'
//  '<S577>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/N Gain/Internal Parameters'
//  '<S578>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/P Copy/Disabled'
//  '<S579>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Parallel P Gain/Internal Parameters'
//  '<S580>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Reset Signal/Disabled'
//  '<S581>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Saturation/Enabled'
//  '<S582>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Saturation Fdbk/Passthrough'
//  '<S583>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Sum/Sum_PID'
//  '<S584>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Sum Fdbk/Enabled'
//  '<S585>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tracking Mode/Disabled'
//  '<S586>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S587>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S588>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S589>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/postSat Signal/Feedback_Path'
//  '<S590>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/preSat Signal/Feedback_Path'
//  '<S591>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternion Validity Check/Quaternion Norm'
//  '<S592>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Angle Calculation'
//  '<S593>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S594>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S595>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S596>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S597>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S598>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S599>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                     // RTW_HEADER_Quadcopter_ControllerWithNavigation_h_

//
// File trailer for generated code.
//
// [EOF]
//
