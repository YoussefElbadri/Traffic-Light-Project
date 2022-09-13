/*
 * LED.c
 *
 *  Created on: Sep 5, 2022
 *      Author: Youssef Elbadri
 */

#include "LED.h"

/*Use DIO_init function to inilize the LED*/
EN_LED_error_t LED_init(uint8_t LEDPort, uint8_t LEDPin)
{
    EN_DIO_error_t error;
    error = DIO_init(LEDPort, LEDPin, OUTPUT);
    if(error == DIO_OK)
    {
        return LED_OK;
    }
    else
    {
        return LED_ERROR;
    }
}

/*Set the LED on by using the DIO_write function and write high in its appropiate bit*/
EN_LED_error_t LED_on(uint8_t LEDPort, uint8_t LEDPin)
{
    EN_DIO_error_t error;
    error = DIO_write(LEDPort, LEDPin, HIGH);
    if(error == DIO_OK)
    {
        return LED_OK;
    }
    else
    {
        return LED_ERROR;
    }
}

/*Set the LED off by using the DIO_write function and write low in its appropiate bit*/
EN_LED_error_t LED_off(uint8_t LEDPort, uint8_t LEDPin)
{
    EN_DIO_error_t error;
    error = DIO_write(LEDPort, LEDPin, LOW);
    if(error == DIO_OK)
    {
        return LED_OK;
    }
    else
    {
        return LED_ERROR;
    }
}

EN_LED_error_t LED_toggle(uint8_t LEDPort, uint8_t LEDPin)
{
    EN_DIO_error_t error;
    error = DIO_toggle(LEDPort, LEDPin);
    if(error == DIO_OK)
    {
        return LED_OK;
    }
    else
    {
        return LED_ERROR;
    }
}
