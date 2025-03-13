#include "bit_math.h"
#include "stdtypes.h"
#include "EXT.h"
#include <avr/interrupt.h>

static void (*EXT0_Callback)(void) = NULL;
static void (*EXT1_Callback)(void) = NULL;
static void (*EXT2_Callback)(void) = NULL;


EXT_ERROR_Status_t EXT_Init()
{
	sei(); // Enable global interrupts
	return EXT_OK;
}

EXT_ERROR_Status_t EXT0_Enable()
{
	GICR |= (1 << INT0);
	return EXT_OK;
}
EXT_ERROR_Status_t EXT1_Enable()
{
	GICR |= (1 << INT1);
	return EXT_OK;
}
EXT_ERROR_Status_t EXT2_Enable()
{
	GICR |= (1 << INT2);
	return EXT_OK;
}

EXT_ERROR_Status_t EXT0_Disable()
{
	GICR &= ~(1 << INT0);
	return EXT_OK;
}
EXT_ERROR_Status_t EXT1_Disable()
{
	GICR &= ~(1 << INT1);
	return EXT_OK;
}
EXT_ERROR_Status_t EXT2_Disable()
{
	GICR &= ~(1 << INT2);
	return EXT_OK;
}

EXT_ERROR_Status_t EXT_SetEdge(EXT_Interrupt_t EXTIx, EXT_Edge_t edge)
{
	switch (EXTIx)
	{
		case EXT_INT0: 
		switch (edge)
		{
			case EXT_EDGE_RISING:
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
			case EXT_EDGE_FALLING:
			CLR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
			case EXT_EDGE_BOTH:
			SET_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;
			case EXT_LOW_LEVEL:
			CLR_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;
			default:
			return EXT_WRONG_EDGE;
		}
		break;
		case EXT_INT1:
		switch (edge)
		{
			case EXT_EDGE_RISING:
			SET_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			break;
			case EXT_EDGE_FALLING:
			CLR_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			break;
			case EXT_EDGE_BOTH:
			SET_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
			break;
			case EXT_LOW_LEVEL:
			CLR_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
			break;
			default:
			return EXT_WRONG_EDGE;
		}
		break;
		case EXT_INT2:
		switch (edge)
		{
			case EXT_EDGE_RISING:
			SET_BIT(MCUCSR, ISC2);
			break;
			case EXT_EDGE_FALLING:
			CLR_BIT(MCUCSR, ISC2);
			break;
			default:
			return EXT_WRONG_EDGE;
		}
		break;
		default:
		return EXT_WRONG_INTERRUPT_NUMBER;
	}
	return EXT_OK;
}

EXT_ERROR_Status_t EXT_SetCallback(EXT_Interrupt_t EXTIx, void (*callback)(void))
{
	if (callback == NULL)
	{
		return EXT_INVALID_CALLBACK;
	}

	switch (EXTIx)
	{
		case EXT_INT0: 
		EXT0_Callback = callback;
		break;
		case EXT_INT1:
		EXT1_Callback = callback;
		break;
		case EXT_INT2:
		EXT2_Callback = callback;
		break;
		default:
		return EXT_WRONG_INTERRUPT_NUMBER;
	}
	return EXT_OK;
}