/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: goldCodeAnalysis.c
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

#include "goldCodeAnalysis.h"
#include "goldCodeAnalysis_private.h"

/* Block signals (default storage) */
B rtB;

/* Block states (default storage) */
DW rtDW;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static real_T rand_g(void);
static real_T rand_g(void)
{
  real_T r;
  int32_T b_kk;
  int32_T k;
  uint32_T b_u[2];
  if (rtDW.method == 4U) {
    uint32_T mti;
    uint32_T y;
    k = (int32_T)(rtDW.state / 127773U);
    mti = (rtDW.state - k * 127773U) * 16807U;
    y = 2836U * k;
    if (mti < y) {
      rtDW.state = ~(y - mti) & 2147483647U;
    } else {
      rtDW.state = mti - y;
    }

    r = (real_T)rtDW.state * 4.6566128752457969E-10;
  } else if (rtDW.method == 5U) {
    uint32_T mti;
    uint32_T y;
    mti = 69069U * rtDW.state_f[0] + 1234567U;
    y = rtDW.state_f[1] << 13 ^ rtDW.state_f[1];
    y ^= y >> 17;
    y ^= y << 5;
    rtDW.state_f[0] = mti;
    rtDW.state_f[1] = y;
    r = (real_T)(mti + y) * 2.328306436538696E-10;
  } else {
    /* ========================= COPYRIGHT NOTICE ============================ */
    /*  This is a uniform (0,1) pseudorandom number generator based on:        */
    /*                                                                         */
    /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
    /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
    /*                                                                         */
    /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
    /*  All rights reserved.                                                   */
    /*                                                                         */
    /*  Redistribution and use in source and binary forms, with or without     */
    /*  modification, are permitted provided that the following conditions     */
    /*  are met:                                                               */
    /*                                                                         */
    /*    1. Redistributions of source code must retain the above copyright    */
    /*       notice, this list of conditions and the following disclaimer.     */
    /*                                                                         */
    /*    2. Redistributions in binary form must reproduce the above copyright */
    /*       notice, this list of conditions and the following disclaimer      */
    /*       in the documentation and/or other materials provided with the     */
    /*       distribution.                                                     */
    /*                                                                         */
    /*    3. The names of its contributors may not be used to endorse or       */
    /*       promote products derived from this software without specific      */
    /*       prior written permission.                                         */
    /*                                                                         */
    /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
    /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
    /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
    /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
    /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
    /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
    /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
    /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
    /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
    /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
    /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
    /*                                                                         */
    /* =============================   END   ================================= */
    int32_T exitg1;
    do {
      uint32_T mti;
      exitg1 = 0;
      for (k = 0; k < 2; k++) {
        uint32_T y;
        mti = rtDW.state_m[624] + 1U;
        if (rtDW.state_m[624] + 1U >= 625U) {
          for (b_kk = 0; b_kk < 227; b_kk++) {
            y = (rtDW.state_m[b_kk + 1] & 2147483647U) | (rtDW.state_m[b_kk] &
              2147483648U);
            if ((y & 1U) == 0U) {
              y >>= 1U;
            } else {
              y = y >> 1U ^ 2567483615U;
            }

            rtDW.state_m[b_kk] = rtDW.state_m[b_kk + 397] ^ y;
          }

          for (b_kk = 0; b_kk < 396; b_kk++) {
            y = (rtDW.state_m[b_kk + 227] & 2147483648U) | (rtDW.state_m[b_kk +
              228] & 2147483647U);
            if ((y & 1U) == 0U) {
              y >>= 1U;
            } else {
              y = y >> 1U ^ 2567483615U;
            }

            rtDW.state_m[b_kk + 227] = rtDW.state_m[b_kk] ^ y;
          }

          y = (rtDW.state_m[623] & 2147483648U) | (rtDW.state_m[0] & 2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          rtDW.state_m[623] = rtDW.state_m[396] ^ y;
          mti = 1U;
        }

        y = rtDW.state_m[(int32_T)mti - 1];
        rtDW.state_m[624] = mti;
        y ^= y >> 11U;
        y ^= y << 7U & 2636928640U;
        y ^= y << 15U & 4022730752U;
        b_u[k] = y >> 18U ^ y;
      }

      r = ((real_T)(b_u[0] >> 5U) * 6.7108864E+7 + (real_T)(b_u[1] >> 6U)) *
        1.1102230246251565E-16;
      if (r == 0.0) {
        boolean_T b_isvalid;
        if ((rtDW.state_m[624] >= 1U) && (rtDW.state_m[624] < 625U)) {
          b_isvalid = true;
        } else {
          b_isvalid = false;
        }

        if (b_isvalid) {
          boolean_T exitg2;
          b_isvalid = false;
          k = 0;
          exitg2 = false;
          while ((!exitg2) && (k + 1 < 625)) {
            if (rtDW.state_m[k] == 0U) {
              k++;
            } else {
              b_isvalid = true;
              exitg2 = true;
            }
          }
        }

        if (!b_isvalid) {
          mti = 5489U;
          rtDW.state_m[0] = 5489U;
          for (k = 0; k < 623; k++) {
            mti = ((mti >> 30U ^ mti) * 1812433253U + k) + 1U;
            rtDW.state_m[k + 1] = mti;
          }

          rtDW.state_m[624] = 624U;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return r;
}

/* Model step function for TID0 */
void goldCodeAnalysis_step0(void)      /* Sample time: [0.005s, 0.0s] */
{
  int32_T rtb_LogicalOperator;
  uint8_T tmp;
  uint8_T tmp2;
  uint8_T tmp2_0;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.005s, 0.0s] to Sample time: [0.05s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID0_1)++;
  if ((rtM->Timing.RateInteraction.TID0_1) > 9) {
    rtM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* S-Function (scompnseq3): '<S1>/PN Sequence Generator1' */
  tmp = 0U;
  tmp2 = 0U;
  for (rtb_LogicalOperator = 0; rtb_LogicalOperator < 6; rtb_LogicalOperator++)
  {
    tmp += (uint8_T)
      (rtConstP.PNSequenceGenerator1_Polynomial[rtb_LogicalOperator + 1] *
       rtDW.shiftReg[rtb_LogicalOperator]);
    tmp2 += (uint8_T)(rtDW.shiftReg[rtb_LogicalOperator] *
                      rtConstP.pooled1[rtb_LogicalOperator]);
  }

  tmp &= 1;
  for (rtb_LogicalOperator = 4; rtb_LogicalOperator >= 0; rtb_LogicalOperator--)
  {
    rtDW.shiftReg[rtb_LogicalOperator + 1] = rtDW.shiftReg[rtb_LogicalOperator];
  }

  rtDW.shiftReg[0U] = tmp;

  /* S-Function (scompnseq3): '<S1>/PN Sequence Generator2' */
  tmp = 0U;
  tmp2_0 = 0U;
  for (rtb_LogicalOperator = 0; rtb_LogicalOperator < 6; rtb_LogicalOperator++)
  {
    tmp += (uint8_T)
      (rtConstP.PNSequenceGenerator2_Polynomial[rtb_LogicalOperator + 1] *
       rtDW.shiftReg_i[rtb_LogicalOperator]);
    tmp2_0 += (uint8_T)(rtDW.shiftReg_i[rtb_LogicalOperator] *
                        rtConstP.pooled1[rtb_LogicalOperator]);
  }

  tmp &= 1;
  for (rtb_LogicalOperator = 4; rtb_LogicalOperator >= 0; rtb_LogicalOperator--)
  {
    rtDW.shiftReg_i[rtb_LogicalOperator + 1] =
      rtDW.shiftReg_i[rtb_LogicalOperator];
  }

  rtDW.shiftReg_i[0U] = tmp;

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  S-Function (scompnseq3): '<S1>/PN Sequence Generator1'
   *  S-Function (scompnseq3): '<S1>/PN Sequence Generator2'
   */
  rtb_LogicalOperator = (int8_T)((int8_T)((tmp2 & 1) != 0) ^ (int8_T)((tmp2_0 &
    1) != 0));

  /* RateTransition generated from: '<Root>/Product' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    /* RateTransition generated from: '<Root>/Product' */
    rtB.TmpRTBAtProductInport1 = rtDW.TmpRTBAtProductInport1_Buffer0;
  }

  /* End of RateTransition generated from: '<Root>/Product' */

  /* Outport: '<Root>/Spread out' incorporates:
   *  Product: '<Root>/Product'
   */
  rtY.Spreadout = rtB.TmpRTBAtProductInport1 * (real_T)rtb_LogicalOperator;

  /* Outport: '<Root>/PN' */
  rtY.PN = rtb_LogicalOperator;
}

/* Model step function for TID1 */
void goldCodeAnalysis_step1(void)      /* Sample time: [0.05s, 0.0s] */
{
  real_T rtb_User1Data;

  /* MATLABSystem: '<Root>/User1Data' */
  rtb_User1Data = rand_g();

  /* RateTransition generated from: '<Root>/Product' incorporates:
   *  MATLABSystem: '<Root>/User1Data'
   */
  rtDW.TmpRTBAtProductInport1_Buffer0 = floor(rtb_User1Data * 2.0);
}

/* Model initialize function */
void goldCodeAnalysis_initialize(void)
{
  {
    int32_T i;
    static const uint32_T tmp[625] = { 5489U, 1301868182U, 2938499221U,
      2950281878U, 1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U,
      219885934U, 2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U,
      3418470598U, 951210697U, 3693558366U, 2923482051U, 1793174584U,
      2982310801U, 1586906132U, 1951078751U, 1808158765U, 1733897588U,
      431328322U, 4202539044U, 530658942U, 1714810322U, 3025256284U, 3342585396U,
      1937033938U, 2640572511U, 1654299090U, 3692403553U, 4233871309U,
      3497650794U, 862629010U, 2943236032U, 2426458545U, 1603307207U,
      1133453895U, 3099196360U, 2208657629U, 2747653927U, 931059398U, 761573964U,
      3157853227U, 785880413U, 730313442U, 124945756U, 2937117055U, 3295982469U,
      1724353043U, 3021675344U, 3884886417U, 4010150098U, 4056961966U,
      699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U, 2376097373U,
      1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U,
      3570962471U, 4287636090U, 4087307012U, 3603343627U, 202242161U,
      2995682783U, 1620962684U, 3704723357U, 371613603U, 2814834333U,
      2111005706U, 624778151U, 2094172212U, 4284947003U, 1211977835U, 991917094U,
      1570449747U, 2962370480U, 1259410321U, 170182696U, 146300961U, 2836829791U,
      619452428U, 2723670296U, 1881399711U, 1161269684U, 1675188680U,
      4132175277U, 780088327U, 3409462821U, 1036518241U, 1834958505U,
      3048448173U, 161811569U, 618488316U, 44795092U, 3918322701U, 1924681712U,
      3239478144U, 383254043U, 4042306580U, 2146983041U, 3992780527U,
      3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U,
      2339662006U, 501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U,
      3393774360U, 1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U,
      819755096U, 2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U,
      1029741190U, 2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U,
      2701024045U, 4117700889U, 759495121U, 3332270341U, 2313004527U,
      2277067795U, 4131855432U, 2722057515U, 1264804546U, 3848622725U,
      2211267957U, 4100593547U, 959123777U, 2130745407U, 3194437393U, 486673947U,
      1377371204U, 17472727U, 352317554U, 3955548058U, 159652094U, 1232063192U,
      3835177280U, 49423123U, 3083993636U, 733092U, 2120519771U, 2573409834U,
      1112952433U, 3239502554U, 761045320U, 1087580692U, 2540165110U, 641058802U,
      1792435497U, 2261799288U, 1579184083U, 627146892U, 2165744623U,
      2200142389U, 2167590760U, 2381418376U, 1793358889U, 3081659520U,
      1663384067U, 2009658756U, 2689600308U, 739136266U, 2304581039U,
      3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U, 2076220115U,
      3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U, 12350217U,
      354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U, 2616064085U,
      1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U,
      1684529556U, 1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U,
      171579916U, 3878728600U, 2475806724U, 2030324028U, 3331164912U,
      1708711359U, 1970023127U, 2859691344U, 2588476477U, 2748146879U,
      136111222U, 2967685492U, 909517429U, 2835297809U, 3206906216U, 3186870716U,
      341264097U, 2542035121U, 3353277068U, 548223577U, 3170936588U, 1678403446U,
      297435620U, 2337555430U, 466603495U, 1132321815U, 1208589219U, 696392160U,
      894244439U, 2562678859U, 470224582U, 3306867480U, 201364898U, 2075966438U,
      1767227936U, 2929737987U, 3674877796U, 2654196643U, 3692734598U,
      3528895099U, 2796780123U, 3048728353U, 842329300U, 191554730U, 2922459673U,
      3489020079U, 3979110629U, 1022523848U, 2202932467U, 3583655201U,
      3565113719U, 587085778U, 4176046313U, 3013713762U, 950944241U, 396426791U,
      3784844662U, 3477431613U, 3594592395U, 2782043838U, 3392093507U,
      3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U, 31522386U,
      2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U,
      1521001832U, 3605886097U, 2802786495U, 2728923319U, 3996284304U,
      903417639U, 1171249804U, 1020374987U, 2824535874U, 423621996U, 1988534473U,
      2493544470U, 1008604435U, 1756003503U, 1488867287U, 1386808992U,
      732088248U, 1780630732U, 2482101014U, 976561178U, 1543448953U, 2602866064U,
      2021139923U, 1952599828U, 2360242564U, 2117959962U, 2753061860U,
      2388623612U, 4138193781U, 2962920654U, 2284970429U, 766920861U,
      3457264692U, 2879611383U, 815055854U, 2332929068U, 1254853997U,
      3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U,
      686850534U, 1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U,
      4195430425U, 607905174U, 3902331779U, 2454067926U, 1708133115U,
      1170874362U, 2008609376U, 3260320415U, 2211196135U, 433538229U,
      2728786374U, 2189520818U, 262554063U, 1182318347U, 3710237267U,
      1221022450U, 715966018U, 2417068910U, 2591870721U, 2870691989U,
      3418190842U, 4238214053U, 1540704231U, 1575580968U, 2095917976U,
      4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U,
      1123218514U, 551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U,
      422862282U, 3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U,
      1324564878U, 1928816105U, 1786535431U, 2878099422U, 3290185549U,
      539474248U, 1657512683U, 552370646U, 1671741683U, 3655312128U, 1552739510U,
      2605208763U, 1441755014U, 181878989U, 3124053868U, 1447103986U,
      3183906156U, 1728556020U, 3502241336U, 3055466967U, 1013272474U,
      818402132U, 1715099063U, 2900113506U, 397254517U, 4194863039U, 1009068739U,
      232864647U, 2540223708U, 2608288560U, 2415367765U, 478404847U, 3455100648U,
      3182600021U, 2115988978U, 434269567U, 4117179324U, 3461774077U, 887256537U,
      3545801025U, 286388911U, 3451742129U, 1981164769U, 786667016U, 3310123729U,
      3097811076U, 2224235657U, 2959658883U, 3370969234U, 2514770915U,
      3345656436U, 2677010851U, 2206236470U, 271648054U, 2342188545U,
      4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U,
      1477814055U, 4043852216U, 1876372354U, 3133294443U, 3871104810U,
      3177020907U, 2074304428U, 3479393793U, 759562891U, 164128153U, 1839069216U,
      2114162633U, 3989947309U, 3611054956U, 1333547922U, 835429831U, 494987340U,
      171987910U, 1252001001U, 370809172U, 3508925425U, 2535703112U, 1276855041U,
      1922855120U, 835673414U, 3030664304U, 613287117U, 171219893U, 3423096126U,
      3376881639U, 2287770315U, 1658692645U, 1262815245U, 3957234326U,
      1168096164U, 2968737525U, 2655813712U, 2132313144U, 3976047964U,
      326516571U, 353088456U, 3679188938U, 3205649712U, 2654036126U, 1249024881U,
      880166166U, 691800469U, 2229503665U, 1673458056U, 4032208375U, 1851778863U,
      2563757330U, 376742205U, 1794655231U, 340247333U, 1505873033U, 396524441U,
      879666767U, 3335579166U, 3260764261U, 3335999539U, 506221798U, 4214658741U,
      975887814U, 2080536343U, 3360539560U, 571586418U, 138896374U, 4234352651U,
      2737620262U, 3928362291U, 1516365296U, 38056726U, 3599462320U, 3585007266U,
      3850961033U, 471667319U, 1536883193U, 2310166751U, 1861637689U,
      2530999841U, 4139843801U, 2710569485U, 827578615U, 2012334720U,
      2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U, 2478379033U,
      643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U,
      3285177704U, 1948416081U, 1311525291U, 1183517742U, 1739192232U,
      3979815115U, 2567840007U, 4116821529U, 213304419U, 4125718577U,
      1473064925U, 2442436592U, 1893310111U, 4195361916U, 3747569474U,
      828465101U, 2991227658U, 750582866U, 1205170309U, 1409813056U, 678418130U,
      1171531016U, 3821236156U, 354504587U, 4202874632U, 3882511497U,
      1893248677U, 1903078632U, 26340130U, 2069166240U, 3657122492U, 3725758099U,
      831344905U, 811453383U, 3447711422U, 2434543565U, 4166886888U, 3358210805U,
      4142984013U, 2988152326U, 3527824853U, 982082992U, 2809155763U, 190157081U,
      3340214818U, 2365432395U, 2548636180U, 2894533366U, 3474657421U,
      2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U, 3186502468U,
      453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U,
      3541393095U, 4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U,
      1795580598U, 2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U,
      705213300U, 363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U,
      2199989172U, 1987356470U, 4026755612U, 2147252133U, 270400031U,
      1367820199U, 2369854699U, 2844269403U, 79981964U, 624U };

    for (i = 0; i < 6; i++) {
      /* InitializeConditions for S-Function (scompnseq3): '<S1>/PN Sequence Generator1' */
      rtDW.shiftReg[i] = rtConstP.pooled1[i];

      /* InitializeConditions for S-Function (scompnseq3): '<S1>/PN Sequence Generator2' */
      rtDW.shiftReg_i[i] = rtConstP.pooled1[i];
    }

    /* Start for MATLABSystem: '<Root>/User1Data' */
    rtDW.method = 7U;
    rtDW.state = 1144108930U;
    rtDW.state_f[0] = 362436069U;
    rtDW.state_f[1] = 521288629U;
    memcpy(&rtDW.state_m[0], &tmp[0], 625U * sizeof(uint32_T));
  }
}

/* Model terminate function */
void goldCodeAnalysis_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
