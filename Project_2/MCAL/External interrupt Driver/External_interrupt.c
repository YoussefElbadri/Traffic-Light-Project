/*
 * External interrupt.c
 *
 *  Created on: Sep 11, 2022
 *      Author: Youssef Elbadri
 */
#include "External_interrupt.h"

/*1- Enable the external interrupt by setting the INTx bit in the GICR register
 *2- Select the working mode by set the ISCxx bits in the MCUCR and MCUCSR registers*/
EN_External_interrupt_error_t EX_Interrupt_init(uint8_t interruptNumber, uint8_t mode)
{
    switch (interruptNumber)
    {
    case INT_0:
        switch (mode)
        {
        case LOW_LEVEL:
            CLEAR_BIT(MCUCR, ISC00);
            CLEAR_BIT(MCUCR, ISC01);
            SET_BIT(GICR, INT0);
            return EX_INTERRUPT_OK;
            break;
        case LOGICAL_CHANGE:
            SET_BIT(MCUCR, ISC00);
            CLEAR_BIT(MCUCR, ISC01);
            SET_BIT(GICR, INT0);
            return EX_INTERRUPT_OK;
            break;
        case FALLING_EDGE:
            CLEAR_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
            SET_BIT(GICR, INT0);
            return EX_INTERRUPT_OK;
            break;
        case RISING_EDGE:
            SET_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
            SET_BIT(GICR, INT0);
            return EX_INTERRUPT_OK;
            break;
        default:
            return EX_INTERRUPT_WRONG_MODE;
            break;
        }    
        break;
    case INT_1:
        switch (mode)
        {
        case LOW_LEVEL:
            CLEAR_BIT(MCUCR, ISC10);
            CLEAR_BIT(MCUCR, ISC11);
            SET_BIT(GICR, INT1);
            return EX_INTERRUPT_OK;
            break;
        case LOGICAL_CHANGE:
            SET_BIT(MCUCR, ISC10);
            CLEAR_BIT(MCUCR, ISC11);
            SET_BIT(GICR, INT1);
            return EX_INTERRUPT_OK;
            break;
        case FALLING_EDGE:
            CLEAR_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
            SET_BIT(GICR, INT1);
            return EX_INTERRUPT_OK;
            break;
        case RISING_EDGE:
            SET_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
            SET_BIT(GICR, INT1);
            return EX_INTERRUPT_OK;
            break;
        default:
            return EX_INTERRUPT_WRONG_MODE;
            break;
        }    
        break;
    case INT_2:
        switch (mode)
        {
        case FALLING_EDGE:
            CLEAR_BIT(MCUCSR, ISC2);
            SET_BIT(GICR, INT2);
            return EX_INTERRUPT_OK;
            break;
        case RISING_EDGE:
            SET_BIT(MCUCSR, ISC2);
            SET_BIT(GICR, INT2);
            return EX_INTERRUPT_OK;
            break;
        default:
            return EX_INTERRUPT_WRONG_MODE;
            break;
        }    
        break;
    default:
        return EX_INTERRUPT_WRONG_INTERRUPT_NUMBER;
        break;
    }
}

/*Start the interrupt by setting the global interrupt bit in the SREG register */
void Interrupt_start(void)
{
    sei();
}
