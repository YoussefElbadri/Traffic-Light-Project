/*
 * Timer.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Youssef Elbadri
 */

#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_

#include "../LIB Driver/Common_Macros.h"
#include "../LIB Driver/Registers.h"
#include "../LIB Driver/STD_Types.h"

typedef enum EN_Timer_error_t 
{
    TIMER_WRONG_TIMER_NUMBER,
    TIMER_WRONG_TIMER_MODE,
    TIMER_WRONG_PRESCALLER,
	TIMER_WRONG_VALUE,
    TIMER_OK
}EN_Timer_error_t;

#define     TIMER_0             'a'
#define     TIMER_1             'b'
#define     TIMER_2             'c'

#define     NORMAL_MODE         0
#define     PWM_PHASE_CORRECT   1
#define     CTC                 2
#define     FAST_PWM            3

EN_Timer_error_t Timer_init(uint8_t timerNumber, uint8_t timerMode);
EN_Timer_error_t Timer_start(uint8_t timerNumber, uint16_t prescaller);
EN_Timer_error_t Timer_read(uint8_t timerNumber, uint8_t timerMode, uint8_t *value);
EN_Timer_error_t Timer_reset(uint8_t timerNumber, uint8_t timerMode, uint16_t value);


#endif /* TIMER_TIMER_H_ */
