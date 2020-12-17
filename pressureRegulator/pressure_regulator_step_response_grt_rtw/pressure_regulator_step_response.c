/*
 * pressure_regulator_step_response.c
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

#include "pressure_regulator_step_response.h"
#include "pressure_regulator_step_response_private.h"

/* Exported block signals */
real_T P_red;                          /* '<Root>/Output' */

/* Block signals (default storage) */
B_pressure_regulator_step_res_T pressure_regulator_step_respo_B;

/* Continuous states */
X_pressure_regulator_step_res_T pressure_regulator_step_respo_X;

/* Block states (default storage) */
DW_pressure_regulator_step_re_T pressure_regulator_step_resp_DW;

/* Real-time model */
RT_MODEL_pressure_regulator_s_T pressure_regulator_step_resp_M_;
RT_MODEL_pressure_regulator_s_T *const pressure_regulator_step_resp_M =
  &pressure_regulator_step_resp_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  pressure_regulator_step_response_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  pressure_regulator_step_response_step();
  pressure_regulator_step_response_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  pressure_regulator_step_response_step();
  pressure_regulator_step_response_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
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

/* Model step function */
void pressure_regulator_step_response_step(void)
{
  real_T A_o1;
  real_T gamma_1;
  real_T tmp;
  if (rtmIsMajorTimeStep(pressure_regulator_step_resp_M)) {
    /* set solver stop time */
    if (!(pressure_regulator_step_resp_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&pressure_regulator_step_resp_M->solverInfo,
                            ((pressure_regulator_step_resp_M->Timing.clockTickH0
        + 1) * pressure_regulator_step_resp_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&pressure_regulator_step_resp_M->solverInfo,
                            ((pressure_regulator_step_resp_M->Timing.clockTick0
        + 1) * pressure_regulator_step_resp_M->Timing.stepSize0 +
        pressure_regulator_step_resp_M->Timing.clockTickH0 *
        pressure_regulator_step_resp_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(pressure_regulator_step_resp_M)) {
    pressure_regulator_step_resp_M->Timing.t[0] = rtsiGetT
      (&pressure_regulator_step_resp_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(pressure_regulator_step_resp_M)) {
    /* Constant: '<Root>/Constant' */
    pressure_regulator_step_respo_B.Constant =
      pressure_regulator_step_respo_P.Constant_Value;
  }

  /* Integrator: '<S2>/Integrator1' */
  if (pressure_regulator_step_resp_DW.Integrator1_IWORK != 0) {
    pressure_regulator_step_respo_X.Integrator1_CSTATE =
      pressure_regulator_step_respo_B.Constant;
  }

  if (rtmIsMajorTimeStep(pressure_regulator_step_resp_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant8'
     */
    pressure_regulator_step_respo_B.F_init =
      pressure_regulator_step_respo_P.Constant1_Value *
      pressure_regulator_step_respo_P.Constant1_Value * 3.1415926535897931 *
      (0.98 * pressure_regulator_step_respo_P.Constant8_Value) / 4.0;
    pressure_regulator_step_respo_B.D_w =
      pressure_regulator_step_respo_B.Constant *
      pressure_regulator_step_respo_B.Constant * 4.0 / 3.1415926535897931;
    pressure_regulator_step_respo_B.D_w = sqrt
      (pressure_regulator_step_respo_B.D_w);
    gamma_1 = 3.0 * pressure_regulator_step_respo_B.Constant;
    A_o1 = 1.5 * pressure_regulator_step_respo_B.Constant;
    pressure_regulator_step_respo_B.m_s = (gamma_1 * gamma_1 *
      3.1415926535897931 * (2.0 * pressure_regulator_step_respo_B.Constant) /
      4.0 + A_o1 * A_o1 * 3.1415926535897931 * (3.0 *
      pressure_regulator_step_respo_B.Constant) / 4.0) * 7800.0;
  }

  /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Integrator: '<S2>/Integrator1'
   */
  A_o1 = asin(pressure_regulator_step_respo_B.Constant /
              pressure_regulator_step_respo_P.Constant1_Value) * 2.0 *
    (pressure_regulator_step_respo_P.Constant1_Value / 2.0) *
    (pressure_regulator_step_respo_B.Constant -
     pressure_regulator_step_respo_X.Integrator1_CSTATE);
  if (A_o1 < 0.0) {
    A_o1 = 0.0;
  }

  gamma_1 = A_o1 * A_o1 * (1.0 - rt_powd_snf
    (pressure_regulator_step_respo_P.Constant6_Value, 4.0));
  A_o1 = (1.0 - rt_powd_snf(sqrt(4.0 * A_o1 / 3.1415926535897931) /
           pressure_regulator_step_respo_B.D_w, 4.0)) *
    (pressure_regulator_step_respo_P.Constant5_Value *
     pressure_regulator_step_respo_P.Constant5_Value);

  /* Step: '<Root>/Step' */
  if (pressure_regulator_step_resp_M->Timing.t[0] <
      pressure_regulator_step_respo_P.Step_Time) {
    tmp = pressure_regulator_step_respo_P.Step_Y0;
  } else {
    tmp = pressure_regulator_step_respo_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant7'
   *  Product: '<Root>/Product'
   */
  gamma_1 = (tmp * pressure_regulator_step_respo_P.Constant7_Value * gamma_1 +
             A_o1 * pressure_regulator_step_respo_P.Constant3_Value) / (gamma_1
    + A_o1);
  A_o1 = pressure_regulator_step_respo_P.Constant1_Value *
    pressure_regulator_step_respo_P.Constant1_Value * 3.1415926535897931 *
    gamma_1 / 4.0;
  tmp = pressure_regulator_step_respo_B.m_s * 9.8 +
    pressure_regulator_step_respo_B.F_init;
  if (A_o1 < tmp) {
    A_o1 = tmp;
  }

  /* Outport: '<Root>/Output' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function1'
   */
  P_red = gamma_1;
  if (rtmIsMajorTimeStep(pressure_regulator_step_resp_M)) {
    /* Gain: '<S2>/g' */
    pressure_regulator_step_respo_B.g = pressure_regulator_step_respo_P.g_Gain *
      pressure_regulator_step_respo_B.m_s;
  }

  /* Integrator: '<S2>/Integrator' */
  pressure_regulator_step_respo_B.x2 =
    pressure_regulator_step_respo_X.Integrator_CSTATE;

  /* Product: '<S2>/Divide' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant4'
   *  Integrator: '<S2>/Integrator1'
   *  MATLAB Function: '<S2>/MATLAB Function1'
   *  Product: '<S2>/Product'
   *  Product: '<S2>/Product1'
   *  Sum: '<S2>/Add'
   *  Sum: '<S2>/Add1'
   */
  pressure_regulator_step_respo_B.Divide = ((((A_o1 -
    pressure_regulator_step_respo_B.F_init) - pressure_regulator_step_respo_B.g)
    - pressure_regulator_step_respo_B.x2 *
    pressure_regulator_step_respo_P.Constant4_Value) -
    pressure_regulator_step_respo_P.Constant2_Value *
    pressure_regulator_step_respo_X.Integrator1_CSTATE) /
    pressure_regulator_step_respo_B.m_s;
  if (rtmIsMajorTimeStep(pressure_regulator_step_resp_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(pressure_regulator_step_resp_M->rtwLogInfo,
                        (pressure_regulator_step_resp_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(pressure_regulator_step_resp_M)) {
    /* Update for Integrator: '<S2>/Integrator1' */
    pressure_regulator_step_resp_DW.Integrator1_IWORK = 0;
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(pressure_regulator_step_resp_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(pressure_regulator_step_resp_M)!=-1) &&
          !((rtmGetTFinal(pressure_regulator_step_resp_M)-
             (((pressure_regulator_step_resp_M->Timing.clockTick1+
                pressure_regulator_step_resp_M->Timing.clockTickH1* 4294967296.0))
              * 1.0E-5)) > (((pressure_regulator_step_resp_M->Timing.clockTick1+
                              pressure_regulator_step_resp_M->Timing.clockTickH1*
              4294967296.0)) * 1.0E-5) * (DBL_EPSILON))) {
        rtmSetErrorStatus(pressure_regulator_step_resp_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&pressure_regulator_step_resp_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++pressure_regulator_step_resp_M->Timing.clockTick0)) {
      ++pressure_regulator_step_resp_M->Timing.clockTickH0;
    }

    pressure_regulator_step_resp_M->Timing.t[0] = rtsiGetSolverStopTime
      (&pressure_regulator_step_resp_M->solverInfo);

    {
      /* Update absolute timer for sample time: [1.0E-5s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      pressure_regulator_step_resp_M->Timing.clockTick1++;
      if (!pressure_regulator_step_resp_M->Timing.clockTick1) {
        pressure_regulator_step_resp_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void pressure_regulator_step_response_derivatives(void)
{
  XDot_pressure_regulator_step__T *_rtXdot;
  _rtXdot = ((XDot_pressure_regulator_step__T *)
             pressure_regulator_step_resp_M->derivs);

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = pressure_regulator_step_respo_B.x2;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = pressure_regulator_step_respo_B.Divide;
}

/* Model initialize function */
void pressure_regulator_step_response_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)pressure_regulator_step_resp_M, 0,
                sizeof(RT_MODEL_pressure_regulator_s_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&pressure_regulator_step_resp_M->solverInfo,
                          &pressure_regulator_step_resp_M->Timing.simTimeStep);
    rtsiSetTPtr(&pressure_regulator_step_resp_M->solverInfo, &rtmGetTPtr
                (pressure_regulator_step_resp_M));
    rtsiSetStepSizePtr(&pressure_regulator_step_resp_M->solverInfo,
                       &pressure_regulator_step_resp_M->Timing.stepSize0);
    rtsiSetdXPtr(&pressure_regulator_step_resp_M->solverInfo,
                 &pressure_regulator_step_resp_M->derivs);
    rtsiSetContStatesPtr(&pressure_regulator_step_resp_M->solverInfo, (real_T **)
                         &pressure_regulator_step_resp_M->contStates);
    rtsiSetNumContStatesPtr(&pressure_regulator_step_resp_M->solverInfo,
      &pressure_regulator_step_resp_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&pressure_regulator_step_resp_M->solverInfo,
      &pressure_regulator_step_resp_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&pressure_regulator_step_resp_M->solverInfo,
       &pressure_regulator_step_resp_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&pressure_regulator_step_resp_M->solverInfo,
       &pressure_regulator_step_resp_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&pressure_regulator_step_resp_M->solverInfo,
                          (&rtmGetErrorStatus(pressure_regulator_step_resp_M)));
    rtsiSetRTModelPtr(&pressure_regulator_step_resp_M->solverInfo,
                      pressure_regulator_step_resp_M);
  }

  rtsiSetSimTimeStep(&pressure_regulator_step_resp_M->solverInfo,
                     MAJOR_TIME_STEP);
  pressure_regulator_step_resp_M->intgData.y =
    pressure_regulator_step_resp_M->odeY;
  pressure_regulator_step_resp_M->intgData.f[0] =
    pressure_regulator_step_resp_M->odeF[0];
  pressure_regulator_step_resp_M->intgData.f[1] =
    pressure_regulator_step_resp_M->odeF[1];
  pressure_regulator_step_resp_M->intgData.f[2] =
    pressure_regulator_step_resp_M->odeF[2];
  pressure_regulator_step_resp_M->contStates = ((X_pressure_regulator_step_res_T
    *) &pressure_regulator_step_respo_X);
  rtsiSetSolverData(&pressure_regulator_step_resp_M->solverInfo, (void *)
                    &pressure_regulator_step_resp_M->intgData);
  rtsiSetSolverName(&pressure_regulator_step_resp_M->solverInfo,"ode3");
  rtmSetTPtr(pressure_regulator_step_resp_M,
             &pressure_regulator_step_resp_M->Timing.tArray[0]);
  rtmSetTFinal(pressure_regulator_step_resp_M, 0.5);
  pressure_regulator_step_resp_M->Timing.stepSize0 = 1.0E-5;
  rtmSetFirstInitCond(pressure_regulator_step_resp_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    pressure_regulator_step_resp_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(pressure_regulator_step_resp_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(pressure_regulator_step_resp_M->rtwLogInfo, (NULL));
    rtliSetLogT(pressure_regulator_step_resp_M->rtwLogInfo, "");
    rtliSetLogX(pressure_regulator_step_resp_M->rtwLogInfo, "");
    rtliSetLogXFinal(pressure_regulator_step_resp_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(pressure_regulator_step_resp_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(pressure_regulator_step_resp_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(pressure_regulator_step_resp_M->rtwLogInfo, 0);
    rtliSetLogDecimation(pressure_regulator_step_resp_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &P_red
      };

      rtliSetLogYSignalPtrs(pressure_regulator_step_resp_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs[] = {
        (NULL)
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "P_red" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "pressure_regulator_step_response/Output" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),
          rt_LoggingPreprocessingFcnPtrs,

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(pressure_regulator_step_resp_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(pressure_regulator_step_resp_M->rtwLogInfo, "reduced_pressure");
  }

  /* block I/O */
  (void) memset(((void *) &pressure_regulator_step_respo_B), 0,
                sizeof(B_pressure_regulator_step_res_T));

  /* states (continuous) */
  {
    (void) memset((void *)&pressure_regulator_step_respo_X, 0,
                  sizeof(X_pressure_regulator_step_res_T));
  }

  /* states (dwork) */
  (void) memset((void *)&pressure_regulator_step_resp_DW, 0,
                sizeof(DW_pressure_regulator_step_re_T));

  /* external outputs */
  P_red = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(pressure_regulator_step_resp_M->rtwLogInfo,
    0.0, rtmGetTFinal(pressure_regulator_step_resp_M),
    pressure_regulator_step_resp_M->Timing.stepSize0, (&rtmGetErrorStatus
    (pressure_regulator_step_resp_M)));

  /* Start for Constant: '<Root>/Constant' */
  pressure_regulator_step_respo_B.Constant =
    pressure_regulator_step_respo_P.Constant_Value;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  if (rtmIsFirstInitCond(pressure_regulator_step_resp_M)) {
    pressure_regulator_step_respo_X.Integrator1_CSTATE = 0.005;
  }

  pressure_regulator_step_resp_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S2>/Integrator1' */

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  pressure_regulator_step_respo_X.Integrator_CSTATE =
    pressure_regulator_step_respo_P.Integrator_IC;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(pressure_regulator_step_resp_M)) {
    rtmSetFirstInitCond(pressure_regulator_step_resp_M, 0);
  }
}

/* Model terminate function */
void pressure_regulator_step_response_terminate(void)
{
  /* (no terminate code required) */
}
