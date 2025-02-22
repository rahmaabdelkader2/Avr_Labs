#ifndef    EXT_H
#define    EXT_H

typedef enum
{
    EXT_EDGE_RISING,
    EXT_EDGE_FALLING,
    EXT_EDGE_BOTH,
    EXT_LOW_LEVEL
} EXT_Edge_t;

typedef enum
{
    EXT_INT0,
    EXT_INT1,
    EXT_INT2
} EXT_Interrupt_t;

typedef enum
{
    EXT_OK,
    EXT_NOK,
    EXT_INVALID_CALLBACK,
    EXT_WRONG_EDGE,
    EXT_WRONG_INTERRUPT_NUMBER
} EXT_ERROR_Status_t;


#define MCUCR   (*(volatile unsigned char*)0x55)  // Address of MCUCR
#define MCUCSR  (*(volatile unsigned char*)0x54)  // Address of MCUCSR
#define GICR    (*(volatile unsigned char*)0x5B)  // Address of GICR
#define GIFR    (*(volatile unsigned char*)0x5A)  // Address of GIFR

// Define Bit Positions
#define ISC00  0
#define ISC01  1
#define ISC10  2
#define ISC11  3

#define ISC2   6

#define INT0   6
#define INT1   7
#define INT2   5

#define INTF0  6
#define INTF1  7
#define INTF2  5



EXT_ERROR_Status_t EXT_Init(void);

EXT_ERROR_Status_t EXT0_Enable(void);
EXT_ERROR_Status_t EXT1_Enable(void);
EXT_ERROR_Status_t EXT2_Enable(void);

EXT_ERROR_Status_t EXT0_Disable(void);
EXT_ERROR_Status_t EXT1_Disable(void);
EXT_ERROR_Status_t EXT2_Disable(void);

EXT_ERROR_Status_t EXT_SetEdge(EXT_Interrupt_t EXTIx ,EXT_Edge_t edge);

EXT_ERROR_Status_t EXT_SetCallback(EXT_Interrupt_t EXTIx, void (*callback)(void));

#endif    // EXT_H

