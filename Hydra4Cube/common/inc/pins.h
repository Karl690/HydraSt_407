#ifndef pins_HEADER // prevent double dipping

#define pins_HEADER
////////////////////////////////////////////////////////////////////////////////
//
// File:    pins.h
//
////////////////////////////////////////////////////////////////////////////////
//
// Purpose: Contains common pin/gpio specific defines, global references, and method prototypes
//          for both 103 and 407/429 designed
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2013  HYREL 3D, LLC.   All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "gpio_4xx.h"


#define PIN_NUM_SHIFT          0        // pin[3:0]
#define PIN_PORT_NUM_SHIFT     4        // pin[7:4]
#define PIN_MODE_SHIFT         8        // pin[9:8]
#define PIN_OSPEED_SHIFT       10       // pin[11:10]
#define PIN_INIT_VAL_SHIFT     12       // pin[12]
#define PIN_INIT_EN_SHIFT      13       // pin[13]
#define PIN_PUPPD_SHIFT        14       // pin[15:14]
#define PIN_AF_SHIFT           16       // pin[19:16]
#define PIN_OTYPE_SHIFT        20       // pin[20]
#define PIN_LOCK_SHIFT         21       // pin[21]

////////////////////////////////////////////////////////////////////////////////
//
// define a simple pin number mapping
//

#define PIN_NUM_00             (0x0 << PIN_NUM_SHIFT)
#define PIN_NUM_01             (0x1 << PIN_NUM_SHIFT)
#define PIN_NUM_02             (0x2 << PIN_NUM_SHIFT)
#define PIN_NUM_03             (0x3 << PIN_NUM_SHIFT)
#define PIN_NUM_04             (0x4 << PIN_NUM_SHIFT)
#define PIN_NUM_05             (0x5 << PIN_NUM_SHIFT)
#define PIN_NUM_06             (0x6 << PIN_NUM_SHIFT)
#define PIN_NUM_07             (0x7 << PIN_NUM_SHIFT)
#define PIN_NUM_08             (0x8 << PIN_NUM_SHIFT)
#define PIN_NUM_09             (0x9 << PIN_NUM_SHIFT)
#define PIN_NUM_10             (0xa << PIN_NUM_SHIFT)
#define PIN_NUM_11             (0xb << PIN_NUM_SHIFT)
#define PIN_NUM_12             (0xc << PIN_NUM_SHIFT)
#define PIN_NUM_13             (0xd << PIN_NUM_SHIFT)
#define PIN_NUM_14             (0xe << PIN_NUM_SHIFT)
#define PIN_NUM_15             (0xf << PIN_NUM_SHIFT)


////////////////////////////////////////////////////////////////////////////////
//
// these define the values for the various fields (and most just match the spec defined register values
//

#define PIN_INIT_NONE          (0 << PIN_INIT_EN_SHIFT)
#define PIN_INIT_LOW           ((1 << PIN_INIT_EN_SHIFT) | (0 << PIN_INIT_VAL_SHIFT))
#define PIN_INIT_HIGH          ((1 << PIN_INIT_EN_SHIFT) | (1 << PIN_INIT_VAL_SHIFT))

#define PIN_MODE_IN            (GPIO_Mode_IN  << PIN_MODE_SHIFT)
#define PIN_MODE_OUT           (GPIO_Mode_OUT << PIN_MODE_SHIFT)
#define PIN_MODE_AF            (GPIO_Mode_AF  << PIN_MODE_SHIFT)
#define PIN_MODE_ANALOG        (GPIO_Mode_AN  << PIN_MODE_SHIFT)

#define PIN_OTYPE_PUSHPULL     (GPIO_OType_PP << PIN_OTYPE_SHIFT)
#define PIN_OTYPE_OPENDRAIN    (GPIO_OType_OD << PIN_OTYPE_SHIFT)

#define PIN_OSPEED_2MHZ        (GPIO_Speed_2MHz   << PIN_OSPEED_SHIFT)
#define PIN_OSPEED_25MHZ       (GPIO_Speed_25MHz  << PIN_OSPEED_SHIFT)
#define PIN_OSPEED_50MHZ       (GPIO_Speed_50MHz  << PIN_OSPEED_SHIFT)
#define PIN_OSPEED_100MHZ      (GPIO_Speed_100MHz << PIN_OSPEED_SHIFT)

#define PIN_PUPPD_NONE         (GPIO_PuPd_NOPULL << PIN_PUPPD_SHIFT)
#define PIN_PUPPD_PULLUP       (GPIO_PuPd_UP     << PIN_PUPPD_SHIFT)
#define PIN_PUPPD_PULLDOWN     (GPIO_PuPd_DOWN   << PIN_PUPPD_SHIFT)

#define PIN_LOCK_UNLOCKED      (0 << PIN_LOCK_SHIFT)
#define PIN_LOCK_LOCKED        (1 << PIN_LOCK_SHIFT)

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

////////////////////////////////////////////////////////////////////////////////

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


typedef enum {
	GPIO_INDEX_PA0 = 0,
	GPIO_INDEX_PA1,
	GPIO_INDEX_PA2,
	GPIO_INDEX_PA3,
	GPIO_INDEX_PA4,
	GPIO_INDEX_PA5,
	GPIO_INDEX_PA6,
	GPIO_INDEX_PA7,
	GPIO_INDEX_PA8,
	GPIO_INDEX_PA9,
	GPIO_INDEX_PA10,
	GPIO_INDEX_PA11,
	GPIO_INDEX_PA12,
	GPIO_INDEX_PA13,
	GPIO_INDEX_PA14,
	GPIO_INDEX_PA15,
	GPIO_INDEX_PB0,
	GPIO_INDEX_PB1,
	GPIO_INDEX_PB2,
	GPIO_INDEX_PB3,
	GPIO_INDEX_PB4,
	GPIO_INDEX_PB5,
	GPIO_INDEX_PB6,
	GPIO_INDEX_PB7,
	GPIO_INDEX_PB8,
	GPIO_INDEX_PB9,
	GPIO_INDEX_PB10,
	GPIO_INDEX_PB11,
	GPIO_INDEX_PB12,
	GPIO_INDEX_PB13,
	GPIO_INDEX_PB14,
	GPIO_INDEX_PB15,
	GPIO_INDEX_PC0,
	GPIO_INDEX_PC1,
	GPIO_INDEX_PC2,
	GPIO_INDEX_PC3,
	GPIO_INDEX_PC4,
	GPIO_INDEX_PC5,
	GPIO_INDEX_PC6,
	GPIO_INDEX_PC7,
	GPIO_INDEX_PC8,
	GPIO_INDEX_PC9,
	GPIO_INDEX_PC10,
	GPIO_INDEX_PC11,
	GPIO_INDEX_PC12,
	GPIO_INDEX_PC13,
	GPIO_INDEX_PC14,
	GPIO_INDEX_PC15,
	GPIO_INDEX_PD0,
	GPIO_INDEX_PD1,
	GPIO_INDEX_PD2,
	GPIO_INDEX_PD3,
	GPIO_INDEX_PD4,
	GPIO_INDEX_PD5,
	GPIO_INDEX_PD6,
	GPIO_INDEX_PD7,
	GPIO_INDEX_PD8,
	GPIO_INDEX_PD9,
	GPIO_INDEX_PD10,
	GPIO_INDEX_PD11,
	GPIO_INDEX_PD12,
	GPIO_INDEX_PD13,
	GPIO_INDEX_PD14,
	GPIO_INDEX_PD15,
} gpioIndex_t;

typedef union {
	uint32_t u32;
	struct {
		unsigned pinNum     : 4;    // shift 0
		unsigned portNum    : 4;    // shift 4
		unsigned mode       : 2;    // shift 8
		unsigned speed      : 2;    // shift 10
		unsigned initVal    : 1;    // shift 11
		unsigned initEn     : 1;    // shift 12
		unsigned pupd       : 2;    // shift 14
		unsigned af         : 4;    // shift 16
		unsigned otype      : 1;    // shift 20
		unsigned lock       : 1;    // shift 21
	} b;
} pinUnion_t;

////////////////////////////////////////////////////////////////////////////////
//  Public Methods available in pin
////////////////////////////////////////////////////////////////////////////////


#define PIN_CLEAR(a,b) ({if (a) {a->BSRRH = b;}})
#define PIN_SET(a,b)   ({if (a) {a->BSRRL = b;}})

////////////////////////////////////////////////////////////////////////////////

#define pinExtractPinMask(pin)      (1 << (uint32_t)(((pinUnion_t)pin).b.pinNum))

#define pinExtractPinNum(pin)       ((uint32_t)(((pinUnion_t)pin).b.pinNum))
#define pinExtractPortNum(pin)      ((uint32_t)(((pinUnion_t)pin).b.portNum))
#define pinExtractMode(pin)         ((HYREL_GPIOMode_TypeDef)(((pinUnion_t)pin).b.mode))
#define pinExtractSpeed(pin)        ((HYREL_GPIOSpeed_TypeDef)(((pinUnion_t)pin).b.speed))
#define pinExtractInitVal(pin)      ((uint32_t)(((pinUnion_t)pin).b.initVal))
#define pinExtractInitEn(pin)       ((uint32_t)(((pinUnion_t)pin).b.initEn))
#define pinExtractPupd(pin)         ((HYREL_GPIOPuPd_TypeDef)(((pinUnion_t)pin).b.pupd))
#define pinExtractAF(pin)           ((uint32_t)(((pinUnion_t)pin).b.af))
#define pinExtractOType(pin)        ((HYREL_GPIOOType_TypeDef)(((pinUnion_t)pin).b.otype))
#define pinExtractLock(pin)         ((uint32_t)(((pinUnion_t)pin).b.lock))
#define pinExtractPortChar(pin)     ((char)(((pinUnion_t)pin).b.portNum) + 'A')


#define BIT_BAND(addr, bitnum)		((addr & 0xF0000000)+0x02000000+((addr & 0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  			*((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)		MEM_ADDR(BIT_BAND(addr, bitnum))


#define PIN_PORT_NUM(pin) 			(((pin>>PIN_PORT_NUM_SHIFT)&0xf)*0x400)
#define PIN_NUM(pin)				((pin>>PIN_NUM_SHIFT)&0xf)
#define PIN_MASK(pin)				(1<<PIN_NUM(pin))

#define ODR_OFS			0x14
#define IDR_OFS			0x10

#define GPIOA_ODR_ADDR    (GPIOA_BASE+ODR_OFS)
#define GPIOB_ODR_ADDR    (GPIOB_BASE+ODR_OFS)
#define GPIOC_ODR_ADDR    (GPIOC_BASE+ODR_OFS)
#define GPIOD_ODR_ADDR    (GPIOD_BASE+ODR_OFS)
#define GPIOE_ODR_ADDR    (GPIOE_BASE+ODR_OFS)
#define GPIOF_ODR_ADDR    (GPIOF_BASE+ODR_OFS)
#define GPIOG_ODR_ADDR    (GPIOG_BASE+ODR_OFS)

#define GPIOA_IDR_ADDR    (GPIOA_BASE+IDR_OFS)
#define GPIOB_IDR_ADDR    (GPIOB_BASE+IDR_OFS)
#define GPIOC_IDR_ADDR    (GPIOC_BASE+IDR_OFS)
#define GPIOD_IDR_ADDR    (GPIOD_BASE+IDR_OFS)
#define GPIOE_IDR_ADDR    (GPIOE_BASE+IDR_OFS)
#define GPIOF_IDR_ADDR    (GPIOF_BASE+IDR_OFS)
#define GPIOG_IDR_ADDR    (GPIOG_BASE+IDR_OFS)

#define PAout(n)   BIT_ADDR(GPIOA_ODR_ADDR,n)
#define PAin(n)    BIT_ADDR(GPIOA_IDR_ADDR,n)

#define PBout(n)   BIT_ADDR(GPIOB_ODR_ADDR,n)
#define PBin(n)    BIT_ADDR(GPIOB_IDR_ADDR,n)

#define PCout(n)   BIT_ADDR(GPIOC_ODR_ADDR,n)
#define PCin(n)    BIT_ADDR(GPIOC_IDR_ADDR,n)

#define PDout(n)   BIT_ADDR(GPIOD_ODR_ADDR,n)
#define PDin(n)    BIT_ADDR(GPIOD_IDR_ADDR,n)

#define PEout(n)   BIT_ADDR(GPIOE_ODR_ADDR,n)
#define PEin(n)    BIT_ADDR(GPIOE_IDR_ADDR,n)

#define PFout(n)   BIT_ADDR(GPIOF_ODR_ADDR,n)
#define PFin(n)    BIT_ADDR(GPIOF_IDR_ADDR,n)

#define PGout(n)   BIT_ADDR(GPIOG_ODR_ADDR,n)
#define PGin(n)    BIT_ADDR(GPIOG_IDR_ADDR,n)

////////////////////////////////////////////////////////////////////////////////

extern HYREL_GPIO_TypeDef *GPIOZ;


extern void pinInit(pinType);
extern void pinClear(pinType);
extern void pinSet(pinType);
extern void pinWrite(pinType, uint32_t);
extern uint32_t pinRead(pinType);
extern uint32_t pinReadOutput(pinType);
extern void pinToggleOutput(pinType);
////////////////////////////////////////////////////////////////////////////////
#endif // #ifndef pins_HEADER // prevent double dipping - MUST BE LAST LINE OF FILE
