/*
 * ICU.c
 *
 *  Created on: 11 Oct 2022
 *      Author: marwa
 */


/*******************************************************************************
 *                           INCLUDES                                      *
 *******************************************************************************/
#include "ICU.h"

/*******************************************************************************
 *                           Global Data                                       *
 *******************************************************************************/

static volatile void (* Global_Ptr)(void)=NULL ;

/*******************************************************************************
 *                           ISR                                       *
 *******************************************************************************/
ISR(TIMER1_CAPT_vect)
{
	/* Checking If the Function Call Pointer Not Equal Null */
	if( Global_Ptr != NULL )
	{
		(* Global_Ptr)(); /* Calling The Pointer */

	}


}

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void Icu_Init(const IcuConfigType  * Config_Ptr)
{
	/* Setting ICP to INput */
	GPIO_setupPinDirection(PORTIDD,6, PINPUT);

	/* Force Out Compare =0 */
	TCCR1A = (1<<FOC1A) | (1<<FOC1B) ;

	/* Force Configuration To the Registers */
	TCCR1B = (Config_Ptr->Clock) | (Config_Ptr->Edge)  ;

    /* Enable ICU Interrupt */
    SET_BIT(TIMSK,TICIE1);

	/* Start Count From Zero */
    TCNT1= 0 ;

    /* Putting The ICU Register = 0 */
    ICR1=0;


}

/*
 * Description: Function to set the Call Back function address.
 */
void Icu_SetCallBack(void(*a_ptr)(void))
{
	/* Assign The Function Address To the Global Pointer To be Called At The ISR */
    Global_Ptr=a_ptr;


}

/*
 * Description: Function to set the required edge detection.
 */
void Icu_SetEdgeDetectionType(const IcuEdgeType edgeType)
{

	/*  Setting The polarity Bit As desired  */
	TCCR1B = (TCCR1B & 0xBF) | (edgeType);

}

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 Icu_GetInputCaptureValue(void)
{
	/* Return The ICR1 Register Value*/
	return ICR1 ;

}

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void Icu_ClearTimerValue(void)
{

	/* Clear TCNT1 Register */
	TCNT1 = 0;

}

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void Icu_DeInit(void)
{
	TCCR1A = 0 ; /* Clear Value */
	TCCR1B = 0 ; /* Clear Value */
	TCNT1  = 0 ; /* Clear Value */
	ICR1   = 0 ; /* Clear Value */

	/* Disable Interrupt */
	CLEAR_BIT(TIMSK,TICIE1);



}
