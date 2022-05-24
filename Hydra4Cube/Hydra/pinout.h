#ifndef pinout_HEADER // prevent double dipping
#define pinout_HEADER
////////////////////////////////////////////////////////////////////////////////
//
// File:    pinout.h
//
////////////////////////////////////////////////////////////////////////////////
//
// Purpose: Contains pinout specific defines, global references, and method prototypes
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2013  HYREL 3D, LLC.   All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////
//
// WARNING WARNING WARNING
//
// The STM32F4x series of parts powers on utilizing several pins for JTAG/SW debug
// Care should be take to not use these pins
//
//        PORT A[13] - JTMS/SWDIO    - AF0 - Input w/ pulldown
//        PORT A[14] - JTCK/SWCLK    - AF0 - Input w/ pulldown
//        PORT A[15] - JTDI          - AF0 - Input w/ pullup
//        PORT B[3]  - JTDO/TRACESWO - AF0 - Output pushpull at 50MHz
//        PORT B[4]  - NJTRST        - AF0 - Input w/ pullup
//
// Additionally, two other pins have limited drive (3ma) as they are special input
// to allow the connection of a low speed crystal oscilator and these pins need
// to have low parasitics (see spec)
//
//        PORT C[14]
//        PORT C[15]
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  pinout specific global defines and macros needed by other modules
////////////////////////////////////////////////////////////////////////////////
//#include "main.h"

#ifdef USE_HYDRA_IO

#ifdef NEW_CO2_LASER_CONTROL_MODULE // no 103 board at power supply; co2 laser lens used for soapstring, etc

CO2_LASER_USES HSS4
#define CO2_RTD         (ANALOG_FLOATING   | PIN_PORT_A | PIN_NUM_06)
#define CO2_TX3         (PIN_AF_USART3     | PIN_PORT_C | PIN_NUM_10)
#define CO2_RX3         (PIN_AF_USART3     | PIN_PORT_C | PIN_NUM_11)
#define SPI3_SPARE      (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_02) fix H2O_PROTECT
#define SPI3_MOSI       (PIN_AF_SPI3       | PIN_PORT_C | PIN_NUM_12) fix DOOR_INTERLOCK
#define SPI3_NSS_NOT    (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_04) fix
#define SPI3_CS         (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_05) fix

#else //!NEW_CO2_LASER_CONTROL_MODULE

#define AIN6_RTD        (ANALOG_FLOATING   | PIN_PORT_A | PIN_NUM_06)
#define SPI3_SCK        (PIN_AF_SPI3       | PIN_PORT_C | PIN_NUM_10)
#define SPI3_MISO       (PIN_AF_SPI3       | PIN_PORT_C | PIN_NUM_11)
#define SPI3_SPARE      (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_02)
#define SPI3_MOSI       (PIN_AF_SPI3       | PIN_PORT_C | PIN_NUM_12)
#define SPI3_NSS_NOT    (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_04)
#define SPI3_CS         (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_05)

#endif //!NEW_CO2_LASER_CONTROL_MODULE

#ifdef USE_AB_ENCODER
#define CO2_LASER_PWM   (PIN_AF_TIM2       | PIN_OTYPE_PUSHPULL | PIN_OSPEED_100MHZ | PIN_PORT_A | PIN_NUM_03 | PIN_INIT_HIGH)
#define PANEL_ENC_A     (INPUT_PULLUP      | PIN_PORT_A | PIN_NUM_00 | PIN_AF_TIM5)
#define PANEL_ENC_B     (INPUT_PULLUP      | PIN_PORT_A | PIN_NUM_01 | PIN_AF_TIM5)
#define PANEL_ENC_SEL   (INPUT_PULLUP      | PIN_PORT_A | PIN_NUM_04)

#else   // original defs (!USE_AB_ENCODER)

#define AIN3            (ANALOG_FLOATING   | PIN_PORT_A | PIN_NUM_03)
#define J19_10          (PIN_UNDEFINED     | PIN_PORT_A | PIN_NUM_00)  // undefined
#define CO2_LASER_PWM   (PIN_AF_TIM5       | PIN_OTYPE_PUSHPULL | PIN_OSPEED_100MHZ | PIN_PORT_A | PIN_NUM_01 | PIN_INIT_HIGH)
#define DAC1_OUT        (ANALOG_FLOATING   | PIN_PORT_A | PIN_NUM_04)

#endif  // !USE_AB_ENCODER

#ifdef USE_6_TO_ONE_SELECT

#define PANEL_SEL_0     (INPUT_PULLUP      | PIN_PORT_F | PIN_NUM_07)
#define PANEL_SEL_1     (INPUT_PULLUP      | PIN_PORT_F | PIN_NUM_08)
#define PANEL_SEL_2     (INPUT_PULLUP      | PIN_PORT_H | PIN_NUM_08)
#define PANEL_SEL_3     (INPUT_PULLUP      | PIN_PORT_H | PIN_NUM_10)
#define PANEL_SEL_4     (INPUT_PULLUP      | PIN_PORT_H | PIN_NUM_09)
#define PANEL_SEL_5     (INPUT_PULLUP      | PIN_PORT_H | PIN_NUM_11)

#else   // original defs (!USE_6_TO_ONE_SELECT)

#define AIN5            (ANALOG_FLOATING   | PIN_PORT_F | PIN_NUM_07)
#define AIN6            (ANALOG_FLOATING   | PIN_PORT_F | PIN_NUM_08)
#define J17_13          (PIN_UNDEFINED     | PIN_PORT_H | PIN_NUM_08)  // undefined
#define J17_14          (PIN_UNDEFINED     | PIN_PORT_H | PIN_NUM_10)  // undefined
#define J17_15          (PIN_UNDEFINED     | PIN_PORT_H | PIN_NUM_09)  // undefined
#define J17_16          (PIN_UNDEFINED     | PIN_PORT_H | PIN_NUM_11)  // undefined

#endif  // !USE_6_TO_ONE_SELECT

#ifdef ADD_ON_SPI_DISPLAY
#define PIN_LCD_CS      (OUTPUT_PP_50MHZ   | PIN_PORT_B | PIN_NUM_12 | PIN_INIT_HIGH)
#define PIN_LCD_SCK     (PIN_AF_SPI2       | PIN_PORT_B | PIN_NUM_13)
#define PIN_LCD_MISO    (PIN_AF_SPI2       | PIN_PORT_B | PIN_NUM_14)
#define PIN_LCD_RST     PIN_UNDEFINED
#define PIN_LCD_MOSI    (PIN_AF_SPI2       | PIN_PORT_B | PIN_NUM_15)
#define PIN_LCD_BKL     (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_08 | PIN_INIT_HIGH)
#define BB_ADDR_PIN_LCD_BKL		BIT_BAND(GPIOC_ODR_ADDR, 8)
#define PIN_LCD_D_CB    (OUTPUT_PP_50MHZ   | PIN_PORT_H | PIN_NUM_12)

#else // original defs (!ADD_ON_SPI_DISPLAY)
#define SPI2_NSS        (PIN_AF_SPI2       | PIN_PORT_B | PIN_NUM_12)
#define SPI2_SCK        (PIN_AF_SPI2       | PIN_PORT_B | PIN_NUM_13)
#define SPI2_MISO       (PIN_AF_SPI2       | PIN_PORT_B | PIN_NUM_14)
#define SPI2_MOSI       (PIN_AF_SPI2       | PIN_PORT_B | PIN_NUM_15)
#define SPI2_CS         (OUTPUT_PP_50MHZ   | PIN_PORT_H | PIN_NUM_12)
#define SPI2_SPARE      (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_08)
#define BB_PIN_LCD_BKL	NULL
#endif  // !ADD_ON_SPI_DISPLAY

#define A_DIR           (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_03)
#define A_FAULT         (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_04)
#define A_HOME          (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_05)
#define A_L1            (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_07)
#define A_L2            (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_06)
#define A_STEP          (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_07)
#define AIN7            (ANALOG_FLOATING   | PIN_PORT_F | PIN_NUM_09)
#define AIN8            (ANALOG_FLOATING   | PIN_PORT_F | PIN_NUM_10)
#define B_DIR           (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_02  | PIN_INIT_LOW)
#define B_FAULT         (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_11)
#define B_HOME          (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_10)
#define B_L1            (INPUT_PULLUP      | PIN_PORT_C | PIN_NUM_13)
#define B_L2            (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_09)
#define B_STEP          (OUTPUT_PP_50MHZ   | PIN_PORT_E | PIN_NUM_06 | PIN_INIT_LOW)
#define LATHE_STEP      (PIN_AF_TIM9       | PIN_OTYPE_PUSHPULL | PIN_OSPEED_100MHZ | PIN_PORT_E | PIN_NUM_06 | PIN_INIT_HIGH)
#define BOOT1           (PIN_UNDEFINED     | PIN_PORT_B | PIN_NUM_02)  // undefined
#define C_DIR           (OUTPUT_PP_50MHZ   | PIN_PORT_I | PIN_NUM_08)
#define C_FAULT         (INPUT_PULLUP      | PIN_PORT_E | PIN_NUM_05)
#define C_HOME          (INPUT_PULLUP      | PIN_PORT_E | PIN_NUM_04)
#define C_L1            (INPUT_PULLUP      | PIN_PORT_E | PIN_NUM_02)
#define C_L2            (INPUT_PULLUP      | PIN_PORT_E | PIN_NUM_03)
#define C_STEP          (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_00 | PIN_INIT_LOW)
#define CAN1_RX         (PIN_AF_CAN1       | PIN_PORT_B | PIN_NUM_08 | PIN_PUPPD_PULLUP)
#define CAN1_TX         (PIN_AF_CAN1       | PIN_PORT_B | PIN_NUM_09)
#define CAN2_RX         (PIN_AF_CAN2       | PIN_PORT_B | PIN_NUM_05 | PIN_PUPPD_PULLUP)
#define CAN2_TX         (PIN_AF_CAN2       | PIN_PORT_B | PIN_NUM_06)
#define DAC2_OUT        (ANALOG_FLOATING   | PIN_PORT_A | PIN_NUM_05)
#define DRAIN1          (OUTPUT_PP_50MHZ   | PIN_PORT_A | PIN_NUM_07)
#define DRAIN2          (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_04)
#define DRAIN3          (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_05)
#define DRAIN4          (OUTPUT_PP_50MHZ   | PIN_PORT_B | PIN_NUM_11)
#define CAN_TX_LED      (OUTPUT_PP_50MHZ   | PIN_PORT_F | PIN_NUM_06)
#define HEARTBEAT       (OUTPUT_PP_2MHZ    | PIN_PORT_C | PIN_NUM_03)
#define HSS_AUX_PWR1    (OUTPUT_PP_50MHZ   | PIN_PORT_H | PIN_NUM_15)
#define HSS_AUX_PWR2    (OUTPUT_PP_50MHZ   | PIN_PORT_H | PIN_NUM_13)
#define HSS_AUX_PWR4    (OUTPUT_PP_50MHZ   | PIN_PORT_H | PIN_NUM_14)
#define HSS_AUX_PWR5    (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_09)
#define HSS_AUX_PWR6    (OUTPUT_PP_50MHZ   | PIN_PORT_G | PIN_NUM_14)
#define HSS_AUX_PWR7    (OUTPUT_PP_50MHZ   | PIN_PORT_G | PIN_NUM_13)
#define HSS_AUX_PWR8    (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_01)
#define HSS_AUX_PWR9    (OUTPUT_PP_50MHZ   | PIN_PORT_A | PIN_NUM_02)
#define J18_13          (PIN_UNDEFINED     | PIN_PORT_B | PIN_NUM_01)  // undefined
#define J18_14          (PIN_UNDEFINED     | PIN_PORT_H | PIN_NUM_03)  // undefined
#define J18_15          (PIN_UNDEFINED     | PIN_PORT_H | PIN_NUM_04)  // undefined
#define J19_9           (PIN_UNDEFINED     | PIN_PORT_H | PIN_NUM_02)  // undefined
#define JTCK_SWCLK      (PIN_AF_SWJ        | PIN_PORT_A | PIN_NUM_14)
#define JTDI            (PIN_AF_SWJ        | PIN_PORT_A | PIN_NUM_15)
#define JTDO_SWO        (PIN_AF_SWJ        | PIN_PORT_B | PIN_NUM_03)
#define JTMS_SWDIO      (PIN_AF_SWJ        | PIN_PORT_A | PIN_NUM_13)
#define JTRST           (PIN_AF_SWJ        | PIN_PORT_B | PIN_NUM_04)
#define MOTOR_EN        (OUTPUT_PP_2MHZ    | PIN_PORT_D | PIN_NUM_11 | PIN_INIT_LOW)
#define NC_SPARE        (PIN_UNDEFINED     | PIN_PORT_B | PIN_NUM_10)  // undefined
#define OSC_IN          (PIN_UNDEFINED     | PIN_PORT_H | PIN_NUM_00)  // undefined
#define OSC_OUT         (PIN_UNDEFINED     | PIN_PORT_H | PIN_NUM_01)  // undefined
#define OSC32_IN        (ANALOG_FLOATING   | PIN_PORT_C | PIN_NUM_14)
#define OSC32_OUT       (ANALOG_FLOATING   | PIN_PORT_C | PIN_NUM_15)
#define OTG_FS_DM       (PIN_AF_OTG_FS     | PIN_OSPEED_100MHZ | PIN_PORT_A | PIN_NUM_11)
#define OTG_FS_DP       (PIN_AF_OTG_FS     | PIN_OSPEED_100MHZ | PIN_PORT_A | PIN_NUM_12)
#define OTG_FS_ID       (PIN_AF_OTG_FS     | PIN_OSPEED_100MHZ | PIN_PORT_A | PIN_NUM_10)
#define RX6             (PIN_AF_USART6     | PIN_PORT_C | PIN_NUM_07)
#define SDRAM_A0        (PIN_AF_FSMC       | PIN_PORT_F | PIN_NUM_00)
#define SDRAM_A1        (PIN_AF_FSMC       | PIN_PORT_F | PIN_NUM_01)
#define SDRAM_A10       (PIN_AF_FSMC       | PIN_PORT_G | PIN_NUM_00)
#define SDRAM_A11       (PIN_AF_FSMC       | PIN_PORT_G | PIN_NUM_01)
#define SDRAM_A2        (PIN_AF_FSMC       | PIN_PORT_F | PIN_NUM_02)
#define SDRAM_A3        (PIN_AF_FSMC       | PIN_PORT_F | PIN_NUM_03)
#define SDRAM_A4        (PIN_AF_FSMC       | PIN_PORT_F | PIN_NUM_04)
#define SDRAM_A5        (PIN_AF_FSMC       | PIN_PORT_F | PIN_NUM_05)
#define SDRAM_A6        (PIN_AF_FSMC       | PIN_PORT_F | PIN_NUM_12)
#define SDRAM_A7        (PIN_AF_FSMC       | PIN_PORT_F | PIN_NUM_13)
#define SDRAM_A8        (PIN_AF_FSMC       | PIN_PORT_F | PIN_NUM_14)
#define SDRAM_A9        (PIN_AF_FSMC       | PIN_PORT_F | PIN_NUM_15)
#define SDRAM_BA0       (PIN_AF_FSMC       | PIN_PORT_G | PIN_NUM_04)
#define SDRAM_BA1       (PIN_AF_FSMC       | PIN_PORT_G | PIN_NUM_05)
#define SDRAM_CLK       (PIN_AF_FSMC       | PIN_PORT_G | PIN_NUM_08)
#define SDRAM_D0        (PIN_AF_FSMC       | PIN_PORT_D | PIN_NUM_14)
#define SDRAM_D1        (PIN_AF_FSMC       | PIN_PORT_D | PIN_NUM_15)
#define SDRAM_D10       (PIN_AF_FSMC       | PIN_PORT_E | PIN_NUM_13)
#define SDRAM_D11       (PIN_AF_FSMC       | PIN_PORT_E | PIN_NUM_14)
#define SDRAM_D12       (PIN_AF_FSMC       | PIN_PORT_E | PIN_NUM_15)
#define SDRAM_D13       (PIN_AF_FSMC       | PIN_PORT_D | PIN_NUM_08)
#define SDRAM_D14       (PIN_AF_FSMC       | PIN_PORT_D | PIN_NUM_09)
#define SDRAM_D15       (PIN_AF_FSMC       | PIN_PORT_D | PIN_NUM_10)
#define SDRAM_D2        (PIN_AF_FSMC       | PIN_PORT_D | PIN_NUM_00)
#define SDRAM_D3        (PIN_AF_FSMC       | PIN_PORT_D | PIN_NUM_01)
#define SDRAM_D4        (PIN_AF_FSMC       | PIN_PORT_E | PIN_NUM_07)
#define SDRAM_D5        (PIN_AF_FSMC       | PIN_PORT_E | PIN_NUM_08)
#define SDRAM_D6        (PIN_AF_FSMC       | PIN_PORT_E | PIN_NUM_09)
#define SDRAM_D7        (PIN_AF_FSMC       | PIN_PORT_E | PIN_NUM_10)
#define SDRAM_D8        (PIN_AF_FSMC       | PIN_PORT_E | PIN_NUM_11)
#define SDRAM_D9        (PIN_AF_FSMC       | PIN_PORT_E | PIN_NUM_12)
#define SDRAM_NBL0      (PIN_AF_FSMC       | PIN_PORT_E | PIN_NUM_00)
#define SDRAM_NBL1      (PIN_AF_FSMC       | PIN_PORT_E | PIN_NUM_01)
#define SDRAM_SDCKE1    (PIN_AF_FSMC       | PIN_PORT_H | PIN_NUM_07)
#define SDRAM_SDNCAS    (PIN_AF_FSMC       | PIN_PORT_G | PIN_NUM_15)
#define SDRAM_SDNE1     (PIN_AF_FSMC       | PIN_PORT_H | PIN_NUM_06)
#define SDRAM_SDNRAS    (PIN_AF_FSMC       | PIN_PORT_F | PIN_NUM_11)
#define SDRAM_SDNWE     (PIN_AF_FSMC       | PIN_PORT_H | PIN_NUM_05)
#define START           (INPUT_PULLUP      | PIN_PORT_B | PIN_NUM_00)
#define TX6             (PIN_AF_USART6     | PIN_PORT_C | PIN_NUM_06)
#define X_DIR           (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_12)
#define X_FAULT         (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_02)
#define X_HOME          (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_03)
#define X_L1            (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_07)
#define X_L2            (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_06)
#define X_STEP          (OUTPUT_PP_50MHZ   | PIN_PORT_A | PIN_NUM_09)
#define Y_DIR           (OUTPUT_PP_50MHZ   | PIN_PORT_A | PIN_NUM_08)
#define Y_FAULT         (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_00)
#define Y_HOME          (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_01)
#define Y_L1            (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_03)
#define Y_L2            (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_02)
#define Y_STEP          (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_13)
#define Z_DIR           (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_06)
#define Z_FAULT         (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_09)
#define Z_HOME          (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_10)
#define Z_L1            (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_12)
#define Z_L2            (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_11)
#define Z_STEP          (OUTPUT_PP_50MHZ   | PIN_PORT_B | PIN_NUM_07)

#ifdef USE_PANEL_6TO1_IO_FOR_DEBUG_PINS

#if defined(USE_6_TO_ONE_SELECT)

#undef PANEL_SEL_0
#undef PANEL_SEL_1
#undef PANEL_SEL_2
#undef PANEL_SEL_3
#undef PANEL_SEL_4
#undef PANEL_SEL_5
#define PANEL_SEL_0     PIN_UNDEFINED
#define PANEL_SEL_1     PIN_UNDEFINED
#define PANEL_SEL_2     PIN_UNDEFINED
#define PANEL_SEL_3     PIN_UNDEFINED
#define PANEL_SEL_4     PIN_UNDEFINED
#define PANEL_SEL_5     PIN_UNDEFINED

#else   // original defs (!USE_6_TO_ONE_SELECT)

#undef AIN5
#undef AIN6
#undef J17_13
#undef J17_14
#undef J17_15
#undef J17_16
#define AIN5            PIN_UNDEFINED
#define AIN6            PIN_UNDEFINED
#define J17_13          PIN_UNDEFINED
#define J17_14          PIN_UNDEFINED
#define J17_15          PIN_UNDEFINED
#define J17_16          PIN_UNDEFINED

#endif  // !USE_6_TO_ONE_SELECT

#define GB_DEBUG_PIN1           (OUTPUT_PP_50MHZ      | PIN_PORT_F | PIN_NUM_07 | PIN_INIT_LOW)  // sel0
#define GB_DEBUG_PIN1_SET       (GPIOF->BSRRL = HYREL_GPIO_Pin_7)
#define GB_DEBUG_PIN1_CLEAR     (GPIOF->BSRRH = HYREL_GPIO_Pin_7)
#define GB_DEBUG_PIN1_READ      (GPIOF->IDR & HYREL_GPIO_Pin_7)
#define GB_DEBUG_PIN1_TOGGLE    {if (GB_DEBUG_PIN1_READ) {GB_DEBUG_PIN1_CLEAR;} else {GB_DEBUG_PIN1_SET;}}

#define GB_DEBUG_PIN2           (OUTPUT_PP_50MHZ      | PIN_PORT_F | PIN_NUM_08 | PIN_INIT_LOW)
#define GB_DEBUG_PIN2_SET       GPIOF->BSRRL = HYREL_GPIO_Pin_8
#define GB_DEBUG_PIN2_CLEAR     GPIOF->BSRRH = HYREL_GPIO_Pin_8

#define GB_DEBUG_PIN3           (OUTPUT_PP_50MHZ      | PIN_PORT_H | PIN_NUM_08 | PIN_INIT_LOW)
#define GB_DEBUG_PIN3_SET       GPIOH->BSRRL = HYREL_GPIO_Pin_8
#define GB_DEBUG_PIN3_CLEAR     GPIOH->BSRRH = HYREL_GPIO_Pin_8

#define GB_DEBUG_PIN4           (OUTPUT_PP_50MHZ      | PIN_PORT_H | PIN_NUM_10 | PIN_INIT_LOW)
#define GB_DEBUG_PIN4_SET       GPIOH->BSRRL = HYREL_GPIO_Pin_10
#define GB_DEBUG_PIN4_CLEAR     GPIOH->BSRRH = HYREL_GPIO_Pin_10

#define GB_DEBUG_PIN5           (OUTPUT_PP_50MHZ      | PIN_PORT_H | PIN_NUM_09 | PIN_INIT_LOW)
#define GB_DEBUG_PIN5_SET       GPIOH->BSRRL = HYREL_GPIO_Pin_9
#define GB_DEBUG_PIN5_CLEAR     GPIOH->BSRRH = HYREL_GPIO_Pin_9

#define GB_DEBUG_PIN6           (OUTPUT_PP_50MHZ      | PIN_PORT_H | PIN_NUM_11 | PIN_INIT_LOW) // sel5
#define GB_DEBUG_PIN6_SET       GPIOH->BSRRL = HYREL_GPIO_Pin_11
#define GB_DEBUG_PIN6_CLEAR     GPIOH->BSRRH = HYREL_GPIO_Pin_11


#else //!USE_PANEL_6TO1_IO_FOR_DEBUG_PINS

#define GB_DEBUG_PIN1 PIN_UNDEFINED
#define GB_DEBUG_PIN2 PIN_UNDEFINED
#define GB_DEBUG_PIN3 PIN_UNDEFINED
#define GB_DEBUG_PIN4 PIN_UNDEFINED
#define GB_DEBUG_PIN5 PIN_UNDEFINED
#define GB_DEBUG_PIN6 PIN_UNDEFINED

#endif //!USE_PANEL_6TO1_IO_FOR_DEBUG_PINS


#ifdef USE_PANEL_ABSEL_IO_FOR_DEBUG_PINS

#if defined(USE_AB_ENCODER)

#undef PANEL_ENC_A
#undef PANEL_ENC_B
#undef PANEL_ENC_SEL
#define PANEL_ENC_A     PIN_UNDEFINED
#define PANEL_ENC_B     PIN_UNDEFINED
#define PANEL_ENC_SEL   PIN_UNDEFINED

#else   // original defs (!USE_AB_ENCODER)

#undef J19_10
#undef CO2_LASER_PWM
#undef DAC1_OUT
#define J19_10          PIN_UNDEFINED
#define CO2_LASER_PWM   PIN_UNDEFINED
#define DAC1_OUT        PIN_UNDEFINED

#endif  // !USE_AB_ENCODER

#define GB_DEBUG_PIN7           (OUTPUT_PP_50MHZ      | PIN_PORT_A | PIN_NUM_00 | PIN_INIT_LOW) // a
#define GB_DEBUG_PIN7_SET       GPIOA->BSRRL = HYREL_GPIO_Pin_0
#define GB_DEBUG_PIN7_CLEAR     GPIOA->BSRRH = HYREL_GPIO_Pin_0

#define GB_DEBUG_PIN8           (OUTPUT_PP_50MHZ      | PIN_PORT_A | PIN_NUM_01 | PIN_INIT_LOW) // b
#define GB_DEBUG_PIN8_SET       GPIOA->BSRRL = HYREL_GPIO_Pin_1
#define GB_DEBUG_PIN8_CLEAR     GPIOA->BSRRH = HYREL_GPIO_Pin_1

#define GB_DEBUG_PIN9           (OUTPUT_PP_50MHZ      | PIN_PORT_A | PIN_NUM_04 | PIN_INIT_LOW) // s
#define GB_DEBUG_PIN9_SET       GPIOA->BSRRL = HYREL_GPIO_Pin_4
#define GB_DEBUG_PIN9_CLEAR     GPIOA->BSRRH = HYREL_GPIO_Pin_4


#else //!USE_PANEL_ABSEL_IO_FOR_DEBUG_PINS

#define GB_DEBUG_PIN7 PIN_UNDEFINED
#define GB_DEBUG_PIN8 PIN_UNDEFINED
#define GB_DEBUG_PIN9 PIN_UNDEFINED

#endif //!USE_PANEL_ABSEL_IO_FOR_DEBUG_PINS

#endif //USE_HYDRA_IO

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifdef USE_HYREL_IO

//we are making the ESR firmware run on the Hydra pcb
/*hydra   ESR
 * Dir	>>Dir
 * Step	>>step
 * Home	>>home
 * L1	>>EN
 * Fault>>Stall
 */

//X
#define X_DIR              (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_12) //(OUTPUT_PP_50MHZ  | PIN_PORT_C | PIN_NUM_15)
#define X_STEP             (OUTPUT_PP_50MHZ   | PIN_PORT_A | PIN_NUM_09)//(OUTPUT_PP_50MHZ  | PIN_PORT_A | PIN_NUM_02)
#define X_HOME             (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_03)//(INPUT_PULLUP     | PIN_PORT_E | PIN_NUM_06)
#define X_STALL            (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_02)//(INPUT_PULLUP     | PIN_PORT_C | PIN_NUM_13)
#define X_EN               (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_07)//
//
//#define X_DIR           (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_12)
//#define X_STEP          (OUTPUT_PP_50MHZ   | PIN_PORT_A | PIN_NUM_09)
//#define X_HOME          (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_03)
//#define X_FAULT         (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_02)
//#define X_L1            (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_07)
//#define X_L2            (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_06)    //spare

//
#define Y_DIR             (OUTPUT_PP_50MHZ   | PIN_PORT_A | PIN_NUM_08)//(OUTPUT_PP_50MHZ  | PIN_PORT_G | PIN_NUM_15)
#define Y_STEP            (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_13)//(OUTPUT_PP_50MHZ  | PIN_PORT_A | PIN_NUM_08)
#define Y_HOME            (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_01)//(INPUT_PULLUP     | PIN_PORT_C | PIN_NUM_03)
#define Y_STALL           (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_00)//(INPUT_PULLUP     | PIN_PORT_C | PIN_NUM_02)
#define Y_EN              (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_03)//(OUTPUT_PP_50MHZ  | PIN_PORT_G | PIN_NUM_13)
//
//#define Y_DIR           (OUTPUT_PP_50MHZ   | PIN_PORT_A | PIN_NUM_08)
//#define Y_STEP          (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_13)
//#define Y_HOME          (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_01)
//#define Y_FAULT         (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_00)
//#define Y_L1            (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_03)
//#define Y_L2            (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_02)

//
#define Z_DIR              (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_06)// (OUTPUT_PP_50MHZ  | PIN_PORT_F | PIN_NUM_08)
#define Z_STEP             (OUTPUT_PP_50MHZ   | PIN_PORT_B | PIN_NUM_07)// (OUTPUT_PP_50MHZ  | PIN_PORT_A | PIN_NUM_10)
#define Z_HOME             (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_10)// (INPUT_PULLUP     | PIN_PORT_G | PIN_NUM_10)
#define Z_STALL            (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_09)// (INPUT_PULLUP     | PIN_PORT_F | PIN_NUM_04)
#define Z_EN               (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_12)// (OUTPUT_PP_50MHZ  | PIN_PORT_F | PIN_NUM_06)
//
//#define Z_DIR           (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_06)
//#define Z_STEP          (OUTPUT_PP_50MHZ   | PIN_PORT_B | PIN_NUM_07)
//#define Z_HOME          (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_10)
//#define Z_FAULT         (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_09)
//#define Z_L1            (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_12)
//#define Z_L2            (INPUT_PULLUP      | PIN_PORT_G | PIN_NUM_11)


//
#define W_DIR              (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_03)// (OUTPUT_PP_50MHZ  | PIN_PORT_G | PIN_NUM_11)
#define W_STEP             (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_07)// (OUTPUT_PP_50MHZ  | PIN_PORT_A | PIN_NUM_03)
#define W_HOME             (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_05)//(INPUT_PULLUP     | PIN_PORT_G | PIN_NUM_14)
#define W_STALL            (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_04)// (INPUT_PULLUP     | PIN_PORT_E | PIN_NUM_00)
#define W_EN               (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_07)// (OUTPUT_PP_50MHZ  | PIN_PORT_G | PIN_NUM_12)
//
//#define A_DIR           (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_03)
//#define A_STEP          (OUTPUT_PP_50MHZ   | PIN_PORT_D | PIN_NUM_07)
//#define A_HOME          (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_05)
//#define A_FAULT         (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_04)
//#define A_L1            (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_07)
//#define A_L2            (INPUT_PULLUP      | PIN_PORT_I | PIN_NUM_06)
//

#define X_HSS1             (OUTPUT_PP_50MHZ   | PIN_PORT_H | PIN_NUM_15)// (OUTPUT_PP_50MHZ  | PIN_PORT_E | PIN_NUM_02) // goes to "LED" input on switch panel
#define X_HSS2             (OUTPUT_PP_50MHZ   | PIN_PORT_H | PIN_NUM_13)// (OUTPUT_PP_50MHZ  | PIN_PORT_E | PIN_NUM_03)
#define Y_HSS1             (OUTPUT_PP_50MHZ   | PIN_PORT_H | PIN_NUM_14)// (OUTPUT_PP_50MHZ  | PIN_PORT_F | PIN_NUM_09)
#define Y_HSS2             (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_09)// (OUTPUT_PP_50MHZ  | PIN_PORT_F | PIN_NUM_10)
#define Z_HSS1             (OUTPUT_PP_50MHZ   | PIN_PORT_G | PIN_NUM_14)// (OUTPUT_PP_50MHZ  | PIN_PORT_F | PIN_NUM_01) // goes to ALRAM (buzzer) on switch panel
#define Z_HSS2             (OUTPUT_PP_50MHZ   | PIN_PORT_G | PIN_NUM_13)// (OUTPUT_PP_50MHZ  | PIN_PORT_F | PIN_NUM_00)
#define W_HSS1             (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_01)// (OUTPUT_PP_50MHZ  | PIN_PORT_E | PIN_NUM_01)
#define W_HSS2             (OUTPUT_PP_50MHZ   | PIN_PORT_A | PIN_NUM_02)//(OUTPUT_PP_50MHZ  | PIN_PORT_B | PIN_NUM_07)
//
//#define HSS_AUX_PWR1    (OUTPUT_PP_50MHZ   | PIN_PORT_H | PIN_NUM_15)
//#define HSS_AUX_PWR2    (OUTPUT_PP_50MHZ   | PIN_PORT_H | PIN_NUM_13)
//#define HSS_AUX_PWR4    (OUTPUT_PP_50MHZ   | PIN_PORT_H | PIN_NUM_14)
//#define HSS_AUX_PWR5    (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_09)
//#define HSS_AUX_PWR6    (OUTPUT_PP_50MHZ   | PIN_PORT_G | PIN_NUM_14)
//#define HSS_AUX_PWR7    (OUTPUT_PP_50MHZ   | PIN_PORT_G | PIN_NUM_13)
//#define HSS_AUX_PWR8    (OUTPUT_PP_50MHZ   | PIN_PORT_C | PIN_NUM_01)
//#define HSS_AUX_PWR9    (OUTPUT_PP_50MHZ   | PIN_PORT_A | PIN_NUM_02)
//


#define Z_HOME1             (INPUT_PULLUP     | PIN_PORT_G | PIN_NUM_10)
#define Z_HOME2             (INPUT_PULLUP     | PIN_PORT_G | PIN_NUM_09)
#define Z_HOME3             (INPUT_PULLUP     | PIN_PORT_D | PIN_NUM_06)
#define Z_HOME4             (INPUT_PULLUP     | PIN_PORT_D | PIN_NUM_03)
#define Z_HOME5             (INPUT_PULLUP     | PIN_PORT_G | PIN_NUM_06)



#define START               (INPUT_PULLUP      | PIN_PORT_B | PIN_NUM_00)// (INPUT_PULLUP    | PIN_PORT_F | PIN_NUM_05)
//#define START           (INPUT_PULLUP      | PIN_PORT_B | PIN_NUM_00)

#define HEARTBEAT           (OUTPUT_PP_50MHZ   | PIN_PORT_F | PIN_NUM_06)//(OUTPUT_PP_50MHZ  | PIN_PORT_F | PIN_NUM_15)
//#define HEARTBEAT       (OUTPUT_PP_2MHZ    | PIN_PORT_C | PIN_NUM_03)

#define CAN_TX_LED          (OUTPUT_PP_50MHZ   | PIN_PORT_F | PIN_NUM_06)// (OUTPUT_PP_50MHZ | PIN_PORT_G | PIN_NUM_01)
//#define CAN_TX_LED      (OUTPUT_PP_50MHZ   | PIN_PORT_F | PIN_NUM_06)

//

#define CAN1_RX             (PIN_AF_CAN1      | PIN_PORT_B | PIN_NUM_08 | PIN_PUPPD_PULLUP)
#define CAN1_TX             (PIN_AF_CAN1      | PIN_PORT_B | PIN_NUM_09)

#define UART3_RX            (PIN_AF_USART3    | PIN_PORT_B | PIN_NUM_11)
#define UART3_TX            (PIN_AF_USART3    | PIN_PORT_B | PIN_NUM_10)

#define UART4_RX            (PIN_AF_UART4     | PIN_PORT_A | PIN_NUM_01)
#define UART4_TX            (PIN_AF_UART4     | PIN_PORT_A | PIN_NUM_00)

#define UART6_RX            (PIN_AF_USART6    | PIN_PORT_C | PIN_NUM_07)
#define UART6_TX            (PIN_AF_USART6    | PIN_PORT_C | PIN_NUM_06)

#define W_RTD2             (INPUT_PULLUP     | PIN_PORT_C | PIN_NUM_04)
#define W_RTD1              (INPUT_PULLUP     | PIN_PORT_G | PIN_NUM_00)

#define HIGHLOWSPEED        (OUTPUT_PP_50MHZ  | PIN_PORT_C | PIN_NUM_09)
#define SPINDLECOOLANT      (OUTPUT_PP_50MHZ  | PIN_PORT_C | PIN_NUM_12)
#define LATHE_STEP          (PIN_AF_TIM9       | PIN_OTYPE_PUSHPULL | PIN_OSPEED_100MHZ | PIN_PORT_A | PIN_NUM_03 | PIN_INIT_HIGH)


#define OTG_FS_DM           (PIN_AF_OTG_FS     | PIN_PORT_A | PIN_NUM_11) //J20_P3 DO NOT USE UNLESS USB IS NOT USED
#define OTG_FS_DP           (PIN_AF_OTG_FS     | PIN_PORT_A | PIN_NUM_12) //J20_P1 DO NOT USE UNLESS USB IS NOT USED
//#define OTG_FS_ID           (PIN_AF_OTG_FS     | PIN_PORT_A | PIN_NUM_10) -- lost pin to Z_STEP
// DEFINED BUT NOT USED !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#define DRAWBAR             (OUTPUT_PP_50MHZ  | PIN_PORT_C | PIN_NUM_08)
#define RELAY7              (OUTPUT_PP_50MHZ  | PIN_PORT_C | PIN_NUM_10)
#define RELAY8              (OUTPUT_PP_50MHZ  | PIN_PORT_C | PIN_NUM_11)



#define NI_LCD_WR           (OUTPUT_PP_50MHZ  | PIN_PORT_D | PIN_NUM_05)
#define NI_LCD_CS           (OUTPUT_PP_50MHZ  | PIN_PORT_D | PIN_NUM_07)
#define NI_LCD_RS           (OUTPUT_PP_50MHZ  | PIN_PORT_D | PIN_NUM_11)
#define NI_BL_CNT           (INPUT_FLOATING   | PIN_PORT_D | PIN_NUM_02)
#define NI_TP_CS            (OUTPUT_PP_50MHZ  | PIN_PORT_D | PIN_NUM_13)
#define NI_TP_IRQ           (INPUT_PULLUP     | PIN_PORT_D | PIN_NUM_12)

#define NI_X_ENCB           (INPUT_PULLUP     | PIN_PORT_E | PIN_NUM_04)
#define NI_X_ENCA           (INPUT_PULLUP     | PIN_PORT_E | PIN_NUM_05)
#define NI_Y_ENCB           (INPUT_PULLUP     | PIN_PORT_C | PIN_NUM_00)
#define NI_Y_ENCA           (INPUT_PULLUP     | PIN_PORT_C | PIN_NUM_01)
#define NI_Z_Q2             (INPUT_PULLUP     | PIN_PORT_F | PIN_NUM_02)     // Z_ENCB
#define NI_Z_Q1             (INPUT_PULLUP     | PIN_PORT_F | PIN_NUM_03)     // Z_ENCA

//#define CAN2_RX             (PIN_PUPPD_PULLUP   | PIN_PORT_B | PIN_NUM_05)
//#define CAN2_TX             (OUTPUT_PP_50MHZ  | PIN_PORT_B | PIN_NUM_06 | PIN_INIT_HIGH)
#define CAN2_RX             (PIN_AF_CAN2      | PIN_PORT_B | PIN_NUM_05 | PIN_PUPPD_PULLUP)
#define CAN2_TX             (PIN_AF_CAN2      | PIN_PORT_B | PIN_NUM_06)

#define NI_SPI2_SCK         (OUTPUT_PP_50MHZ  | PIN_PORT_B | PIN_NUM_13)    // XXX NEEDS AF TO USE
#define NI_SPI2_MISO        (INPUT_FLOATING   | PIN_PORT_B | PIN_NUM_14)    // XXX NEEDS AF TO USE
#define NI_SPI2_SS_SDCARD   (INPUT_FLOATING   | PIN_PORT_B | PIN_NUM_12)    // XXX NEEDS AF TO USE
#define NI_SPI2_MOSI        (INPUT_FLOATING   | PIN_PORT_B | PIN_NUM_15)    // XXX NEEDS AF TO USE

#define NI_VCO1_CNTRL       (INPUT_FLOATING   | PIN_PORT_A | PIN_NUM_04)     //AF DAC1_OUT
#define NI_VCO1_FREQ        (INPUT_PULLUP     | PIN_PORT_A | PIN_NUM_06)
#define NI_VCO2_CNTRL       (INPUT_FLOATING   | PIN_PORT_X | PIN_NUM_05)     //AF DAC2_OUT PA5_Dac_Channel2
#define NI_VCO2_FREQ        (INPUT_FLOATING   | PIN_PORT_A | PIN_NUM_07)     //AF TIM14_CH1 FREQ1_PA7

// Avoid using the following JTAG pins as it will interfere with using the ST-LINK/debugger.  if USBOTG is not used,
// the it is possible to reuse A12
#define NI_J20_P2           (INPUT_FLOATING   | PIN_PORT_A | PIN_NUM_13)    //J20_20 DO NOT USE -- JTMS/SWDIO
#define NI_JTCK_SWCLK       (INPUT_FLOATING   | PIN_PORT_A | PIN_NUM_14)    //J21_P5 DO NOT USE -- JTCK/SWCLK
#define NI_J21_P8           (INPUT_FLOATING   | PIN_PORT_A | PIN_NUM_15)    //J21_P8 DO NOT USE -- JTDI
#define NI_JTDO_TRACESWO    (INPUT_FLOATING   | PIN_PORT_B | PIN_NUM_03)     //JTAG/TRACESO - DO NOT USE
#define NI_JTRST            (INPUT_FLOATING   | PIN_PORT_B | PIN_NUM_04)     //JTRST - DO NOT USE

#define NI_J13_P1           (INPUT_FLOATING   | PIN_PORT_B | PIN_NUM_00)
#define NI_J13_P2           (INPUT_FLOATING   | PIN_PORT_C | PIN_NUM_05)
#define NI_J13_P3           (INPUT_FLOATING   | PIN_PORT_B | PIN_NUM_02)
#define NI_J13_P4           (INPUT_FLOATING   | PIN_PORT_B | PIN_NUM_01)
#define J13_P6              (INPUT_PULLUP     | PIN_PORT_F | PIN_NUM_11)    // RTD_CALIBRATION_DATA_BIT
#define NI_J13_P5           (INPUT_FLOATING   | PIN_PORT_F | PIN_NUM_12)
#define J13_P8              (OUTPUT_PP_50MHZ  | PIN_PORT_F | PIN_NUM_13)    // RTD_CALIBRATION_CSB
#define J13_P7              (OUTPUT_PP_50MHZ  | PIN_PORT_F | PIN_NUM_14)    // RTD_CALIBRATION_CLOCK

#define NI_J14_P35          (INPUT_FLOATING   | PIN_PORT_G | PIN_NUM_07)
#define NI_J14_P36          (INPUT_FLOATING   | PIN_PORT_G | PIN_NUM_08)
#define NI_J14_P37          (INPUT_FLOATING   | PIN_PORT_G | PIN_NUM_05)
#define NI_J14_P38          (INPUT_FLOATING   | PIN_PORT_G | PIN_NUM_03)
#define NI_J14_P39          (INPUT_FLOATING   | PIN_PORT_G | PIN_NUM_04)
#define NI_J14_P40          (INPUT_FLOATING   | PIN_PORT_G | PIN_NUM_02)

#define NI_J21_P5           (INPUT_FLOATING   | PIN_PORT_A | PIN_NUM_09)

#define NI_FSMC_D0          (INPUT_FLOATING   | PIN_PORT_D | PIN_NUM_14)
#define NI_FSMC_D1          (INPUT_FLOATING   | PIN_PORT_D | PIN_NUM_15)
#define NI_FSMC_D2          (INPUT_FLOATING   | PIN_PORT_D | PIN_NUM_00)
#define NI_FSMC_D3          (INPUT_FLOATING   | PIN_PORT_D | PIN_NUM_01)
#define NI_FSMC_D4          (INPUT_FLOATING   | PIN_PORT_E | PIN_NUM_07)
#define NI_FSMC_D5          (INPUT_FLOATING   | PIN_PORT_E | PIN_NUM_08)
#define NI_FSMC_D6          (INPUT_FLOATING   | PIN_PORT_E | PIN_NUM_09)
#define NI_FSMC_D7          (INPUT_FLOATING   | PIN_PORT_E | PIN_NUM_10)
#define NI_FSMC_D8          (INPUT_FLOATING   | PIN_PORT_E | PIN_NUM_11)
#define NI_FSMC_D9          (INPUT_FLOATING   | PIN_PORT_E | PIN_NUM_12)
#define NI_FSMC_D10         (INPUT_FLOATING   | PIN_PORT_E | PIN_NUM_13)
#define NI_FSMC_D11         (INPUT_FLOATING   | PIN_PORT_E | PIN_NUM_14)
#define NI_FSMC_D12         (INPUT_FLOATING   | PIN_PORT_E | PIN_NUM_15)
#define NI_FSMC_D13         (INPUT_FLOATING   | PIN_PORT_D | PIN_NUM_08)
#define NI_FSMC_D14         (INPUT_FLOATING   | PIN_PORT_D | PIN_NUM_09)
#define NI_FSMC_D15         (INPUT_FLOATING   | PIN_PORT_D | PIN_NUM_10)

#define CO2_LASER_PWM PIN_UNDEFINED

//============= GB XXX stuck in here for testing of code in prep for 429
#define A_HOME W_HOME
#define A_STEP W_STEP
#define A_EN W_EN
#define A_DIR W_DIR
#define A_STALL W_STALL

#define B_HOME PIN_UNDEFINED
#define B_STEP PIN_UNDEFINED
#define B_EN PIN_UNDEFINED
#define B_DIR PIN_UNDEFINED
#define B_STALL PIN_UNDEFINED
#define C_HOME PIN_UNDEFINED
#define C_STEP PIN_UNDEFINED
#define C_EN PIN_UNDEFINED
#define C_DIR PIN_UNDEFINED
#define C_STALL PIN_UNDEFINED
#define C_L1 PIN_UNDEFINED
#define C_L2 PIN_UNDEFINED

#endif //USE_HYREL_IO

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifdef MEGASONIC_HYDRA
#define HEARTBEAT           (OUTPUT_PP_50MHZ  | PIN_PORT_E | PIN_NUM_03 | PIN_INIT_LOW)
#define CAN_TX_LED           (OUTPUT_PP_50MHZ  | PIN_PORT_E | PIN_NUM_04 | PIN_INIT_LOW)
#define CAN_RX_LED           (OUTPUT_PP_50MHZ  | PIN_PORT_G | PIN_NUM_09 | PIN_INIT_LOW)

#define CAN1_RX         (PIN_AF_CAN1       | PIN_PORT_B | PIN_NUM_08 | PIN_PUPPD_PULLUP)
#define CAN1_TX         (PIN_AF_CAN1       | PIN_PORT_B | PIN_NUM_09)
//#define CAN1_RX             PIN_UNDEFINED //(PIN_AF_CAN1      | PIN_PORT_A | PIN_NUM_11 | PIN_PUPPD_PULLUP)
//#define CAN1_TX             PIN_UNDEFINED //(PIN_AF_CAN1      | PIN_PORT_A | PIN_NUM_12 | PIN_MODE_AF | PIN_OTYPE_PUSHPULL | PIN_OSPEED_100MHZ)

#define CAN2_RX         (PIN_AF_CAN2       | PIN_PORT_B | PIN_NUM_12 | PIN_PUPPD_PULLUP)
#define CAN2_TX         (PIN_AF_CAN2       | PIN_PORT_B | PIN_NUM_13)

#define OTG_FS_DM       (PIN_AF_OTG_FS     | PIN_OSPEED_100MHZ | PIN_PORT_A | PIN_NUM_11)
#define OTG_FS_DP       (PIN_AF_OTG_FS     | PIN_OSPEED_100MHZ | PIN_PORT_A | PIN_NUM_12)

#define A_DIR           PIN_UNDEFINED
#define A_FAULT         PIN_UNDEFINED
#define A_HOME          PIN_UNDEFINED
#define A_L1            PIN_UNDEFINED
#define A_L2            PIN_UNDEFINED
#define A_STEP          PIN_UNDEFINED
#define AIN3            PIN_UNDEFINED
#define AIN5            PIN_UNDEFINED
#define AIN6            PIN_UNDEFINED
#define AIN6_RTD        PIN_UNDEFINED
#define AIN7            PIN_UNDEFINED
#define AIN8            PIN_UNDEFINED
#define B_DIR           PIN_UNDEFINED
#define B_FAULT         PIN_UNDEFINED
#define B_HOME          PIN_UNDEFINED
#define B_L1            PIN_UNDEFINED
#define B_L2            PIN_UNDEFINED
#define B_STEP          PIN_UNDEFINED
#define LATHE_STEP      PIN_UNDEFINED
#define BOOT1           PIN_UNDEFINED  // undefined
#define C_DIR           PIN_UNDEFINED
#define C_FAULT         PIN_UNDEFINED
#define C_HOME          PIN_UNDEFINED
#define C_L1            PIN_UNDEFINED
#define C_L2            PIN_UNDEFINED
#define C_STEP          PIN_UNDEFINED

#define CO2_LASER_PWM   PIN_UNDEFINED
#define DAC1_OUT        PIN_UNDEFINED
#define DAC2_OUT        PIN_UNDEFINED
#define DRAIN1          PIN_UNDEFINED
#define DRAIN2          PIN_UNDEFINED
#define DRAIN3          PIN_UNDEFINED
#define DRAIN4          PIN_UNDEFINED

#define HSS_AUX_PWR1    PIN_UNDEFINED
#define HSS_AUX_PWR2    PIN_UNDEFINED
#define HSS_AUX_PWR4    PIN_UNDEFINED
#define HSS_AUX_PWR5    PIN_UNDEFINED
#define HSS_AUX_PWR6    PIN_UNDEFINED
#define HSS_AUX_PWR7    PIN_UNDEFINED
#define HSS_AUX_PWR8    PIN_UNDEFINED
#define HSS_AUX_PWR9    PIN_UNDEFINED
#define J17_13          PIN_UNDEFINED  // undefined
#define J17_14          PIN_UNDEFINED  // undefined
#define J17_15          PIN_UNDEFINED  // undefined
#define J17_16          PIN_UNDEFINED  // undefined
#define J18_13          PIN_UNDEFINED  // undefined
#define J18_14          PIN_UNDEFINED  // undefined
#define J18_15          PIN_UNDEFINED  // undefined
#define J19_10          PIN_UNDEFINED  // undefined
#define J19_9           PIN_UNDEFINED  // undefined
#define JTCK_SWCLK      PIN_UNDEFINED
#define JTDI            PIN_UNDEFINED
#define JTDO_SWO        PIN_UNDEFINED
#define JTMS_SWDIO      PIN_UNDEFINED
#define JTRST           PIN_UNDEFINED
#define MOTOR_EN        PIN_UNDEFINED
#define NC_SPARE        PIN_UNDEFINED  // undefined
#define OSC_IN          PIN_UNDEFINED  // undefined
#define OSC_OUT         PIN_UNDEFINED  // undefined
#define OSC32_IN        PIN_UNDEFINED
#define OSC32_OUT       PIN_UNDEFINED

#define OTG_FS_ID       PIN_UNDEFINED
#define RX6             PIN_UNDEFINED
#define SDRAM_A0        PIN_UNDEFINED
#define SDRAM_A1        PIN_UNDEFINED
#define SDRAM_A10       PIN_UNDEFINED
#define SDRAM_A11       PIN_UNDEFINED
#define SDRAM_A2        PIN_UNDEFINED
#define SDRAM_A3        PIN_UNDEFINED
#define SDRAM_A4        PIN_UNDEFINED
#define SDRAM_A5        PIN_UNDEFINED
#define SDRAM_A6        PIN_UNDEFINED
#define SDRAM_A7        PIN_UNDEFINED
#define SDRAM_A8        PIN_UNDEFINED
#define SDRAM_A9        PIN_UNDEFINED
#define SDRAM_BA0       PIN_UNDEFINED
#define SDRAM_BA1       PIN_UNDEFINED
#define SDRAM_CLK       PIN_UNDEFINED
#define SDRAM_D0        PIN_UNDEFINED
#define SDRAM_D1        PIN_UNDEFINED
#define SDRAM_D10       PIN_UNDEFINED
#define SDRAM_D11       PIN_UNDEFINED
#define SDRAM_D12       PIN_UNDEFINED
#define SDRAM_D13       PIN_UNDEFINED
#define SDRAM_D14       PIN_UNDEFINED
#define SDRAM_D15       PIN_UNDEFINED
#define SDRAM_D2        PIN_UNDEFINED
#define SDRAM_D3        PIN_UNDEFINED
#define SDRAM_D4        PIN_UNDEFINED
#define SDRAM_D5        PIN_UNDEFINED
#define SDRAM_D6        PIN_UNDEFINED
#define SDRAM_D7        PIN_UNDEFINED
#define SDRAM_D8        PIN_UNDEFINED
#define SDRAM_D9        PIN_UNDEFINED
#define SDRAM_NBL0      PIN_UNDEFINED
#define SDRAM_NBL1      PIN_UNDEFINED
#define SDRAM_SDCKE1    PIN_UNDEFINED
#define SDRAM_SDNCAS    PIN_UNDEFINED
#define SDRAM_SDNE1     PIN_UNDEFINED
#define SDRAM_SDNRAS    PIN_UNDEFINED
#define SDRAM_SDNWE     PIN_UNDEFINED
#define SPI2_CS         PIN_UNDEFINED
#define SPI2_MISO       PIN_UNDEFINED
#define SPI2_MOSI       PIN_UNDEFINED
#define SPI2_NSS        PIN_UNDEFINED
#define SPI2_SCK        PIN_UNDEFINED
#define SPI2_SPARE      PIN_UNDEFINED
#define SPI3_CS         PIN_UNDEFINED
#define SPI3_MISO       PIN_UNDEFINED
#define SPI3_MOSI       PIN_UNDEFINED
#define SPI3_NSS_NOT    PIN_UNDEFINED
#define SPI3_SCK        PIN_UNDEFINED
#define SPI3_SPARE      PIN_UNDEFINED
#define START           PIN_UNDEFINED
#define TX6             PIN_UNDEFINED
#define X_DIR           PIN_UNDEFINED
#define X_FAULT         PIN_UNDEFINED
#define X_HOME          PIN_UNDEFINED
#define X_L1            PIN_UNDEFINED
#define X_L2            PIN_UNDEFINED
#define X_STEP          PIN_UNDEFINED
#define Y_DIR           PIN_UNDEFINED
#define Y_FAULT         PIN_UNDEFINED
#define Y_HOME          PIN_UNDEFINED
#define Y_L1            PIN_UNDEFINED
#define Y_L2            PIN_UNDEFINED
#define Y_STEP          PIN_UNDEFINED
#define Z_DIR           PIN_UNDEFINED
#define Z_FAULT         PIN_UNDEFINED
#define Z_HOME          PIN_UNDEFINED
#define Z_L1            PIN_UNDEFINED
#define Z_L2            PIN_UNDEFINED
#define Z_STEP          PIN_UNDEFINED
#endif //MEGASONIC_HYDRA

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifdef MEGASONIC_HYREL
#define HEARTBEAT           (OUTPUT_PP_50MHZ  | PIN_PORT_E | PIN_NUM_03 | PIN_INIT_LOW)
#define CAN_TX_LED           (OUTPUT_PP_50MHZ  | PIN_PORT_E | PIN_NUM_04 | PIN_INIT_LOW)
#define CAN_RX_LED           (OUTPUT_PP_50MHZ  | PIN_PORT_G | PIN_NUM_09 | PIN_INIT_LOW)

#define CAN1_RX             (PIN_AF_CAN1      | PIN_PORT_A | PIN_NUM_11 | PIN_PUPPD_PULLUP)
#define CAN1_TX             (PIN_AF_CAN1      | PIN_PORT_A | PIN_NUM_12 | PIN_MODE_AF | PIN_OTYPE_PUSHPULL | PIN_OSPEED_100MHZ)

#define OTG_FS_DM           PIN_UNDEFINED //(PIN_AF_OTG_FS     | PIN_PORT_A | PIN_NUM_11)
#define OTG_FS_DP           PIN_UNDEFINED //(PIN_AF_OTG_FS     | PIN_PORT_A | PIN_NUM_12)

///////////
#define W_EN                PIN_UNDEFINED
#define W_DIR               PIN_UNDEFINED
#define W_STEP              PIN_UNDEFINED
#define LATHE_STEP          PIN_UNDEFINED
#define W_HSS1              PIN_UNDEFINED
#define W_HSS2              PIN_UNDEFINED
#define W_HOME              PIN_UNDEFINED
#define W_STALL             PIN_UNDEFINED

#define X_EN                PIN_UNDEFINED
#define X_DIR               PIN_UNDEFINED
#define X_STEP              PIN_UNDEFINED
#define X_HSS1              PIN_UNDEFINED // goes to "LED" input on switch panel
#define X_HSS2              PIN_UNDEFINED
#define X_HOME              PIN_UNDEFINED
#define X_STALL             PIN_UNDEFINED

#define Y_EN                PIN_UNDEFINED
#define Y_DIR               PIN_UNDEFINED
#define Y_STEP              PIN_UNDEFINED
#define Y_HSS1              PIN_UNDEFINED
#define Y_HSS2              PIN_UNDEFINED
#define Y_STALL             PIN_UNDEFINED
#define Y_HOME              PIN_UNDEFINED

#define Z_STEP              PIN_UNDEFINED
#define Z_DIR               PIN_UNDEFINED
#define Z_EN                PIN_UNDEFINED
#define Z_HSS1              PIN_UNDEFINED
#define Z_HSS2              PIN_UNDEFINED
#define Z_STALL             PIN_UNDEFINED

#define START               PIN_UNDEFINED
#define Z_HOME              PIN_UNDEFINED
#define Z_HOME1             PIN_UNDEFINED
#define Z_HOME2             PIN_UNDEFINED
#define Z_HOME3             PIN_UNDEFINED
#define Z_HOME4             PIN_UNDEFINED
#define Z_HOME5             PIN_UNDEFINED

#define CAN2_RX             PIN_UNDEFINED
#define CAN2_TX             PIN_UNDEFINED

#define UART3_RX            PIN_UNDEFINED
#define UART3_TX            PIN_UNDEFINED
#define UART4_RX            PIN_UNDEFINED
#define UART4_TX            PIN_UNDEFINED
#define UART6_RX            PIN_UNDEFINED
#define UART6_TX            PIN_UNDEFINED

#define W_RTD2             PIN_UNDEFINED
#define W_RTD1              PIN_UNDEFINED

#define DRAWBAR             PIN_UNDEFINED
#define RELAY7              PIN_UNDEFINED
#define RELAY8              PIN_UNDEFINED

//#define CAN_TX_LED          PIN_UNDEFINED

#define NI_LCD_WR           PIN_UNDEFINED
#define NI_LCD_CS           PIN_UNDEFINED
#define NI_LCD_RS           PIN_UNDEFINED
#define NI_BL_CNT           PIN_UNDEFINED
#define NI_TP_CS            PIN_UNDEFINED
#define NI_TP_IRQ           PIN_UNDEFINED

#define NI_X_ENCB           PIN_UNDEFINED
#define NI_X_ENCA           PIN_UNDEFINED
#define NI_Y_ENCB           PIN_UNDEFINED
#define NI_Y_ENCA           PIN_UNDEFINED
#define NI_Z_Q2             PIN_UNDEFINED     // Z_ENCB
#define NI_Z_Q1             PIN_UNDEFINED     // Z_ENCA

#define NI_SPI2_SCK         PIN_UNDEFINED    // XXX NEEDS AF TO USE
#define NI_SPI2_MISO        PIN_UNDEFINED    // XXX NEEDS AF TO USE
#define NI_SPI2_SS_SDCARD   PIN_UNDEFINED    // XXX NEEDS AF TO USE
#define NI_SPI2_MOSI        PIN_UNDEFINED    // XXX NEEDS AF TO USE

#define NI_VCO1_CNTRL       PIN_UNDEFINED     //AF DAC1_OUT
#define NI_VCO1_FREQ        PIN_UNDEFINED
#define NI_VCO2_CNTRL       PIN_UNDEFINED     //AF DAC2_OUT PA5_Dac_Channel2
#define NI_VCO2_FREQ        PIN_UNDEFINED     //AF TIM14_CH1 FREQ1_PA7

// Avoid using the following JTAG pins as it will interfere with using the ST-LINK/debugger.  if USBOTG is not used,
// the it is possible to reuse A12
#define NI_J20_P2           PIN_UNDEFINED    //J20_20 DO NOT USE -- JTMS/SWDIO
#define NI_JTCK_SWCLK       PIN_UNDEFINED    //J21_P5 DO NOT USE -- JTCK/SWCLK
#define NI_J21_P8           PIN_UNDEFINED    //J21_P8 DO NOT USE -- JTDI
#define NI_JTDO_TRACESWO    PIN_UNDEFINED     //JTAG/TRACESO - DO NOT USE
#define NI_JTRST            PIN_UNDEFINED     //JTRST - DO NOT USE

#define NI_J13_P1           PIN_UNDEFINED
#define NI_J13_P2           PIN_UNDEFINED
#define NI_J13_P3           PIN_UNDEFINED
#define NI_J13_P4           PIN_UNDEFINED
#define J13_P6              PIN_UNDEFINED    // RTD_CALIBRATION_DATA_BIT
#define NI_J13_P5           PIN_UNDEFINED
#define J13_P8              PIN_UNDEFINED    // RTD_CALIBRATION_CSB
#define J13_P7              PIN_UNDEFINED    // RTD_CALIBRATION_CLOCK

#define NI_J14_P35          PIN_UNDEFINED
#define NI_J14_P36          PIN_UNDEFINED
#define NI_J14_P37          PIN_UNDEFINED
#define NI_J14_P38          PIN_UNDEFINED
#define NI_J14_P39          PIN_UNDEFINED
#define NI_J14_P40          PIN_UNDEFINED

#define NI_J21_P5           PIN_UNDEFINED

#define NI_FSMC_D0          PIN_UNDEFINED
#define NI_FSMC_D1          PIN_UNDEFINED
#define NI_FSMC_D2          PIN_UNDEFINED
#define NI_FSMC_D3          PIN_UNDEFINED
#define NI_FSMC_D4          PIN_UNDEFINED
#define NI_FSMC_D5          PIN_UNDEFINED
#define NI_FSMC_D6          PIN_UNDEFINED
#define NI_FSMC_D7          PIN_UNDEFINED
#define NI_FSMC_D8          PIN_UNDEFINED
#define NI_FSMC_D9          PIN_UNDEFINED
#define NI_FSMC_D10         PIN_UNDEFINED
#define NI_FSMC_D11         PIN_UNDEFINED
#define NI_FSMC_D12         PIN_UNDEFINED
#define NI_FSMC_D13         PIN_UNDEFINED
#define NI_FSMC_D14         PIN_UNDEFINED
#define NI_FSMC_D15         PIN_UNDEFINED


#define A_HOME W_HOME
#define A_STEP W_STEP
#define A_EN W_EN
#define A_DIR W_DIR
#define A_STALL W_STALL

#define B_HOME PIN_UNDEFINED
#define B_STEP PIN_UNDEFINED
#define B_EN PIN_UNDEFINED
#define B_DIR PIN_UNDEFINED
#define B_STALL PIN_UNDEFINED
#define C_HOME PIN_UNDEFINED
#define C_STEP PIN_UNDEFINED
#define C_EN PIN_UNDEFINED
#define C_DIR PIN_UNDEFINED
#define C_STALL PIN_UNDEFINED
#define C_L1 PIN_UNDEFINED
#define C_L2 PIN_UNDEFINED
#endif //MEGASONIC_HYREL

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#ifdef HYDRA_DIAGS
#define EMO_PIN PIN_UNDEFINED
#else
#define EMO_PIN C_L1
#endif

////////////////////////////////////////////////////////////////////////////////
//  Global Variables defined in pinout that can be referenced by other modules
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  Public Methods available in pinout
////////////////////////////////////////////////////////////////////////////////


#endif // #ifndef pinout_HEADER // prevent double dipping - MUST BE LAST LINE OF FILE
