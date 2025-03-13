#include "stdtypes.h"
#include "bit_math.h"
#include "DIO.h"
#include "TIMER0.h"
#include "TIMER0_Config.h"

// Global callback function pointers
static Timer0_Callback overflowCallback = NULL;
static Timer0_Callback compareMatchCallback = NULL;

// Set the overflow callback
TIMER0_ERROR_STATUS Timer0_SetOverflowCallback(Timer0_Callback callback) {
    if (callback == NULL) {
        return TIMER0_CALLBACK_NOT_SET;
    }
    overflowCallback = callback;
    return TIMER0_OK;
}

// Set the compare match callback
TIMER0_ERROR_STATUS Timer0_SetCompareMatchCallback(Timer0_Callback callback) {
    if (callback == NULL) {
        return TIMER0_CALLBACK_NOT_SET;
    }
    compareMatchCallback = callback;
    return TIMER0_OK;
}

// Timer0 overflow interrupt service routine
void __vector_11(void) __attribute__((signal, used));
void __vector_11(void) {
    if (overflowCallback != NULL) {
        overflowCallback(); // Call the overflow callback
    }
}

// Timer0 compare match interrupt service routine
void __vector_10(void) __attribute__((signal, used));
void __vector_10(void) {
    if (compareMatchCallback != NULL) {
        compareMatchCallback(); // Call the compare match callback
    }
}

// Enable global interrupts
void Timer0_EnableGlobalInterrupts(void) {
    __asm__ __volatile__ ("sei" ::: "memory");
}

// Disable global interrupts
void Timer0_DisableGlobalInterrupts(void) {
    __asm__ __volatile__ ("cli" ::: "memory");
}

// Rest of the functions remain the same...
TIMER0_ERROR_STATUS Timer0_Init_NormalMode(u8 prescaler) {
    if (prescaler > TIMER0_EXTERNAL_CLOCK_RISING) {
        return TIMER0_INVALID_PRESCALER;
    }
    TIMER0->TCCR0 = prescaler; // Set prescaler
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_Init_CTCMode(u8 prescaler, u8 compareValue) {
    if (prescaler > TIMER0_EXTERNAL_CLOCK_RISING) {
        return TIMER0_INVALID_PRESCALER;
    }
    if (compareValue > 255) {
        return TIMER0_INVALID_COMPARE_VALUE;
    }
    TIMER0->TCCR0 = (1 << WGM01) | prescaler; // Set CTC mode and prescaler
    TIMER0->OCR0 = compareValue; // Set compare value
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_Init_FastPWM(u8 prescaler, u8 dutyCycle) {
    if (prescaler > TIMER0_EXTERNAL_CLOCK_RISING) {
        return TIMER0_INVALID_PRESCALER;
    }
    if (dutyCycle > 100) {
        return TIMER0_INVALID_DUTY_CYCLE;
    }
    TIMER0->TCCR0 = (1 << WGM00) | (1 << WGM01) | prescaler; // Set Fast PWM mode and prescaler
    TIMER0->OCR0 = (dutyCycle * 255) / 100; // Set duty cycle
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_Init_PhaseCorrectPWM(u8 prescaler, u8 dutyCycle) {
    if (prescaler > TIMER0_EXTERNAL_CLOCK_RISING) {
        return TIMER0_INVALID_PRESCALER;
    }
    if (dutyCycle > 100) {
        return TIMER0_INVALID_DUTY_CYCLE;
    }
    TIMER0->TCCR0 = (1 << WGM00) | prescaler; // Set Phase Correct PWM mode and prescaler
    TIMER0->OCR0 = (dutyCycle * 255) / 100; // Set duty cycle
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_Start(void) {
    if (TIMER0->TCCR0 & ((1 << CS02) | (1 << CS01) | (1 << CS00))) {
        return TIMER0_BUSY;
    }
    TIMER0->TCCR0 |= (1 << CS00); // Start Timer0
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_Stop(void) {
    if (!(TIMER0->TCCR0 & ((1 << CS02) | (1 << CS01) | (1 << CS00)))) {
        return TIMER0_BUSY;
    }
    TIMER0->TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00)); // Stop Timer0
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_SetPrescaler(u8 prescaler) {
    if (prescaler > TIMER0_EXTERNAL_CLOCK_RISING) {
        return TIMER0_INVALID_PRESCALER;
    }
    TIMER0->TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00)); // Clear prescaler bits
    TIMER0->TCCR0 |= prescaler; // Set new prescaler
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_SetCompareValue(u8 compareValue) {
    if (compareValue > 255) {
        return TIMER0_INVALID_COMPARE_VALUE;
    }
    TIMER0->OCR0 = compareValue; // Set compare value
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_SetDutyCycle(u8 dutyCycle) {
    if (dutyCycle > 100) {
        return TIMER0_INVALID_DUTY_CYCLE;
    }
    TIMER0->OCR0 = (dutyCycle * 255) / 100; // Set duty cycle
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_EnableOverflowInterrupt(void) {
    TIMER0->TIMSK |= (1 << TOIE0); // Enable overflow interrupt
    Timer0_EnableGlobalInterrupts(); // Enable global interrupts
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_DisableOverflowInterrupt(void) {
    TIMER0->TIMSK &= ~(1 << TOIE0); // Disable overflow interrupt
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_EnableCompareMatchInterrupt(void) {
    TIMER0->TIMSK |= (1 << OCIE0); // Enable compare match interrupt
    Timer0_EnableGlobalInterrupts(); // Enable global interrupts
    return TIMER0_OK;
}

TIMER0_ERROR_STATUS Timer0_DisableCompareMatchInterrupt(void) {
    TIMER0->TIMSK &= ~(1 << OCIE0); // Disable compare match interrupt
    return TIMER0_OK;
}

u8 Timer0_GetCounterValue(void) {
    return TIMER0->TCNT0; // Return current counter value
}

TIMER0_ERROR_STATUS Timer0_ClearCounter(void) {
    TIMER0->TCNT0 = 0; // Clear counter
    return TIMER0_OK;
}