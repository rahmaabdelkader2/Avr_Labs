#include "bit_math.h"
#include "DIO.h"
#include "DIO_Private.h"


// Function to set a pin value
MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPinNum_t Copy_enuPinNum, MDIO_enuPinConfiguration_t Copy_enuPinConfiguration)
{
   
        switch (Copy_enuPinConfiguration)
        {
            case MDIO_HIGH:
                switch (Copy_enuPortNum)
                {
                    case MDIO_PORTA: SET_BIT(PORTA_REG, Copy_enuPinNum); break;
                    case MDIO_PORTB: SET_BIT(PORTB_REG, Copy_enuPinNum); break;
                    case MDIO_PORTC: SET_BIT(PORTC_REG, Copy_enuPinNum); break;
                    case MDIO_PORTD: SET_BIT(PORTD_REG, Copy_enuPinNum); break;
                    default: return MDIO_NOK;
                }
                break;

            case MDIO_LOW:
                switch (Copy_enuPortNum)
                {
                    case MDIO_PORTA: CLR_BIT(PORTA_REG, Copy_enuPinNum); break;
                    case MDIO_PORTB: CLR_BIT(PORTB_REG, Copy_enuPinNum); break;
                    case MDIO_PORTC: CLR_BIT(PORTC_REG, Copy_enuPinNum); break;
                    case MDIO_PORTD: CLR_BIT(PORTD_REG, Copy_enuPinNum); break;
                    default: return MDIO_NOK;
                }
                break;

            default:
                return MDIO_NOK;
        }
        return MDIO_OK;
    
    return MDIO_NOK;
}

// Function to configure a pin direction
MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPinNum_t Copy_enuPinNum, u8 Copy_u8PinDir)
{
    
        switch (Copy_u8PinDir)
        {
            case MDIO_OUTPUT:
                switch (Copy_enuPortNum)
                {
                    case MDIO_PORTA: SET_BIT(DDRA_REG, Copy_enuPinNum); break;
                    case MDIO_PORTB: SET_BIT(DDRB_REG, Copy_enuPinNum); break;
                    case MDIO_PORTC: SET_BIT(DDRC_REG, Copy_enuPinNum); break;
                    case MDIO_PORTD: SET_BIT(DDRD_REG, Copy_enuPinNum); break;
                    default: return MDIO_NOK;
                }
                break;

            case MDIO_INPUT:
                switch (Copy_enuPortNum)
                {
                    case MDIO_PORTA: CLR_BIT(DDRA_REG, Copy_enuPinNum); CLR_BIT(PORTA_REG, Copy_enuPinNum); break;
                    case MDIO_PORTB: CLR_BIT(DDRB_REG, Copy_enuPinNum); CLR_BIT(PORTB_REG, Copy_enuPinNum); break;
                    case MDIO_PORTC: CLR_BIT(DDRC_REG, Copy_enuPinNum); CLR_BIT(PORTC_REG, Copy_enuPinNum); break;
                    case MDIO_PORTD: CLR_BIT(DDRD_REG, Copy_enuPinNum); CLR_BIT(PORTD_REG, Copy_enuPinNum); break;
                    default: return MDIO_NOK;
                }
                break;

            case MDIO_INPUT_PULLUP:
                switch (Copy_enuPortNum)
                {
                    case MDIO_PORTA: CLR_BIT(DDRA_REG, Copy_enuPinNum); SET_BIT(PORTA_REG, Copy_enuPinNum); break;
                    case MDIO_PORTB: CLR_BIT(DDRB_REG, Copy_enuPinNum); SET_BIT(PORTB_REG, Copy_enuPinNum); break;
                    case MDIO_PORTC: CLR_BIT(DDRC_REG, Copy_enuPinNum); SET_BIT(PORTC_REG, Copy_enuPinNum); break;
                    case MDIO_PORTD: CLR_BIT(DDRD_REG, Copy_enuPinNum); SET_BIT(PORTD_REG, Copy_enuPinNum); break;
                    default: return MDIO_NOK;
                }
                break;

            default:
                return MDIO_NOK;
        }
        return MDIO_OK;
    
    return MDIO_NOK;
}

// Function to set the value of a whole port
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum_t Copy_enuPortNum, u8 Copy_u8PortValue)
{
    if (Copy_enuPortNum <= MDIO_PORTD)
    {
        switch (Copy_enuPortNum)
        {
            case MDIO_PORTA: PORTA_REG = Copy_u8PortValue; break;
            case MDIO_PORTB: PORTB_REG = Copy_u8PortValue; break;
            case MDIO_PORTC: PORTC_REG = Copy_u8PortValue; break;
            case MDIO_PORTD: PORTD_REG = Copy_u8PortValue; break;
            default: return MDIO_NOK;
        }
        return MDIO_OK;
    }
    return MDIO_NOK;
}

// Function to configure the direction of a whole port
MDIO_enuErrorStatus_t MDIO_enuSetPortDir(MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPortConfiguration_t Copy_enuPortConfiguration)
{
    if (Copy_enuPortNum <= MDIO_PORTD)
    {
        switch (Copy_enuPortNum)
        {
            case MDIO_PORTA: DDRA_REG = Copy_enuPortConfiguration; break;
            case MDIO_PORTB: DDRB_REG = Copy_enuPortConfiguration; break;
            case MDIO_PORTC: DDRC_REG = Copy_enuPortConfiguration; break;
            case MDIO_PORTD: DDRD_REG = Copy_enuPortConfiguration; break;
            default: return MDIO_NOK;
        }
        return MDIO_OK;
    }
    return MDIO_NOK;
}

// Function to get the value of a pin
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPinNum_t Copy_enuPinNum, u8* Add_pu8PinValue)
{
    
        switch (Copy_enuPortNum)
        {
            case MDIO_PORTA: *Add_pu8PinValue = GET_BIT(PINA_REG, Copy_enuPinNum); break;
            case MDIO_PORTB: *Add_pu8PinValue = GET_BIT(PINB_REG, Copy_enuPinNum); break;
            case MDIO_PORTC: *Add_pu8PinValue = GET_BIT(PINC_REG, Copy_enuPinNum); break;
            case MDIO_PORTD: *Add_pu8PinValue = GET_BIT(PIND_REG, Copy_enuPinNum); break;
            default: return MDIO_NOK;
        }
        return MDIO_OK;
    
}

