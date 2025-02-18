//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Quadcopter_ControllerWithNavigation.cpp
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
#include "Quadcopter_ControllerWithNavigation.h"
#include "rtwtypes.h"
#include "Quadcopter_ControllerWithNavigation_types.h"
#include "Quadcopter_ControllerWithNavigation_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rt_defines.h"
#include <float.h>

// Named constants for MATLAB Function: '<S55>/MATLAB Function2'
const int32_T Quadcopter_ControllerWithNavigation_CALL_EVENT = -1;

// Named constants for MATLAB Function: '<S56>/MATLAB Function'
const int32_T Quadcopter_ControllerWithNavigation_CALL_EVENT_e = -1;

// Named constants for MATLAB Function: '<S58>/MATLAB Function'
const int32_T Quadcopter_ControllerWithNavigation_CALL_EVENT_l = -1;
const real_T Quadcopter_ControllerWithNavigation_period = 0.01;

// Block signals (default storage)
B_Quadcopter_ControllerWithNavigation_T Quadcopter_ControllerWithNavigation_B;

// Block states (default storage)
DW_Quadcopter_ControllerWithNavigation_T Quadcopter_ControllerWithNavigation_DW;

// Real-time model
RT_MODEL_Quadcopter_ControllerWithNavigation_T
  Quadcopter_ControllerWithNavigation_M_ =
  RT_MODEL_Quadcopter_ControllerWithNavigation_T();
RT_MODEL_Quadcopter_ControllerWithNavigation_T *const
  Quadcopter_ControllerWithNavigation_M =
  &Quadcopter_ControllerWithNavigation_M_;

// Forward declaration for local functions
static real_T Quadcopter_ControllerWithNavigation_sind(real_T x);

// Forward declaration for local functions
static real_T Quadcopter_ControllerWithNavigation_rt_remd_snf(real_T u0, real_T
  u1);
static real_T Quadcopter_ControllerWithNavigation_sind_l(real_T x);
static real_T Quadcopter_ControllerWithNavigation_rt_atan2d_snf(real_T u0,
  real_T u1);
static void Quadcopter_ControllerWithNavigation_lla2ned(const real_T lla[3],
  const real_T lla0[3], real_T xyzNED[3]);
static real_T Quadcopter_ControllerWithNavigation_norm(const real_T x[3]);
static real_T Quadcopter_ControllerWithNavigation_std(const real_T x[130]);
static real_T Quadcopter_ControllerWithNavigation_maximum(const real_T x[130]);
static void Quadcopter_Cont_FFTImplementationCallback_doHalfLengthBluestein(
  const real_T x[130], int32_T xoffInit, creal_T y[130], const creal_T wwc[129],
  const real_T costabinv[257], const real_T sintabinv[257]);
static real_T Quadcopter_ControllerWithNavigation_trapz(const real_T x[99],
  const real_T y[99]);
static void Quadcopter_ControllerWithNavigation_SystemCore_setup
  (px4_internal_block_PWM_Quadcopter_ControllerWithNavigation_T *obj, boolean_T
   varargin_1, boolean_T varargin_2);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void Quadcopter_ControllerWithNavigation_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(Quadcopter_ControllerWithNavigation_M,
    1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Quadcopter_ControllerWithNavigation_M,
    2));
}

//
//         This function updates active task flag for each subrate
//         and rate transition flags for tasks that exchange data.
//         The function assumes rate-monotonic multitasking scheduler.
//         The function must be called at model base rate so that
//         the generated code self-manages all its subrates and rate
//         transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (Quadcopter_ControllerWithNavigation_M->Timing.TaskCounters.TID[1])++;
  if ((Quadcopter_ControllerWithNavigation_M->Timing.TaskCounters.TID[1]) > 1) {// Sample time: [0.01s, 0.0s] 
    Quadcopter_ControllerWithNavigation_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Quadcopter_ControllerWithNavigation_M->Timing.TaskCounters.TID[2])++;
  if ((Quadcopter_ControllerWithNavigation_M->Timing.TaskCounters.TID[2]) > 2) {// Sample time: [0.015s, 0.0s] 
    Quadcopter_ControllerWithNavigation_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    real_T q;
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

static real_T Quadcopter_ControllerWithNavigation_sind(real_T x)
{
  real_T absx;
  real_T b_x;

  // Start for MATLABSystem: '<S40>/MATLAB System'
  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = rt_remd_snf(x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x = sin(0.017453292519943295 * b_x);
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = cos((b_x - 90.0) * 0.017453292519943295);
      } else {
        b_x = -cos((b_x + 90.0) * 0.017453292519943295);
      }
    } else {
      if (b_x > 0.0) {
        b_x = (b_x - 180.0) * 0.017453292519943295;
      } else {
        b_x = (b_x + 180.0) * 0.017453292519943295;
      }

      b_x = -sin(b_x);
    }
  }

  // End of Start for MATLABSystem: '<S40>/MATLAB System'
  return b_x;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// System initialize for atomic system:
void Quadcopter_ControllerWithNavigation_MATLABSystem_Init
  (DW_MATLABSystem_Quadcopter_ControllerWithNavigation_T *localDW)
{
  // Start for MATLABSystem: '<S40>/MATLAB System'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Quadcopter_ControllerWithNavigation_MATLABSystem(const real_T rtu_0[3],
  const real_T rtu_1[3], boolean_T rtu_2, uint8_T rtu_3,
  B_MATLABSystem_Quadcopter_ControllerWithNavigation_T *localB)
{
  real_T Rn_tmp;
  real_T absx;
  real_T dLon;
  real_T flat;
  real_T u;
  int32_T b_k;
  boolean_T b[3];
  boolean_T exitg1;
  boolean_T latp2;

  // MATLABSystem: '<S40>/MATLAB System'
  if (rtu_2 && (rtu_3 != 5)) {
    localB->dLat = rtu_0[0] - rtu_1[0];
    dLon = rtu_0[1] - rtu_1[1];
    flat = fabs(localB->dLat);
    if (flat > 180.0) {
      if (rtIsNaN(localB->dLat + 180.0) || rtIsInf(localB->dLat + 180.0)) {
        flat = (rtNaN);
      } else if (localB->dLat + 180.0 == 0.0) {
        flat = 0.0;
      } else {
        flat = fmod(localB->dLat + 180.0, 360.0);
        if (flat == 0.0) {
          flat = 0.0;
        } else if (localB->dLat + 180.0 < 0.0) {
          flat += 360.0;
        }
      }

      localB->dLat = localB->dLat * 0.0 + (flat - 180.0);
      flat = fabs(localB->dLat);
    }

    if (flat > 90.0) {
      flat = fabs(localB->dLat);
      latp2 = (flat > 90.0);
      dLon += 180.0;
      u = localB->dLat * static_cast<real_T>(latp2);
      if (rtIsNaN(u)) {
        u = (rtNaN);
      } else if (u < 0.0) {
        u = -1.0;
      } else {
        u = (u > 0.0);
      }

      localB->dLat = (90.0 - (flat * static_cast<real_T>(latp2) - 90.0)) * u *
        static_cast<real_T>(latp2) + localB->dLat * static_cast<real_T>(!latp2);
    }

    if ((dLon > 180.0) || (dLon < -180.0)) {
      flat = rt_remd_snf(dLon, 360.0);
      u = flat / 180.0;
      if (u < 0.0) {
        u = ceil(u);
      } else {
        u = floor(u);
      }

      dLon = (flat - 360.0 * u) + dLon * 0.0;
    }

    flat = Quadcopter_ControllerWithNavigation_sind(rtu_1[0]);
    Rn_tmp = 1.0 - 0.0066943799901413165 * flat * flat;
    flat = 6.378137E+6 / sqrt(Rn_tmp);
    if (rtIsInf(rtu_1[0]) || rtIsNaN(rtu_1[0])) {
      u = (rtNaN);
    } else {
      u = rt_remd_snf(rtu_1[0], 360.0);
      absx = fabs(u);
      if (absx > 180.0) {
        if (u > 0.0) {
          u -= 360.0;
        } else {
          u += 360.0;
        }

        absx = fabs(u);
      }

      if (absx <= 45.0) {
        u = cos(0.017453292519943295 * u);
      } else if (absx <= 135.0) {
        if (u > 0.0) {
          u = -sin((u - 90.0) * 0.017453292519943295);
        } else {
          u = sin((u + 90.0) * 0.017453292519943295);
        }
      } else {
        if (u > 0.0) {
          u = (u - 180.0) * 0.017453292519943295;
        } else {
          u = (u + 180.0) * 0.017453292519943295;
        }

        u = -cos(u);
      }
    }

    localB->dLat /= rt_atan2d_snf(1.0, 0.99330562000985867 / Rn_tmp * flat) *
      57.295779513082323;
    dLon /= rt_atan2d_snf(1.0, flat * u) * 57.295779513082323;
    flat = -rtu_0[2] + rtu_1[2];
    b[0] = rtIsNaN(localB->dLat);
    b[1] = rtIsNaN(dLon);
    b[2] = rtIsNaN(flat);
    latp2 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 3)) {
      if (b[b_k]) {
        latp2 = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }

    u = 0.0 / static_cast<real_T>(!latp2);
    localB->MATLABSystem[0] = static_cast<real32_T>(u + localB->dLat);
    localB->MATLABSystem[1] = static_cast<real32_T>(u + dLon);
    localB->MATLABSystem[2] = static_cast<real32_T>(u + flat);
  } else {
    localB->MATLABSystem[0] = 0.0F;
    localB->MATLABSystem[1] = 0.0F;
    localB->MATLABSystem[2] = 0.0F;
  }

  // End of MATLABSystem: '<S40>/MATLAB System'
}

// Termination for atomic system:
void Quadcopter_ControllerWithNavigation_MATLABSystem_Term
  (DW_MATLABSystem_Quadcopter_ControllerWithNavigation_T *localDW)
{
  // Terminate for MATLABSystem: '<S40>/MATLAB System'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S40>/MATLAB System'
}

//
// System initialize for atomic system:
//    '<S55>/MATLAB Function2'
//    '<S56>/MATLAB Function2'
//    '<S57>/MATLAB Function2'
//    '<S58>/MATLAB Function2'
//    '<S59>/MATLAB Function2'
//
void Quadcopter_ControllerWithNavigation_MATLABFunction2_Init
  (DW_MATLABFunction2_Quadcopter_ControllerWithNavigation_T *localDW)
{
  localDW->sfEvent = Quadcopter_ControllerWithNavigation_CALL_EVENT;
}

//
// Output and update for atomic system:
//    '<S55>/MATLAB Function2'
//    '<S56>/MATLAB Function2'
//    '<S57>/MATLAB Function2'
//    '<S58>/MATLAB Function2'
//    '<S59>/MATLAB Function2'
//
void Quadcopter_ControllerWithNavigation_MATLABFunction2(const real_T
  rtu_buffer[130], real_T rtu_k, real_T rty_orderedBuffer[130],
  DW_MATLABFunction2_Quadcopter_ControllerWithNavigation_T *localDW)
{
  real_T k;
  localDW->sfEvent = Quadcopter_ControllerWithNavigation_CALL_EVENT;
  k = rtu_k;
  for (int32_T i = 0; i < 130; i++) {
    real_T r;
    rty_orderedBuffer[i] = rtu_buffer[static_cast<int32_T>(k) - 1];
    if (rtIsNaN(k)) {
      r = (rtNaN);
    } else if (rtIsInf(k)) {
      r = (rtNaN);
    } else if (k == 0.0) {
      r = 0.0;
    } else {
      r = fmod(k, 130.0);
      if (r == 0.0) {
        r = 0.0;
      } else if (k < 0.0) {
        r += 130.0;
      }
    }

    k = r + 1.0;
  }
}

//
// System initialize for atomic system:
//    '<S56>/MATLAB Function'
//    '<S57>/MATLAB Function'
//
void Quadcopter_ControllerWithNavigation_MATLABFunction_Init
  (DW_MATLABFunction_Quadcopter_ControllerWithNavigation_T *localDW)
{
  localDW->sfEvent = Quadcopter_ControllerWithNavigation_CALL_EVENT_e;
}

//
// Output and update for atomic system:
//    '<S56>/MATLAB Function'
//    '<S57>/MATLAB Function'
//
void Quadcopter_ControllerWithNavigation_MATLABFunction(int32_T rtu_newValue,
  real_T rtu_bufferSize, real_T rty_buffer[130], real_T *rty_k,
  DW_MATLABFunction_Quadcopter_ControllerWithNavigation_T *localDW)
{
  real_T r;
  localDW->sfEvent = Quadcopter_ControllerWithNavigation_CALL_EVENT_e;
  rty_buffer[static_cast<int32_T>(*rty_k) - 1] = rtu_newValue;
  r = *rty_k;
  if (rtu_bufferSize == 0.0) {
    if (*rty_k == 0.0) {
      r = rtu_bufferSize;
    }
  } else if (rtIsNaN(*rty_k)) {
    r = (rtNaN);
  } else if (rtIsNaN(rtu_bufferSize)) {
    r = (rtNaN);
  } else if (rtIsInf(*rty_k)) {
    r = (rtNaN);
  } else if (*rty_k == 0.0) {
    r = 0.0 / rtu_bufferSize;
  } else if (rtIsInf(rtu_bufferSize)) {
    if ((rtu_bufferSize < 0.0) != (*rty_k < 0.0)) {
      r = rtu_bufferSize;
    }
  } else {
    boolean_T rEQ0;
    r = fmod(*rty_k, rtu_bufferSize);
    rEQ0 = (r == 0.0);
    if ((!rEQ0) && (rtu_bufferSize > floor(rtu_bufferSize))) {
      real_T q;
      q = fabs(*rty_k / rtu_bufferSize);
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = rtu_bufferSize * 0.0;
    } else if ((*rty_k < 0.0) != (rtu_bufferSize < 0.0)) {
      r += rtu_bufferSize;
    }
  }

  *rty_k = r + 1.0;
}

//
// System initialize for atomic system:
//    '<S58>/MATLAB Function'
//    '<S59>/MATLAB Function'
//
void Quadcopter_ControllerWithNavigation_MATLABFunction_m_Init
  (DW_MATLABFunction_Quadcopter_ControllerWithNavigation_g_T *localDW)
{
  localDW->sfEvent = Quadcopter_ControllerWithNavigation_CALL_EVENT_l;
}

//
// Output and update for atomic system:
//    '<S58>/MATLAB Function'
//    '<S59>/MATLAB Function'
//
void Quadcopter_ControllerWithNavigation_MATLABFunction_i(real32_T rtu_newValue,
  real_T rtu_bufferSize, real_T rty_buffer[130], real_T *rty_k,
  DW_MATLABFunction_Quadcopter_ControllerWithNavigation_g_T *localDW)
{
  real_T r;
  localDW->sfEvent = Quadcopter_ControllerWithNavigation_CALL_EVENT_l;
  rty_buffer[static_cast<int32_T>(*rty_k) - 1] = rtu_newValue;
  r = *rty_k;
  if (rtu_bufferSize == 0.0) {
    if (*rty_k == 0.0) {
      r = rtu_bufferSize;
    }
  } else if (rtIsNaN(*rty_k)) {
    r = (rtNaN);
  } else if (rtIsNaN(rtu_bufferSize)) {
    r = (rtNaN);
  } else if (rtIsInf(*rty_k)) {
    r = (rtNaN);
  } else if (*rty_k == 0.0) {
    r = 0.0 / rtu_bufferSize;
  } else if (rtIsInf(rtu_bufferSize)) {
    if ((rtu_bufferSize < 0.0) != (*rty_k < 0.0)) {
      r = rtu_bufferSize;
    }
  } else {
    boolean_T rEQ0;
    r = fmod(*rty_k, rtu_bufferSize);
    rEQ0 = (r == 0.0);
    if ((!rEQ0) && (rtu_bufferSize > floor(rtu_bufferSize))) {
      real_T q;
      q = fabs(*rty_k / rtu_bufferSize);
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = rtu_bufferSize * 0.0;
    } else if ((*rty_k < 0.0) != (rtu_bufferSize < 0.0)) {
      r += rtu_bufferSize;
    }
  }

  *rty_k = r + 1.0;
}

static real_T Quadcopter_ControllerWithNavigation_rt_remd_snf(real_T u0, real_T
  u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      Quadcopter_ControllerWithNavigation_B.q_l = ceil(u1);
    } else {
      Quadcopter_ControllerWithNavigation_B.q_l = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != Quadcopter_ControllerWithNavigation_B.q_l)) {
      Quadcopter_ControllerWithNavigation_B.q_l = fabs(u0 / u1);
      if (!(fabs(Quadcopter_ControllerWithNavigation_B.q_l - floor
                 (Quadcopter_ControllerWithNavigation_B.q_l + 0.5)) >
            DBL_EPSILON * Quadcopter_ControllerWithNavigation_B.q_l)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

static real_T Quadcopter_ControllerWithNavigation_sind_l(real_T x)
{
  real_T b_x;

  // Start for MATLABSystem: '<S17>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S43>/MATLAB System'

  if (rtIsInf(x) || rtIsNaN(x)) {
    b_x = (rtNaN);
  } else {
    b_x = Quadcopter_ControllerWithNavigation_rt_remd_snf(x, 360.0);
    Quadcopter_ControllerWithNavigation_B.absx_g = fabs(b_x);
    if (Quadcopter_ControllerWithNavigation_B.absx_g > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      Quadcopter_ControllerWithNavigation_B.absx_g = fabs(b_x);
    }

    if (Quadcopter_ControllerWithNavigation_B.absx_g <= 45.0) {
      b_x = sin(0.017453292519943295 * b_x);
    } else if (Quadcopter_ControllerWithNavigation_B.absx_g <= 135.0) {
      if (b_x > 0.0) {
        b_x = cos((b_x - 90.0) * 0.017453292519943295);
      } else {
        b_x = -cos((b_x + 90.0) * 0.017453292519943295);
      }
    } else {
      if (b_x > 0.0) {
        b_x = (b_x - 180.0) * 0.017453292519943295;
      } else {
        b_x = (b_x + 180.0) * 0.017453292519943295;
      }

      b_x = -sin(b_x);
    }
  }

  // End of Start for MATLABSystem: '<S17>/LLA2LocalCoordinates'
  return b_x;
}

static real_T Quadcopter_ControllerWithNavigation_rt_atan2d_snf(real_T u0,
  real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      Quadcopter_ControllerWithNavigation_B.i = 1;
    } else {
      Quadcopter_ControllerWithNavigation_B.i = -1;
    }

    if (u1 > 0.0) {
      Quadcopter_ControllerWithNavigation_B.i1_b = 1;
    } else {
      Quadcopter_ControllerWithNavigation_B.i1_b = -1;
    }

    y = atan2(static_cast<real_T>(Quadcopter_ControllerWithNavigation_B.i),
              static_cast<real_T>(Quadcopter_ControllerWithNavigation_B.i1_b));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void Quadcopter_ControllerWithNavigation_lla2ned(const real_T lla[3],
  const real_T lla0[3], real_T xyzNED[3])
{
  boolean_T exitg1;

  // Start for MATLABSystem: '<S17>/LLA2LocalCoordinates'
  Quadcopter_ControllerWithNavigation_B.dLat = lla[0] - lla0[0];
  Quadcopter_ControllerWithNavigation_B.dLon = lla[1] - lla0[1];
  Quadcopter_ControllerWithNavigation_B.flat = fabs
    (Quadcopter_ControllerWithNavigation_B.dLat);
  if (Quadcopter_ControllerWithNavigation_B.flat > 180.0) {
    // Start for MATLABSystem: '<S17>/LLA2LocalCoordinates'
    if (rtIsNaN(Quadcopter_ControllerWithNavigation_B.dLat + 180.0) || rtIsInf
        (Quadcopter_ControllerWithNavigation_B.dLat + 180.0)) {
      Quadcopter_ControllerWithNavigation_B.flat = (rtNaN);
    } else if (Quadcopter_ControllerWithNavigation_B.dLat + 180.0 == 0.0) {
      Quadcopter_ControllerWithNavigation_B.flat = 0.0;
    } else {
      Quadcopter_ControllerWithNavigation_B.flat = fmod
        (Quadcopter_ControllerWithNavigation_B.dLat + 180.0, 360.0);
      if (Quadcopter_ControllerWithNavigation_B.flat == 0.0) {
        Quadcopter_ControllerWithNavigation_B.flat = 0.0;
      } else if (Quadcopter_ControllerWithNavigation_B.dLat + 180.0 < 0.0) {
        Quadcopter_ControllerWithNavigation_B.flat += 360.0;
      }
    }

    Quadcopter_ControllerWithNavigation_B.dLat =
      Quadcopter_ControllerWithNavigation_B.dLat * 0.0 +
      (Quadcopter_ControllerWithNavigation_B.flat - 180.0);
    Quadcopter_ControllerWithNavigation_B.flat = fabs
      (Quadcopter_ControllerWithNavigation_B.dLat);
  }

  if (Quadcopter_ControllerWithNavigation_B.flat > 90.0) {
    // Start for MATLABSystem: '<S17>/LLA2LocalCoordinates'
    Quadcopter_ControllerWithNavigation_B.flat = fabs
      (Quadcopter_ControllerWithNavigation_B.dLat);
    Quadcopter_ControllerWithNavigation_B.latp2_l =
      (Quadcopter_ControllerWithNavigation_B.flat > 90.0);

    // Start for MATLABSystem: '<S17>/LLA2LocalCoordinates'
    Quadcopter_ControllerWithNavigation_B.dLon += 180.0;
    Quadcopter_ControllerWithNavigation_B.Rn =
      Quadcopter_ControllerWithNavigation_B.dLat * static_cast<real_T>
      (Quadcopter_ControllerWithNavigation_B.latp2_l);
    if (rtIsNaN(Quadcopter_ControllerWithNavigation_B.Rn)) {
      Quadcopter_ControllerWithNavigation_B.Rn = (rtNaN);
    } else if (Quadcopter_ControllerWithNavigation_B.Rn < 0.0) {
      Quadcopter_ControllerWithNavigation_B.Rn = -1.0;
    } else {
      Quadcopter_ControllerWithNavigation_B.Rn =
        (Quadcopter_ControllerWithNavigation_B.Rn > 0.0);
    }

    Quadcopter_ControllerWithNavigation_B.dLat = (90.0 -
      (Quadcopter_ControllerWithNavigation_B.flat * static_cast<real_T>
       (Quadcopter_ControllerWithNavigation_B.latp2_l) - 90.0)) *
      Quadcopter_ControllerWithNavigation_B.Rn * static_cast<real_T>
      (Quadcopter_ControllerWithNavigation_B.latp2_l) +
      Quadcopter_ControllerWithNavigation_B.dLat * static_cast<real_T>
      (!Quadcopter_ControllerWithNavigation_B.latp2_l);
  }

  // Start for MATLABSystem: '<S17>/LLA2LocalCoordinates'
  if ((Quadcopter_ControllerWithNavigation_B.dLon > 180.0) ||
      (Quadcopter_ControllerWithNavigation_B.dLon < -180.0)) {
    Quadcopter_ControllerWithNavigation_B.flat =
      Quadcopter_ControllerWithNavigation_rt_remd_snf
      (Quadcopter_ControllerWithNavigation_B.dLon, 360.0);
    Quadcopter_ControllerWithNavigation_B.Rn =
      Quadcopter_ControllerWithNavigation_B.flat / 180.0;
    if (Quadcopter_ControllerWithNavigation_B.Rn < 0.0) {
      Quadcopter_ControllerWithNavigation_B.Rn = ceil
        (Quadcopter_ControllerWithNavigation_B.Rn);
    } else {
      Quadcopter_ControllerWithNavigation_B.Rn = floor
        (Quadcopter_ControllerWithNavigation_B.Rn);
    }

    Quadcopter_ControllerWithNavigation_B.dLon =
      (Quadcopter_ControllerWithNavigation_B.flat - 360.0 *
       Quadcopter_ControllerWithNavigation_B.Rn) +
      Quadcopter_ControllerWithNavigation_B.dLon * 0.0;
  }

  Quadcopter_ControllerWithNavigation_B.flat =
    Quadcopter_ControllerWithNavigation_sind_l(lla0[0]);
  Quadcopter_ControllerWithNavigation_B.flat = 1.0 - 0.0066943799901413165 *
    Quadcopter_ControllerWithNavigation_B.flat *
    Quadcopter_ControllerWithNavigation_B.flat;
  Quadcopter_ControllerWithNavigation_B.Rn = 6.378137E+6 / sqrt
    (Quadcopter_ControllerWithNavigation_B.flat);
  if (rtIsInf(lla0[0]) || rtIsNaN(lla0[0])) {
    Quadcopter_ControllerWithNavigation_B.b_x_d = (rtNaN);
  } else {
    Quadcopter_ControllerWithNavigation_B.b_x_d =
      Quadcopter_ControllerWithNavigation_rt_remd_snf(lla0[0], 360.0);
    Quadcopter_ControllerWithNavigation_B.absx = fabs
      (Quadcopter_ControllerWithNavigation_B.b_x_d);
    if (Quadcopter_ControllerWithNavigation_B.absx > 180.0) {
      if (Quadcopter_ControllerWithNavigation_B.b_x_d > 0.0) {
        Quadcopter_ControllerWithNavigation_B.b_x_d -= 360.0;
      } else {
        Quadcopter_ControllerWithNavigation_B.b_x_d += 360.0;
      }

      Quadcopter_ControllerWithNavigation_B.absx = fabs
        (Quadcopter_ControllerWithNavigation_B.b_x_d);
    }

    if (Quadcopter_ControllerWithNavigation_B.absx <= 45.0) {
      Quadcopter_ControllerWithNavigation_B.b_x_d = cos(0.017453292519943295 *
        Quadcopter_ControllerWithNavigation_B.b_x_d);
    } else if (Quadcopter_ControllerWithNavigation_B.absx <= 135.0) {
      if (Quadcopter_ControllerWithNavigation_B.b_x_d > 0.0) {
        Quadcopter_ControllerWithNavigation_B.b_x_d = -sin
          ((Quadcopter_ControllerWithNavigation_B.b_x_d - 90.0) *
           0.017453292519943295);
      } else {
        Quadcopter_ControllerWithNavigation_B.b_x_d = sin
          ((Quadcopter_ControllerWithNavigation_B.b_x_d + 90.0) *
           0.017453292519943295);
      }
    } else {
      if (Quadcopter_ControllerWithNavigation_B.b_x_d > 0.0) {
        Quadcopter_ControllerWithNavigation_B.b_x_d =
          (Quadcopter_ControllerWithNavigation_B.b_x_d - 180.0) *
          0.017453292519943295;
      } else {
        Quadcopter_ControllerWithNavigation_B.b_x_d =
          (Quadcopter_ControllerWithNavigation_B.b_x_d + 180.0) *
          0.017453292519943295;
      }

      Quadcopter_ControllerWithNavigation_B.b_x_d = -cos
        (Quadcopter_ControllerWithNavigation_B.b_x_d);
    }
  }

  xyzNED[0] = Quadcopter_ControllerWithNavigation_B.dLat /
    (Quadcopter_ControllerWithNavigation_rt_atan2d_snf(1.0, 0.99330562000985867 /
      Quadcopter_ControllerWithNavigation_B.flat *
      Quadcopter_ControllerWithNavigation_B.Rn) * 57.295779513082323);
  xyzNED[1] = Quadcopter_ControllerWithNavigation_B.dLon /
    (Quadcopter_ControllerWithNavigation_rt_atan2d_snf(1.0,
      Quadcopter_ControllerWithNavigation_B.Rn *
      Quadcopter_ControllerWithNavigation_B.b_x_d) * 57.295779513082323);
  xyzNED[2] = -lla[2] + lla0[2];
  Quadcopter_ControllerWithNavigation_B.b_n[0] = rtIsNaN(xyzNED[0]);
  Quadcopter_ControllerWithNavigation_B.b_n[1] = rtIsNaN(xyzNED[1]);
  Quadcopter_ControllerWithNavigation_B.b_n[2] = rtIsNaN(xyzNED[2]);
  Quadcopter_ControllerWithNavigation_B.latp2_l = false;
  Quadcopter_ControllerWithNavigation_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (Quadcopter_ControllerWithNavigation_B.b_k < 3)) {
    if (Quadcopter_ControllerWithNavigation_B.b_n[Quadcopter_ControllerWithNavigation_B.b_k])
    {
      Quadcopter_ControllerWithNavigation_B.latp2_l = true;
      exitg1 = true;
    } else {
      Quadcopter_ControllerWithNavigation_B.b_k++;
    }
  }

  // Start for MATLABSystem: '<S17>/LLA2LocalCoordinates'
  Quadcopter_ControllerWithNavigation_B.dLat = 0.0 / static_cast<real_T>
    (!Quadcopter_ControllerWithNavigation_B.latp2_l);
  xyzNED[0] += Quadcopter_ControllerWithNavigation_B.dLat;
  xyzNED[1] += Quadcopter_ControllerWithNavigation_B.dLat;
  xyzNED[2] += Quadcopter_ControllerWithNavigation_B.dLat;
}

static real_T Quadcopter_ControllerWithNavigation_norm(const real_T x[3])
{
  real_T y;
  Quadcopter_ControllerWithNavigation_B.scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S21>/UAV Waypoint Follower'
  Quadcopter_ControllerWithNavigation_B.absxk = fabs(x[0]);
  if (Quadcopter_ControllerWithNavigation_B.absxk > 3.3121686421112381E-170) {
    y = 1.0;
    Quadcopter_ControllerWithNavigation_B.scale =
      Quadcopter_ControllerWithNavigation_B.absxk;
  } else {
    Quadcopter_ControllerWithNavigation_B.t =
      Quadcopter_ControllerWithNavigation_B.absxk / 3.3121686421112381E-170;
    y = Quadcopter_ControllerWithNavigation_B.t *
      Quadcopter_ControllerWithNavigation_B.t;
  }

  // Start for MATLABSystem: '<S21>/UAV Waypoint Follower'
  Quadcopter_ControllerWithNavigation_B.absxk = fabs(x[1]);
  if (Quadcopter_ControllerWithNavigation_B.absxk >
      Quadcopter_ControllerWithNavigation_B.scale) {
    Quadcopter_ControllerWithNavigation_B.t =
      Quadcopter_ControllerWithNavigation_B.scale /
      Quadcopter_ControllerWithNavigation_B.absxk;
    y = y * Quadcopter_ControllerWithNavigation_B.t *
      Quadcopter_ControllerWithNavigation_B.t + 1.0;
    Quadcopter_ControllerWithNavigation_B.scale =
      Quadcopter_ControllerWithNavigation_B.absxk;
  } else {
    Quadcopter_ControllerWithNavigation_B.t =
      Quadcopter_ControllerWithNavigation_B.absxk /
      Quadcopter_ControllerWithNavigation_B.scale;
    y += Quadcopter_ControllerWithNavigation_B.t *
      Quadcopter_ControllerWithNavigation_B.t;
  }

  // Start for MATLABSystem: '<S21>/UAV Waypoint Follower'
  Quadcopter_ControllerWithNavigation_B.absxk = fabs(x[2]);
  if (Quadcopter_ControllerWithNavigation_B.absxk >
      Quadcopter_ControllerWithNavigation_B.scale) {
    Quadcopter_ControllerWithNavigation_B.t =
      Quadcopter_ControllerWithNavigation_B.scale /
      Quadcopter_ControllerWithNavigation_B.absxk;
    y = y * Quadcopter_ControllerWithNavigation_B.t *
      Quadcopter_ControllerWithNavigation_B.t + 1.0;
    Quadcopter_ControllerWithNavigation_B.scale =
      Quadcopter_ControllerWithNavigation_B.absxk;
  } else {
    Quadcopter_ControllerWithNavigation_B.t =
      Quadcopter_ControllerWithNavigation_B.absxk /
      Quadcopter_ControllerWithNavigation_B.scale;
    y += Quadcopter_ControllerWithNavigation_B.t *
      Quadcopter_ControllerWithNavigation_B.t;
  }

  return Quadcopter_ControllerWithNavigation_B.scale * sqrt(y);
}

// Function for MATLAB Function: '<S52>/MATLAB Function1'
static real_T Quadcopter_ControllerWithNavigation_std(const real_T x[130])
{
  real_T scale;
  real_T xbar;
  real_T y;
  xbar = x[0];
  for (int32_T c_k = 0; c_k < 129; c_k++) {
    xbar += x[c_k + 1];
  }

  xbar /= 130.0;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (int32_T c_k = 0; c_k < 130; c_k++) {
    real_T absdiff;
    absdiff = fabs(x[c_k] - xbar);
    if (absdiff > scale) {
      real_T t;
      t = scale / absdiff;
      y = y * t * t + 1.0;
      scale = absdiff;
    } else {
      real_T t;
      t = absdiff / scale;
      y += t * t;
    }
  }

  y = scale * sqrt(y);
  y /= 11.357816691600547;
  return y;
}

// Function for MATLAB Function: '<S52>/MATLAB Function1'
static real_T Quadcopter_ControllerWithNavigation_maximum(const real_T x[130])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 131)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 131; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S52>/MATLAB Function1'
static void Quadcopter_Cont_FFTImplementationCallback_doHalfLengthBluestein(
  const real_T x[130], int32_T xoffInit, creal_T y[130], const creal_T wwc[129],
  const real_T costabinv[257], const real_T sintabinv[257])
{
  int32_T b_k;
  int32_T c_ihi;
  int32_T c_istart;
  int32_T i;
  int32_T iheight;
  int32_T iy;
  int32_T j_i;
  int32_T ju;
  boolean_T tst;
  static const real_T b[257] = { 1.0, 0.9999247018391445, 0.99969881869620425,
    0.99932238458834954, 0.99879545620517241, 0.99811811290014918,
    0.99729045667869021, 0.996312612182778, 0.99518472667219693,
    0.99390697000235606, 0.99247953459871, 0.99090263542778, 0.989176509964781,
    0.98730141815785843, 0.98527764238894122, 0.98310548743121629,
    0.98078528040323043, 0.97831737071962765, 0.97570213003852857,
    0.97293995220556018, 0.970031253194544, 0.96697647104485207,
    0.96377606579543984, 0.96043051941556579, 0.95694033573220882,
    0.95330604035419386, 0.94952818059303667, 0.94560732538052128,
    0.94154406518302081, 0.937339011912575, 0.932992798834739,
    0.92850608047321559, 0.92387953251128674, 0.91911385169005777,
    0.91420975570353069, 0.90916798309052238, 0.90398929312344334,
    0.89867446569395382, 0.89322430119551532, 0.88763962040285393,
    0.881921264348355, 0.8760700941954066, 0.87008699110871146,
    0.8639728561215867, 0.85772861000027212, 0.8513551931052652,
    0.84485356524970712, 0.83822470555483808, 0.83146961230254524,
    0.82458930278502529, 0.81758481315158371, 0.81045719825259477,
    0.80320753148064494, 0.79583690460888357, 0.78834642762660634,
    0.78073722857209449, 0.773010453362737, 0.765167265622459,
    0.75720884650648457, 0.74913639452345937, 0.74095112535495922,
    0.73265427167241282, 0.724247082951467, 0.71573082528381859,
    0.70710678118654757, 0.69837624940897292, 0.68954054473706683,
    0.680600997795453, 0.67155895484701833, 0.66241577759017178,
    0.65317284295377676, 0.64383154288979139, 0.63439328416364549,
    0.62485948814238634, 0.61523159058062682, 0.60551104140432555,
    0.59569930449243336, 0.58579785745643886, 0.57580819141784534,
    0.56573181078361312, 0.55557023301960218, 0.54532498842204646,
    0.53499761988709715, 0.524589682678469, 0.51410274419322166,
    0.50353838372571758, 0.49289819222978404, 0.48218377207912272,
    0.47139673682599764, 0.46053871095824, 0.44961132965460654,
    0.43861623853852766, 0.42755509343028208, 0.41642956009763715,
    0.40524131400498986, 0.3939920400610481, 0.38268343236508978,
    0.37131719395183749, 0.35989503653498811, 0.34841868024943456,
    0.33688985339222005, 0.32531029216226293, 0.31368174039889152,
    0.30200594931922808, 0.29028467725446233, 0.27851968938505306,
    0.26671275747489837, 0.25486565960451457, 0.24298017990326387,
    0.23105810828067111, 0.2191012401568698, 0.20711137619221856,
    0.19509032201612825, 0.18303988795514095, 0.17096188876030122,
    0.15885814333386145, 0.14673047445536175, 0.13458070850712617,
    0.1224106751992162, 0.11022220729388306, 0.0980171403295606,
    0.0857973123444399, 0.073564563599667426, 0.061320736302208578,
    0.049067674327418015, 0.036807222941358832, 0.024541228522912288,
    0.012271538285719925, 0.0, -0.012271538285719925, -0.024541228522912288,
    -0.036807222941358832, -0.049067674327418015, -0.061320736302208578,
    -0.073564563599667426, -0.0857973123444399, -0.0980171403295606,
    -0.11022220729388306, -0.1224106751992162, -0.13458070850712617,
    -0.14673047445536175, -0.15885814333386145, -0.17096188876030122,
    -0.18303988795514095, -0.19509032201612825, -0.20711137619221856,
    -0.2191012401568698, -0.23105810828067111, -0.24298017990326387,
    -0.25486565960451457, -0.26671275747489837, -0.27851968938505306,
    -0.29028467725446233, -0.30200594931922808, -0.31368174039889152,
    -0.32531029216226293, -0.33688985339222005, -0.34841868024943456,
    -0.35989503653498811, -0.37131719395183749, -0.38268343236508978,
    -0.3939920400610481, -0.40524131400498986, -0.41642956009763715,
    -0.42755509343028208, -0.43861623853852766, -0.44961132965460654,
    -0.46053871095824, -0.47139673682599764, -0.48218377207912272,
    -0.49289819222978404, -0.50353838372571758, -0.51410274419322166,
    -0.524589682678469, -0.53499761988709715, -0.54532498842204646,
    -0.55557023301960218, -0.56573181078361312, -0.57580819141784534,
    -0.58579785745643886, -0.59569930449243336, -0.60551104140432555,
    -0.61523159058062682, -0.62485948814238634, -0.63439328416364549,
    -0.64383154288979139, -0.65317284295377676, -0.66241577759017178,
    -0.67155895484701833, -0.680600997795453, -0.68954054473706683,
    -0.69837624940897292, -0.70710678118654757, -0.71573082528381859,
    -0.724247082951467, -0.73265427167241282, -0.74095112535495922,
    -0.74913639452345937, -0.75720884650648457, -0.765167265622459,
    -0.773010453362737, -0.78073722857209449, -0.78834642762660634,
    -0.79583690460888357, -0.80320753148064494, -0.81045719825259477,
    -0.81758481315158371, -0.82458930278502529, -0.83146961230254524,
    -0.83822470555483808, -0.84485356524970712, -0.8513551931052652,
    -0.85772861000027212, -0.8639728561215867, -0.87008699110871146,
    -0.8760700941954066, -0.881921264348355, -0.88763962040285393,
    -0.89322430119551532, -0.89867446569395382, -0.90398929312344334,
    -0.90916798309052238, -0.91420975570353069, -0.91911385169005777,
    -0.92387953251128674, -0.92850608047321559, -0.932992798834739,
    -0.937339011912575, -0.94154406518302081, -0.94560732538052128,
    -0.94952818059303667, -0.95330604035419386, -0.95694033573220882,
    -0.96043051941556579, -0.96377606579543984, -0.96697647104485207,
    -0.970031253194544, -0.97293995220556018, -0.97570213003852857,
    -0.97831737071962765, -0.98078528040323043, -0.98310548743121629,
    -0.98527764238894122, -0.98730141815785843, -0.989176509964781,
    -0.99090263542778, -0.99247953459871, -0.99390697000235606,
    -0.99518472667219693, -0.996312612182778, -0.99729045667869021,
    -0.99811811290014918, -0.99879545620517241, -0.99932238458834954,
    -0.99969881869620425, -0.9999247018391445, -1.0 };

  static const real_T c[257] = { 0.0, -0.012271538285719925,
    -0.024541228522912288, -0.036807222941358832, -0.049067674327418015,
    -0.061320736302208578, -0.073564563599667426, -0.0857973123444399,
    -0.0980171403295606, -0.11022220729388306, -0.1224106751992162,
    -0.13458070850712617, -0.14673047445536175, -0.15885814333386145,
    -0.17096188876030122, -0.18303988795514095, -0.19509032201612825,
    -0.20711137619221856, -0.2191012401568698, -0.23105810828067111,
    -0.24298017990326387, -0.25486565960451457, -0.26671275747489837,
    -0.27851968938505306, -0.29028467725446233, -0.30200594931922808,
    -0.31368174039889152, -0.32531029216226293, -0.33688985339222005,
    -0.34841868024943456, -0.35989503653498811, -0.37131719395183749,
    -0.38268343236508978, -0.3939920400610481, -0.40524131400498986,
    -0.41642956009763715, -0.42755509343028208, -0.43861623853852766,
    -0.44961132965460654, -0.46053871095824, -0.47139673682599764,
    -0.48218377207912272, -0.49289819222978404, -0.50353838372571758,
    -0.51410274419322166, -0.524589682678469, -0.53499761988709715,
    -0.54532498842204646, -0.55557023301960218, -0.56573181078361312,
    -0.57580819141784534, -0.58579785745643886, -0.59569930449243336,
    -0.60551104140432555, -0.61523159058062682, -0.62485948814238634,
    -0.63439328416364549, -0.64383154288979139, -0.65317284295377676,
    -0.66241577759017178, -0.67155895484701833, -0.680600997795453,
    -0.68954054473706683, -0.69837624940897292, -0.70710678118654757,
    -0.71573082528381859, -0.724247082951467, -0.73265427167241282,
    -0.74095112535495922, -0.74913639452345937, -0.75720884650648457,
    -0.765167265622459, -0.773010453362737, -0.78073722857209449,
    -0.78834642762660634, -0.79583690460888357, -0.80320753148064494,
    -0.81045719825259477, -0.81758481315158371, -0.82458930278502529,
    -0.83146961230254524, -0.83822470555483808, -0.84485356524970712,
    -0.8513551931052652, -0.85772861000027212, -0.8639728561215867,
    -0.87008699110871146, -0.8760700941954066, -0.881921264348355,
    -0.88763962040285393, -0.89322430119551532, -0.89867446569395382,
    -0.90398929312344334, -0.90916798309052238, -0.91420975570353069,
    -0.91911385169005777, -0.92387953251128674, -0.92850608047321559,
    -0.932992798834739, -0.937339011912575, -0.94154406518302081,
    -0.94560732538052128, -0.94952818059303667, -0.95330604035419386,
    -0.95694033573220882, -0.96043051941556579, -0.96377606579543984,
    -0.96697647104485207, -0.970031253194544, -0.97293995220556018,
    -0.97570213003852857, -0.97831737071962765, -0.98078528040323043,
    -0.98310548743121629, -0.98527764238894122, -0.98730141815785843,
    -0.989176509964781, -0.99090263542778, -0.99247953459871,
    -0.99390697000235606, -0.99518472667219693, -0.996312612182778,
    -0.99729045667869021, -0.99811811290014918, -0.99879545620517241,
    -0.99932238458834954, -0.99969881869620425, -0.9999247018391445, -1.0,
    -0.9999247018391445, -0.99969881869620425, -0.99932238458834954,
    -0.99879545620517241, -0.99811811290014918, -0.99729045667869021,
    -0.996312612182778, -0.99518472667219693, -0.99390697000235606,
    -0.99247953459871, -0.99090263542778, -0.989176509964781,
    -0.98730141815785843, -0.98527764238894122, -0.98310548743121629,
    -0.98078528040323043, -0.97831737071962765, -0.97570213003852857,
    -0.97293995220556018, -0.970031253194544, -0.96697647104485207,
    -0.96377606579543984, -0.96043051941556579, -0.95694033573220882,
    -0.95330604035419386, -0.94952818059303667, -0.94560732538052128,
    -0.94154406518302081, -0.937339011912575, -0.932992798834739,
    -0.92850608047321559, -0.92387953251128674, -0.91911385169005777,
    -0.91420975570353069, -0.90916798309052238, -0.90398929312344334,
    -0.89867446569395382, -0.89322430119551532, -0.88763962040285393,
    -0.881921264348355, -0.8760700941954066, -0.87008699110871146,
    -0.8639728561215867, -0.85772861000027212, -0.8513551931052652,
    -0.84485356524970712, -0.83822470555483808, -0.83146961230254524,
    -0.82458930278502529, -0.81758481315158371, -0.81045719825259477,
    -0.80320753148064494, -0.79583690460888357, -0.78834642762660634,
    -0.78073722857209449, -0.773010453362737, -0.765167265622459,
    -0.75720884650648457, -0.74913639452345937, -0.74095112535495922,
    -0.73265427167241282, -0.724247082951467, -0.71573082528381859,
    -0.70710678118654757, -0.69837624940897292, -0.68954054473706683,
    -0.680600997795453, -0.67155895484701833, -0.66241577759017178,
    -0.65317284295377676, -0.64383154288979139, -0.63439328416364549,
    -0.62485948814238634, -0.61523159058062682, -0.60551104140432555,
    -0.59569930449243336, -0.58579785745643886, -0.57580819141784534,
    -0.56573181078361312, -0.55557023301960218, -0.54532498842204646,
    -0.53499761988709715, -0.524589682678469, -0.51410274419322166,
    -0.50353838372571758, -0.49289819222978404, -0.48218377207912272,
    -0.47139673682599764, -0.46053871095824, -0.44961132965460654,
    -0.43861623853852766, -0.42755509343028208, -0.41642956009763715,
    -0.40524131400498986, -0.3939920400610481, -0.38268343236508978,
    -0.37131719395183749, -0.35989503653498811, -0.34841868024943456,
    -0.33688985339222005, -0.32531029216226293, -0.31368174039889152,
    -0.30200594931922808, -0.29028467725446233, -0.27851968938505306,
    -0.26671275747489837, -0.25486565960451457, -0.24298017990326387,
    -0.23105810828067111, -0.2191012401568698, -0.20711137619221856,
    -0.19509032201612825, -0.18303988795514095, -0.17096188876030122,
    -0.15885814333386145, -0.14673047445536175, -0.13458070850712617,
    -0.1224106751992162, -0.11022220729388306, -0.0980171403295606,
    -0.0857973123444399, -0.073564563599667426, -0.061320736302208578,
    -0.049067674327418015, -0.036807222941358832, -0.024541228522912288,
    -0.012271538285719925, -0.0 };

  static const creal_T reconVar1[65] = { { 1.0,// re
      -1.0                             // im
    }, { 0.95168662047449293,          // re
      -0.99883222683232664             // im
    }, { 0.90348607908548484,          // re
      -0.99533163471764863             // im
    }, { 0.85551095043077874,          // re
      -0.98950639945105112             // im
    }, { 0.80787328264629166,          // re
      -0.98137012613941343             // im
    }, { 0.76068433571244221,          // re
      -0.970941817426052               // im
    }, { 0.71405432160131077,          // re
      -0.95824582910916623             // im
    }, { 0.66809214687147156,          // re
      -0.94331181325774316             // im
    }, { 0.62290515831167959,          // re
      -0.92617464895777657             // im
    }, { 0.578598892227471,            // re
      -0.9068743608505454              // im
    }, { 0.53527682795623144,          // re
      -0.88545602565320991             // im
    }, { 0.49304014618640968,          // re
      -0.86196966688004928             // im
    }, { 0.45198749264533,             // re
      -0.83647013801022674             // im
    }, { 0.41221474770752686,          // re
      -0.80901699437494745             // im
    }, { 0.37381480246168641,          // re
      -0.7796743540632225              // im
    }, { 0.33687734175920481,          // re
      -0.74851074817110119             // im
    }, { 0.301488634751063,            // re
      -0.7155989607441211              // im
    }, { 0.26773133340222643,          // re
      -0.68101585878679716             // im
    }, { 0.23568427945415171,          // re
      -0.64484221273617059             // im
    }, { 0.20542232028624563,          // re
      -0.60716250781871117             // im
    }, { 0.17701613410634354,          // re
      -0.5680647467311557              // im
    }, { 0.15053206487847892,          // re
      -0.52764024410613275             // im
    }, { 0.126031967373482,            // re
      -0.48598341324260608             // im
    }, { 0.10357306270429623,          // re
      -0.44319154559924129             // im
    }, { 0.0832078046834176,           // re
      -0.39936458356569554             // im
    }, { 0.064983757314585167,         // re
      -0.35460488704253557             // im
    }, { 0.048943483704846469,         // re
      -0.3090169943749474              // im
    }, { 0.035124446656448538,         // re
      -0.26270737819858692             // im
    }, { 0.023558921170727887,         // re
      -0.21578419676780614             // im
    }, { 0.014273919068349072,         // re
      -0.16835704134703852             // im
    }, { 0.0072911259019460273,        // re
      -0.12053668025532305             // im
    }, { 0.0026268503085088435,        // re
      -0.072434800161762361            // im
    }, { 0.00029198591980705846,       // re
      -0.024163745236132288            // im
    }, { 0.00029198591980705846,       // re
      0.024163745236132288             // im
    }, { 0.0026268503085088435,        // re
      0.072434800161762361             // im
    }, { 0.0072911259019460273,        // re
      0.12053668025532305              // im
    }, { 0.014273919068349072,         // re
      0.16835704134703852              // im
    }, { 0.023558921170727887,         // re
      0.21578419676780614              // im
    }, { 0.035124446656448538,         // re
      0.26270737819858692              // im
    }, { 0.048943483704846469,         // re
      0.3090169943749474               // im
    }, { 0.064983757314585167,         // re
      0.35460488704253557              // im
    }, { 0.0832078046834176,           // re
      0.39936458356569554              // im
    }, { 0.10357306270429623,          // re
      0.44319154559924129              // im
    }, { 0.126031967373482,            // re
      0.48598341324260608              // im
    }, { 0.15053206487847892,          // re
      0.52764024410613275              // im
    }, { 0.17701613410634354,          // re
      0.5680647467311557               // im
    }, { 0.20542232028624563,          // re
      0.60716250781871117              // im
    }, { 0.23568427945415171,          // re
      0.64484221273617059              // im
    }, { 0.26773133340222643,          // re
      0.68101585878679716              // im
    }, { 0.301488634751063,            // re
      0.7155989607441211               // im
    }, { 0.33687734175920481,          // re
      0.74851074817110119              // im
    }, { 0.37381480246168641,          // re
      0.7796743540632225               // im
    }, { 0.41221474770752686,          // re
      0.80901699437494745              // im
    }, { 0.45198749264533,             // re
      0.83647013801022674              // im
    }, { 0.49304014618640968,          // re
      0.86196966688004928              // im
    }, { 0.53527682795623144,          // re
      0.88545602565320991              // im
    }, { 0.578598892227471,            // re
      0.9068743608505454               // im
    }, { 0.62290515831167959,          // re
      0.92617464895777657              // im
    }, { 0.66809214687147156,          // re
      0.94331181325774316              // im
    }, { 0.71405432160131077,          // re
      0.95824582910916623              // im
    }, { 0.76068433571244221,          // re
      0.970941817426052                // im
    }, { 0.80787328264629166,          // re
      0.98137012613941343              // im
    }, { 0.85551095043077874,          // re
      0.98950639945105112              // im
    }, { 0.90348607908548484,          // re
      0.99533163471764863              // im
    }, { 0.95168662047449293,          // re
      0.99883222683232664              // im
    } };

  static const int8_T d_0[65] = { 1, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55,
    54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36,
    35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17,
    16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 };

  static const creal_T reconVar2[65] = { { 1.0,// re
      1.0                              // im
    }, { 1.0483133795255071,           // re
      0.99883222683232664              // im
    }, { 1.0965139209145152,           // re
      0.99533163471764863              // im
    }, { 1.1444890495692213,           // re
      0.98950639945105112              // im
    }, { 1.1921267173537085,           // re
      0.98137012613941343              // im
    }, { 1.2393156642875578,           // re
      0.970941817426052                // im
    }, { 1.2859456783986891,           // re
      0.95824582910916623              // im
    }, { 1.3319078531285284,           // re
      0.94331181325774316              // im
    }, { 1.3770948416883204,           // re
      0.92617464895777657              // im
    }, { 1.421401107772529,            // re
      0.9068743608505454               // im
    }, { 1.4647231720437686,           // re
      0.88545602565320991              // im
    }, { 1.5069598538135902,           // re
      0.86196966688004928              // im
    }, { 1.54801250735467,             // re
      0.83647013801022674              // im
    }, { 1.5877852522924731,           // re
      0.80901699437494745              // im
    }, { 1.6261851975383137,           // re
      0.7796743540632225               // im
    }, { 1.6631226582407952,           // re
      0.74851074817110119              // im
    }, { 1.698511365248937,            // re
      0.7155989607441211               // im
    }, { 1.7322686665977736,           // re
      0.68101585878679716              // im
    }, { 1.7643157205458482,           // re
      0.64484221273617059              // im
    }, { 1.7945776797137545,           // re
      0.60716250781871117              // im
    }, { 1.8229838658936566,           // re
      0.5680647467311557               // im
    }, { 1.8494679351215211,           // re
      0.52764024410613275              // im
    }, { 1.873968032626518,            // re
      0.48598341324260608              // im
    }, { 1.8964269372957037,           // re
      0.44319154559924129              // im
    }, { 1.9167921953165825,           // re
      0.39936458356569554              // im
    }, { 1.9350162426854149,           // re
      0.35460488704253557              // im
    }, { 1.9510565162951536,           // re
      0.3090169943749474               // im
    }, { 1.9648755533435516,           // re
      0.26270737819858692              // im
    }, { 1.9764410788292721,           // re
      0.21578419676780614              // im
    }, { 1.9857260809316508,           // re
      0.16835704134703852              // im
    }, { 1.9927088740980539,           // re
      0.12053668025532305              // im
    }, { 1.9973731496914913,           // re
      0.072434800161762361             // im
    }, { 1.9997080140801931,           // re
      0.024163745236132288             // im
    }, { 1.9997080140801931,           // re
      -0.024163745236132288            // im
    }, { 1.9973731496914913,           // re
      -0.072434800161762361            // im
    }, { 1.9927088740980539,           // re
      -0.12053668025532305             // im
    }, { 1.9857260809316508,           // re
      -0.16835704134703852             // im
    }, { 1.9764410788292721,           // re
      -0.21578419676780614             // im
    }, { 1.9648755533435516,           // re
      -0.26270737819858692             // im
    }, { 1.9510565162951536,           // re
      -0.3090169943749474              // im
    }, { 1.9350162426854149,           // re
      -0.35460488704253557             // im
    }, { 1.9167921953165825,           // re
      -0.39936458356569554             // im
    }, { 1.8964269372957037,           // re
      -0.44319154559924129             // im
    }, { 1.873968032626518,            // re
      -0.48598341324260608             // im
    }, { 1.8494679351215211,           // re
      -0.52764024410613275             // im
    }, { 1.8229838658936566,           // re
      -0.5680647467311557              // im
    }, { 1.7945776797137545,           // re
      -0.60716250781871117             // im
    }, { 1.7643157205458482,           // re
      -0.64484221273617059             // im
    }, { 1.7322686665977736,           // re
      -0.68101585878679716             // im
    }, { 1.698511365248937,            // re
      -0.7155989607441211              // im
    }, { 1.6631226582407952,           // re
      -0.74851074817110119             // im
    }, { 1.6261851975383137,           // re
      -0.7796743540632225              // im
    }, { 1.5877852522924731,           // re
      -0.80901699437494745             // im
    }, { 1.54801250735467,             // re
      -0.83647013801022674             // im
    }, { 1.5069598538135902,           // re
      -0.86196966688004928             // im
    }, { 1.4647231720437686,           // re
      -0.88545602565320991             // im
    }, { 1.421401107772529,            // re
      -0.9068743608505454              // im
    }, { 1.3770948416883204,           // re
      -0.92617464895777657             // im
    }, { 1.3319078531285284,           // re
      -0.94331181325774316             // im
    }, { 1.2859456783986891,           // re
      -0.95824582910916623             // im
    }, { 1.2393156642875578,           // re
      -0.970941817426052               // im
    }, { 1.1921267173537085,           // re
      -0.98137012613941343             // im
    }, { 1.1444890495692213,           // re
      -0.98950639945105112             // im
    }, { 1.0965139209145152,           // re
      -0.99533163471764863             // im
    }, { 1.0483133795255071,           // re
      -0.99883222683232664             // im
    } };

  for (i = 0; i < 128; i++) {
    ju = ((i + 1) << 1) - 2;
    Quadcopter_ControllerWithNavigation_B.hcostab[i] = b[ju];
    Quadcopter_ControllerWithNavigation_B.hsintab[i] = c[ju];
    Quadcopter_ControllerWithNavigation_B.hcostabinv[i] = costabinv[ju];
    Quadcopter_ControllerWithNavigation_B.hsintabinv[i] = sintabinv[ju];
  }

  for (ju = 0; ju < 65; ju++) {
    i = (ju << 1) + xoffInit;
    Quadcopter_ControllerWithNavigation_B.temp_re = x[i];
    Quadcopter_ControllerWithNavigation_B.temp_im = x[i + 1];
    Quadcopter_ControllerWithNavigation_B.twid_re = wwc[ju + 64].re;
    Quadcopter_ControllerWithNavigation_B.twid_im = wwc[ju + 64].im;
    Quadcopter_ControllerWithNavigation_B.ytmp[ju].re =
      Quadcopter_ControllerWithNavigation_B.twid_re *
      Quadcopter_ControllerWithNavigation_B.temp_re +
      Quadcopter_ControllerWithNavigation_B.twid_im *
      Quadcopter_ControllerWithNavigation_B.temp_im;
    Quadcopter_ControllerWithNavigation_B.ytmp[ju].im =
      Quadcopter_ControllerWithNavigation_B.twid_re *
      Quadcopter_ControllerWithNavigation_B.temp_im -
      Quadcopter_ControllerWithNavigation_B.twid_im *
      Quadcopter_ControllerWithNavigation_B.temp_re;
  }

  memset(&Quadcopter_ControllerWithNavigation_B.fy[0], 0, sizeof(creal_T) << 8U);
  iy = 0;
  ju = 0;
  for (i = 0; i < 64; i++) {
    Quadcopter_ControllerWithNavigation_B.fy[iy] =
      Quadcopter_ControllerWithNavigation_B.ytmp[i];
    iy = 256;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
  }

  Quadcopter_ControllerWithNavigation_B.fy[iy] =
    Quadcopter_ControllerWithNavigation_B.ytmp[64];
  for (i = 0; i <= 254; i += 2) {
    Quadcopter_ControllerWithNavigation_B.temp_re =
      Quadcopter_ControllerWithNavigation_B.fy[i + 1].re;
    Quadcopter_ControllerWithNavigation_B.temp_im =
      Quadcopter_ControllerWithNavigation_B.fy[i + 1].im;
    Quadcopter_ControllerWithNavigation_B.twid_re =
      Quadcopter_ControllerWithNavigation_B.fy[i].re;
    Quadcopter_ControllerWithNavigation_B.twid_im =
      Quadcopter_ControllerWithNavigation_B.fy[i].im;
    Quadcopter_ControllerWithNavigation_B.fy[i + 1].re =
      Quadcopter_ControllerWithNavigation_B.twid_re -
      Quadcopter_ControllerWithNavigation_B.temp_re;
    Quadcopter_ControllerWithNavigation_B.fy[i + 1].im =
      Quadcopter_ControllerWithNavigation_B.twid_im -
      Quadcopter_ControllerWithNavigation_B.temp_im;
    Quadcopter_ControllerWithNavigation_B.fy[i].re =
      Quadcopter_ControllerWithNavigation_B.twid_re +
      Quadcopter_ControllerWithNavigation_B.temp_re;
    Quadcopter_ControllerWithNavigation_B.fy[i].im =
      Quadcopter_ControllerWithNavigation_B.twid_im +
      Quadcopter_ControllerWithNavigation_B.temp_im;
  }

  ju = 2;
  iy = 4;
  b_k = 64;
  iheight = 253;
  while (b_k > 0) {
    for (j_i = 0; j_i < iheight; j_i += iy) {
      i = j_i + ju;
      Quadcopter_ControllerWithNavigation_B.temp_re =
        Quadcopter_ControllerWithNavigation_B.fy[i].re;
      Quadcopter_ControllerWithNavigation_B.temp_im =
        Quadcopter_ControllerWithNavigation_B.fy[i].im;
      Quadcopter_ControllerWithNavigation_B.fy[i].re =
        Quadcopter_ControllerWithNavigation_B.fy[j_i].re -
        Quadcopter_ControllerWithNavigation_B.temp_re;
      Quadcopter_ControllerWithNavigation_B.fy[i].im =
        Quadcopter_ControllerWithNavigation_B.fy[j_i].im -
        Quadcopter_ControllerWithNavigation_B.temp_im;
      Quadcopter_ControllerWithNavigation_B.fy[j_i].re +=
        Quadcopter_ControllerWithNavigation_B.temp_re;
      Quadcopter_ControllerWithNavigation_B.fy[j_i].im +=
        Quadcopter_ControllerWithNavigation_B.temp_im;
    }

    c_istart = 1;
    for (int32_T c_j = b_k; c_j < 128; c_j += b_k) {
      Quadcopter_ControllerWithNavigation_B.twid_re =
        Quadcopter_ControllerWithNavigation_B.hcostab[c_j];
      Quadcopter_ControllerWithNavigation_B.twid_im =
        Quadcopter_ControllerWithNavigation_B.hsintab[c_j];
      j_i = c_istart;
      c_ihi = c_istart + iheight;
      while (j_i < c_ihi) {
        i = j_i + ju;
        Quadcopter_ControllerWithNavigation_B.temp_im =
          Quadcopter_ControllerWithNavigation_B.fy[i].im;
        Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp =
          Quadcopter_ControllerWithNavigation_B.fy[i].re;
        Quadcopter_ControllerWithNavigation_B.temp_re =
          Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp *
          Quadcopter_ControllerWithNavigation_B.twid_re -
          Quadcopter_ControllerWithNavigation_B.temp_im *
          Quadcopter_ControllerWithNavigation_B.twid_im;
        Quadcopter_ControllerWithNavigation_B.temp_im =
          Quadcopter_ControllerWithNavigation_B.temp_im *
          Quadcopter_ControllerWithNavigation_B.twid_re +
          Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp *
          Quadcopter_ControllerWithNavigation_B.twid_im;
        Quadcopter_ControllerWithNavigation_B.fy[i].re =
          Quadcopter_ControllerWithNavigation_B.fy[j_i].re -
          Quadcopter_ControllerWithNavigation_B.temp_re;
        Quadcopter_ControllerWithNavigation_B.fy[i].im =
          Quadcopter_ControllerWithNavigation_B.fy[j_i].im -
          Quadcopter_ControllerWithNavigation_B.temp_im;
        Quadcopter_ControllerWithNavigation_B.fy[j_i].re +=
          Quadcopter_ControllerWithNavigation_B.temp_re;
        Quadcopter_ControllerWithNavigation_B.fy[j_i].im +=
          Quadcopter_ControllerWithNavigation_B.temp_im;
        j_i += iy;
      }

      c_istart++;
    }

    b_k /= 2;
    ju = iy;
    iy += iy;
    iheight -= ju;
  }

  memset(&Quadcopter_ControllerWithNavigation_B.fv[0], 0, sizeof(creal_T) << 8U);
  iy = 0;
  ju = 0;
  for (i = 0; i < 128; i++) {
    Quadcopter_ControllerWithNavigation_B.fv[iy] = wwc[i];
    iy = 256;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
  }

  Quadcopter_ControllerWithNavigation_B.fv[iy] = wwc[128];
  for (i = 0; i <= 254; i += 2) {
    Quadcopter_ControllerWithNavigation_B.temp_re =
      Quadcopter_ControllerWithNavigation_B.fv[i + 1].re;
    Quadcopter_ControllerWithNavigation_B.temp_im =
      Quadcopter_ControllerWithNavigation_B.fv[i + 1].im;
    Quadcopter_ControllerWithNavigation_B.twid_re =
      Quadcopter_ControllerWithNavigation_B.fv[i].re;
    Quadcopter_ControllerWithNavigation_B.twid_im =
      Quadcopter_ControllerWithNavigation_B.fv[i].im;
    Quadcopter_ControllerWithNavigation_B.fv[i + 1].re =
      Quadcopter_ControllerWithNavigation_B.twid_re -
      Quadcopter_ControllerWithNavigation_B.temp_re;
    Quadcopter_ControllerWithNavigation_B.fv[i + 1].im =
      Quadcopter_ControllerWithNavigation_B.twid_im -
      Quadcopter_ControllerWithNavigation_B.temp_im;
    Quadcopter_ControllerWithNavigation_B.fv[i].re =
      Quadcopter_ControllerWithNavigation_B.twid_re +
      Quadcopter_ControllerWithNavigation_B.temp_re;
    Quadcopter_ControllerWithNavigation_B.fv[i].im =
      Quadcopter_ControllerWithNavigation_B.twid_im +
      Quadcopter_ControllerWithNavigation_B.temp_im;
  }

  ju = 2;
  iy = 4;
  b_k = 64;
  iheight = 253;
  while (b_k > 0) {
    for (j_i = 0; j_i < iheight; j_i += iy) {
      i = j_i + ju;
      Quadcopter_ControllerWithNavigation_B.temp_re =
        Quadcopter_ControllerWithNavigation_B.fv[i].re;
      Quadcopter_ControllerWithNavigation_B.temp_im =
        Quadcopter_ControllerWithNavigation_B.fv[i].im;
      Quadcopter_ControllerWithNavigation_B.fv[i].re =
        Quadcopter_ControllerWithNavigation_B.fv[j_i].re -
        Quadcopter_ControllerWithNavigation_B.temp_re;
      Quadcopter_ControllerWithNavigation_B.fv[i].im =
        Quadcopter_ControllerWithNavigation_B.fv[j_i].im -
        Quadcopter_ControllerWithNavigation_B.temp_im;
      Quadcopter_ControllerWithNavigation_B.fv[j_i].re +=
        Quadcopter_ControllerWithNavigation_B.temp_re;
      Quadcopter_ControllerWithNavigation_B.fv[j_i].im +=
        Quadcopter_ControllerWithNavigation_B.temp_im;
    }

    c_istart = 1;
    for (int32_T c_j = b_k; c_j < 128; c_j += b_k) {
      Quadcopter_ControllerWithNavigation_B.twid_re =
        Quadcopter_ControllerWithNavigation_B.hcostab[c_j];
      Quadcopter_ControllerWithNavigation_B.twid_im =
        Quadcopter_ControllerWithNavigation_B.hsintab[c_j];
      j_i = c_istart;
      c_ihi = c_istart + iheight;
      while (j_i < c_ihi) {
        i = j_i + ju;
        Quadcopter_ControllerWithNavigation_B.temp_im =
          Quadcopter_ControllerWithNavigation_B.fv[i].im;
        Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp =
          Quadcopter_ControllerWithNavigation_B.fv[i].re;
        Quadcopter_ControllerWithNavigation_B.temp_re =
          Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp *
          Quadcopter_ControllerWithNavigation_B.twid_re -
          Quadcopter_ControllerWithNavigation_B.temp_im *
          Quadcopter_ControllerWithNavigation_B.twid_im;
        Quadcopter_ControllerWithNavigation_B.temp_im =
          Quadcopter_ControllerWithNavigation_B.temp_im *
          Quadcopter_ControllerWithNavigation_B.twid_re +
          Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp *
          Quadcopter_ControllerWithNavigation_B.twid_im;
        Quadcopter_ControllerWithNavigation_B.fv[i].re =
          Quadcopter_ControllerWithNavigation_B.fv[j_i].re -
          Quadcopter_ControllerWithNavigation_B.temp_re;
        Quadcopter_ControllerWithNavigation_B.fv[i].im =
          Quadcopter_ControllerWithNavigation_B.fv[j_i].im -
          Quadcopter_ControllerWithNavigation_B.temp_im;
        Quadcopter_ControllerWithNavigation_B.fv[j_i].re +=
          Quadcopter_ControllerWithNavigation_B.temp_re;
        Quadcopter_ControllerWithNavigation_B.fv[j_i].im +=
          Quadcopter_ControllerWithNavigation_B.temp_im;
        j_i += iy;
      }

      c_istart++;
    }

    b_k /= 2;
    ju = iy;
    iy += iy;
    iheight -= ju;
  }

  for (i = 0; i < 256; i++) {
    Quadcopter_ControllerWithNavigation_B.temp_re =
      Quadcopter_ControllerWithNavigation_B.fy[i].re;
    Quadcopter_ControllerWithNavigation_B.temp_im =
      Quadcopter_ControllerWithNavigation_B.fy[i].im;
    Quadcopter_ControllerWithNavigation_B.twid_re =
      Quadcopter_ControllerWithNavigation_B.fv[i].im;
    Quadcopter_ControllerWithNavigation_B.twid_im =
      Quadcopter_ControllerWithNavigation_B.fv[i].re;
    Quadcopter_ControllerWithNavigation_B.fy[i].re =
      Quadcopter_ControllerWithNavigation_B.temp_re *
      Quadcopter_ControllerWithNavigation_B.twid_im -
      Quadcopter_ControllerWithNavigation_B.temp_im *
      Quadcopter_ControllerWithNavigation_B.twid_re;
    Quadcopter_ControllerWithNavigation_B.fy[i].im =
      Quadcopter_ControllerWithNavigation_B.temp_re *
      Quadcopter_ControllerWithNavigation_B.twid_re +
      Quadcopter_ControllerWithNavigation_B.temp_im *
      Quadcopter_ControllerWithNavigation_B.twid_im;
  }

  iy = 0;
  ju = 0;
  for (i = 0; i < 255; i++) {
    Quadcopter_ControllerWithNavigation_B.fv[iy] =
      Quadcopter_ControllerWithNavigation_B.fy[i];
    iy = 256;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
  }

  Quadcopter_ControllerWithNavigation_B.fv[iy] =
    Quadcopter_ControllerWithNavigation_B.fy[255];
  for (i = 0; i <= 254; i += 2) {
    Quadcopter_ControllerWithNavigation_B.temp_re =
      Quadcopter_ControllerWithNavigation_B.fv[i + 1].re;
    Quadcopter_ControllerWithNavigation_B.temp_im =
      Quadcopter_ControllerWithNavigation_B.fv[i + 1].im;
    Quadcopter_ControllerWithNavigation_B.twid_re =
      Quadcopter_ControllerWithNavigation_B.fv[i].re;
    Quadcopter_ControllerWithNavigation_B.twid_im =
      Quadcopter_ControllerWithNavigation_B.fv[i].im;
    Quadcopter_ControllerWithNavigation_B.fv[i + 1].re =
      Quadcopter_ControllerWithNavigation_B.twid_re -
      Quadcopter_ControllerWithNavigation_B.temp_re;
    Quadcopter_ControllerWithNavigation_B.fv[i + 1].im =
      Quadcopter_ControllerWithNavigation_B.twid_im -
      Quadcopter_ControllerWithNavigation_B.temp_im;
    Quadcopter_ControllerWithNavigation_B.fv[i].re =
      Quadcopter_ControllerWithNavigation_B.twid_re +
      Quadcopter_ControllerWithNavigation_B.temp_re;
    Quadcopter_ControllerWithNavigation_B.fv[i].im =
      Quadcopter_ControllerWithNavigation_B.twid_im +
      Quadcopter_ControllerWithNavigation_B.temp_im;
  }

  ju = 2;
  iy = 4;
  b_k = 64;
  iheight = 253;
  while (b_k > 0) {
    for (j_i = 0; j_i < iheight; j_i += iy) {
      i = j_i + ju;
      Quadcopter_ControllerWithNavigation_B.temp_re =
        Quadcopter_ControllerWithNavigation_B.fv[i].re;
      Quadcopter_ControllerWithNavigation_B.temp_im =
        Quadcopter_ControllerWithNavigation_B.fv[i].im;
      Quadcopter_ControllerWithNavigation_B.fv[i].re =
        Quadcopter_ControllerWithNavigation_B.fv[j_i].re -
        Quadcopter_ControllerWithNavigation_B.temp_re;
      Quadcopter_ControllerWithNavigation_B.fv[i].im =
        Quadcopter_ControllerWithNavigation_B.fv[j_i].im -
        Quadcopter_ControllerWithNavigation_B.temp_im;
      Quadcopter_ControllerWithNavigation_B.fv[j_i].re +=
        Quadcopter_ControllerWithNavigation_B.temp_re;
      Quadcopter_ControllerWithNavigation_B.fv[j_i].im +=
        Quadcopter_ControllerWithNavigation_B.temp_im;
    }

    c_istart = 1;
    for (int32_T c_j = b_k; c_j < 128; c_j += b_k) {
      Quadcopter_ControllerWithNavigation_B.twid_re =
        Quadcopter_ControllerWithNavigation_B.hcostabinv[c_j];
      Quadcopter_ControllerWithNavigation_B.twid_im =
        Quadcopter_ControllerWithNavigation_B.hsintabinv[c_j];
      j_i = c_istart;
      c_ihi = c_istart + iheight;
      while (j_i < c_ihi) {
        i = j_i + ju;
        Quadcopter_ControllerWithNavigation_B.temp_im =
          Quadcopter_ControllerWithNavigation_B.fv[i].im;
        Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp =
          Quadcopter_ControllerWithNavigation_B.fv[i].re;
        Quadcopter_ControllerWithNavigation_B.temp_re =
          Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp *
          Quadcopter_ControllerWithNavigation_B.twid_re -
          Quadcopter_ControllerWithNavigation_B.temp_im *
          Quadcopter_ControllerWithNavigation_B.twid_im;
        Quadcopter_ControllerWithNavigation_B.temp_im =
          Quadcopter_ControllerWithNavigation_B.temp_im *
          Quadcopter_ControllerWithNavigation_B.twid_re +
          Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp *
          Quadcopter_ControllerWithNavigation_B.twid_im;
        Quadcopter_ControllerWithNavigation_B.fv[i].re =
          Quadcopter_ControllerWithNavigation_B.fv[j_i].re -
          Quadcopter_ControllerWithNavigation_B.temp_re;
        Quadcopter_ControllerWithNavigation_B.fv[i].im =
          Quadcopter_ControllerWithNavigation_B.fv[j_i].im -
          Quadcopter_ControllerWithNavigation_B.temp_im;
        Quadcopter_ControllerWithNavigation_B.fv[j_i].re +=
          Quadcopter_ControllerWithNavigation_B.temp_re;
        Quadcopter_ControllerWithNavigation_B.fv[j_i].im +=
          Quadcopter_ControllerWithNavigation_B.temp_im;
        j_i += iy;
      }

      c_istart++;
    }

    b_k /= 2;
    ju = iy;
    iy += iy;
    iheight -= ju;
  }

  for (i = 0; i < 256; i++) {
    Quadcopter_ControllerWithNavigation_B.fv[i].re *= 0.00390625;
    Quadcopter_ControllerWithNavigation_B.fv[i].im *= 0.00390625;
  }

  for (i = 0; i < 65; i++) {
    Quadcopter_ControllerWithNavigation_B.twid_re = wwc[i + 64].re;
    Quadcopter_ControllerWithNavigation_B.twid_im = wwc[i + 64].im;
    Quadcopter_ControllerWithNavigation_B.temp_re =
      Quadcopter_ControllerWithNavigation_B.fv[i + 64].re;
    Quadcopter_ControllerWithNavigation_B.temp_im =
      Quadcopter_ControllerWithNavigation_B.fv[i + 64].im;
    Quadcopter_ControllerWithNavigation_B.ytmp[i].re =
      Quadcopter_ControllerWithNavigation_B.twid_re *
      Quadcopter_ControllerWithNavigation_B.temp_re +
      Quadcopter_ControllerWithNavigation_B.twid_im *
      Quadcopter_ControllerWithNavigation_B.temp_im;
    Quadcopter_ControllerWithNavigation_B.ytmp[i].im =
      Quadcopter_ControllerWithNavigation_B.twid_re *
      Quadcopter_ControllerWithNavigation_B.temp_im -
      Quadcopter_ControllerWithNavigation_B.twid_im *
      Quadcopter_ControllerWithNavigation_B.temp_re;
  }

  for (i = 0; i < 65; i++) {
    int8_T d;
    Quadcopter_ControllerWithNavigation_B.temp_re = reconVar1[i].re;
    Quadcopter_ControllerWithNavigation_B.temp_im = reconVar1[i].im;
    d = d_0[i];
    Quadcopter_ControllerWithNavigation_B.twid_re = reconVar2[i].re;
    Quadcopter_ControllerWithNavigation_B.twid_im = reconVar2[i].im;
    Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp =
      Quadcopter_ControllerWithNavigation_B.ytmp[d - 1].re;
    Quadcopter_ControllerWithNavigation_B.ytmp_im_tmp =
      -Quadcopter_ControllerWithNavigation_B.ytmp[d - 1].im;
    Quadcopter_ControllerWithNavigation_B.d4 =
      Quadcopter_ControllerWithNavigation_B.ytmp[i].re;
    Quadcopter_ControllerWithNavigation_B.d5 =
      Quadcopter_ControllerWithNavigation_B.ytmp[i].im;
    y[i].re = ((Quadcopter_ControllerWithNavigation_B.d4 *
                Quadcopter_ControllerWithNavigation_B.temp_re -
                Quadcopter_ControllerWithNavigation_B.d5 *
                Quadcopter_ControllerWithNavigation_B.temp_im) +
               (Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp *
                Quadcopter_ControllerWithNavigation_B.twid_re -
                Quadcopter_ControllerWithNavigation_B.ytmp_im_tmp *
                Quadcopter_ControllerWithNavigation_B.twid_im)) * 0.5;
    y[i].im = ((Quadcopter_ControllerWithNavigation_B.d4 *
                Quadcopter_ControllerWithNavigation_B.temp_im +
                Quadcopter_ControllerWithNavigation_B.d5 *
                Quadcopter_ControllerWithNavigation_B.temp_re) +
               (Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp *
                Quadcopter_ControllerWithNavigation_B.twid_im +
                Quadcopter_ControllerWithNavigation_B.ytmp_im_tmp *
                Quadcopter_ControllerWithNavigation_B.twid_re)) * 0.5;
    y[i + 65].re = ((Quadcopter_ControllerWithNavigation_B.d4 *
                     Quadcopter_ControllerWithNavigation_B.twid_re -
                     Quadcopter_ControllerWithNavigation_B.d5 *
                     Quadcopter_ControllerWithNavigation_B.twid_im) +
                    (Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp *
                     Quadcopter_ControllerWithNavigation_B.temp_re -
                     Quadcopter_ControllerWithNavigation_B.ytmp_im_tmp *
                     Quadcopter_ControllerWithNavigation_B.temp_im)) * 0.5;
    y[i + 65].im = ((Quadcopter_ControllerWithNavigation_B.d4 *
                     Quadcopter_ControllerWithNavigation_B.twid_im +
                     Quadcopter_ControllerWithNavigation_B.d5 *
                     Quadcopter_ControllerWithNavigation_B.twid_re) +
                    (Quadcopter_ControllerWithNavigation_B.ytmp_re_tmp *
                     Quadcopter_ControllerWithNavigation_B.temp_im +
                     Quadcopter_ControllerWithNavigation_B.ytmp_im_tmp *
                     Quadcopter_ControllerWithNavigation_B.temp_re)) * 0.5;
  }
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S52>/MATLAB Function1'
static real_T Quadcopter_ControllerWithNavigation_trapz(const real_T x[99],
  const real_T y[99])
{
  real_T z;
  int32_T ix;
  Quadcopter_ControllerWithNavigation_B.b_x[0] = (x[1] - x[0]) * 0.5;
  for (ix = 0; ix < 97; ix++) {
    Quadcopter_ControllerWithNavigation_B.b_x[ix + 1] = (x[ix + 2] - x[ix]) *
      0.5;
  }

  Quadcopter_ControllerWithNavigation_B.b_x[98] = (x[98] - x[97]) * 0.5;
  ix = 0;
  z = 0.0;
  for (int32_T b_iac = 0; b_iac < 99; b_iac++) {
    int32_T iac;
    iac = b_iac + 1;
    for (int32_T ia = iac; ia <= iac; ia++) {
      z += y[ia - 1] * Quadcopter_ControllerWithNavigation_B.b_x[ix];
    }

    ix++;
  }

  return z;
}

static void Quadcopter_ControllerWithNavigation_SystemCore_setup
  (px4_internal_block_PWM_Quadcopter_ControllerWithNavigation_T *obj, boolean_T
   varargin_1, boolean_T varargin_2)
{
  uint16_T status;
  obj->isSetupComplete = false;

  // Start for MATLABSystem: '<S5>/PX4 PWM Output'
  obj->isInitialized = 1;
  obj->isMain = true;
  obj->pwmDevObj = MW_PWM_OUTPUT_MAIN_DEVICE_PATH;
  status = pwm_open(&obj->pwmDevHandler, obj->pwmDevObj,
                    &obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  obj->servoCount = 0;
  status = pwm_getServoCount(&obj->pwmDevHandler, &obj->servoCount);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  if (varargin_1) {
    status = pwm_arm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    status = pwm_disarm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setPWMRate(&obj->pwmDevHandler, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  obj->channelMask = 15;
  status = pwm_setChannelMask(&obj->pwmDevHandler, obj->channelMask);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setFailsafePWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setDisarmedPWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain, &obj->actuatorAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  if (obj->isMain) {
    status = pwm_forceFailsafe(&obj->pwmDevHandler, static_cast<int32_T>
      (varargin_2));
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
    status = pwm_forceTerminateFailsafe(&obj->pwmDevHandler, 0);
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  }

  // End of Start for MATLABSystem: '<S5>/PX4 PWM Output'
  obj->isSetupComplete = true;
}

// Model step function for TID0
void Quadcopter_ControllerWithNavigation_step0(void) // Sample time: [0.005s, 0.0s] 
{
  {                                    // Sample time: [0.005s, 0.0s]
    rate_monotonic_scheduler();
  }

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  Quadcopter_ControllerWithNavigation_M->Timing.taskTime0 =
    ((time_T)(++Quadcopter_ControllerWithNavigation_M->Timing.clockTick0)) *
    Quadcopter_ControllerWithNavigation_M->Timing.stepSize0;
}

// Model step function for TID1
void Quadcopter_ControllerWithNavigation_step1(void) // Sample time: [0.01s, 0.0s] 
{
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_a);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_d3);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_eq);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem2_SubsysRanBC_b);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_ControllerWithNavigation_DW.Takeoff_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_d);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem2_SubsysRanBC_d);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_ControllerWithNavigation_DW.Land_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_ControllerWithNavigation_DW.Waypoint_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_ControllerWithNavigation_DW.IDLE_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_h);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem2_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem1_SubsysRanBC_m);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem_SubsysRanBC_g);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.SendwaypointstoOBC_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_l);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_n);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem2_SubsysRanBC);

  // MATLABSystem: '<S7>/SourceBlock'
  Quadcopter_ControllerWithNavigation_B.latp2 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_d.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_d.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_n, false, 1.0);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  // Start for MATLABSystem: '<S7>/SourceBlock'
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    // SignalConversion generated from: '<S11>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_b =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_n;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_f);
  }

  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'

  // MATLABSystem: '<S9>/SourceBlock'
  Quadcopter_ControllerWithNavigation_B.latp2 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_m.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_m.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  // Start for MATLABSystem: '<S9>/SourceBlock'
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    // SignalConversion generated from: '<S13>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_c =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_cx;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_eq);
  }

  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'

  // DataTypeConversion: '<S2>/Data Type Conversion1'
  Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0] =
    Quadcopter_ControllerWithNavigation_B.In1_c.x;
  Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1] =
    Quadcopter_ControllerWithNavigation_B.In1_c.y;
  Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] =
    Quadcopter_ControllerWithNavigation_B.In1_c.z;
  Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[3] =
    Quadcopter_ControllerWithNavigation_B.In1_c.vx;
  Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[4] =
    Quadcopter_ControllerWithNavigation_B.In1_c.vy;
  Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[5] =
    Quadcopter_ControllerWithNavigation_B.In1_c.vz;
  Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[6] =
    Quadcopter_ControllerWithNavigation_B.In1_c.heading;

  // MATLABSystem: '<S17>/Read Parameter'
  if (Quadcopter_ControllerWithNavigation_DW.obj_k.SampleTime !=
      Quadcopter_ControllerWithNavigation_P.ReadParameter_SampleTime) {
    Quadcopter_ControllerWithNavigation_DW.obj_k.SampleTime =
      Quadcopter_ControllerWithNavigation_P.ReadParameter_SampleTime;
  }

  Quadcopter_ControllerWithNavigation_B.latp2 = MW_Param_Step
    (Quadcopter_ControllerWithNavigation_DW.obj_k.MW_PARAMHANDLE, MW_INT32,
     &Quadcopter_ControllerWithNavigation_B.ParamStep_l);
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    Quadcopter_ControllerWithNavigation_B.ParamStep_l = 0;
  }

  // MATLABSystem: '<S38>/SourceBlock'
  Quadcopter_ControllerWithNavigation_B.latp2 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_e.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_e.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S38>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S39>/Enable'

  // Start for MATLABSystem: '<S38>/SourceBlock'
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    // SignalConversion generated from: '<S39>/In1'
    Quadcopter_ControllerWithNavigation_B.In1 =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_h);
  }

  // End of Outputs for SubSystem: '<S38>/Enabled Subsystem'

  // MATLABSystem: '<S36>/SourceBlock'
  Quadcopter_ControllerWithNavigation_B.latp2 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_kz.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_kz.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S36>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S51>/Enable'

  // Start for MATLABSystem: '<S36>/SourceBlock'
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    // SignalConversion generated from: '<S51>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_p =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_k;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_n);
  }

  // End of Outputs for SubSystem: '<S36>/Enabled Subsystem'

  // MATLABSystem: '<S35>/SourceBlock'
  Quadcopter_ControllerWithNavigation_B.latp2 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_gf.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_gf.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_cv, false, 1.0);

  // Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S50>/Enable'

  // Start for MATLABSystem: '<S35>/SourceBlock'
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    // SignalConversion generated from: '<S50>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_f =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_cv;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_l);
  }

  // End of Outputs for SubSystem: '<S35>/Enabled Subsystem'

  // MATLABSystem: '<S17>/LLA2LocalCoordinates' incorporates:
  //   MATLABSystem: '<S17>/Read Parameter'
  //   SignalConversion generated from: '<S50>/In1'
  //
  Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0] = 0.0;
  Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] = 0.0;
  Quadcopter_ControllerWithNavigation_B.b_varargout_3[0] = 0.0;
  Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1] = 0.0;
  Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1] = 0.0;
  Quadcopter_ControllerWithNavigation_B.b_varargout_3[1] = 0.0;
  Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2] = 0.0;
  Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2] = 0.0;
  Quadcopter_ControllerWithNavigation_B.b_varargout_3[2] = 0.0;
  Quadcopter_ControllerWithNavigation_B.lla0[0] =
    Quadcopter_ControllerWithNavigation_B.In1_f.lat;
  Quadcopter_ControllerWithNavigation_B.lla0[1] =
    Quadcopter_ControllerWithNavigation_B.In1_f.lon;
  Quadcopter_ControllerWithNavigation_B.lla0[2] =
    Quadcopter_ControllerWithNavigation_B.In1_f.alt;
  if (Quadcopter_ControllerWithNavigation_B.In1_p.previous.valid &&
      (!Quadcopter_ControllerWithNavigation_DW.obj_mr.previousValidReceived)) {
    Quadcopter_ControllerWithNavigation_DW.obj_mr.previousValidReceived = true;
  }

  if (Quadcopter_ControllerWithNavigation_B.In1_p.next.valid &&
      (!Quadcopter_ControllerWithNavigation_DW.obj_mr.nextValidReceived)) {
    Quadcopter_ControllerWithNavigation_DW.obj_mr.nextValidReceived = true;
  }

  if (Quadcopter_ControllerWithNavigation_B.In1_f.valid_hpos &&
      Quadcopter_ControllerWithNavigation_B.In1_p.current.valid &&
      (Quadcopter_ControllerWithNavigation_B.In1_p.current.type != 5)) {
    if (Quadcopter_ControllerWithNavigation_B.ParamStep_l != 0) {
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] =
        Quadcopter_ControllerWithNavigation_B.In1.waypoints[0].position[0];
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1] =
        Quadcopter_ControllerWithNavigation_B.In1.waypoints[0].position[1];
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2] =
        Quadcopter_ControllerWithNavigation_B.In1.waypoints[0].position[2];
    } else {
      Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[0] =
        Quadcopter_ControllerWithNavigation_B.In1_p.current.lat;
      Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[1] =
        Quadcopter_ControllerWithNavigation_B.In1_p.current.lon;
      Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[2] =
        Quadcopter_ControllerWithNavigation_B.In1_p.current.alt;
      Quadcopter_ControllerWithNavigation_lla2ned
        (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m,
         Quadcopter_ControllerWithNavigation_B.lla0,
         Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1);
    }
  }

  if (Quadcopter_ControllerWithNavigation_B.In1_f.valid_hpos &&
      (Quadcopter_ControllerWithNavigation_B.In1_p.previous.valid ||
       Quadcopter_ControllerWithNavigation_DW.obj_mr.previousValidReceived)) {
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[0] =
      Quadcopter_ControllerWithNavigation_B.In1_p.previous.lat;
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[1] =
      Quadcopter_ControllerWithNavigation_B.In1_p.previous.lon;
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[2] =
      Quadcopter_ControllerWithNavigation_B.In1_p.previous.alt;
    Quadcopter_ControllerWithNavigation_lla2ned
      (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m,
       Quadcopter_ControllerWithNavigation_B.lla0,
       Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k);
  }

  if (Quadcopter_ControllerWithNavigation_B.In1_f.valid_hpos &&
      (Quadcopter_ControllerWithNavigation_B.In1_p.next.valid ||
       Quadcopter_ControllerWithNavigation_DW.obj_mr.nextValidReceived)) {
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[0] =
      Quadcopter_ControllerWithNavigation_B.In1_p.next.lat;
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[1] =
      Quadcopter_ControllerWithNavigation_B.In1_p.next.lon;
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[2] =
      Quadcopter_ControllerWithNavigation_B.In1_p.next.alt;
    Quadcopter_ControllerWithNavigation_lla2ned
      (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m,
       Quadcopter_ControllerWithNavigation_B.lla0,
       Quadcopter_ControllerWithNavigation_B.b_varargout_3);
  }

  // If: '<S16>/If' incorporates:
  //   Delay: '<S22>/Delay'
  //   Delay: '<S25>/Delay'
  //   Delay: '<S29>/Delay'
  //   MATLABSystem: '<S17>/LLA2LocalCoordinates'
  //
  Quadcopter_ControllerWithNavigation_B.rtPrevAction =
    Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem;
  if (Quadcopter_ControllerWithNavigation_B.In1_p.current.type == 3) {
    Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem = 0;
  } else if (Quadcopter_ControllerWithNavigation_B.In1_p.current.type == 4) {
    Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem = 1;
  } else if (Quadcopter_ControllerWithNavigation_B.In1_p.current.type == 0) {
    Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem = 2;
  } else {
    Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem = 3;
  }

  switch (Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem) {
   case 0:
    if (Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem !=
        Quadcopter_ControllerWithNavigation_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S16>/Take-off' incorporates:
      //   ActionPort: '<S20>/Action Port'

      // InitializeConditions for If: '<S16>/If' incorporates:
      //   Delay: '<S28>/Delay'
      //   Delay: '<S29>/Delay'

      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_c =
        Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition;
      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_d =
        Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_g;

      // End of InitializeConditions for SubSystem: '<S16>/Take-off'
    }

    // Outputs for IfAction SubSystem: '<S16>/Take-off' incorporates:
    //   ActionPort: '<S20>/Action Port'

    // Sum: '<S28>/Sum' incorporates:
    //   Constant: '<S28>/Rate'
    //   Delay: '<S28>/Delay'

    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_c +=
      Quadcopter_ControllerWithNavigation_P.Rate_Value;

    // Gain: '<S28>/Gain1'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_P.Gain1_Gain *
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2];

    // Outputs for Enabled SubSystem: '<S29>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S30>/Enable'

    if (Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_d > 0.0) {
      // SignalConversion generated from: '<S30>/yaw_In'
      Quadcopter_ControllerWithNavigation_B.yaw_In_ik =
        Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[6];
      srUpdateBC
        (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem2_SubsysRanBC_b);
    }

    // End of Outputs for SubSystem: '<S29>/Enabled Subsystem2'

    // Merge: '<S16>/Merge' incorporates:
    //   Delay: '<S29>/Delay'
    //   Reshape: '<S20>/Reshape'

    Quadcopter_ControllerWithNavigation_B.Merge[0] =
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0];
    Quadcopter_ControllerWithNavigation_B.Merge[1] =
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1];

    // Gain: '<S28>/Gain' incorporates:
    //   Delay: '<S28>/Delay'
    //   RelationalOperator: '<S28>/Relational Operator'
    //   Switch: '<S28>/Switch'

    if (!(Quadcopter_ControllerWithNavigation_B.Gain_i <=
          Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_c)) {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_c;
    }

    // Merge: '<S16>/Merge' incorporates:
    //   Gain: '<S28>/Gain'
    //   Reshape: '<S20>/Reshape'
    //   Switch: '<S28>/Switch'

    Quadcopter_ControllerWithNavigation_B.Merge[2] =
      Quadcopter_ControllerWithNavigation_P.Gain_Gain *
      Quadcopter_ControllerWithNavigation_B.Gain_i;
    Quadcopter_ControllerWithNavigation_B.Merge[3] =
      Quadcopter_ControllerWithNavigation_B.yaw_In_ik;

    // Update for Delay: '<S29>/Delay' incorporates:
    //   Constant: '<S29>/Constant'

    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_d =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_f;
    srUpdateBC(Quadcopter_ControllerWithNavigation_DW.Takeoff_SubsysRanBC);

    // End of Outputs for SubSystem: '<S16>/Take-off'
    break;

   case 1:
    if (Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem !=
        Quadcopter_ControllerWithNavigation_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S16>/Land' incorporates:
      //   ActionPort: '<S19>/Action Port'

      // InitializeConditions for If: '<S16>/If' incorporates:
      //   Delay: '<S19>/Delay'
      //   Delay: '<S24>/Delay'
      //   Delay: '<S25>/Delay'
      //   Gain: '<S24>/Gain1'

      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_l[0] =
        Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_n;
      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_l[1] =
        Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_n;
      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_n =
        Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_m;
      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_b =
        Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_j;

      // End of InitializeConditions for SubSystem: '<S16>/Land'
    }

    // Outputs for IfAction SubSystem: '<S16>/Land' incorporates:
    //   ActionPort: '<S19>/Action Port'

    // Switch: '<S19>/Switch' incorporates:
    //   Delay: '<S19>/Delay'
    //   Logic: '<S19>/OR'
    //   RelationalOperator: '<S19>/IsNaN'

    if ((!rtIsNaN(Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0])) &&
        (!rtIsNaN(Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1])))
    {
      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_l[0] =
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0];
      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_l[1] =
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1];
    }

    // End of Switch: '<S19>/Switch'

    // Switch: '<S24>/Switch' incorporates:
    //   Delay: '<S24>/Delay'

    if (!(Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_n >
          Quadcopter_ControllerWithNavigation_P.Switch_Threshold)) {
      // Gain: '<S24>/Gain1' incorporates:
      //   Gain: '<S24>/Gain'

      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_n =
        Quadcopter_ControllerWithNavigation_P.Gain_Gain_l *
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2];
    }

    // End of Switch: '<S24>/Switch'

    // Sum: '<S24>/Subtract' incorporates:
    //   Constant: '<S24>/Rate of descent'

    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_n -
      Quadcopter_ControllerWithNavigation_P.Rateofdescent_Value;

    // Gain: '<S24>/Gain1' incorporates:
    //   Gain: '<S24>/Gain2'

    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_n =
      Quadcopter_ControllerWithNavigation_P.Gain2_Gain *
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2];

    // Outputs for Enabled SubSystem: '<S25>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S27>/Enable'

    if (Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_b > 0.0) {
      // SignalConversion generated from: '<S27>/yaw_In'
      Quadcopter_ControllerWithNavigation_B.yaw_In_i =
        Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[6];
      srUpdateBC
        (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem2_SubsysRanBC_d);
    }

    // End of Outputs for SubSystem: '<S25>/Enabled Subsystem2'

    // Merge: '<S16>/Merge' incorporates:
    //   Delay: '<S19>/Delay'
    //   Delay: '<S25>/Delay'
    //   Reshape: '<S19>/Reshape'

    Quadcopter_ControllerWithNavigation_B.Merge[0] =
      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_l[0];
    Quadcopter_ControllerWithNavigation_B.Merge[1] =
      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_l[1];

    // Switch: '<S24>/Switch1' incorporates:
    //   RelationalOperator: '<S24>/GreaterThan'

    if (!(Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_n >
          Quadcopter_ControllerWithNavigation_B.Gain_i)) {
      // Gain: '<S24>/Gain1'
      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_n =
        Quadcopter_ControllerWithNavigation_B.Gain_i;
    }

    // Merge: '<S16>/Merge' incorporates:
    //   Gain: '<S24>/Gain1'
    //   Reshape: '<S19>/Reshape'
    //   Switch: '<S24>/Switch1'

    Quadcopter_ControllerWithNavigation_B.Merge[2] =
      Quadcopter_ControllerWithNavigation_P.Gain1_Gain_a *
      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_n;
    Quadcopter_ControllerWithNavigation_B.Merge[3] =
      Quadcopter_ControllerWithNavigation_B.yaw_In_i;

    // Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S26>/Enable'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i > 0.0) {
      // SignalConversion generated from: '<S26>/In'
      Quadcopter_ControllerWithNavigation_B.In =
        Quadcopter_ControllerWithNavigation_B.Gain_i;
      srUpdateBC
        (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_d);
    }

    // End of Outputs for SubSystem: '<S24>/Enabled Subsystem'

    // Update for Delay: '<S19>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_l[0] =
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0];
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_l[1] =
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1];

    // Update for Gain: '<S24>/Gain1' incorporates:
    //   Delay: '<S24>/Delay'

    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_n =
      Quadcopter_ControllerWithNavigation_B.In;

    // Update for Delay: '<S25>/Delay' incorporates:
    //   Constant: '<S25>/Constant'

    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_b =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_nn;
    srUpdateBC(Quadcopter_ControllerWithNavigation_DW.Land_SubsysRanBC);

    // End of Outputs for SubSystem: '<S16>/Land'
    break;

   case 2:
    if (Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem !=
        Quadcopter_ControllerWithNavigation_B.rtPrevAction) {
      // SystemReset for IfAction SubSystem: '<S16>/Waypoint' incorporates:
      //   ActionPort: '<S21>/Action Port'

      // SystemReset for If: '<S16>/If' incorporates:
      //   MATLABSystem: '<S21>/UAV Waypoint Follower'
      //
      Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex = 1.0;
      for (Quadcopter_ControllerWithNavigation_B.j = 0;
           Quadcopter_ControllerWithNavigation_B.j < 9;
           Quadcopter_ControllerWithNavigation_B.j++) {
        Quadcopter_ControllerWithNavigation_DW.obj.WaypointsInternal[Quadcopter_ControllerWithNavigation_B.j]
          *= 0.0;
      }

      // End of SystemReset for If: '<S16>/If'
      // End of SystemReset for SubSystem: '<S16>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S16>/Waypoint' incorporates:
    //   ActionPort: '<S21>/Action Port'

    // Concatenate: '<S21>/Matrix Concatenate'
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[0] =
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0];
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[1] =
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0];
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[2] =
      Quadcopter_ControllerWithNavigation_B.b_varargout_3[0];
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[3] =
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1];
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[4] =
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1];
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[5] =
      Quadcopter_ControllerWithNavigation_B.b_varargout_3[1];
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[6] =
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2];
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[7] =
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2];
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[8] =
      Quadcopter_ControllerWithNavigation_B.b_varargout_3[2];

    // MATLABSystem: '<S21>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S21>/Matrix Concatenate'
    //   Constant: '<S21>/Constant'

    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_gw;
    Quadcopter_ControllerWithNavigation_DW.obj.LookaheadDistFlag = 0U;
    if (Quadcopter_ControllerWithNavigation_P.Constant_Value_gw < 0.3) {
      Quadcopter_ControllerWithNavigation_B.Gain_i = 0.3;
      Quadcopter_ControllerWithNavigation_DW.obj.LookaheadDistFlag = 1U;
    }

    Quadcopter_ControllerWithNavigation_DW.obj.InitialPose[0] = 0.0;
    Quadcopter_ControllerWithNavigation_DW.obj.InitialPose[1] = 0.0;
    Quadcopter_ControllerWithNavigation_DW.obj.InitialPose[2] = 0.0;
    Quadcopter_ControllerWithNavigation_DW.obj.InitialPose[3] = 0.0;
    Quadcopter_ControllerWithNavigation_DW.obj.NumWaypoints = 3.0;
    Quadcopter_ControllerWithNavigation_B.latp2 = false;
    Quadcopter_ControllerWithNavigation_B.p = true;
    Quadcopter_ControllerWithNavigation_B.i1 = 0;
    exitg1 = false;
    while ((!exitg1) && (Quadcopter_ControllerWithNavigation_B.i1 <= 8)) {
      Quadcopter_ControllerWithNavigation_B.j =
        Quadcopter_ControllerWithNavigation_B.i1 / 3 * 3 +
        Quadcopter_ControllerWithNavigation_B.i1 % 3;
      if (!(Quadcopter_ControllerWithNavigation_DW.obj.WaypointsInternal[Quadcopter_ControllerWithNavigation_B.j]
            ==
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[Quadcopter_ControllerWithNavigation_B.j]))
      {
        Quadcopter_ControllerWithNavigation_B.p = false;
        exitg1 = true;
      } else {
        Quadcopter_ControllerWithNavigation_B.i1++;
      }
    }

    if (Quadcopter_ControllerWithNavigation_B.p) {
      Quadcopter_ControllerWithNavigation_B.latp2 = true;
    }

    if (!Quadcopter_ControllerWithNavigation_B.latp2) {
      memcpy(&Quadcopter_ControllerWithNavigation_DW.obj.WaypointsInternal[0],
             &Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[0], 9U *
             sizeof(real_T));
      Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex = 1.0;
    }

    for (Quadcopter_ControllerWithNavigation_B.j = 0;
         Quadcopter_ControllerWithNavigation_B.j < 3;
         Quadcopter_ControllerWithNavigation_B.j++) {
      Quadcopter_ControllerWithNavigation_B.distinctWptsIdx[Quadcopter_ControllerWithNavigation_B.j]
        = true;
      Quadcopter_ControllerWithNavigation_B.y_l =
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[3 *
        Quadcopter_ControllerWithNavigation_B.j + 1];
      Quadcopter_ControllerWithNavigation_B.i1 =
        Quadcopter_ControllerWithNavigation_B.j << 1;
      Quadcopter_ControllerWithNavigation_B.x_d[Quadcopter_ControllerWithNavigation_B.i1]
        = (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[3 *
           Quadcopter_ControllerWithNavigation_B.j] !=
           Quadcopter_ControllerWithNavigation_B.y_l);
      Quadcopter_ControllerWithNavigation_B.x_d[Quadcopter_ControllerWithNavigation_B.i1
        + 1] = (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[3 *
                Quadcopter_ControllerWithNavigation_B.j + 2] !=
                Quadcopter_ControllerWithNavigation_B.y_l);
    }

    Quadcopter_ControllerWithNavigation_B.IsNaN_l[0] = false;
    Quadcopter_ControllerWithNavigation_B.IsNaN_l[1] = false;
    Quadcopter_ControllerWithNavigation_B.i1 = 0;
    Quadcopter_ControllerWithNavigation_B.i2 = 4;
    for (Quadcopter_ControllerWithNavigation_B.j = 0;
         Quadcopter_ControllerWithNavigation_B.j < 2;
         Quadcopter_ControllerWithNavigation_B.j++) {
      Quadcopter_ControllerWithNavigation_B.i1++;
      Quadcopter_ControllerWithNavigation_B.i2++;
      Quadcopter_ControllerWithNavigation_B.ix =
        Quadcopter_ControllerWithNavigation_B.i1;
      exitg1 = false;
      while ((!exitg1) && (Quadcopter_ControllerWithNavigation_B.ix <=
                           Quadcopter_ControllerWithNavigation_B.i2)) {
        if (Quadcopter_ControllerWithNavigation_B.x_d[Quadcopter_ControllerWithNavigation_B.ix
            - 1]) {
          Quadcopter_ControllerWithNavigation_B.IsNaN_l[Quadcopter_ControllerWithNavigation_B.j]
            = true;
          exitg1 = true;
        } else {
          Quadcopter_ControllerWithNavigation_B.ix += 2;
        }
      }
    }

    Quadcopter_ControllerWithNavigation_B.distinctWptsIdx[0] =
      Quadcopter_ControllerWithNavigation_B.IsNaN_l[0];
    Quadcopter_ControllerWithNavigation_B.distinctWptsIdx[1] =
      Quadcopter_ControllerWithNavigation_B.IsNaN_l[1];

    // End of Outputs for SubSystem: '<S16>/Waypoint'
    Quadcopter_ControllerWithNavigation_B.i1 = 0;
    for (Quadcopter_ControllerWithNavigation_B.j = 0;
         Quadcopter_ControllerWithNavigation_B.j < 3;
         Quadcopter_ControllerWithNavigation_B.j++) {
      // Outputs for IfAction SubSystem: '<S16>/Waypoint' incorporates:
      //   ActionPort: '<S21>/Action Port'

      if (Quadcopter_ControllerWithNavigation_B.distinctWptsIdx[Quadcopter_ControllerWithNavigation_B.j])
      {
        Quadcopter_ControllerWithNavigation_B.i1++;
      }

      // End of Outputs for SubSystem: '<S16>/Waypoint'
    }

    Quadcopter_ControllerWithNavigation_B.ix =
      Quadcopter_ControllerWithNavigation_B.i1;
    Quadcopter_ControllerWithNavigation_B.i1 = 0;
    for (Quadcopter_ControllerWithNavigation_B.j = 0;
         Quadcopter_ControllerWithNavigation_B.j < 3;
         Quadcopter_ControllerWithNavigation_B.j++) {
      // Outputs for IfAction SubSystem: '<S16>/Waypoint' incorporates:
      //   ActionPort: '<S21>/Action Port'

      if (Quadcopter_ControllerWithNavigation_B.distinctWptsIdx[Quadcopter_ControllerWithNavigation_B.j])
      {
        // Start for MATLABSystem: '<S21>/UAV Waypoint Follower'
        Quadcopter_ControllerWithNavigation_B.tmp_data[Quadcopter_ControllerWithNavigation_B.i1]
          = static_cast<int8_T>(Quadcopter_ControllerWithNavigation_B.j);
        Quadcopter_ControllerWithNavigation_B.i1++;
      }

      // End of Outputs for SubSystem: '<S16>/Waypoint'
    }

    // Outputs for IfAction SubSystem: '<S16>/Waypoint' incorporates:
    //   ActionPort: '<S21>/Action Port'

    // MATLABSystem: '<S21>/UAV Waypoint Follower' incorporates:
    //   Concatenate: '<S21>/Matrix Concatenate'
    //   Reshape: '<S21>/Reshape1'

    for (Quadcopter_ControllerWithNavigation_B.j = 0;
         Quadcopter_ControllerWithNavigation_B.j < 3;
         Quadcopter_ControllerWithNavigation_B.j++) {
      for (Quadcopter_ControllerWithNavigation_B.i2 = 0;
           Quadcopter_ControllerWithNavigation_B.i2 <
           Quadcopter_ControllerWithNavigation_B.ix;
           Quadcopter_ControllerWithNavigation_B.i2++) {
        Quadcopter_ControllerWithNavigation_B.b_waypointsIn_data[Quadcopter_ControllerWithNavigation_B.i2
          + Quadcopter_ControllerWithNavigation_B.ix *
          Quadcopter_ControllerWithNavigation_B.j] =
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[3 *
          Quadcopter_ControllerWithNavigation_B.j +
          Quadcopter_ControllerWithNavigation_B.tmp_data[Quadcopter_ControllerWithNavigation_B.i2]];
      }
    }

    Quadcopter_ControllerWithNavigation_DW.obj.LookaheadDistance =
      Quadcopter_ControllerWithNavigation_B.Gain_i;
    if (Quadcopter_ControllerWithNavigation_B.ix == 0) {
      Quadcopter_ControllerWithNavigation_B.lla0[0] =
        Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0];
      Quadcopter_ControllerWithNavigation_B.lla0[1] =
        Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1];
      Quadcopter_ControllerWithNavigation_B.lla0[2] =
        Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2];
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[6];
    } else {
      guard1 = false;
      if (Quadcopter_ControllerWithNavigation_B.ix == 1) {
        if (Quadcopter_ControllerWithNavigation_DW.obj.StartFlag) {
          Quadcopter_ControllerWithNavigation_DW.obj.InitialPose[0] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0];
          Quadcopter_ControllerWithNavigation_DW.obj.InitialPose[1] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1];
          Quadcopter_ControllerWithNavigation_DW.obj.InitialPose[2] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2];
          Quadcopter_ControllerWithNavigation_DW.obj.InitialPose[3] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[6];
        }

        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0] =
          Quadcopter_ControllerWithNavigation_B.b_waypointsIn_data[0] -
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0];
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1] =
          Quadcopter_ControllerWithNavigation_B.b_waypointsIn_data[1] -
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1];
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2] =
          Quadcopter_ControllerWithNavigation_B.b_waypointsIn_data[2] -
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2];
        if (Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k) <
            1.4901161193847656E-8) {
          Quadcopter_ControllerWithNavigation_B.lla0[0] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0];
          Quadcopter_ControllerWithNavigation_B.lla0[1] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1];
          Quadcopter_ControllerWithNavigation_B.lla0[2] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2];
          Quadcopter_ControllerWithNavigation_B.Gain_i =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[6];
          Quadcopter_ControllerWithNavigation_DW.obj.StartFlag = false;
        } else {
          Quadcopter_ControllerWithNavigation_DW.obj.StartFlag = false;
          Quadcopter_ControllerWithNavigation_DW.obj.NumWaypoints = 2.0;
          Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0 =
            Quadcopter_ControllerWithNavigation_B.ix + 1;
          for (Quadcopter_ControllerWithNavigation_B.j = 0;
               Quadcopter_ControllerWithNavigation_B.j < 3;
               Quadcopter_ControllerWithNavigation_B.j++) {
            Quadcopter_ControllerWithNavigation_B.i1 =
              (Quadcopter_ControllerWithNavigation_B.ix + 1) *
              Quadcopter_ControllerWithNavigation_B.j;
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[Quadcopter_ControllerWithNavigation_B.i1]
              =
              Quadcopter_ControllerWithNavigation_DW.obj.InitialPose[Quadcopter_ControllerWithNavigation_B.j];
            for (Quadcopter_ControllerWithNavigation_B.i2 = 0;
                 Quadcopter_ControllerWithNavigation_B.i2 <
                 Quadcopter_ControllerWithNavigation_B.ix;
                 Quadcopter_ControllerWithNavigation_B.i2++) {
              Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p
                [(Quadcopter_ControllerWithNavigation_B.i2 +
                  Quadcopter_ControllerWithNavigation_B.i1) + 1] =
                Quadcopter_ControllerWithNavigation_B.b_waypointsIn_data[Quadcopter_ControllerWithNavigation_B.ix
                * Quadcopter_ControllerWithNavigation_B.j +
                Quadcopter_ControllerWithNavigation_B.i2];
            }
          }

          guard1 = true;
        }
      } else {
        Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0 =
          Quadcopter_ControllerWithNavigation_B.ix;
        Quadcopter_ControllerWithNavigation_B.i1 =
          Quadcopter_ControllerWithNavigation_B.ix * 3;
        if (Quadcopter_ControllerWithNavigation_B.i1 - 1 >= 0) {
          memcpy(&Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[0],
                 &Quadcopter_ControllerWithNavigation_B.b_waypointsIn_data[0],
                 static_cast<uint32_T>(Quadcopter_ControllerWithNavigation_B.i1)
                 * sizeof(real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        Quadcopter_ControllerWithNavigation_B.latp2 = false;
        if (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex ==
            Quadcopter_ControllerWithNavigation_DW.obj.NumWaypoints) {
          Quadcopter_ControllerWithNavigation_B.latp2 = true;
        }

        if (Quadcopter_ControllerWithNavigation_B.latp2) {
          Quadcopter_ControllerWithNavigation_DW.obj.LastWaypointFlag = true;
          Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex--;
        }

        Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[0] =
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p
          [static_cast<int32_T>
          (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) - 1];
        Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[1] =
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
          static_cast<int32_T>
          (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) +
          Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0) - 1];
        Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[2] =
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
          static_cast<int32_T>
          (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) +
          (Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0 << 1)) - 1];
        guard2 = false;
        if (Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m) <= 2.0) {
          guard2 = true;
        } else {
          Quadcopter_ControllerWithNavigation_B.Gain_i =
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[
            static_cast<int32_T>
            (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) - 1];
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0] =
            Quadcopter_ControllerWithNavigation_B.Gain_i -
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[
            static_cast<int32_T>
            (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex) - 1];
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0] -
            Quadcopter_ControllerWithNavigation_B.Gain_i;
          Quadcopter_ControllerWithNavigation_B.Gain_i =
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
            static_cast<int32_T>
            (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) +
            Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0) - 1];
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1] =
            Quadcopter_ControllerWithNavigation_B.Gain_i -
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
            static_cast<int32_T>
            (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex) +
            Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0) - 1];
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1] -
            Quadcopter_ControllerWithNavigation_B.Gain_i;
          Quadcopter_ControllerWithNavigation_B.y_l =
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
            static_cast<int32_T>
            (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) +
            (Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0 << 1)) -
            1];
          Quadcopter_ControllerWithNavigation_B.lambda =
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p
            [((Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0 << 1)
              + static_cast<int32_T>
              (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex)) - 1];
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2] =
            Quadcopter_ControllerWithNavigation_B.y_l -
            Quadcopter_ControllerWithNavigation_B.lambda;
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
            Quadcopter_ControllerWithNavigation_B.y_l;
          Quadcopter_ControllerWithNavigation_B.b =
            Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k);
          Quadcopter_ControllerWithNavigation_B.Gain_i =
            Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1);
          Quadcopter_ControllerWithNavigation_B.Gain_i =
            (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0] /
             Quadcopter_ControllerWithNavigation_B.b *
             (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] /
              Quadcopter_ControllerWithNavigation_B.Gain_i) +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1] /
             Quadcopter_ControllerWithNavigation_B.b *
             (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1] /
              Quadcopter_ControllerWithNavigation_B.Gain_i)) +
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2] /
            Quadcopter_ControllerWithNavigation_B.b *
            (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2] /
             Quadcopter_ControllerWithNavigation_B.Gain_i);
          if (rtIsNaN(Quadcopter_ControllerWithNavigation_B.Gain_i) ||
              (Quadcopter_ControllerWithNavigation_B.Gain_i < 0.0)) {
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0] =
              Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[
              static_cast<int32_T>
              (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex) - 1];
            Quadcopter_ControllerWithNavigation_B.lla0[0] =
              Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[
              static_cast<int32_T>
              (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) -
              1];
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1] =
              Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
              static_cast<int32_T>
              (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex) +
              Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0) - 1];
            Quadcopter_ControllerWithNavigation_B.lla0[1] =
              Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
              static_cast<int32_T>
              (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) +
              Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0) - 1];
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2] =
              Quadcopter_ControllerWithNavigation_B.lambda;
            Quadcopter_ControllerWithNavigation_B.lla0[2] =
              Quadcopter_ControllerWithNavigation_B.y_l;
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex++;
          Quadcopter_ControllerWithNavigation_B.latp2 = false;
          if (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex ==
              Quadcopter_ControllerWithNavigation_DW.obj.NumWaypoints) {
            Quadcopter_ControllerWithNavigation_B.latp2 = true;
          }

          if (Quadcopter_ControllerWithNavigation_B.latp2) {
            Quadcopter_ControllerWithNavigation_DW.obj.LastWaypointFlag = true;
            Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex--;
          }

          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0] =
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[
            static_cast<int32_T>
            (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex) - 1];
          Quadcopter_ControllerWithNavigation_B.lla0[0] =
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[
            static_cast<int32_T>
            (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) - 1];
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1] =
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
            static_cast<int32_T>
            (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex) +
            Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0) - 1];
          Quadcopter_ControllerWithNavigation_B.lla0[1] =
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
            static_cast<int32_T>
            (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) +
            Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0) - 1];
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2] =
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p
            [((Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0 << 1)
              + static_cast<int32_T>
              (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex)) - 1];
          Quadcopter_ControllerWithNavigation_B.lla0[2] =
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
            static_cast<int32_T>
            (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) +
            (Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0 << 1)) -
            1];
        }

        Quadcopter_ControllerWithNavigation_B.Gain_i =
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0];
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] =
          Quadcopter_ControllerWithNavigation_B.Gain_i;
        Quadcopter_ControllerWithNavigation_B.b =
          Quadcopter_ControllerWithNavigation_B.lla0[0] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0];
        Quadcopter_ControllerWithNavigation_B.b_varargout_3[0] =
          Quadcopter_ControllerWithNavigation_B.b;
        Quadcopter_ControllerWithNavigation_B.lambda =
          Quadcopter_ControllerWithNavigation_B.Gain_i *
          Quadcopter_ControllerWithNavigation_B.b;
        Quadcopter_ControllerWithNavigation_B.y_l =
          Quadcopter_ControllerWithNavigation_B.b *
          Quadcopter_ControllerWithNavigation_B.b;
        Quadcopter_ControllerWithNavigation_B.Filter =
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1];
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1] =
          Quadcopter_ControllerWithNavigation_B.Filter;
        Quadcopter_ControllerWithNavigation_B.b =
          Quadcopter_ControllerWithNavigation_B.lla0[1] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1];
        Quadcopter_ControllerWithNavigation_B.b_varargout_3[1] =
          Quadcopter_ControllerWithNavigation_B.b;
        Quadcopter_ControllerWithNavigation_B.lambda +=
          Quadcopter_ControllerWithNavigation_B.Filter *
          Quadcopter_ControllerWithNavigation_B.b;
        Quadcopter_ControllerWithNavigation_B.y_l +=
          Quadcopter_ControllerWithNavigation_B.b *
          Quadcopter_ControllerWithNavigation_B.b;
        Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k =
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2];
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2] =
          Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k;
        Quadcopter_ControllerWithNavigation_B.b =
          Quadcopter_ControllerWithNavigation_B.lla0[2] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2];
        Quadcopter_ControllerWithNavigation_B.y_l +=
          Quadcopter_ControllerWithNavigation_B.b *
          Quadcopter_ControllerWithNavigation_B.b;
        Quadcopter_ControllerWithNavigation_B.lambda =
          (Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k *
           Quadcopter_ControllerWithNavigation_B.b +
           Quadcopter_ControllerWithNavigation_B.lambda) /
          Quadcopter_ControllerWithNavigation_B.y_l;
        if (Quadcopter_ControllerWithNavigation_B.lambda < 0.0) {
          Quadcopter_ControllerWithNavigation_B.lambda =
            Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1);
        } else if (Quadcopter_ControllerWithNavigation_B.lambda > 1.0) {
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[0] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0] -
            Quadcopter_ControllerWithNavigation_B.lla0[0];
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[1] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1] -
            Quadcopter_ControllerWithNavigation_B.lla0[1];
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[2] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
            Quadcopter_ControllerWithNavigation_B.lla0[2];
          Quadcopter_ControllerWithNavigation_B.lambda =
            Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m);
        } else {
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[0] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b_varargout_3[0] +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0]);
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[1] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b_varargout_3[1] +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1]);
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[2] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2]);
          Quadcopter_ControllerWithNavigation_B.lambda =
            Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m);
        }

        if (Quadcopter_ControllerWithNavigation_DW.obj.LastWaypointFlag) {
          Quadcopter_ControllerWithNavigation_B.lambda =
            ((Quadcopter_ControllerWithNavigation_B.Gain_i *
              Quadcopter_ControllerWithNavigation_B.b_varargout_3[0] +
              Quadcopter_ControllerWithNavigation_B.Filter *
              Quadcopter_ControllerWithNavigation_B.b_varargout_3[1]) +
             Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k *
             Quadcopter_ControllerWithNavigation_B.b) /
            Quadcopter_ControllerWithNavigation_B.y_l;
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[0] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b_varargout_3[0] +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0]);
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[1] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b_varargout_3[1] +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1]);
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m[2] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2]);
          Quadcopter_ControllerWithNavigation_B.lambda =
            Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_m);
        }

        Quadcopter_ControllerWithNavigation_B.Gain_i = fabs
          (Quadcopter_ControllerWithNavigation_B.lambda);
        if (rtIsInf(Quadcopter_ControllerWithNavigation_B.Gain_i) || rtIsNaN
            (Quadcopter_ControllerWithNavigation_B.Gain_i)) {
          Quadcopter_ControllerWithNavigation_B.Filter = (rtNaN);
          Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k = (rtNaN);
        } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
                   4.4501477170144028E-308) {
          Quadcopter_ControllerWithNavigation_B.Filter = 4.94065645841247E-324;
          Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k =
            4.94065645841247E-324;
        } else {
          frexp(Quadcopter_ControllerWithNavigation_B.Gain_i,
                &Quadcopter_ControllerWithNavigation_B.b_exponent);
          Quadcopter_ControllerWithNavigation_B.Filter = ldexp(1.0,
            Quadcopter_ControllerWithNavigation_B.b_exponent - 53);
          frexp(Quadcopter_ControllerWithNavigation_B.Gain_i,
                &Quadcopter_ControllerWithNavigation_B.b_exponent_o);
          Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k = ldexp(1.0,
            Quadcopter_ControllerWithNavigation_B.b_exponent_o - 53);
        }

        Quadcopter_ControllerWithNavigation_B.Gain_i = sqrt
          (Quadcopter_ControllerWithNavigation_B.Filter);
        Quadcopter_ControllerWithNavigation_B.Filter = 5.0 *
          Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k;
        if ((Quadcopter_ControllerWithNavigation_B.Gain_i >=
             Quadcopter_ControllerWithNavigation_B.Filter) || rtIsNaN
            (Quadcopter_ControllerWithNavigation_B.Filter)) {
          Quadcopter_ControllerWithNavigation_B.Filter =
            Quadcopter_ControllerWithNavigation_B.Gain_i;
        }

        if (Quadcopter_ControllerWithNavigation_DW.obj.LookaheadDistance <=
            Quadcopter_ControllerWithNavigation_B.lambda +
            Quadcopter_ControllerWithNavigation_B.Filter) {
          Quadcopter_ControllerWithNavigation_DW.obj.LookaheadDistance =
            Quadcopter_ControllerWithNavigation_DW.obj.LookaheadFactor *
            Quadcopter_ControllerWithNavigation_B.lambda;
        }

        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] =
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0] -
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0];
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1] =
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1] -
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1];
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2] =
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2] -
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2];
        Quadcopter_ControllerWithNavigation_B.b =
          ((Quadcopter_ControllerWithNavigation_B.b_varargout_3[0] *
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] +
            Quadcopter_ControllerWithNavigation_B.b_varargout_3[1] *
            Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1]) +
           Quadcopter_ControllerWithNavigation_B.b *
           Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2]) * 2.0;
        Quadcopter_ControllerWithNavigation_B.lambda = sqrt
          (Quadcopter_ControllerWithNavigation_B.b *
           Quadcopter_ControllerWithNavigation_B.b -
           (((Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] *
              Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] +
              Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1] *
              Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1]) +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2] *
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2]) -
            Quadcopter_ControllerWithNavigation_DW.obj.LookaheadDistance *
            Quadcopter_ControllerWithNavigation_DW.obj.LookaheadDistance) * (4.0
            * Quadcopter_ControllerWithNavigation_B.y_l));
        Quadcopter_ControllerWithNavigation_B.Gain_i =
          (-Quadcopter_ControllerWithNavigation_B.b +
           Quadcopter_ControllerWithNavigation_B.lambda) / 2.0 /
          Quadcopter_ControllerWithNavigation_B.y_l;
        Quadcopter_ControllerWithNavigation_B.y_l =
          (-Quadcopter_ControllerWithNavigation_B.b -
           Quadcopter_ControllerWithNavigation_B.lambda) / 2.0 /
          Quadcopter_ControllerWithNavigation_B.y_l;
        if ((Quadcopter_ControllerWithNavigation_B.Gain_i >=
             Quadcopter_ControllerWithNavigation_B.y_l) || rtIsNaN
            (Quadcopter_ControllerWithNavigation_B.y_l)) {
          Quadcopter_ControllerWithNavigation_B.y_l =
            Quadcopter_ControllerWithNavigation_B.Gain_i;
        }

        Quadcopter_ControllerWithNavigation_B.lla0[0] = (1.0 -
          Quadcopter_ControllerWithNavigation_B.y_l) *
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0] +
          Quadcopter_ControllerWithNavigation_B.y_l *
          Quadcopter_ControllerWithNavigation_B.lla0[0];
        Quadcopter_ControllerWithNavigation_B.lla0[1] = (1.0 -
          Quadcopter_ControllerWithNavigation_B.y_l) *
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1] +
          Quadcopter_ControllerWithNavigation_B.y_l *
          Quadcopter_ControllerWithNavigation_B.lla0[1];
        Quadcopter_ControllerWithNavigation_B.lla0[2] = (1.0 -
          Quadcopter_ControllerWithNavigation_B.y_l) *
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2] +
          Quadcopter_ControllerWithNavigation_B.y_l *
          Quadcopter_ControllerWithNavigation_B.lla0[2];
        Quadcopter_ControllerWithNavigation_B.Gain_i =
          Quadcopter_ControllerWithNavigation_rt_atan2d_snf
          (Quadcopter_ControllerWithNavigation_B.lla0[1] -
           Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1],
           Quadcopter_ControllerWithNavigation_B.lla0[0] -
           Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0]);
        Quadcopter_ControllerWithNavigation_DW.obj.LastWaypointFlag = false;
      }
    }

    // Switch: '<S31>/Switch1' incorporates:
    //   Constant: '<S32>/Constant'
    //   Logic: '<S31>/OR'
    //   Logic: '<S31>/OR1'
    //   MATLABSystem: '<S21>/UAV Waypoint Follower'
    //   RelationalOperator: '<S31>/IsNaN'
    //   RelationalOperator: '<S31>/IsNaN1'
    //   RelationalOperator: '<S32>/Compare'
    //   Switch: '<S31>/Switch'
    //
    if (rtIsNaN(Quadcopter_ControllerWithNavigation_B.lla0[0]) || rtIsNaN
        (Quadcopter_ControllerWithNavigation_B.lla0[1]) || rtIsNaN
        (Quadcopter_ControllerWithNavigation_B.lla0[2]) ||
        (Quadcopter_ControllerWithNavigation_B.In1_p.current.type ==
         Quadcopter_ControllerWithNavigation_P.CompareToConstant_const)) {
      // Merge: '<S16>/Merge' incorporates:
      //   Reshape: '<S31>/Reshape3'

      Quadcopter_ControllerWithNavigation_B.Merge[0] =
        Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0];
      Quadcopter_ControllerWithNavigation_B.Merge[1] =
        Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1];
      Quadcopter_ControllerWithNavigation_B.Merge[2] =
        Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2];
      Quadcopter_ControllerWithNavigation_B.Merge[3] =
        Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[6];
    } else {
      if (rtIsNaN(Quadcopter_ControllerWithNavigation_B.Gain_i)) {
        // Switch: '<S31>/Switch' incorporates:
        //   Constant: '<S31>/Constant'
        //   Merge: '<S16>/Merge'
        //   Reshape: '<S31>/Reshape2'

        Quadcopter_ControllerWithNavigation_B.Merge[3] =
          Quadcopter_ControllerWithNavigation_P.Constant_Value_jd;
      } else {
        // Reshape: '<S31>/Reshape2' incorporates:
        //   Merge: '<S16>/Merge'
        //   Switch: '<S31>/Switch'

        Quadcopter_ControllerWithNavigation_B.Merge[3] =
          Quadcopter_ControllerWithNavigation_B.Gain_i;
      }

      // Math: '<S31>/Transpose1' incorporates:
      //   Merge: '<S16>/Merge'

      Quadcopter_ControllerWithNavigation_B.Merge[0] =
        Quadcopter_ControllerWithNavigation_B.lla0[0];
      Quadcopter_ControllerWithNavigation_B.Merge[1] =
        Quadcopter_ControllerWithNavigation_B.lla0[1];
      Quadcopter_ControllerWithNavigation_B.Merge[2] =
        Quadcopter_ControllerWithNavigation_B.lla0[2];
    }

    // End of Switch: '<S31>/Switch1'
    srUpdateBC(Quadcopter_ControllerWithNavigation_DW.Waypoint_SubsysRanBC);

    // End of Outputs for SubSystem: '<S16>/Waypoint'
    break;

   default:
    if (Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem !=
        Quadcopter_ControllerWithNavigation_B.rtPrevAction) {
      // InitializeConditions for IfAction SubSystem: '<S16>/IDLE' incorporates:
      //   ActionPort: '<S18>/Action Port'

      // InitializeConditions for If: '<S16>/If' incorporates:
      //   Delay: '<S22>/Delay'

      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_i =
        Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_g0;

      // End of InitializeConditions for SubSystem: '<S16>/IDLE'
    }

    // Outputs for IfAction SubSystem: '<S16>/IDLE' incorporates:
    //   ActionPort: '<S18>/Action Port'

    // Outputs for Enabled SubSystem: '<S22>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S23>/Enable'

    if (Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_i > 0.0) {
      // SignalConversion generated from: '<S23>/yaw_In'
      Quadcopter_ControllerWithNavigation_B.yaw_In =
        Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[6];
      srUpdateBC
        (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem2_SubsysRanBC);
    }

    // End of Outputs for SubSystem: '<S22>/Enabled Subsystem2'

    // Merge: '<S16>/Merge' incorporates:
    //   Delay: '<S22>/Delay'
    //   Reshape: '<S18>/Reshape1'

    Quadcopter_ControllerWithNavigation_B.Merge[0] =
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0];
    Quadcopter_ControllerWithNavigation_B.Merge[1] =
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1];
    Quadcopter_ControllerWithNavigation_B.Merge[2] =
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2];
    Quadcopter_ControllerWithNavigation_B.Merge[3] =
      Quadcopter_ControllerWithNavigation_B.yaw_In;

    // Update for Delay: '<S22>/Delay' incorporates:
    //   Constant: '<S22>/Constant'

    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_i =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_i;
    srUpdateBC(Quadcopter_ControllerWithNavigation_DW.IDLE_SubsysRanBC);

    // End of Outputs for SubSystem: '<S16>/IDLE'
    break;
  }

  // End of If: '<S16>/If'

  // Gain: '<S52>/Gain'
  Quadcopter_ControllerWithNavigation_B.desiredZ =
    Quadcopter_ControllerWithNavigation_P.Gain_Gain_c *
    Quadcopter_ControllerWithNavigation_B.Merge[2];

  // MATLABSystem: '<S8>/SourceBlock'
  Quadcopter_ControllerWithNavigation_B.latp2 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_gv.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_gv.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_p, false, 1.0);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  // Start for MATLABSystem: '<S8>/SourceBlock'
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    // SignalConversion generated from: '<S12>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_m =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_p;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_d3);
  }

  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'

  // DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
  //   SignalConversion generated from: '<S5>/Product1'

  Quadcopter_ControllerWithNavigation_B.Gain_i =
    Quadcopter_ControllerWithNavigation_B.In1_m.q[0];
  Quadcopter_ControllerWithNavigation_B.lambda =
    Quadcopter_ControllerWithNavigation_B.In1_m.q[1];
  Quadcopter_ControllerWithNavigation_B.b =
    Quadcopter_ControllerWithNavigation_B.In1_m.q[2];
  Quadcopter_ControllerWithNavigation_B.y_l =
    Quadcopter_ControllerWithNavigation_B.In1_m.q[3];

  // Switch: '<S67>/Switch' incorporates:
  //   Constant: '<S67>/Constant'
  //   DataTypeConversion: '<S2>/Data Type Conversion'
  //   Product: '<S591>/Product'
  //   Product: '<S591>/Product1'
  //   Product: '<S591>/Product2'
  //   Product: '<S591>/Product3'
  //   SignalConversion generated from: '<S5>/Product1'
  //   Sum: '<S591>/Sum'

  if (!(((static_cast<real_T>(Quadcopter_ControllerWithNavigation_B.In1_m.q[0]) *
          Quadcopter_ControllerWithNavigation_B.In1_m.q[0] + static_cast<real_T>
          (Quadcopter_ControllerWithNavigation_B.In1_m.q[1]) *
          Quadcopter_ControllerWithNavigation_B.In1_m.q[1]) + static_cast<real_T>
         (Quadcopter_ControllerWithNavigation_B.In1_m.q[2]) *
         Quadcopter_ControllerWithNavigation_B.In1_m.q[2]) + static_cast<real_T>
        (Quadcopter_ControllerWithNavigation_B.In1_m.q[3]) *
        Quadcopter_ControllerWithNavigation_B.In1_m.q[3] >
        Quadcopter_ControllerWithNavigation_P.Switch_Threshold_l)) {
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_im[0];
    Quadcopter_ControllerWithNavigation_B.lambda =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_im[1];
    Quadcopter_ControllerWithNavigation_B.b =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_im[2];
    Quadcopter_ControllerWithNavigation_B.y_l =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_im[3];
  }

  // End of Switch: '<S67>/Switch'

  // Sqrt: '<S598>/sqrt' incorporates:
  //   Product: '<S599>/Product'
  //   Product: '<S599>/Product1'
  //   Product: '<S599>/Product2'
  //   Product: '<S599>/Product3'
  //   Sum: '<S599>/Sum'

  Quadcopter_ControllerWithNavigation_B.Filter = sqrt
    (((Quadcopter_ControllerWithNavigation_B.Gain_i *
       Quadcopter_ControllerWithNavigation_B.Gain_i +
       Quadcopter_ControllerWithNavigation_B.lambda *
       Quadcopter_ControllerWithNavigation_B.lambda) +
      Quadcopter_ControllerWithNavigation_B.b *
      Quadcopter_ControllerWithNavigation_B.b) +
     Quadcopter_ControllerWithNavigation_B.y_l *
     Quadcopter_ControllerWithNavigation_B.y_l);

  // Product: '<S593>/Product'
  Quadcopter_ControllerWithNavigation_B.Gain_i /=
    Quadcopter_ControllerWithNavigation_B.Filter;

  // Product: '<S593>/Product1'
  Quadcopter_ControllerWithNavigation_B.lambda /=
    Quadcopter_ControllerWithNavigation_B.Filter;

  // Product: '<S593>/Product2'
  Quadcopter_ControllerWithNavigation_B.b /=
    Quadcopter_ControllerWithNavigation_B.Filter;

  // Product: '<S593>/Product3'
  Quadcopter_ControllerWithNavigation_B.Filter =
    Quadcopter_ControllerWithNavigation_B.y_l /
    Quadcopter_ControllerWithNavigation_B.Filter;

  // Fcn: '<S68>/fcn2' incorporates:
  //   Fcn: '<S68>/fcn5'

  Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k =
    Quadcopter_ControllerWithNavigation_B.Gain_i *
    Quadcopter_ControllerWithNavigation_B.Gain_i;
  Quadcopter_ControllerWithNavigation_B.Filter_o =
    Quadcopter_ControllerWithNavigation_B.lambda *
    Quadcopter_ControllerWithNavigation_B.lambda;
  Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp =
    Quadcopter_ControllerWithNavigation_B.b *
    Quadcopter_ControllerWithNavigation_B.b;
  Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp_j =
    Quadcopter_ControllerWithNavigation_B.Filter *
    Quadcopter_ControllerWithNavigation_B.Filter;

  // Trigonometry: '<S592>/Trigonometric Function1' incorporates:
  //   Concatenate: '<S592>/Vector Concatenate'
  //   Fcn: '<S68>/fcn1'
  //   Fcn: '<S68>/fcn2'

  Quadcopter_ControllerWithNavigation_B.VectorConcatenate[0] =
    Quadcopter_ControllerWithNavigation_rt_atan2d_snf
    ((Quadcopter_ControllerWithNavigation_B.lambda *
      Quadcopter_ControllerWithNavigation_B.b +
      Quadcopter_ControllerWithNavigation_B.Gain_i *
      Quadcopter_ControllerWithNavigation_B.Filter) * 2.0,
     ((Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k +
       Quadcopter_ControllerWithNavigation_B.Filter_o) -
      Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp) -
     Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp_j);

  // Fcn: '<S68>/fcn3'
  Quadcopter_ControllerWithNavigation_B.y_l =
    (Quadcopter_ControllerWithNavigation_B.lambda *
     Quadcopter_ControllerWithNavigation_B.Filter -
     Quadcopter_ControllerWithNavigation_B.Gain_i *
     Quadcopter_ControllerWithNavigation_B.b) * -2.0;

  // If: '<S594>/If' incorporates:
  //   Constant: '<S595>/Constant'
  //   Constant: '<S596>/Constant'

  if (Quadcopter_ControllerWithNavigation_B.y_l > 1.0) {
    // Outputs for IfAction SubSystem: '<S594>/If Action Subsystem' incorporates:
    //   ActionPort: '<S595>/Action Port'

    Quadcopter_ControllerWithNavigation_B.y_l =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_be;

    // End of Outputs for SubSystem: '<S594>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S594>/If Action Subsystem' incorporates:
    //   ActionPort: '<S595>/Action Port'

    // Update for If: '<S594>/If' incorporates:
    //   Constant: '<S595>/Constant'

    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S594>/If Action Subsystem'
  } else if (Quadcopter_ControllerWithNavigation_B.y_l < -1.0) {
    // Outputs for IfAction SubSystem: '<S594>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S596>/Action Port'

    Quadcopter_ControllerWithNavigation_B.y_l =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_m;

    // End of Outputs for SubSystem: '<S594>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S594>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S596>/Action Port'

    // Update for If: '<S594>/If' incorporates:
    //   Constant: '<S596>/Constant'

    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S594>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S594>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S597>/Action Port'

    // Update for If: '<S594>/If'
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S594>/If Action Subsystem2'
  }

  // End of If: '<S594>/If'

  // Trigonometry: '<S592>/trigFcn' incorporates:
  //   Concatenate: '<S592>/Vector Concatenate'

  if (Quadcopter_ControllerWithNavigation_B.y_l > 1.0) {
    Quadcopter_ControllerWithNavigation_B.y_l = 1.0;
  } else if (Quadcopter_ControllerWithNavigation_B.y_l < -1.0) {
    Quadcopter_ControllerWithNavigation_B.y_l = -1.0;
  }

  Quadcopter_ControllerWithNavigation_B.VectorConcatenate[1] = asin
    (Quadcopter_ControllerWithNavigation_B.y_l);

  // End of Trigonometry: '<S592>/trigFcn'

  // Trigonometry: '<S592>/Trigonometric Function3' incorporates:
  //   Concatenate: '<S592>/Vector Concatenate'
  //   Fcn: '<S68>/fcn4'
  //   Fcn: '<S68>/fcn5'

  Quadcopter_ControllerWithNavigation_B.VectorConcatenate[2] =
    Quadcopter_ControllerWithNavigation_rt_atan2d_snf
    ((Quadcopter_ControllerWithNavigation_B.b *
      Quadcopter_ControllerWithNavigation_B.Filter +
      Quadcopter_ControllerWithNavigation_B.Gain_i *
      Quadcopter_ControllerWithNavigation_B.lambda) * 2.0,
     ((Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k -
       Quadcopter_ControllerWithNavigation_B.Filter_o) -
      Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp) +
     Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp_j);

  // Outputs for Enabled SubSystem: '<S52>/Position & Altitude controller' incorporates:
  //   EnablePort: '<S66>/Enable'

  if (Quadcopter_ControllerWithNavigation_B.In1_b.armed) {
    // Gain: '<S388>/Gain1'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_P.Gain1_Gain_o *
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2];

    // Switch: '<S394>/Switch' incorporates:
    //   Constant: '<S388>/Constant'
    //   RelationalOperator: '<S394>/UpperRelop'
    //   Switch: '<S394>/Switch2'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i <
        Quadcopter_ControllerWithNavigation_P.Constant_Value_j4) {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_j4;
    }

    // Sum: '<S66>/Sum2' incorporates:
    //   Switch: '<S394>/Switch'
    //   Switch: '<S394>/Switch2'

    Quadcopter_ControllerWithNavigation_B.y_l =
      Quadcopter_ControllerWithNavigation_B.desiredZ -
      Quadcopter_ControllerWithNavigation_B.Gain_i;

    // Gain: '<S529>/Proportional Gain'
    Quadcopter_ControllerWithNavigation_B.Filter =
      Quadcopter_ControllerWithNavigation_P.PID_Altitude_P *
      Quadcopter_ControllerWithNavigation_B.y_l;

    // Gain: '<S527>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S519>/Filter'
    //   Gain: '<S518>/Derivative Gain'
    //   Sum: '<S519>/SumD'

    Quadcopter_ControllerWithNavigation_B.b =
      (Quadcopter_ControllerWithNavigation_P.PID_Altitude_D *
       Quadcopter_ControllerWithNavigation_B.y_l -
       Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE) *
      Quadcopter_ControllerWithNavigation_P.PID_Altitude_N;

    // Sum: '<S534>/Sum Fdbk'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_B.Filter +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE) +
      Quadcopter_ControllerWithNavigation_B.b;

    // DeadZone: '<S517>/DeadZone'
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.PID_Altitude_UpperSaturationLimit)
    {
      Quadcopter_ControllerWithNavigation_B.Gain_i -=
        Quadcopter_ControllerWithNavigation_P.PID_Altitude_UpperSaturationLimit;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i >=
               Quadcopter_ControllerWithNavigation_P.PID_Altitude_LowerSaturationLimit)
    {
      Quadcopter_ControllerWithNavigation_B.Gain_i = 0.0;
    } else {
      Quadcopter_ControllerWithNavigation_B.Gain_i -=
        Quadcopter_ControllerWithNavigation_P.PID_Altitude_LowerSaturationLimit;
    }

    // End of DeadZone: '<S517>/DeadZone'

    // Gain: '<S521>/Integral Gain'
    Quadcopter_ControllerWithNavigation_B.y_l *=
      Quadcopter_ControllerWithNavigation_P.PID_Altitude_I;

    // Switch: '<S515>/Switch1' incorporates:
    //   Constant: '<S515>/Clamping_zero'
    //   Constant: '<S515>/Constant'
    //   Constant: '<S515>/Constant2'
    //   RelationalOperator: '<S515>/fix for DT propagation issue'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_m) {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_hk;
    } else {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant2_Value_l;
    }

    // Switch: '<S515>/Switch2' incorporates:
    //   Constant: '<S515>/Clamping_zero'
    //   Constant: '<S515>/Constant3'
    //   Constant: '<S515>/Constant4'
    //   RelationalOperator: '<S515>/fix for DT propagation issue1'

    if (Quadcopter_ControllerWithNavigation_B.y_l >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_m) {
      Quadcopter_ControllerWithNavigation_B.i2_b =
        Quadcopter_ControllerWithNavigation_P.Constant3_Value_gn;
    } else {
      Quadcopter_ControllerWithNavigation_B.i2_b =
        Quadcopter_ControllerWithNavigation_P.Constant4_Value_g;
    }

    // Switch: '<S515>/Switch' incorporates:
    //   Constant: '<S515>/Clamping_zero'
    //   Constant: '<S515>/Constant1'
    //   Logic: '<S515>/AND3'
    //   RelationalOperator: '<S515>/Equal1'
    //   RelationalOperator: '<S515>/Relational Operator'
    //   Switch: '<S515>/Switch1'
    //   Switch: '<S515>/Switch2'

    if ((Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_m !=
         Quadcopter_ControllerWithNavigation_B.Gain_i) &&
        (Quadcopter_ControllerWithNavigation_B.rtPrevAction ==
         Quadcopter_ControllerWithNavigation_B.i2_b)) {
      Quadcopter_ControllerWithNavigation_B.y_l =
        Quadcopter_ControllerWithNavigation_P.Constant1_Value_f;
    }

    // DiscreteIntegrator: '<S524>/Integrator' incorporates:
    //   Switch: '<S515>/Switch'

    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE +=
      Quadcopter_ControllerWithNavigation_P.Integrator_gainval_a *
      Quadcopter_ControllerWithNavigation_B.y_l;

    // Sum: '<S533>/Sum'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_B.Filter +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE) +
      Quadcopter_ControllerWithNavigation_B.b;

    // Saturate: '<S531>/Saturation'
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.PID_Altitude_UpperSaturationLimit)
    {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.PID_Altitude_UpperSaturationLimit;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
               Quadcopter_ControllerWithNavigation_P.PID_Altitude_LowerSaturationLimit)
    {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.PID_Altitude_LowerSaturationLimit;
    }

    // Sum: '<S66>/Sum3' incorporates:
    //   Saturate: '<S531>/Saturation'
    //   UnaryMinus: '<S66>/Unary Minus'

    Quadcopter_ControllerWithNavigation_B.Filter =
      Quadcopter_ControllerWithNavigation_B.Gain_i -
      (-Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[5]);

    // Gain: '<S579>/Proportional Gain'
    Quadcopter_ControllerWithNavigation_B.y_l =
      Quadcopter_ControllerWithNavigation_P.PID_vz_P *
      Quadcopter_ControllerWithNavigation_B.Filter;

    // Gain: '<S577>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S569>/Filter'
    //   Gain: '<S568>/Derivative Gain'
    //   Sum: '<S569>/SumD'

    Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k =
      (Quadcopter_ControllerWithNavigation_P.PID_vz_D *
       Quadcopter_ControllerWithNavigation_B.Filter -
       Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_m) *
      Quadcopter_ControllerWithNavigation_P.PID_vz_N;

    // Sum: '<S584>/Sum Fdbk'
    Quadcopter_ControllerWithNavigation_B.lambda =
      (Quadcopter_ControllerWithNavigation_B.y_l +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_c) +
      Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k;

    // DeadZone: '<S567>/DeadZone'
    if (Quadcopter_ControllerWithNavigation_B.lambda >
        Quadcopter_ControllerWithNavigation_P.PID_vz_UpperSaturationLimit) {
      Quadcopter_ControllerWithNavigation_B.lambda -=
        Quadcopter_ControllerWithNavigation_P.PID_vz_UpperSaturationLimit;
    } else if (Quadcopter_ControllerWithNavigation_B.lambda >=
               Quadcopter_ControllerWithNavigation_P.PID_vz_LowerSaturationLimit)
    {
      Quadcopter_ControllerWithNavigation_B.lambda = 0.0;
    } else {
      Quadcopter_ControllerWithNavigation_B.lambda -=
        Quadcopter_ControllerWithNavigation_P.PID_vz_LowerSaturationLimit;
    }

    // End of DeadZone: '<S567>/DeadZone'

    // Gain: '<S571>/Integral Gain'
    Quadcopter_ControllerWithNavigation_B.Filter *=
      Quadcopter_ControllerWithNavigation_P.PID_vz_I;

    // Switch: '<S565>/Switch1' incorporates:
    //   Constant: '<S565>/Clamping_zero'
    //   Constant: '<S565>/Constant'
    //   Constant: '<S565>/Constant2'
    //   RelationalOperator: '<S565>/fix for DT propagation issue'

    if (Quadcopter_ControllerWithNavigation_B.lambda >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_et) {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_mp;
    } else {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant2_Value_k;
    }

    // Switch: '<S565>/Switch2' incorporates:
    //   Constant: '<S565>/Clamping_zero'
    //   Constant: '<S565>/Constant3'
    //   Constant: '<S565>/Constant4'
    //   RelationalOperator: '<S565>/fix for DT propagation issue1'

    if (Quadcopter_ControllerWithNavigation_B.Filter >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_et) {
      Quadcopter_ControllerWithNavigation_B.i2_b =
        Quadcopter_ControllerWithNavigation_P.Constant3_Value_i;
    } else {
      Quadcopter_ControllerWithNavigation_B.i2_b =
        Quadcopter_ControllerWithNavigation_P.Constant4_Value_ja;
    }

    // Switch: '<S565>/Switch' incorporates:
    //   Constant: '<S565>/Clamping_zero'
    //   Constant: '<S565>/Constant1'
    //   Logic: '<S565>/AND3'
    //   RelationalOperator: '<S565>/Equal1'
    //   RelationalOperator: '<S565>/Relational Operator'
    //   Switch: '<S565>/Switch1'
    //   Switch: '<S565>/Switch2'

    if ((Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_et !=
         Quadcopter_ControllerWithNavigation_B.lambda) &&
        (Quadcopter_ControllerWithNavigation_B.rtPrevAction ==
         Quadcopter_ControllerWithNavigation_B.i2_b)) {
      Quadcopter_ControllerWithNavigation_B.Filter =
        Quadcopter_ControllerWithNavigation_P.Constant1_Value_o;
    }

    // DiscreteIntegrator: '<S574>/Integrator' incorporates:
    //   Switch: '<S565>/Switch'

    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_c +=
      Quadcopter_ControllerWithNavigation_P.Integrator_gainval_g *
      Quadcopter_ControllerWithNavigation_B.Filter;

    // Sum: '<S583>/Sum'
    Quadcopter_ControllerWithNavigation_B.Saturation =
      (Quadcopter_ControllerWithNavigation_B.y_l +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_c) +
      Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k;

    // Saturate: '<S581>/Saturation'
    if (Quadcopter_ControllerWithNavigation_B.Saturation >
        Quadcopter_ControllerWithNavigation_P.PID_vz_UpperSaturationLimit) {
      // Sum: '<S583>/Sum' incorporates:
      //   Saturate: '<S581>/Saturation'

      Quadcopter_ControllerWithNavigation_B.Saturation =
        Quadcopter_ControllerWithNavigation_P.PID_vz_UpperSaturationLimit;
    } else if (Quadcopter_ControllerWithNavigation_B.Saturation <
               Quadcopter_ControllerWithNavigation_P.PID_vz_LowerSaturationLimit)
    {
      // Sum: '<S583>/Sum' incorporates:
      //   Saturate: '<S581>/Saturation'

      Quadcopter_ControllerWithNavigation_B.Saturation =
        Quadcopter_ControllerWithNavigation_P.PID_vz_LowerSaturationLimit;
    }

    // End of Saturate: '<S581>/Saturation'

    // Trigonometry: '<S389>/SinCos'
    Quadcopter_ControllerWithNavigation_B.y_l = sin
      (Quadcopter_ControllerWithNavigation_B.VectorConcatenate[0]);
    Quadcopter_ControllerWithNavigation_B.Filter = cos
      (Quadcopter_ControllerWithNavigation_B.VectorConcatenate[0]);

    // Saturate: '<S481>/Saturation' incorporates:
    //   Gain: '<S479>/Proportional Gain'
    //   Sum: '<S66>/Sum1'

    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_B.Merge[0] -
       Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0]) *
      Quadcopter_ControllerWithNavigation_P.PIDController1_P_f;
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.PIDController1_UpperSaturationLimit_h)
    {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.PIDController1_UpperSaturationLimit_h;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
               Quadcopter_ControllerWithNavigation_P.PIDController1_LowerSaturationLimit_j)
    {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.PIDController1_LowerSaturationLimit_j;
    }

    // Sum: '<S66>/Sum' incorporates:
    //   Saturate: '<S481>/Saturation'
    //   Sum: '<S66>/Sum1'

    Quadcopter_ControllerWithNavigation_B.lambda =
      Quadcopter_ControllerWithNavigation_B.Gain_i -
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[3];

    // Saturate: '<S481>/Saturation' incorporates:
    //   Gain: '<S479>/Proportional Gain'
    //   Sum: '<S66>/Sum1'

    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_B.Merge[1] -
       Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1]) *
      Quadcopter_ControllerWithNavigation_P.PIDController1_P_f;
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.PIDController1_UpperSaturationLimit_h)
    {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.PIDController1_UpperSaturationLimit_h;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
               Quadcopter_ControllerWithNavigation_P.PIDController1_LowerSaturationLimit_j)
    {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.PIDController1_LowerSaturationLimit_j;
    }

    // Sum: '<S66>/Sum' incorporates:
    //   Saturate: '<S481>/Saturation'
    //   Sum: '<S66>/Sum1'

    Quadcopter_ControllerWithNavigation_B.Filter_o =
      Quadcopter_ControllerWithNavigation_B.Gain_i -
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[4];

    // Saturate: '<S433>/Saturation' incorporates:
    //   Gain: '<S389>/Gain'
    //   Gain: '<S431>/Proportional Gain'
    //   Product: '<S66>/MatrixMultiply'
    //   Reshape: '<S389>/Reshape'
    //   Reshape: '<S389>/Reshape1'

    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_B.Filter *
       Quadcopter_ControllerWithNavigation_B.lambda +
       Quadcopter_ControllerWithNavigation_B.y_l *
       Quadcopter_ControllerWithNavigation_B.Filter_o) *
      Quadcopter_ControllerWithNavigation_P.PIDController_P_n;
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit_i)
    {
      // Saturate: '<S433>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[0] =
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit_i;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
               Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit_f)
    {
      // Saturate: '<S433>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[0] =
        Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit_f;
    } else {
      // Saturate: '<S433>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[0] =
        Quadcopter_ControllerWithNavigation_B.Gain_i;
    }

    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_P.Gain_Gain_l2 *
       Quadcopter_ControllerWithNavigation_B.y_l *
       Quadcopter_ControllerWithNavigation_B.lambda +
       Quadcopter_ControllerWithNavigation_B.Filter *
       Quadcopter_ControllerWithNavigation_B.Filter_o) *
      Quadcopter_ControllerWithNavigation_P.PIDController_P_n;
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit_i)
    {
      // Saturate: '<S433>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[1] =
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit_i;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
               Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit_f)
    {
      // Saturate: '<S433>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[1] =
        Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit_f;
    } else {
      // Saturate: '<S433>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[1] =
        Quadcopter_ControllerWithNavigation_B.Gain_i;
    }

    // End of Saturate: '<S433>/Saturation'

    // Gain: '<S66>/Gain1'
    Quadcopter_ControllerWithNavigation_B.Gain1 =
      Quadcopter_ControllerWithNavigation_P.Gain1_Gain_f *
      Quadcopter_ControllerWithNavigation_B.Saturation_n[0];

    // Update for DiscreteIntegrator: '<S519>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE +=
      Quadcopter_ControllerWithNavigation_P.Filter_gainval_g *
      Quadcopter_ControllerWithNavigation_B.b;

    // Update for DiscreteIntegrator: '<S569>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_m +=
      Quadcopter_ControllerWithNavigation_P.Filter_gainval_k *
      Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S52>/Position & Altitude controller'

  // MATLABSystem: '<S6>/SourceBlock'
  Quadcopter_ControllerWithNavigation_B.latp2 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_po.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_po.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S10>/Enable'

  // Start for MATLABSystem: '<S6>/SourceBlock'
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    // SignalConversion generated from: '<S10>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_l =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_c;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_a);
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // DataTypeConversion: '<S2>/Data Type Conversion2'
  Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[0] =
    Quadcopter_ControllerWithNavigation_B.In1_l.rollspeed;
  Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[1] =
    Quadcopter_ControllerWithNavigation_B.In1_l.pitchspeed;
  Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[2] =
    Quadcopter_ControllerWithNavigation_B.In1_l.yawspeed;

  // Outputs for Enabled SubSystem: '<S52>/Attitude controller' incorporates:
  //   EnablePort: '<S54>/Enable'

  if (Quadcopter_ControllerWithNavigation_B.In1_b.armed) {
    // Sum: '<S54>/Sum5'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_B.Merge[3] -
      Quadcopter_ControllerWithNavigation_B.VectorConcatenate[0];

    // Switch: '<S71>/Switch' incorporates:
    //   Abs: '<S71>/Abs'

    if (fabs(Quadcopter_ControllerWithNavigation_B.Gain_i) >
        Quadcopter_ControllerWithNavigation_P.Switch_Threshold_e) {
      // Switch: '<S71>/Switch1' incorporates:
      //   Constant: '<S71>/Constant'
      //   Sum: '<S71>/Add'
      //   Sum: '<S71>/Subtract'

      if (Quadcopter_ControllerWithNavigation_B.Gain_i >
          Quadcopter_ControllerWithNavigation_P.Switch1_Threshold) {
        Quadcopter_ControllerWithNavigation_B.Gain_i -=
          Quadcopter_ControllerWithNavigation_P.Constant_Value_p;
      } else {
        Quadcopter_ControllerWithNavigation_B.Gain_i +=
          Quadcopter_ControllerWithNavigation_P.Constant_Value_p;
      }

      // End of Switch: '<S71>/Switch1'
    }

    // Gain: '<S360>/Proportional Gain' incorporates:
    //   Switch: '<S71>/Switch'

    Quadcopter_ControllerWithNavigation_B.Gain_i *=
      Quadcopter_ControllerWithNavigation_P.PIDController5_P;

    // Saturate: '<S362>/Saturation'
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.PIDController5_UpperSaturationLimit)
    {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.PIDController5_UpperSaturationLimit;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
               Quadcopter_ControllerWithNavigation_P.PIDController5_LowerSaturationLimit)
    {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.PIDController5_LowerSaturationLimit;
    }

    // Sum: '<S54>/Sum4' incorporates:
    //   Saturate: '<S362>/Saturation'

    Quadcopter_ControllerWithNavigation_B.y_l =
      Quadcopter_ControllerWithNavigation_B.Gain_i -
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[2];

    // Gain: '<S114>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S106>/Filter'
    //   Gain: '<S105>/Derivative Gain'
    //   Sum: '<S106>/SumD'

    Quadcopter_ControllerWithNavigation_B.lambda =
      (Quadcopter_ControllerWithNavigation_P.PIDController_D *
       Quadcopter_ControllerWithNavigation_B.y_l -
       Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_f) *
      Quadcopter_ControllerWithNavigation_P.PIDController_N;

    // Sum: '<S120>/Sum' incorporates:
    //   DiscreteIntegrator: '<S111>/Integrator'
    //   Gain: '<S116>/Proportional Gain'

    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_P.PIDController_P *
       Quadcopter_ControllerWithNavigation_B.y_l +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_h) +
      Quadcopter_ControllerWithNavigation_B.lambda;

    // Saturate: '<S118>/Saturation' incorporates:
    //   DeadZone: '<S104>/DeadZone'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit)
    {
      // Saturate: '<S118>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_h =
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit;
      Quadcopter_ControllerWithNavigation_B.Gain_i -=
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit;
    } else {
      if (Quadcopter_ControllerWithNavigation_B.Gain_i <
          Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit)
      {
        // Saturate: '<S118>/Saturation'
        Quadcopter_ControllerWithNavigation_B.Saturation_h =
          Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit;
      } else {
        // Saturate: '<S118>/Saturation'
        Quadcopter_ControllerWithNavigation_B.Saturation_h =
          Quadcopter_ControllerWithNavigation_B.Gain_i;
      }

      if (Quadcopter_ControllerWithNavigation_B.Gain_i >=
          Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit)
      {
        Quadcopter_ControllerWithNavigation_B.Gain_i = 0.0;
      } else {
        Quadcopter_ControllerWithNavigation_B.Gain_i -=
          Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit;
      }
    }

    // End of Saturate: '<S118>/Saturation'

    // Gain: '<S108>/Integral Gain'
    Quadcopter_ControllerWithNavigation_B.y_l *=
      Quadcopter_ControllerWithNavigation_P.PIDController_I;

    // Switch: '<S102>/Switch1' incorporates:
    //   Constant: '<S102>/Clamping_zero'
    //   Constant: '<S102>/Constant'
    //   Constant: '<S102>/Constant2'
    //   RelationalOperator: '<S102>/fix for DT propagation issue'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value) {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_k;
    } else {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant2_Value_e;
    }

    // Switch: '<S102>/Switch2' incorporates:
    //   Constant: '<S102>/Clamping_zero'
    //   Constant: '<S102>/Constant3'
    //   Constant: '<S102>/Constant4'
    //   RelationalOperator: '<S102>/fix for DT propagation issue1'

    if (Quadcopter_ControllerWithNavigation_B.y_l >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value) {
      Quadcopter_ControllerWithNavigation_B.i2_b =
        Quadcopter_ControllerWithNavigation_P.Constant3_Value_g;
    } else {
      Quadcopter_ControllerWithNavigation_B.i2_b =
        Quadcopter_ControllerWithNavigation_P.Constant4_Value_j;
    }

    // Switch: '<S102>/Switch' incorporates:
    //   Constant: '<S102>/Clamping_zero'
    //   Constant: '<S102>/Constant1'
    //   Logic: '<S102>/AND3'
    //   RelationalOperator: '<S102>/Equal1'
    //   RelationalOperator: '<S102>/Relational Operator'
    //   Switch: '<S102>/Switch1'
    //   Switch: '<S102>/Switch2'

    if ((Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value !=
         Quadcopter_ControllerWithNavigation_B.Gain_i) &&
        (Quadcopter_ControllerWithNavigation_B.rtPrevAction ==
         Quadcopter_ControllerWithNavigation_B.i2_b)) {
      Quadcopter_ControllerWithNavigation_B.Filter =
        Quadcopter_ControllerWithNavigation_P.Constant1_Value;
    } else {
      Quadcopter_ControllerWithNavigation_B.Filter =
        Quadcopter_ControllerWithNavigation_B.y_l;
    }

    // End of Switch: '<S102>/Switch'

    // RateLimiter: '<S54>/Rate Limiter2'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_B.Gain1 -
      Quadcopter_ControllerWithNavigation_DW.PrevY;
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.RateLimiter2_RisingLim *
        Quadcopter_ControllerWithNavigation_period) {
      Quadcopter_ControllerWithNavigation_B.y_l =
        Quadcopter_ControllerWithNavigation_P.RateLimiter2_RisingLim *
        Quadcopter_ControllerWithNavigation_period +
        Quadcopter_ControllerWithNavigation_DW.PrevY;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
               Quadcopter_ControllerWithNavigation_P.RateLimiter2_FallingLim *
               Quadcopter_ControllerWithNavigation_period) {
      Quadcopter_ControllerWithNavigation_B.y_l =
        Quadcopter_ControllerWithNavigation_P.RateLimiter2_FallingLim *
        Quadcopter_ControllerWithNavigation_period +
        Quadcopter_ControllerWithNavigation_DW.PrevY;
    } else {
      Quadcopter_ControllerWithNavigation_B.y_l =
        Quadcopter_ControllerWithNavigation_B.Gain1;
    }

    Quadcopter_ControllerWithNavigation_DW.PrevY =
      Quadcopter_ControllerWithNavigation_B.y_l;

    // End of RateLimiter: '<S54>/Rate Limiter2'

    // Saturate: '<S54>/Saturation1'
    if (Quadcopter_ControllerWithNavigation_B.y_l >
        Quadcopter_ControllerWithNavigation_P.Saturation1_UpperSat) {
      Quadcopter_ControllerWithNavigation_B.y_l =
        Quadcopter_ControllerWithNavigation_P.Saturation1_UpperSat;
    } else if (Quadcopter_ControllerWithNavigation_B.y_l <
               Quadcopter_ControllerWithNavigation_P.Saturation1_LowerSat) {
      Quadcopter_ControllerWithNavigation_B.y_l =
        Quadcopter_ControllerWithNavigation_P.Saturation1_LowerSat;
    }

    // Sum: '<S54>/Sum' incorporates:
    //   Gain: '<S264>/Proportional Gain'
    //   Saturate: '<S54>/Saturation1'
    //   Sum: '<S54>/Sum2'

    Quadcopter_ControllerWithNavigation_B.y_l =
      (Quadcopter_ControllerWithNavigation_B.y_l -
       Quadcopter_ControllerWithNavigation_B.VectorConcatenate[1]) *
      Quadcopter_ControllerWithNavigation_P.PIDController3_P -
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[1];

    // Gain: '<S158>/Integral Gain'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_P.PIDController1_I *
      Quadcopter_ControllerWithNavigation_B.y_l;

    // Gain: '<S164>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S156>/Filter'
    //   Gain: '<S155>/Derivative Gain'
    //   Sum: '<S156>/SumD'

    Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k =
      (Quadcopter_ControllerWithNavigation_P.PIDController1_D *
       Quadcopter_ControllerWithNavigation_B.y_l -
       Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_n) *
      Quadcopter_ControllerWithNavigation_P.PIDController1_N;

    // Sum: '<S170>/Sum' incorporates:
    //   DiscreteIntegrator: '<S161>/Integrator'
    //   Gain: '<S166>/Proportional Gain'

    Quadcopter_ControllerWithNavigation_B.b =
      (Quadcopter_ControllerWithNavigation_P.PIDController1_P *
       Quadcopter_ControllerWithNavigation_B.y_l +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_o) +
      Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k;

    // DeadZone: '<S154>/DeadZone'
    if (Quadcopter_ControllerWithNavigation_B.b >
        Quadcopter_ControllerWithNavigation_P.PIDController1_UpperSaturationLimit)
    {
      Quadcopter_ControllerWithNavigation_B.Filter_o =
        Quadcopter_ControllerWithNavigation_B.b -
        Quadcopter_ControllerWithNavigation_P.PIDController1_UpperSaturationLimit;
    } else if (Quadcopter_ControllerWithNavigation_B.b >=
               Quadcopter_ControllerWithNavigation_P.PIDController1_LowerSaturationLimit)
    {
      Quadcopter_ControllerWithNavigation_B.Filter_o = 0.0;
    } else {
      Quadcopter_ControllerWithNavigation_B.Filter_o =
        Quadcopter_ControllerWithNavigation_B.b -
        Quadcopter_ControllerWithNavigation_P.PIDController1_LowerSaturationLimit;
    }

    // End of DeadZone: '<S154>/DeadZone'

    // Switch: '<S152>/Switch1' incorporates:
    //   Constant: '<S152>/Clamping_zero'
    //   Constant: '<S152>/Constant'
    //   Constant: '<S152>/Constant2'
    //   RelationalOperator: '<S152>/fix for DT propagation issue'

    if (Quadcopter_ControllerWithNavigation_B.Filter_o >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_e) {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_h;
    } else {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant2_Value_f;
    }

    // Switch: '<S152>/Switch2' incorporates:
    //   Constant: '<S152>/Clamping_zero'
    //   Constant: '<S152>/Constant3'
    //   Constant: '<S152>/Constant4'
    //   RelationalOperator: '<S152>/fix for DT propagation issue1'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_e) {
      Quadcopter_ControllerWithNavigation_B.i2_b =
        Quadcopter_ControllerWithNavigation_P.Constant3_Value_c;
    } else {
      Quadcopter_ControllerWithNavigation_B.i2_b =
        Quadcopter_ControllerWithNavigation_P.Constant4_Value_e;
    }

    // Switch: '<S152>/Switch' incorporates:
    //   Constant: '<S152>/Clamping_zero'
    //   Constant: '<S152>/Constant1'
    //   Logic: '<S152>/AND3'
    //   RelationalOperator: '<S152>/Equal1'
    //   RelationalOperator: '<S152>/Relational Operator'
    //   Switch: '<S152>/Switch1'
    //   Switch: '<S152>/Switch2'

    if ((Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_e !=
         Quadcopter_ControllerWithNavigation_B.Filter_o) &&
        (Quadcopter_ControllerWithNavigation_B.rtPrevAction ==
         Quadcopter_ControllerWithNavigation_B.i2_b)) {
      Quadcopter_ControllerWithNavigation_B.y_l =
        Quadcopter_ControllerWithNavigation_P.Constant1_Value_e;
    } else {
      Quadcopter_ControllerWithNavigation_B.y_l =
        Quadcopter_ControllerWithNavigation_B.Gain_i;
    }

    // End of Switch: '<S152>/Switch'

    // Saturate: '<S168>/Saturation'
    if (Quadcopter_ControllerWithNavigation_B.b >
        Quadcopter_ControllerWithNavigation_P.PIDController1_UpperSaturationLimit)
    {
      // Saturate: '<S168>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_c =
        Quadcopter_ControllerWithNavigation_P.PIDController1_UpperSaturationLimit;
    } else if (Quadcopter_ControllerWithNavigation_B.b <
               Quadcopter_ControllerWithNavigation_P.PIDController1_LowerSaturationLimit)
    {
      // Saturate: '<S168>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_c =
        Quadcopter_ControllerWithNavigation_P.PIDController1_LowerSaturationLimit;
    } else {
      // Saturate: '<S168>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_c =
        Quadcopter_ControllerWithNavigation_B.b;
    }

    // End of Saturate: '<S168>/Saturation'

    // RateLimiter: '<S54>/Rate Limiter1'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_B.Saturation_n[1] -
      Quadcopter_ControllerWithNavigation_DW.PrevY_b;
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.RateLimiter1_RisingLim *
        Quadcopter_ControllerWithNavigation_period) {
      Quadcopter_ControllerWithNavigation_B.Filter_o =
        Quadcopter_ControllerWithNavigation_P.RateLimiter1_RisingLim *
        Quadcopter_ControllerWithNavigation_period +
        Quadcopter_ControllerWithNavigation_DW.PrevY_b;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
               Quadcopter_ControllerWithNavigation_P.RateLimiter1_FallingLim *
               Quadcopter_ControllerWithNavigation_period) {
      Quadcopter_ControllerWithNavigation_B.Filter_o =
        Quadcopter_ControllerWithNavigation_P.RateLimiter1_FallingLim *
        Quadcopter_ControllerWithNavigation_period +
        Quadcopter_ControllerWithNavigation_DW.PrevY_b;
    } else {
      Quadcopter_ControllerWithNavigation_B.Filter_o =
        Quadcopter_ControllerWithNavigation_B.Saturation_n[1];
    }

    Quadcopter_ControllerWithNavigation_DW.PrevY_b =
      Quadcopter_ControllerWithNavigation_B.Filter_o;

    // End of RateLimiter: '<S54>/Rate Limiter1'

    // Saturate: '<S54>/Saturation'
    if (Quadcopter_ControllerWithNavigation_B.Filter_o >
        Quadcopter_ControllerWithNavigation_P.Saturation_UpperSat) {
      Quadcopter_ControllerWithNavigation_B.Filter_o =
        Quadcopter_ControllerWithNavigation_P.Saturation_UpperSat;
    } else if (Quadcopter_ControllerWithNavigation_B.Filter_o <
               Quadcopter_ControllerWithNavigation_P.Saturation_LowerSat) {
      Quadcopter_ControllerWithNavigation_B.Filter_o =
        Quadcopter_ControllerWithNavigation_P.Saturation_LowerSat;
    }

    // Sum: '<S54>/Sum1' incorporates:
    //   Gain: '<S312>/Proportional Gain'
    //   Saturate: '<S54>/Saturation'
    //   Sum: '<S54>/Sum3'

    Quadcopter_ControllerWithNavigation_B.Filter_o =
      (Quadcopter_ControllerWithNavigation_B.Filter_o -
       Quadcopter_ControllerWithNavigation_B.VectorConcatenate[2]) *
      Quadcopter_ControllerWithNavigation_P.PIDController4_P -
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[0];

    // Gain: '<S208>/Integral Gain'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_P.PIDController2_I *
      Quadcopter_ControllerWithNavigation_B.Filter_o;

    // Gain: '<S214>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S206>/Filter'
    //   Gain: '<S205>/Derivative Gain'
    //   Sum: '<S206>/SumD'

    Quadcopter_ControllerWithNavigation_B.b =
      (Quadcopter_ControllerWithNavigation_P.PIDController2_D *
       Quadcopter_ControllerWithNavigation_B.Filter_o -
       Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_k) *
      Quadcopter_ControllerWithNavigation_P.PIDController2_N;

    // Sum: '<S220>/Sum' incorporates:
    //   DiscreteIntegrator: '<S211>/Integrator'
    //   Gain: '<S216>/Proportional Gain'

    Quadcopter_ControllerWithNavigation_B.Saturation_d =
      (Quadcopter_ControllerWithNavigation_P.PIDController2_P *
       Quadcopter_ControllerWithNavigation_B.Filter_o +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_i) +
      Quadcopter_ControllerWithNavigation_B.b;

    // DeadZone: '<S204>/DeadZone' incorporates:
    //   Saturate: '<S218>/Saturation'

    if (Quadcopter_ControllerWithNavigation_B.Saturation_d >
        Quadcopter_ControllerWithNavigation_P.PIDController2_UpperSaturationLimit)
    {
      Quadcopter_ControllerWithNavigation_B.Filter_o =
        Quadcopter_ControllerWithNavigation_B.Saturation_d -
        Quadcopter_ControllerWithNavigation_P.PIDController2_UpperSaturationLimit;

      // Sum: '<S220>/Sum' incorporates:
      //   Saturate: '<S218>/Saturation'

      Quadcopter_ControllerWithNavigation_B.Saturation_d =
        Quadcopter_ControllerWithNavigation_P.PIDController2_UpperSaturationLimit;
    } else {
      if (Quadcopter_ControllerWithNavigation_B.Saturation_d >=
          Quadcopter_ControllerWithNavigation_P.PIDController2_LowerSaturationLimit)
      {
        Quadcopter_ControllerWithNavigation_B.Filter_o = 0.0;
      } else {
        Quadcopter_ControllerWithNavigation_B.Filter_o =
          Quadcopter_ControllerWithNavigation_B.Saturation_d -
          Quadcopter_ControllerWithNavigation_P.PIDController2_LowerSaturationLimit;
      }

      if (Quadcopter_ControllerWithNavigation_B.Saturation_d <
          Quadcopter_ControllerWithNavigation_P.PIDController2_LowerSaturationLimit)
      {
        // Sum: '<S220>/Sum' incorporates:
        //   Saturate: '<S218>/Saturation'

        Quadcopter_ControllerWithNavigation_B.Saturation_d =
          Quadcopter_ControllerWithNavigation_P.PIDController2_LowerSaturationLimit;
      }
    }

    // End of DeadZone: '<S204>/DeadZone'

    // Update for DiscreteIntegrator: '<S111>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_h +=
      Quadcopter_ControllerWithNavigation_P.Integrator_gainval *
      Quadcopter_ControllerWithNavigation_B.Filter;

    // Update for DiscreteIntegrator: '<S106>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_f +=
      Quadcopter_ControllerWithNavigation_P.Filter_gainval *
      Quadcopter_ControllerWithNavigation_B.lambda;

    // Update for DiscreteIntegrator: '<S161>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_o +=
      Quadcopter_ControllerWithNavigation_P.Integrator_gainval_k *
      Quadcopter_ControllerWithNavigation_B.y_l;

    // Update for DiscreteIntegrator: '<S156>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_n +=
      Quadcopter_ControllerWithNavigation_P.Filter_gainval_p *
      Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k;

    // Switch: '<S202>/Switch1' incorporates:
    //   Constant: '<S202>/Clamping_zero'
    //   Constant: '<S202>/Constant'
    //   Constant: '<S202>/Constant2'
    //   RelationalOperator: '<S202>/fix for DT propagation issue'

    if (Quadcopter_ControllerWithNavigation_B.Filter_o >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_p) {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_is;
    } else {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant2_Value_a;
    }

    // Switch: '<S202>/Switch2' incorporates:
    //   Constant: '<S202>/Clamping_zero'
    //   Constant: '<S202>/Constant3'
    //   Constant: '<S202>/Constant4'
    //   RelationalOperator: '<S202>/fix for DT propagation issue1'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_p) {
      Quadcopter_ControllerWithNavigation_B.i2_b =
        Quadcopter_ControllerWithNavigation_P.Constant3_Value_b;
    } else {
      Quadcopter_ControllerWithNavigation_B.i2_b =
        Quadcopter_ControllerWithNavigation_P.Constant4_Value_k;
    }

    // Switch: '<S202>/Switch' incorporates:
    //   Constant: '<S202>/Clamping_zero'
    //   Constant: '<S202>/Constant1'
    //   Logic: '<S202>/AND3'
    //   RelationalOperator: '<S202>/Equal1'
    //   RelationalOperator: '<S202>/Relational Operator'
    //   Switch: '<S202>/Switch1'
    //   Switch: '<S202>/Switch2'

    if ((Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_p !=
         Quadcopter_ControllerWithNavigation_B.Filter_o) &&
        (Quadcopter_ControllerWithNavigation_B.rtPrevAction ==
         Quadcopter_ControllerWithNavigation_B.i2_b)) {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.Constant1_Value_a;
    }

    // Update for DiscreteIntegrator: '<S211>/Integrator' incorporates:
    //   Switch: '<S202>/Switch'

    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_i +=
      Quadcopter_ControllerWithNavigation_P.Integrator_gainval_i *
      Quadcopter_ControllerWithNavigation_B.Gain_i;

    // Update for DiscreteIntegrator: '<S206>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_k +=
      Quadcopter_ControllerWithNavigation_P.Filter_gainval_h *
      Quadcopter_ControllerWithNavigation_B.b;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S52>/Attitude controller'
  for (Quadcopter_ControllerWithNavigation_B.j = 0;
       Quadcopter_ControllerWithNavigation_B.j < 4;
       Quadcopter_ControllerWithNavigation_B.j++) {
    // Saturate: '<S5>/Saturation' incorporates:
    //   Bias: '<S5>/Bias'
    //   Constant: '<S5>/Mixer matrix'
    //   Gain: '<S5>/Gain1'
    //   Product: '<S5>/Product1'
    //   SignalConversion generated from: '<S5>/Product1'

    Quadcopter_ControllerWithNavigation_B.b = floor
      (((((Quadcopter_ControllerWithNavigation_P.Mixermatrix_Value[Quadcopter_ControllerWithNavigation_B.j
           + 4] * Quadcopter_ControllerWithNavigation_B.Saturation_c +
           Quadcopter_ControllerWithNavigation_P.Mixermatrix_Value[Quadcopter_ControllerWithNavigation_B.j]
           * Quadcopter_ControllerWithNavigation_B.Saturation) +
          Quadcopter_ControllerWithNavigation_P.Mixermatrix_Value[Quadcopter_ControllerWithNavigation_B.j
          + 8] * Quadcopter_ControllerWithNavigation_B.Saturation_d) +
         Quadcopter_ControllerWithNavigation_P.Mixermatrix_Value[Quadcopter_ControllerWithNavigation_B.j
         + 12] * Quadcopter_ControllerWithNavigation_B.Saturation_h) +
        Quadcopter_ControllerWithNavigation_P.Bias_Bias) *
       Quadcopter_ControllerWithNavigation_P.Gain1_Gain_p);
    if (rtIsNaN(Quadcopter_ControllerWithNavigation_B.b) || rtIsInf
        (Quadcopter_ControllerWithNavigation_B.b)) {
      Quadcopter_ControllerWithNavigation_B.b = 0.0;
    } else {
      Quadcopter_ControllerWithNavigation_B.b = fmod
        (Quadcopter_ControllerWithNavigation_B.b, 65536.0);
    }

    Quadcopter_ControllerWithNavigation_B.status = static_cast<uint16_T>
      (Quadcopter_ControllerWithNavigation_B.b < 0.0 ? static_cast<int32_T>(
        static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-Quadcopter_ControllerWithNavigation_B.b)))) : static_cast<int32_T>(
        static_cast<uint16_T>(Quadcopter_ControllerWithNavigation_B.b)));
    if (Quadcopter_ControllerWithNavigation_B.status >
        Quadcopter_ControllerWithNavigation_P.Saturation_UpperSat_g) {
      Quadcopter_ControllerWithNavigation_B.Saturation_dh[Quadcopter_ControllerWithNavigation_B.j]
        = Quadcopter_ControllerWithNavigation_P.Saturation_UpperSat_g;
    } else if (Quadcopter_ControllerWithNavigation_B.status <
               Quadcopter_ControllerWithNavigation_P.Saturation_LowerSat_j) {
      Quadcopter_ControllerWithNavigation_B.Saturation_dh[Quadcopter_ControllerWithNavigation_B.j]
        = Quadcopter_ControllerWithNavigation_P.Saturation_LowerSat_j;
    } else {
      Quadcopter_ControllerWithNavigation_B.Saturation_dh[Quadcopter_ControllerWithNavigation_B.j]
        = Quadcopter_ControllerWithNavigation_B.status;
    }

    // End of Saturate: '<S5>/Saturation'
  }

  // MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
  //   Constant: '<S5>/Constant1'

  for (Quadcopter_ControllerWithNavigation_B.j = 0;
       Quadcopter_ControllerWithNavigation_B.j < 8;
       Quadcopter_ControllerWithNavigation_B.j++) {
    Quadcopter_ControllerWithNavigation_B.pwmValue[Quadcopter_ControllerWithNavigation_B.j]
      = 0U;
  }

  Quadcopter_ControllerWithNavigation_B.pwmValue[0] =
    Quadcopter_ControllerWithNavigation_B.Saturation_dh[0];
  Quadcopter_ControllerWithNavigation_B.pwmValue[1] =
    Quadcopter_ControllerWithNavigation_B.Saturation_dh[1];
  Quadcopter_ControllerWithNavigation_B.pwmValue[2] =
    Quadcopter_ControllerWithNavigation_B.Saturation_dh[2];
  Quadcopter_ControllerWithNavigation_B.pwmValue[3] =
    Quadcopter_ControllerWithNavigation_B.Saturation_dh[3];
  if (Quadcopter_ControllerWithNavigation_B.In1_b.armed) {
    if (!Quadcopter_ControllerWithNavigation_DW.obj_p.isArmed) {
      Quadcopter_ControllerWithNavigation_DW.obj_p.isArmed = true;
      Quadcopter_ControllerWithNavigation_B.status = pwm_arm
        (&Quadcopter_ControllerWithNavigation_DW.obj_p.pwmDevHandler,
         &Quadcopter_ControllerWithNavigation_DW.obj_p.armAdvertiseObj);
      Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus =
        static_cast<uint16_T>
        (Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus |
         Quadcopter_ControllerWithNavigation_B.status);
    }

    Quadcopter_ControllerWithNavigation_B.status = pwm_setServo
      (&Quadcopter_ControllerWithNavigation_DW.obj_p.pwmDevHandler,
       Quadcopter_ControllerWithNavigation_DW.obj_p.servoCount,
       Quadcopter_ControllerWithNavigation_DW.obj_p.channelMask,
       &Quadcopter_ControllerWithNavigation_B.pwmValue[0],
       Quadcopter_ControllerWithNavigation_DW.obj_p.isMain,
       &Quadcopter_ControllerWithNavigation_DW.obj_p.actuatorAdvertiseObj);
    Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus =
      static_cast<uint16_T>
      (Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus |
       Quadcopter_ControllerWithNavigation_B.status);
  } else {
    Quadcopter_ControllerWithNavigation_B.status = pwm_disarm
      (&Quadcopter_ControllerWithNavigation_DW.obj_p.pwmDevHandler,
       &Quadcopter_ControllerWithNavigation_DW.obj_p.armAdvertiseObj);
    Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus =
      static_cast<uint16_T>
      (Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus |
       Quadcopter_ControllerWithNavigation_B.status);
    Quadcopter_ControllerWithNavigation_DW.obj_p.isArmed = false;
    Quadcopter_ControllerWithNavigation_B.status = pwm_resetServo
      (&Quadcopter_ControllerWithNavigation_DW.obj_p.pwmDevHandler,
       Quadcopter_ControllerWithNavigation_DW.obj_p.servoCount,
       Quadcopter_ControllerWithNavigation_DW.obj_p.channelMask,
       Quadcopter_ControllerWithNavigation_DW.obj_p.isMain,
       &Quadcopter_ControllerWithNavigation_DW.obj_p.actuatorAdvertiseObj);
    Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus =
      static_cast<uint16_T>
      (Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus |
       Quadcopter_ControllerWithNavigation_B.status);
  }

  if (Quadcopter_ControllerWithNavigation_DW.obj_p.isMain) {
    Quadcopter_ControllerWithNavigation_B.status = pwm_forceFailsafe
      (&Quadcopter_ControllerWithNavigation_DW.obj_p.pwmDevHandler, static_cast<
       int32_T>(Quadcopter_ControllerWithNavigation_P.Constant1_Value_c));
    Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus = static_cast<
      uint16_T>(Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus |
                Quadcopter_ControllerWithNavigation_B.status);
  }

  // End of MATLABSystem: '<S5>/PX4 PWM Output'

  // Outputs for Enabled SubSystem: '<S17>/Send waypoints to OBC' incorporates:
  //   EnablePort: '<S34>/Enable'

  // Start for MATLABSystem: '<S17>/Read Parameter'
  if (Quadcopter_ControllerWithNavigation_B.ParamStep_l > 0) {
    // BusAssignment: '<S34>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment'
    //   Constant: '<S44>/Constant'
    //   SignalConversion generated from: '<S40>/Bus Assignment1'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0] =
      Quadcopter_ControllerWithNavigation_P.Constant_Value.waypoints[0];

    // SignalConversion generated from: '<S40>/Matrix Concatenate1'
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.lat;

    // SignalConversion generated from: '<S40>/Matrix Concatenate1'
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1] =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.lon;

    // DataTypeConversion: '<S40>/Data Type Conversion'
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2] =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.alt;

    // SignalConversion generated from: '<S34>/Matrix Concatenate1'
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0] =
      Quadcopter_ControllerWithNavigation_B.In1_f.lat;

    // SignalConversion generated from: '<S34>/Matrix Concatenate1'
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1] =
      Quadcopter_ControllerWithNavigation_B.In1_f.lon;

    // DataTypeConversion: '<S34>/Data Type Conversion'
    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2] =
      Quadcopter_ControllerWithNavigation_B.In1_f.alt;
    Quadcopter_ControllerWithNavigation_MATLABSystem
      (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1,
       Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k,
       Quadcopter_ControllerWithNavigation_B.In1_p.current.valid,
       Quadcopter_ControllerWithNavigation_B.In1_p.current.type,
       &Quadcopter_ControllerWithNavigation_B.MATLABSystem);

    // SignalConversion generated from: '<S46>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   BusAssignment: '<S40>/Bus Assignment1'
    //   MATLABSystem: '<S40>/MATLAB System'
    //   SignalConversion generated from: '<S40>/MATLAB System'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0].position[0]
      = Quadcopter_ControllerWithNavigation_B.MATLABSystem.MATLABSystem[0];

    // SignalConversion generated from: '<S46>/Matrix Concatenate' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   BusAssignment: '<S40>/Bus Assignment1'
    //   MATLABSystem: '<S40>/MATLAB System'
    //   SignalConversion generated from: '<S40>/MATLAB System'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0].position[1]
      = Quadcopter_ControllerWithNavigation_B.MATLABSystem.MATLABSystem[1];

    // If: '<S46>/If' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   BusAssignment: '<S40>/Bus Assignment1'
    //   Constant: '<S48>/Constant'
    //   Constant: '<S48>/Constant1'
    //   Constant: '<S49>/Constant'
    //   Constant: '<S49>/Constant1'

    if (Quadcopter_ControllerWithNavigation_B.In1_p.current.type == 4) {
      // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S49>/Action Port'

      // MATLABSystem: '<S49>/Read Parameter' incorporates:
      //   BusAssignment: '<S34>/Bus Assignment1'
      //   BusAssignment: '<S40>/Bus Assignment1'
      //   SignalConversion generated from: '<S49>/Read Parameter'

      if (Quadcopter_ControllerWithNavigation_DW.obj_g.SampleTime !=
          Quadcopter_ControllerWithNavigation_P.ReadParameter_SampleTime_c) {
        Quadcopter_ControllerWithNavigation_DW.obj_g.SampleTime =
          Quadcopter_ControllerWithNavigation_P.ReadParameter_SampleTime_c;
      }

      Quadcopter_ControllerWithNavigation_B.latp2 = MW_Param_Step
        (Quadcopter_ControllerWithNavigation_DW.obj_g.MW_PARAMHANDLE, MW_SINGLE,
         &Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0].
         velocity[2]);
      if (Quadcopter_ControllerWithNavigation_B.latp2) {
        Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0].
          velocity[2] = 0.0F;
      }

      // End of MATLABSystem: '<S49>/Read Parameter'
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0]
        .velocity[0] = Quadcopter_ControllerWithNavigation_P.Constant1_Value_d[0];
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0]
        .velocity[1] = Quadcopter_ControllerWithNavigation_P.Constant1_Value_d[1];
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0]
        .position[2] = Quadcopter_ControllerWithNavigation_P.Constant_Value_f2;

      // End of Outputs for SubSystem: '<S46>/If Action Subsystem2'

      // Update for IfAction SubSystem: '<S46>/If Action Subsystem2' incorporates:
      //   ActionPort: '<S49>/Action Port'

      // Update for If: '<S46>/If' incorporates:
      //   BusAssignment: '<S34>/Bus Assignment1'
      //   BusAssignment: '<S40>/Bus Assignment1'
      //   Constant: '<S49>/Constant'
      //   Constant: '<S49>/Constant1'

      srUpdateBC
        (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem2_SubsysRanBC_k);

      // End of Update for SubSystem: '<S46>/If Action Subsystem2'
    } else if (Quadcopter_ControllerWithNavigation_B.In1_p.current.type == 3) {
      // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S48>/Action Port'

      // MATLABSystem: '<S48>/Read Parameter'
      if (Quadcopter_ControllerWithNavigation_DW.obj_b.SampleTime !=
          Quadcopter_ControllerWithNavigation_P.ReadParameter_SampleTime_g) {
        Quadcopter_ControllerWithNavigation_DW.obj_b.SampleTime =
          Quadcopter_ControllerWithNavigation_P.ReadParameter_SampleTime_g;
      }

      Quadcopter_ControllerWithNavigation_B.latp2 = MW_Param_Step
        (Quadcopter_ControllerWithNavigation_DW.obj_b.MW_PARAMHANDLE, MW_SINGLE,
         &Quadcopter_ControllerWithNavigation_B.ParamStep);
      if (Quadcopter_ControllerWithNavigation_B.latp2) {
        Quadcopter_ControllerWithNavigation_B.ParamStep = 0.0F;
      }

      // Gain: '<S48>/Gain' incorporates:
      //   BusAssignment: '<S34>/Bus Assignment1'
      //   BusAssignment: '<S40>/Bus Assignment1'
      //   MATLABSystem: '<S48>/Read Parameter'
      //
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0]
        .velocity[2] = Quadcopter_ControllerWithNavigation_P.Gain_Gain_h *
        Quadcopter_ControllerWithNavigation_B.ParamStep;
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0]
        .velocity[0] = Quadcopter_ControllerWithNavigation_P.Constant1_Value_k[0];
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0]
        .velocity[1] = Quadcopter_ControllerWithNavigation_P.Constant1_Value_k[1];
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0]
        .position[2] = Quadcopter_ControllerWithNavigation_P.Constant_Value_l4;

      // End of Outputs for SubSystem: '<S46>/If Action Subsystem1'

      // Update for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S48>/Action Port'

      // Update for If: '<S46>/If' incorporates:
      //   BusAssignment: '<S34>/Bus Assignment1'
      //   BusAssignment: '<S40>/Bus Assignment1'
      //   Constant: '<S48>/Constant'
      //   Constant: '<S48>/Constant1'

      srUpdateBC
        (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem1_SubsysRanBC_m);

      // End of Update for SubSystem: '<S46>/If Action Subsystem1'
    } else {
      // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
      //   ActionPort: '<S47>/Action Port'

      // SignalConversion generated from: '<S47>/In1' incorporates:
      //   BusAssignment: '<S34>/Bus Assignment1'
      //   BusAssignment: '<S40>/Bus Assignment1'
      //   MATLABSystem: '<S40>/MATLAB System'
      //   SignalConversion generated from: '<S40>/MATLAB System'

      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0]
        .position[2] =
        Quadcopter_ControllerWithNavigation_B.MATLABSystem.MATLABSystem[2];

      // BusAssignment: '<S40>/Bus Assignment1' incorporates:
      //   BusAssignment: '<S34>/Bus Assignment1'
      //   SignalConversion generated from: '<S46>/Matrix Concatenate1'
      //   SignalConversion generated from: '<S47>/In2'
      //
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0]
        .velocity[0] = Quadcopter_ControllerWithNavigation_B.In1_p.current.vx;
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0]
        .velocity[1] = Quadcopter_ControllerWithNavigation_B.In1_p.current.vy;
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0]
        .velocity[2] = Quadcopter_ControllerWithNavigation_B.In1_p.current.vz;

      // End of Outputs for SubSystem: '<S46>/If Action Subsystem'

      // Update for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
      //   ActionPort: '<S47>/Action Port'

      // Update for If: '<S46>/If'
      srUpdateBC
        (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem_SubsysRanBC_g);

      // End of Update for SubSystem: '<S46>/If Action Subsystem'
    }

    // End of If: '<S46>/If'

    // BusAssignment: '<S40>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   Constant: '<S40>/Constant5'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0].timestamp =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.timestamp;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0].type =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.type;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0].yaw =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.yaw;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0].yaw_speed =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.yawspeed;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[0].
      point_valid = Quadcopter_ControllerWithNavigation_P.Constant5_Value;

    // BusAssignment: '<S34>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment'
    //   Constant: '<S44>/Constant'
    //   SignalConversion generated from: '<S41>/Bus Assignment1'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1] =
      Quadcopter_ControllerWithNavigation_P.Constant_Value.waypoints[1];

    // SignalConversion generated from: '<S41>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S40>/Matrix Concatenate1'

    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.lat;

    // SignalConversion generated from: '<S41>/Matrix Concatenate' incorporates:
    //   SignalConversion generated from: '<S40>/Matrix Concatenate1'

    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1] =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.lon;

    // DataTypeConversion: '<S41>/Data Type Conversion' incorporates:
    //   DataTypeConversion: '<S40>/Data Type Conversion'

    Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2] =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.alt;
    Quadcopter_ControllerWithNavigation_MATLABSystem
      (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1,
       Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k,
       Quadcopter_ControllerWithNavigation_B.In1_p.current.valid,
       Quadcopter_ControllerWithNavigation_B.In1_p.current.type,
       &Quadcopter_ControllerWithNavigation_B.MATLABSystem_b);

    // SignalConversion generated from: '<S41>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   BusAssignment: '<S41>/Bus Assignment1'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1].velocity[0]
      = Quadcopter_ControllerWithNavigation_B.In1_p.current.vx;

    // SignalConversion generated from: '<S41>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   BusAssignment: '<S41>/Bus Assignment1'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1].velocity[1]
      = Quadcopter_ControllerWithNavigation_B.In1_p.current.vy;

    // SignalConversion generated from: '<S41>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   BusAssignment: '<S41>/Bus Assignment1'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1].velocity[2]
      = Quadcopter_ControllerWithNavigation_B.In1_p.current.vz;

    // BusAssignment: '<S41>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   BusAssignment: '<S40>/Bus Assignment1'
    //   Constant: '<S41>/Constant5'
    //   MATLABSystem: '<S41>/MATLAB System'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1].timestamp =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.timestamp;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1].position[0]
      = Quadcopter_ControllerWithNavigation_B.MATLABSystem_b.MATLABSystem[0];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1].position[1]
      = Quadcopter_ControllerWithNavigation_B.MATLABSystem_b.MATLABSystem[1];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1].position[2]
      = Quadcopter_ControllerWithNavigation_B.MATLABSystem_b.MATLABSystem[2];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1].yaw =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.yaw;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1].yaw_speed =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.yawspeed;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1].
      point_valid = Quadcopter_ControllerWithNavigation_P.Constant5_Value_k;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[1].type =
      Quadcopter_ControllerWithNavigation_B.In1_p.current.type;

    // BusAssignment: '<S34>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment'
    //   Constant: '<S44>/Constant'
    //   SignalConversion generated from: '<S43>/Bus Assignment1'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2] =
      Quadcopter_ControllerWithNavigation_P.Constant_Value.waypoints[2];

    // MATLABSystem: '<S43>/MATLAB System' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   DataTypeConversion: '<S34>/Data Type Conversion'
    //   DataTypeConversion: '<S43>/Data Type Conversion'
    //   SignalConversion generated from: '<S34>/Matrix Concatenate1'
    //   SignalConversion generated from: '<S43>/Matrix Concatenate'
    //
    if (Quadcopter_ControllerWithNavigation_B.In1_p.next.valid) {
      Quadcopter_ControllerWithNavigation_B.y_l =
        Quadcopter_ControllerWithNavigation_B.In1_p.next.lat -
        Quadcopter_ControllerWithNavigation_B.In1_f.lat;
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_B.In1_p.next.lon -
        Quadcopter_ControllerWithNavigation_B.In1_f.lon;
      Quadcopter_ControllerWithNavigation_B.lambda = fabs
        (Quadcopter_ControllerWithNavigation_B.y_l);
      if (Quadcopter_ControllerWithNavigation_B.lambda > 180.0) {
        if (rtIsNaN(Quadcopter_ControllerWithNavigation_B.y_l + 180.0) ||
            rtIsInf(Quadcopter_ControllerWithNavigation_B.y_l + 180.0)) {
          Quadcopter_ControllerWithNavigation_B.Filter = (rtNaN);
        } else if (Quadcopter_ControllerWithNavigation_B.y_l + 180.0 == 0.0) {
          Quadcopter_ControllerWithNavigation_B.Filter = 0.0;
        } else {
          Quadcopter_ControllerWithNavigation_B.Filter = fmod
            (Quadcopter_ControllerWithNavigation_B.y_l + 180.0, 360.0);
          if (Quadcopter_ControllerWithNavigation_B.Filter == 0.0) {
            Quadcopter_ControllerWithNavigation_B.Filter = 0.0;
          } else if (Quadcopter_ControllerWithNavigation_B.y_l + 180.0 < 0.0) {
            Quadcopter_ControllerWithNavigation_B.Filter += 360.0;
          }
        }

        Quadcopter_ControllerWithNavigation_B.y_l =
          Quadcopter_ControllerWithNavigation_B.y_l * 0.0 +
          (Quadcopter_ControllerWithNavigation_B.Filter - 180.0);
        Quadcopter_ControllerWithNavigation_B.lambda = fabs
          (Quadcopter_ControllerWithNavigation_B.y_l);
      }

      if (Quadcopter_ControllerWithNavigation_B.lambda > 90.0) {
        Quadcopter_ControllerWithNavigation_B.lambda = fabs
          (Quadcopter_ControllerWithNavigation_B.y_l);
        Quadcopter_ControllerWithNavigation_B.latp2 =
          (Quadcopter_ControllerWithNavigation_B.lambda > 90.0);
        Quadcopter_ControllerWithNavigation_B.Gain_i += 180.0;
        Quadcopter_ControllerWithNavigation_B.b =
          Quadcopter_ControllerWithNavigation_B.y_l * static_cast<real_T>
          (Quadcopter_ControllerWithNavigation_B.latp2);
        if (rtIsNaN(Quadcopter_ControllerWithNavigation_B.b)) {
          Quadcopter_ControllerWithNavigation_B.b = (rtNaN);
        } else if (Quadcopter_ControllerWithNavigation_B.b < 0.0) {
          Quadcopter_ControllerWithNavigation_B.b = -1.0;
        } else {
          Quadcopter_ControllerWithNavigation_B.b =
            (Quadcopter_ControllerWithNavigation_B.b > 0.0);
        }

        Quadcopter_ControllerWithNavigation_B.y_l = (90.0 -
          (Quadcopter_ControllerWithNavigation_B.lambda * static_cast<real_T>
           (Quadcopter_ControllerWithNavigation_B.latp2) - 90.0)) *
          Quadcopter_ControllerWithNavigation_B.b * static_cast<real_T>
          (Quadcopter_ControllerWithNavigation_B.latp2) +
          Quadcopter_ControllerWithNavigation_B.y_l * static_cast<real_T>
          (!Quadcopter_ControllerWithNavigation_B.latp2);
      }

      if ((Quadcopter_ControllerWithNavigation_B.Gain_i > 180.0) ||
          (Quadcopter_ControllerWithNavigation_B.Gain_i < -180.0)) {
        Quadcopter_ControllerWithNavigation_B.lambda =
          Quadcopter_ControllerWithNavigation_rt_remd_snf
          (Quadcopter_ControllerWithNavigation_B.Gain_i, 360.0);
        Quadcopter_ControllerWithNavigation_B.b =
          Quadcopter_ControllerWithNavigation_B.lambda / 180.0;
        if (Quadcopter_ControllerWithNavigation_B.b < 0.0) {
          Quadcopter_ControllerWithNavigation_B.b = ceil
            (Quadcopter_ControllerWithNavigation_B.b);
        } else {
          Quadcopter_ControllerWithNavigation_B.b = floor
            (Quadcopter_ControllerWithNavigation_B.b);
        }

        Quadcopter_ControllerWithNavigation_B.Gain_i =
          (Quadcopter_ControllerWithNavigation_B.lambda - 360.0 *
           Quadcopter_ControllerWithNavigation_B.b) +
          Quadcopter_ControllerWithNavigation_B.Gain_i * 0.0;
      }

      Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k =
        Quadcopter_ControllerWithNavigation_sind_l
        (Quadcopter_ControllerWithNavigation_B.In1_f.lat);
      Quadcopter_ControllerWithNavigation_B.b = 6.378137E+6 / sqrt(1.0 -
        0.0066943799901413165 *
        Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k *
        Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k);
      if (rtIsInf(Quadcopter_ControllerWithNavigation_B.In1_f.lat) || rtIsNaN
          (Quadcopter_ControllerWithNavigation_B.In1_f.lat)) {
        Quadcopter_ControllerWithNavigation_B.lambda = (rtNaN);
      } else {
        Quadcopter_ControllerWithNavigation_B.lambda =
          Quadcopter_ControllerWithNavigation_rt_remd_snf
          (Quadcopter_ControllerWithNavigation_B.In1_f.lat, 360.0);
        Quadcopter_ControllerWithNavigation_B.Filter = fabs
          (Quadcopter_ControllerWithNavigation_B.lambda);
        if (Quadcopter_ControllerWithNavigation_B.Filter > 180.0) {
          if (Quadcopter_ControllerWithNavigation_B.lambda > 0.0) {
            Quadcopter_ControllerWithNavigation_B.lambda -= 360.0;
          } else {
            Quadcopter_ControllerWithNavigation_B.lambda += 360.0;
          }

          Quadcopter_ControllerWithNavigation_B.Filter = fabs
            (Quadcopter_ControllerWithNavigation_B.lambda);
        }

        if (Quadcopter_ControllerWithNavigation_B.Filter <= 45.0) {
          Quadcopter_ControllerWithNavigation_B.lambda = cos
            (0.017453292519943295 * Quadcopter_ControllerWithNavigation_B.lambda);
        } else if (Quadcopter_ControllerWithNavigation_B.Filter <= 135.0) {
          if (Quadcopter_ControllerWithNavigation_B.lambda > 0.0) {
            Quadcopter_ControllerWithNavigation_B.lambda = -sin
              ((Quadcopter_ControllerWithNavigation_B.lambda - 90.0) *
               0.017453292519943295);
          } else {
            Quadcopter_ControllerWithNavigation_B.lambda = sin
              ((Quadcopter_ControllerWithNavigation_B.lambda + 90.0) *
               0.017453292519943295);
          }
        } else {
          if (Quadcopter_ControllerWithNavigation_B.lambda > 0.0) {
            Quadcopter_ControllerWithNavigation_B.lambda =
              (Quadcopter_ControllerWithNavigation_B.lambda - 180.0) *
              0.017453292519943295;
          } else {
            Quadcopter_ControllerWithNavigation_B.lambda =
              (Quadcopter_ControllerWithNavigation_B.lambda + 180.0) *
              0.017453292519943295;
          }

          Quadcopter_ControllerWithNavigation_B.lambda = -cos
            (Quadcopter_ControllerWithNavigation_B.lambda);
        }
      }

      Quadcopter_ControllerWithNavigation_B.y_l /=
        Quadcopter_ControllerWithNavigation_rt_atan2d_snf(1.0,
        0.99330562000985867 / (1.0 - 0.0066943799901413165 *
        Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k *
        Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k) *
        Quadcopter_ControllerWithNavigation_B.b) * 57.295779513082323;
      Quadcopter_ControllerWithNavigation_B.Gain_i /=
        Quadcopter_ControllerWithNavigation_rt_atan2d_snf(1.0,
        Quadcopter_ControllerWithNavigation_B.b *
        Quadcopter_ControllerWithNavigation_B.lambda) * 57.295779513082323;
      Quadcopter_ControllerWithNavigation_B.lambda = -static_cast<real_T>
        (Quadcopter_ControllerWithNavigation_B.In1_p.next.alt) +
        Quadcopter_ControllerWithNavigation_B.In1_f.alt;
      Quadcopter_ControllerWithNavigation_B.distinctWptsIdx[0] = rtIsNaN
        (Quadcopter_ControllerWithNavigation_B.y_l);
      Quadcopter_ControllerWithNavigation_B.distinctWptsIdx[1] = rtIsNaN
        (Quadcopter_ControllerWithNavigation_B.Gain_i);
      Quadcopter_ControllerWithNavigation_B.distinctWptsIdx[2] = rtIsNaN
        (Quadcopter_ControllerWithNavigation_B.lambda);
      Quadcopter_ControllerWithNavigation_B.latp2 = false;
      Quadcopter_ControllerWithNavigation_B.i1 = 0;
      exitg1 = false;
      while ((!exitg1) && (Quadcopter_ControllerWithNavigation_B.i1 < 3)) {
        if (Quadcopter_ControllerWithNavigation_B.distinctWptsIdx[Quadcopter_ControllerWithNavigation_B.i1])
        {
          Quadcopter_ControllerWithNavigation_B.latp2 = true;
          exitg1 = true;
        } else {
          Quadcopter_ControllerWithNavigation_B.i1++;
        }
      }

      Quadcopter_ControllerWithNavigation_B.b = 0.0 / static_cast<real_T>
        (!Quadcopter_ControllerWithNavigation_B.latp2);
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2]
        .position[0] = static_cast<real32_T>
        (Quadcopter_ControllerWithNavigation_B.b +
         Quadcopter_ControllerWithNavigation_B.y_l);
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2]
        .position[1] = static_cast<real32_T>
        (Quadcopter_ControllerWithNavigation_B.b +
         Quadcopter_ControllerWithNavigation_B.Gain_i);
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2]
        .position[2] = static_cast<real32_T>
        (Quadcopter_ControllerWithNavigation_B.b +
         Quadcopter_ControllerWithNavigation_B.lambda);
    } else {
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2]
        .position[0] = 0.0F;
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2]
        .position[1] = 0.0F;
      Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2]
        .position[2] = 0.0F;
    }

    // End of MATLABSystem: '<S43>/MATLAB System'

    // SignalConversion generated from: '<S43>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   BusAssignment: '<S43>/Bus Assignment1'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2].velocity[0]
      = Quadcopter_ControllerWithNavigation_B.In1_p.next.vx;

    // SignalConversion generated from: '<S43>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   BusAssignment: '<S43>/Bus Assignment1'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2].velocity[1]
      = Quadcopter_ControllerWithNavigation_B.In1_p.next.vy;

    // SignalConversion generated from: '<S43>/Matrix Concatenate1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   BusAssignment: '<S43>/Bus Assignment1'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2].velocity[2]
      = Quadcopter_ControllerWithNavigation_B.In1_p.next.vz;

    // BusAssignment: '<S43>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'
    //   Constant: '<S43>/Constant5'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2].timestamp =
      Quadcopter_ControllerWithNavigation_B.In1_p.next.timestamp;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2].yaw =
      Quadcopter_ControllerWithNavigation_B.In1_p.next.yaw;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2].yaw_speed =
      Quadcopter_ControllerWithNavigation_B.In1_p.next.yawspeed;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2].
      point_valid = Quadcopter_ControllerWithNavigation_P.Constant5_Value_h;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[2].type =
      Quadcopter_ControllerWithNavigation_B.In1_p.next.type;

    // SignalConversion generated from: '<S42>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment'
    //   BusAssignment: '<S42>/Bus Assignment1'
    //   Constant: '<S44>/Constant'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f =
      Quadcopter_ControllerWithNavigation_P.Constant_Value.waypoints[0];

    // BusAssignment: '<S42>/Bus Assignment1' incorporates:
    //   Constant: '<S42>/Constant'
    //   Constant: '<S42>/Constant1'
    //   Constant: '<S42>/Constant2'
    //   Constant: '<S42>/Constant3'
    //   Constant: '<S42>/Constant4'
    //   Constant: '<S42>/Constant5'
    //   Constant: '<S42>/Constant6'
    //   Constant: '<S42>/Constant7'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.timestamp =
      Quadcopter_ControllerWithNavigation_P.Constant7_Value;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.yaw =
      Quadcopter_ControllerWithNavigation_P.Constant3_Value;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.yaw_speed =
      Quadcopter_ControllerWithNavigation_P.Constant4_Value;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.position[0] =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_fh[0];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.velocity[0] =
      Quadcopter_ControllerWithNavigation_P.Constant1_Value_h[0];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.acceleration[0] =
      Quadcopter_ControllerWithNavigation_P.Constant2_Value[0];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.position[1] =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_fh[1];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.velocity[1] =
      Quadcopter_ControllerWithNavigation_P.Constant1_Value_h[1];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.acceleration[1] =
      Quadcopter_ControllerWithNavigation_P.Constant2_Value[1];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.position[2] =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_fh[2];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.velocity[2] =
      Quadcopter_ControllerWithNavigation_P.Constant1_Value_h[2];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.acceleration[2] =
      Quadcopter_ControllerWithNavigation_P.Constant2_Value[2];
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.point_valid =
      Quadcopter_ControllerWithNavigation_P.Constant5_Value_l;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1_f.type =
      Quadcopter_ControllerWithNavigation_P.Constant6_Value;

    // BusAssignment: '<S34>/Bus Assignment1' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment'
    //   BusAssignment: '<S42>/Bus Assignment1'
    //   Concatenate: '<S34>/Matrix Concatenate'
    //   Constant: '<S34>/Constant'
    //   Constant: '<S44>/Constant'

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.timestamp =
      Quadcopter_ControllerWithNavigation_B.In1_p.timestamp;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.type =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_fm;
    for (Quadcopter_ControllerWithNavigation_B.j = 0;
         Quadcopter_ControllerWithNavigation_B.j < 7;
         Quadcopter_ControllerWithNavigation_B.j++) {
      Quadcopter_ControllerWithNavigation_B.BusAssignment1._padding0[Quadcopter_ControllerWithNavigation_B.j]
        =
        Quadcopter_ControllerWithNavigation_P.Constant_Value._padding0[Quadcopter_ControllerWithNavigation_B.j];
    }

    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[3] =
      Quadcopter_ControllerWithNavigation_B.BusAssignment1_f;
    Quadcopter_ControllerWithNavigation_B.BusAssignment1.waypoints[4] =
      Quadcopter_ControllerWithNavigation_B.BusAssignment1_f;

    // MATLABSystem: '<S45>/SinkBlock' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'

    uORB_write_step(Quadcopter_ControllerWithNavigation_DW.obj_mc.orbMetadataObj,
                    &Quadcopter_ControllerWithNavigation_DW.obj_mc.orbAdvertiseObj,
                    &Quadcopter_ControllerWithNavigation_B.BusAssignment1);
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.SendwaypointstoOBC_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S17>/Send waypoints to OBC'

  // MATLABSystem: '<S33>/PX4 Timestamp'
  hrt_absolute_time();
  for (Quadcopter_ControllerWithNavigation_B.j = 0;
       Quadcopter_ControllerWithNavigation_B.j < 6;
       Quadcopter_ControllerWithNavigation_B.j++) {
    // SignalConversion generated from: '<S52>/To Workspace'
    Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
      [Quadcopter_ControllerWithNavigation_B.j] =
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[Quadcopter_ControllerWithNavigation_B.j];
  }

  // SignalConversion generated from: '<S52>/To Workspace'
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [6] = Quadcopter_ControllerWithNavigation_B.Merge[0];
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [7] = Quadcopter_ControllerWithNavigation_B.Merge[1];
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [8] = Quadcopter_ControllerWithNavigation_B.desiredZ;
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [9] = Quadcopter_ControllerWithNavigation_B.VectorConcatenate[0];
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [12] = Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[0];
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [10] = Quadcopter_ControllerWithNavigation_B.VectorConcatenate[1];
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [13] = Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[1];
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [11] = Quadcopter_ControllerWithNavigation_B.VectorConcatenate[2];
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [14] = Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[2];
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [15] = Quadcopter_ControllerWithNavigation_B.Merge[3];
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [16] = Quadcopter_ControllerWithNavigation_B.Gain1;
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspaceInport
    [17] = Quadcopter_ControllerWithNavigation_B.Saturation_n[1];

  // SignalConversion generated from: '<S52>/To Workspace3'
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspace3Inpor
    [0] = Quadcopter_ControllerWithNavigation_B.x;
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspace3Inpor
    [1] = Quadcopter_ControllerWithNavigation_B.y;
  Quadcopter_ControllerWithNavigation_B.TmpSignalConversionAt_asyncqueue_inserted_for_ToWorkspace3Inpor
    [2] = Quadcopter_ControllerWithNavigation_B.z;

  // Update absolute time
  // The "clockTick1" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.01, which is the step size
  //  of the task. Size of "clockTick1" ensures timer will not overflow during the
  //  application lifespan selected.

  Quadcopter_ControllerWithNavigation_M->Timing.clockTick1++;
}

// Model step function for TID2
void Quadcopter_ControllerWithNavigation_step2(void) // Sample time: [0.015s, 0.0s] 
{
  int32_T idx;
  boolean_T rEQ0;
  static const creal_T wwc[129] = { { -0.99883222683232664,// re
      -0.048313379525507079            // im
    }, { -0.98137012613941343,         // re
      -0.19212671735370834             // im
    }, { -0.90687436085054551,         // re
      -0.42140110777252887             // im
    }, { -0.71559896074412122,         // re
      -0.69851136524893687             // im
    }, { -0.3546048870425359,          // re
      -0.93501624268541472             // im
    }, { 0.16835704134703883,          // re
      -0.98572608093165082             // im
    }, { 0.71559896074412066,          // re
      -0.69851136524893742             // im
    }, { 0.99883222683232653,          // re
      -0.048313379525507447            // im
    }, { 0.7155989607441211,           // re
      0.698511365248937                // im
    }, { -0.12053668025532288,         // re
      0.992708874098054                // im
    }, { -0.9068743608505454,          // re
      0.42140110777252909              // im
    }, { -0.77967435406322239,         // re
      -0.6261851975383137              // im
    }, { 0.30901699437494723,          // re
      -0.95105651629515364             // im
    }, { 0.99883222683232664,          // re
      0.048313379525507065             // im
    }, { 0.12053668025532323,          // re
      0.992708874098054                // im
    }, { -0.98137012613941343,         // re
      0.19212671735370859              // im
    }, { -0.16835704134703833,         // re
      -0.98572608093165093             // im
    }, { 0.99883222683232653,          // re
      -0.048313379525507447            // im
    }, { -0.16835704134703852,         // re
      0.98572608093165093              // im
    }, { -0.88545602565320991,         // re
      -0.46472317204376845             // im
    }, { 0.77967435406322216,          // re
      -0.62618519753831392             // im
    }, { 0.16835704134703863,          // re
      0.98572608093165082              // im
    }, { -0.90687436085054551,         // re
      -0.42140110777252887             // im
    }, { 0.90687436085054562,          // re
      -0.42140110777252882             // im
    }, { -0.35460488704253545,         // re
      0.93501624268541483              // im
    }, { -0.30901699437494756,         // re
      -0.95105651629515353             // im
    }, { 0.77967435406322239,          // re
      0.6261851975383137               // im
    }, { -0.98137012613941343,         // re
      -0.19212671735370834             // im
    }, { 0.98137012613941343,          // re
      -0.19212671735370829             // im
    }, { -0.8854560256532098,          // re
      0.46472317204376867              // im
    }, { 0.77967435406322216,          // re
      -0.62618519753831392             // im
    }, { -0.7155989607441211,          // re
      0.698511365248937                // im
    }, { 0.71559896074412066,          // re
      -0.69851136524893742             // im
    }, { -0.77967435406322227,         // re
      0.62618519753831392              // im
    }, { 0.88545602565320958,          // re
      -0.46472317204376917             // im
    }, { -0.98137012613941343,         // re
      0.19212671735370859              // im
    }, { 0.98137012613941343,          // re
      0.19212671735370837              // im
    }, { -0.77967435406322239,         // re
      -0.6261851975383137              // im
    }, { 0.30901699437494745,          // re
      0.95105651629515353              // im
    }, { 0.35460488704253557,          // re
      -0.93501624268541483             // im
    }, { -0.9068743608505454,          // re
      0.42140110777252909              // im
    }, { 0.9068743608505454,           // re
      0.42140110777252909              // im
    }, { -0.16835704134703833,         // re
      -0.98572608093165093             // im
    }, { -0.77967435406322227,         // re
      0.62618519753831392              // im
    }, { 0.88545602565320991,          // re
      0.46472317204376851              // im
    }, { 0.16835704134703883,          // re
      -0.98572608093165082             // im
    }, { -0.99883222683232653,         // re
      0.048313379525507322             // im
    }, { 0.16835704134703863,          // re
      0.98572608093165082              // im
    }, { 0.98137012613941343,          // re
      -0.19212671735370829             // im
    }, { -0.12053668025532269,         // re
      -0.99270887409805408             // im
    }, { -0.99883222683232664,         // re
      -0.048313379525507079            // im
    }, { -0.30901699437494734,         // re
      0.95105651629515364              // im
    }, { 0.77967435406322239,          // re
      0.6261851975383137               // im
    }, { 0.90687436085054562,          // re
      -0.42140110777252882             // im
    }, { 0.1205366802553232,           // re
      -0.992708874098054               // im
    }, { -0.71559896074412122,         // re
      -0.69851136524893687             // im
    }, { -0.99883222683232653,         // re
      0.048313379525507322             // im
    }, { -0.7155989607441211,          // re
      0.698511365248937                // im
    }, { -0.16835704134703852,         // re
      0.98572608093165093              // im
    }, { 0.35460488704253557,          // re
      0.93501624268541483              // im
    }, { 0.7155989607441211,           // re
      0.698511365248937                // im
    }, { 0.9068743608505454,           // re
      0.42140110777252909              // im
    }, { 0.98137012613941343,          // re
      0.19212671735370837              // im
    }, { 0.99883222683232664,          // re
      0.048313379525507065             // im
    }, { 1.0,                          // re
      0.0                              // im
    }, { 0.99883222683232664,          // re
      0.048313379525507065             // im
    }, { 0.98137012613941343,          // re
      0.19212671735370837              // im
    }, { 0.9068743608505454,           // re
      0.42140110777252909              // im
    }, { 0.7155989607441211,           // re
      0.698511365248937                // im
    }, { 0.35460488704253557,          // re
      0.93501624268541483              // im
    }, { -0.16835704134703852,         // re
      0.98572608093165093              // im
    }, { -0.7155989607441211,          // re
      0.698511365248937                // im
    }, { -0.99883222683232653,         // re
      0.048313379525507322             // im
    }, { -0.71559896074412122,         // re
      -0.69851136524893687             // im
    }, { 0.1205366802553232,           // re
      -0.992708874098054               // im
    }, { 0.90687436085054562,          // re
      -0.42140110777252882             // im
    }, { 0.77967435406322239,          // re
      0.6261851975383137               // im
    }, { -0.30901699437494734,         // re
      0.95105651629515364              // im
    }, { -0.99883222683232664,         // re
      -0.048313379525507079            // im
    }, { -0.12053668025532269,         // re
      -0.99270887409805408             // im
    }, { 0.98137012613941343,          // re
      -0.19212671735370829             // im
    }, { 0.16835704134703863,          // re
      0.98572608093165082              // im
    }, { -0.99883222683232653,         // re
      0.048313379525507322             // im
    }, { 0.16835704134703883,          // re
      -0.98572608093165082             // im
    }, { 0.88545602565320991,          // re
      0.46472317204376851              // im
    }, { -0.77967435406322227,         // re
      0.62618519753831392              // im
    }, { -0.16835704134703833,         // re
      -0.98572608093165093             // im
    }, { 0.9068743608505454,           // re
      0.42140110777252909              // im
    }, { -0.9068743608505454,          // re
      0.42140110777252909              // im
    }, { 0.35460488704253557,          // re
      -0.93501624268541483             // im
    }, { 0.30901699437494745,          // re
      0.95105651629515353              // im
    }, { -0.77967435406322239,         // re
      -0.6261851975383137              // im
    }, { 0.98137012613941343,          // re
      0.19212671735370837              // im
    }, { -0.98137012613941343,         // re
      0.19212671735370859              // im
    }, { 0.88545602565320958,          // re
      -0.46472317204376917             // im
    }, { -0.77967435406322227,         // re
      0.62618519753831392              // im
    }, { 0.71559896074412066,          // re
      -0.69851136524893742             // im
    }, { -0.7155989607441211,          // re
      0.698511365248937                // im
    }, { 0.77967435406322216,          // re
      -0.62618519753831392             // im
    }, { -0.8854560256532098,          // re
      0.46472317204376867              // im
    }, { 0.98137012613941343,          // re
      -0.19212671735370829             // im
    }, { -0.98137012613941343,         // re
      -0.19212671735370834             // im
    }, { 0.77967435406322239,          // re
      0.6261851975383137               // im
    }, { -0.30901699437494756,         // re
      -0.95105651629515353             // im
    }, { -0.35460488704253545,         // re
      0.93501624268541483              // im
    }, { 0.90687436085054562,          // re
      -0.42140110777252882             // im
    }, { -0.90687436085054551,         // re
      -0.42140110777252887             // im
    }, { 0.16835704134703863,          // re
      0.98572608093165082              // im
    }, { 0.77967435406322216,          // re
      -0.62618519753831392             // im
    }, { -0.88545602565320991,         // re
      -0.46472317204376845             // im
    }, { -0.16835704134703852,         // re
      0.98572608093165093              // im
    }, { 0.99883222683232653,          // re
      -0.048313379525507447            // im
    }, { -0.16835704134703833,         // re
      -0.98572608093165093             // im
    }, { -0.98137012613941343,         // re
      0.19212671735370859              // im
    }, { 0.12053668025532323,          // re
      0.992708874098054                // im
    }, { 0.99883222683232664,          // re
      0.048313379525507065             // im
    }, { 0.30901699437494723,          // re
      -0.95105651629515364             // im
    }, { -0.77967435406322239,         // re
      -0.6261851975383137              // im
    }, { -0.9068743608505454,          // re
      0.42140110777252909              // im
    }, { -0.12053668025532288,         // re
      0.992708874098054                // im
    }, { 0.7155989607441211,           // re
      0.698511365248937                // im
    }, { 0.99883222683232653,          // re
      -0.048313379525507447            // im
    }, { 0.71559896074412066,          // re
      -0.69851136524893742             // im
    }, { 0.16835704134703883,          // re
      -0.98572608093165082             // im
    }, { -0.3546048870425359,          // re
      -0.93501624268541472             // im
    }, { -0.71559896074412122,         // re
      -0.69851136524893687             // im
    }, { -0.90687436085054551,         // re
      -0.42140110777252887             // im
    }, { -0.98137012613941343,         // re
      -0.19212671735370834             // im
    }, { -0.99883222683232664,         // re
      -0.048313379525507079            // im
    } };

  static const real_T costabinv[257] = { 1.0, 0.9999247018391445,
    0.99969881869620425, 0.99932238458834954, 0.99879545620517241,
    0.99811811290014918, 0.99729045667869021, 0.996312612182778,
    0.99518472667219693, 0.99390697000235606, 0.99247953459871, 0.99090263542778,
    0.989176509964781, 0.98730141815785843, 0.98527764238894122,
    0.98310548743121629, 0.98078528040323043, 0.97831737071962765,
    0.97570213003852857, 0.97293995220556018, 0.970031253194544,
    0.96697647104485207, 0.96377606579543984, 0.96043051941556579,
    0.95694033573220882, 0.95330604035419386, 0.94952818059303667,
    0.94560732538052128, 0.94154406518302081, 0.937339011912575,
    0.932992798834739, 0.92850608047321559, 0.92387953251128674,
    0.91911385169005777, 0.91420975570353069, 0.90916798309052238,
    0.90398929312344334, 0.89867446569395382, 0.89322430119551532,
    0.88763962040285393, 0.881921264348355, 0.8760700941954066,
    0.87008699110871146, 0.8639728561215867, 0.85772861000027212,
    0.8513551931052652, 0.84485356524970712, 0.83822470555483808,
    0.83146961230254524, 0.82458930278502529, 0.81758481315158371,
    0.81045719825259477, 0.80320753148064494, 0.79583690460888357,
    0.78834642762660634, 0.78073722857209449, 0.773010453362737,
    0.765167265622459, 0.75720884650648457, 0.74913639452345937,
    0.74095112535495922, 0.73265427167241282, 0.724247082951467,
    0.71573082528381859, 0.70710678118654757, 0.69837624940897292,
    0.68954054473706683, 0.680600997795453, 0.67155895484701833,
    0.66241577759017178, 0.65317284295377676, 0.64383154288979139,
    0.63439328416364549, 0.62485948814238634, 0.61523159058062682,
    0.60551104140432555, 0.59569930449243336, 0.58579785745643886,
    0.57580819141784534, 0.56573181078361312, 0.55557023301960218,
    0.54532498842204646, 0.53499761988709715, 0.524589682678469,
    0.51410274419322166, 0.50353838372571758, 0.49289819222978404,
    0.48218377207912272, 0.47139673682599764, 0.46053871095824,
    0.44961132965460654, 0.43861623853852766, 0.42755509343028208,
    0.41642956009763715, 0.40524131400498986, 0.3939920400610481,
    0.38268343236508978, 0.37131719395183749, 0.35989503653498811,
    0.34841868024943456, 0.33688985339222005, 0.32531029216226293,
    0.31368174039889152, 0.30200594931922808, 0.29028467725446233,
    0.27851968938505306, 0.26671275747489837, 0.25486565960451457,
    0.24298017990326387, 0.23105810828067111, 0.2191012401568698,
    0.20711137619221856, 0.19509032201612825, 0.18303988795514095,
    0.17096188876030122, 0.15885814333386145, 0.14673047445536175,
    0.13458070850712617, 0.1224106751992162, 0.11022220729388306,
    0.0980171403295606, 0.0857973123444399, 0.073564563599667426,
    0.061320736302208578, 0.049067674327418015, 0.036807222941358832,
    0.024541228522912288, 0.012271538285719925, 0.0, -0.012271538285719925,
    -0.024541228522912288, -0.036807222941358832, -0.049067674327418015,
    -0.061320736302208578, -0.073564563599667426, -0.0857973123444399,
    -0.0980171403295606, -0.11022220729388306, -0.1224106751992162,
    -0.13458070850712617, -0.14673047445536175, -0.15885814333386145,
    -0.17096188876030122, -0.18303988795514095, -0.19509032201612825,
    -0.20711137619221856, -0.2191012401568698, -0.23105810828067111,
    -0.24298017990326387, -0.25486565960451457, -0.26671275747489837,
    -0.27851968938505306, -0.29028467725446233, -0.30200594931922808,
    -0.31368174039889152, -0.32531029216226293, -0.33688985339222005,
    -0.34841868024943456, -0.35989503653498811, -0.37131719395183749,
    -0.38268343236508978, -0.3939920400610481, -0.40524131400498986,
    -0.41642956009763715, -0.42755509343028208, -0.43861623853852766,
    -0.44961132965460654, -0.46053871095824, -0.47139673682599764,
    -0.48218377207912272, -0.49289819222978404, -0.50353838372571758,
    -0.51410274419322166, -0.524589682678469, -0.53499761988709715,
    -0.54532498842204646, -0.55557023301960218, -0.56573181078361312,
    -0.57580819141784534, -0.58579785745643886, -0.59569930449243336,
    -0.60551104140432555, -0.61523159058062682, -0.62485948814238634,
    -0.63439328416364549, -0.64383154288979139, -0.65317284295377676,
    -0.66241577759017178, -0.67155895484701833, -0.680600997795453,
    -0.68954054473706683, -0.69837624940897292, -0.70710678118654757,
    -0.71573082528381859, -0.724247082951467, -0.73265427167241282,
    -0.74095112535495922, -0.74913639452345937, -0.75720884650648457,
    -0.765167265622459, -0.773010453362737, -0.78073722857209449,
    -0.78834642762660634, -0.79583690460888357, -0.80320753148064494,
    -0.81045719825259477, -0.81758481315158371, -0.82458930278502529,
    -0.83146961230254524, -0.83822470555483808, -0.84485356524970712,
    -0.8513551931052652, -0.85772861000027212, -0.8639728561215867,
    -0.87008699110871146, -0.8760700941954066, -0.881921264348355,
    -0.88763962040285393, -0.89322430119551532, -0.89867446569395382,
    -0.90398929312344334, -0.90916798309052238, -0.91420975570353069,
    -0.91911385169005777, -0.92387953251128674, -0.92850608047321559,
    -0.932992798834739, -0.937339011912575, -0.94154406518302081,
    -0.94560732538052128, -0.94952818059303667, -0.95330604035419386,
    -0.95694033573220882, -0.96043051941556579, -0.96377606579543984,
    -0.96697647104485207, -0.970031253194544, -0.97293995220556018,
    -0.97570213003852857, -0.97831737071962765, -0.98078528040323043,
    -0.98310548743121629, -0.98527764238894122, -0.98730141815785843,
    -0.989176509964781, -0.99090263542778, -0.99247953459871,
    -0.99390697000235606, -0.99518472667219693, -0.996312612182778,
    -0.99729045667869021, -0.99811811290014918, -0.99879545620517241,
    -0.99932238458834954, -0.99969881869620425, -0.9999247018391445, -1.0 };

  static const real_T sintabinv[257] = { 0.0, 0.012271538285719925,
    0.024541228522912288, 0.036807222941358832, 0.049067674327418015,
    0.061320736302208578, 0.073564563599667426, 0.0857973123444399,
    0.0980171403295606, 0.11022220729388306, 0.1224106751992162,
    0.13458070850712617, 0.14673047445536175, 0.15885814333386145,
    0.17096188876030122, 0.18303988795514095, 0.19509032201612825,
    0.20711137619221856, 0.2191012401568698, 0.23105810828067111,
    0.24298017990326387, 0.25486565960451457, 0.26671275747489837,
    0.27851968938505306, 0.29028467725446233, 0.30200594931922808,
    0.31368174039889152, 0.32531029216226293, 0.33688985339222005,
    0.34841868024943456, 0.35989503653498811, 0.37131719395183749,
    0.38268343236508978, 0.3939920400610481, 0.40524131400498986,
    0.41642956009763715, 0.42755509343028208, 0.43861623853852766,
    0.44961132965460654, 0.46053871095824, 0.47139673682599764,
    0.48218377207912272, 0.49289819222978404, 0.50353838372571758,
    0.51410274419322166, 0.524589682678469, 0.53499761988709715,
    0.54532498842204646, 0.55557023301960218, 0.56573181078361312,
    0.57580819141784534, 0.58579785745643886, 0.59569930449243336,
    0.60551104140432555, 0.61523159058062682, 0.62485948814238634,
    0.63439328416364549, 0.64383154288979139, 0.65317284295377676,
    0.66241577759017178, 0.67155895484701833, 0.680600997795453,
    0.68954054473706683, 0.69837624940897292, 0.70710678118654757,
    0.71573082528381859, 0.724247082951467, 0.73265427167241282,
    0.74095112535495922, 0.74913639452345937, 0.75720884650648457,
    0.765167265622459, 0.773010453362737, 0.78073722857209449,
    0.78834642762660634, 0.79583690460888357, 0.80320753148064494,
    0.81045719825259477, 0.81758481315158371, 0.82458930278502529,
    0.83146961230254524, 0.83822470555483808, 0.84485356524970712,
    0.8513551931052652, 0.85772861000027212, 0.8639728561215867,
    0.87008699110871146, 0.8760700941954066, 0.881921264348355,
    0.88763962040285393, 0.89322430119551532, 0.89867446569395382,
    0.90398929312344334, 0.90916798309052238, 0.91420975570353069,
    0.91911385169005777, 0.92387953251128674, 0.92850608047321559,
    0.932992798834739, 0.937339011912575, 0.94154406518302081,
    0.94560732538052128, 0.94952818059303667, 0.95330604035419386,
    0.95694033573220882, 0.96043051941556579, 0.96377606579543984,
    0.96697647104485207, 0.970031253194544, 0.97293995220556018,
    0.97570213003852857, 0.97831737071962765, 0.98078528040323043,
    0.98310548743121629, 0.98527764238894122, 0.98730141815785843,
    0.989176509964781, 0.99090263542778, 0.99247953459871, 0.99390697000235606,
    0.99518472667219693, 0.996312612182778, 0.99729045667869021,
    0.99811811290014918, 0.99879545620517241, 0.99932238458834954,
    0.99969881869620425, 0.9999247018391445, 1.0, 0.9999247018391445,
    0.99969881869620425, 0.99932238458834954, 0.99879545620517241,
    0.99811811290014918, 0.99729045667869021, 0.996312612182778,
    0.99518472667219693, 0.99390697000235606, 0.99247953459871, 0.99090263542778,
    0.989176509964781, 0.98730141815785843, 0.98527764238894122,
    0.98310548743121629, 0.98078528040323043, 0.97831737071962765,
    0.97570213003852857, 0.97293995220556018, 0.970031253194544,
    0.96697647104485207, 0.96377606579543984, 0.96043051941556579,
    0.95694033573220882, 0.95330604035419386, 0.94952818059303667,
    0.94560732538052128, 0.94154406518302081, 0.937339011912575,
    0.932992798834739, 0.92850608047321559, 0.92387953251128674,
    0.91911385169005777, 0.91420975570353069, 0.90916798309052238,
    0.90398929312344334, 0.89867446569395382, 0.89322430119551532,
    0.88763962040285393, 0.881921264348355, 0.8760700941954066,
    0.87008699110871146, 0.8639728561215867, 0.85772861000027212,
    0.8513551931052652, 0.84485356524970712, 0.83822470555483808,
    0.83146961230254524, 0.82458930278502529, 0.81758481315158371,
    0.81045719825259477, 0.80320753148064494, 0.79583690460888357,
    0.78834642762660634, 0.78073722857209449, 0.773010453362737,
    0.765167265622459, 0.75720884650648457, 0.74913639452345937,
    0.74095112535495922, 0.73265427167241282, 0.724247082951467,
    0.71573082528381859, 0.70710678118654757, 0.69837624940897292,
    0.68954054473706683, 0.680600997795453, 0.67155895484701833,
    0.66241577759017178, 0.65317284295377676, 0.64383154288979139,
    0.63439328416364549, 0.62485948814238634, 0.61523159058062682,
    0.60551104140432555, 0.59569930449243336, 0.58579785745643886,
    0.57580819141784534, 0.56573181078361312, 0.55557023301960218,
    0.54532498842204646, 0.53499761988709715, 0.524589682678469,
    0.51410274419322166, 0.50353838372571758, 0.49289819222978404,
    0.48218377207912272, 0.47139673682599764, 0.46053871095824,
    0.44961132965460654, 0.43861623853852766, 0.42755509343028208,
    0.41642956009763715, 0.40524131400498986, 0.3939920400610481,
    0.38268343236508978, 0.37131719395183749, 0.35989503653498811,
    0.34841868024943456, 0.33688985339222005, 0.32531029216226293,
    0.31368174039889152, 0.30200594931922808, 0.29028467725446233,
    0.27851968938505306, 0.26671275747489837, 0.25486565960451457,
    0.24298017990326387, 0.23105810828067111, 0.2191012401568698,
    0.20711137619221856, 0.19509032201612825, 0.18303988795514095,
    0.17096188876030122, 0.15885814333386145, 0.14673047445536175,
    0.13458070850712617, 0.1224106751992162, 0.11022220729388306,
    0.0980171403295606, 0.0857973123444399, 0.073564563599667426,
    0.061320736302208578, 0.049067674327418015, 0.036807222941358832,
    0.024541228522912288, 0.012271538285719925, 0.0 };

  boolean_T exitg1;

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_j);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_e);

  // Reset subsysRan breadcrumbs
  srClearBC
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_m);

  // Reset subsysRan breadcrumbs
  srClearBC(Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC);

  // MATLABSystem: '<S386>/SourceBlock'
  rEQ0 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_h.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_h.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_g1, false, 1.0);

  // Outputs for Enabled SubSystem: '<S386>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S387>/Enable'

  // Start for MATLABSystem: '<S386>/SourceBlock'
  if (rEQ0) {
    // SignalConversion generated from: '<S387>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_j =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_g1;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S386>/Enabled Subsystem'

  // MATLAB Function: '<S55>/MATLAB Function' incorporates:
  //   Constant: '<S52>/Constant'
  //   Delay: '<S55>/Delay'

  Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE[static_cast<int32_T>
    (Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE) - 1] =
    Quadcopter_ControllerWithNavigation_B.In1_j.z;
  Quadcopter_ControllerWithNavigation_B.r =
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE;
  if (Quadcopter_ControllerWithNavigation_P.Constant_Value_o == 0.0) {
    if (Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE == 0.0) {
      Quadcopter_ControllerWithNavigation_B.r =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_o;
    }
  } else if (rtIsNaN(Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE)) {
    Quadcopter_ControllerWithNavigation_B.r = (rtNaN);
  } else if (rtIsNaN(Quadcopter_ControllerWithNavigation_P.Constant_Value_o)) {
    Quadcopter_ControllerWithNavigation_B.r = (rtNaN);
  } else if (rtIsInf(Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE)) {
    Quadcopter_ControllerWithNavigation_B.r = (rtNaN);
  } else if (Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE == 0.0) {
    Quadcopter_ControllerWithNavigation_B.r = 0.0 /
      Quadcopter_ControllerWithNavigation_P.Constant_Value_o;
  } else if (rtIsInf(Quadcopter_ControllerWithNavigation_P.Constant_Value_o)) {
    if ((Quadcopter_ControllerWithNavigation_P.Constant_Value_o < 0.0) !=
        (Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE < 0.0)) {
      Quadcopter_ControllerWithNavigation_B.r =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_o;
    }
  } else {
    Quadcopter_ControllerWithNavigation_B.r = fmod
      (Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE,
       Quadcopter_ControllerWithNavigation_P.Constant_Value_o);
    rEQ0 = (Quadcopter_ControllerWithNavigation_B.r == 0.0);
    if ((!rEQ0) && (Quadcopter_ControllerWithNavigation_P.Constant_Value_o >
                    floor(Quadcopter_ControllerWithNavigation_P.Constant_Value_o)))
    {
      Quadcopter_ControllerWithNavigation_B.q = fabs
        (Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE /
         Quadcopter_ControllerWithNavigation_P.Constant_Value_o);
      rEQ0 = !(fabs(Quadcopter_ControllerWithNavigation_B.q - floor
                    (Quadcopter_ControllerWithNavigation_B.q + 0.5)) >
               2.2204460492503131E-16 * Quadcopter_ControllerWithNavigation_B.q);
    }

    if (rEQ0) {
      Quadcopter_ControllerWithNavigation_B.r =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_o * 0.0;
    } else if ((Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE < 0.0) !=
               (Quadcopter_ControllerWithNavigation_P.Constant_Value_o < 0.0)) {
      Quadcopter_ControllerWithNavigation_B.r +=
        Quadcopter_ControllerWithNavigation_P.Constant_Value_o;
    }
  }

  // MATLAB Function: '<S55>/MATLAB Function2' incorporates:
  //   MATLAB Function: '<S55>/MATLAB Function'

  Quadcopter_ControllerWithNavigation_MATLABFunction2
    (Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE,
     Quadcopter_ControllerWithNavigation_B.r + 1.0,
     Quadcopter_ControllerWithNavigation_B.orderedBuffer_am,
     &Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction2);

  // MATLABSystem: '<S382>/SourceBlock'
  rEQ0 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_n.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_n.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S382>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S383>/Enable'

  // Start for MATLABSystem: '<S382>/SourceBlock'
  if (rEQ0) {
    // SignalConversion generated from: '<S383>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_n =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_b;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_e);
  }

  // End of Outputs for SubSystem: '<S382>/Enabled Subsystem'

  // MATLAB Function: '<S56>/MATLAB Function' incorporates:
  //   Constant: '<S52>/Constant'

  Quadcopter_ControllerWithNavigation_MATLABFunction
    (Quadcopter_ControllerWithNavigation_B.In1_n.lat,
     Quadcopter_ControllerWithNavigation_P.Constant_Value_o,
     Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_k,
     &Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_e,
     &Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction_p);

  // MATLAB Function: '<S56>/MATLAB Function2'
  Quadcopter_ControllerWithNavigation_MATLABFunction2
    (Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_k,
     Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_e,
     Quadcopter_ControllerWithNavigation_B.orderedBuffer_a,
     &Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction2_o);

  // MATLAB Function: '<S57>/MATLAB Function' incorporates:
  //   Constant: '<S52>/Constant'

  Quadcopter_ControllerWithNavigation_MATLABFunction
    (Quadcopter_ControllerWithNavigation_B.In1_n.lon,
     Quadcopter_ControllerWithNavigation_P.Constant_Value_o,
     Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_f,
     &Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_h,
     &Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction_o);

  // MATLAB Function: '<S57>/MATLAB Function2'
  Quadcopter_ControllerWithNavigation_MATLABFunction2
    (Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_f,
     Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_h,
     Quadcopter_ControllerWithNavigation_B.orderedBuffer_c,
     &Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction2_k);

  // MATLABSystem: '<S69>/SourceBlock'
  rEQ0 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_f.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_f.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_f, false, 1.0);

  // Outputs for Enabled SubSystem: '<S69>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S70>/Enable'

  // Start for MATLABSystem: '<S69>/SourceBlock'
  if (rEQ0) {
    // SignalConversion generated from: '<S70>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_a =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_f;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_j);
  }

  // End of Outputs for SubSystem: '<S69>/Enabled Subsystem'

  // SignalConversion generated from: '<S53>/Bus Selector'
  Quadcopter_ControllerWithNavigation_B.x =
    Quadcopter_ControllerWithNavigation_B.In1_a.x;

  // MATLAB Function: '<S58>/MATLAB Function' incorporates:
  //   Constant: '<S52>/Constant'

  Quadcopter_ControllerWithNavigation_MATLABFunction_i
    (Quadcopter_ControllerWithNavigation_B.x,
     Quadcopter_ControllerWithNavigation_P.Constant_Value_o,
     Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_e,
     &Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_hd,
     &Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction_i);

  // MATLAB Function: '<S58>/MATLAB Function2'
  Quadcopter_ControllerWithNavigation_MATLABFunction2
    (Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_e,
     Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_hd,
     Quadcopter_ControllerWithNavigation_B.orderedBuffer_e,
     &Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction2_h);

  // MATLABSystem: '<S384>/SourceBlock'
  rEQ0 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_c.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_c.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_g, false, 1.0);

  // Outputs for Enabled SubSystem: '<S384>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S385>/Enable'

  // Start for MATLABSystem: '<S384>/SourceBlock'
  if (rEQ0) {
    // SignalConversion generated from: '<S385>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_m2 =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_g;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_m);
  }

  // End of Outputs for SubSystem: '<S384>/Enabled Subsystem'

  // MATLAB Function: '<S59>/MATLAB Function' incorporates:
  //   Constant: '<S52>/Constant'

  Quadcopter_ControllerWithNavigation_MATLABFunction_i
    (Quadcopter_ControllerWithNavigation_B.In1_m2.y,
     Quadcopter_ControllerWithNavigation_P.Constant_Value_o,
     Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_j,
     &Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_p,
     &Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction_o2);

  // MATLAB Function: '<S59>/MATLAB Function2'
  Quadcopter_ControllerWithNavigation_MATLABFunction2
    (Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_j,
     Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_p,
     Quadcopter_ControllerWithNavigation_B.orderedBuffer,
     &Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction2_a);

  // MATLAB Function: '<S52>/MATLAB Function1'
  Quadcopter_ControllerWithNavigation_B.q =
    Quadcopter_ControllerWithNavigation_B.orderedBuffer_a[0];
  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 129;
       Quadcopter_ControllerWithNavigation_B.k++) {
    Quadcopter_ControllerWithNavigation_B.q +=
      Quadcopter_ControllerWithNavigation_B.orderedBuffer_a[Quadcopter_ControllerWithNavigation_B.k
      + 1];
  }

  Quadcopter_ControllerWithNavigation_B.q /= 130.0;
  Quadcopter_ControllerWithNavigation_B.bufferStd =
    Quadcopter_ControllerWithNavigation_std
    (Quadcopter_ControllerWithNavigation_B.orderedBuffer_a);
  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 130;
       Quadcopter_ControllerWithNavigation_B.k++) {
    if (Quadcopter_ControllerWithNavigation_B.bufferStd == 0.0) {
      Quadcopter_ControllerWithNavigation_B.orderedBuffer_a[Quadcopter_ControllerWithNavigation_B.k]
        = 0.0;
    } else {
      Quadcopter_ControllerWithNavigation_B.orderedBuffer_a[Quadcopter_ControllerWithNavigation_B.k]
        =
        (Quadcopter_ControllerWithNavigation_B.orderedBuffer_a[Quadcopter_ControllerWithNavigation_B.k]
         - Quadcopter_ControllerWithNavigation_B.q) /
        Quadcopter_ControllerWithNavigation_B.bufferStd;
    }
  }

  Quadcopter_ControllerWithNavigation_B.q =
    Quadcopter_ControllerWithNavigation_B.orderedBuffer_c[0];
  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 129;
       Quadcopter_ControllerWithNavigation_B.k++) {
    Quadcopter_ControllerWithNavigation_B.q +=
      Quadcopter_ControllerWithNavigation_B.orderedBuffer_c[Quadcopter_ControllerWithNavigation_B.k
      + 1];
  }

  Quadcopter_ControllerWithNavigation_B.q /= 130.0;
  Quadcopter_ControllerWithNavigation_B.bufferStd =
    Quadcopter_ControllerWithNavigation_std
    (Quadcopter_ControllerWithNavigation_B.orderedBuffer_c);
  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 130;
       Quadcopter_ControllerWithNavigation_B.k++) {
    if (Quadcopter_ControllerWithNavigation_B.bufferStd == 0.0) {
      Quadcopter_ControllerWithNavigation_B.orderedBuffer_c[Quadcopter_ControllerWithNavigation_B.k]
        = 0.0;
    } else {
      Quadcopter_ControllerWithNavigation_B.orderedBuffer_c[Quadcopter_ControllerWithNavigation_B.k]
        =
        (Quadcopter_ControllerWithNavigation_B.orderedBuffer_c[Quadcopter_ControllerWithNavigation_B.k]
         - Quadcopter_ControllerWithNavigation_B.q) /
        Quadcopter_ControllerWithNavigation_B.bufferStd;
    }

    Quadcopter_ControllerWithNavigation_B.varargin_1_tmp = fabs
      (Quadcopter_ControllerWithNavigation_B.orderedBuffer_am[Quadcopter_ControllerWithNavigation_B.k]);
    Quadcopter_ControllerWithNavigation_B.varargin_1[Quadcopter_ControllerWithNavigation_B.k]
      = Quadcopter_ControllerWithNavigation_B.varargin_1_tmp;
    Quadcopter_ControllerWithNavigation_B.c_y[Quadcopter_ControllerWithNavigation_B.k]
      = sqrt(Quadcopter_ControllerWithNavigation_B.varargin_1_tmp);
  }

  Quadcopter_ControllerWithNavigation_B.bufferStd =
    Quadcopter_ControllerWithNavigation_B.c_y[0];
  Quadcopter_ControllerWithNavigation_B.q =
    Quadcopter_ControllerWithNavigation_maximum
    (Quadcopter_ControllerWithNavigation_B.varargin_1);
  Quadcopter_ControllerWithNavigation_B.varargin_1_tmp =
    Quadcopter_ControllerWithNavigation_B.orderedBuffer[0];
  Quadcopter_ControllerWithNavigation_B.j_y =
    Quadcopter_ControllerWithNavigation_B.orderedBuffer_e[0];
  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 129;
       Quadcopter_ControllerWithNavigation_B.k++) {
    Quadcopter_ControllerWithNavigation_B.bufferStd +=
      Quadcopter_ControllerWithNavigation_B.c_y[Quadcopter_ControllerWithNavigation_B.k
      + 1];
    Quadcopter_ControllerWithNavigation_B.varargin_1_tmp +=
      Quadcopter_ControllerWithNavigation_B.orderedBuffer[Quadcopter_ControllerWithNavigation_B.k
      + 1];
    Quadcopter_ControllerWithNavigation_B.j_y +=
      Quadcopter_ControllerWithNavigation_B.orderedBuffer_e[Quadcopter_ControllerWithNavigation_B.k
      + 1];
  }

  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 130;
       Quadcopter_ControllerWithNavigation_B.k++) {
    Quadcopter_ControllerWithNavigation_B.orderedBuffer_e_p =
      Quadcopter_ControllerWithNavigation_B.orderedBuffer_e[Quadcopter_ControllerWithNavigation_B.k];
    Quadcopter_ControllerWithNavigation_B.varargin_1[Quadcopter_ControllerWithNavigation_B.k]
      = Quadcopter_ControllerWithNavigation_B.orderedBuffer_e_p *
      Quadcopter_ControllerWithNavigation_B.orderedBuffer_e_p;
  }

  Quadcopter_ControllerWithNavigation_B.orderedBuffer_e_p =
    Quadcopter_ControllerWithNavigation_B.varargin_1[0];
  Quadcopter_ControllerWithNavigation_B.d =
    Quadcopter_ControllerWithNavigation_maximum
    (Quadcopter_ControllerWithNavigation_B.orderedBuffer_e);
  Quadcopter_ControllerWithNavigation_B.d1 =
    Quadcopter_ControllerWithNavigation_std
    (Quadcopter_ControllerWithNavigation_B.orderedBuffer_e);
  Quadcopter_ControllerWithNavigation_B.featuresVector_idx_7 =
    Quadcopter_ControllerWithNavigation_B.j_y / 130.0;
  Quadcopter_ControllerWithNavigation_B.j_y =
    Quadcopter_ControllerWithNavigation_B.orderedBuffer_a[0];
  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 129;
       Quadcopter_ControllerWithNavigation_B.k++) {
    Quadcopter_ControllerWithNavigation_B.orderedBuffer_e_p +=
      Quadcopter_ControllerWithNavigation_B.varargin_1[Quadcopter_ControllerWithNavigation_B.k
      + 1];
    Quadcopter_ControllerWithNavigation_B.j_y +=
      Quadcopter_ControllerWithNavigation_B.orderedBuffer_a[Quadcopter_ControllerWithNavigation_B.k
      + 1];
  }

  Quadcopter_ControllerWithNavigation_B.j_y /= 130.0;
  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 130;
       Quadcopter_ControllerWithNavigation_B.k++) {
    Quadcopter_ControllerWithNavigation_B.c_y[Quadcopter_ControllerWithNavigation_B.k]
      = rt_powd_snf
      (Quadcopter_ControllerWithNavigation_B.orderedBuffer_a[Quadcopter_ControllerWithNavigation_B.k]
       - Quadcopter_ControllerWithNavigation_B.j_y, 3.0);
  }

  Quadcopter_ControllerWithNavigation_B.j_y =
    Quadcopter_ControllerWithNavigation_B.c_y[0];
  Quadcopter_ControllerWithNavigation_B.d2 =
    Quadcopter_ControllerWithNavigation_maximum
    (Quadcopter_ControllerWithNavigation_B.orderedBuffer_a);
  Quadcopter_ControllerWithNavigation_B.d3 = rt_powd_snf
    (Quadcopter_ControllerWithNavigation_std
     (Quadcopter_ControllerWithNavigation_B.orderedBuffer_a), 3.0);
  Quadcopter_ControllerWithNavigation_B.v_y =
    Quadcopter_ControllerWithNavigation_B.orderedBuffer_c[0];
  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 129;
       Quadcopter_ControllerWithNavigation_B.k++) {
    Quadcopter_ControllerWithNavigation_B.j_y +=
      Quadcopter_ControllerWithNavigation_B.c_y[Quadcopter_ControllerWithNavigation_B.k
      + 1];
    Quadcopter_ControllerWithNavigation_B.v_y +=
      Quadcopter_ControllerWithNavigation_B.orderedBuffer_c[Quadcopter_ControllerWithNavigation_B.k
      + 1];
  }

  Quadcopter_ControllerWithNavigation_B.v_y /= 130.0;
  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 130;
       Quadcopter_ControllerWithNavigation_B.k++) {
    Quadcopter_ControllerWithNavigation_B.c_y[Quadcopter_ControllerWithNavigation_B.k]
      = rt_powd_snf
      (Quadcopter_ControllerWithNavigation_B.orderedBuffer_c[Quadcopter_ControllerWithNavigation_B.k]
       - Quadcopter_ControllerWithNavigation_B.v_y, 3.0);
  }

  Quadcopter_ControllerWithNavigation_B.v_y =
    Quadcopter_ControllerWithNavigation_B.c_y[0];
  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 129;
       Quadcopter_ControllerWithNavigation_B.k++) {
    Quadcopter_ControllerWithNavigation_B.v_y +=
      Quadcopter_ControllerWithNavigation_B.c_y[Quadcopter_ControllerWithNavigation_B.k
      + 1];
  }

  Quadcopter_Cont_FFTImplementationCallback_doHalfLengthBluestein
    (Quadcopter_ControllerWithNavigation_B.orderedBuffer_a, 0,
     Quadcopter_ControllerWithNavigation_B.yCol, wwc, costabinv, sintabinv);
  Quadcopter_Cont_FFTImplementationCallback_doHalfLengthBluestein
    (Quadcopter_ControllerWithNavigation_B.orderedBuffer_c, 0,
     Quadcopter_ControllerWithNavigation_B.yCol, wwc, costabinv, sintabinv);
  Quadcopter_Cont_FFTImplementationCallback_doHalfLengthBluestein
    (Quadcopter_ControllerWithNavigation_B.orderedBuffer, 0,
     Quadcopter_ControllerWithNavigation_B.yCol, wwc, costabinv, sintabinv);
  Quadcopter_Cont_FFTImplementationCallback_doHalfLengthBluestein
    (Quadcopter_ControllerWithNavigation_B.orderedBuffer_am, 0,
     Quadcopter_ControllerWithNavigation_B.yCol, wwc, costabinv, sintabinv);
  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 130;
       Quadcopter_ControllerWithNavigation_B.k++) {
    Quadcopter_ControllerWithNavigation_B.featuresVector_idx_23 = rt_hypotd_snf
      (Quadcopter_ControllerWithNavigation_B.yCol[Quadcopter_ControllerWithNavigation_B.k]
       .re,
       Quadcopter_ControllerWithNavigation_B.yCol[Quadcopter_ControllerWithNavigation_B.k]
       .im);
    Quadcopter_ControllerWithNavigation_B.orderedBuffer_a[Quadcopter_ControllerWithNavigation_B.k]
      = Quadcopter_ControllerWithNavigation_B.featuresVector_idx_23 *
      Quadcopter_ControllerWithNavigation_B.featuresVector_idx_23;
  }

  for (Quadcopter_ControllerWithNavigation_B.k = 0;
       Quadcopter_ControllerWithNavigation_B.k < 99;
       Quadcopter_ControllerWithNavigation_B.k++) {
    Quadcopter_ControllerWithNavigation_B.dv[Quadcopter_ControllerWithNavigation_B.k]
      = 0.5 * static_cast<real_T>(Quadcopter_ControllerWithNavigation_B.k) + 1.0;
  }

  Quadcopter_ControllerWithNavigation_B.featuresVector_idx_23 =
    Quadcopter_ControllerWithNavigation_trapz
    (Quadcopter_ControllerWithNavigation_B.dv,
     &Quadcopter_ControllerWithNavigation_B.orderedBuffer_a[2]);

  // MATLAB Function: '<S52>/MATLAB Function3' incorporates:
  //   MATLAB Function: '<S52>/MATLAB Function1'

  if (Quadcopter_ControllerWithNavigation_B.featuresVector_idx_23 < 1.894085) {
    if (Quadcopter_ControllerWithNavigation_B.v_y / 130.0 / rt_powd_snf
        (Quadcopter_ControllerWithNavigation_std
         (Quadcopter_ControllerWithNavigation_B.orderedBuffer_c), 3.0) <
        -0.926407) {
      if (Quadcopter_ControllerWithNavigation_B.featuresVector_idx_7 < -0.066185)
      {
        if (Quadcopter_ControllerWithNavigation_B.j_y / 130.0 /
            Quadcopter_ControllerWithNavigation_B.d3 < -0.48297) {
          Quadcopter_ControllerWithNavigation_B.label = 4.0;
        } else {
          Quadcopter_ControllerWithNavigation_B.label = 0.0;
        }
      } else {
        Quadcopter_ControllerWithNavigation_B.label = 0.0;
      }
    } else if (Quadcopter_ControllerWithNavigation_B.featuresVector_idx_7 <
               0.003763) {
      if (Quadcopter_ControllerWithNavigation_B.featuresVector_idx_7 < -0.186753)
      {
        if (Quadcopter_ControllerWithNavigation_B.d1 < 0.055735) {
          if (Quadcopter_ControllerWithNavigation_B.featuresVector_idx_23 <
              0.126809) {
            if (Quadcopter_ControllerWithNavigation_B.d < 0.195835) {
              Quadcopter_ControllerWithNavigation_B.label = 0.0;
            } else {
              Quadcopter_ControllerWithNavigation_B.label = 2.0;
            }
          } else {
            Quadcopter_ControllerWithNavigation_B.label = 0.0;
          }
        } else if (Quadcopter_ControllerWithNavigation_B.d < 0.356904) {
          Quadcopter_ControllerWithNavigation_B.label = 0.0;
        } else {
          Quadcopter_ControllerWithNavigation_B.label = 2.0;
        }
      } else if (Quadcopter_ControllerWithNavigation_B.varargin_1_tmp / 130.0 <
                 0.027177) {
        if (sqrt(Quadcopter_ControllerWithNavigation_B.orderedBuffer_e_p / 130.0)
            < 0.130393) {
          if (Quadcopter_ControllerWithNavigation_B.d1 < 0.003027) {
            Quadcopter_ControllerWithNavigation_B.label = 0.0;
          } else {
            Quadcopter_ControllerWithNavigation_B.label =
              (Quadcopter_ControllerWithNavigation_B.q /
               (Quadcopter_ControllerWithNavigation_B.bufferStd / 130.0) <
               1.018185);
          }
        } else {
          Quadcopter_ControllerWithNavigation_B.label = 0.0;
        }
      } else if (Quadcopter_ControllerWithNavigation_B.featuresVector_idx_23 <
                 0.003724) {
        if (Quadcopter_ControllerWithNavigation_B.d2 < 1.138235) {
          Quadcopter_ControllerWithNavigation_B.label = 0.0;
        } else {
          Quadcopter_ControllerWithNavigation_B.label = 2.0;
        }
      } else {
        Quadcopter_ControllerWithNavigation_B.label =
          !(Quadcopter_ControllerWithNavigation_B.featuresVector_idx_7 <
            -0.119822);
      }
    } else {
      Quadcopter_ControllerWithNavigation_B.label = 1.0;
    }
  } else {
    Quadcopter_ControllerWithNavigation_B.label = 3.0;
  }

  // End of MATLAB Function: '<S52>/MATLAB Function3'
  // MATLAB Function: '<S52>/MATLAB Function'
  Quadcopter_ControllerWithNavigation_B.q =
    Quadcopter_ControllerWithNavigation_DW.labelBuffer[static_cast<int32_T>
    (Quadcopter_ControllerWithNavigation_DW.bufferIndex) - 1];
  if ((Quadcopter_ControllerWithNavigation_B.q > 0.0) &&
      (Quadcopter_ControllerWithNavigation_B.q <= 5.0)) {
    Quadcopter_ControllerWithNavigation_DW.labelCounts[static_cast<int32_T>
      (Quadcopter_ControllerWithNavigation_B.q) - 1]--;
  }

  Quadcopter_ControllerWithNavigation_DW.labelBuffer[static_cast<int32_T>
    (Quadcopter_ControllerWithNavigation_DW.bufferIndex) - 1] =
    Quadcopter_ControllerWithNavigation_B.label;
  if (rtIsNaN(Quadcopter_ControllerWithNavigation_DW.bufferIndex)) {
    Quadcopter_ControllerWithNavigation_B.q = (rtNaN);
  } else if (rtIsInf(Quadcopter_ControllerWithNavigation_DW.bufferIndex)) {
    Quadcopter_ControllerWithNavigation_B.q = (rtNaN);
  } else if (Quadcopter_ControllerWithNavigation_DW.bufferIndex == 0.0) {
    Quadcopter_ControllerWithNavigation_B.q = 0.0;
  } else {
    Quadcopter_ControllerWithNavigation_B.q = fmod
      (Quadcopter_ControllerWithNavigation_DW.bufferIndex, 333.0);
    if (Quadcopter_ControllerWithNavigation_B.q == 0.0) {
      Quadcopter_ControllerWithNavigation_B.q = 0.0;
    } else if (Quadcopter_ControllerWithNavigation_DW.bufferIndex < 0.0) {
      Quadcopter_ControllerWithNavigation_B.q += 333.0;
    }
  }

  Quadcopter_ControllerWithNavigation_DW.bufferIndex =
    Quadcopter_ControllerWithNavigation_B.q + 1.0;
  if ((Quadcopter_ControllerWithNavigation_B.label > 0.0) &&
      (Quadcopter_ControllerWithNavigation_B.label <= 5.0)) {
    Quadcopter_ControllerWithNavigation_DW.labelCounts[static_cast<int32_T>
      (Quadcopter_ControllerWithNavigation_B.label) - 1]++;
  }

  if (!rtIsNaN(Quadcopter_ControllerWithNavigation_DW.labelCounts[0])) {
    idx = 1;
  } else {
    idx = 0;
    Quadcopter_ControllerWithNavigation_B.k = 2;
    exitg1 = false;
    while ((!exitg1) && (Quadcopter_ControllerWithNavigation_B.k < 6)) {
      if (!rtIsNaN
          (Quadcopter_ControllerWithNavigation_DW.labelCounts[Quadcopter_ControllerWithNavigation_B.k
           - 1])) {
        idx = Quadcopter_ControllerWithNavigation_B.k;
        exitg1 = true;
      } else {
        Quadcopter_ControllerWithNavigation_B.k++;
      }
    }
  }

  if (idx == 0) {
    Quadcopter_ControllerWithNavigation_B.iindx = 1;
  } else {
    Quadcopter_ControllerWithNavigation_B.q =
      Quadcopter_ControllerWithNavigation_DW.labelCounts[idx - 1];
    Quadcopter_ControllerWithNavigation_B.iindx = idx;
    for (Quadcopter_ControllerWithNavigation_B.k = idx + 1;
         Quadcopter_ControllerWithNavigation_B.k < 6;
         Quadcopter_ControllerWithNavigation_B.k++) {
      Quadcopter_ControllerWithNavigation_B.bufferStd =
        Quadcopter_ControllerWithNavigation_DW.labelCounts[Quadcopter_ControllerWithNavigation_B.k
        - 1];
      if (Quadcopter_ControllerWithNavigation_B.q <
          Quadcopter_ControllerWithNavigation_B.bufferStd) {
        Quadcopter_ControllerWithNavigation_B.q =
          Quadcopter_ControllerWithNavigation_B.bufferStd;
        Quadcopter_ControllerWithNavigation_B.iindx =
          Quadcopter_ControllerWithNavigation_B.k;
      }
    }
  }

  Quadcopter_ControllerWithNavigation_B.filteredLabel =
    Quadcopter_ControllerWithNavigation_B.iindx;

  // End of MATLAB Function: '<S52>/MATLAB Function'
  // SignalConversion generated from: '<S53>/Bus Selector'
  Quadcopter_ControllerWithNavigation_B.y =
    Quadcopter_ControllerWithNavigation_B.In1_a.y;

  // SignalConversion generated from: '<S53>/Bus Selector'
  Quadcopter_ControllerWithNavigation_B.z =
    Quadcopter_ControllerWithNavigation_B.In1_a.z;

  // Update for Delay: '<S55>/Delay' incorporates:
  //   MATLAB Function: '<S55>/MATLAB Function'

  Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE =
    Quadcopter_ControllerWithNavigation_B.r + 1.0;

  // Update absolute time
  // The "clockTick2" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.015, which is the step size
  //  of the task. Size of "clockTick2" ensures timer will not overflow during the
  //  application lifespan selected.

  Quadcopter_ControllerWithNavigation_M->Timing.clockTick2++;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void Quadcopter_ControllerWithNavigation_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Quadcopter_ControllerWithNavigation_step0();
    break;

   case 1 :
    Quadcopter_ControllerWithNavigation_step1();
    break;

   case 2 :
    Quadcopter_ControllerWithNavigation_step2();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void Quadcopter_ControllerWithNavigation_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  Quadcopter_ControllerWithNavigation_P.Constant1_Value_d[0] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant1_Value_d[1] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant_Value_f2 = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant1_Value_k[0] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant1_Value_k[1] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant_Value_l4 = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant_Value_fh[0] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant_Value_fh[1] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant_Value_fh[2] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant1_Value_h[0] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant1_Value_h[1] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant1_Value_h[2] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant3_Value = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant4_Value = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant2_Value[0] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant2_Value[1] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant2_Value[2] = rtNaNF;
  rtmSetTFinal(Quadcopter_ControllerWithNavigation_M, -1);
  Quadcopter_ControllerWithNavigation_M->Timing.stepSize0 = 0.005;

  // External mode info
  Quadcopter_ControllerWithNavigation_M->Sizes.checksums[0] = (4046238197U);
  Quadcopter_ControllerWithNavigation_M->Sizes.checksums[1] = (2941961882U);
  Quadcopter_ControllerWithNavigation_M->Sizes.checksums[2] = (599462845U);
  Quadcopter_ControllerWithNavigation_M->Sizes.checksums[3] = (3839375752U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[93];
    Quadcopter_ControllerWithNavigation_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_a;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_f;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_d3;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_eq;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem2_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.IDLE_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_d;
    systemRan[13] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Land_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem2_SubsysRanBC_d;
    systemRan[15] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Land_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem2_SubsysRanBC_b;
    systemRan[17] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Takeoff_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Waypoint_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Waypoint_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Waypoint_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Waypoint_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Waypoint_SubsysRanBC;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_h;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem_SubsysRanBC_g;
    systemRan[29] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem1_SubsysRanBC_m;
    systemRan[30] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem1_SubsysRanBC_m;
    systemRan[31] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem2_SubsysRanBC_k;
    systemRan[32] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem2_SubsysRanBC_k;
    systemRan[33] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.SendwaypointstoOBC_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.SendwaypointstoOBC_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.SendwaypointstoOBC_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.SendwaypointstoOBC_SubsysRanBC;
    systemRan[37] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.SendwaypointstoOBC_SubsysRanBC;
    systemRan[38] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_l;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_n;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_j;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[45] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[46] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[47] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[49] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[50] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[51] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[52] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[53] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[54] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[55] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[56] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[57] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[58] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[59] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[60] = &rtAlwaysEnabled;
    systemRan[61] = &rtAlwaysEnabled;
    systemRan[62] = &rtAlwaysEnabled;
    systemRan[63] = &rtAlwaysEnabled;
    systemRan[64] = &rtAlwaysEnabled;
    systemRan[65] = &rtAlwaysEnabled;
    systemRan[66] = &rtAlwaysEnabled;
    systemRan[67] = &rtAlwaysEnabled;
    systemRan[68] = &rtAlwaysEnabled;
    systemRan[69] = &rtAlwaysEnabled;
    systemRan[70] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_e;
    systemRan[71] = &rtAlwaysEnabled;
    systemRan[72] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_m;
    systemRan[73] = &rtAlwaysEnabled;
    systemRan[74] = &rtAlwaysEnabled;
    systemRan[75] = &rtAlwaysEnabled;
    systemRan[76] = &rtAlwaysEnabled;
    systemRan[77] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[78] = &rtAlwaysEnabled;
    systemRan[79] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[80] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[81] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[82] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[83] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[84] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[85] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[86] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[87] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[88] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[89] = &rtAlwaysEnabled;
    systemRan[90] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[91] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[92] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem2_SubsysRanBC;
    rteiSetModelMappingInfoPtr
      (Quadcopter_ControllerWithNavigation_M->extModeInfo,
       &Quadcopter_ControllerWithNavigation_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Quadcopter_ControllerWithNavigation_M->extModeInfo,
                        Quadcopter_ControllerWithNavigation_M->Sizes.checksums);
    rteiSetTPtr(Quadcopter_ControllerWithNavigation_M->extModeInfo, rtmGetTPtr
                (Quadcopter_ControllerWithNavigation_M));
  }

  {
    static const char_T ParameterNameStr[14] = "COM_OBS_AVOID";
    static const char_T ParameterNameStr_0[14] = "MPC_TKO_SPEED";
    static const char_T ParameterNameStr_1[15] = "MPC_LAND_SPEED";
    real_T tmp;

    // Start for If: '<S16>/If'
    Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem = -1;

    // InitializeConditions for Delay: '<S55>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_p;

    // InitializeConditions for Delay: '<S56>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_e =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_jz;

    // InitializeConditions for Delay: '<S57>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_h =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_o;

    // InitializeConditions for Delay: '<S58>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_hd =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_h;

    // InitializeConditions for Delay: '<S55>/Delay1'
    memcpy(&Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE[0],
           &Quadcopter_ControllerWithNavigation_P.Delay1_InitialCondition[0],
           130U * sizeof(real_T));

    // InitializeConditions for Delay: '<S56>/Delay1'
    memcpy(&Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_k[0],
           &Quadcopter_ControllerWithNavigation_P.Delay1_InitialCondition_a[0],
           130U * sizeof(real_T));

    // InitializeConditions for Delay: '<S57>/Delay1'
    memcpy(&Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_f[0],
           &Quadcopter_ControllerWithNavigation_P.Delay1_InitialCondition_h[0],
           130U * sizeof(real_T));

    // InitializeConditions for Delay: '<S58>/Delay1'
    memcpy(&Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_e[0],
           &Quadcopter_ControllerWithNavigation_P.Delay1_InitialCondition_f[0],
           130U * sizeof(real_T));

    // InitializeConditions for Delay: '<S59>/Delay1'
    memcpy(&Quadcopter_ControllerWithNavigation_DW.Delay1_DSTATE_j[0],
           &Quadcopter_ControllerWithNavigation_P.Delay1_InitialCondition_b[0],
           130U * sizeof(real_T));

    // InitializeConditions for Delay: '<S59>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_p =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_b;

    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
    //   Outport: '<S13>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_c =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S12>/In1' incorporates:
    //   Outport: '<S12>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_m =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S10>/In1' incorporates:
    //   Outport: '<S10>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_l =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S11>/In1' incorporates:
    //   Outport: '<S11>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_b =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S16>/IDLE'
    // InitializeConditions for Delay: '<S22>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_i =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_g0;

    // SystemInitialize for Enabled SubSystem: '<S22>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S23>/yaw_In' incorporates:
    //   Outport: '<S23>/yaw_Out'

    Quadcopter_ControllerWithNavigation_B.yaw_In =
      Quadcopter_ControllerWithNavigation_P.yaw_Out_Y0_p;

    // End of SystemInitialize for SubSystem: '<S22>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S16>/IDLE'

    // SystemInitialize for IfAction SubSystem: '<S16>/Land'
    // InitializeConditions for Delay: '<S19>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_l[0] =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_n;
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_l[1] =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_n;

    // InitializeConditions for Gain: '<S24>/Gain1' incorporates:
    //   Delay: '<S24>/Delay'

    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_n =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_m;

    // InitializeConditions for Delay: '<S25>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_b =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_j;

    // SystemInitialize for Enabled SubSystem: '<S24>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S26>/In' incorporates:
    //   Outport: '<S26>/Out'

    Quadcopter_ControllerWithNavigation_B.In =
      Quadcopter_ControllerWithNavigation_P.Out_Y0;

    // End of SystemInitialize for SubSystem: '<S24>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S25>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S27>/yaw_In' incorporates:
    //   Outport: '<S27>/yaw_Out'

    Quadcopter_ControllerWithNavigation_B.yaw_In_i =
      Quadcopter_ControllerWithNavigation_P.yaw_Out_Y0_f;

    // End of SystemInitialize for SubSystem: '<S25>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S16>/Land'

    // SystemInitialize for IfAction SubSystem: '<S16>/Take-off'
    // InitializeConditions for Delay: '<S28>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_c =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE_d =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_g;

    // SystemInitialize for Enabled SubSystem: '<S29>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S30>/yaw_In' incorporates:
    //   Outport: '<S30>/yaw_Out'

    Quadcopter_ControllerWithNavigation_B.yaw_In_ik =
      Quadcopter_ControllerWithNavigation_P.yaw_Out_Y0;

    // End of SystemInitialize for SubSystem: '<S29>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S16>/Take-off'

    // SystemInitialize for IfAction SubSystem: '<S16>/Waypoint'
    // Start for MATLABSystem: '<S21>/UAV Waypoint Follower'
    Quadcopter_ControllerWithNavigation_DW.obj.LastWaypointFlag = false;
    Quadcopter_ControllerWithNavigation_DW.obj.StartFlag = true;
    Quadcopter_ControllerWithNavigation_DW.obj.LookaheadFactor = 1.01;
    Quadcopter_ControllerWithNavigation_DW.obj.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj.NumWaypoints = 0.0;

    // InitializeConditions for MATLABSystem: '<S21>/UAV Waypoint Follower'
    Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex = 1.0;
    memset(&Quadcopter_ControllerWithNavigation_DW.obj.WaypointsInternal[0], 0,
           9U * sizeof(real_T));

    // End of SystemInitialize for SubSystem: '<S16>/Waypoint'

    // SystemInitialize for Enabled SubSystem: '<S17>/Send waypoints to OBC'
    // SystemInitialize for IfAction SubSystem: '<S46>/If Action Subsystem1'
    // Start for MATLABSystem: '<S48>/Read Parameter'
    Quadcopter_ControllerWithNavigation_DW.obj_b.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_b.SampleTime =
      Quadcopter_ControllerWithNavigation_P.ReadParameter_SampleTime_g;
    Quadcopter_ControllerWithNavigation_DW.obj_b.isInitialized = 1;
    if (Quadcopter_ControllerWithNavigation_DW.obj_b.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Quadcopter_ControllerWithNavigation_DW.obj_b.SampleTime;
    }

    Quadcopter_ControllerWithNavigation_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param(
      &ParameterNameStr_0[0], true, tmp * 1000.0);
    Quadcopter_ControllerWithNavigation_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S48>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S46>/If Action Subsystem1'

    // SystemInitialize for IfAction SubSystem: '<S46>/If Action Subsystem2'
    // Start for MATLABSystem: '<S49>/Read Parameter'
    Quadcopter_ControllerWithNavigation_DW.obj_g.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_g.SampleTime =
      Quadcopter_ControllerWithNavigation_P.ReadParameter_SampleTime_c;
    Quadcopter_ControllerWithNavigation_DW.obj_g.isInitialized = 1;
    if (Quadcopter_ControllerWithNavigation_DW.obj_g.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Quadcopter_ControllerWithNavigation_DW.obj_g.SampleTime;
    }

    Quadcopter_ControllerWithNavigation_DW.obj_g.MW_PARAMHANDLE = MW_Init_Param(
      &ParameterNameStr_1[0], true, tmp * 1000.0);
    Quadcopter_ControllerWithNavigation_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S49>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S46>/If Action Subsystem2'
    Quadcopter_ControllerWithNavigation_MATLABSystem_Init
      (&Quadcopter_ControllerWithNavigation_DW.MATLABSystem);
    Quadcopter_ControllerWithNavigation_MATLABSystem_Init
      (&Quadcopter_ControllerWithNavigation_DW.MATLABSystem_b);

    // Start for MATLABSystem: '<S43>/MATLAB System'
    Quadcopter_ControllerWithNavigation_DW.obj_mu.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_mu.isSetupComplete = true;

    // Start for MATLABSystem: '<S45>/SinkBlock' incorporates:
    //   BusAssignment: '<S34>/Bus Assignment1'

    Quadcopter_ControllerWithNavigation_DW.obj_mc.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_mc.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_mc.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint_desired);
    uORB_write_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_mc.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_mc.orbAdvertiseObj,
       &Quadcopter_ControllerWithNavigation_B.BusAssignment1_m, 1);
    Quadcopter_ControllerWithNavigation_DW.obj_mc.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S17>/Send waypoints to OBC'

    // SystemInitialize for Enabled SubSystem: '<S38>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S39>/In1' incorporates:
    //   Outport: '<S39>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1 =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S38>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S50>/In1' incorporates:
    //   Outport: '<S50>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_f =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S36>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S51>/In1' incorporates:
    //   Outport: '<S51>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_p =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S36>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S52>/Attitude controller'
    // InitializeConditions for DiscreteIntegrator: '<S111>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_h =
      Quadcopter_ControllerWithNavigation_P.PIDController_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S106>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_f =
      Quadcopter_ControllerWithNavigation_P.PIDController_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S54>/Rate Limiter2'
    Quadcopter_ControllerWithNavigation_DW.PrevY =
      Quadcopter_ControllerWithNavigation_P.RateLimiter2_IC;

    // InitializeConditions for DiscreteIntegrator: '<S161>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_o =
      Quadcopter_ControllerWithNavigation_P.PIDController1_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S156>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_n =
      Quadcopter_ControllerWithNavigation_P.PIDController1_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S54>/Rate Limiter1'
    Quadcopter_ControllerWithNavigation_DW.PrevY_b =
      Quadcopter_ControllerWithNavigation_P.RateLimiter1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S211>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_i =
      Quadcopter_ControllerWithNavigation_P.PIDController2_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S206>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_k =
      Quadcopter_ControllerWithNavigation_P.PIDController2_InitialConditionForFilter;

    // SystemInitialize for Saturate: '<S118>/Saturation' incorporates:
    //   Outport: '<S54>/tau_Yaw'

    Quadcopter_ControllerWithNavigation_B.Saturation_h =
      Quadcopter_ControllerWithNavigation_P.tau_Yaw_Y0;

    // SystemInitialize for Saturate: '<S168>/Saturation' incorporates:
    //   Outport: '<S54>/tau_Pitch'

    Quadcopter_ControllerWithNavigation_B.Saturation_c =
      Quadcopter_ControllerWithNavigation_P.tau_Pitch_Y0;

    // SystemInitialize for Sum: '<S220>/Sum' incorporates:
    //   Outport: '<S54>/tau_Roll'
    //   Saturate: '<S218>/Saturation'

    Quadcopter_ControllerWithNavigation_B.Saturation_d =
      Quadcopter_ControllerWithNavigation_P.tau_Roll_Y0;

    // End of SystemInitialize for SubSystem: '<S52>/Attitude controller'

    // SystemInitialize for Enabled SubSystem: '<S52>/Position & Altitude controller' 
    // InitializeConditions for DiscreteIntegrator: '<S519>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE =
      Quadcopter_ControllerWithNavigation_P.PID_Altitude_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S524>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE =
      Quadcopter_ControllerWithNavigation_P.PID_Altitude_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S569>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_m =
      Quadcopter_ControllerWithNavigation_P.PID_vz_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S574>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_c =
      Quadcopter_ControllerWithNavigation_P.PID_vz_InitialConditionForIntegrator;

    // SystemInitialize for Sum: '<S583>/Sum' incorporates:
    //   Outport: '<S66>/tau_Thrust'
    //   Saturate: '<S581>/Saturation'

    Quadcopter_ControllerWithNavigation_B.Saturation =
      Quadcopter_ControllerWithNavigation_P.tau_Thrust_Y0;

    // SystemInitialize for Gain: '<S66>/Gain1' incorporates:
    //   Outport: '<S66>/des_pitch'

    Quadcopter_ControllerWithNavigation_B.Gain1 =
      Quadcopter_ControllerWithNavigation_P.des_pitch_Y0;

    // SystemInitialize for Outport: '<S66>/des_roll' incorporates:
    //   Saturate: '<S433>/Saturation'

    Quadcopter_ControllerWithNavigation_B.Saturation_n[1] =
      Quadcopter_ControllerWithNavigation_P.des_roll_Y0;

    // End of SystemInitialize for SubSystem: '<S52>/Position & Altitude controller' 

    // SystemInitialize for Enabled SubSystem: '<S69>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S70>/In1' incorporates:
    //   Outport: '<S70>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_a =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_g;

    // End of SystemInitialize for SubSystem: '<S69>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S55>/MATLAB Function2'
    Quadcopter_ControllerWithNavigation_MATLABFunction2_Init
      (&Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction2);

    // SystemInitialize for MATLAB Function: '<S56>/MATLAB Function'
    Quadcopter_ControllerWithNavigation_MATLABFunction_Init
      (&Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction_p);

    // SystemInitialize for MATLAB Function: '<S56>/MATLAB Function2'
    Quadcopter_ControllerWithNavigation_MATLABFunction2_Init
      (&Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction2_o);

    // SystemInitialize for MATLAB Function: '<S57>/MATLAB Function'
    Quadcopter_ControllerWithNavigation_MATLABFunction_Init
      (&Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction_o);

    // SystemInitialize for MATLAB Function: '<S57>/MATLAB Function2'
    Quadcopter_ControllerWithNavigation_MATLABFunction2_Init
      (&Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction2_k);

    // SystemInitialize for MATLAB Function: '<S58>/MATLAB Function'
    Quadcopter_ControllerWithNavigation_MATLABFunction_m_Init
      (&Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction_i);

    // SystemInitialize for MATLAB Function: '<S58>/MATLAB Function2'
    Quadcopter_ControllerWithNavigation_MATLABFunction2_Init
      (&Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction2_h);

    // SystemInitialize for MATLAB Function: '<S59>/MATLAB Function'
    Quadcopter_ControllerWithNavigation_MATLABFunction_m_Init
      (&Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction_o2);

    // SystemInitialize for MATLAB Function: '<S59>/MATLAB Function2'
    Quadcopter_ControllerWithNavigation_MATLABFunction2_Init
      (&Quadcopter_ControllerWithNavigation_DW.sf_MATLABFunction2_a);

    // SystemInitialize for Enabled SubSystem: '<S382>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S383>/In1' incorporates:
    //   Outport: '<S383>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_n =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_j;

    // End of SystemInitialize for SubSystem: '<S382>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S384>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S385>/In1' incorporates:
    //   Outport: '<S385>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_m2 =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_eg;

    // End of SystemInitialize for SubSystem: '<S384>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S52>/MATLAB Function'
    Quadcopter_ControllerWithNavigation_DW.bufferIndex = 1.0;

    // SystemInitialize for Enabled SubSystem: '<S386>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S387>/In1' incorporates:
    //   Outport: '<S387>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_j =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S386>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_d.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_d.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_d.orbMetadataObj = ORB_ID
      (actuator_armed);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_d.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_d.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S9>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_m.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_m.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_m.orbMetadataObj = ORB_ID
      (vehicle_local_position);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_m.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_m.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S17>/Read Parameter'
    Quadcopter_ControllerWithNavigation_DW.obj_k.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_k.SampleTime =
      Quadcopter_ControllerWithNavigation_P.ReadParameter_SampleTime;
    Quadcopter_ControllerWithNavigation_DW.obj_k.isInitialized = 1;
    if (Quadcopter_ControllerWithNavigation_DW.obj_k.SampleTime == -1.0) {
      tmp = 0.2;
    } else {
      tmp = Quadcopter_ControllerWithNavigation_DW.obj_k.SampleTime;
    }

    Quadcopter_ControllerWithNavigation_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param(
      &ParameterNameStr[0], true, tmp * 1000.0);
    Quadcopter_ControllerWithNavigation_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S17>/Read Parameter'

    // Start for MATLABSystem: '<S38>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_e.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_e.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_e.orbMetadataObj = ORB_ID
      (vehicle_trajectory_waypoint);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_e.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_e.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S36>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_kz.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_kz.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_kz.orbMetadataObj = ORB_ID
      (position_setpoint_triplet);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_kz.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_kz.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_kz.isSetupComplete = true;

    // Start for MATLABSystem: '<S35>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_gf.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_gf.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_gf.orbMetadataObj = ORB_ID
      (home_position);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_gf.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_gf.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_gf.isSetupComplete = true;

    // Start for MATLABSystem: '<S17>/LLA2LocalCoordinates'
    Quadcopter_ControllerWithNavigation_DW.obj_mr.previousValidReceived = false;
    Quadcopter_ControllerWithNavigation_DW.obj_mr.nextValidReceived = false;
    Quadcopter_ControllerWithNavigation_DW.obj_mr.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_mr.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_mr.isSetupComplete = true;

    // Start for MATLABSystem: '<S8>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_gv.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_gv.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_gv.orbMetadataObj = ORB_ID
      (vehicle_attitude);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_gv.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_gv.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_gv.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_po.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_po.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_po.orbMetadataObj = ORB_ID
      (vehicle_odometry);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_po.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_po.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_po.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
    //   Constant: '<S5>/Constant1'

    Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus = 0U;
    Quadcopter_ControllerWithNavigation_DW.obj_p.isInitialized = 0;
    Quadcopter_ControllerWithNavigation_DW.obj_p.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_SystemCore_setup
      (&Quadcopter_ControllerWithNavigation_DW.obj_p,
       Quadcopter_ControllerWithNavigation_B.In1_b.armed,
       Quadcopter_ControllerWithNavigation_P.Constant1_Value_c);

    // Start for MATLABSystem: '<S33>/PX4 Timestamp'
    Quadcopter_ControllerWithNavigation_DW.obj_np.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_np.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_np.isSetupComplete = true;

    // Start for MATLABSystem: '<S386>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_h.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_h.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_h.orbMetadataObj = ORB_ID
      (sensor_mag);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_h.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_h.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S382>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_n.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_n.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_n.orbMetadataObj = ORB_ID
      (vehicle_gps_position);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_n.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_n.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S69>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_f.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_f.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_f.orbMetadataObj = ORB_ID
      (sensor_accel);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_f.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_f.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<S384>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_c.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_c.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_c.orbMetadataObj = ORB_ID
      (sensor_gyro);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_c.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_c.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_c.isSetupComplete = true;
  }
}

// Model terminate function
void Quadcopter_ControllerWithNavigation_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_d.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_d.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_d.isSetupComplete) {
      uORB_read_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'

  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_m.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_m.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_m.isSetupComplete) {
      uORB_read_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'

  // Terminate for MATLABSystem: '<S17>/Read Parameter'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_k.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/Read Parameter'

  // Terminate for MATLABSystem: '<S38>/SourceBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_e.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_e.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_e.isSetupComplete) {
      uORB_read_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S38>/SourceBlock'

  // Terminate for MATLABSystem: '<S36>/SourceBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_kz.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_kz.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_kz.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_kz.isSetupComplete) {
      uORB_read_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_kz.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S36>/SourceBlock'

  // Terminate for MATLABSystem: '<S35>/SourceBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_gf.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_gf.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_gf.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_gf.isSetupComplete) {
      uORB_read_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_gf.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S35>/SourceBlock'

  // Terminate for MATLABSystem: '<S17>/LLA2LocalCoordinates'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_mr.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_mr.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/LLA2LocalCoordinates'

  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_gv.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_gv.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_gv.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_gv.isSetupComplete) {
      uORB_read_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_gv.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_po.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_po.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_po.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_po.isSetupComplete) {
      uORB_read_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_po.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_p.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_p.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_p.isSetupComplete) {
      status = pwm_disarm
        (&Quadcopter_ControllerWithNavigation_DW.obj_p.pwmDevHandler,
         &Quadcopter_ControllerWithNavigation_DW.obj_p.armAdvertiseObj);
      Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus = static_cast<
        uint16_T>(Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus |
                  status);
      status = pwm_resetServo
        (&Quadcopter_ControllerWithNavigation_DW.obj_p.pwmDevHandler,
         Quadcopter_ControllerWithNavigation_DW.obj_p.servoCount,
         Quadcopter_ControllerWithNavigation_DW.obj_p.channelMask,
         Quadcopter_ControllerWithNavigation_DW.obj_p.isMain,
         &Quadcopter_ControllerWithNavigation_DW.obj_p.actuatorAdvertiseObj);
      Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus =
        static_cast<uint16_T>
        (Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus | status);
      status = pwm_close
        (&Quadcopter_ControllerWithNavigation_DW.obj_p.pwmDevHandler,
         &Quadcopter_ControllerWithNavigation_DW.obj_p.actuatorAdvertiseObj,
         &Quadcopter_ControllerWithNavigation_DW.obj_p.armAdvertiseObj);
      Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus =
        static_cast<uint16_T>
        (Quadcopter_ControllerWithNavigation_DW.obj_p.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/PX4 PWM Output'

  // Terminate for Enabled SubSystem: '<S17>/Send waypoints to OBC'
  Quadcopter_ControllerWithNavigation_MATLABSystem_Term
    (&Quadcopter_ControllerWithNavigation_DW.MATLABSystem);

  // Terminate for IfAction SubSystem: '<S46>/If Action Subsystem2'
  // Terminate for MATLABSystem: '<S49>/Read Parameter'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_g.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S49>/Read Parameter'
  // End of Terminate for SubSystem: '<S46>/If Action Subsystem2'

  // Terminate for IfAction SubSystem: '<S46>/If Action Subsystem1'
  // Terminate for MATLABSystem: '<S48>/Read Parameter'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_b.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S48>/Read Parameter'
  // End of Terminate for SubSystem: '<S46>/If Action Subsystem1'
  Quadcopter_ControllerWithNavigation_MATLABSystem_Term
    (&Quadcopter_ControllerWithNavigation_DW.MATLABSystem_b);

  // Terminate for MATLABSystem: '<S43>/MATLAB System'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_mu.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_mu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S43>/MATLAB System'

  // Terminate for MATLABSystem: '<S45>/SinkBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_mc.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_mc.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_mc.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_mc.isSetupComplete) {
      uORB_write_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_mc.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S45>/SinkBlock'
  // End of Terminate for SubSystem: '<S17>/Send waypoints to OBC'

  // Terminate for MATLABSystem: '<S33>/PX4 Timestamp'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_np.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_np.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S33>/PX4 Timestamp'
  // Terminate for MATLABSystem: '<S386>/SourceBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_h.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_h.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_h.isSetupComplete) {
      uORB_read_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_h.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S386>/SourceBlock'

  // Terminate for MATLABSystem: '<S382>/SourceBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_n.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_n.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_n.isSetupComplete) {
      uORB_read_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S382>/SourceBlock'

  // Terminate for MATLABSystem: '<S69>/SourceBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_f.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_f.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_f.isSetupComplete) {
      uORB_read_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_f.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S69>/SourceBlock'

  // Terminate for MATLABSystem: '<S384>/SourceBlock'
  if (!Quadcopter_ControllerWithNavigation_DW.obj_c.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Quadcopter_ControllerWithNavigation_DW.obj_c.isInitialized == 1) &&
        Quadcopter_ControllerWithNavigation_DW.obj_c.isSetupComplete) {
      uORB_read_terminate
        (&Quadcopter_ControllerWithNavigation_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S384>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
