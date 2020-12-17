/*
 * pressure_regulator_step_response.h
 *
 * Code generation for model "pressure_regulator_step_response".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Dec 17 13:00:00 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pressure_regulator_step_response_h_
#define RTW_HEADER_pressure_regulator_step_response_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef pressure_regulator_step_response_COMMON_INCLUDES_
# define pressure_regulator_step_response_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                   /* pressure_regulator_step_response_COMMON_INCLUDES_ */

#include "pressure_regulator_step_response_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#define pressure_regulator_step_response_M (pressure_regulator_step_resp_M)

/* Block signals (default storage) */
typedef struct {
  real_T Constant;                     /* '<Root>/Constant' */
  real_T g;                            /* '<S2>/g' */
  real_T x2;                           /* '<S2>/Integrator' */
  real_T Divide;                       /* '<S2>/Divide' */
  real_T F_init;                       /* '<Root>/MATLAB Function1' */
  real_T D_w;                          /* '<Root>/MATLAB Function1' */
  real_T m_s;                          /* '<Root>/MATLAB Function1' */
} B_pressure_regulator_step_res_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int_T Integrator1_IWORK;             /* '<S2>/Integrator1' */
} DW_pressure_regulator_step_re_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S2>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S2>/Integrator' */
} X_pressure_regulator_step_res_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S2>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S2>/Integrator' */
} XDot_pressure_regulator_step__T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S2>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S2>/Integrator' */
} XDis_pressure_regulator_step__T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_pressure_regulator_step_res_T_ {
  real_T Constant_Value;               /* Expression: 0.005
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Step_Time;                    /* Expression: 0.1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 2
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Constant7_Value;              /* Expression: 1.08e6
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant5_Value;              /* Expression: 7.854e-7
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 0.25
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 0.0257
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant8_Value;              /* Expression: 1e6
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant2_Value;              /* Expression: 2.23e3
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 2.23e2
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T g_Gain;                       /* Expression: 9.8
                                        * Referenced by: '<S2>/g'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_pressure_regulator_st_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_pressure_regulator_step_res_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_pressure_regulator_step_res_T pressure_regulator_step_respo_P;

/* Block signals (default storage) */
extern B_pressure_regulator_step_res_T pressure_regulator_step_respo_B;

/* Continuous states (default storage) */
extern X_pressure_regulator_step_res_T pressure_regulator_step_respo_X;

/* Block states (default storage) */
extern DW_pressure_regulator_step_re_T pressure_regulator_step_resp_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T P_red;                   /* '<Root>/Output' */

/* Model entry point functions */
extern void pressure_regulator_step_response_initialize(void);
extern void pressure_regulator_step_response_step(void);
extern void pressure_regulator_step_response_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pressure_regulator_s_T *const pressure_regulator_step_resp_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'pressure_regulator_step_response'
 * '<S1>'   : 'pressure_regulator_step_response/MATLAB Function1'
 * '<S2>'   : 'pressure_regulator_step_response/regulator_dynamics'
 * '<S3>'   : 'pressure_regulator_step_response/regulator_dynamics/MATLAB Function1'
 */
#endif                      /* RTW_HEADER_pressure_regulator_step_response_h_ */
