////////////////////////////////////////////////////////////////////////////////
//
// File:    pins.c
//
////////////////////////////////////////////////////////////////////////////////
//
// Purpose: This module contains all of the general purpose I//O read, write, and
///         initialization routines..
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2013  HYREL 3D, LLC.   All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

#include "main.h"
#include "pins.h" // (get our own global defines and typedefs)
#include "pinout.h"
////////////////////////////////////////////////////////////////////////////////
//  Local #defines (defines ONLY used in this module)
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  Public global definitions (exposed in pins.h)
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  Local global definitions (do not expose in pins.h)
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//  Forward declarations - any local modules needing an early template
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//    Each pin will have a #define that will concatinate all the values needed
//    to define everything to setup, initialize, and commmunicate into a
//    single 32-bit unsigned int.   All access to the pins, whether for
//    initialization, reading or writing, etc will use these #defines.  This
//    will allow simple porting of code between board/processor changes as
//    only the PORT and PIN part of the #define will need to be modified and
//    everything else *should* continue to work.
//
////////////////////////////////////////////////////////////////////////////////

HYREL_GPIO_TypeDef PGIOZ_fake;
HYREL_GPIO_TypeDef *GPIOZ = &PGIOZ_fake;

HYREL_GPIO_TypeDef *pinExtractPortPtr(pinType pin)
{   // return address pointer to this pin's port
	if (pin != PIN_UNDEFINED)
	{
		switch (pinExtractPortNum(pin))
		{
		case GPIO_PortSourceGPIOA : return(HYREL_GPIOA);
		case GPIO_PortSourceGPIOB : return(HYREL_GPIOB);
		case GPIO_PortSourceGPIOC : return(HYREL_GPIOC);
		case GPIO_PortSourceGPIOD : return(HYREL_GPIOD);
		case GPIO_PortSourceGPIOE : return(HYREL_GPIOE);
		case GPIO_PortSourceGPIOF : return(HYREL_GPIOF);
		case GPIO_PortSourceGPIOG : return(HYREL_GPIOG);
		case GPIO_PortSourceGPIOH : return(HYREL_GPIOH);
		case GPIO_PortSourceGPIOI : return(HYREL_GPIOI);
		//default: return(HYREL_GPIOZ); // pointer to fake I/O mem area
		}
	}
	else
	{
		return(0);
	}
}

////////////////////////////////////////////////////////////////////////////////

void pinInit(pinType pin)
{   // init the pin using the ST provided routine (can be put inline and sped up
	// if needed

	if (pin != PIN_UNDEFINED)
	{   // skip if not a valid pin

		if (pinExtractMode(pin) == GPIO_Mode_AF)
		{   // if the pin is set for using an Alternate Function then complete
			// then complete the initialization for that pin by setting the requested
			// alternated function -- WARNING: this needs to be set BEFORE putting the I/O
			// pin in AF Mode, otherwise will have undetermined behavior

			// Warning: GPIO_PinAFConfig uses the BinNum and not BitPos like the other GPIO routines

			HYREL_GPIO_PinAFConfig(pinExtractPortPtr(pin), pinExtractPinNum(pin), pinExtractAF(pin));
		}
		else
		{
			HYREL_GPIO_PinAFConfig(pinExtractPortPtr(pin), pinExtractPinNum(pin), 0);
		}

		HYREL_GPIO_InitTypeDef GPIO_InitStructure;

		GPIO_InitStructure.GPIO_Pin   = pinExtractPinMask(pin);
		GPIO_InitStructure.GPIO_Mode  = pinExtractMode(pin);
		GPIO_InitStructure.GPIO_Speed = pinExtractSpeed(pin);
		GPIO_InitStructure.GPIO_OType = pinExtractOType(pin);
		GPIO_InitStructure.GPIO_PuPd  = pinExtractPupd(pin);

		HYREL_GPIO_Init(pinExtractPortPtr(pin), &GPIO_InitStructure);

		if (pinExtractInitEn(pin))
		{   // initialize pin
			pinWrite(pin, pinExtractInitVal(pin));
		}
	}
}

////////////////////////////////////////////////////////////////////////////////

void pinClear(pinType pin)
{   // writing "1" to any bit in the UPPER 16 bits of the BSSR reg (BSSR[31:16]
	// will force the corresponding bit(s) on that port to be set to 0

	if (pin != PIN_UNDEFINED)
	{
		pinExtractPortPtr(pin)->BSRRH = pinExtractPinMask(pin);
	}
}

////////////////////////////////////////////////////////////////////////////////

void pinSet(pinType pin)
{   // writing "1" to any bit in the LOWER 16 bits of the BSSR (ie, BSSR[15:0]
	// will force the corresponding bit(s) on that port to be set to 1

	if (pin != PIN_UNDEFINED)
	{
		pinExtractPortPtr(pin)->BSRRL = pinExtractPinMask(pin);
	}
}

////////////////////////////////////////////////////////////////////////////////

void pinWrite(pinType pin, uint32_t value)
{   // use clear or set to force the output to the desired value
	// NO CHECKING is performed to make sure this is requested on an OUTPUT

	if (pin == PIN_UNDEFINED) return;

	if (value == 0)
		pinClear(pin);
	else
		pinSet(pin);
}

////////////////////////////////////////////////////////////////////////////////

uint32_t pinRead(pinType pin)
{   // grab the IDR for the port belong to the pin and shift results down to move
	// the desired bit position to the LBS and AND with 0x1 to make sure only
	// the value from the requested bit is return (returns a 0 or 1)

	if (pin == PIN_UNDEFINED) return(0);

	return((byte)(pinExtractPortPtr(pin)->IDR >> pinExtractPinNum(pin)) & 0x1);
}

////////////////////////////////////////////////////////////////////////////////

uint32_t pinReadOutput(pinType pin)
{   // grab the IDR for the port belong to the pin and shift results down to move
	// the desired bit position to the LBS and AND with 0x1 to make sure only
	// the value from the requested bit is return (returns a 0 or 1)

	if (pin == PIN_UNDEFINED) return(0);

	return(uint32_t)((byte)(pinExtractPortPtr(pin)->ODR >> pinExtractPinNum(pin)) & 0x1);
}

////////////////////////////////////////////////////////////////////////////////

void pinToggleOutput(pinType pin)
{   // really used for driving the LA for debug....flip the output state of an output pin

	if (pin == PIN_UNDEFINED) return;

	pinWrite(pin, (~pinReadOutput(pin)) & 0x1);
}

////////////////////////////////////////////////////////////////////////////////
