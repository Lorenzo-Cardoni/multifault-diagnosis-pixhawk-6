//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Quadcopter_ControllerWithNavigation_private.h
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
#ifndef RTW_HEADER_Quadcopter_ControllerWithNavigation_private_h_
#define RTW_HEADER_Quadcopter_ControllerWithNavigation_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Quadcopter_ControllerWithNavigation.h"
#include "Quadcopter_ControllerWithNavigation_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void Quadcopter_ControllerWithNavigation_MATLABSystem_Init
  (DW_MATLABSystem_Quadcopter_ControllerWithNavigation_T *localDW);
extern void Quadcopter_ControllerWithNavigation_MATLABSystem(const real_T rtu_0
  [3], const real_T rtu_1[3], boolean_T rtu_2, uint8_T rtu_3,
  B_MATLABSystem_Quadcopter_ControllerWithNavigation_T *localB);
extern void Quadcopter_ControllerWithNavigation_MATLABSystem_Term
  (DW_MATLABSystem_Quadcopter_ControllerWithNavigation_T *localDW);

#endif             // RTW_HEADER_Quadcopter_ControllerWithNavigation_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
