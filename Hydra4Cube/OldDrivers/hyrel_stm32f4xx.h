#include "stm32f407xx.h"
/********************  Bit definition for DBGMCU_APB2_FZ register  ************/
#define  DBGMCU_APB1_FZ_DBG_TIM1_STOP        ((uint32_t)0x00000001)
#define  DBGMCU_APB1_FZ_DBG_TIM8_STOP        ((uint32_t)0x00000002)
#define  DBGMCU_APB1_FZ_DBG_TIM9_STOP        ((uint32_t)0x00010000)
#define  DBGMCU_APB1_FZ_DBG_TIM10_STOP       ((uint32_t)0x00020000)
#define  DBGMCU_APB1_FZ_DBG_TIM11_STOP       ((uint32_t)0x00040000)



/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O                             */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for GPIO_MODER register  *****************/
#define HYREL_GPIO_MODER_MODER0                    ((uint32_t)0x00000003)
#define HYREL_GPIO_MODER_MODER0_0                  ((uint32_t)0x00000001)
#define HYREL_GPIO_MODER_MODER0_1                  ((uint32_t)0x00000002)

#define HYREL_GPIO_MODER_MODER1                    ((uint32_t)0x0000000C)
#define HYREL_GPIO_MODER_MODER1_0                  ((uint32_t)0x00000004)
#define HYREL_GPIO_MODER_MODER1_1                  ((uint32_t)0x00000008)

#define HYREL_GPIO_MODER_MODER2                    ((uint32_t)0x00000030)
#define HYREL_GPIO_MODER_MODER2_0                  ((uint32_t)0x00000010)
#define HYREL_GPIO_MODER_MODER2_1                  ((uint32_t)0x00000020)

#define HYREL_GPIO_MODER_MODER3                    ((uint32_t)0x000000C0)
#define HYREL_GPIO_MODER_MODER3_0                  ((uint32_t)0x00000040)
#define HYREL_GPIO_MODER_MODER3_1                  ((uint32_t)0x00000080)

#define HYREL_GPIO_MODER_MODER4                    ((uint32_t)0x00000300)
#define HYREL_GPIO_MODER_MODER4_0                  ((uint32_t)0x00000100)
#define HYREL_GPIO_MODER_MODER4_1                  ((uint32_t)0x00000200)

#define HYREL_GPIO_MODER_MODER5                    ((uint32_t)0x00000C00)
#define HYREL_GPIO_MODER_MODER5_0                  ((uint32_t)0x00000400)
#define HYREL_GPIO_MODER_MODER5_1                  ((uint32_t)0x00000800)

#define HYREL_GPIO_MODER_MODER6                    ((uint32_t)0x00003000)
#define HYREL_GPIO_MODER_MODER6_0                  ((uint32_t)0x00001000)
#define HYREL_GPIO_MODER_MODER6_1                  ((uint32_t)0x00002000)

#define HYREL_GPIO_MODER_MODER7                    ((uint32_t)0x0000C000)
#define HYREL_GPIO_MODER_MODER7_0                  ((uint32_t)0x00004000)
#define HYREL_GPIO_MODER_MODER7_1                  ((uint32_t)0x00008000)

#define HYREL_GPIO_MODER_MODER8                    ((uint32_t)0x00030000)
#define HYREL_GPIO_MODER_MODER8_0                  ((uint32_t)0x00010000)
#define HYREL_GPIO_MODER_MODER8_1                  ((uint32_t)0x00020000)

#define HYREL_GPIO_MODER_MODER9                    ((uint32_t)0x000C0000)
#define HYREL_GPIO_MODER_MODER9_0                  ((uint32_t)0x00040000)
#define HYREL_GPIO_MODER_MODER9_1                  ((uint32_t)0x00080000)

#define HYREL_GPIO_MODER_MODER10                   ((uint32_t)0x00300000)
#define HYREL_GPIO_MODER_MODER10_0                 ((uint32_t)0x00100000)
#define HYREL_GPIO_MODER_MODER10_1                 ((uint32_t)0x00200000)

#define HYREL_GPIO_MODER_MODER11                   ((uint32_t)0x00C00000)
#define HYREL_GPIO_MODER_MODER11_0                 ((uint32_t)0x00400000)
#define HYREL_GPIO_MODER_MODER11_1                 ((uint32_t)0x00800000)

#define HYREL_GPIO_MODER_MODER12                   ((uint32_t)0x03000000)
#define HYREL_GPIO_MODER_MODER12_0                 ((uint32_t)0x01000000)
#define HYREL_GPIO_MODER_MODER12_1                 ((uint32_t)0x02000000)

#define HYREL_GPIO_MODER_MODER13                   ((uint32_t)0x0C000000)
#define HYREL_GPIO_MODER_MODER13_0                 ((uint32_t)0x04000000)
#define HYREL_GPIO_MODER_MODER13_1                 ((uint32_t)0x08000000)

#define HYREL_GPIO_MODER_MODER14                   ((uint32_t)0x30000000)
#define HYREL_GPIO_MODER_MODER14_0                 ((uint32_t)0x10000000)
#define HYREL_GPIO_MODER_MODER14_1                 ((uint32_t)0x20000000)

#define HYREL_GPIO_MODER_MODER15                   ((uint32_t)0xC0000000)
#define HYREL_GPIO_MODER_MODER15_0                 ((uint32_t)0x40000000)
#define HYREL_GPIO_MODER_MODER15_1                 ((uint32_t)0x80000000)

/******************  Bits definition for GPIO_OTYPER register  ****************/
#define HYREL_GPIO_OTYPER_OT_0                     ((uint32_t)0x00000001)
#define HYREL_GPIO_OTYPER_OT_1                     ((uint32_t)0x00000002)
#define HYREL_GPIO_OTYPER_OT_2                     ((uint32_t)0x00000004)
#define HYREL_GPIO_OTYPER_OT_3                     ((uint32_t)0x00000008)
#define HYREL_GPIO_OTYPER_OT_4                     ((uint32_t)0x00000010)
#define HYREL_GPIO_OTYPER_OT_5                     ((uint32_t)0x00000020)
#define HYREL_GPIO_OTYPER_OT_6                     ((uint32_t)0x00000040)
#define HYREL_GPIO_OTYPER_OT_7                     ((uint32_t)0x00000080)
#define HYREL_GPIO_OTYPER_OT_8                     ((uint32_t)0x00000100)
#define HYREL_GPIO_OTYPER_OT_9                     ((uint32_t)0x00000200)
#define HYREL_GPIO_OTYPER_OT_10                    ((uint32_t)0x00000400)
#define HYREL_GPIO_OTYPER_OT_11                    ((uint32_t)0x00000800)
#define HYREL_GPIO_OTYPER_OT_12                    ((uint32_t)0x00001000)
#define HYREL_GPIO_OTYPER_OT_13                    ((uint32_t)0x00002000)
#define HYREL_GPIO_OTYPER_OT_14                    ((uint32_t)0x00004000)
#define HYREL_GPIO_OTYPER_OT_15                    ((uint32_t)0x00008000)

/******************  Bits definition for GPIO_OSPEEDR register  ***************/
#define HYREL_GPIO_OSPEEDER_OSPEEDR0               ((uint32_t)0x00000003)
#define HYREL_GPIO_OSPEEDER_OSPEEDR0_0             ((uint32_t)0x00000001)
#define HYREL_GPIO_OSPEEDER_OSPEEDR0_1             ((uint32_t)0x00000002)

#define HYREL_GPIO_OSPEEDER_OSPEEDR1               ((uint32_t)0x0000000C)
#define HYREL_GPIO_OSPEEDER_OSPEEDR1_0             ((uint32_t)0x00000004)
#define HYREL_GPIO_OSPEEDER_OSPEEDR1_1             ((uint32_t)0x00000008)

#define HYREL_GPIO_OSPEEDER_OSPEEDR2               ((uint32_t)0x00000030)
#define HYREL_GPIO_OSPEEDER_OSPEEDR2_0             ((uint32_t)0x00000010)
#define HYREL_GPIO_OSPEEDER_OSPEEDR2_1             ((uint32_t)0x00000020)

#define HYREL_GPIO_OSPEEDER_OSPEEDR3               ((uint32_t)0x000000C0)
#define HYREL_GPIO_OSPEEDER_OSPEEDR3_0             ((uint32_t)0x00000040)
#define HYREL_GPIO_OSPEEDER_OSPEEDR3_1             ((uint32_t)0x00000080)

#define HYREL_GPIO_OSPEEDER_OSPEEDR4               ((uint32_t)0x00000300)
#define HYREL_GPIO_OSPEEDER_OSPEEDR4_0             ((uint32_t)0x00000100)
#define HYREL_GPIO_OSPEEDER_OSPEEDR4_1             ((uint32_t)0x00000200)

#define HYREL_GPIO_OSPEEDER_OSPEEDR5               ((uint32_t)0x00000C00)
#define HYREL_GPIO_OSPEEDER_OSPEEDR5_0             ((uint32_t)0x00000400)
#define HYREL_GPIO_OSPEEDER_OSPEEDR5_1             ((uint32_t)0x00000800)

#define HYREL_GPIO_OSPEEDER_OSPEEDR6               ((uint32_t)0x00003000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR6_0             ((uint32_t)0x00001000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR6_1             ((uint32_t)0x00002000)

#define HYREL_GPIO_OSPEEDER_OSPEEDR7               ((uint32_t)0x0000C000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR7_0             ((uint32_t)0x00004000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR7_1             ((uint32_t)0x00008000)

#define HYREL_GPIO_OSPEEDER_OSPEEDR8               ((uint32_t)0x00030000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR8_0             ((uint32_t)0x00010000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR8_1             ((uint32_t)0x00020000)

#define HYREL_GPIO_OSPEEDER_OSPEEDR9               ((uint32_t)0x000C0000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR9_0             ((uint32_t)0x00040000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR9_1             ((uint32_t)0x00080000)

#define HYREL_GPIO_OSPEEDER_OSPEEDR10              ((uint32_t)0x00300000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR10_0            ((uint32_t)0x00100000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR10_1            ((uint32_t)0x00200000)

#define HYREL_GPIO_OSPEEDER_OSPEEDR11              ((uint32_t)0x00C00000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR11_0            ((uint32_t)0x00400000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR11_1            ((uint32_t)0x00800000)

#define HYREL_GPIO_OSPEEDER_OSPEEDR12              ((uint32_t)0x03000000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR12_0            ((uint32_t)0x01000000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR12_1            ((uint32_t)0x02000000)

#define HYREL_GPIO_OSPEEDER_OSPEEDR13              ((uint32_t)0x0C000000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR13_0            ((uint32_t)0x04000000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR13_1            ((uint32_t)0x08000000)

#define HYREL_GPIO_OSPEEDER_OSPEEDR14              ((uint32_t)0x30000000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR14_0            ((uint32_t)0x10000000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR14_1            ((uint32_t)0x20000000)

#define HYREL_GPIO_OSPEEDER_OSPEEDR15              ((uint32_t)0xC0000000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR15_0            ((uint32_t)0x40000000)
#define HYREL_GPIO_OSPEEDER_OSPEEDR15_1            ((uint32_t)0x80000000)

/******************  Bits definition for GPIO_PUPDR register  *****************/
#define HYREL_GPIO_PUPDR_PUPDR0                    ((uint32_t)0x00000003)
#define HYREL_GPIO_PUPDR_PUPDR0_0                  ((uint32_t)0x00000001)
#define HYREL_GPIO_PUPDR_PUPDR0_1                  ((uint32_t)0x00000002)

#define HYREL_GPIO_PUPDR_PUPDR1                    ((uint32_t)0x0000000C)
#define HYREL_GPIO_PUPDR_PUPDR1_0                  ((uint32_t)0x00000004)
#define HYREL_GPIO_PUPDR_PUPDR1_1                  ((uint32_t)0x00000008)

#define HYREL_GPIO_PUPDR_PUPDR2                    ((uint32_t)0x00000030)
#define HYREL_GPIO_PUPDR_PUPDR2_0                  ((uint32_t)0x00000010)
#define HYREL_GPIO_PUPDR_PUPDR2_1                  ((uint32_t)0x00000020)

#define HYREL_GPIO_PUPDR_PUPDR3                    ((uint32_t)0x000000C0)
#define HYREL_GPIO_PUPDR_PUPDR3_0                  ((uint32_t)0x00000040)
#define HYREL_GPIO_PUPDR_PUPDR3_1                  ((uint32_t)0x00000080)

#define HYREL_GPIO_PUPDR_PUPDR4                    ((uint32_t)0x00000300)
#define HYREL_GPIO_PUPDR_PUPDR4_0                  ((uint32_t)0x00000100)
#define HYREL_GPIO_PUPDR_PUPDR4_1                  ((uint32_t)0x00000200)

#define HYREL_GPIO_PUPDR_PUPDR5                    ((uint32_t)0x00000C00)
#define HYREL_GPIO_PUPDR_PUPDR5_0                  ((uint32_t)0x00000400)
#define HYREL_GPIO_PUPDR_PUPDR5_1                  ((uint32_t)0x00000800)

#define HYREL_GPIO_PUPDR_PUPDR6                    ((uint32_t)0x00003000)
#define HYREL_GPIO_PUPDR_PUPDR6_0                  ((uint32_t)0x00001000)
#define HYREL_GPIO_PUPDR_PUPDR6_1                  ((uint32_t)0x00002000)

#define HYREL_GPIO_PUPDR_PUPDR7                    ((uint32_t)0x0000C000)
#define HYREL_GPIO_PUPDR_PUPDR7_0                  ((uint32_t)0x00004000)
#define HYREL_GPIO_PUPDR_PUPDR7_1                  ((uint32_t)0x00008000)

#define HYREL_GPIO_PUPDR_PUPDR8                    ((uint32_t)0x00030000)
#define HYREL_GPIO_PUPDR_PUPDR8_0                  ((uint32_t)0x00010000)
#define HYREL_GPIO_PUPDR_PUPDR8_1                  ((uint32_t)0x00020000)

#define HYREL_GPIO_PUPDR_PUPDR9                    ((uint32_t)0x000C0000)
#define HYREL_GPIO_PUPDR_PUPDR9_0                  ((uint32_t)0x00040000)
#define HYREL_GPIO_PUPDR_PUPDR9_1                  ((uint32_t)0x00080000)

#define HYREL_GPIO_PUPDR_PUPDR10                   ((uint32_t)0x00300000)
#define HYREL_GPIO_PUPDR_PUPDR10_0                 ((uint32_t)0x00100000)
#define HYREL_GPIO_PUPDR_PUPDR10_1                 ((uint32_t)0x00200000)

#define HYREL_GPIO_PUPDR_PUPDR11                   ((uint32_t)0x00C00000)
#define HYREL_GPIO_PUPDR_PUPDR11_0                 ((uint32_t)0x00400000)
#define HYREL_GPIO_PUPDR_PUPDR11_1                 ((uint32_t)0x00800000)

#define HYREL_GPIO_PUPDR_PUPDR12                   ((uint32_t)0x03000000)
#define HYREL_GPIO_PUPDR_PUPDR12_0                 ((uint32_t)0x01000000)
#define HYREL_GPIO_PUPDR_PUPDR12_1                 ((uint32_t)0x02000000)

#define HYREL_GPIO_PUPDR_PUPDR13                   ((uint32_t)0x0C000000)
#define HYREL_GPIO_PUPDR_PUPDR13_0                 ((uint32_t)0x04000000)
#define HYREL_GPIO_PUPDR_PUPDR13_1                 ((uint32_t)0x08000000)

#define HYREL_GPIO_PUPDR_PUPDR14                   ((uint32_t)0x30000000)
#define HYREL_GPIO_PUPDR_PUPDR14_0                 ((uint32_t)0x10000000)
#define HYREL_GPIO_PUPDR_PUPDR14_1                 ((uint32_t)0x20000000)

#define HYREL_GPIO_PUPDR_PUPDR15                   ((uint32_t)0xC0000000)
#define HYREL_GPIO_PUPDR_PUPDR15_0                 ((uint32_t)0x40000000)
#define HYREL_GPIO_PUPDR_PUPDR15_1                 ((uint32_t)0x80000000)

/******************  Bits definition for GPIO_IDR register  *******************/
#define HYREL_GPIO_IDR_IDR_0                       ((uint32_t)0x00000001)
#define HYREL_GPIO_IDR_IDR_1                       ((uint32_t)0x00000002)
#define HYREL_GPIO_IDR_IDR_2                       ((uint32_t)0x00000004)
#define HYREL_GPIO_IDR_IDR_3                       ((uint32_t)0x00000008)
#define HYREL_GPIO_IDR_IDR_4                       ((uint32_t)0x00000010)
#define HYREL_GPIO_IDR_IDR_5                       ((uint32_t)0x00000020)
#define HYREL_GPIO_IDR_IDR_6                       ((uint32_t)0x00000040)
#define HYREL_GPIO_IDR_IDR_7                       ((uint32_t)0x00000080)
#define HYREL_GPIO_IDR_IDR_8                       ((uint32_t)0x00000100)
#define HYREL_GPIO_IDR_IDR_9                       ((uint32_t)0x00000200)
#define HYREL_GPIO_IDR_IDR_10                      ((uint32_t)0x00000400)
#define HYREL_GPIO_IDR_IDR_11                      ((uint32_t)0x00000800)
#define HYREL_GPIO_IDR_IDR_12                      ((uint32_t)0x00001000)
#define HYREL_GPIO_IDR_IDR_13                      ((uint32_t)0x00002000)
#define HYREL_GPIO_IDR_IDR_14                      ((uint32_t)0x00004000)
#define HYREL_GPIO_IDR_IDR_15                      ((uint32_t)0x00008000)
/* Old GPIO_IDR register bits definition, maintained for legacy purpose */
#define HYREL_GPIO_OTYPER_IDR_0                    GPIO_IDR_IDR_0
#define HYREL_GPIO_OTYPER_IDR_1                    GPIO_IDR_IDR_1
#define HYREL_GPIO_OTYPER_IDR_2                    GPIO_IDR_IDR_2
#define HYREL_GPIO_OTYPER_IDR_3                    GPIO_IDR_IDR_3
#define HYREL_GPIO_OTYPER_IDR_4                    GPIO_IDR_IDR_4
#define HYREL_GPIO_OTYPER_IDR_5                    GPIO_IDR_IDR_5
#define HYREL_GPIO_OTYPER_IDR_6                    GPIO_IDR_IDR_6
#define HYREL_GPIO_OTYPER_IDR_7                    GPIO_IDR_IDR_7
#define HYREL_GPIO_OTYPER_IDR_8                    GPIO_IDR_IDR_8
#define HYREL_GPIO_OTYPER_IDR_9                    GPIO_IDR_IDR_9
#define HYREL_GPIO_OTYPER_IDR_10                   GPIO_IDR_IDR_10
#define HYREL_GPIO_OTYPER_IDR_11                   GPIO_IDR_IDR_11
#define HYREL_GPIO_OTYPER_IDR_12                   GPIO_IDR_IDR_12
#define HYREL_GPIO_OTYPER_IDR_13                   GPIO_IDR_IDR_13
#define HYREL_GPIO_OTYPER_IDR_14                   GPIO_IDR_IDR_14
#define HYREL_GPIO_OTYPER_IDR_15                   GPIO_IDR_IDR_15

/******************  Bits definition for GPIO_ODR register  *******************/
#define HYREL_GPIO_ODR_ODR_0                       ((uint32_t)0x00000001)
#define HYREL_GPIO_ODR_ODR_1                       ((uint32_t)0x00000002)
#define HYREL_GPIO_ODR_ODR_2                       ((uint32_t)0x00000004)
#define HYREL_GPIO_ODR_ODR_3                       ((uint32_t)0x00000008)
#define HYREL_GPIO_ODR_ODR_4                       ((uint32_t)0x00000010)
#define HYREL_GPIO_ODR_ODR_5                       ((uint32_t)0x00000020)
#define HYREL_GPIO_ODR_ODR_6                       ((uint32_t)0x00000040)
#define HYREL_GPIO_ODR_ODR_7                       ((uint32_t)0x00000080)
#define HYREL_GPIO_ODR_ODR_8                       ((uint32_t)0x00000100)
#define HYREL_GPIO_ODR_ODR_9                       ((uint32_t)0x00000200)
#define HYREL_GPIO_ODR_ODR_10                      ((uint32_t)0x00000400)
#define HYREL_GPIO_ODR_ODR_11                      ((uint32_t)0x00000800)
#define HYREL_GPIO_ODR_ODR_12                      ((uint32_t)0x00001000)
#define HYREL_GPIO_ODR_ODR_13                      ((uint32_t)0x00002000)
#define HYREL_GPIO_ODR_ODR_14                      ((uint32_t)0x00004000)
#define HYREL_GPIO_ODR_ODR_15                      ((uint32_t)0x00008000)
/* Old GPIO_ODR register bits definition, maintained for legacy purpose */
#define HYREL_GPIO_OTYPER_ODR_0                    GPIO_ODR_ODR_0
#define HYREL_GPIO_OTYPER_ODR_1                    GPIO_ODR_ODR_1
#define HYREL_GPIO_OTYPER_ODR_2                    GPIO_ODR_ODR_2
#define HYREL_GPIO_OTYPER_ODR_3                    GPIO_ODR_ODR_3
#define HYREL_GPIO_OTYPER_ODR_4                    GPIO_ODR_ODR_4
#define HYREL_GPIO_OTYPER_ODR_5                    GPIO_ODR_ODR_5
#define HYREL_GPIO_OTYPER_ODR_6                    GPIO_ODR_ODR_6
#define HYREL_GPIO_OTYPER_ODR_7                    GPIO_ODR_ODR_7
#define HYREL_GPIO_OTYPER_ODR_8                    GPIO_ODR_ODR_8
#define HYREL_GPIO_OTYPER_ODR_9                    GPIO_ODR_ODR_9
#define HYREL_GPIO_OTYPER_ODR_10                   GPIO_ODR_ODR_10
#define HYREL_GPIO_OTYPER_ODR_11                   GPIO_ODR_ODR_11
#define HYREL_GPIO_OTYPER_ODR_12                   GPIO_ODR_ODR_12
#define HYREL_GPIO_OTYPER_ODR_13                   GPIO_ODR_ODR_13
#define HYREL_GPIO_OTYPER_ODR_14                   GPIO_ODR_ODR_14
#define HYREL_GPIO_OTYPER_ODR_15                   GPIO_ODR_ODR_15

/******************  Bits definition for GPIO_BSRR register  ******************/
#define HYREL_GPIO_BSRR_BS_0                       ((uint32_t)0x00000001)
#define HYREL_GPIO_BSRR_BS_1                       ((uint32_t)0x00000002)
#define HYREL_GPIO_BSRR_BS_2                       ((uint32_t)0x00000004)
#define HYREL_GPIO_BSRR_BS_3                       ((uint32_t)0x00000008)
#define HYREL_GPIO_BSRR_BS_4                       ((uint32_t)0x00000010)
#define HYREL_GPIO_BSRR_BS_5                       ((uint32_t)0x00000020)
#define HYREL_GPIO_BSRR_BS_6                       ((uint32_t)0x00000040)
#define HYREL_GPIO_BSRR_BS_7                       ((uint32_t)0x00000080)
#define HYREL_GPIO_BSRR_BS_8                       ((uint32_t)0x00000100)
#define HYREL_GPIO_BSRR_BS_9                       ((uint32_t)0x00000200)
#define HYREL_GPIO_BSRR_BS_10                      ((uint32_t)0x00000400)
#define HYREL_GPIO_BSRR_BS_11                      ((uint32_t)0x00000800)
#define HYREL_GPIO_BSRR_BS_12                      ((uint32_t)0x00001000)
#define HYREL_GPIO_BSRR_BS_13                      ((uint32_t)0x00002000)
#define HYREL_GPIO_BSRR_BS_14                      ((uint32_t)0x00004000)
#define HYREL_GPIO_BSRR_BS_15                      ((uint32_t)0x00008000)
#define HYREL_GPIO_BSRR_BR_0                       ((uint32_t)0x00010000)
#define HYREL_GPIO_BSRR_BR_1                       ((uint32_t)0x00020000)
#define HYREL_GPIO_BSRR_BR_2                       ((uint32_t)0x00040000)
#define HYREL_GPIO_BSRR_BR_3                       ((uint32_t)0x00080000)
#define HYREL_GPIO_BSRR_BR_4                       ((uint32_t)0x00100000)
#define HYREL_GPIO_BSRR_BR_5                       ((uint32_t)0x00200000)
#define HYREL_GPIO_BSRR_BR_6                       ((uint32_t)0x00400000)
#define HYREL_GPIO_BSRR_BR_7                       ((uint32_t)0x00800000)
#define HYREL_GPIO_BSRR_BR_8                       ((uint32_t)0x01000000)
#define HYREL_GPIO_BSRR_BR_9                       ((uint32_t)0x02000000)
#define HYREL_GPIO_BSRR_BR_10                      ((uint32_t)0x04000000)
#define HYREL_GPIO_BSRR_BR_11                      ((uint32_t)0x08000000)
#define HYREL_GPIO_BSRR_BR_12                      ((uint32_t)0x10000000)
#define HYREL_GPIO_BSRR_BR_13                      ((uint32_t)0x20000000)
#define HYREL_GPIO_BSRR_BR_14                      ((uint32_t)0x40000000)

/**
  * @brief General Purpose I/O
  */

typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint16_t BSRRL;    /*!< GPIO port bit set/reset low register,  Address offset: 0x18      */
  __IO uint16_t BSRRH;    /*!< GPIO port bit set/reset high register, Address offset: 0x1A      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} HYREL_GPIO_TypeDef;

/*!< AHB1 peripherals */
#define HYREL_GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define HYREL_GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define HYREL_GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define HYREL_GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
#define HYREL_GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)
#define HYREL_GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400UL)
#define HYREL_GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800UL)
#define HYREL_GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)
#define HYREL_GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000UL)

#define HYREL_GPIOA               ((HYREL_GPIO_TypeDef *) HYREL_GPIOA_BASE)
#define HYREL_GPIOB               ((HYREL_GPIO_TypeDef *) HYREL_GPIOB_BASE)
#define HYREL_GPIOC               ((HYREL_GPIO_TypeDef *) HYREL_GPIOC_BASE)
#define HYREL_GPIOD               ((HYREL_GPIO_TypeDef *) HYREL_GPIOD_BASE)
#define HYREL_GPIOE               ((HYREL_GPIO_TypeDef *) HYREL_GPIOE_BASE)
#define HYREL_GPIOF               ((HYREL_GPIO_TypeDef *) HYREL_GPIOF_BASE)
#define HYREL_GPIOG               ((HYREL_GPIO_TypeDef *) HYREL_GPIOG_BASE)
#define HYREL_GPIOH               ((HYREL_GPIO_TypeDef *) HYREL_GPIOH_BASE)
#define HYREL_GPIOI               ((HYREL_GPIO_TypeDef *) HYREL_GPIOI_BASE)

#define HYREL_IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == HYREL_GPIOA) || \
                                    ((PERIPH) == HYREL_GPIOB) || \
                                    ((PERIPH) == HYREL_GPIOC) || \
                                    ((PERIPH) == HYREL_GPIOD) || \
                                    ((PERIPH) == HYREL_GPIOE) || \
                                    ((PERIPH) == HYREL_GPIOF) || \
                                    ((PERIPH) == HYREL_GPIOG) || \
                                    ((PERIPH) == HYREL_GPIOH) || \
                                    ((PERIPH) == HYREL_GPIOI))




#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *   which reports the name of the source file and the source
  *   line number of the call that failed.
  *   If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */
