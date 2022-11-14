/*
 * ICU_Types.h
 *
 *  Created on: 11 Oct 2022
 *      Author: marwa
 */

#ifndef ICU_TYPES_H_
#define ICU_TYPES_H_

/**************************************************************************************
 *                                  Defines                                           *
 **************************************************************************************/
#define ICU_PRESCALER    8

/* Clock Prescaler */
typedef enum {
	ICU_NOCLOCK ,ICU_CLOCK , ICU_CLOCK8,ICU_CLOCK64 ,ICU_CLOCK256,ICU_CLOCK1024

}IcuClockType;



/* Clock Polarity */
typedef enum {

	NEAGTIVE_EDGE,POSITIVE_EDGE=0x40

}IcuEdgeType;



/* ICU Configuration Struct Type  */
typedef struct {

	IcuClockType Clock;   /* Clock Field */
	IcuEdgeType  Edge;    /* Clock Polarity Field */

}IcuConfigType;






#endif /* ICU_TYPES_H_ */
