
#include "application.h"

ISR(INT0_vect)
{
	Pedestrians_Mode();
}


int main()
{
	/*External Interrupt Initialization*/
	EX_Interrupt_init(INT_0, LOGICAL_CHANGE);
	Interrupt_start();

	/*LED Initialization*/
	LED_init(PORT_A, CARS_LED_GREEN);
	LED_init(PORT_A, CARS_LED_YELLOW);
	LED_init(PORT_A, CARS_LED_RED);
	LED_init(PORT_B, PEDESTRIANS_LED_GREEN);
	LED_init(PORT_B, PEDESTRIANS_LED_YELLOW);
	LED_init(PORT_B, PEDESTRIANS_LED_RED);

	/*Timer Initialization*/
	Timer_init(TIMER_0, NORMAL_MODE);
	Timer_start(TIMER_0, 1024);
	Timer_reset(TIMER_0, NORMAL_MODE, 10);

	while (1)
	{
		Normal_Mode();
	}

}

void Pedestrians_Mode(void)
{

	++pressFlag;
	if (pressFlag == 1)
	{
		pressValue = timerValue;
	}
	if(pressFlag == 2)
	{
		if (timerValue - pressValue < (2*4))
		{
			timerValue = 0;
				Timer_reset(TIMER_0, NORMAL_MODE, 10);
				if (currentState == RED)
				{
					while(timerValue < (5*4))
					{
						Timer_read(TIMER_0, NORMAL_MODE, &timerFlag);
						if (timerFlag == 1)
						{
							Timer_reset(TIMER_0, NORMAL_MODE, 10);
							++timerValue;
						}
						carsTrafficRed_ON();
						pedestriansTrafficGreen_ON();
					}
					timerValue = (5*4);
					Timer_reset(TIMER_0, Normal_Mode, 10);
				}

				else
				{
					while(timerValue < (5*4))
					{
						Timer_read(TIMER_0, NORMAL_MODE, &timerFlag);
						if (timerFlag == 1)
						{
							Timer_reset(TIMER_0, NORMAL_MODE, 10);
							++timerValue;
						}
						if(timerValue%5==0)
						{
							carsTrafficYellow_ON();
							pedestriansTrafficYellow_ON();
						}
					}
					while((5*4) <= timerValue && timerValue < (10*4) )
					{
						Timer_read(TIMER_0, NORMAL_MODE, &timerFlag);
						if (timerFlag == 1)
						{
							Timer_reset(TIMER_0, NORMAL_MODE, 10);
							++timerValue;
						}
						carsTrafficRed_ON();
						pedestriansTrafficGreen_ON();
					}
					timerValue = (5*4);
					Timer_reset(TIMER_0, Normal_Mode, 10);
				}

		}
		pressFlag = 0;
	}
}

void Normal_Mode(void)
{
	Timer_read(TIMER_0, NORMAL_MODE, &timerFlag);
	if (timerFlag == 1)
	{
		Timer_reset(TIMER_0, NORMAL_MODE, 10);
		++timerValue;
	}
	if (timerValue < (5*4))
	{
		carsTrafficRed_ON();
		pedestriansTrafficGreen_ON();
		currentState = RED;
	}
	if (timerValue%5==0 && (5*4) <= timerValue && timerValue < (10*4))
	{
		carsTrafficYellow_ON();
		pedestriansTrafficRed_ON();
		currentState = YELLOW;
	}
	if ((10*4) <= timerValue && timerValue  < (15*4))
	{
		carsTrafficGreen_ON();
		pedestriansTrafficRed_ON();
		currentState = GREEN;
	}
	if (timerValue%5==0 && (15*4) <= timerValue && timerValue  < (20*4))
	{
		carsTrafficYellow_ON();
		pedestriansTrafficRed_ON();
		currentState = YELLOW;
	}
	if (timerValue == 20*4)
	{
		timerValue = 0;
	}
}

void carsTrafficRed_ON(void)
{
	LED_on(PORT_A, CARS_LED_RED);
	LED_off(PORT_A, CARS_LED_YELLOW);
	LED_off(PORT_A, CARS_LED_GREEN);
}
void carsTrafficYellow_ON(void)
{
	LED_off(PORT_A, CARS_LED_RED);
	LED_toggle(PORT_A, CARS_LED_YELLOW);
	LED_off(PORT_A, CARS_LED_GREEN);
}
void carsTrafficGreen_ON(void)
{
	LED_off(PORT_A, CARS_LED_RED);
	LED_off(PORT_A, CARS_LED_YELLOW);
	LED_on(PORT_A, CARS_LED_GREEN);
}

void pedestriansTrafficRed_ON(void)
{
	LED_on(PORT_B, PEDESTRIANS_LED_RED);
	LED_off(PORT_B, PEDESTRIANS_LED_YELLOW);
	LED_off(PORT_B, PEDESTRIANS_LED_GREEN);
}

void pedestriansTrafficYellow_ON(void)
{
	LED_off(PORT_B, PEDESTRIANS_LED_RED);
	LED_toggle(PORT_B, PEDESTRIANS_LED_YELLOW);
	LED_off(PORT_B, PEDESTRIANS_LED_GREEN);
}

void pedestriansTrafficGreen_ON(void)
{
	LED_off(PORT_B, PEDESTRIANS_LED_RED);
	LED_off(PORT_B, PEDESTRIANS_LED_YELLOW);
	LED_on(PORT_B, PEDESTRIANS_LED_GREEN);
}

void pedestriansTraffic_OFF(void)
{
	LED_off(PORT_B, PEDESTRIANS_LED_RED);
	LED_off(PORT_B, PEDESTRIANS_LED_YELLOW);
	LED_off(PORT_B, PEDESTRIANS_LED_GREEN);
}
