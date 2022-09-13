/*
 * Button.c
 *
 *  Created on: Sep 5, 2022
 *      Author: Youssef Elbadri
 */

#include "Button.h"

/*Initlize the button by using DIO_init and set it to input*/
EN_Button_error_t Button_init(uint8_t buttonPort, uint8_t buttonPin)
{
    EN_Button_error_t error;
    error = DIO_init(buttonPort, buttonPin, INPUT);
    if(error == DIO_OK)
    {
        return BUTTON_OK;
    }
    else
    {
        return BUTTON_ERROR;
    }
}

/*read the value of a button by using DIO_read*/
EN_Button_error_t Button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{
    EN_Button_error_t error;
    error = DIO_read(buttonPort, buttonPin, value);
    if(error == DIO_OK)
    {
        return BUTTON_OK;
    }
    else
    {
        return BUTTON_ERROR;
    }
}
