/*
 * application.h
 *
 *  Created on: Sep 11, 2022
 *      Author: Youssef Elbadri
 */

#ifndef APPLICATION_APPLICATION_H_
#define APPLICATION_APPLICATION_H_

#include "../HAL/Button Driver/Button.h"
#include "../HAL/LED Driver/LED.h"
#include "../MCAL/External interrupt Driver/External_interrupt.h"
#include "../MCAL/Timer Driver/Timer.h"

#define CARS_LED_GREEN           2
#define CARS_LED_YELLOW          1
#define CARS_LED_RED             0

#define PEDESTRIANS_LED_GREEN    2
#define PEDESTRIANS_LED_YELLOW   1
#define PEDESTRIANS_LED_RED      0

typedef enum EN_Cars_Traffic_States_t 
{
    RED,
    YELLOW,
    GREEN
}EN_Cars_Traffic_States_t;

EN_Cars_Traffic_States_t currentState;
uint8_t timerFlag = 1, timerValue = 0, pressFlag=0, pressValue=0;

void carsTrafficRed_ON(void);
void carsTrafficYellow_ON(void);
void carsTrafficGreen_ON(void);

void pedestriansTrafficRed_ON(void);
void pedestriansTrafficYellow_ON(void);
void pedestriansTrafficGreen_ON(void);

void Normal_Mode(void);
void Pedestrians_Mode(void);

#endif /* APPLICATION_APPLICATION_H_ */
