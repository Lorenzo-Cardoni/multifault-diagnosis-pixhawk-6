//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Quadcopter_ControllerWithNavigation_data.cpp
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
#include "Quadcopter_ControllerWithNavigation.h"

// Block parameters (default storage)
P_Quadcopter_ControllerWithNavigation_T Quadcopter_ControllerWithNavigation_P =
  {
  // Mask Parameter: PIDController_D
  //  Referenced by: '<S91>/Derivative Gain'

  0.0,

  // Mask Parameter: PIDController1_D
  //  Referenced by: '<S141>/Derivative Gain'

  0.0025,

  // Mask Parameter: PIDController2_D
  //  Referenced by: '<S191>/Derivative Gain'

  0.0025,

  // Mask Parameter: PID_Altitude_D
  //  Referenced by: '<S488>/Derivative Gain'

  0.01,

  // Mask Parameter: PID_vz_D
  //  Referenced by: '<S538>/Derivative Gain'

  0.05,

  // Mask Parameter: PIDController_I
  //  Referenced by: '<S94>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController1_I
  //  Referenced by: '<S144>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController2_I
  //  Referenced by: '<S194>/Integral Gain'

  0.0,

  // Mask Parameter: PID_Altitude_I
  //  Referenced by: '<S491>/Integral Gain'

  0.01,

  // Mask Parameter: PID_vz_I
  //  Referenced by: '<S541>/Integral Gain'

  0.1,

  // Mask Parameter: PIDController_InitialConditionForFilter
  //  Referenced by: '<S92>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForFilter
  //  Referenced by: '<S142>/Filter'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForFilter
  //  Referenced by: '<S192>/Filter'

  0.0,

  // Mask Parameter: PID_Altitude_InitialConditionForFilter
  //  Referenced by: '<S489>/Filter'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForFilter
  //  Referenced by: '<S539>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditionForIntegrator
  //  Referenced by: '<S97>/Integrator'

  0.0,

  // Mask Parameter: PIDController1_InitialConditionForIntegrator
  //  Referenced by: '<S147>/Integrator'

  0.0,

  // Mask Parameter: PIDController2_InitialConditionForIntegrator
  //  Referenced by: '<S197>/Integrator'

  0.0,

  // Mask Parameter: PID_Altitude_InitialConditionForIntegrator
  //  Referenced by: '<S494>/Integrator'

  0.0,

  // Mask Parameter: PID_vz_InitialConditionForIntegrator
  //  Referenced by: '<S544>/Integrator'

  0.0,

  // Mask Parameter: PIDController5_LowerSaturationLimit
  //  Referenced by: '<S348>/Saturation'

  -0.87266462599716477,

  // Mask Parameter: PIDController_LowerSaturationLimit
  //  Referenced by:
  //    '<S104>/Saturation'
  //    '<S90>/DeadZone'

  -0.1,

  // Mask Parameter: PIDController1_LowerSaturationLimit
  //  Referenced by:
  //    '<S154>/Saturation'
  //    '<S140>/DeadZone'

  -0.2,

  // Mask Parameter: PIDController2_LowerSaturationLimit
  //  Referenced by:
  //    '<S204>/Saturation'
  //    '<S190>/DeadZone'

  -0.2,

  // Mask Parameter: PID_Altitude_LowerSaturationLimit
  //  Referenced by:
  //    '<S501>/Saturation'
  //    '<S487>/DeadZone'

  -2.0,

  // Mask Parameter: PID_vz_LowerSaturationLimit
  //  Referenced by:
  //    '<S551>/Saturation'
  //    '<S537>/DeadZone'

  0.0,

  // Mask Parameter: PIDController1_LowerSaturationLimit_j
  //  Referenced by: '<S451>/Saturation'

  -4.0,

  // Mask Parameter: PIDController_LowerSaturationLimit_f
  //  Referenced by: '<S403>/Saturation'

  -0.3490658503988659,

  // Mask Parameter: PIDController_N
  //  Referenced by: '<S100>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController1_N
  //  Referenced by: '<S150>/Filter Coefficient'

  50.0,

  // Mask Parameter: PIDController2_N
  //  Referenced by: '<S200>/Filter Coefficient'

  50.0,

  // Mask Parameter: PID_Altitude_N
  //  Referenced by: '<S497>/Filter Coefficient'

  10.0,

  // Mask Parameter: PID_vz_N
  //  Referenced by: '<S547>/Filter Coefficient'

  10.0,

  // Mask Parameter: PIDController5_P
  //  Referenced by: '<S346>/Proportional Gain'

  2.0,

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S102>/Proportional Gain'

  0.2,

  // Mask Parameter: PIDController3_P
  //  Referenced by: '<S250>/Proportional Gain'

  4.0,

  // Mask Parameter: PIDController1_P
  //  Referenced by: '<S152>/Proportional Gain'

  0.035,

  // Mask Parameter: PIDController4_P
  //  Referenced by: '<S298>/Proportional Gain'

  4.0,

  // Mask Parameter: PIDController2_P
  //  Referenced by: '<S202>/Proportional Gain'

  0.035,

  // Mask Parameter: PID_Altitude_P
  //  Referenced by: '<S499>/Proportional Gain'

  1.5,

  // Mask Parameter: PID_vz_P
  //  Referenced by: '<S549>/Proportional Gain'

  0.5,

  // Mask Parameter: PIDController1_P_f
  //  Referenced by: '<S449>/Proportional Gain'

  0.6,

  // Mask Parameter: PIDController_P_n
  //  Referenced by: '<S401>/Proportional Gain'

  0.3,

  // Mask Parameter: PIDController5_UpperSaturationLimit
  //  Referenced by: '<S348>/Saturation'

  0.87266462599716477,

  // Mask Parameter: PIDController_UpperSaturationLimit
  //  Referenced by:
  //    '<S104>/Saturation'
  //    '<S90>/DeadZone'

  0.1,

  // Mask Parameter: PIDController1_UpperSaturationLimit
  //  Referenced by:
  //    '<S154>/Saturation'
  //    '<S140>/DeadZone'

  0.2,

  // Mask Parameter: PIDController2_UpperSaturationLimit
  //  Referenced by:
  //    '<S204>/Saturation'
  //    '<S190>/DeadZone'

  0.2,

  // Mask Parameter: PID_Altitude_UpperSaturationLimit
  //  Referenced by:
  //    '<S501>/Saturation'
  //    '<S487>/DeadZone'

  2.0,

  // Mask Parameter: PID_vz_UpperSaturationLimit
  //  Referenced by:
  //    '<S551>/Saturation'
  //    '<S537>/DeadZone'

  1.0,

  // Mask Parameter: PIDController1_UpperSaturationLimit_h
  //  Referenced by: '<S451>/Saturation'

  4.0,

  // Mask Parameter: PIDController_UpperSaturationLimit_i
  //  Referenced by: '<S403>/Saturation'

  0.3490658503988659,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S32>/Constant'

  5U,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S39>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // type

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // _padding0

    {
      {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      } }
    // waypoints
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S44>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // type

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // _padding0

    {
      {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      } }
    // waypoints
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S38>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // type

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // _padding0

    {
      {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      }, {
        (0ULL),                        // timestamp

        {
          0.0F, 0.0F, 0.0F }
        ,                              // position

        {
          0.0F, 0.0F, 0.0F }
        ,                              // velocity

        {
          0.0F, 0.0F, 0.0F }
        ,                              // acceleration
        0.0F,                          // yaw
        0.0F,                          // yaw_speed
        false,                         // point_valid
        0U,                            // type

        {
          0U, 0U }
        // _padding0
      } }
    // waypoints
  },

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S10>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame
    0U,                                // velocity_frame

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S6>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame
    0U,                                // velocity_frame

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S51>/Out1'

  {
    (0ULL),                            // timestamp

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
    },                                 // previous

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
    },                                 // current

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
    }                                  // next
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S36>/Constant'

  {
    (0ULL),                            // timestamp

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
    },                                 // previous

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
    },                                 // current

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // velocity_valid
      0U,                              // velocity_frame
      false,                           // alt_valid
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      0,                               // landing_gear
      0,                               // loiter_direction
      false,                           // disable_weather_vane

      {
        0U, 0U, 0U, 0U, 0U, 0U }
      // _padding0
    }                                  // next
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S13>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S9>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S12>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S8>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S50>/Out1'

  {
    (0ULL),                            // timestamp
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // yaw
    false,                             // valid_alt
    false,                             // valid_hpos
    false,                             // valid_lpos
    false                              // manual_home
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S35>/Constant'

  {
    (0ULL),                            // timestamp
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // yaw
    false,                             // valid_alt
    false,                             // valid_hpos
    false,                             // valid_lpos
    false                              // manual_home
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S11>/Out1'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    false                              // soft_stop
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S7>/Constant'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    false                              // soft_stop
  },

  // Computed Parameter: yaw_Out_Y0
  //  Referenced by: '<S30>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S28>/Delay'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<S28>/Rate'

  0.01,

  // Expression: -1
  //  Referenced by: '<S28>/Gain1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S28>/Gain'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S29>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S29>/Constant'

  0.0,

  // Computed Parameter: Out_Y0
  //  Referenced by: '<S26>/Out'

  0.0,

  // Expression: -1
  //  Referenced by: '<S24>/Gain'

  -1.0,

  // Computed Parameter: yaw_Out_Y0_f
  //  Referenced by: '<S27>/yaw_Out'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S19>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S24>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/Switch'

  0.0,

  // Expression: 0.02
  //  Referenced by: '<S24>/Rate of descent'

  0.02,

  // Expression: -1
  //  Referenced by: '<S24>/Gain2'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S24>/Gain1'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S25>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S25>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S31>/Constant'

  0.0,

  // Expression: 6
  //  Referenced by: '<S21>/Constant'

  6.0,

  // Computed Parameter: yaw_Out_Y0_p
  //  Referenced by: '<S23>/yaw_Out'

  0.0,

  // Expression: 1
  //  Referenced by: '<S22>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S22>/Constant'

  0.0,

  // Expression: -1
  //  Referenced by: '<S17>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S49>/Read Parameter'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S48>/Read Parameter'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S57>/Switch1'

  0.0,

  // Computed Parameter: tau_Yaw_Y0
  //  Referenced by: '<S53>/tau_Yaw'

  0.0,

  // Computed Parameter: tau_Pitch_Y0
  //  Referenced by: '<S53>/tau_Pitch'

  0.0,

  // Computed Parameter: tau_Roll_Y0
  //  Referenced by: '<S53>/tau_Roll'

  0.0,

  // Expression: 0
  //  Referenced by: '<S88>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S138>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S188>/Constant1'

  0.0,

  // Expression: 2*pi
  //  Referenced by: '<S57>/Constant'

  6.2831853071795862,

  // Expression: pi
  //  Referenced by: '<S57>/Switch'

  3.1415926535897931,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S97>/Integrator'

  0.01,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S92>/Filter'

  0.01,

  // Expression: 0
  //  Referenced by: '<S88>/Clamping_zero'

  0.0,

  // Expression: 40*pi/180
  //  Referenced by: '<S53>/Rate Limiter2'

  0.69813170079773179,

  // Expression: -40*pi/180
  //  Referenced by: '<S53>/Rate Limiter2'

  -0.69813170079773179,

  // Expression: 0
  //  Referenced by: '<S53>/Rate Limiter2'

  0.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S53>/Saturation1'

  0.3490658503988659,

  // Expression: -20*pi/180
  //  Referenced by: '<S53>/Saturation1'

  -0.3490658503988659,

  // Expression: 0
  //  Referenced by: '<S138>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval_k
  //  Referenced by: '<S147>/Integrator'

  0.01,

  // Computed Parameter: Filter_gainval_p
  //  Referenced by: '<S142>/Filter'

  0.01,

  // Expression: 40*pi/180
  //  Referenced by: '<S53>/Rate Limiter1'

  0.69813170079773179,

  // Expression: -40*pi/180
  //  Referenced by: '<S53>/Rate Limiter1'

  -0.69813170079773179,

  // Expression: 0
  //  Referenced by: '<S53>/Rate Limiter1'

  0.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S53>/Saturation'

  0.3490658503988659,

  // Expression: -20*pi/180
  //  Referenced by: '<S53>/Saturation'

  -0.3490658503988659,

  // Expression: 0
  //  Referenced by: '<S188>/Clamping_zero'

  0.0,

  // Computed Parameter: Integrator_gainval_i
  //  Referenced by: '<S197>/Integrator'

  0.01,

  // Computed Parameter: Filter_gainval_h
  //  Referenced by: '<S192>/Filter'

  0.01,

  // Expression: 0
  //  Referenced by: '<S358>/Constant'

  0.0,

  // Computed Parameter: tau_Thrust_Y0
  //  Referenced by: '<S54>/tau_Thrust'

  0.0,

  // Computed Parameter: des_pitch_Y0
  //  Referenced by: '<S54>/des_pitch'

  0.0,

  // Computed Parameter: des_roll_Y0
  //  Referenced by: '<S54>/des_roll'

  0.0,

  // Expression: 0
  //  Referenced by: '<S485>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S535>/Constant1'

  0.0,

  // Expression: -1
  //  Referenced by: '<S358>/Gain1'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S485>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval_g
  //  Referenced by: '<S489>/Filter'

  0.01,

  // Computed Parameter: Integrator_gainval_a
  //  Referenced by: '<S494>/Integrator'

  0.01,

  // Expression: 0
  //  Referenced by: '<S535>/Clamping_zero'

  0.0,

  // Computed Parameter: Filter_gainval_k
  //  Referenced by: '<S539>/Filter'

  0.01,

  // Computed Parameter: Integrator_gainval_g
  //  Referenced by: '<S544>/Integrator'

  0.01,

  // Expression: -1
  //  Referenced by: '<S359>/Gain'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S54>/Gain1'

  -1.0,

  // Expression: [1 0 0 0]
  //  Referenced by: '<S55>/Constant'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S565>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S566>/Constant'

  1.0,

  // Expression: -1
  //  Referenced by: '<S52>/Gain'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S55>/Switch'

  0.0,

  // Expression: [1 1 -1 1;1 -1 1 1;1 1 1 -1;1 -1 -1 -1]
  //  Referenced by: '<S5>/Mixer matrix'

  { 1.0, 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, -1.0, -1.0, 1.0, 1.0, -1.0, 1.0, 1.0,
    -1.0, -1.0 },

  // Expression: 1
  //  Referenced by: '<S5>/Bias'

  1.0,

  // Expression: 1000
  //  Referenced by: '<S5>/Gain1'

  1000.0,

  // Computed Parameter: Constant7_Value
  //  Referenced by: '<S42>/Constant7'

  (0ULL),

  // Computed Parameter: Constant1_Value_d
  //  Referenced by: '<S49>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_f2
  //  Referenced by: '<S49>/Constant'

  0.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S48>/Gain'

  -1.0F,

  // Computed Parameter: Constant1_Value_k
  //  Referenced by: '<S48>/Constant1'

  { 0.0F, 0.0F },

  // Computed Parameter: Constant_Value_l4
  //  Referenced by: '<S48>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_fh
  //  Referenced by: '<S42>/Constant'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant1_Value_h
  //  Referenced by: '<S42>/Constant1'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<S42>/Constant2'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant3_Value
  //  Referenced by: '<S42>/Constant3'

  0.0F,

  // Computed Parameter: Constant4_Value
  //  Referenced by: '<S42>/Constant4'

  0.0F,

  // Computed Parameter: Saturation_UpperSat_g
  //  Referenced by: '<S5>/Saturation'

  2000U,

  // Computed Parameter: Saturation_LowerSat_j
  //  Referenced by: '<S5>/Saturation'

  1000U,

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<S40>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_k
  //  Referenced by: '<S41>/Constant5'

  true,

  // Computed Parameter: Constant1_Value_dl
  //  Referenced by: '<S43>/Constant1'

  true,

  // Computed Parameter: Constant5_Value_h
  //  Referenced by: '<S43>/Constant5'

  true,

  // Computed Parameter: Constant5_Value_l
  //  Referenced by: '<S42>/Constant5'

  false,

  // Expression: false
  //  Referenced by: '<S5>/Constant1'

  false,

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S88>/Constant'

  1,

  // Computed Parameter: Constant2_Value_e
  //  Referenced by: '<S88>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_g
  //  Referenced by: '<S88>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_j
  //  Referenced by: '<S88>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S138>/Constant'

  1,

  // Computed Parameter: Constant2_Value_f
  //  Referenced by: '<S138>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_c
  //  Referenced by: '<S138>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_e
  //  Referenced by: '<S138>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_is
  //  Referenced by: '<S188>/Constant'

  1,

  // Computed Parameter: Constant2_Value_a
  //  Referenced by: '<S188>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_b
  //  Referenced by: '<S188>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_k
  //  Referenced by: '<S188>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_hk
  //  Referenced by: '<S485>/Constant'

  1,

  // Computed Parameter: Constant2_Value_l
  //  Referenced by: '<S485>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_gn
  //  Referenced by: '<S485>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_g
  //  Referenced by: '<S485>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_mp
  //  Referenced by: '<S535>/Constant'

  1,

  // Computed Parameter: Constant2_Value_k
  //  Referenced by: '<S535>/Constant2'

  -1,

  // Computed Parameter: Constant3_Value_i
  //  Referenced by: '<S535>/Constant3'

  1,

  // Computed Parameter: Constant4_Value_ja
  //  Referenced by: '<S535>/Constant4'

  -1,

  // Computed Parameter: Constant_Value_fm
  //  Referenced by: '<S34>/Constant'

  0U,

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S42>/Constant6'

  255U
};

//
// File trailer for generated code.
//
// [EOF]
//
