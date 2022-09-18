/*
 * File: M01_HPP_Control.c
 *
 * Code generated for Simulink model 'M01_HPP_Control'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Sep 18 17:29:45 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "M01_HPP_Control.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if 0

/* Skip this size verification because of preprocessor limitation */
#if ( ULLONG_MAX != (0xFFFFFFFFFFFFFFFFULL) ) || ( LLONG_MAX != (0x7FFFFFFFFFFFFFFFLL) )
#error Code was generated for compiler with different sized ulong_long/long_long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif
#endif

/* Block signals and states (auto storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* Model step function */
void M01_HPP_Control_step(void)
{
  int32_T rtb_DataTypeConversion;
  boolean_T zcEvent;
  int32_T rtb_DataTypeConversion1;
  int32_T rtb_Sum1;
  uint32_T rtb_Sum;
  boolean_T LogicalOperator1;

  /* Chart: '<Root>/Диспетчер' */
  /* Gateway: Диспетчер */
  /* During: Диспетчер */
  if (rtDW.HPP_interf_inEventCounter > 0U) {
    rtDW.HPP_interf_in = !rtDW.HPP_interf_in;
    rtDW.HPP_interf_inEventCounter--;
  }

  if (rtDW.HPP_ModeDispEventCounter > 0U) {
    rtDW.HPP_ModeDisp = !rtDW.HPP_ModeDisp;
    rtDW.HPP_ModeDispEventCounter--;
  }

  if (rtDW.HPP_PIDEventCounter > 0U) {
    rtDW.HPP_PID = !rtDW.HPP_PID;
    rtDW.HPP_PIDEventCounter--;
  }

  if (rtDW.HPP_SafetyEventCounter > 0U) {
    rtDW.HPP_Safety = !rtDW.HPP_Safety;
    rtDW.HPP_SafetyEventCounter--;
  }

  if (rtDW.HPP_interf_outEventCounter > 0U) {
    rtDW.HPP_interf_out = !rtDW.HPP_interf_out;
    rtDW.HPP_interf_outEventCounter--;
  }

  /* End of Chart: '<Root>/Диспетчер' */

  /* Outputs for Enabled SubSystem: '<Root>/HPP_Disp' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  if (rtDW.HPP_ModeDisp) {
    /* DataStoreWrite: '<S1>/Data Store Write' incorporates:
     *  DataStoreRead: '<S1>/Data Store Read'
     */
    P_PIDMode = P_PIDMode_Set;
  }

  /* End of Outputs for SubSystem: '<Root>/HPP_Disp' */

  /* Outputs for Enabled SubSystem: '<Root>/HPP_PID' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtDW.HPP_PID) {
    /* Sum: '<S2>/Sum' incorporates:
     *  DataStoreRead: '<S2>/Data Store Read'
     *  DataStoreRead: '<S2>/Data Store Read1'
     */
    rtb_Sum = p_RailPressure - P_RailPressure_set;

    /* DataStoreWrite: '<S2>/Data Store Write' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion2'
     */
    p_RailPressure_Error = (int32_T)rtb_Sum;

    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  DataStoreRead: '<S2>/Data Store Read2'
     *  Product: '<S2>/Product'
     */
    rtb_DataTypeConversion = (int32_T)((uint32_T)(((int64_T)rtb_Sum * P_P_Coeff)
      >> 22) >> 18);

    /* Switch: '<S7>/Switch2' incorporates:
     *  Constant: '<S2>/Constant'
     *  RelationalOperator: '<S7>/LowerRelop1'
     */
    if (rtb_DataTypeConversion > 1000) {
      rtb_DataTypeConversion = 1000;
    }

    /* End of Switch: '<S7>/Switch2' */

    /* Logic: '<S2>/Logical Operator1' incorporates:
     *  DataStoreRead: '<S2>/Data Store Read5'
     *  DataStoreRead: '<S2>/Data Store Read6'
     *  Logic: '<S2>/Logical Operator'
     */
    LogicalOperator1 = (P_PIDMode && (!p_PIDError_Status));

    /* Delay: '<S2>/Delay' */
    zcEvent = ((!LogicalOperator1) && (rtPrevZCX.Delay_Reset_ZCE != ZERO_ZCSIG));
    rtPrevZCX.Delay_Reset_ZCE = LogicalOperator1;
    if (LogicalOperator1) {
      if (zcEvent) {
        rtDW.Delay_DSTATE = 0.0;
      }

      rtDW.Delay = rtDW.Delay_DSTATE;
    }

    /* End of Delay: '<S2>/Delay' */

    /* DataTypeConversion: '<S2>/Data Type Conversion1' */
    rtb_DataTypeConversion1 = (int32_T)floor(rtDW.Delay);

    /* Switch: '<S9>/Switch2' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant3'
     *  RelationalOperator: '<S9>/LowerRelop1'
     *  RelationalOperator: '<S9>/UpperRelop'
     *  Switch: '<S9>/Switch'
     */
    if (rtb_DataTypeConversion1 > 1000) {
      rtb_DataTypeConversion1 = 1000;
    } else {
      if (rtb_DataTypeConversion1 < 0) {
        /* Switch: '<S9>/Switch' incorporates:
         *  Constant: '<S2>/Constant3'
         */
        rtb_DataTypeConversion1 = 0;
      }
    }

    /* End of Switch: '<S9>/Switch2' */

    /* Switch: '<S2>/Switch' incorporates:
     *  Constant: '<S2>/Constant6'
     */
    if (LogicalOperator1) {
      /* Sum: '<S2>/Sum1' */
      rtb_Sum1 = rtb_DataTypeConversion + rtb_DataTypeConversion1;

      /* Switch: '<S8>/Switch2' incorporates:
       *  Constant: '<S2>/Constant4'
       *  RelationalOperator: '<S8>/LowerRelop1'
       */
      if (rtb_Sum1 > 1000) {
        rtb_Sum1 = 1000;
      }

      /* End of Switch: '<S8>/Switch2' */
    } else {
      rtb_Sum1 = 1000;
    }

    /* End of Switch: '<S2>/Switch' */

    /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
     *  Constant: '<S2>/Constant9'
     *  Switch: '<S10>/Switch2'
     */
    p_PWM_out = 920;

    /* DataStoreWrite: '<S2>/Data Store Write2' */
    p_PID_Out = rtb_Sum1;

    /* DataStoreWrite: '<S2>/Data Store Write3' */
    p_P_Part = rtb_DataTypeConversion;

    /* DataStoreWrite: '<S2>/Data Store Write4' */
    p_I_Part = rtb_DataTypeConversion1;

    /* Update for Delay: '<S2>/Delay' incorporates:
     *  DataStoreRead: '<S2>/Data Store Read3'
     *  Product: '<S2>/Product1'
     *  Sum: '<S2>/Sum2'
     */
    if (LogicalOperator1) {
      rtDW.Delay_DSTATE = (real_T)((uint32_T)(((int64_T)rtb_Sum * P_I_Coeff) >>
        22) + (uint32_T)(rtDW.Delay * 262144.0)) * 3.814697265625E-6;
    }

    /* End of Update for Delay: '<S2>/Delay' */
  }

  /* End of Outputs for SubSystem: '<Root>/HPP_PID' */

  /* Outputs for Enabled SubSystem: '<Root>/HPP_Safety' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (rtDW.HPP_Safety) {
    /* Relay: '<S3>/Relay' incorporates:
     *  DataStoreRead: '<S3>/Data Store Read'
     */
    if (p_RailPressure >= 445644800U) {
      rtDW.Relay_Mode = true;
    } else {
      if (p_RailPressure <= 393216000U) {
        rtDW.Relay_Mode = false;
      }
    }

    /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
     *  Relay: '<S3>/Relay'
     */
    p_PIDError_Status = rtDW.Relay_Mode;
  }

  /* End of Outputs for SubSystem: '<Root>/HPP_Safety' */

  /* Outputs for Enabled SubSystem: '<Root>/Interface_In' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (rtDW.HPP_interf_in) {
    /* Product: '<S4>/Product' incorporates:
     *  DataStoreRead: '<S4>/Data Store Read3'
     */
    rtb_Sum = (uint32_T)((p_RailPressureSensor_bit * 320471ULL) >> 16);

    /* DataStoreWrite: '<S4>/Data Store Write3' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant3'
     *  Product: '<S4>/Product1'
     *  Sum: '<S4>/Add'
     */
    p_RailPressure = 63753421U + (uint32_T)((rtb_Sum * 125043ULL) >> 18);

    /* DataStoreWrite: '<S4>/Data Store Write4' */
    p_RailPressureSensor_U = rtb_Sum;

    /* DataStoreWrite: '<S4>/Data Store Write' incorporates:
     *  DataStoreRead: '<S4>/Data Store Read'
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     */
    P_RailPressure_set = (uint32_T)P_In_RailPressure_set << 18;

    /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
     *  DataStoreRead: '<S4>/Data Store Read1'
     *  DataTypeConversion: '<S4>/Data Type Conversion1'
     */
    P_P_Coeff = (int32_T)floorf(P_In_I_Coeff * 4.194304E+6F);

    /* DataStoreWrite: '<S4>/Data Store Write2' incorporates:
     *  DataStoreRead: '<S4>/Data Store Read2'
     *  DataTypeConversion: '<S4>/Data Type Conversion2'
     */
    P_I_Coeff = (int32_T)floorf(P_In_P_Coeff * 4.194304E+6F);
  }

  /* End of Outputs for SubSystem: '<Root>/Interface_In' */
}

/* Model initialize function */
void M01_HPP_Control_initialize(void)
{
  rtPrevZCX.Delay_Reset_ZCE = ZERO_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
