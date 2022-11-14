/*
 * ICU.h
 *
 *  Created on: 11 Oct 2022
 *      Author: marwa
 */

#ifndef ICU_H_
#define ICU_H_

/*******************************************************************************
 *                           INCLUDES                                      *
 *******************************************************************************/

#include "avr/io.h"
#include "avr/interrupt.h"
#include "Macros.h"
#include "Std_Types.h"
#include "ICU_Types.h"
#include "GPIO.h"
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
void Icu_Init(const IcuConfigType  * Config_Ptr);

/*
 * Description: Function to set the Call Back function address.
 */
void Icu_SetCallBack(void(*a_ptr)(void));

/*
 * Description: Function to set the required edge detection.
 */
void Icu_SetEdgeDetectionType(const IcuEdgeType edgeType);

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 Icu_GetInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void Icu_ClearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void Icu_DeInit(void);


#endif /* ICU_H_ */
