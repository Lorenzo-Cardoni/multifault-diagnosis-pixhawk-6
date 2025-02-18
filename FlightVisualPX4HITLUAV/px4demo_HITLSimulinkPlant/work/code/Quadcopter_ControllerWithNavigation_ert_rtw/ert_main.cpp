//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
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
#include <stdio.h>
#include <stdlib.h>
#include "Quadcopter_ControllerWithNavigation.h"
#include "Quadcopter_ControllerWithNavigation_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "ext_mode.h"
#include "MW_PX4_TaskControl.h"
#include "nuttxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

// Function prototype declaration
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
extmodeErrorCode_T errorCode;
px4_sem_t stopSem;
px4_sem_t baserateTaskSem;
px4_sem_t subrateTaskSem[2];
int taskId[2];
pthread_t schedulerThread;
pthread_t baseRateThread;
pthread_t backgroundThread;
void *threadJoinStatus;
int terminatingmodel = 0;
pthread_t subRateThread[2];
int subratePriority[2];
extmodeSimulationTime_T getCurrentTaskTime(int tid)
{
  extmodeSimulationTime_T currentTime = 0;
  switch (tid) {
   case 1:
    currentTime = (extmodeSimulationTime_T)
      ((Quadcopter_ControllerWithNavigation_M->Timing.clockTick1) * 0.01);
    break;

   case 2:
    currentTime = (extmodeSimulationTime_T)
      ((Quadcopter_ControllerWithNavigation_M->Timing.clockTick2) * 0.015);
    break;
  }

  return currentTime;
}

void *subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 1;
  while (runModel) {
    px4_sem_wait(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    extmodeSimulationTime_T currentTime = getCurrentTaskTime(subRateId);
    Quadcopter_ControllerWithNavigation_step(subRateId);

    // Get model outputs here

    // Trigger External Mode event
    extmodeEvent(subRateId, currentTime);
  }

  pthread_exit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  int_T i;
  runModel = (rtmGetErrorStatus(Quadcopter_ControllerWithNavigation_M) == (NULL));
  while (runModel) {
    px4_sem_wait(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    for (i = 1
         ; i <= 2; i++) {
      if (rtmStepTask(Quadcopter_ControllerWithNavigation_M, i)
          ) {
        px4_sem_post(&subrateTaskSem[ i - 1
                     ]);
      }
    }

    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      Quadcopter_ControllerWithNavigation_M->Timing.taskTime0;
    Quadcopter_ControllerWithNavigation_step(0);

    // Get model outputs here

    // Trigger External Mode event
    extmodeEvent(0, currentTime);
    stopRequested = !((rtmGetErrorStatus(Quadcopter_ControllerWithNavigation_M) ==
                       (NULL)));
    runModel = !stopRequested && !extmodeSimulationComplete() &&
      !extmodeStopRequested();
  }

  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(Quadcopter_ControllerWithNavigation_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    // Signal all periodic tasks to complete
    for (i=0; i<2; i++) {
      CHECK_STATUS(px4_sem_post(&subrateTaskSem[i]), 0, "px4_sem_post");
      CHECK_STATUS(px4_sem_destroy(&subrateTaskSem[i]), 0, "px4_sem_destroy");
    }

    // Wait for all periodic tasks to complete
    for (i=0; i<2; i++) {
      CHECK_STATUS(pthread_join(subRateThread[i], &threadJoinStatus), 0,
                   "pthread_join");
    }

    runModel = 0;

    // Wait for background task to complete
    CHECK_STATUS(pthread_join(backgroundThread, &threadJoinStatus), 0,
                 "pthread_join");
  }

  MW_PX4_Terminate();

  // Terminate model
  Quadcopter_ControllerWithNavigation_terminate();
  extmodeReset();
  px4_sem_post(&stopSem);
  return NULL;
}

void *backgroundTask(void *arg)
{
  while (runModel) {
    // Run External Mode background activities
    errorCode = extmodeBackgroundRun();
    if (errorCode != EXTMODE_SUCCESS) {
      // Code to handle External Mode background task errors
      // may be added here
    }
  }

  pthread_exit((void *)0);
  return NULL;
}

int px4_simulink_app_task_main (int argc, char *argv[])
{
  subratePriority[0] = 249;
  subratePriority[1] = 248;
  px4_simulink_app_control_MAVLink();
  rtmSetErrorStatus(Quadcopter_ControllerWithNavigation_M, 0);

  // Parse External Mode command line arguments
  errorCode = extmodeParseArgs(argc, (const char_T **)argv);
  if (errorCode != EXTMODE_SUCCESS) {
    return (errorCode);
  }

  // Initialize model
  Quadcopter_ControllerWithNavigation_initialize();

  // External Mode initialization
  errorCode = extmodeInit(Quadcopter_ControllerWithNavigation_M->extModeInfo,
    &rtmGetTFinal(Quadcopter_ControllerWithNavigation_M));
  if (errorCode != EXTMODE_SUCCESS) {
    // Code to handle External Mode initialization errors
    // may be added here
  }

  if (errorCode == EXTMODE_SUCCESS) {
    // Wait until a Start or Stop Request has been received from the Host
    extmodeWaitForHostRequest(EXTMODE_WAIT_FOREVER);
    if (extmodeStopRequested()) {
      rtmSetStopRequested(Quadcopter_ControllerWithNavigation_M, true);
    }
  }

  // Call RTOS Initialization function
  nuttxRTOSInit(0.005, 2);

  // Wait for stop semaphore
  px4_sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(px4_sem_destroy(&timerTaskSem[i]), 0, "px4_sem_destroy");
    }
  }

#endif

  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
