/*
 * External interrupt.h
 *
 *  Created on: Sep 11, 2022
 *      Author: Youssef Elbadri
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_DRIVER_EXTERNAL_INTERRUPT_H_
#define MCAL_EXTERNAL_INTERRUPT_DRIVER_EXTERNAL_INTERRUPT_H_
#include <avr/interrupt.h>
#include "../LIB Driver/Common_Macros.h"
#include "../LIB Driver/Registers.h"
#include "../LIB Driver/STD_Types.h"

typedef enum EN_External_interrupt_error_t 
{
    EX_INTERRUPT_WRONG_INTERRUPT_NUMBER,
    EX_INTERRUPT_WRONG_MODE,
    EX_INTERRUPT_OK
}EN_External_interrupt_error_t;

#define INT_0    0
#define INT_1    1
#define INT_2    2

#define LOW_LEVEL       'a'
#define LOGICAL_CHANGE  'b'
#define FALLING_EDGE    'c'
#define RISING_EDGE     'd'

EN_External_interrupt_error_t EX_Interrupt_init(uint8_t interruptNumber, uint8_t mode);
void Interrupt_start(void);

#endif /* MCAL_EXTERNAL_INTERRUPT_DRIVER_EXTERNAL_INTERRUPT_H_ */
