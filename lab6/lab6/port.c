#include "stdtypes.h"
#include "private.h"
#include "bit_math.h"
#include "config.h"
#include "port.h"

extern PinConfig_t  MPORT_ArrPinConfig[];

// Function: MPORT_vPortInit
// Initializes all pins in all ports with their configuration based on MPORT_enuArrPinConfig array.
void MPORT_vPortInit(void)
{
	u8 counter;


	// Loop through all pins in all ports and set their configurations
	for (counter = 0; counter < (nummber_of_ports * number_of_pins_per_port); counter++)
	{

		// Configure the pin based on the extracted port and pin numbers
		MPORT_enuSetPinDirection(MPORT_ArrPinConfig[counter].PortNum_PinNum , MPORT_ArrPinConfig[counter].Config);
	}
}




// Function: MPORT_enuSetPinDirection
// Sets the direction of a specific pin in a given port.
MPORT_enuErrorStatus_t MPORT_enuSetPinDirection(u8 Copy_enuPinNum, u8 Copy_enuPinDirection)
{
	MPORT_enuErrorStatus_t Ret_enuError = MPORT_NOK;
	u8 port_Number = (Copy_enuPinNum >> 4) & 0x0F; // Extract port number
	u8 pin_Number = Copy_enuPinNum & 0x0F;        // Extract pin number

	// Validate pin direction
	if (Copy_enuPinDirection != PIN_INPUT && Copy_enuPinDirection != PIN_OUTPUT)
	{
		return MPORT_ERROR_INVALID_DIRECTION;
	}

	// Set the direction based on the extracted port number
	switch (port_Number)
	{
		case 0: // PORTA
		if (Copy_enuPinDirection == PIN_OUTPUT)
		SET_BIT(DDRA, pin_Number);
		else
		CLEAR_BIT(DDRA, pin_Number);
		Ret_enuError = MPORT_OK;
		break;

		case 1: // PORTB
		if (Copy_enuPinDirection == PIN_OUTPUT)
		SET_BIT(DDRB, pin_Number);
		else
		CLEAR_BIT(DDRB, pin_Number);
		Ret_enuError = MPORT_OK;
		break;

		case 2: // PORTC
		if (Copy_enuPinDirection == PIN_OUTPUT)
		SET_BIT(DDRC, pin_Number);
		else
		CLEAR_BIT(DDRC, pin_Number);
		Ret_enuError = MPORT_OK;
		break;

		case 3: // PORTD
		if (Copy_enuPinDirection == PIN_OUTPUT)
		SET_BIT(DDRD, pin_Number);
		else
		CLEAR_BIT(DDRD, pin_Number);
		Ret_enuError = MPORT_OK;
		break;

		default:
		Ret_enuError = MPORT_ERROR_INVALID_PIN;
		break;
	}

	return Ret_enuError;
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
			CLEAR_BIT(DDRA, pin_Number); // Configure as input
			SET_BIT(PORTA, pin_Number);  // Enable pull-up
			break;

			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLEAR_BIT(DDRA, pin_Number); // Configure as input
			CLEAR_BIT(PORTA, pin_Number); // Disable pull-up (external pull-down required)
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
			CLEAR_BIT(DDRB, pin_Number);
			SET_BIT(PORTB, pin_Number);
			break;

			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLEAR_BIT(DDRB, pin_Number);
			CLEAR_BIT(PORTB, pin_Number);
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
			CLEAR_BIT(DDRC, pin_Number);
			SET_BIT(PORTC, pin_Number);
			break;

			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLEAR_BIT(DDRC, pin_Number);
			CLEAR_BIT(PORTC, pin_Number);
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
			CLEAR_BIT(DDRD, pin_Number);
			SET_BIT(PORTD, pin_Number);
			break;

			case PORT_PIN_MODE_INPUT_PULLDOWN:
			CLEAR_BIT(DDRD, pin_Number);
			CLEAR_BIT(PORTD, pin_Number);
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
		SET_BIT(DDRA, pin_Number);
		else
		(DDRA, pin_Number);
		break;

		case 1: // PORTB
		if (Copy_enuConfigration == PIN_OUTPUT)
		SET_BIT(DDRB, pin_Number);
		else
		CLEAR_BIT(DDRB, pin_Number);
		break;

		case 2: // PORTC
		if (Copy_enuConfigration == PIN_OUTPUT)
		SET_BIT(DDRC, pin_Number);
		else
		CLEAR_BIT(DDRC, pin_Number);
		break;

		case 3: // PORTD
		if (Copy_enuConfigration == PIN_OUTPUT)
		SET_BIT(DDRD, pin_Number);
		else
		CLEAR_BIT(DDRD, pin_Number);
		break;

		default:
		return MPORT_ERROR_INVALID_PIN;
		break;
	}
	return MPORT_OK;

}