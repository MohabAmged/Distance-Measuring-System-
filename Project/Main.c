/*
 * Main.c
 *
 *  Created on: 12 Oct 2022
 *      Author: marwa
 */


/*******************************************************************************
 *                           INCLUDES                                          *
 *******************************************************************************/
#include "UltraSonic.h"
#include "LCD.h"
#include "GPIO.h"
#include "Macros.h"
#include "Std_Types.h"
/*******************************************************************************
 *                           Global Variables                                   *
 *******************************************************************************/
extern IcuConfigType UltraSonic_Config ;

#define F_CPU 8000000UL


int main (void)
{
	/* Setting R/w Pin to lOW */
	GPIO_setupPinDirection(LCD_RS_E_PORT, LCD_RW_PIN, POUTPUT);
	GPIO_writePin(LCD_RS_E_PORT, LCD_RW_PIN, PLOW);

    /* Set UltraSonic Configurations     */
	UltraSonic_Config.Clock=ICU_CLOCK8;
	UltraSonic_Config.Edge =POSITIVE_EDGE;

	/* LCD Init */
     LCD_Init();

    /* Sensor Init */
    Ultrasonic_init();


    /* SENSOR READING */
    uint16 Reading=0;

    /* LCD PRINT */
    LCD_DisplayString("Distance = ");

    /* Enable Interrupts */
    SET_BIT(SREG,7);
    while (1)
     {
    	 /* Get Sensor Reading */
    	 Reading = Ultrasonic_readDistance();

    	 /* Set LCD Cursor Position  */
    	 LCD_MoveCursor(0,11);

    	 /* LCD Display Distance    */
    	 LCD_IntegerDisplay(Reading);
    	 LCD_DisplayString("Cm  ");



     }










	return 0 ;

}
