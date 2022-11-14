/*
 * UltraSonic.h
 *
 *  Created on: 12 Oct 2022
 *      Author: marwa
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/*******************************************************************************
 *                           INCLUDES                                      *
 *******************************************************************************/
#include "Macros.h"
#include "Std_Types.h"
#include "ICU.h"
#include "GPIO.h"
#include "util/delay.h"
/*******************************************************************************
 *                            Defines                                       *
 *******************************************************************************/
#define ICU_TRIGGER_PORT       PORTIDB

#define ICU_TRIGGER_PIN        5


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* Init Function */
void Ultrasonic_init(void);

/* Trigger Function*/
void Ultrasonic_Trigger(void);

/*  Distance Read Function     */
uint16 Ultrasonic_readDistance(void);

/* Edge Processing Function */
void Ultrasonic_edgeProcessing(void);




#endif /* ULTRASONIC_H_ */
