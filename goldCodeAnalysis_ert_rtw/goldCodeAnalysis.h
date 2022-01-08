/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: goldCodeAnalysis.h
 *
 * Code generated for Simulink model 'goldCodeAnalysis'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Jan  6 20:51:49 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_goldCodeAnalysis_h_
#define RTW_HEADER_goldCodeAnalysis_h_
#include <math.h>
#include <string.h>
#ifndef goldCodeAnalysis_COMMON_INCLUDES_
#define goldCodeAnalysis_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* goldCodeAnalysis_COMMON_INCLUDES_ */

#include "goldCodeAnalysis_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TmpRTBAtProductInport1;       /* '<Root>/User1Data' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T TmpRTBAtProductInport1_Buffer0;/* synthesized block */
  uint32_T state;                      /* '<Root>/User1Data' */
  uint32_T state_f[2];                 /* '<Root>/User1Data' */
  uint32_T state_m[625];               /* '<Root>/User1Data' */
  uint32_T method;                     /* '<Root>/User1Data' */
  uint8_T shiftReg[6];                 /* '<S1>/PN Sequence Generator1' */
  uint8_T shiftReg_i[6];               /* '<S1>/PN Sequence Generator2' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: PNSequenceGenerator1_Polynomial
   * Referenced by: '<S1>/PN Sequence Generator1'
   */
  uint8_T PNSequenceGenerator1_Polynomial[7];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S1>/PN Sequence Generator1'
   *   '<S1>/PN Sequence Generator2'
   */
  uint8_T pooled1[6];

  /* Computed Parameter: PNSequenceGenerator2_Polynomial
   * Referenced by: '<S1>/PN Sequence Generator2'
   */
  uint8_T PNSequenceGenerator2_Polynomial[7];
} ConstP;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Spreadout;                    /* '<Root>/Spread out' */
  real_T PN;                           /* '<Root>/PN' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals (default storage) */
extern B rtB;

/* Block states (default storage) */
extern DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void goldCodeAnalysis_initialize(void);
extern void goldCodeAnalysis_step0(void);
extern void goldCodeAnalysis_step1(void);
extern void goldCodeAnalysis_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'goldCodeAnalysis'
 * '<S1>'   : 'goldCodeAnalysis/Gold Sequence Generator'
 */
#endif                                 /* RTW_HEADER_goldCodeAnalysis_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
