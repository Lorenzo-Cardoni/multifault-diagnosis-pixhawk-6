//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Quadcopter_ControllerWithNavigation.cpp
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
static void Quadcopter_ControllerWithNavigation_SystemCore_setup
  (px4_internal_block_PWM_Quadcopter_ControllerWithNavigation_T *obj, boolean_T
   varargin_1, boolean_T varargin_2);
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
      Quadcopter_ControllerWithNavigation_B.q = ceil(u1);
    } else {
      Quadcopter_ControllerWithNavigation_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != Quadcopter_ControllerWithNavigation_B.q)) {
      Quadcopter_ControllerWithNavigation_B.q = fabs(u0 / u1);
      if (!(fabs(Quadcopter_ControllerWithNavigation_B.q - floor
                 (Quadcopter_ControllerWithNavigation_B.q + 0.5)) > DBL_EPSILON *
            Quadcopter_ControllerWithNavigation_B.q)) {
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
      Quadcopter_ControllerWithNavigation_B.i1_l = 1;
    } else {
      Quadcopter_ControllerWithNavigation_B.i1_l = -1;
    }

    y = atan2(static_cast<real_T>(Quadcopter_ControllerWithNavigation_B.i),
              static_cast<real_T>(Quadcopter_ControllerWithNavigation_B.i1_l));
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
    Quadcopter_ControllerWithNavigation_B.latp2_g =
      (Quadcopter_ControllerWithNavigation_B.flat > 90.0);

    // Start for MATLABSystem: '<S17>/LLA2LocalCoordinates'
    Quadcopter_ControllerWithNavigation_B.dLon += 180.0;
    Quadcopter_ControllerWithNavigation_B.Rn =
      Quadcopter_ControllerWithNavigation_B.dLat * static_cast<real_T>
      (Quadcopter_ControllerWithNavigation_B.latp2_g);
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
       (Quadcopter_ControllerWithNavigation_B.latp2_g) - 90.0)) *
      Quadcopter_ControllerWithNavigation_B.Rn * static_cast<real_T>
      (Quadcopter_ControllerWithNavigation_B.latp2_g) +
      Quadcopter_ControllerWithNavigation_B.dLat * static_cast<real_T>
      (!Quadcopter_ControllerWithNavigation_B.latp2_g);
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
    Quadcopter_ControllerWithNavigation_B.b_x = (rtNaN);
  } else {
    Quadcopter_ControllerWithNavigation_B.b_x =
      Quadcopter_ControllerWithNavigation_rt_remd_snf(lla0[0], 360.0);
    Quadcopter_ControllerWithNavigation_B.absx = fabs
      (Quadcopter_ControllerWithNavigation_B.b_x);
    if (Quadcopter_ControllerWithNavigation_B.absx > 180.0) {
      if (Quadcopter_ControllerWithNavigation_B.b_x > 0.0) {
        Quadcopter_ControllerWithNavigation_B.b_x -= 360.0;
      } else {
        Quadcopter_ControllerWithNavigation_B.b_x += 360.0;
      }

      Quadcopter_ControllerWithNavigation_B.absx = fabs
        (Quadcopter_ControllerWithNavigation_B.b_x);
    }

    if (Quadcopter_ControllerWithNavigation_B.absx <= 45.0) {
      Quadcopter_ControllerWithNavigation_B.b_x = cos(0.017453292519943295 *
        Quadcopter_ControllerWithNavigation_B.b_x);
    } else if (Quadcopter_ControllerWithNavigation_B.absx <= 135.0) {
      if (Quadcopter_ControllerWithNavigation_B.b_x > 0.0) {
        Quadcopter_ControllerWithNavigation_B.b_x = -sin
          ((Quadcopter_ControllerWithNavigation_B.b_x - 90.0) *
           0.017453292519943295);
      } else {
        Quadcopter_ControllerWithNavigation_B.b_x = sin
          ((Quadcopter_ControllerWithNavigation_B.b_x + 90.0) *
           0.017453292519943295);
      }
    } else {
      if (Quadcopter_ControllerWithNavigation_B.b_x > 0.0) {
        Quadcopter_ControllerWithNavigation_B.b_x =
          (Quadcopter_ControllerWithNavigation_B.b_x - 180.0) *
          0.017453292519943295;
      } else {
        Quadcopter_ControllerWithNavigation_B.b_x =
          (Quadcopter_ControllerWithNavigation_B.b_x + 180.0) *
          0.017453292519943295;
      }

      Quadcopter_ControllerWithNavigation_B.b_x = -cos
        (Quadcopter_ControllerWithNavigation_B.b_x);
    }
  }

  xyzNED[0] = Quadcopter_ControllerWithNavigation_B.dLat /
    (Quadcopter_ControllerWithNavigation_rt_atan2d_snf(1.0, 0.99330562000985867 /
      Quadcopter_ControllerWithNavigation_B.flat *
      Quadcopter_ControllerWithNavigation_B.Rn) * 57.295779513082323);
  xyzNED[1] = Quadcopter_ControllerWithNavigation_B.dLon /
    (Quadcopter_ControllerWithNavigation_rt_atan2d_snf(1.0,
      Quadcopter_ControllerWithNavigation_B.Rn *
      Quadcopter_ControllerWithNavigation_B.b_x) * 57.295779513082323);
  xyzNED[2] = -lla[2] + lla0[2];
  Quadcopter_ControllerWithNavigation_B.b_j[0] = rtIsNaN(xyzNED[0]);
  Quadcopter_ControllerWithNavigation_B.b_j[1] = rtIsNaN(xyzNED[1]);
  Quadcopter_ControllerWithNavigation_B.b_j[2] = rtIsNaN(xyzNED[2]);
  Quadcopter_ControllerWithNavigation_B.latp2_g = false;
  Quadcopter_ControllerWithNavigation_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (Quadcopter_ControllerWithNavigation_B.b_k < 3)) {
    if (Quadcopter_ControllerWithNavigation_B.b_j[Quadcopter_ControllerWithNavigation_B.b_k])
    {
      Quadcopter_ControllerWithNavigation_B.latp2_g = true;
      exitg1 = true;
    } else {
      Quadcopter_ControllerWithNavigation_B.b_k++;
    }
  }

  // Start for MATLABSystem: '<S17>/LLA2LocalCoordinates'
  Quadcopter_ControllerWithNavigation_B.dLat = 0.0 / static_cast<real_T>
    (!Quadcopter_ControllerWithNavigation_B.latp2_g);
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

// Model step function
void Quadcopter_ControllerWithNavigation_step(void)
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
    (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_e);

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
  srClearBC(Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC);

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
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_e);
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
     &Quadcopter_ControllerWithNavigation_B.ParamStep_n);
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    Quadcopter_ControllerWithNavigation_B.ParamStep_n = 0;
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
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of Outputs for SubSystem: '<S36>/Enabled Subsystem'

  // MATLABSystem: '<S35>/SourceBlock'
  Quadcopter_ControllerWithNavigation_B.latp2 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_gf.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_gf.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_p, false, 1.0);

  // Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S50>/Enable'

  // Start for MATLABSystem: '<S35>/SourceBlock'
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    // SignalConversion generated from: '<S50>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_f =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_p;
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
    if (Quadcopter_ControllerWithNavigation_B.ParamStep_n != 0) {
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[0] =
        Quadcopter_ControllerWithNavigation_B.In1.waypoints[0].position[0];
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[1] =
        Quadcopter_ControllerWithNavigation_B.In1.waypoints[0].position[1];
      Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2] =
        Quadcopter_ControllerWithNavigation_B.In1.waypoints[0].position[2];
    } else {
      Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[0] =
        Quadcopter_ControllerWithNavigation_B.In1_p.current.lat;
      Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[1] =
        Quadcopter_ControllerWithNavigation_B.In1_p.current.lon;
      Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[2] =
        Quadcopter_ControllerWithNavigation_B.In1_p.current.alt;
      Quadcopter_ControllerWithNavigation_lla2ned
        (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c,
         Quadcopter_ControllerWithNavigation_B.lla0,
         Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1);
    }
  }

  if (Quadcopter_ControllerWithNavigation_B.In1_f.valid_hpos &&
      (Quadcopter_ControllerWithNavigation_B.In1_p.previous.valid ||
       Quadcopter_ControllerWithNavigation_DW.obj_mr.previousValidReceived)) {
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[0] =
      Quadcopter_ControllerWithNavigation_B.In1_p.previous.lat;
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[1] =
      Quadcopter_ControllerWithNavigation_B.In1_p.previous.lon;
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[2] =
      Quadcopter_ControllerWithNavigation_B.In1_p.previous.alt;
    Quadcopter_ControllerWithNavigation_lla2ned
      (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c,
       Quadcopter_ControllerWithNavigation_B.lla0,
       Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k);
  }

  if (Quadcopter_ControllerWithNavigation_B.In1_f.valid_hpos &&
      (Quadcopter_ControllerWithNavigation_B.In1_p.next.valid ||
       Quadcopter_ControllerWithNavigation_DW.obj_mr.nextValidReceived)) {
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[0] =
      Quadcopter_ControllerWithNavigation_B.In1_p.next.lat;
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[1] =
      Quadcopter_ControllerWithNavigation_B.In1_p.next.lon;
    Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[2] =
      Quadcopter_ControllerWithNavigation_B.In1_p.next.alt;
    Quadcopter_ControllerWithNavigation_lla2ned
      (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c,
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
      Quadcopter_ControllerWithNavigation_B.y =
        Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[3 *
        Quadcopter_ControllerWithNavigation_B.j + 1];
      Quadcopter_ControllerWithNavigation_B.i1 =
        Quadcopter_ControllerWithNavigation_B.j << 1;
      Quadcopter_ControllerWithNavigation_B.x[Quadcopter_ControllerWithNavigation_B.i1]
        = (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[3 *
           Quadcopter_ControllerWithNavigation_B.j] !=
           Quadcopter_ControllerWithNavigation_B.y);
      Quadcopter_ControllerWithNavigation_B.x[Quadcopter_ControllerWithNavigation_B.i1
        + 1] = (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[3 *
                Quadcopter_ControllerWithNavigation_B.j + 2] !=
                Quadcopter_ControllerWithNavigation_B.y);
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
        if (Quadcopter_ControllerWithNavigation_B.x[Quadcopter_ControllerWithNavigation_B.ix
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

        Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[0] =
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p
          [static_cast<int32_T>
          (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) - 1];
        Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[1] =
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
          static_cast<int32_T>
          (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) +
          Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0) - 1];
        Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[2] =
          Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate_p[(
          static_cast<int32_T>
          (Quadcopter_ControllerWithNavigation_DW.obj.WaypointIndex + 1.0) +
          (Quadcopter_ControllerWithNavigation_B.waypoints_size_idx_0 << 1)) - 1];
        guard2 = false;
        if (Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c) <= 2.0) {
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
          Quadcopter_ControllerWithNavigation_B.y =
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
            Quadcopter_ControllerWithNavigation_B.y -
            Quadcopter_ControllerWithNavigation_B.lambda;
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1[2] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
            Quadcopter_ControllerWithNavigation_B.y;
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
              Quadcopter_ControllerWithNavigation_B.y;
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
        Quadcopter_ControllerWithNavigation_B.y =
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
        Quadcopter_ControllerWithNavigation_B.y +=
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
        Quadcopter_ControllerWithNavigation_B.y +=
          Quadcopter_ControllerWithNavigation_B.b *
          Quadcopter_ControllerWithNavigation_B.b;
        Quadcopter_ControllerWithNavigation_B.lambda =
          (Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k *
           Quadcopter_ControllerWithNavigation_B.b +
           Quadcopter_ControllerWithNavigation_B.lambda) /
          Quadcopter_ControllerWithNavigation_B.y;
        if (Quadcopter_ControllerWithNavigation_B.lambda < 0.0) {
          Quadcopter_ControllerWithNavigation_B.lambda =
            Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1);
        } else if (Quadcopter_ControllerWithNavigation_B.lambda > 1.0) {
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[0] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0] -
            Quadcopter_ControllerWithNavigation_B.lla0[0];
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[1] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1] -
            Quadcopter_ControllerWithNavigation_B.lla0[1];
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[2] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
            Quadcopter_ControllerWithNavigation_B.lla0[2];
          Quadcopter_ControllerWithNavigation_B.lambda =
            Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c);
        } else {
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[0] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b_varargout_3[0] +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0]);
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[1] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b_varargout_3[1] +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1]);
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[2] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2]);
          Quadcopter_ControllerWithNavigation_B.lambda =
            Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c);
        }

        if (Quadcopter_ControllerWithNavigation_DW.obj.LastWaypointFlag) {
          Quadcopter_ControllerWithNavigation_B.lambda =
            ((Quadcopter_ControllerWithNavigation_B.Gain_i *
              Quadcopter_ControllerWithNavigation_B.b_varargout_3[0] +
              Quadcopter_ControllerWithNavigation_B.Filter *
              Quadcopter_ControllerWithNavigation_B.b_varargout_3[1]) +
             (Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
              Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2]) *
             Quadcopter_ControllerWithNavigation_B.b) /
            Quadcopter_ControllerWithNavigation_B.y;
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[0] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[0] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b_varargout_3[0] +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0]);
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[1] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[1] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b_varargout_3[1] +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1]);
          Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c[2] =
            Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2] -
            (Quadcopter_ControllerWithNavigation_B.lambda *
             Quadcopter_ControllerWithNavigation_B.b +
             Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2]);
          Quadcopter_ControllerWithNavigation_B.lambda =
            Quadcopter_ControllerWithNavigation_norm
            (Quadcopter_ControllerWithNavigation_B.rtb_Reshape1_c);
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
                &Quadcopter_ControllerWithNavigation_B.b_exponent_p);
          Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k = ldexp(1.0,
            Quadcopter_ControllerWithNavigation_B.b_exponent_p - 53);
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
            * Quadcopter_ControllerWithNavigation_B.y));
        Quadcopter_ControllerWithNavigation_B.Gain_i =
          (-Quadcopter_ControllerWithNavigation_B.b +
           Quadcopter_ControllerWithNavigation_B.lambda) / 2.0 /
          Quadcopter_ControllerWithNavigation_B.y;
        Quadcopter_ControllerWithNavigation_B.y =
          (-Quadcopter_ControllerWithNavigation_B.b -
           Quadcopter_ControllerWithNavigation_B.lambda) / 2.0 /
          Quadcopter_ControllerWithNavigation_B.y;
        if ((Quadcopter_ControllerWithNavigation_B.Gain_i >=
             Quadcopter_ControllerWithNavigation_B.y) || rtIsNaN
            (Quadcopter_ControllerWithNavigation_B.y)) {
          Quadcopter_ControllerWithNavigation_B.y =
            Quadcopter_ControllerWithNavigation_B.Gain_i;
        }

        Quadcopter_ControllerWithNavigation_B.lla0[0] = (1.0 -
          Quadcopter_ControllerWithNavigation_B.y) *
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[0] +
          Quadcopter_ControllerWithNavigation_B.y *
          Quadcopter_ControllerWithNavigation_B.lla0[0];
        Quadcopter_ControllerWithNavigation_B.lla0[1] = (1.0 -
          Quadcopter_ControllerWithNavigation_B.y) *
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[1] +
          Quadcopter_ControllerWithNavigation_B.y *
          Quadcopter_ControllerWithNavigation_B.lla0[1];
        Quadcopter_ControllerWithNavigation_B.lla0[2] = (1.0 -
          Quadcopter_ControllerWithNavigation_B.y) *
          Quadcopter_ControllerWithNavigation_B.MatrixConcatenate1_k[2] +
          Quadcopter_ControllerWithNavigation_B.y *
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

      Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE =
        Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_g0;

      // End of InitializeConditions for SubSystem: '<S16>/IDLE'
    }

    // Outputs for IfAction SubSystem: '<S16>/IDLE' incorporates:
    //   ActionPort: '<S18>/Action Port'

    // Outputs for Enabled SubSystem: '<S22>/Enabled Subsystem2' incorporates:
    //   EnablePort: '<S23>/Enable'

    if (Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE > 0.0) {
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

    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE =
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
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  // Start for MATLABSystem: '<S8>/SourceBlock'
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    // SignalConversion generated from: '<S12>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_m =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_b;
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
  Quadcopter_ControllerWithNavigation_B.y =
    Quadcopter_ControllerWithNavigation_B.In1_m.q[3];

  // Switch: '<S55>/Switch' incorporates:
  //   Constant: '<S55>/Constant'
  //   DataTypeConversion: '<S2>/Data Type Conversion'
  //   Product: '<S561>/Product'
  //   Product: '<S561>/Product1'
  //   Product: '<S561>/Product2'
  //   Product: '<S561>/Product3'
  //   SignalConversion generated from: '<S5>/Product1'
  //   Sum: '<S561>/Sum'

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
    Quadcopter_ControllerWithNavigation_B.y =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_im[3];
  }

  // End of Switch: '<S55>/Switch'

  // Sqrt: '<S568>/sqrt' incorporates:
  //   Product: '<S569>/Product'
  //   Product: '<S569>/Product1'
  //   Product: '<S569>/Product2'
  //   Product: '<S569>/Product3'
  //   Sum: '<S569>/Sum'

  Quadcopter_ControllerWithNavigation_B.Filter = sqrt
    (((Quadcopter_ControllerWithNavigation_B.Gain_i *
       Quadcopter_ControllerWithNavigation_B.Gain_i +
       Quadcopter_ControllerWithNavigation_B.lambda *
       Quadcopter_ControllerWithNavigation_B.lambda) +
      Quadcopter_ControllerWithNavigation_B.b *
      Quadcopter_ControllerWithNavigation_B.b) +
     Quadcopter_ControllerWithNavigation_B.y *
     Quadcopter_ControllerWithNavigation_B.y);

  // Product: '<S563>/Product'
  Quadcopter_ControllerWithNavigation_B.Gain_i /=
    Quadcopter_ControllerWithNavigation_B.Filter;

  // Product: '<S563>/Product1'
  Quadcopter_ControllerWithNavigation_B.lambda /=
    Quadcopter_ControllerWithNavigation_B.Filter;

  // Product: '<S563>/Product2'
  Quadcopter_ControllerWithNavigation_B.b /=
    Quadcopter_ControllerWithNavigation_B.Filter;

  // Product: '<S563>/Product3'
  Quadcopter_ControllerWithNavigation_B.Filter =
    Quadcopter_ControllerWithNavigation_B.y /
    Quadcopter_ControllerWithNavigation_B.Filter;

  // Fcn: '<S56>/fcn2' incorporates:
  //   Fcn: '<S56>/fcn5'

  Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k =
    Quadcopter_ControllerWithNavigation_B.Gain_i *
    Quadcopter_ControllerWithNavigation_B.Gain_i;
  Quadcopter_ControllerWithNavigation_B.Filter_o =
    Quadcopter_ControllerWithNavigation_B.lambda *
    Quadcopter_ControllerWithNavigation_B.lambda;
  Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp =
    Quadcopter_ControllerWithNavigation_B.b *
    Quadcopter_ControllerWithNavigation_B.b;
  Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp_g =
    Quadcopter_ControllerWithNavigation_B.Filter *
    Quadcopter_ControllerWithNavigation_B.Filter;

  // Trigonometry: '<S562>/Trigonometric Function1' incorporates:
  //   Concatenate: '<S562>/Vector Concatenate'
  //   Fcn: '<S56>/fcn1'
  //   Fcn: '<S56>/fcn2'

  Quadcopter_ControllerWithNavigation_B.VectorConcatenate[0] =
    Quadcopter_ControllerWithNavigation_rt_atan2d_snf
    ((Quadcopter_ControllerWithNavigation_B.lambda *
      Quadcopter_ControllerWithNavigation_B.b +
      Quadcopter_ControllerWithNavigation_B.Gain_i *
      Quadcopter_ControllerWithNavigation_B.Filter) * 2.0,
     ((Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k +
       Quadcopter_ControllerWithNavigation_B.Filter_o) -
      Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp) -
     Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp_g);

  // Fcn: '<S56>/fcn3'
  Quadcopter_ControllerWithNavigation_B.y =
    (Quadcopter_ControllerWithNavigation_B.lambda *
     Quadcopter_ControllerWithNavigation_B.Filter -
     Quadcopter_ControllerWithNavigation_B.Gain_i *
     Quadcopter_ControllerWithNavigation_B.b) * -2.0;

  // If: '<S564>/If' incorporates:
  //   Constant: '<S565>/Constant'
  //   Constant: '<S566>/Constant'

  if (Quadcopter_ControllerWithNavigation_B.y > 1.0) {
    // Outputs for IfAction SubSystem: '<S564>/If Action Subsystem' incorporates:
    //   ActionPort: '<S565>/Action Port'

    Quadcopter_ControllerWithNavigation_B.y =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_be;

    // End of Outputs for SubSystem: '<S564>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S564>/If Action Subsystem' incorporates:
    //   ActionPort: '<S565>/Action Port'

    // Update for If: '<S564>/If' incorporates:
    //   Constant: '<S565>/Constant'

    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S564>/If Action Subsystem'
  } else if (Quadcopter_ControllerWithNavigation_B.y < -1.0) {
    // Outputs for IfAction SubSystem: '<S564>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S566>/Action Port'

    Quadcopter_ControllerWithNavigation_B.y =
      Quadcopter_ControllerWithNavigation_P.Constant_Value_m;

    // End of Outputs for SubSystem: '<S564>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S564>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S566>/Action Port'

    // Update for If: '<S564>/If' incorporates:
    //   Constant: '<S566>/Constant'

    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S564>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S564>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S567>/Action Port'

    // Update for If: '<S564>/If'
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S564>/If Action Subsystem2'
  }

  // End of If: '<S564>/If'

  // Trigonometry: '<S562>/trigFcn' incorporates:
  //   Concatenate: '<S562>/Vector Concatenate'

  if (Quadcopter_ControllerWithNavigation_B.y > 1.0) {
    Quadcopter_ControllerWithNavigation_B.y = 1.0;
  } else if (Quadcopter_ControllerWithNavigation_B.y < -1.0) {
    Quadcopter_ControllerWithNavigation_B.y = -1.0;
  }

  Quadcopter_ControllerWithNavigation_B.VectorConcatenate[1] = asin
    (Quadcopter_ControllerWithNavigation_B.y);

  // End of Trigonometry: '<S562>/trigFcn'

  // Trigonometry: '<S562>/Trigonometric Function3' incorporates:
  //   Concatenate: '<S562>/Vector Concatenate'
  //   Fcn: '<S56>/fcn4'
  //   Fcn: '<S56>/fcn5'

  Quadcopter_ControllerWithNavigation_B.VectorConcatenate[2] =
    Quadcopter_ControllerWithNavigation_rt_atan2d_snf
    ((Quadcopter_ControllerWithNavigation_B.b *
      Quadcopter_ControllerWithNavigation_B.Filter +
      Quadcopter_ControllerWithNavigation_B.Gain_i *
      Quadcopter_ControllerWithNavigation_B.lambda) * 2.0,
     ((Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k -
       Quadcopter_ControllerWithNavigation_B.Filter_o) -
      Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp) +
     Quadcopter_ControllerWithNavigation_B.VectorConcatenate_tmp_g);

  // MATLABSystem: '<S7>/SourceBlock'
  Quadcopter_ControllerWithNavigation_B.latp2 = uORB_read_step
    (Quadcopter_ControllerWithNavigation_DW.obj_d.orbMetadataObj,
     &Quadcopter_ControllerWithNavigation_DW.obj_d.eventStructObj,
     &Quadcopter_ControllerWithNavigation_B.b_varargout_2_f, false, 1.0);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  // Start for MATLABSystem: '<S7>/SourceBlock'
  if (Quadcopter_ControllerWithNavigation_B.latp2) {
    // SignalConversion generated from: '<S11>/In1'
    Quadcopter_ControllerWithNavigation_B.In1_b =
      Quadcopter_ControllerWithNavigation_B.b_varargout_2_f;
    srUpdateBC
      (Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_f);
  }

  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S52>/Position & Altitude controller' incorporates:
  //   EnablePort: '<S54>/Enable'

  if (Quadcopter_ControllerWithNavigation_B.In1_b.armed) {
    // Gain: '<S358>/Gain1'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_P.Gain1_Gain_o *
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[2];

    // Switch: '<S364>/Switch' incorporates:
    //   Constant: '<S358>/Constant'
    //   RelationalOperator: '<S364>/UpperRelop'
    //   Switch: '<S364>/Switch2'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i <
        Quadcopter_ControllerWithNavigation_P.Constant_Value_j4) {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_j4;
    }

    // Sum: '<S54>/Sum2' incorporates:
    //   Switch: '<S364>/Switch'
    //   Switch: '<S364>/Switch2'

    Quadcopter_ControllerWithNavigation_B.y =
      Quadcopter_ControllerWithNavigation_B.desiredZ -
      Quadcopter_ControllerWithNavigation_B.Gain_i;

    // Gain: '<S499>/Proportional Gain'
    Quadcopter_ControllerWithNavigation_B.Filter =
      Quadcopter_ControllerWithNavigation_P.PID_Altitude_P *
      Quadcopter_ControllerWithNavigation_B.y;

    // Gain: '<S497>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S489>/Filter'
    //   Gain: '<S488>/Derivative Gain'
    //   Sum: '<S489>/SumD'

    Quadcopter_ControllerWithNavigation_B.b =
      (Quadcopter_ControllerWithNavigation_P.PID_Altitude_D *
       Quadcopter_ControllerWithNavigation_B.y -
       Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE) *
      Quadcopter_ControllerWithNavigation_P.PID_Altitude_N;

    // Sum: '<S504>/Sum Fdbk'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_B.Filter +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE) +
      Quadcopter_ControllerWithNavigation_B.b;

    // DeadZone: '<S487>/DeadZone'
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

    // End of DeadZone: '<S487>/DeadZone'

    // Gain: '<S491>/Integral Gain'
    Quadcopter_ControllerWithNavigation_B.y *=
      Quadcopter_ControllerWithNavigation_P.PID_Altitude_I;

    // Switch: '<S485>/Switch1' incorporates:
    //   Constant: '<S485>/Clamping_zero'
    //   Constant: '<S485>/Constant'
    //   Constant: '<S485>/Constant2'
    //   RelationalOperator: '<S485>/fix for DT propagation issue'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_m) {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_hk;
    } else {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant2_Value_l;
    }

    // Switch: '<S485>/Switch2' incorporates:
    //   Constant: '<S485>/Clamping_zero'
    //   Constant: '<S485>/Constant3'
    //   Constant: '<S485>/Constant4'
    //   RelationalOperator: '<S485>/fix for DT propagation issue1'

    if (Quadcopter_ControllerWithNavigation_B.y >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_m) {
      Quadcopter_ControllerWithNavigation_B.i2_d =
        Quadcopter_ControllerWithNavigation_P.Constant3_Value_gn;
    } else {
      Quadcopter_ControllerWithNavigation_B.i2_d =
        Quadcopter_ControllerWithNavigation_P.Constant4_Value_g;
    }

    // Switch: '<S485>/Switch' incorporates:
    //   Constant: '<S485>/Clamping_zero'
    //   Constant: '<S485>/Constant1'
    //   Logic: '<S485>/AND3'
    //   RelationalOperator: '<S485>/Equal1'
    //   RelationalOperator: '<S485>/Relational Operator'
    //   Switch: '<S485>/Switch1'
    //   Switch: '<S485>/Switch2'

    if ((Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_m !=
         Quadcopter_ControllerWithNavigation_B.Gain_i) &&
        (Quadcopter_ControllerWithNavigation_B.rtPrevAction ==
         Quadcopter_ControllerWithNavigation_B.i2_d)) {
      Quadcopter_ControllerWithNavigation_B.y =
        Quadcopter_ControllerWithNavigation_P.Constant1_Value_f;
    }

    // DiscreteIntegrator: '<S494>/Integrator' incorporates:
    //   Switch: '<S485>/Switch'

    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE +=
      Quadcopter_ControllerWithNavigation_P.Integrator_gainval_a *
      Quadcopter_ControllerWithNavigation_B.y;

    // Sum: '<S503>/Sum'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_B.Filter +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE) +
      Quadcopter_ControllerWithNavigation_B.b;

    // Saturate: '<S501>/Saturation'
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

    // Sum: '<S54>/Sum3' incorporates:
    //   Saturate: '<S501>/Saturation'
    //   UnaryMinus: '<S54>/Unary Minus'

    Quadcopter_ControllerWithNavigation_B.Filter =
      Quadcopter_ControllerWithNavigation_B.Gain_i -
      (-Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[5]);

    // Gain: '<S549>/Proportional Gain'
    Quadcopter_ControllerWithNavigation_B.y =
      Quadcopter_ControllerWithNavigation_P.PID_vz_P *
      Quadcopter_ControllerWithNavigation_B.Filter;

    // Gain: '<S547>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S539>/Filter'
    //   Gain: '<S538>/Derivative Gain'
    //   Sum: '<S539>/SumD'

    Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k =
      (Quadcopter_ControllerWithNavigation_P.PID_vz_D *
       Quadcopter_ControllerWithNavigation_B.Filter -
       Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_m) *
      Quadcopter_ControllerWithNavigation_P.PID_vz_N;

    // Sum: '<S554>/Sum Fdbk'
    Quadcopter_ControllerWithNavigation_B.lambda =
      (Quadcopter_ControllerWithNavigation_B.y +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_c) +
      Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k;

    // DeadZone: '<S537>/DeadZone'
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

    // End of DeadZone: '<S537>/DeadZone'

    // Gain: '<S541>/Integral Gain'
    Quadcopter_ControllerWithNavigation_B.Filter *=
      Quadcopter_ControllerWithNavigation_P.PID_vz_I;

    // Switch: '<S535>/Switch1' incorporates:
    //   Constant: '<S535>/Clamping_zero'
    //   Constant: '<S535>/Constant'
    //   Constant: '<S535>/Constant2'
    //   RelationalOperator: '<S535>/fix for DT propagation issue'

    if (Quadcopter_ControllerWithNavigation_B.lambda >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_et) {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_mp;
    } else {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant2_Value_k;
    }

    // Switch: '<S535>/Switch2' incorporates:
    //   Constant: '<S535>/Clamping_zero'
    //   Constant: '<S535>/Constant3'
    //   Constant: '<S535>/Constant4'
    //   RelationalOperator: '<S535>/fix for DT propagation issue1'

    if (Quadcopter_ControllerWithNavigation_B.Filter >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_et) {
      Quadcopter_ControllerWithNavigation_B.i2_d =
        Quadcopter_ControllerWithNavigation_P.Constant3_Value_i;
    } else {
      Quadcopter_ControllerWithNavigation_B.i2_d =
        Quadcopter_ControllerWithNavigation_P.Constant4_Value_ja;
    }

    // Switch: '<S535>/Switch' incorporates:
    //   Constant: '<S535>/Clamping_zero'
    //   Constant: '<S535>/Constant1'
    //   Logic: '<S535>/AND3'
    //   RelationalOperator: '<S535>/Equal1'
    //   RelationalOperator: '<S535>/Relational Operator'
    //   Switch: '<S535>/Switch1'
    //   Switch: '<S535>/Switch2'

    if ((Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_et !=
         Quadcopter_ControllerWithNavigation_B.lambda) &&
        (Quadcopter_ControllerWithNavigation_B.rtPrevAction ==
         Quadcopter_ControllerWithNavigation_B.i2_d)) {
      Quadcopter_ControllerWithNavigation_B.Filter =
        Quadcopter_ControllerWithNavigation_P.Constant1_Value_o;
    }

    // DiscreteIntegrator: '<S544>/Integrator' incorporates:
    //   Switch: '<S535>/Switch'

    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_c +=
      Quadcopter_ControllerWithNavigation_P.Integrator_gainval_g *
      Quadcopter_ControllerWithNavigation_B.Filter;

    // Sum: '<S553>/Sum'
    Quadcopter_ControllerWithNavigation_B.Saturation =
      (Quadcopter_ControllerWithNavigation_B.y +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_c) +
      Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k;

    // Saturate: '<S551>/Saturation'
    if (Quadcopter_ControllerWithNavigation_B.Saturation >
        Quadcopter_ControllerWithNavigation_P.PID_vz_UpperSaturationLimit) {
      // Sum: '<S553>/Sum' incorporates:
      //   Saturate: '<S551>/Saturation'

      Quadcopter_ControllerWithNavigation_B.Saturation =
        Quadcopter_ControllerWithNavigation_P.PID_vz_UpperSaturationLimit;
    } else if (Quadcopter_ControllerWithNavigation_B.Saturation <
               Quadcopter_ControllerWithNavigation_P.PID_vz_LowerSaturationLimit)
    {
      // Sum: '<S553>/Sum' incorporates:
      //   Saturate: '<S551>/Saturation'

      Quadcopter_ControllerWithNavigation_B.Saturation =
        Quadcopter_ControllerWithNavigation_P.PID_vz_LowerSaturationLimit;
    }

    // End of Saturate: '<S551>/Saturation'

    // Trigonometry: '<S359>/SinCos'
    Quadcopter_ControllerWithNavigation_B.y = sin
      (Quadcopter_ControllerWithNavigation_B.VectorConcatenate[0]);
    Quadcopter_ControllerWithNavigation_B.Filter = cos
      (Quadcopter_ControllerWithNavigation_B.VectorConcatenate[0]);

    // Saturate: '<S451>/Saturation' incorporates:
    //   Gain: '<S449>/Proportional Gain'
    //   Sum: '<S54>/Sum1'

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

    // Sum: '<S54>/Sum' incorporates:
    //   Saturate: '<S451>/Saturation'
    //   Sum: '<S54>/Sum1'

    Quadcopter_ControllerWithNavigation_B.lambda =
      Quadcopter_ControllerWithNavigation_B.Gain_i -
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[3];

    // Saturate: '<S451>/Saturation' incorporates:
    //   Gain: '<S449>/Proportional Gain'
    //   Sum: '<S54>/Sum1'

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

    // Sum: '<S54>/Sum' incorporates:
    //   Saturate: '<S451>/Saturation'
    //   Sum: '<S54>/Sum1'

    Quadcopter_ControllerWithNavigation_B.Filter_o =
      Quadcopter_ControllerWithNavigation_B.Gain_i -
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion1[4];

    // Saturate: '<S403>/Saturation' incorporates:
    //   Gain: '<S359>/Gain'
    //   Gain: '<S401>/Proportional Gain'
    //   Product: '<S54>/MatrixMultiply'
    //   Reshape: '<S359>/Reshape'
    //   Reshape: '<S359>/Reshape1'

    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_B.Filter *
       Quadcopter_ControllerWithNavigation_B.lambda +
       Quadcopter_ControllerWithNavigation_B.y *
       Quadcopter_ControllerWithNavigation_B.Filter_o) *
      Quadcopter_ControllerWithNavigation_P.PIDController_P_n;
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit_i)
    {
      // Saturate: '<S403>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[0] =
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit_i;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
               Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit_f)
    {
      // Saturate: '<S403>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[0] =
        Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit_f;
    } else {
      // Saturate: '<S403>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[0] =
        Quadcopter_ControllerWithNavigation_B.Gain_i;
    }

    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_P.Gain_Gain_l2 *
       Quadcopter_ControllerWithNavigation_B.y *
       Quadcopter_ControllerWithNavigation_B.lambda +
       Quadcopter_ControllerWithNavigation_B.Filter *
       Quadcopter_ControllerWithNavigation_B.Filter_o) *
      Quadcopter_ControllerWithNavigation_P.PIDController_P_n;
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit_i)
    {
      // Saturate: '<S403>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[1] =
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit_i;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
               Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit_f)
    {
      // Saturate: '<S403>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[1] =
        Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit_f;
    } else {
      // Saturate: '<S403>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_n[1] =
        Quadcopter_ControllerWithNavigation_B.Gain_i;
    }

    // End of Saturate: '<S403>/Saturation'

    // Gain: '<S54>/Gain1'
    Quadcopter_ControllerWithNavigation_B.Gain1 =
      Quadcopter_ControllerWithNavigation_P.Gain1_Gain_f *
      Quadcopter_ControllerWithNavigation_B.Saturation_n[0];

    // Update for DiscreteIntegrator: '<S489>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE +=
      Quadcopter_ControllerWithNavigation_P.Filter_gainval_g *
      Quadcopter_ControllerWithNavigation_B.b;

    // Update for DiscreteIntegrator: '<S539>/Filter'
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

  // Outputs for Enabled SubSystem: '<S52>/Attitude controller' incorporates:
  //   EnablePort: '<S53>/Enable'

  if (Quadcopter_ControllerWithNavigation_B.In1_b.armed) {
    // Sum: '<S53>/Sum5'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_B.Merge[3] -
      Quadcopter_ControllerWithNavigation_B.VectorConcatenate[0];

    // Switch: '<S57>/Switch' incorporates:
    //   Abs: '<S57>/Abs'

    if (fabs(Quadcopter_ControllerWithNavigation_B.Gain_i) >
        Quadcopter_ControllerWithNavigation_P.Switch_Threshold_e) {
      // Switch: '<S57>/Switch1' incorporates:
      //   Constant: '<S57>/Constant'
      //   Sum: '<S57>/Add'
      //   Sum: '<S57>/Subtract'

      if (Quadcopter_ControllerWithNavigation_B.Gain_i >
          Quadcopter_ControllerWithNavigation_P.Switch1_Threshold) {
        Quadcopter_ControllerWithNavigation_B.Gain_i -=
          Quadcopter_ControllerWithNavigation_P.Constant_Value_p;
      } else {
        Quadcopter_ControllerWithNavigation_B.Gain_i +=
          Quadcopter_ControllerWithNavigation_P.Constant_Value_p;
      }

      // End of Switch: '<S57>/Switch1'
    }

    // Gain: '<S346>/Proportional Gain' incorporates:
    //   Switch: '<S57>/Switch'

    Quadcopter_ControllerWithNavigation_B.Gain_i *=
      Quadcopter_ControllerWithNavigation_P.PIDController5_P;

    // Saturate: '<S348>/Saturation'
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

    // Sum: '<S53>/Sum4' incorporates:
    //   Saturate: '<S348>/Saturation'

    Quadcopter_ControllerWithNavigation_B.y =
      Quadcopter_ControllerWithNavigation_B.Gain_i -
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[2];

    // Gain: '<S100>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S92>/Filter'
    //   Gain: '<S91>/Derivative Gain'
    //   Sum: '<S92>/SumD'

    Quadcopter_ControllerWithNavigation_B.lambda =
      (Quadcopter_ControllerWithNavigation_P.PIDController_D *
       Quadcopter_ControllerWithNavigation_B.y -
       Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_f) *
      Quadcopter_ControllerWithNavigation_P.PIDController_N;

    // Sum: '<S106>/Sum' incorporates:
    //   DiscreteIntegrator: '<S97>/Integrator'
    //   Gain: '<S102>/Proportional Gain'

    Quadcopter_ControllerWithNavigation_B.Gain_i =
      (Quadcopter_ControllerWithNavigation_P.PIDController_P *
       Quadcopter_ControllerWithNavigation_B.y +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_h) +
      Quadcopter_ControllerWithNavigation_B.lambda;

    // Saturate: '<S104>/Saturation' incorporates:
    //   DeadZone: '<S90>/DeadZone'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit)
    {
      // Saturate: '<S104>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_h =
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit;
      Quadcopter_ControllerWithNavigation_B.Gain_i -=
        Quadcopter_ControllerWithNavigation_P.PIDController_UpperSaturationLimit;
    } else {
      if (Quadcopter_ControllerWithNavigation_B.Gain_i <
          Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit)
      {
        // Saturate: '<S104>/Saturation'
        Quadcopter_ControllerWithNavigation_B.Saturation_h =
          Quadcopter_ControllerWithNavigation_P.PIDController_LowerSaturationLimit;
      } else {
        // Saturate: '<S104>/Saturation'
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

    // End of Saturate: '<S104>/Saturation'

    // Gain: '<S94>/Integral Gain'
    Quadcopter_ControllerWithNavigation_B.y *=
      Quadcopter_ControllerWithNavigation_P.PIDController_I;

    // Switch: '<S88>/Switch1' incorporates:
    //   Constant: '<S88>/Clamping_zero'
    //   Constant: '<S88>/Constant'
    //   Constant: '<S88>/Constant2'
    //   RelationalOperator: '<S88>/fix for DT propagation issue'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value) {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_k;
    } else {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant2_Value_e;
    }

    // Switch: '<S88>/Switch2' incorporates:
    //   Constant: '<S88>/Clamping_zero'
    //   Constant: '<S88>/Constant3'
    //   Constant: '<S88>/Constant4'
    //   RelationalOperator: '<S88>/fix for DT propagation issue1'

    if (Quadcopter_ControllerWithNavigation_B.y >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value) {
      Quadcopter_ControllerWithNavigation_B.i2_d =
        Quadcopter_ControllerWithNavigation_P.Constant3_Value_g;
    } else {
      Quadcopter_ControllerWithNavigation_B.i2_d =
        Quadcopter_ControllerWithNavigation_P.Constant4_Value_j;
    }

    // Switch: '<S88>/Switch' incorporates:
    //   Constant: '<S88>/Clamping_zero'
    //   Constant: '<S88>/Constant1'
    //   Logic: '<S88>/AND3'
    //   RelationalOperator: '<S88>/Equal1'
    //   RelationalOperator: '<S88>/Relational Operator'
    //   Switch: '<S88>/Switch1'
    //   Switch: '<S88>/Switch2'

    if ((Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value !=
         Quadcopter_ControllerWithNavigation_B.Gain_i) &&
        (Quadcopter_ControllerWithNavigation_B.rtPrevAction ==
         Quadcopter_ControllerWithNavigation_B.i2_d)) {
      Quadcopter_ControllerWithNavigation_B.Filter =
        Quadcopter_ControllerWithNavigation_P.Constant1_Value;
    } else {
      Quadcopter_ControllerWithNavigation_B.Filter =
        Quadcopter_ControllerWithNavigation_B.y;
    }

    // End of Switch: '<S88>/Switch'

    // RateLimiter: '<S53>/Rate Limiter2'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_B.Gain1 -
      Quadcopter_ControllerWithNavigation_DW.PrevY;
    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.RateLimiter2_RisingLim *
        Quadcopter_ControllerWithNavigation_period) {
      Quadcopter_ControllerWithNavigation_B.y =
        Quadcopter_ControllerWithNavigation_P.RateLimiter2_RisingLim *
        Quadcopter_ControllerWithNavigation_period +
        Quadcopter_ControllerWithNavigation_DW.PrevY;
    } else if (Quadcopter_ControllerWithNavigation_B.Gain_i <
               Quadcopter_ControllerWithNavigation_P.RateLimiter2_FallingLim *
               Quadcopter_ControllerWithNavigation_period) {
      Quadcopter_ControllerWithNavigation_B.y =
        Quadcopter_ControllerWithNavigation_P.RateLimiter2_FallingLim *
        Quadcopter_ControllerWithNavigation_period +
        Quadcopter_ControllerWithNavigation_DW.PrevY;
    } else {
      Quadcopter_ControllerWithNavigation_B.y =
        Quadcopter_ControllerWithNavigation_B.Gain1;
    }

    Quadcopter_ControllerWithNavigation_DW.PrevY =
      Quadcopter_ControllerWithNavigation_B.y;

    // End of RateLimiter: '<S53>/Rate Limiter2'

    // Saturate: '<S53>/Saturation1'
    if (Quadcopter_ControllerWithNavigation_B.y >
        Quadcopter_ControllerWithNavigation_P.Saturation1_UpperSat) {
      Quadcopter_ControllerWithNavigation_B.y =
        Quadcopter_ControllerWithNavigation_P.Saturation1_UpperSat;
    } else if (Quadcopter_ControllerWithNavigation_B.y <
               Quadcopter_ControllerWithNavigation_P.Saturation1_LowerSat) {
      Quadcopter_ControllerWithNavigation_B.y =
        Quadcopter_ControllerWithNavigation_P.Saturation1_LowerSat;
    }

    // Sum: '<S53>/Sum' incorporates:
    //   Gain: '<S250>/Proportional Gain'
    //   Saturate: '<S53>/Saturation1'
    //   Sum: '<S53>/Sum2'

    Quadcopter_ControllerWithNavigation_B.y =
      (Quadcopter_ControllerWithNavigation_B.y -
       Quadcopter_ControllerWithNavigation_B.VectorConcatenate[1]) *
      Quadcopter_ControllerWithNavigation_P.PIDController3_P -
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[1];

    // Gain: '<S144>/Integral Gain'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_P.PIDController1_I *
      Quadcopter_ControllerWithNavigation_B.y;

    // Gain: '<S150>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S142>/Filter'
    //   Gain: '<S141>/Derivative Gain'
    //   Sum: '<S142>/SumD'

    Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k =
      (Quadcopter_ControllerWithNavigation_P.PIDController1_D *
       Quadcopter_ControllerWithNavigation_B.y -
       Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_n) *
      Quadcopter_ControllerWithNavigation_P.PIDController1_N;

    // Sum: '<S156>/Sum' incorporates:
    //   DiscreteIntegrator: '<S147>/Integrator'
    //   Gain: '<S152>/Proportional Gain'

    Quadcopter_ControllerWithNavigation_B.b =
      (Quadcopter_ControllerWithNavigation_P.PIDController1_P *
       Quadcopter_ControllerWithNavigation_B.y +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_o) +
      Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k;

    // DeadZone: '<S140>/DeadZone'
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

    // End of DeadZone: '<S140>/DeadZone'

    // Switch: '<S138>/Switch1' incorporates:
    //   Constant: '<S138>/Clamping_zero'
    //   Constant: '<S138>/Constant'
    //   Constant: '<S138>/Constant2'
    //   RelationalOperator: '<S138>/fix for DT propagation issue'

    if (Quadcopter_ControllerWithNavigation_B.Filter_o >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_e) {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_h;
    } else {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant2_Value_f;
    }

    // Switch: '<S138>/Switch2' incorporates:
    //   Constant: '<S138>/Clamping_zero'
    //   Constant: '<S138>/Constant3'
    //   Constant: '<S138>/Constant4'
    //   RelationalOperator: '<S138>/fix for DT propagation issue1'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_e) {
      Quadcopter_ControllerWithNavigation_B.i2_d =
        Quadcopter_ControllerWithNavigation_P.Constant3_Value_c;
    } else {
      Quadcopter_ControllerWithNavigation_B.i2_d =
        Quadcopter_ControllerWithNavigation_P.Constant4_Value_e;
    }

    // Switch: '<S138>/Switch' incorporates:
    //   Constant: '<S138>/Clamping_zero'
    //   Constant: '<S138>/Constant1'
    //   Logic: '<S138>/AND3'
    //   RelationalOperator: '<S138>/Equal1'
    //   RelationalOperator: '<S138>/Relational Operator'
    //   Switch: '<S138>/Switch1'
    //   Switch: '<S138>/Switch2'

    if ((Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_e !=
         Quadcopter_ControllerWithNavigation_B.Filter_o) &&
        (Quadcopter_ControllerWithNavigation_B.rtPrevAction ==
         Quadcopter_ControllerWithNavigation_B.i2_d)) {
      Quadcopter_ControllerWithNavigation_B.y =
        Quadcopter_ControllerWithNavigation_P.Constant1_Value_e;
    } else {
      Quadcopter_ControllerWithNavigation_B.y =
        Quadcopter_ControllerWithNavigation_B.Gain_i;
    }

    // End of Switch: '<S138>/Switch'

    // Saturate: '<S154>/Saturation'
    if (Quadcopter_ControllerWithNavigation_B.b >
        Quadcopter_ControllerWithNavigation_P.PIDController1_UpperSaturationLimit)
    {
      // Saturate: '<S154>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_c =
        Quadcopter_ControllerWithNavigation_P.PIDController1_UpperSaturationLimit;
    } else if (Quadcopter_ControllerWithNavigation_B.b <
               Quadcopter_ControllerWithNavigation_P.PIDController1_LowerSaturationLimit)
    {
      // Saturate: '<S154>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_c =
        Quadcopter_ControllerWithNavigation_P.PIDController1_LowerSaturationLimit;
    } else {
      // Saturate: '<S154>/Saturation'
      Quadcopter_ControllerWithNavigation_B.Saturation_c =
        Quadcopter_ControllerWithNavigation_B.b;
    }

    // End of Saturate: '<S154>/Saturation'

    // RateLimiter: '<S53>/Rate Limiter1'
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

    // End of RateLimiter: '<S53>/Rate Limiter1'

    // Saturate: '<S53>/Saturation'
    if (Quadcopter_ControllerWithNavigation_B.Filter_o >
        Quadcopter_ControllerWithNavigation_P.Saturation_UpperSat) {
      Quadcopter_ControllerWithNavigation_B.Filter_o =
        Quadcopter_ControllerWithNavigation_P.Saturation_UpperSat;
    } else if (Quadcopter_ControllerWithNavigation_B.Filter_o <
               Quadcopter_ControllerWithNavigation_P.Saturation_LowerSat) {
      Quadcopter_ControllerWithNavigation_B.Filter_o =
        Quadcopter_ControllerWithNavigation_P.Saturation_LowerSat;
    }

    // Sum: '<S53>/Sum1' incorporates:
    //   Gain: '<S298>/Proportional Gain'
    //   Saturate: '<S53>/Saturation'
    //   Sum: '<S53>/Sum3'

    Quadcopter_ControllerWithNavigation_B.Filter_o =
      (Quadcopter_ControllerWithNavigation_B.Filter_o -
       Quadcopter_ControllerWithNavigation_B.VectorConcatenate[2]) *
      Quadcopter_ControllerWithNavigation_P.PIDController4_P -
      Quadcopter_ControllerWithNavigation_B.DataTypeConversion2[0];

    // Gain: '<S194>/Integral Gain'
    Quadcopter_ControllerWithNavigation_B.Gain_i =
      Quadcopter_ControllerWithNavigation_P.PIDController2_I *
      Quadcopter_ControllerWithNavigation_B.Filter_o;

    // Gain: '<S200>/Filter Coefficient' incorporates:
    //   DiscreteIntegrator: '<S192>/Filter'
    //   Gain: '<S191>/Derivative Gain'
    //   Sum: '<S192>/SumD'

    Quadcopter_ControllerWithNavigation_B.b =
      (Quadcopter_ControllerWithNavigation_P.PIDController2_D *
       Quadcopter_ControllerWithNavigation_B.Filter_o -
       Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_k) *
      Quadcopter_ControllerWithNavigation_P.PIDController2_N;

    // Sum: '<S206>/Sum' incorporates:
    //   DiscreteIntegrator: '<S197>/Integrator'
    //   Gain: '<S202>/Proportional Gain'

    Quadcopter_ControllerWithNavigation_B.Saturation_d =
      (Quadcopter_ControllerWithNavigation_P.PIDController2_P *
       Quadcopter_ControllerWithNavigation_B.Filter_o +
       Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_i) +
      Quadcopter_ControllerWithNavigation_B.b;

    // DeadZone: '<S190>/DeadZone' incorporates:
    //   Saturate: '<S204>/Saturation'

    if (Quadcopter_ControllerWithNavigation_B.Saturation_d >
        Quadcopter_ControllerWithNavigation_P.PIDController2_UpperSaturationLimit)
    {
      Quadcopter_ControllerWithNavigation_B.Filter_o =
        Quadcopter_ControllerWithNavigation_B.Saturation_d -
        Quadcopter_ControllerWithNavigation_P.PIDController2_UpperSaturationLimit;

      // Sum: '<S206>/Sum' incorporates:
      //   Saturate: '<S204>/Saturation'

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
        // Sum: '<S206>/Sum' incorporates:
        //   Saturate: '<S204>/Saturation'

        Quadcopter_ControllerWithNavigation_B.Saturation_d =
          Quadcopter_ControllerWithNavigation_P.PIDController2_LowerSaturationLimit;
      }
    }

    // End of DeadZone: '<S190>/DeadZone'

    // Update for DiscreteIntegrator: '<S97>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_h +=
      Quadcopter_ControllerWithNavigation_P.Integrator_gainval *
      Quadcopter_ControllerWithNavigation_B.Filter;

    // Update for DiscreteIntegrator: '<S92>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_f +=
      Quadcopter_ControllerWithNavigation_P.Filter_gainval *
      Quadcopter_ControllerWithNavigation_B.lambda;

    // Update for DiscreteIntegrator: '<S147>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_o +=
      Quadcopter_ControllerWithNavigation_P.Integrator_gainval_k *
      Quadcopter_ControllerWithNavigation_B.y;

    // Update for DiscreteIntegrator: '<S142>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_n +=
      Quadcopter_ControllerWithNavigation_P.Filter_gainval_p *
      Quadcopter_ControllerWithNavigation_B.FilterCoefficient_k;

    // Switch: '<S188>/Switch1' incorporates:
    //   Constant: '<S188>/Clamping_zero'
    //   Constant: '<S188>/Constant'
    //   Constant: '<S188>/Constant2'
    //   RelationalOperator: '<S188>/fix for DT propagation issue'

    if (Quadcopter_ControllerWithNavigation_B.Filter_o >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_p) {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant_Value_is;
    } else {
      Quadcopter_ControllerWithNavigation_B.rtPrevAction =
        Quadcopter_ControllerWithNavigation_P.Constant2_Value_a;
    }

    // Switch: '<S188>/Switch2' incorporates:
    //   Constant: '<S188>/Clamping_zero'
    //   Constant: '<S188>/Constant3'
    //   Constant: '<S188>/Constant4'
    //   RelationalOperator: '<S188>/fix for DT propagation issue1'

    if (Quadcopter_ControllerWithNavigation_B.Gain_i >
        Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_p) {
      Quadcopter_ControllerWithNavigation_B.i2_d =
        Quadcopter_ControllerWithNavigation_P.Constant3_Value_b;
    } else {
      Quadcopter_ControllerWithNavigation_B.i2_d =
        Quadcopter_ControllerWithNavigation_P.Constant4_Value_k;
    }

    // Switch: '<S188>/Switch' incorporates:
    //   Constant: '<S188>/Clamping_zero'
    //   Constant: '<S188>/Constant1'
    //   Logic: '<S188>/AND3'
    //   RelationalOperator: '<S188>/Equal1'
    //   RelationalOperator: '<S188>/Relational Operator'
    //   Switch: '<S188>/Switch1'
    //   Switch: '<S188>/Switch2'

    if ((Quadcopter_ControllerWithNavigation_P.Clamping_zero_Value_p !=
         Quadcopter_ControllerWithNavigation_B.Filter_o) &&
        (Quadcopter_ControllerWithNavigation_B.rtPrevAction ==
         Quadcopter_ControllerWithNavigation_B.i2_d)) {
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_P.Constant1_Value_a;
    }

    // Update for DiscreteIntegrator: '<S197>/Integrator' incorporates:
    //   Switch: '<S188>/Switch'

    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_i +=
      Quadcopter_ControllerWithNavigation_P.Integrator_gainval_i *
      Quadcopter_ControllerWithNavigation_B.Gain_i;

    // Update for DiscreteIntegrator: '<S192>/Filter'
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
      Quadcopter_ControllerWithNavigation_B.Saturation_m[Quadcopter_ControllerWithNavigation_B.j]
        = Quadcopter_ControllerWithNavigation_P.Saturation_UpperSat_g;
    } else if (Quadcopter_ControllerWithNavigation_B.status <
               Quadcopter_ControllerWithNavigation_P.Saturation_LowerSat_j) {
      Quadcopter_ControllerWithNavigation_B.Saturation_m[Quadcopter_ControllerWithNavigation_B.j]
        = Quadcopter_ControllerWithNavigation_P.Saturation_LowerSat_j;
    } else {
      Quadcopter_ControllerWithNavigation_B.Saturation_m[Quadcopter_ControllerWithNavigation_B.j]
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
    Quadcopter_ControllerWithNavigation_B.Saturation_m[0];
  Quadcopter_ControllerWithNavigation_B.pwmValue[1] =
    Quadcopter_ControllerWithNavigation_B.Saturation_m[1];
  Quadcopter_ControllerWithNavigation_B.pwmValue[2] =
    Quadcopter_ControllerWithNavigation_B.Saturation_m[2];
  Quadcopter_ControllerWithNavigation_B.pwmValue[3] =
    Quadcopter_ControllerWithNavigation_B.Saturation_m[3];
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
  if (Quadcopter_ControllerWithNavigation_B.ParamStep_n > 0) {
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
      Quadcopter_ControllerWithNavigation_B.y =
        Quadcopter_ControllerWithNavigation_B.In1_p.next.lat -
        Quadcopter_ControllerWithNavigation_B.In1_f.lat;
      Quadcopter_ControllerWithNavigation_B.Gain_i =
        Quadcopter_ControllerWithNavigation_B.In1_p.next.lon -
        Quadcopter_ControllerWithNavigation_B.In1_f.lon;
      Quadcopter_ControllerWithNavigation_B.lambda = fabs
        (Quadcopter_ControllerWithNavigation_B.y);
      if (Quadcopter_ControllerWithNavigation_B.lambda > 180.0) {
        if (rtIsNaN(Quadcopter_ControllerWithNavigation_B.y + 180.0) || rtIsInf
            (Quadcopter_ControllerWithNavigation_B.y + 180.0)) {
          Quadcopter_ControllerWithNavigation_B.Filter = (rtNaN);
        } else if (Quadcopter_ControllerWithNavigation_B.y + 180.0 == 0.0) {
          Quadcopter_ControllerWithNavigation_B.Filter = 0.0;
        } else {
          Quadcopter_ControllerWithNavigation_B.Filter = fmod
            (Quadcopter_ControllerWithNavigation_B.y + 180.0, 360.0);
          if (Quadcopter_ControllerWithNavigation_B.Filter == 0.0) {
            Quadcopter_ControllerWithNavigation_B.Filter = 0.0;
          } else if (Quadcopter_ControllerWithNavigation_B.y + 180.0 < 0.0) {
            Quadcopter_ControllerWithNavigation_B.Filter += 360.0;
          }
        }

        Quadcopter_ControllerWithNavigation_B.y =
          Quadcopter_ControllerWithNavigation_B.y * 0.0 +
          (Quadcopter_ControllerWithNavigation_B.Filter - 180.0);
        Quadcopter_ControllerWithNavigation_B.lambda = fabs
          (Quadcopter_ControllerWithNavigation_B.y);
      }

      if (Quadcopter_ControllerWithNavigation_B.lambda > 90.0) {
        Quadcopter_ControllerWithNavigation_B.lambda = fabs
          (Quadcopter_ControllerWithNavigation_B.y);
        Quadcopter_ControllerWithNavigation_B.latp2 =
          (Quadcopter_ControllerWithNavigation_B.lambda > 90.0);
        Quadcopter_ControllerWithNavigation_B.Gain_i += 180.0;
        Quadcopter_ControllerWithNavigation_B.b =
          Quadcopter_ControllerWithNavigation_B.y * static_cast<real_T>
          (Quadcopter_ControllerWithNavigation_B.latp2);
        if (rtIsNaN(Quadcopter_ControllerWithNavigation_B.b)) {
          Quadcopter_ControllerWithNavigation_B.b = (rtNaN);
        } else if (Quadcopter_ControllerWithNavigation_B.b < 0.0) {
          Quadcopter_ControllerWithNavigation_B.b = -1.0;
        } else {
          Quadcopter_ControllerWithNavigation_B.b =
            (Quadcopter_ControllerWithNavigation_B.b > 0.0);
        }

        Quadcopter_ControllerWithNavigation_B.y = (90.0 -
          (Quadcopter_ControllerWithNavigation_B.lambda * static_cast<real_T>
           (Quadcopter_ControllerWithNavigation_B.latp2) - 90.0)) *
          Quadcopter_ControllerWithNavigation_B.b * static_cast<real_T>
          (Quadcopter_ControllerWithNavigation_B.latp2) +
          Quadcopter_ControllerWithNavigation_B.y * static_cast<real_T>
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

      Quadcopter_ControllerWithNavigation_B.y /=
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
        (Quadcopter_ControllerWithNavigation_B.y);
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
         Quadcopter_ControllerWithNavigation_B.y);
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

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  Quadcopter_ControllerWithNavigation_M->Timing.taskTime0 =
    ((time_T)(++Quadcopter_ControllerWithNavigation_M->Timing.clockTick0)) *
    Quadcopter_ControllerWithNavigation_M->Timing.stepSize0;
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
  Quadcopter_ControllerWithNavigation_P.Constant2_Value[0] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant2_Value[1] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant2_Value[2] = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant3_Value = rtNaNF;
  Quadcopter_ControllerWithNavigation_P.Constant4_Value = rtNaNF;
  rtmSetTFinal(Quadcopter_ControllerWithNavigation_M, -1);
  Quadcopter_ControllerWithNavigation_M->Timing.stepSize0 = 0.01;

  // External mode info
  Quadcopter_ControllerWithNavigation_M->Sizes.checksums[0] = (228586759U);
  Quadcopter_ControllerWithNavigation_M->Sizes.checksums[1] = (2201831582U);
  Quadcopter_ControllerWithNavigation_M->Sizes.checksums[2] = (750313944U);
  Quadcopter_ControllerWithNavigation_M->Sizes.checksums[3] = (4049990418U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[72];
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
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC_e;
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
      &Quadcopter_ControllerWithNavigation_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.Attitudecontroller_SubsysRanBC;
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
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[59] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[60] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[61] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[62] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[63] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[64] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[65] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[66] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[67] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.PositionAltitudecontroller_SubsysRanBC;
    systemRan[68] = &rtAlwaysEnabled;
    systemRan[69] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[70] = (sysRanDType *)
      &Quadcopter_ControllerWithNavigation_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[71] = (sysRanDType *)
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
    static const char_T ParameterNameStr[15] = "MPC_LAND_SPEED";
    static const char_T ParameterNameStr_0[14] = "MPC_TKO_SPEED";
    static const char_T ParameterNameStr_1[14] = "COM_OBS_AVOID";
    real_T tmp;

    // Start for If: '<S16>/If'
    Quadcopter_ControllerWithNavigation_DW.If_ActiveSubsystem = -1;

    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
    //   Outport: '<S13>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_c =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S38>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S39>/In1' incorporates:
    //   Outport: '<S39>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1 =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S38>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S36>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S51>/In1' incorporates:
    //   Outport: '<S51>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_p =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S36>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S50>/In1' incorporates:
    //   Outport: '<S50>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_f =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem'

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

    // SystemInitialize for Enabled SubSystem: '<S25>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S27>/yaw_In' incorporates:
    //   Outport: '<S27>/yaw_Out'

    Quadcopter_ControllerWithNavigation_B.yaw_In_i =
      Quadcopter_ControllerWithNavigation_P.yaw_Out_Y0_f;

    // End of SystemInitialize for SubSystem: '<S25>/Enabled Subsystem2'

    // SystemInitialize for Enabled SubSystem: '<S24>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S26>/In' incorporates:
    //   Outport: '<S26>/Out'

    Quadcopter_ControllerWithNavigation_B.In =
      Quadcopter_ControllerWithNavigation_P.Out_Y0;

    // End of SystemInitialize for SubSystem: '<S24>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S16>/Land'

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

    // SystemInitialize for IfAction SubSystem: '<S16>/IDLE'
    // InitializeConditions for Delay: '<S22>/Delay'
    Quadcopter_ControllerWithNavigation_DW.Delay_DSTATE =
      Quadcopter_ControllerWithNavigation_P.Delay_InitialCondition_g0;

    // SystemInitialize for Enabled SubSystem: '<S22>/Enabled Subsystem2'
    // SystemInitialize for SignalConversion generated from: '<S23>/yaw_In' incorporates:
    //   Outport: '<S23>/yaw_Out'

    Quadcopter_ControllerWithNavigation_B.yaw_In =
      Quadcopter_ControllerWithNavigation_P.yaw_Out_Y0_p;

    // End of SystemInitialize for SubSystem: '<S22>/Enabled Subsystem2'
    // End of SystemInitialize for SubSystem: '<S16>/IDLE'

    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S12>/In1' incorporates:
    //   Outport: '<S12>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_m =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S11>/In1' incorporates:
    //   Outport: '<S11>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_b =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S52>/Position & Altitude controller' 
    // InitializeConditions for DiscreteIntegrator: '<S489>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE =
      Quadcopter_ControllerWithNavigation_P.PID_Altitude_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S494>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE =
      Quadcopter_ControllerWithNavigation_P.PID_Altitude_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S539>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_m =
      Quadcopter_ControllerWithNavigation_P.PID_vz_InitialConditionForFilter;

    // InitializeConditions for DiscreteIntegrator: '<S544>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_c =
      Quadcopter_ControllerWithNavigation_P.PID_vz_InitialConditionForIntegrator;

    // SystemInitialize for Sum: '<S553>/Sum' incorporates:
    //   Outport: '<S54>/tau_Thrust'
    //   Saturate: '<S551>/Saturation'

    Quadcopter_ControllerWithNavigation_B.Saturation =
      Quadcopter_ControllerWithNavigation_P.tau_Thrust_Y0;

    // SystemInitialize for Gain: '<S54>/Gain1' incorporates:
    //   Outport: '<S54>/des_pitch'

    Quadcopter_ControllerWithNavigation_B.Gain1 =
      Quadcopter_ControllerWithNavigation_P.des_pitch_Y0;

    // SystemInitialize for Outport: '<S54>/des_roll' incorporates:
    //   Saturate: '<S403>/Saturation'

    Quadcopter_ControllerWithNavigation_B.Saturation_n[1] =
      Quadcopter_ControllerWithNavigation_P.des_roll_Y0;

    // End of SystemInitialize for SubSystem: '<S52>/Position & Altitude controller' 

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S10>/In1' incorporates:
    //   Outport: '<S10>/Out1'

    Quadcopter_ControllerWithNavigation_B.In1_l =
      Quadcopter_ControllerWithNavigation_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S52>/Attitude controller'
    // InitializeConditions for DiscreteIntegrator: '<S97>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_h =
      Quadcopter_ControllerWithNavigation_P.PIDController_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S92>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_f =
      Quadcopter_ControllerWithNavigation_P.PIDController_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S53>/Rate Limiter2'
    Quadcopter_ControllerWithNavigation_DW.PrevY =
      Quadcopter_ControllerWithNavigation_P.RateLimiter2_IC;

    // InitializeConditions for DiscreteIntegrator: '<S147>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_o =
      Quadcopter_ControllerWithNavigation_P.PIDController1_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S142>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_n =
      Quadcopter_ControllerWithNavigation_P.PIDController1_InitialConditionForFilter;

    // InitializeConditions for RateLimiter: '<S53>/Rate Limiter1'
    Quadcopter_ControllerWithNavigation_DW.PrevY_b =
      Quadcopter_ControllerWithNavigation_P.RateLimiter1_IC;

    // InitializeConditions for DiscreteIntegrator: '<S197>/Integrator'
    Quadcopter_ControllerWithNavigation_DW.Integrator_DSTATE_i =
      Quadcopter_ControllerWithNavigation_P.PIDController2_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S192>/Filter'
    Quadcopter_ControllerWithNavigation_DW.Filter_DSTATE_k =
      Quadcopter_ControllerWithNavigation_P.PIDController2_InitialConditionForFilter;

    // SystemInitialize for Saturate: '<S104>/Saturation' incorporates:
    //   Outport: '<S53>/tau_Yaw'

    Quadcopter_ControllerWithNavigation_B.Saturation_h =
      Quadcopter_ControllerWithNavigation_P.tau_Yaw_Y0;

    // SystemInitialize for Saturate: '<S154>/Saturation' incorporates:
    //   Outport: '<S53>/tau_Pitch'

    Quadcopter_ControllerWithNavigation_B.Saturation_c =
      Quadcopter_ControllerWithNavigation_P.tau_Pitch_Y0;

    // SystemInitialize for Sum: '<S206>/Sum' incorporates:
    //   Outport: '<S53>/tau_Roll'
    //   Saturate: '<S204>/Saturation'

    Quadcopter_ControllerWithNavigation_B.Saturation_d =
      Quadcopter_ControllerWithNavigation_P.tau_Roll_Y0;

    // End of SystemInitialize for SubSystem: '<S52>/Attitude controller'

    // SystemInitialize for Enabled SubSystem: '<S17>/Send waypoints to OBC'
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
      &ParameterNameStr[0], true, tmp * 1000.0);
    Quadcopter_ControllerWithNavigation_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S49>/Read Parameter'
    // End of SystemInitialize for SubSystem: '<S46>/If Action Subsystem2'

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
      &ParameterNameStr_1[0], true, tmp * 1000.0);
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

    // Start for MATLABSystem: '<S7>/SourceBlock'
    Quadcopter_ControllerWithNavigation_DW.obj_d.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_d.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_d.orbMetadataObj = ORB_ID
      (actuator_armed);
    uORB_read_initialize
      (Quadcopter_ControllerWithNavigation_DW.obj_d.orbMetadataObj,
       &Quadcopter_ControllerWithNavigation_DW.obj_d.eventStructObj);
    Quadcopter_ControllerWithNavigation_DW.obj_d.isSetupComplete = true;

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
    Quadcopter_ControllerWithNavigation_DW.obj_n.matlabCodegenIsDeleted = false;
    Quadcopter_ControllerWithNavigation_DW.obj_n.isInitialized = 1;
    Quadcopter_ControllerWithNavigation_DW.obj_n.isSetupComplete = true;
  }
}

// Model terminate function
void Quadcopter_ControllerWithNavigation_terminate(void)
{
  uint16_T status;

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
  if (!Quadcopter_ControllerWithNavigation_DW.obj_n.matlabCodegenIsDeleted) {
    Quadcopter_ControllerWithNavigation_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S33>/PX4 Timestamp'
}

//
// File trailer for generated code.
//
// [EOF]
//
