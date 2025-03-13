#ifndef TIMER0_H
#define TIMER0_H


// Timer0 Error Status Enumeration
typedef enum {
	TIMER0_OK,               // Operation successful
	TIMER0_NOK,              // General error (unspecified)
	TIMER0_BUSY,             // Timer is busy (e.g., already running)
	TIMER0_INVALID_PRESCALER, // Invalid prescaler value provided
	TIMER0_INVALID_MODE,     // Invalid timer mode selected
	TIMER0_INVALID_DUTY_CYCLE, // Invalid duty cycle value (e.g., out of range)
	TIMER0_INVALID_COMPARE_VALUE, // Invalid compare value (e.g., exceeds timer resolution)
	TIMER0_INTERRUPT_NOT_SUPPORTED, // Requested interrupt type is not supported
	TIMER0_CALLBACK_NOT_SET, // Callback function not set for interrupt
	TIMER0_HARDWARE_ERROR,   // Hardware-related error (e.g., timer not functioning)
	TIMER0_UNINITIALIZED,    // Timer not initialized before use
	TIMER0_INVALID_OPERATION // Invalid operation for the current timer mode
} TIMER0_ERROR_STATUS;

// Function pointer type for callbacks
typedef void (*Timer0_Callback)(void);

#define TIMER0_BASE_ADDRESS 0x53
// Timer0 register structure
typedef struct {
	volatile u8 TCCR0;  // Timer/Counter Control Register 0
	volatile u8 TCNT0;  // Timer/Counter Register 0
	volatile u8 OCR0;   // Output Compare Register 0
	volatile u8 reserved; // Reserved byte (not used)
	volatile u8 TIMSK;  // Timer/Counter Interrupt Mask Register
	volatile u8 TIFR;   // Timer/Counter Interrupt Flag Register
} Timer0_Registers;

// Map the struct to the Timer0 base address
#define TIMER0 ((volatile Timer0_Registers *)TIMER0_BASE_ADDRESS)



// Function Prototypes

// Initialization Functions
TIMER0_ERROR_STATUS Timer0_Init_NormalMode(u8 prescaler);
TIMER0_ERROR_STATUS Timer0_Init_CTCMode(u8 prescaler, u8 compareValue);
TIMER0_ERROR_STATUS Timer0_Init_FastPWM(u8 prescaler, u8 dutyCycle);
TIMER0_ERROR_STATUS Timer0_Init_PhaseCorrectPWM(u8 prescaler, u8 dutyCycle);

// Control Functions
TIMER0_ERROR_STATUS Timer0_Start(void);
TIMER0_ERROR_STATUS Timer0_Stop(void);
TIMER0_ERROR_STATUS Timer0_SetPrescaler(u8 prescaler);
TIMER0_ERROR_STATUS Timer0_SetCompareValue(u8 compareValue);
TIMER0_ERROR_STATUS Timer0_SetDutyCycle(u8 dutyCycle);

// Interrupt Functions
TIMER0_ERROR_STATUS Timer0_EnableOverflowInterrupt(void);
TIMER0_ERROR_STATUS Timer0_DisableOverflowInterrupt(void);
TIMER0_ERROR_STATUS Timer0_EnableCompareMatchInterrupt(void);
TIMER0_ERROR_STATUS Timer0_DisableCompareMatchInterrupt(void);
TIMER0_ERROR_STATUS Timer0_SetOverflowCallback(Timer0_Callback callback);
TIMER0_ERROR_STATUS Timer0_SetCompareMatchCallback(Timer0_Callback callback);

// Utility Functions
u8 Timer0_GetCounterValue(void);
TIMER0_ERROR_STATUS Timer0_ClearCounter(void);

#endif // TIMER0_H