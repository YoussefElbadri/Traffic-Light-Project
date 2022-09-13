/*
 * DIO.c
 *
 *  Created on: Sep 5, 2022
 *      Author: Youssef Elbadri
 */
#include "DIO.h"

/*Setting a pin to whether input or output by clearing or setting its bit in DDRx register*/
EN_DIO_error_t DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
    if (pinNumber<0 || pinNumber>7)
    {
        return DIO_WRONG_PIN_NUMBER;
    }
    else
    {
    switch (portNumber)
    {
    case PORT_A:
        switch(direction)
         {
           case OUTPUT:
                SET_BIT(DDRA, pinNumber);
                return DIO_OK; 
                break;
            case INPUT:
                CLEAR_BIT(DDRA, pinNumber);
                return DIO_OK; 
                break;
            default:
                return DIO_WRONG_DIRECTION;
                break;
         }
         break;

    case PORT_B:
        switch(direction)
         {
           case OUTPUT:
                SET_BIT(DDRB, pinNumber);
                return DIO_OK; 
                break;
            case INPUT:
                CLEAR_BIT(DDRB, pinNumber);
                return DIO_OK; 
                break;
            default:
                return DIO_WRONG_DIRECTION;
                break;
         }
         break;

    case PORT_C:
        switch(direction)
         {
           case OUTPUT:
                SET_BIT(DDRC, pinNumber);
                return DIO_OK; 
                break;
            case INPUT:
                CLEAR_BIT(DDRC, pinNumber);
                return DIO_OK; 
                break;
            default:
                return DIO_WRONG_DIRECTION;
                break;
         }
         break;

    case PORT_D:
        switch(direction)
         {
           case OUTPUT:
                SET_BIT(DDRD, pinNumber);
                return DIO_OK; 
                break;
            case INPUT:
                CLEAR_BIT(DDRD, pinNumber);
                return DIO_OK; 
                break;
            default:
                return DIO_WRONG_DIRECTION;
                break;
         }
         break;
    default:
        return DIO_WRONG_PORT_NUMBER;
        break;
    }
}
}

/*Setting the output of a pin by clearing or setting its bit in PORTx register*/
EN_DIO_error_t DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
    if (pinNumber<0 || pinNumber>7)
    {
        return DIO_WRONG_PIN_NUMBER;
    }
    else
    {
    switch (portNumber)
    {
    case PORT_A:
        switch (value)
        {
        case HIGH:
            SET_BIT(PORTA, pinNumber);
            return DIO_OK; 
            break;
        case LOW:
            CLEAR_BIT(PORTA, pinNumber);
            return DIO_OK; 
            break;
        default:
            return DIO_WRONG_DIRECTION;
            break;
        }
        break;
    case PORT_B:
        switch (value)
        {
        case HIGH:
            SET_BIT(PORTB, pinNumber);
            return DIO_OK; 
            break;
        case LOW:
            CLEAR_BIT(PORTB, pinNumber);
            return DIO_OK; 
            break;
        default:
            return DIO_WRONG_DIRECTION;
            break;
        }
        break;
    case PORT_C:
        switch (value)
        {
        case HIGH:
            SET_BIT(PORTC, pinNumber);
            return DIO_OK; 
            break;
        case LOW:
            CLEAR_BIT(PORTC, pinNumber);
            return DIO_OK; 
            break;
        default:
            return DIO_WRONG_DIRECTION;
            break;
        }
        break;
    case PORT_D:
        switch (value)
        {
        case HIGH:
            SET_BIT(PORTD, pinNumber);
            return DIO_OK; 
            break;
        case LOW:
            CLEAR_BIT(PORTD, pinNumber);
            return DIO_OK; 
            break;
        default:
            return DIO_WRONG_DIRECTION;
            break;
        }
        break;

    default:
        return DIO_WRONG_PORT_NUMBER;
        break;
    }
    }
}

/*Read the value of an input pin by reading the value of its bit in PINx register*/
EN_DIO_error_t DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value)
{
    if (pinNumber<0 || pinNumber>7)
    {
        return DIO_WRONG_PIN_NUMBER;
    }
    else
    {
    switch (portNumber)
    {
    case PORT_A:
        *value = READ_BIT(PINA, pinNumber);
        return DIO_OK;
        break;

    case PORT_B:
        *value = READ_BIT(PINB, pinNumber);
        return DIO_OK;
        break;
    
    case PORT_C:
        *value = READ_BIT(PINC, pinNumber);
        return DIO_OK;
        break;
    
    case PORT_D:
        *value = READ_BIT(PIND, pinNumber);
        return DIO_OK;
        break;

    default:
        return DIO_WRONG_PORT_NUMBER;
        break;
    }
    }  

}

/*Toggling the output of an pin by toggling its bit in the PORTx register*/
EN_DIO_error_t DIO_toggle(uint8_t portNumber, uint8_t pinNumber)
{
    if (pinNumber<0 || pinNumber>7)
    {
        return DIO_WRONG_PIN_NUMBER;
    }
    else
    {
    switch (portNumber)
    {
    case PORT_A:
        TOGGLE_BIT(PORTA, pinNumber);
        return DIO_OK;
        break;

    case PORT_B:
        TOGGLE_BIT(PORTB, pinNumber);
        return DIO_OK;
        break;
    
    case PORT_C:
        TOGGLE_BIT(PORTC, pinNumber);
        return DIO_OK;
        break;
    
    case PORT_D:
        TOGGLE_BIT(PORTD, pinNumber);
        return DIO_OK;
        break;

    default:
        return DIO_WRONG_PORT_NUMBER;
        break;
    }
    }
 
}
