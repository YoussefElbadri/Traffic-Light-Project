/*
 * Timer.c
 *
 *  Created on: Sep 10, 2022
 *      Author: Youssef Elbadri
 */

#include "Timer.h"

/* Setting the mode by setting the WGMxx bits in TCRRx register */
EN_Timer_error_t Timer_init(uint8_t timerNumber, uint8_t timerMode)
{
    switch (timerNumber)
    {
    case TIMER_0:
        switch (timerMode)
        {
        case NORMAL_MODE:
            CLEAR_BIT(TCCR0, WGM00);
            CLEAR_BIT(TCCR0, WGM01);
            return TIMER_OK;
            break;

        case PWM_PHASE_CORRECT:
            SET_BIT(TCCR0, WGM00);
            CLEAR_BIT(TCCR0, WGM01);
            return TIMER_OK;
            break;

        case CTC:
            CLEAR_BIT(TCCR0, WGM00);
            SET_BIT(TCCR0, WGM01);
            return TIMER_OK;
            break;

        case FAST_PWM:
            SET_BIT(TCCR0, WGM00);
            SET_BIT(TCCR0, WGM01);
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;

    case TIMER_1:
    switch (timerMode)
        {
        case NORMAL_MODE:
            CLEAR_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            CLEAR_BIT(TCCR1B, WGM12);
            CLEAR_BIT(TCCR1B, WGM13);
            return TIMER_OK;
            break;

        case PWM_PHASE_CORRECT:
            SET_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            CLEAR_BIT(TCCR1B, WGM12);
            CLEAR_BIT(TCCR1B, WGM13);
            return TIMER_OK;
            break;

        case CTC:
            CLEAR_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            CLEAR_BIT(TCCR1B, WGM13);
            return TIMER_OK;
            break;

        case FAST_PWM:
            SET_BIT(TCCR1A, WGM10);
            CLEAR_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            CLEAR_BIT(TCCR1B, WGM13);
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;

    case TIMER_2:
        switch (timerMode)
        {
        case NORMAL_MODE:
            CLEAR_BIT(TCCR2, WGM20);
            CLEAR_BIT(TCCR2, WGM21);
            return TIMER_OK;
            break;

        case PWM_PHASE_CORRECT:
            SET_BIT(TCCR2, WGM20);
            CLEAR_BIT(TCCR2, WGM21);
            return TIMER_OK;
            break;

        case CTC:
            CLEAR_BIT(TCCR2, WGM20);
            SET_BIT(TCCR2, WGM21);
            return TIMER_OK;
            break;

        case FAST_PWM:
            SET_BIT(TCCR2, WGM20);
            SET_BIT(TCCR2, WGM21);
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;
    default:
        return TIMER_WRONG_TIMER_NUMBER;
        break;
    }
}

/* Setting the prescaller by setting the CSxx bits in TCRRx register which will start the timer */
EN_Timer_error_t Timer_start(uint8_t timerNumber, uint16_t prescaller)
{
    switch (timerNumber)
    {
    case TIMER_0:
        switch (prescaller)
        {
        case 0:
            SET_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            return TIMER_OK;
            break;
        case 8:
            CLEAR_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            return TIMER_OK;
            break;
        case 64:
            SET_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            return TIMER_OK;
            break;
        case 256:
            CLEAR_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            SET_BIT(TCCR0, CS02);
            return TIMER_OK;
            break;
        case 1024:
            SET_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            SET_BIT(TCCR0, CS02);
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;
    case TIMER_1:
        switch (prescaller)
        {
        case 0:
            SET_BIT(TCCR1B, CS10);
            CLEAR_BIT(TCCR1B, CS11);
            CLEAR_BIT(TCCR1B, CS12);
            return TIMER_OK;
            break;
        case 8:
            CLEAR_BIT(TCCR1B, CS10);
            SET_BIT(TCCR1B, CS11);
            CLEAR_BIT(TCCR1B, CS12);
            return TIMER_OK;
            break;
        case 64:
            SET_BIT(TCCR1B, CS10);
            SET_BIT(TCCR1B, CS11);
            CLEAR_BIT(TCCR1B, CS12);
            return TIMER_OK;
            break;
        case 256:
            CLEAR_BIT(TCCR1B, CS10);
            CLEAR_BIT(TCCR1B, CS11);
            SET_BIT(TCCR1B, CS12);
            return TIMER_OK;
            break;
        case 1024:
            SET_BIT(TCCR1B, CS10);
            CLEAR_BIT(TCCR1B, CS11);
            SET_BIT(TCCR1B, CS12);
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;
    case TIMER_2:
        switch (prescaller)
        {
        case 0:
            SET_BIT(TCCR2, CS20);
            CLEAR_BIT(TCCR2, CS21);
            CLEAR_BIT(TCCR2, CS22);
            return TIMER_OK;
            break;
        case 8:
            CLEAR_BIT(TCCR2, CS20);
            SET_BIT(TCCR2, CS21);
            CLEAR_BIT(TCCR2, CS22);
            return TIMER_OK;
            break;
        case 64:
            SET_BIT(TCCR2, CS20);
            SET_BIT(TCCR2, CS21);
            CLEAR_BIT(TCCR2, CS22);
            return TIMER_OK;
            break;
        case 256:
            CLEAR_BIT(TCCR2, CS20);
            CLEAR_BIT(TCCR2, CS21);
            SET_BIT(TCCR2, CS22);
            return TIMER_OK;
            break;
        case 1024:
            SET_BIT(TCCR2, CS20);
            CLEAR_BIT(TCCR2, CS21);
            SET_BIT(TCCR2, CS22);
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;
    default:
        return TIMER_WRONG_TIMER_NUMBER;
        break;
    }
}

/* Reading the different flags in the TIFR register */
EN_Timer_error_t Timer_read(uint8_t timerNumber, uint8_t timerMode, uint8_t *value)
{
    switch (timerNumber)
    {
    case TIMER_0:
        switch (timerMode)
        {
        case NORMAL_MODE:
            *value = READ_BIT(TIFR, TOV0);
            return TIMER_OK;
            break;
        case CTC:
            *value = READ_BIT(TIFR, OCF0);
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;
    case TIMER_1:
        switch (timerMode)
        {
        case NORMAL_MODE:
            *value = READ_BIT(TIFR, TOV1);
            return TIMER_OK;
            break;
        case CTC:
            *value = READ_BIT(TIFR, OCF1A);
            *value |= (READ_BIT(TIFR, OCF1B)<<1);
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;
    case TIMER_2:
        switch (timerMode)
        {
        case NORMAL_MODE:
            *value = READ_BIT(TIFR, TOV2);
            return TIMER_OK;
            break;
        case CTC:
            *value = READ_BIT(TIFR, OCF2);
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;
    default:
        return TIMER_WRONG_TIMER_NUMBER;
        break;
    }
}

/* 1- Setting the different flags of the timer in the TIFR register
 * 2- Loading the timer with intial value to count from it by load TCNTx with value */
EN_Timer_error_t Timer_reset(uint8_t timerNumber, uint8_t timerMode, uint16_t value)
{
	if (value<0 || value > 65536){
		return TIMER_WRONG_VALUE;
	}
	else
	{
	switch (timerNumber)
    {
    case TIMER_0:
        switch (timerMode)
        {
        case NORMAL_MODE:
            SET_BIT(TIFR, TOV0);
            TCNT0 = value;
            return TIMER_OK;
            break;
        case CTC:
            SET_BIT(TIFR, OCF0);
            TCNT0 = value;
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;
    case TIMER_1:
        switch (timerMode)
        {
        case NORMAL_MODE:
            SET_BIT(TIFR, TOV1);
            TCNT1 = value;
            return TIMER_OK;
            break;
        case CTC:
            SET_BIT(TIFR, OCF1A);
            SET_BIT(TIFR, OCF1B);
            TCNT1 = value;
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;
    case TIMER_2:
        switch (timerMode)
        {
        case NORMAL_MODE:
            SET_BIT(TIFR, TOV2);
            TCNT2 = value;
            break;
        case CTC:
            SET_BIT(TIFR, TOV2);
            TCNT2 = value;
            return TIMER_OK;
            break;
        default:
            return TIMER_WRONG_TIMER_MODE;
            break;
        }
        break;
    default:
        return TIMER_WRONG_TIMER_NUMBER;
        break;
    }
	}
}
