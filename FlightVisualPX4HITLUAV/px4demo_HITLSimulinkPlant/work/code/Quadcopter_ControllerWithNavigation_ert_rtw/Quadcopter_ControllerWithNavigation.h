//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Quadcopter_ControllerWithNavigation.h
//
// Code generated for Simulink model 'Quadcopter_ControllerWithNavigation'.
//
// Model version                  : 4.12
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Dec 13 15:25:49 2024
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
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/trajectory_waypoint.h>
#include <uORB/topics/home_position.h>
#include <uORB/topics/actuator_armed.h>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

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

// Block signals (default storage)
struct B_Quadcopter_ControllerWithNavigation_T {
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
  real_T b_waypointsIn_data[9];
  real_T MatrixConcatenate_p[9];       // '<S21>/Matrix Concatenate'
  px4_Bus_vehicle_attitude In1_m;      // '<S12>/In1'
  px4_Bus_vehicle_attitude b_varargout_2_b;
  px4_Bus_trajectory_waypoint BusAssignment1_f;// '<S42>/Bus Assignment1'
  px4_Bus_home_position In1_f;         // '<S50>/In1'
  px4_Bus_home_position b_varargout_2_p;
  real_T DataTypeConversion2[3];       // '<S2>/Data Type Conversion2'
  real_T TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport[18];
  // '<S52>/TmpSignal ConversionAt_asyncqueue_inserted_for_To WorkspaceInport1'
  real_T b_varargout_3[3];
  real_T lla0[3];
  real_T MatrixConcatenate1[3];        // '<S40>/Matrix Concatenate1'
  real_T MatrixConcatenate1_k[3];      // '<S34>/Matrix Concatenate1'
  real_T rtb_Reshape1_c[3];
  uint16_T pwmValue[8];
  px4_Bus_actuator_armed In1_b;        // '<S11>/In1'
  real_T DataTypeConversion1[7];       // '<S2>/Data Type Conversion1'
  real_T Merge[4];                     // '<S16>/Merge'
  px4_Bus_actuator_armed b_varargout_2_f;
  real_T desiredZ;                     // '<S52>/Gain'
  real_T VectorConcatenate[3];         // '<S562>/Vector Concatenate'
  real_T Saturation;                   // '<S551>/Saturation'
  real_T Saturation_n[2];              // '<S403>/Saturation'
  real_T Gain1;                        // '<S54>/Gain1'
  real_T Saturation_h;                 // '<S104>/Saturation'
  real_T Saturation_c;                 // '<S154>/Saturation'
  real_T Saturation_d;                 // '<S204>/Saturation'
  real_T yaw_In;                       // '<S23>/yaw_In'
  real_T yaw_In_i;                     // '<S27>/yaw_In'
  real_T In;                           // '<S26>/In'
  real_T yaw_In_ik;                    // '<S30>/yaw_In'
  real_T lambda;
  real_T b;
  real_T y;
  real_T Gain_i;                       // '<S28>/Gain'
  real_T Filter;                       // '<S92>/Filter'
  real_T FilterCoefficient_k;          // '<S547>/Filter Coefficient'
  real_T Filter_o;                     // '<S192>/Filter'
  real_T VectorConcatenate_tmp;
  real_T VectorConcatenate_tmp_g;
  real_T dLat;
  real_T dLon;
  real_T Rn;
  real_T flat;
  real_T b_x;
  real_T absx;
  real_T absx_g;
  real_T q;
  real_T scale;
  real_T absxk;
  real_T t;
  uint16_T Saturation_m[4];            // '<S5>/Saturation'
  boolean_T x[6];
  real32_T ParamStep;
  int32_T ParamStep_n;
  int32_T i2;
  int32_T i1;
  int32_T j;
  int32_T ix;
  int32_T b_exponent;
  int32_T b_exponent_p;
  int32_T waypoints_size_idx_0;
  int32_T b_k;
  int32_T i;
  int32_T i1_l;
  int8_T tmp_data[3];
  boolean_T distinctWptsIdx[3];
  boolean_T b_j[3];
  uint16_T status;
  boolean_T IsNaN_l[2];                // '<S19>/IsNaN'
  int8_T rtPrevAction;
  int8_T i2_d;
  boolean_T latp2;
  boolean_T p;
  boolean_T latp2_g;
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
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_kz;// '<S36>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_gf;// '<S35>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_e;// '<S38>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_m;// '<S9>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_gv;// '<S8>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_d;// '<S7>/SourceBlock' 
  px4_internal_block_Subscriber_Quadcopter_ControllerWithNaviga_T obj_po;// '<S6>/SourceBlock' 
  px4_internal_block_getPX4AbsoluteTime_Quadcopter_ControllerWi_T obj_n;// '<S33>/PX4 Timestamp' 
  px4_internal_block_LLA2LocalCoordinates_Quadcopter_Controller_T obj_mr;// '<S17>/LLA2LocalCoordinates' 
  px4_internal_block_Publisher_Quadcopter_ControllerWithNavigat_T obj_mc;// '<S45>/SinkBlock' 
  real_T Filter_DSTATE;                // '<S489>/Filter'
  real_T Integrator_DSTATE;            // '<S494>/Integrator'
  real_T Filter_DSTATE_m;              // '<S539>/Filter'
  real_T Integrator_DSTATE_c;          // '<S544>/Integrator'
  real_T Integrator_DSTATE_h;          // '<S97>/Integrator'
  real_T Filter_DSTATE_f;              // '<S92>/Filter'
  real_T Integrator_DSTATE_o;          // '<S147>/Integrator'
  real_T Filter_DSTATE_n;              // '<S142>/Filter'
  real_T Integrator_DSTATE_i;          // '<S197>/Integrator'
  real_T Filter_DSTATE_k;              // '<S192>/Filter'
  real_T Delay_DSTATE;                 // '<S22>/Delay'
  real_T Delay_DSTATE_l[2];            // '<S19>/Delay'
  real_T Delay_DSTATE_n;               // '<S24>/Delay'
  real_T Delay_DSTATE_b;               // '<S25>/Delay'
  real_T Delay_DSTATE_c;               // '<S28>/Delay'
  real_T Delay_DSTATE_d;               // '<S29>/Delay'
  real_T PrevY;                        // '<S53>/Rate Limiter2'
  real_T PrevY_b;                      // '<S53>/Rate Limiter1'
  px4_internal_block_LLA2LocalCoordinatesNED_Quadcopter_Control_T obj_mu;// '<S43>/MATLAB System' 
  int8_T If_ActiveSubsystem;           // '<S16>/If'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S564>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S564>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S564>/If Action Subsystem'
  int8_T PositionAltitudecontroller_SubsysRanBC;
                                      // '<S52>/Position & Altitude controller'
  int8_T Attitudecontroller_SubsysRanBC;// '<S52>/Attitude controller'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S36>/Enabled Subsystem'
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
  int8_T EnabledSubsystem_SubsysRanBC_e;// '<S9>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_d3;// '<S8>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_f;// '<S7>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_a;// '<S6>/Enabled Subsystem'
  DW_MATLABSystem_Quadcopter_ControllerWithNavigation_T MATLABSystem_b;// '<S40>/MATLAB System' 
  DW_MATLABSystem_Quadcopter_ControllerWithNavigation_T MATLABSystem;// '<S40>/MATLAB System' 
};

// Parameters (default storage)
struct P_Quadcopter_ControllerWithNavigation_T_ {
  real_T PIDController_D;              // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S91>/Derivative Gain'

  real_T PIDController1_D;             // Mask Parameter: PIDController1_D
                                          //  Referenced by: '<S141>/Derivative Gain'

  real_T PIDController2_D;             // Mask Parameter: PIDController2_D
                                          //  Referenced by: '<S191>/Derivative Gain'

  real_T PID_Altitude_D;               // Mask Parameter: PID_Altitude_D
                                          //  Referenced by: '<S488>/Derivative Gain'

  real_T PID_vz_D;                     // Mask Parameter: PID_vz_D
                                          //  Referenced by: '<S538>/Derivative Gain'

  real_T PIDController_I;              // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S94>/Integral Gain'

  real_T PIDController1_I;             // Mask Parameter: PIDController1_I
                                          //  Referenced by: '<S144>/Integral Gain'

  real_T PIDController2_I;             // Mask Parameter: PIDController2_I
                                          //  Referenced by: '<S194>/Integral Gain'

  real_T PID_Altitude_I;               // Mask Parameter: PID_Altitude_I
                                          //  Referenced by: '<S491>/Integral Gain'

  real_T PID_vz_I;                     // Mask Parameter: PID_vz_I
                                          //  Referenced by: '<S541>/Integral Gain'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S92>/Filter'

  real_T PIDController1_InitialConditionForFilter;
                     // Mask Parameter: PIDController1_InitialConditionForFilter
                        //  Referenced by: '<S142>/Filter'

  real_T PIDController2_InitialConditionForFilter;
                     // Mask Parameter: PIDController2_InitialConditionForFilter
                        //  Referenced by: '<S192>/Filter'

  real_T PID_Altitude_InitialConditionForFilter;
                       // Mask Parameter: PID_Altitude_InitialConditionForFilter
                          //  Referenced by: '<S489>/Filter'

  real_T PID_vz_InitialConditionForFilter;
                             // Mask Parameter: PID_vz_InitialConditionForFilter
                                //  Referenced by: '<S539>/Filter'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S97>/Integrator'

  real_T PIDController1_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController1_InitialConditionForIntegrator
                    //  Referenced by: '<S147>/Integrator'

  real_T PIDController2_InitialConditionForIntegrator;
                 // Mask Parameter: PIDController2_InitialConditionForIntegrator
                    //  Referenced by: '<S197>/Integrator'

  real_T PID_Altitude_InitialConditionForIntegrator;
                   // Mask Parameter: PID_Altitude_InitialConditionForIntegrator
                      //  Referenced by: '<S494>/Integrator'

  real_T PID_vz_InitialConditionForIntegrator;
                         // Mask Parameter: PID_vz_InitialConditionForIntegrator
                            //  Referenced by: '<S544>/Integrator'

  real_T PIDController5_LowerSaturationLimit;
                          // Mask Parameter: PIDController5_LowerSaturationLimit
                             //  Referenced by: '<S348>/Saturation'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by:
                              //    '<S104>/Saturation'
                              //    '<S90>/DeadZone'

  real_T PIDController1_LowerSaturationLimit;
                          // Mask Parameter: PIDController1_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S154>/Saturation'
                             //    '<S140>/DeadZone'

  real_T PIDController2_LowerSaturationLimit;
                          // Mask Parameter: PIDController2_LowerSaturationLimit
                             //  Referenced by:
                             //    '<S204>/Saturation'
                             //    '<S190>/DeadZone'

  real_T PID_Altitude_LowerSaturationLimit;
                            // Mask Parameter: PID_Altitude_LowerSaturationLimit
                               //  Referenced by:
                               //    '<S501>/Saturation'
                               //    '<S487>/DeadZone'

  real_T PID_vz_LowerSaturationLimit;
                                  // Mask Parameter: PID_vz_LowerSaturationLimit
                                     //  Referenced by:
                                     //    '<S551>/Saturation'
                                     //    '<S537>/DeadZone'

  real_T PIDController1_LowerSaturationLimit_j;
                        // Mask Parameter: PIDController1_LowerSaturationLimit_j
                           //  Referenced by: '<S451>/Saturation'

  real_T PIDController_LowerSaturationLimit_f;
                         // Mask Parameter: PIDController_LowerSaturationLimit_f
                            //  Referenced by: '<S403>/Saturation'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S100>/Filter Coefficient'

  real_T PIDController1_N;             // Mask Parameter: PIDController1_N
                                          //  Referenced by: '<S150>/Filter Coefficient'

  real_T PIDController2_N;             // Mask Parameter: PIDController2_N
                                          //  Referenced by: '<S200>/Filter Coefficient'

  real_T PID_Altitude_N;               // Mask Parameter: PID_Altitude_N
                                          //  Referenced by: '<S497>/Filter Coefficient'

  real_T PID_vz_N;                     // Mask Parameter: PID_vz_N
                                          //  Referenced by: '<S547>/Filter Coefficient'

  real_T PIDController5_P;             // Mask Parameter: PIDController5_P
                                          //  Referenced by: '<S346>/Proportional Gain'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S102>/Proportional Gain'

  real_T PIDController3_P;             // Mask Parameter: PIDController3_P
                                          //  Referenced by: '<S250>/Proportional Gain'

  real_T PIDController1_P;             // Mask Parameter: PIDController1_P
                                          //  Referenced by: '<S152>/Proportional Gain'

  real_T PIDController4_P;             // Mask Parameter: PIDController4_P
                                          //  Referenced by: '<S298>/Proportional Gain'

  real_T PIDController2_P;             // Mask Parameter: PIDController2_P
                                          //  Referenced by: '<S202>/Proportional Gain'

  real_T PID_Altitude_P;               // Mask Parameter: PID_Altitude_P
                                          //  Referenced by: '<S499>/Proportional Gain'

  real_T PID_vz_P;                     // Mask Parameter: PID_vz_P
                                          //  Referenced by: '<S549>/Proportional Gain'

  real_T PIDController1_P_f;           // Mask Parameter: PIDController1_P_f
                                          //  Referenced by: '<S449>/Proportional Gain'

  real_T PIDController_P_n;            // Mask Parameter: PIDController_P_n
                                          //  Referenced by: '<S401>/Proportional Gain'

  real_T PIDController5_UpperSaturationLimit;
                          // Mask Parameter: PIDController5_UpperSaturationLimit
                             //  Referenced by: '<S348>/Saturation'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by:
                              //    '<S104>/Saturation'
                              //    '<S90>/DeadZone'

  real_T PIDController1_UpperSaturationLimit;
                          // Mask Parameter: PIDController1_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S154>/Saturation'
                             //    '<S140>/DeadZone'

  real_T PIDController2_UpperSaturationLimit;
                          // Mask Parameter: PIDController2_UpperSaturationLimit
                             //  Referenced by:
                             //    '<S204>/Saturation'
                             //    '<S190>/DeadZone'

  real_T PID_Altitude_UpperSaturationLimit;
                            // Mask Parameter: PID_Altitude_UpperSaturationLimit
                               //  Referenced by:
                               //    '<S501>/Saturation'
                               //    '<S487>/DeadZone'

  real_T PID_vz_UpperSaturationLimit;
                                  // Mask Parameter: PID_vz_UpperSaturationLimit
                                     //  Referenced by:
                                     //    '<S551>/Saturation'
                                     //    '<S537>/DeadZone'

  real_T PIDController1_UpperSaturationLimit_h;
                        // Mask Parameter: PIDController1_UpperSaturationLimit_h
                           //  Referenced by: '<S451>/Saturation'

  real_T PIDController_UpperSaturationLimit_i;
                         // Mask Parameter: PIDController_UpperSaturationLimit_i
                            //  Referenced by: '<S403>/Saturation'

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

  px4_Bus_vehicle_attitude Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S12>/Out1'

  px4_Bus_vehicle_attitude Constant_Value_l;// Computed Parameter: Constant_Value_l
                                               //  Referenced by: '<S8>/Constant'

  px4_Bus_home_position Out1_Y0_o;     // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S50>/Out1'

  px4_Bus_home_position Constant_Value_b;// Computed Parameter: Constant_Value_b
                                            //  Referenced by: '<S35>/Constant'

  px4_Bus_actuator_armed Out1_Y0_d;    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S11>/Out1'

  px4_Bus_actuator_armed Constant_Value_j;// Computed Parameter: Constant_Value_j
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
                                          //  Referenced by: '<S57>/Switch1'

  real_T tau_Yaw_Y0;                   // Computed Parameter: tau_Yaw_Y0
                                          //  Referenced by: '<S53>/tau_Yaw'

  real_T tau_Pitch_Y0;                 // Computed Parameter: tau_Pitch_Y0
                                          //  Referenced by: '<S53>/tau_Pitch'

  real_T tau_Roll_Y0;                  // Computed Parameter: tau_Roll_Y0
                                          //  Referenced by: '<S53>/tau_Roll'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S88>/Constant1'

  real_T Constant1_Value_e;            // Expression: 0
                                          //  Referenced by: '<S138>/Constant1'

  real_T Constant1_Value_a;            // Expression: 0
                                          //  Referenced by: '<S188>/Constant1'

  real_T Constant_Value_p;             // Expression: 2*pi
                                          //  Referenced by: '<S57>/Constant'

  real_T Switch_Threshold_e;           // Expression: pi
                                          //  Referenced by: '<S57>/Switch'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S97>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S92>/Filter'

  real_T Clamping_zero_Value;          // Expression: 0
                                          //  Referenced by: '<S88>/Clamping_zero'

  real_T RateLimiter2_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S53>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S53>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                          //  Referenced by: '<S53>/Rate Limiter2'

  real_T Saturation1_UpperSat;         // Expression: 20*pi/180
                                          //  Referenced by: '<S53>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -20*pi/180
                                          //  Referenced by: '<S53>/Saturation1'

  real_T Clamping_zero_Value_e;        // Expression: 0
                                          //  Referenced by: '<S138>/Clamping_zero'

  real_T Integrator_gainval_k;       // Computed Parameter: Integrator_gainval_k
                                        //  Referenced by: '<S147>/Integrator'

  real_T Filter_gainval_p;             // Computed Parameter: Filter_gainval_p
                                          //  Referenced by: '<S142>/Filter'

  real_T RateLimiter1_RisingLim;       // Expression: 40*pi/180
                                          //  Referenced by: '<S53>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Expression: -40*pi/180
                                          //  Referenced by: '<S53>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                          //  Referenced by: '<S53>/Rate Limiter1'

  real_T Saturation_UpperSat;          // Expression: 20*pi/180
                                          //  Referenced by: '<S53>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -20*pi/180
                                          //  Referenced by: '<S53>/Saturation'

  real_T Clamping_zero_Value_p;        // Expression: 0
                                          //  Referenced by: '<S188>/Clamping_zero'

  real_T Integrator_gainval_i;       // Computed Parameter: Integrator_gainval_i
                                        //  Referenced by: '<S197>/Integrator'

  real_T Filter_gainval_h;             // Computed Parameter: Filter_gainval_h
                                          //  Referenced by: '<S192>/Filter'

  real_T Constant_Value_j4;            // Expression: 0
                                          //  Referenced by: '<S358>/Constant'

  real_T tau_Thrust_Y0;                // Computed Parameter: tau_Thrust_Y0
                                          //  Referenced by: '<S54>/tau_Thrust'

  real_T des_pitch_Y0;                 // Computed Parameter: des_pitch_Y0
                                          //  Referenced by: '<S54>/des_pitch'

  real_T des_roll_Y0;                  // Computed Parameter: des_roll_Y0
                                          //  Referenced by: '<S54>/des_roll'

  real_T Constant1_Value_f;            // Expression: 0
                                          //  Referenced by: '<S485>/Constant1'

  real_T Constant1_Value_o;            // Expression: 0
                                          //  Referenced by: '<S535>/Constant1'

  real_T Gain1_Gain_o;                 // Expression: -1
                                          //  Referenced by: '<S358>/Gain1'

  real_T Clamping_zero_Value_m;        // Expression: 0
                                          //  Referenced by: '<S485>/Clamping_zero'

  real_T Filter_gainval_g;             // Computed Parameter: Filter_gainval_g
                                          //  Referenced by: '<S489>/Filter'

  real_T Integrator_gainval_a;       // Computed Parameter: Integrator_gainval_a
                                        //  Referenced by: '<S494>/Integrator'

  real_T Clamping_zero_Value_et;       // Expression: 0
                                          //  Referenced by: '<S535>/Clamping_zero'

  real_T Filter_gainval_k;             // Computed Parameter: Filter_gainval_k
                                          //  Referenced by: '<S539>/Filter'

  real_T Integrator_gainval_g;       // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S544>/Integrator'

  real_T Gain_Gain_l2;                 // Expression: -1
                                          //  Referenced by: '<S359>/Gain'

  real_T Gain1_Gain_f;                 // Expression: -1
                                          //  Referenced by: '<S54>/Gain1'

  real_T Constant_Value_im[4];         // Expression: [1 0 0 0]
                                          //  Referenced by: '<S55>/Constant'

  real_T Constant_Value_be;            // Expression: 1
                                          //  Referenced by: '<S565>/Constant'

  real_T Constant_Value_m;             // Expression: 1
                                          //  Referenced by: '<S566>/Constant'

  real_T Gain_Gain_c;                  // Expression: -1
                                          //  Referenced by: '<S52>/Gain'

  real_T Switch_Threshold_l;           // Expression: 0
                                          //  Referenced by: '<S55>/Switch'

  real_T Mixermatrix_Value[16];
                          // Expression: [1 1 -1 1;1 -1 1 1;1 1 1 -1;1 -1 -1 -1]
                             //  Referenced by: '<S5>/Mixer matrix'

  real_T Bias_Bias;                    // Expression: 1
                                          //  Referenced by: '<S5>/Bias'

  real_T Gain1_Gain_p;                 // Expression: 1000
                                          //  Referenced by: '<S5>/Gain1'

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

  real32_T Constant2_Value[3];         // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<S42>/Constant2'

  real32_T Constant3_Value;            // Computed Parameter: Constant3_Value
                                          //  Referenced by: '<S42>/Constant3'

  real32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                          //  Referenced by: '<S42>/Constant4'

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
                                          //  Referenced by: '<S88>/Constant'

  int8_T Constant2_Value_e;            // Computed Parameter: Constant2_Value_e
                                          //  Referenced by: '<S88>/Constant2'

  int8_T Constant3_Value_g;            // Computed Parameter: Constant3_Value_g
                                          //  Referenced by: '<S88>/Constant3'

  int8_T Constant4_Value_j;            // Computed Parameter: Constant4_Value_j
                                          //  Referenced by: '<S88>/Constant4'

  int8_T Constant_Value_h;             // Computed Parameter: Constant_Value_h
                                          //  Referenced by: '<S138>/Constant'

  int8_T Constant2_Value_f;            // Computed Parameter: Constant2_Value_f
                                          //  Referenced by: '<S138>/Constant2'

  int8_T Constant3_Value_c;            // Computed Parameter: Constant3_Value_c
                                          //  Referenced by: '<S138>/Constant3'

  int8_T Constant4_Value_e;            // Computed Parameter: Constant4_Value_e
                                          //  Referenced by: '<S138>/Constant4'

  int8_T Constant_Value_is;            // Computed Parameter: Constant_Value_is
                                          //  Referenced by: '<S188>/Constant'

  int8_T Constant2_Value_a;            // Computed Parameter: Constant2_Value_a
                                          //  Referenced by: '<S188>/Constant2'

  int8_T Constant3_Value_b;            // Computed Parameter: Constant3_Value_b
                                          //  Referenced by: '<S188>/Constant3'

  int8_T Constant4_Value_k;            // Computed Parameter: Constant4_Value_k
                                          //  Referenced by: '<S188>/Constant4'

  int8_T Constant_Value_hk;            // Computed Parameter: Constant_Value_hk
                                          //  Referenced by: '<S485>/Constant'

  int8_T Constant2_Value_l;            // Computed Parameter: Constant2_Value_l
                                          //  Referenced by: '<S485>/Constant2'

  int8_T Constant3_Value_gn;           // Computed Parameter: Constant3_Value_gn
                                          //  Referenced by: '<S485>/Constant3'

  int8_T Constant4_Value_g;            // Computed Parameter: Constant4_Value_g
                                          //  Referenced by: '<S485>/Constant4'

  int8_T Constant_Value_mp;            // Computed Parameter: Constant_Value_mp
                                          //  Referenced by: '<S535>/Constant'

  int8_T Constant2_Value_k;            // Computed Parameter: Constant2_Value_k
                                          //  Referenced by: '<S535>/Constant2'

  int8_T Constant3_Value_i;            // Computed Parameter: Constant3_Value_i
                                          //  Referenced by: '<S535>/Constant3'

  int8_T Constant4_Value_ja;           // Computed Parameter: Constant4_Value_ja
                                          //  Referenced by: '<S535>/Constant4'

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

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void Quadcopter_ControllerWithNavigation_initialize(void);
  extern void Quadcopter_ControllerWithNavigation_step(void);
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
//  Block '<S364>/Data Type Duplicate' : Unused code path elimination
//  Block '<S364>/Data Type Propagation' : Unused code path elimination
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
//  '<S53>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller'
//  '<S54>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller'
//  '<S55>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternion Validity Check'
//  '<S56>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles'
//  '<S57>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/Calculate minimum Turn'
//  '<S58>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller'
//  '<S59>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1'
//  '<S60>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2'
//  '<S61>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3'
//  '<S62>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4'
//  '<S63>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5'
//  '<S64>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Anti-windup'
//  '<S65>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/D Gain'
//  '<S66>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Filter'
//  '<S67>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Filter ICs'
//  '<S68>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/I Gain'
//  '<S69>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Ideal P Gain'
//  '<S70>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S71>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Integrator'
//  '<S72>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Integrator ICs'
//  '<S73>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/N Copy'
//  '<S74>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/N Gain'
//  '<S75>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/P Copy'
//  '<S76>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Parallel P Gain'
//  '<S77>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Reset Signal'
//  '<S78>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Saturation'
//  '<S79>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Saturation Fdbk'
//  '<S80>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Sum'
//  '<S81>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Sum Fdbk'
//  '<S82>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tracking Mode'
//  '<S83>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tracking Mode Sum'
//  '<S84>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tsamp - Integral'
//  '<S85>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tsamp - Ngain'
//  '<S86>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/postSat Signal'
//  '<S87>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/preSat Signal'
//  '<S88>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
//  '<S89>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S90>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S91>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/D Gain/Internal Parameters'
//  '<S92>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S93>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S94>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/I Gain/Internal Parameters'
//  '<S95>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S96>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S97>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Integrator/Discrete'
//  '<S98>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Integrator ICs/Internal IC'
//  '<S99>'  : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/N Copy/Disabled'
//  '<S100>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/N Gain/Internal Parameters'
//  '<S101>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/P Copy/Disabled'
//  '<S102>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S103>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Reset Signal/Disabled'
//  '<S104>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Saturation/Enabled'
//  '<S105>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S106>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Sum/Sum_PID'
//  '<S107>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S108>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S109>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S110>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S111>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S112>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S113>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S114>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Anti-windup'
//  '<S115>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/D Gain'
//  '<S116>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Filter'
//  '<S117>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Filter ICs'
//  '<S118>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/I Gain'
//  '<S119>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Ideal P Gain'
//  '<S120>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S121>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Integrator'
//  '<S122>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Integrator ICs'
//  '<S123>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/N Copy'
//  '<S124>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/N Gain'
//  '<S125>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/P Copy'
//  '<S126>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Parallel P Gain'
//  '<S127>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Reset Signal'
//  '<S128>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Saturation'
//  '<S129>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Saturation Fdbk'
//  '<S130>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Sum'
//  '<S131>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Sum Fdbk'
//  '<S132>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tracking Mode'
//  '<S133>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tracking Mode Sum'
//  '<S134>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tsamp - Integral'
//  '<S135>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tsamp - Ngain'
//  '<S136>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/postSat Signal'
//  '<S137>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/preSat Signal'
//  '<S138>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel'
//  '<S139>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S140>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S141>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/D Gain/Internal Parameters'
//  '<S142>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Filter/Disc. Forward Euler Filter'
//  '<S143>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Filter ICs/Internal IC - Filter'
//  '<S144>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/I Gain/Internal Parameters'
//  '<S145>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S146>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S147>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Integrator/Discrete'
//  '<S148>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Integrator ICs/Internal IC'
//  '<S149>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/N Copy/Disabled'
//  '<S150>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/N Gain/Internal Parameters'
//  '<S151>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/P Copy/Disabled'
//  '<S152>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S153>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S154>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Saturation/Enabled'
//  '<S155>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S156>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Sum/Sum_PID'
//  '<S157>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S158>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S159>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S160>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S161>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S162>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S163>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S164>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Anti-windup'
//  '<S165>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/D Gain'
//  '<S166>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Filter'
//  '<S167>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Filter ICs'
//  '<S168>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/I Gain'
//  '<S169>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Ideal P Gain'
//  '<S170>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Ideal P Gain Fdbk'
//  '<S171>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Integrator'
//  '<S172>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Integrator ICs'
//  '<S173>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/N Copy'
//  '<S174>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/N Gain'
//  '<S175>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/P Copy'
//  '<S176>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Parallel P Gain'
//  '<S177>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Reset Signal'
//  '<S178>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Saturation'
//  '<S179>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Saturation Fdbk'
//  '<S180>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Sum'
//  '<S181>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Sum Fdbk'
//  '<S182>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tracking Mode'
//  '<S183>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tracking Mode Sum'
//  '<S184>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tsamp - Integral'
//  '<S185>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tsamp - Ngain'
//  '<S186>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/postSat Signal'
//  '<S187>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/preSat Signal'
//  '<S188>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel'
//  '<S189>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S190>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S191>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/D Gain/Internal Parameters'
//  '<S192>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Filter/Disc. Forward Euler Filter'
//  '<S193>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Filter ICs/Internal IC - Filter'
//  '<S194>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/I Gain/Internal Parameters'
//  '<S195>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Ideal P Gain/Passthrough'
//  '<S196>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Ideal P Gain Fdbk/Disabled'
//  '<S197>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Integrator/Discrete'
//  '<S198>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Integrator ICs/Internal IC'
//  '<S199>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/N Copy/Disabled'
//  '<S200>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/N Gain/Internal Parameters'
//  '<S201>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/P Copy/Disabled'
//  '<S202>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Parallel P Gain/Internal Parameters'
//  '<S203>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Reset Signal/Disabled'
//  '<S204>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Saturation/Enabled'
//  '<S205>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Saturation Fdbk/Disabled'
//  '<S206>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Sum/Sum_PID'
//  '<S207>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Sum Fdbk/Disabled'
//  '<S208>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tracking Mode/Disabled'
//  '<S209>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tracking Mode Sum/Passthrough'
//  '<S210>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tsamp - Integral/TsSignalSpecification'
//  '<S211>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/Tsamp - Ngain/Passthrough'
//  '<S212>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/postSat Signal/Forward_Path'
//  '<S213>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller2/preSat Signal/Forward_Path'
//  '<S214>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Anti-windup'
//  '<S215>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/D Gain'
//  '<S216>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Filter'
//  '<S217>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Filter ICs'
//  '<S218>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/I Gain'
//  '<S219>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Ideal P Gain'
//  '<S220>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Ideal P Gain Fdbk'
//  '<S221>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Integrator'
//  '<S222>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Integrator ICs'
//  '<S223>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/N Copy'
//  '<S224>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/N Gain'
//  '<S225>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/P Copy'
//  '<S226>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Parallel P Gain'
//  '<S227>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Reset Signal'
//  '<S228>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Saturation'
//  '<S229>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Saturation Fdbk'
//  '<S230>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Sum'
//  '<S231>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Sum Fdbk'
//  '<S232>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tracking Mode'
//  '<S233>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tracking Mode Sum'
//  '<S234>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tsamp - Integral'
//  '<S235>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tsamp - Ngain'
//  '<S236>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/postSat Signal'
//  '<S237>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/preSat Signal'
//  '<S238>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Anti-windup/Disabled'
//  '<S239>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/D Gain/Disabled'
//  '<S240>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Filter/Disabled'
//  '<S241>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Filter ICs/Disabled'
//  '<S242>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/I Gain/Disabled'
//  '<S243>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Ideal P Gain/Passthrough'
//  '<S244>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Ideal P Gain Fdbk/Disabled'
//  '<S245>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Integrator/Disabled'
//  '<S246>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Integrator ICs/Disabled'
//  '<S247>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/N Copy/Disabled wSignal Specification'
//  '<S248>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/N Gain/Disabled'
//  '<S249>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/P Copy/Disabled'
//  '<S250>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Parallel P Gain/Internal Parameters'
//  '<S251>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Reset Signal/Disabled'
//  '<S252>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Saturation/Passthrough'
//  '<S253>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Saturation Fdbk/Disabled'
//  '<S254>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Sum/Passthrough_P'
//  '<S255>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Sum Fdbk/Disabled'
//  '<S256>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tracking Mode/Disabled'
//  '<S257>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tracking Mode Sum/Passthrough'
//  '<S258>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tsamp - Integral/TsSignalSpecification'
//  '<S259>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/Tsamp - Ngain/Passthrough'
//  '<S260>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/postSat Signal/Forward_Path'
//  '<S261>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller3/preSat Signal/Forward_Path'
//  '<S262>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Anti-windup'
//  '<S263>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/D Gain'
//  '<S264>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Filter'
//  '<S265>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Filter ICs'
//  '<S266>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/I Gain'
//  '<S267>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Ideal P Gain'
//  '<S268>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Ideal P Gain Fdbk'
//  '<S269>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Integrator'
//  '<S270>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Integrator ICs'
//  '<S271>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/N Copy'
//  '<S272>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/N Gain'
//  '<S273>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/P Copy'
//  '<S274>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Parallel P Gain'
//  '<S275>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Reset Signal'
//  '<S276>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Saturation'
//  '<S277>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Saturation Fdbk'
//  '<S278>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Sum'
//  '<S279>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Sum Fdbk'
//  '<S280>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tracking Mode'
//  '<S281>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tracking Mode Sum'
//  '<S282>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tsamp - Integral'
//  '<S283>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tsamp - Ngain'
//  '<S284>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/postSat Signal'
//  '<S285>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/preSat Signal'
//  '<S286>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Anti-windup/Disabled'
//  '<S287>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/D Gain/Disabled'
//  '<S288>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Filter/Disabled'
//  '<S289>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Filter ICs/Disabled'
//  '<S290>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/I Gain/Disabled'
//  '<S291>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Ideal P Gain/Passthrough'
//  '<S292>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Ideal P Gain Fdbk/Disabled'
//  '<S293>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Integrator/Disabled'
//  '<S294>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Integrator ICs/Disabled'
//  '<S295>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/N Copy/Disabled wSignal Specification'
//  '<S296>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/N Gain/Disabled'
//  '<S297>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/P Copy/Disabled'
//  '<S298>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Parallel P Gain/Internal Parameters'
//  '<S299>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Reset Signal/Disabled'
//  '<S300>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Saturation/Passthrough'
//  '<S301>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Saturation Fdbk/Disabled'
//  '<S302>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Sum/Passthrough_P'
//  '<S303>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Sum Fdbk/Disabled'
//  '<S304>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tracking Mode/Disabled'
//  '<S305>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tracking Mode Sum/Passthrough'
//  '<S306>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tsamp - Integral/TsSignalSpecification'
//  '<S307>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/Tsamp - Ngain/Passthrough'
//  '<S308>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/postSat Signal/Forward_Path'
//  '<S309>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller4/preSat Signal/Forward_Path'
//  '<S310>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Anti-windup'
//  '<S311>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/D Gain'
//  '<S312>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Filter'
//  '<S313>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Filter ICs'
//  '<S314>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/I Gain'
//  '<S315>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Ideal P Gain'
//  '<S316>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Ideal P Gain Fdbk'
//  '<S317>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Integrator'
//  '<S318>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Integrator ICs'
//  '<S319>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/N Copy'
//  '<S320>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/N Gain'
//  '<S321>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/P Copy'
//  '<S322>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Parallel P Gain'
//  '<S323>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Reset Signal'
//  '<S324>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Saturation'
//  '<S325>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Saturation Fdbk'
//  '<S326>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Sum'
//  '<S327>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Sum Fdbk'
//  '<S328>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tracking Mode'
//  '<S329>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tracking Mode Sum'
//  '<S330>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tsamp - Integral'
//  '<S331>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tsamp - Ngain'
//  '<S332>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/postSat Signal'
//  '<S333>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/preSat Signal'
//  '<S334>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Anti-windup/Disabled'
//  '<S335>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/D Gain/Disabled'
//  '<S336>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Filter/Disabled'
//  '<S337>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Filter ICs/Disabled'
//  '<S338>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/I Gain/Disabled'
//  '<S339>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Ideal P Gain/Passthrough'
//  '<S340>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Ideal P Gain Fdbk/Disabled'
//  '<S341>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Integrator/Disabled'
//  '<S342>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Integrator ICs/Disabled'
//  '<S343>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/N Copy/Disabled wSignal Specification'
//  '<S344>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/N Gain/Disabled'
//  '<S345>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/P Copy/Disabled'
//  '<S346>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Parallel P Gain/Internal Parameters'
//  '<S347>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Reset Signal/Disabled'
//  '<S348>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Saturation/Enabled'
//  '<S349>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Saturation Fdbk/Disabled'
//  '<S350>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Sum/Passthrough_P'
//  '<S351>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Sum Fdbk/Disabled'
//  '<S352>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tracking Mode/Disabled'
//  '<S353>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tracking Mode Sum/Passthrough'
//  '<S354>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tsamp - Integral/TsSignalSpecification'
//  '<S355>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/Tsamp - Ngain/Passthrough'
//  '<S356>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/postSat Signal/Forward_Path'
//  '<S357>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Attitude controller/PID Controller5/preSat Signal/Forward_Path'
//  '<S358>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/Altitude Signal conditioning'
//  '<S359>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/Calculate Transformation Matrix'
//  '<S360>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller'
//  '<S361>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1'
//  '<S362>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude'
//  '<S363>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz'
//  '<S364>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/Altitude Signal conditioning/Saturation Dynamic'
//  '<S365>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Anti-windup'
//  '<S366>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/D Gain'
//  '<S367>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Filter'
//  '<S368>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Filter ICs'
//  '<S369>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/I Gain'
//  '<S370>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Ideal P Gain'
//  '<S371>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk'
//  '<S372>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Integrator'
//  '<S373>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Integrator ICs'
//  '<S374>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/N Copy'
//  '<S375>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/N Gain'
//  '<S376>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/P Copy'
//  '<S377>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Parallel P Gain'
//  '<S378>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Reset Signal'
//  '<S379>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Saturation'
//  '<S380>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Saturation Fdbk'
//  '<S381>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Sum'
//  '<S382>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Sum Fdbk'
//  '<S383>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tracking Mode'
//  '<S384>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tracking Mode Sum'
//  '<S385>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tsamp - Integral'
//  '<S386>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tsamp - Ngain'
//  '<S387>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/postSat Signal'
//  '<S388>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/preSat Signal'
//  '<S389>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Anti-windup/Disabled'
//  '<S390>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/D Gain/Disabled'
//  '<S391>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Filter/Disabled'
//  '<S392>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Filter ICs/Disabled'
//  '<S393>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/I Gain/Disabled'
//  '<S394>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Ideal P Gain/Passthrough'
//  '<S395>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S396>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Integrator/Disabled'
//  '<S397>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Integrator ICs/Disabled'
//  '<S398>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/N Copy/Disabled wSignal Specification'
//  '<S399>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/N Gain/Disabled'
//  '<S400>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/P Copy/Disabled'
//  '<S401>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S402>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Reset Signal/Disabled'
//  '<S403>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Saturation/Enabled'
//  '<S404>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Saturation Fdbk/Disabled'
//  '<S405>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Sum/Passthrough_P'
//  '<S406>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Sum Fdbk/Disabled'
//  '<S407>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tracking Mode/Disabled'
//  '<S408>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S409>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S410>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S411>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/postSat Signal/Forward_Path'
//  '<S412>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller/preSat Signal/Forward_Path'
//  '<S413>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Anti-windup'
//  '<S414>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/D Gain'
//  '<S415>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Filter'
//  '<S416>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Filter ICs'
//  '<S417>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/I Gain'
//  '<S418>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Ideal P Gain'
//  '<S419>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk'
//  '<S420>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Integrator'
//  '<S421>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Integrator ICs'
//  '<S422>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/N Copy'
//  '<S423>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/N Gain'
//  '<S424>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/P Copy'
//  '<S425>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Parallel P Gain'
//  '<S426>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Reset Signal'
//  '<S427>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Saturation'
//  '<S428>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Saturation Fdbk'
//  '<S429>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Sum'
//  '<S430>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Sum Fdbk'
//  '<S431>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tracking Mode'
//  '<S432>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tracking Mode Sum'
//  '<S433>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tsamp - Integral'
//  '<S434>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tsamp - Ngain'
//  '<S435>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/postSat Signal'
//  '<S436>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/preSat Signal'
//  '<S437>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Anti-windup/Disabled'
//  '<S438>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/D Gain/Disabled'
//  '<S439>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Filter/Disabled'
//  '<S440>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Filter ICs/Disabled'
//  '<S441>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/I Gain/Disabled'
//  '<S442>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Ideal P Gain/Passthrough'
//  '<S443>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
//  '<S444>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Integrator/Disabled'
//  '<S445>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Integrator ICs/Disabled'
//  '<S446>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/N Copy/Disabled wSignal Specification'
//  '<S447>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/N Gain/Disabled'
//  '<S448>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/P Copy/Disabled'
//  '<S449>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Parallel P Gain/Internal Parameters'
//  '<S450>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Reset Signal/Disabled'
//  '<S451>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Saturation/Enabled'
//  '<S452>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Saturation Fdbk/Disabled'
//  '<S453>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Sum/Passthrough_P'
//  '<S454>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Sum Fdbk/Disabled'
//  '<S455>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tracking Mode/Disabled'
//  '<S456>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tracking Mode Sum/Passthrough'
//  '<S457>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tsamp - Integral/TsSignalSpecification'
//  '<S458>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/Tsamp - Ngain/Passthrough'
//  '<S459>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/postSat Signal/Forward_Path'
//  '<S460>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID Controller1/preSat Signal/Forward_Path'
//  '<S461>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Anti-windup'
//  '<S462>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/D Gain'
//  '<S463>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Filter'
//  '<S464>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Filter ICs'
//  '<S465>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/I Gain'
//  '<S466>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain'
//  '<S467>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk'
//  '<S468>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Integrator'
//  '<S469>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Integrator ICs'
//  '<S470>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/N Copy'
//  '<S471>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/N Gain'
//  '<S472>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/P Copy'
//  '<S473>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain'
//  '<S474>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Reset Signal'
//  '<S475>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Saturation'
//  '<S476>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk'
//  '<S477>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Sum'
//  '<S478>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk'
//  '<S479>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode'
//  '<S480>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum'
//  '<S481>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral'
//  '<S482>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain'
//  '<S483>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/postSat Signal'
//  '<S484>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/preSat Signal'
//  '<S485>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel'
//  '<S486>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S487>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S488>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/D Gain/Internal Parameters'
//  '<S489>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Filter/Disc. Forward Euler Filter'
//  '<S490>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Filter ICs/Internal IC - Filter'
//  '<S491>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/I Gain/Internal Parameters'
//  '<S492>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain/Passthrough'
//  '<S493>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Ideal P Gain Fdbk/Passthrough'
//  '<S494>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Integrator/Discrete'
//  '<S495>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Integrator ICs/Internal IC'
//  '<S496>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/N Copy/Disabled'
//  '<S497>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/N Gain/Internal Parameters'
//  '<S498>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/P Copy/Disabled'
//  '<S499>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Parallel P Gain/Internal Parameters'
//  '<S500>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Reset Signal/Disabled'
//  '<S501>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Saturation/Enabled'
//  '<S502>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Saturation Fdbk/Passthrough'
//  '<S503>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Sum/Sum_PID'
//  '<S504>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Sum Fdbk/Enabled'
//  '<S505>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode/Disabled'
//  '<S506>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tracking Mode Sum/Passthrough'
//  '<S507>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Integral/TsSignalSpecification'
//  '<S508>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/Tsamp - Ngain/Passthrough'
//  '<S509>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/postSat Signal/Feedback_Path'
//  '<S510>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_Altitude/preSat Signal/Feedback_Path'
//  '<S511>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Anti-windup'
//  '<S512>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/D Gain'
//  '<S513>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Filter'
//  '<S514>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Filter ICs'
//  '<S515>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/I Gain'
//  '<S516>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Ideal P Gain'
//  '<S517>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk'
//  '<S518>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Integrator'
//  '<S519>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Integrator ICs'
//  '<S520>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/N Copy'
//  '<S521>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/N Gain'
//  '<S522>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/P Copy'
//  '<S523>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Parallel P Gain'
//  '<S524>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Reset Signal'
//  '<S525>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Saturation'
//  '<S526>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Saturation Fdbk'
//  '<S527>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Sum'
//  '<S528>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Sum Fdbk'
//  '<S529>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tracking Mode'
//  '<S530>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum'
//  '<S531>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tsamp - Integral'
//  '<S532>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain'
//  '<S533>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/postSat Signal'
//  '<S534>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/preSat Signal'
//  '<S535>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel'
//  '<S536>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone'
//  '<S537>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
//  '<S538>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/D Gain/Internal Parameters'
//  '<S539>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Filter/Disc. Forward Euler Filter'
//  '<S540>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Filter ICs/Internal IC - Filter'
//  '<S541>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/I Gain/Internal Parameters'
//  '<S542>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Ideal P Gain/Passthrough'
//  '<S543>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Ideal P Gain Fdbk/Passthrough'
//  '<S544>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Integrator/Discrete'
//  '<S545>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Integrator ICs/Internal IC'
//  '<S546>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/N Copy/Disabled'
//  '<S547>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/N Gain/Internal Parameters'
//  '<S548>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/P Copy/Disabled'
//  '<S549>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Parallel P Gain/Internal Parameters'
//  '<S550>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Reset Signal/Disabled'
//  '<S551>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Saturation/Enabled'
//  '<S552>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Saturation Fdbk/Passthrough'
//  '<S553>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Sum/Sum_PID'
//  '<S554>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Sum Fdbk/Enabled'
//  '<S555>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tracking Mode/Disabled'
//  '<S556>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tracking Mode Sum/Passthrough'
//  '<S557>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tsamp - Integral/TsSignalSpecification'
//  '<S558>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/Tsamp - Ngain/Passthrough'
//  '<S559>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/postSat Signal/Feedback_Path'
//  '<S560>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Position & Altitude controller/PID_vz/preSat Signal/Feedback_Path'
//  '<S561>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternion Validity Check/Quaternion Norm'
//  '<S562>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Angle Calculation'
//  '<S563>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S564>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S565>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S566>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S567>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S568>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S569>' : 'Quadcopter_ControllerWithNavigation/Position & Rate Controller/Controller/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'

#endif                     // RTW_HEADER_Quadcopter_ControllerWithNavigation_h_

//
// File trailer for generated code.
//
// [EOF]
//
