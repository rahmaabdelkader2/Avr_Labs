#include "stdtypes.h"
#include "bit_math.h"
#include "DIO.h"
#include "KEYPAD.h"
#include "KEYPAD_Config.h"

KEYPAD_CONNECTION_t KEYPAD_HW_CONNECTION =
{
	.port = KEYPAD_PORT,
	.KPD_u8RowPins = {MDIO_PIN0, MDIO_PIN1, MDIO_PIN2, MDIO_PIN3},
	.KPD_u8ColPins = {MDIO_PIN4, MDIO_PIN5, MDIO_PIN6, MDIO_PIN7}
};
