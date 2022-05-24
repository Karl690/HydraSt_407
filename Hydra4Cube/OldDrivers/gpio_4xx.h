#ifndef gpio_HEADER // prevent double dipping
#define gpio_HEADER
////////////////////////////////////////////////////////////////////////////////
//
// File:    gpio.h
//
////////////////////////////////////////////////////////////////////////////////
//
// Purpose: Contains gpio specific defines, global references, and method prototypes
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2013  HYREL 3D, LLC.   All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////
//

#include <stdint.h>

/* Exported types ------------------------------------------------------------*/


/**
  * @brief  GPIO Configuration Mode enumeration
  */
typedef enum
{
  GPIO_Mode_IN   = 0x00, /*!< GPIO Input Mode */
  GPIO_Mode_OUT  = 0x01, /*!< GPIO Output Mode */
  GPIO_Mode_AF   = 0x02, /*!< GPIO Alternate function Mode */
  GPIO_Mode_AN   = 0x03  /*!< GPIO Analog Mode */
}HYREL_GPIOMode_TypeDef;
#define HYREL_IS_GPIO_MODE(MODE) (((MODE) == GPIO_Mode_IN)  || ((MODE) == GPIO_Mode_OUT) || \
                            ((MODE) == GPIO_Mode_AF)|| ((MODE) == GPIO_Mode_AN))

/**
  * @brief  GPIO Output type enumeration
  */
typedef enum
{
  GPIO_OType_PP = 0x00,
  GPIO_OType_OD = 0x01
}HYREL_GPIOOType_TypeDef;
#define HYREL_IS_GPIO_OTYPE(OTYPE) (((OTYPE) == GPIO_OType_PP) || ((OTYPE) == GPIO_OType_OD))


/**
  * @brief  GPIO Output Maximum frequency enumeration
  */
typedef enum
{
  GPIO_Speed_2MHz   = 0x00, /*!< Low speed */
  GPIO_Speed_25MHz  = 0x01, /*!< Medium speed */
  GPIO_Speed_50MHz  = 0x02, /*!< Fast speed */
  GPIO_Speed_100MHz = 0x03  /*!< High speed on 30 pF (80 MHz Output max speed on 15 pF) */
}HYREL_GPIOSpeed_TypeDef;
#ifndef HYREL_IS_GPIO_SPEED
#define HYREL_IS_GPIO_SPEED(SPEED) (((SPEED) == GPIO_Speed_2MHz) || ((SPEED) == GPIO_Speed_25MHz) || \
                              ((SPEED) == GPIO_Speed_50MHz)||  ((SPEED) == GPIO_Speed_100MHz))
#endif
/**
  * @brief  GPIO Configuration PullUp PullDown enumeration
  */
typedef enum
{
  GPIO_PuPd_NOPULL = 0x00,
  GPIO_PuPd_UP     = 0x01,
  GPIO_PuPd_DOWN   = 0x02
}HYREL_GPIOPuPd_TypeDef;
#define HYREL_IS_GPIO_PUPD(PUPD) (((PUPD) == GPIO_PuPd_NOPULL) || ((PUPD) == GPIO_PuPd_UP) || \
                            ((PUPD) == GPIO_PuPd_DOWN))

typedef struct
{
  uint32_t GPIO_Pin;              /*!< Specifies the GPIO pins to be configured.
                                       This parameter can be any value of @ref GPIO_pins_define */

  HYREL_GPIOMode_TypeDef GPIO_Mode;     /*!< Specifies the operating mode for the selected pins.
                                       This parameter can be a value of @ref GPIOMode_TypeDef */

  HYREL_GPIOSpeed_TypeDef GPIO_Speed;   /*!< Specifies the speed for the selected pins.
                                       This parameter can be a value of @ref GPIOSpeed_TypeDef */

  HYREL_GPIOOType_TypeDef GPIO_OType;   /*!< Specifies the operating output type for the selected pins.
                                       This parameter can be a value of @ref GPIOOType_TypeDef */

  HYREL_GPIOPuPd_TypeDef GPIO_PuPd;     /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                                       This parameter can be a value of @ref GPIOPuPd_TypeDef */
}HYREL_GPIO_InitTypeDef;


/* Exported constants --------------------------------------------------------*/

/** @defgroup GPIO_Exported_Constants
  * @{
  */

/** @defgroup GPIO_pins_define
  * @{
  */
#define HYREL_GPIO_Pin_0                 ((uint16_t)0x0001)  /* Pin 0 selected */
#define HYREL_GPIO_Pin_1                 ((uint16_t)0x0002)  /* Pin 1 selected */
#define HYREL_GPIO_Pin_2                 ((uint16_t)0x0004)  /* Pin 2 selected */
#define HYREL_GPIO_Pin_3                 ((uint16_t)0x0008)  /* Pin 3 selected */
#define HYREL_GPIO_Pin_4                 ((uint16_t)0x0010)  /* Pin 4 selected */
#define HYREL_GPIO_Pin_5                 ((uint16_t)0x0020)  /* Pin 5 selected */
#define HYREL_GPIO_Pin_6                 ((uint16_t)0x0040)  /* Pin 6 selected */
#define HYREL_GPIO_Pin_7                 ((uint16_t)0x0080)  /* Pin 7 selected */
#define HYREL_GPIO_Pin_8                 ((uint16_t)0x0100)  /* Pin 8 selected */
#define HYREL_GPIO_Pin_9                 ((uint16_t)0x0200)  /* Pin 9 selected */
#define HYREL_GPIO_Pin_10                ((uint16_t)0x0400)  /* Pin 10 selected */
#define HYREL_GPIO_Pin_11                ((uint16_t)0x0800)  /* Pin 11 selected */
#define HYREL_GPIO_Pin_12                ((uint16_t)0x1000)  /* Pin 12 selected */
#define HYREL_GPIO_Pin_13                ((uint16_t)0x2000)  /* Pin 13 selected */
#define HYREL_GPIO_Pin_14                ((uint16_t)0x4000)  /* Pin 14 selected */
#define HYREL_GPIO_Pin_15                ((uint16_t)0x8000)  /* Pin 15 selected */
#define HYREL_GPIO_Pin_All               ((uint16_t)0xFFFF)  /* All pins selected */

#define HYREL_IS_GPIO_PIN(PIN) ((((PIN) & (uint16_t)0x00) == 0x00) && ((PIN) != (uint16_t)0x00))
#define HYREL_IS_GET_GPIO_PIN(PIN) (((PIN) == GPIO_Pin_0) || \
                              ((PIN) == HYREL_GPIO_Pin_1) || \
                              ((PIN) == HYREL_GPIO_Pin_2) || \
                              ((PIN) == HYREL_GPIO_Pin_3) || \
                              ((PIN) == HYREL_GPIO_Pin_4) || \
                              ((PIN) == HYREL_GPIO_Pin_5) || \
                              ((PIN) == HYREL_GPIO_Pin_6) || \
                              ((PIN) == HYREL_GPIO_Pin_7) || \
                              ((PIN) == HYREL_GPIO_Pin_8) || \
                              ((PIN) == HYREL_GPIO_Pin_9) || \
                              ((PIN) == HYREL_GPIO_Pin_10) || \
                              ((PIN) == HYREL_GPIO_Pin_11) || \
                              ((PIN) == HYREL_GPIO_Pin_12) || \
                              ((PIN) == HYREL_GPIO_Pin_13) || \
                              ((PIN) == HYREL_GPIO_Pin_14) || \
                              ((PIN) == HYREL_GPIO_Pin_15))
/**
  * @}
  */



#define HYREL_GPIO_PinSource0            ((uint8_t)0x00)
#define HYREL_GPIO_PinSource1            ((uint8_t)0x01)
#define HYREL_GPIO_PinSource2            ((uint8_t)0x02)
#define HYREL_GPIO_PinSource3            ((uint8_t)0x03)
#define HYREL_GPIO_PinSource4            ((uint8_t)0x04)
#define HYREL_GPIO_PinSource5            ((uint8_t)0x05)
#define HYREL_GPIO_PinSource6            ((uint8_t)0x06)
#define HYREL_GPIO_PinSource7            ((uint8_t)0x07)
#define HYREL_GPIO_PinSource8            ((uint8_t)0x08)
#define HYREL_GPIO_PinSource9            ((uint8_t)0x09)
#define HYREL_GPIO_PinSource10           ((uint8_t)0x0A)
#define HYREL_GPIO_PinSource11           ((uint8_t)0x0B)
#define HYREL_GPIO_PinSource12           ((uint8_t)0x0C)
#define HYREL_GPIO_PinSource13           ((uint8_t)0x0D)
#define HYREL_GPIO_PinSource14           ((uint8_t)0x0E)
#define HYREL_GPIO_PinSource15           ((uint8_t)0x0F)

#define HYREL_IS_GPIO_PIN_SOURCE(PINSOURCE) (((PINSOURCE) == HYREL_GPIO_PinSource0) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource1) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource2) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource3) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource4) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource5) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource6) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource7) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource8) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource9) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource10) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource11) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource12) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource13) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource14) || \
                                       ((PINSOURCE) == HYREL_GPIO_PinSource15))


/** @defgroup GPIO_Alternat_function_selection_define
  * @{
  */
/**
  * @brief   AF 0 selection
  */
#define GPIO_AF_RTC_50Hz      ((uint8_t)0x00)  /* RTC_50Hz Alternate Function mapping */
#define GPIO_AF_MCO           ((uint8_t)0x00)  /* MCO (MCO1 and MCO2) Alternate Function mapping */
#define GPIO_AF_TAMPER        ((uint8_t)0x00)  /* TAMPER (TAMPER_1 and TAMPER_2) Alternate Function mapping */
#define GPIO_AF_SWJ           ((uint8_t)0x00)  /* SWJ (SWD and JTAG) Alternate Function mapping */
#define GPIO_AF_TRACE         ((uint8_t)0x00)  /* TRACE Alternate Function mapping */

/**
  * @brief   AF 1 selection
  */
#define GPIO_AF_TIM1          ((uint8_t)0x01)  /* TIM1 Alternate Function mapping */
#define GPIO_AF_TIM2          ((uint8_t)0x01)  /* TIM2 Alternate Function mapping */

/**
  * @brief   AF 2 selection
  */
#define GPIO_AF_TIM3          ((uint8_t)0x02)  /* TIM3 Alternate Function mapping */
#define GPIO_AF_TIM4          ((uint8_t)0x02)  /* TIM4 Alternate Function mapping */
#define GPIO_AF_TIM5          ((uint8_t)0x02)  /* TIM5 Alternate Function mapping */

/**
  * @brief   AF 3 selection
  */
#define GPIO_AF_TIM8          ((uint8_t)0x03)  /* TIM8 Alternate Function mapping */
#define GPIO_AF_TIM9          ((uint8_t)0x03)  /* TIM9 Alternate Function mapping */
#define GPIO_AF_TIM10         ((uint8_t)0x03)  /* TIM10 Alternate Function mapping */
#define GPIO_AF_TIM11         ((uint8_t)0x03)  /* TIM11 Alternate Function mapping */

/**
  * @brief   AF 4 selection
  */
#define GPIO_AF_I2C1          ((uint8_t)0x04)  /* I2C1 Alternate Function mapping */
#define GPIO_AF_I2C2          ((uint8_t)0x04)  /* I2C2 Alternate Function mapping */
#define GPIO_AF_I2C3          ((uint8_t)0x04)  /* I2C3 Alternate Function mapping */

/**
  * @brief   AF 5 selection
  */
#define GPIO_AF_SPI1          ((uint8_t)0x05)  /* SPI1 Alternate Function mapping */
#define GPIO_AF_SPI2          ((uint8_t)0x05)  /* SPI2/I2S2 Alternate Function mapping */

/**
  * @brief   AF 6 selection
  */
#define GPIO_AF_SPI3          ((uint8_t)0x06)  /* SPI3/I2S3 Alternate Function mapping */

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF_USART1        ((uint8_t)0x07)  /* USART1 Alternate Function mapping */
#define GPIO_AF_USART2        ((uint8_t)0x07)  /* USART2 Alternate Function mapping */
#define GPIO_AF_USART3        ((uint8_t)0x07)  /* USART3 Alternate Function mapping */
#define GPIO_AF_I2S3ext       ((uint8_t)0x07)  /* I2S3ext Alternate Function mapping */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF_UART4         ((uint8_t)0x08)  /* UART4 Alternate Function mapping */
#define GPIO_AF_UART5         ((uint8_t)0x08)  /* UART5 Alternate Function mapping */
#define GPIO_AF_USART6        ((uint8_t)0x08)  /* USART6 Alternate Function mapping */

/**
  * @brief   AF 9 selection
  */
#define GPIO_AF_CAN1          ((uint8_t)0x09)  /* CAN1 Alternate Function mapping */
#define GPIO_AF_CAN2          ((uint8_t)0x09)  /* CAN2 Alternate Function mapping */
#define GPIO_AF_TIM12         ((uint8_t)0x09)  /* TIM12 Alternate Function mapping */
#define GPIO_AF_TIM13         ((uint8_t)0x09)  /* TIM13 Alternate Function mapping */
#define GPIO_AF_TIM14         ((uint8_t)0x09)  /* TIM14 Alternate Function mapping */
/**
  * @brief   AF 10 selection
  */
#define GPIO_AF_OTG_FS         ((uint8_t)0xA)  /* OTG_FS Alternate Function mapping */
#define GPIO_AF_OTG_HS         ((uint8_t)0xA)  /* OTG_HS Alternate Function mapping */


/**
  * @brief   AF 11 selection
  */
#define GPIO_AF_ETH             ((uint8_t)0x0B)  /* ETHERNET Alternate Function mapping */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF_FSMC            ((uint8_t)0xC)  /* FSMC Alternate Function mapping */
#define GPIO_AF_OTG_HS_FS       ((uint8_t)0xC)  /* OTG HS configured in FS, Alternate Function mapping */
#define GPIO_AF_SDIO            ((uint8_t)0xC)  /* SDIO Alternate Function mapping */

/**
  * @brief   AF 13 selection
  */
#define GPIO_AF_DCMI          ((uint8_t)0x0D)  /* DCMI Alternate Function mapping */

/**
  * @brief   AF 15 selection
  */
#define GPIO_AF_EVENTOUT      ((uint8_t)0x0F)  /* EVENTOUT Alternate Function mapping */
////////////////////////////////////////////////////////////////////////////////
//
// these define all of the legal Alternate Function mappings
// it's up to the coder to made sure a given pin supports the requested mapping
//

#define PIN_AF_CAN1            (PIN_MODE_AF | (GPIO_AF_CAN1      << PIN_AF_SHIFT))    // CAN1 Alternate Function
#define PIN_AF_CAN2            (PIN_MODE_AF | (GPIO_AF_CAN2      << PIN_AF_SHIFT))    // CAN2 Alternate Function
#define PIN_AF_DCMI            (PIN_MODE_AF | (GPIO_AF_DCMI      << PIN_AF_SHIFT))    // DCMI Alternate Function
#define PIN_AF_ETH             (PIN_MODE_AF | (GPIO_AF_ETH       << PIN_AF_SHIFT))    // ETHERNET Alternate Function
#define PIN_AF_EVENTOUT        (PIN_MODE_AF | (GPIO_AF_EVENTOUT  << PIN_AF_SHIFT))    // EVENTOUT Alternate Function
#define PIN_AF_FSMC            (PIN_MODE_AF | (GPIO_AF_FSMC      << PIN_AF_SHIFT))    // FSMC Alternate Function
#define PIN_AF_I2C1            (PIN_MODE_AF | (GPIO_AF_I2C1      << PIN_AF_SHIFT))    // I2C1 Alternate Function
#define PIN_AF_I2C2            (PIN_MODE_AF | (GPIO_AF_I2C2      << PIN_AF_SHIFT))    // I2C2 Alternate Function
#define PIN_AF_I2C3            (PIN_MODE_AF | (GPIO_AF_I2C3      << PIN_AF_SHIFT))    // I2C3 Alternate Function
#define PIN_AF_I2S3ext         (PIN_MODE_AF | (GPIO_AF_I2S3ext   << PIN_AF_SHIFT))    // I2S3ext Alternate Function
#define PIN_AF_MCO             (PIN_MODE_AF | (GPIO_AF_MCO       << PIN_AF_SHIFT))    // MCO (MCO1 and MCO2) Alternate Function
//#define PIN_AF_OTG_FS          (PIN_MODE_AF | (GPIO_AF_OTG_FS    << PIN_AF_SHIFT))    // OTG_FS Alternate Function
#define PIN_AF_OTG_FS          (PIN_MODE_AF | PIN_OSPEED_100MHZ | (GPIO_AF_OTG_FS    << PIN_AF_SHIFT))    // OTG_FS Alternate Function
//#define PIN_AF_OTG_HS          (PIN_MODE_AF | PIN_OSPEED_100MHZ | (GPIO_AF_OTG_HS    << PIN_AF_SHIFT))    // OTG_HS Alternate Function
//#define PIN_AF_OTG_HS_FS       (PIN_MODE_AF | PIN_OSPEED_100MHZ | (GPIO_AF_OTG_HS_FS << PIN_AF_SHIFT))    // OTG HS configured in FS, Alternate Function
#define PIN_AF_RTC_50Hz        (PIN_MODE_AF | (GPIO_AF_RTC_50Hz  << PIN_AF_SHIFT))    // RTC_50Hz Alternate Function
#define PIN_AF_SDIO            (PIN_MODE_AF | (GPIO_AF_SDIO      << PIN_AF_SHIFT))    // SDIO Alternate Function
#define PIN_AF_SPI1            (PIN_MODE_AF | (GPIO_AF_SPI1      << PIN_AF_SHIFT))    // SPI1 Alternate Function
#define PIN_AF_SPI2            (PIN_MODE_AF | (GPIO_AF_SPI2      << PIN_AF_SHIFT))    // SPI2/I2S2 Alternate Function
#define PIN_AF_SPI3            (PIN_MODE_AF | (GPIO_AF_SPI3      << PIN_AF_SHIFT))    // SPI3/I2S3 Alternate Function
#define PIN_AF_SWJ             (PIN_MODE_AF | (GPIO_AF_SWJ       << PIN_AF_SHIFT))    // SWJ (SWD and JTAG) Alternate Function
#define PIN_AF_TAMPER          (PIN_MODE_AF | (GPIO_AF_TAMPER    << PIN_AF_SHIFT))    // TAMPER (TAMPER_1 and TAMPER_2) Alternate Function
#define PIN_AF_TIM1            (PIN_MODE_AF | (GPIO_AF_TIM1      << PIN_AF_SHIFT))    // TIM1 Alternate Function
#define PIN_AF_TIM10           (PIN_MODE_AF | (GPIO_AF_TIM10     << PIN_AF_SHIFT))    // TIM10 Alternate Function
#define PIN_AF_TIM11           (PIN_MODE_AF | (GPIO_AF_TIM11     << PIN_AF_SHIFT))    // TIM11 Alternate Function
#define PIN_AF_TIM12           (PIN_MODE_AF | (GPIO_AF_TIM12     << PIN_AF_SHIFT))    // TIM12 Alternate Function
#define PIN_AF_TIM13           (PIN_MODE_AF | (GPIO_AF_TIM13     << PIN_AF_SHIFT))    // TIM13 Alternate Function
#define PIN_AF_TIM14           (PIN_MODE_AF | (GPIO_AF_TIM14     << PIN_AF_SHIFT))    // TIM14 Alternate Function
#define PIN_AF_TIM2            (PIN_MODE_AF | (GPIO_AF_TIM2      << PIN_AF_SHIFT))    // TIM2 Alternate Function
#define PIN_AF_TIM3            (PIN_MODE_AF | (GPIO_AF_TIM3      << PIN_AF_SHIFT))    // TIM3 Alternate Function
#define PIN_AF_TIM4            (PIN_MODE_AF | (GPIO_AF_TIM4      << PIN_AF_SHIFT))    // TIM4 Alternate Function
#define PIN_AF_TIM5            (PIN_MODE_AF | (GPIO_AF_TIM5      << PIN_AF_SHIFT))    // TIM5 Alternate Function
#define PIN_AF_TIM8            (PIN_MODE_AF | (GPIO_AF_TIM8      << PIN_AF_SHIFT))    // TIM8 Alternate Function
#define PIN_AF_TIM9            (PIN_MODE_AF | (GPIO_AF_TIM9      << PIN_AF_SHIFT))    // TIM9 Alternate Function
#define PIN_AF_TRACE           (PIN_MODE_AF | (GPIO_AF_TRACE     << PIN_AF_SHIFT))    // TRACE Alternate Function
#define PIN_AF_UART4           (PIN_MODE_AF | (GPIO_AF_UART4     << PIN_AF_SHIFT))    // UART4 Alternate Function
#define PIN_AF_UART5           (PIN_MODE_AF | (GPIO_AF_UART5     << PIN_AF_SHIFT))    // UART5 Alternate Function
#define PIN_AF_USART1          (PIN_MODE_AF | (GPIO_AF_USART1    << PIN_AF_SHIFT))    // USART1 Alternate Function
#define PIN_AF_USART2          (PIN_MODE_AF | (GPIO_AF_USART2    << PIN_AF_SHIFT))    // USART2 Alternate Function
#define PIN_AF_USART3          (PIN_MODE_AF | (GPIO_AF_USART3    << PIN_AF_SHIFT))    // USART3 Alternate Function
#define PIN_AF_USART6          (PIN_MODE_AF | (GPIO_AF_USART6    << PIN_AF_SHIFT))    // USART6 Alternate Function

////////////////////////////////////////////////////////////////////////////////
//
// common definitions for basic IO
//

#define AF_OUT_PP_2MHZ    (PIN_MODE_AF | PIN_OTYPE_PUSHPULL  | PIN_OSPEED_2MHZ)
#define AF_OUT_PP_25MHZ   (PIN_MODE_AF | PIN_OTYPE_PUSHPULL  | PIN_OSPEED_25MHZ)
#define AF_OUT_PP_50MHZ   (PIN_MODE_AF | PIN_OTYPE_PUSHPULL  | PIN_OSPEED_50MHZ)
#define AF_OUT_PP_100MHZ  (PIN_MODE_AF | PIN_OTYPE_PUSHPULL  | PIN_OSPEED_100MHZ)

#define AF_OUT_OD_2MHZ    (PIN_MODE_AF | PIN_OTYPE_OPENDRAIN  | PIN_OSPEED_2MHZ)
#define AF_OUT_OD_25MHZ   (PIN_MODE_AF | PIN_OTYPE_OPENDRAIN  | PIN_OSPEED_25MHZ)
#define AF_OUT_OD_50MHZ   (PIN_MODE_AF | PIN_OTYPE_OPENDRAIN  | PIN_OSPEED_50MHZ)
#define AF_OUT_OD_100MHZ  (PIN_MODE_AF | PIN_OTYPE_OPENDRAIN  | PIN_OSPEED_100MHZ)

#define OUTPUT_PP_2MHZ    (PIN_MODE_OUT | PIN_OTYPE_PUSHPULL  | PIN_OSPEED_2MHZ)
#define OUTPUT_PP_25MHZ   (PIN_MODE_OUT | PIN_OTYPE_PUSHPULL  | PIN_OSPEED_25MHZ)
#define OUTPUT_PP_50MHZ   (PIN_MODE_OUT | PIN_OTYPE_PUSHPULL  | PIN_OSPEED_50MHZ)
#define OUTPUT_PP_100MHZ  (PIN_MODE_OUT | PIN_OTYPE_PUSHPULL  | PIN_OSPEED_100MHZ)

#define OUTPUT_OD_2MHZ    (PIN_MODE_OUT | PIN_OTYPE_OPENDRAIN | PIN_OSPEED_2MHZ)
#define OUTPUT_OD_25MHZ   (PIN_MODE_OUT | PIN_OTYPE_OPENDRAIN | PIN_OSPEED_25MHZ)
#define OUTPUT_OD_50MHZ   (PIN_MODE_OUT | PIN_OTYPE_OPENDRAIN | PIN_OSPEED_50MHZ)
#define OUTPUT_OD_100MHZ  (PIN_MODE_OUT | PIN_OTYPE_OPENDRAIN | PIN_OSPEED_100MHZ)

#define AF_IN_FLOATING    (PIN_MODE_IN | PIN_PUPPD_NONE)
#define AF_IN_PULLUP      (PIN_MODE_IN | PIN_PUPPD_PULLUP)
#define AF_IN_PULLDOWN    (PIN_MODE_IN | PIN_PUPPD_PULLDOWN)

#define INPUT_FLOATING    (PIN_MODE_IN | PIN_PUPPD_NONE)
#define INPUT_PULLUP      (PIN_MODE_IN | PIN_PUPPD_PULLUP)
#define INPUT_PULLDOWN    (PIN_MODE_IN | PIN_PUPPD_PULLDOWN)

#define ANALOG_FLOATING   (PIN_MODE_ANALOG | PIN_PUPPD_NONE)
#define ANALOG_PULLUP     (PIN_MODE_ANALOG | PIN_PUPPD_PULLUP)
#define ANALOG_PULLDOWN   (PIN_MODE_ANALOG | PIN_PUPPD_PULLDOWN)


#define GPIO_PortSourceGPIOA       ((uint8_t)0x00)
#define GPIO_PortSourceGPIOB       ((uint8_t)0x01)
#define GPIO_PortSourceGPIOC       ((uint8_t)0x02)
#define GPIO_PortSourceGPIOD       ((uint8_t)0x03)
#define GPIO_PortSourceGPIOE       ((uint8_t)0x04)
#define GPIO_PortSourceGPIOF       ((uint8_t)0x05)
#define GPIO_PortSourceGPIOG       ((uint8_t)0x06)
#define GPIO_PortSourceGPIOH       ((uint8_t)0x07)
#define GPIO_PortSourceGPIOI       ((uint8_t)0x08)

#define PIN_PORT_A      ((uint32_t)(GPIO_PortSourceGPIOA) << PIN_PORT_NUM_SHIFT)
#define PIN_PORT_B      ((uint32_t)(GPIO_PortSourceGPIOB) << PIN_PORT_NUM_SHIFT)
#define PIN_PORT_C      ((uint32_t)(GPIO_PortSourceGPIOC) << PIN_PORT_NUM_SHIFT)
#define PIN_PORT_D      ((uint32_t)(GPIO_PortSourceGPIOD) << PIN_PORT_NUM_SHIFT)
#define PIN_PORT_E      ((uint32_t)(GPIO_PortSourceGPIOE) << PIN_PORT_NUM_SHIFT)
#define PIN_PORT_F      ((uint32_t)(GPIO_PortSourceGPIOF) << PIN_PORT_NUM_SHIFT)
#define PIN_PORT_G      ((uint32_t)(GPIO_PortSourceGPIOG) << PIN_PORT_NUM_SHIFT)
#define PIN_PORT_H      ((uint32_t)(GPIO_PortSourceGPIOH) << PIN_PORT_NUM_SHIFT)
#define PIN_PORT_I      ((uint32_t)(GPIO_PortSourceGPIOI) << PIN_PORT_NUM_SHIFT)
#define PIN_PORT_NONE   (0xf << PIN_PORT_NUM_SHIFT)

#define PIN_UNDEFINED   (0xffffffff)

////////////////////////////////////////////////////////////////////////////////
#endif // #ifndef gpio_HEADER // prevent double dipping - MUST BE LAST LINE OF FILE
