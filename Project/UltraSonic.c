/*
 * UltraSonic.c
 *
 *  Created on: 12 Oct 2022
 *      Author: marwa
 */



/*******************************************************************************
 *                           INCLUDES                                      *
 *******************************************************************************/
#include "UltraSonic.h"
#include "math.h"
/*******************************************************************************
 *                           Global Variables                                       *
 *******************************************************************************/
IcuConfigType UltraSonic_Config ;

IcuConfigType * Icu_Config_Ptr =&UltraSonic_Config;

uint16 Global_IcuTimeMeasured = 0 ;

static void (* Func_ptr ) (void) ;

static const uint16  Global_Prescaler[6] ={0,1,8,64,256,1024};
/*******************************************************************************
 *                      Functions Definition                                   *
 *******************************************************************************/

/* Init Function */
void Ultrasonic_init(void)
{


/* Init ICU */
Icu_Init(Icu_Config_Ptr);


/* Setting Call BAck Function */
Func_ptr=Ultrasonic_edgeProcessing;
Icu_SetCallBack(Func_ptr);



/*  Init Trigger Pin */
GPIO_setupPinDirection(ICU_TRIGGER_PORT,ICU_TRIGGER_PIN,POUTPUT);


}

/* Trigger Function*/
void Ultrasonic_Trigger(void)
{
/* Trigger Pin High For 10us */
GPIO_writePin(ICU_TRIGGER_PORT,ICU_TRIGGER_PIN,PHIGH);

/* Delay */
_delay_us(11);

/* Trigger Pin low  */
GPIO_writePin(ICU_TRIGGER_PORT,ICU_TRIGGER_PIN,PLOW);

}

/*  Distance Read Function     */
uint16 Ultrasonic_readDistance(void)
{
	/* Ultrasonic_Trigger */
	Ultrasonic_Trigger();
	/* Variables Init */
	uint16 Distance=0;

	/* Distance Equation return distance in CM */
    Distance = (Global_Prescaler[Icu_Config_Ptr->Clock] / (float) F_CPU ) * Global_IcuTimeMeasured * 17000;


    return Distance;
}



/* Edge Processing Function */
void Ultrasonic_edgeProcessing(void)
{


/*	 Check IF the Module Detect high */
	if( Icu_Config_Ptr->Edge == POSITIVE_EDGE  )
	{
		 /*Reverse Clock Polarity to Measure From +ve Edge To -ve Edge and Set ICR to zero */
		Icu_ClearTimerValue();
		Icu_SetEdgeDetectionType(NEAGTIVE_EDGE);
		Icu_Config_Ptr->Edge=NEAGTIVE_EDGE;   /*Negative Edge Detection*/
	}
	else
	{
		Global_IcuTimeMeasured=Icu_GetInputCaptureValue();
		Icu_SetEdgeDetectionType(POSITIVE_EDGE);
		Icu_Config_Ptr->Edge=POSITIVE_EDGE;   /*Negative Edge Detection */

	}


}
