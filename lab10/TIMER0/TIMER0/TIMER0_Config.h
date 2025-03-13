#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H

// Timer0 Control Register (TCCR0) bits
#define FOC0   7 // Force Output Compare
#define WGM00  6 // Waveform Generation Mode bit 0
#define COM01  5 // Compare Match Output Mode bit 1
#define COM00  4 // Compare Match Output Mode bit 0
#define WGM01  3 // Waveform Generation Mode bit 1
#define CS02   2 // Clock Select bit 2
#define CS01   1 // Clock Select bit 1
#define CS00   0 // Clock Select bit 0

// Timer0 Interrupt Mask Register (TIMSK) bits
#define OCIE0  1 // Output Compare Match Interrupt Enable
#define TOIE0  0 // Overflow Interrupt Enable

// Timer0 Interrupt Flag Register (TIFR) bits
#define OCF0   1 // Output Compare Flag
#define TOV0   0 // Overflow Flag

// Timer0 Modes
typedef enum {
    TIMER0_NORMAL_MODE,            // Normal mode
    TIMER0_CTC_MODE,               // Clear Timer on Compare Match (CTC) mode
    TIMER0_FAST_PWM_MODE,          // Fast PWM mode
    TIMER0_PHASE_CORRECT_PWM_MODE  // Phase Correct PWM mode
} TIMER0_Mode;

// Timer0 Prescaler Options
typedef enum {
    TIMER0_NO_CLOCK,               // No clock source (Timer/Counter stopped)
    TIMER0_NO_PRESCALER,           // No prescaling (clock = F_CPU)
    TIMER0_PRESCALER_8,            // Prescaler = 8
    TIMER0_PRESCALER_64,           // Prescaler = 64
    TIMER0_PRESCALER_256,          // Prescaler = 256
    TIMER0_PRESCALER_1024,         // Prescaler = 1024
    TIMER0_EXTERNAL_CLOCK_FALLING, // External clock on T0 pin, falling edge
    TIMER0_EXTERNAL_CLOCK_RISING   // External clock on T0 pin, rising edge
} TIMER0_Prescaler;

// Timer0 Configuration Structure
typedef struct {
    TIMER0_Mode mode;       // Timer0 mode (Normal, CTC, Fast PWM, Phase Correct PWM)
    TIMER0_Prescaler prescaler; // Timer0 prescaler
    u8 compareValue;        // Compare value for CTC and PWM modes
    u8 dutyCycle;           // Duty cycle for PWM modes (0-100%)
} TIMER0_ConfigType;

#endif // TIMER0_CONFIG_H