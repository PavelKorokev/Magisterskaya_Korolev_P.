/*
 * File: M01_HPP_Control.h
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

#ifndef RTW_HEADER_M01_HPP_Control_h_
#define RTW_HEADER_M01_HPP_Control_h_
#include <math.h>
#ifndef M01_HPP_Control_COMMON_INCLUDES_
# define M01_HPP_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* M01_HPP_Control_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay;                        /* '<S2>/Delay' */
  real_T Delay_DSTATE;                 /* '<S2>/Delay' */
  uint32_T HPP_interf_inEventCounter;  /* '<Root>/Диспетчер' */
  uint32_T HPP_ModeDispEventCounter;   /* '<Root>/Диспетчер' */
  uint32_T HPP_PIDEventCounter;        /* '<Root>/Диспетчер' */
  uint32_T HPP_SafetyEventCounter;     /* '<Root>/Диспетчер' */
  uint32_T HPP_interf_outEventCounter; /* '<Root>/Диспетчер' */
  boolean_T HPP_interf_in;             /* '<Root>/Диспетчер' */
  boolean_T HPP_ModeDisp;              /* '<Root>/Диспетчер' */
  boolean_T HPP_PID;                   /* '<Root>/Диспетчер' */
  boolean_T HPP_Safety;                /* '<Root>/Диспетчер' */
  boolean_T HPP_interf_out;            /* '<Root>/Диспетчер' */
  boolean_T Relay_Mode;                /* '<S3>/Relay' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S2>/Delay' */
} PrevZCX;

/* Imported (extern) states */
extern real32_T P_In_I_Coeff;          /* Simulink.Signal object 'P_In_I_Coeff'
                                        * {{GROUP=HPP_PID}} I-part coefficient
                                        */
extern real32_T P_In_P_Coeff;          /* Simulink.Signal object 'P_In_P_Coeff'
                                        * {{GROUP=HPP_PID}} P-part coefficient
                                        */
extern int32_T P_In_RailPressure_set;  /* Simulink.Signal object 'P_In_RailPressure_set'
                                        * {{GROUP=HPP_PID}} desired rail pressure
                                        */
extern int32_T p_I_Part;               /* Simulink.Signal object 'p_I_Part'
                                        * {{GROUP=HPP_PID}} I-part coefficient
                                        */
extern int32_T p_PID_Out;              /* Simulink.Signal object 'p_PID_Out'
                                        * {{GROUP=HPP_PID}} I-part coefficient
                                        */
extern int32_T p_PWM_out;              /* Simulink.Signal object 'p_PWM_out'
                                        * {{GROUP=HPP_PID}} HPP MEU PWM:	0 - max rate 1 - HPP disabled
                                        */
extern int32_T p_P_Part;               /* Simulink.Signal object 'p_P_Part'
                                        * {{GROUP=HPP_PID}} I-part coefficient
                                        */
extern int32_T p_RailPressure_Error;   /* Simulink.Signal object 'p_RailPressure_Error'
                                        * {{GROUP=HPP_PID}} error of PID-control
                                        */
extern uint32_T P_RailPressure_set;    /* Simulink.Signal object 'P_RailPressure_set'
                                        * {{GROUP=HPP_PID}} desired rail pressure
                                        */
extern uint32_T p_RailPressure;        /* Simulink.Signal object 'p_RailPressure'
                                        * {{GROUP=HPP_PID}} measured rail pressure
                                        */
extern uint32_T p_RailPressureSensor_U;/* Simulink.Signal object 'p_RailPressureSensor_U'
                                        * {{GROUP=HPP_PID}} bit of rail pressure sensor ADC
                                        */
extern uint32_T p_RailPressureSensor_bit;/* Simulink.Signal object 'p_RailPressureSensor_bit'
                                          * {{GROUP=HPP_PID}} bit of rail pressure sensor ADC
                                          */
extern int32_T P_I_Coeff;              /* Simulink.Signal object 'P_I_Coeff'
                                        * {{GROUP=HPP_PID}} I-part coefficient
                                        */
extern int32_T P_P_Coeff;              /* Simulink.Signal object 'P_P_Coeff'
                                        * {{GROUP=HPP_PID}} P-part coefficient
                                        */
extern boolean_T P_PIDMode;            /* Simulink.Signal object 'P_PIDMode'
                                        * {{GROUP=HPP_PID}} P_PIDMode_Set copy
                                        */
extern boolean_T P_PIDMode_Set;        /* Simulink.Signal object 'P_PIDMode_Set'
                                        * {{GROUP=HPP_PID}} mode of PID-control: 1 - PID on 2 - PID off
                                        */
extern boolean_T p_PIDError_Status;    /* Simulink.Signal object 'p_PIDError_Status'
                                        * {{GROUP=HPP_PID}} Error status: 0 - there is no error	1 - overpressure
                                        */

/* Block signals and states (auto storage) */
extern DW rtDW;

/* Model entry point functions */
extern void M01_HPP_Control_initialize(void);
extern void M01_HPP_Control_step(void);

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
 * '<Root>' : 'M01_HPP_Control'
 * '<S1>'   : 'M01_HPP_Control/HPP_Disp'
 * '<S2>'   : 'M01_HPP_Control/HPP_PID'
 * '<S3>'   : 'M01_HPP_Control/HPP_Safety'
 * '<S4>'   : 'M01_HPP_Control/Interface_In'
 * '<S5>'   : 'M01_HPP_Control/Interface_Out'
 * '<S6>'   : 'M01_HPP_Control/Диспетчер'
 * '<S7>'   : 'M01_HPP_Control/HPP_PID/Saturation Dynamic'
 * '<S8>'   : 'M01_HPP_Control/HPP_PID/Saturation Dynamic1'
 * '<S9>'   : 'M01_HPP_Control/HPP_PID/Saturation Dynamic2'
 * '<S10>'  : 'M01_HPP_Control/HPP_PID/Saturation Dynamic3'
 */
#endif                                 /* RTW_HEADER_M01_HPP_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
