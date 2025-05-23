#include "bit_math.h"
#include "PORT.h"
#include "port_config.h"
#include "DIO.h"
#include "DIO_Private.h"

extern MPORT_PinCfg_t PinCfg[];

void MPORT_portInit()
{
	for (u8 i = 0; i < TOTAL_PINS; i++)
	{
		MPORT_enuErrorStatus_t status =MPORT_enuSetPinDirection(PinCfg[i].port_pin, PinCfg[i].dir);
        if (status != MPORT_OK)
		{
                // Handle error (e.g., log it or halt execution)
		}
	}
}

MPORT_enuErrorStatus_t MPORT_enuSetPinDirection( u8 Copy_enuPinNum  ,  u8  Copy_enuPinDirection  )
{

	u8 port_Number = (Copy_enuPinNum >> 4) & 0x0F; // Extract port number
	u8 pin_Number = Copy_enuPinNum & 0x0F;        // Extract pin number

	// Validate direction
	if (Copy_enuPinDirection < MPORT_INPUT || Copy_enuPinDirection > MPORT_INPUT_PULLUP)
	{
		return MPORT_ERROR_INVALID_DIRECTION;
	}

	switch (port_Number)
	{
		case 0: // PORTA
		switch (Copy_enuPinDirection)
		{
			case MPORT_INPUT:
			CLR_BIT(DDRA_REG, pin_Number); // Configure as input
			break;

			case MPORT_OUTPUT:
			SET_BIT(DDRA_REG, pin_Number); // Configure as output
			break;

			case MPORT_INPUT_PULLUP:
			CLR_BIT(DDRA_REG, pin_Number); // Configure as input
			SET_BIT(PORTA_REG, pin_Number);  // Enable pull-up
			break;

			default:
			return MPORT_ERROR_INVALID_DIRECTION;
		}
		break;

		case 1: // PORTB
		switch (Copy_enuPinDirection)
		{
			case MPORT_INPUT:
			CLR_BIT(DDRB_REG, pin_Number);
			break;

			case MPORT_OUTPUT:
			SET_BIT(DDRB_REG, pin_Number);
			break;

			case MPORT_INPUT_PULLUP:
			CLR_BIT(DDRB_REG, pin_Number);
			SET_BIT(PORTB_REG, pin_Number);
			break;

			default:
			return MPORT_ERROR_INVALID_DIRECTION;
		}
		break;
		case 2: // PORTC
		switch (Copy_enuPinDirection)
		{
			case MPORT_INPUT:
			CLR_BIT(DDRC_REG, pin_Number);
			break;

			case MPORT_OUTPUT:
			SET_BIT(DDRC_REG, pin_Number);
			break;

			case MPORT_INPUT_PULLUP:
			CLR_BIT(DDRC_REG, pin_Number);
			SET_BIT(PORTC_REG, pin_Number);
			break;

			default:
			return MPORT_ERROR_INVALID_DIRECTION;
		}
		break;
		case 3: // PORTD
		switch (Copy_enuPinDirection)
		{
			case MPORT_INPUT:
			CLR_BIT(DDRD_REG, pin_Number);
			break;

			case MPORT_OUTPUT:
			SET_BIT(DDRD_REG, pin_Number);
			break;

			case MPORT_INPUT_PULLUP:
			CLR_BIT(DDRD_REG, pin_Number);
			SET_BIT(PORTD_REG, pin_Number);
			break;

			default:
			return MPORT_ERROR_INVALID_DIRECTION;
		}
		break;
		
		default:
		return MPORT_ERROR_INVALID_PIN;
		break;
	}
	
}

// Function: MPORT_enuSetPinMode
// Configures the mode of a specific pin.
MPORT_enuErrorStatus_t MPORT_enuSetPinMode(u8 Copy_enuPinNum, MPORT_enuPinMode_t Copy_enuPinMode)
{
	MPORT_enuErrorStatus_t Ret_enuError = MPORT_NOK;
	u8 port_Number = (Copy_enuPinNum >> 4) & 0x0F; // Extract port number
	u8 pin_Number = Copy_enuPinNum & 0x0F;        // Extract pin number

	// Validate mode
	if (Copy_enuPinMode < PORT_PIN_MODE_INPUT_PULLUP || Copy_enuPinMode > PORT_PIN_MODE_SPI)
	{
		return MPORT_ERROR_INVALID_MODE;
	}

	switch (port_Number)
	{
		case 0: // PORTA
		switch (Copy_enuPinMode)
		{
			case PORT_PIN_MODE_INPUT_PULLUP:
			CLR_BIT(DDRA_REG, pin_Number); // Configure as input
			SET_BIT(PORTA_REG, pin_Number);  // Enable pull-up
			break;
			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLR_BIT(DDRA_REG, pin_Number); // Configure as input
			CLR_BIT(PORTA_REG, pin_Number); // Disable pull-up (external pull-down required)
			break;

			case PORT_PIN_MODE_UART:
			case PORT_PIN_MODE_SPI:
			// Configure UART/SPI registers here as per the microcontroller's specifications
			Ret_enuError = MPORT_ERROR_UNCHANGEABLE_MODE; // Placeholder for now
			break;

			default:
			return MPORT_ERROR_INVALID_MODE;
		}
		Ret_enuError = MPORT_OK;
		break;

		case 1: // PORTB
		switch (Copy_enuPinMode)
		{
			case PORT_PIN_MODE_INPUT_PULLUP:
			CLR_BIT(DDRB_REG, pin_Number);
			SET_BIT(PORTB_REG, pin_Number);
			break;

			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLR_BIT(DDRB_REG, pin_Number);
			CLR_BIT(PORTB_REG, pin_Number);
			break;

			case PORT_PIN_MODE_UART:
			case PORT_PIN_MODE_SPI:
			// Add UART/SPI configuration here
			Ret_enuError = MPORT_ERROR_UNCHANGEABLE_MODE;
			break;

			default:
			return MPORT_ERROR_INVALID_MODE;
		}
		Ret_enuError = MPORT_OK;
		break;

		case 2: // PORTC
		switch (Copy_enuPinMode)
		{
			case PORT_PIN_MODE_INPUT_PULLUP:
			CLR_BIT(DDRC_REG, pin_Number);
			SET_BIT(PORTC_REG, pin_Number);
			break;

			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLR_BIT(DDRC_REG, pin_Number);
			CLR_BIT(PORTC_REG, pin_Number);
			break;

			case PORT_PIN_MODE_UART:
			case PORT_PIN_MODE_SPI:
			// Add UART/SPI configuration here
			Ret_enuError = MPORT_ERROR_UNCHANGEABLE_MODE;
			break;

			default:
			return MPORT_ERROR_INVALID_MODE;
		}
		Ret_enuError = MPORT_OK;
		break;

		case 3: // PORTD
		switch (Copy_enuPinMode)
		{
			case PORT_PIN_MODE_INPUT_PULLUP:
			CLR_BIT(DDRD_REG, pin_Number);
			SET_BIT(PORTD_REG, pin_Number);
			break;

			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLR_BIT(DDRD_REG, pin_Number);
			CLR_BIT(PORTD_REG, pin_Number);
			break;

			case PORT_PIN_MODE_UART:
			case PORT_PIN_MODE_SPI:
			// Add UART/SPI configuration here
			Ret_enuError = MPORT_ERROR_UNCHANGEABLE_MODE;
			break;

			default:
			return MPORT_ERROR_INVALID_MODE;
		}
		Ret_enuError = MPORT_OK;
		break;

		default:
		Ret_enuError = MPORT_ERROR_INVALID_PIN;
		break;
	}

	return Ret_enuError;
}

MPORT_enuErrorStatus_t MPORT_enuSetPortConfigration(u8 Copy_enuPortNum_PinNum, u8 Copy_enuConfigration) {
	//extract port number
	u8 port_Number = (Copy_enuPortNum_PinNum >> 4) & 0x0F;
	//extract pin number
	u8 pin_Number = Copy_enuPortNum_PinNum & 0x0F;
	//validate the configuration
	if (Copy_enuConfigration != PIN_INPUT && Copy_enuConfigration != PIN_OUTPUT)
	{
		return MPORT_ERROR_INVALID_DIRECTION;
	}
	//set the configuration based on the extracted port number
	switch (port_Number)
	{
		case 0: // PORTA
		if (Copy_enuConfigration == PIN_OUTPUT)
		SET_BIT(DDRA_REG, pin_Number);
		else
		(DDRA_REG, pin_Number);
		break;

		case 1: // PORTB
		if (Copy_enuConfigration == PIN_OUTPUT)
		SET_BIT(DDRB_REG, pin_Number);
		else
		CLR_BIT(DDRB_REG, pin_Number);
		break;

		case 2: // PORTC
		if (Copy_enuConfigration == PIN_OUTPUT)
		SET_BIT(DDRC_REG, pin_Number);
		else
		CLR_BIT(DDRC_REG, pin_Number);
		break;

		case 3: // PORTD
		if (Copy_enuConfigration == PIN_OUTPUT)
		SET_BIT(DDRD_REG, pin_Number);
		else
		CLR_BIT(DDRD_REG, pin_Number);
		break;

		default:
		return MPORT_ERROR_INVALID_PIN;
		break;
	}
	return MPORT_OK;

}