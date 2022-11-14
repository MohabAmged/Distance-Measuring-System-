/*
 * GPIO_Types.h
 *
 *  Created on: 2 Oct 2022
 *      Author: marwa
 */

#ifndef GPIO_TYPES_H_
#define GPIO_TYPES_H_


typedef enum   /*   Enum Def  For Input Or Output Selection  */
{
	PINPUT , POUTPUT


}PinDirectionType;


typedef enum   /*   Enum Def  For Input Or Output (PORT) Selection  */
{
	PORTIN , PORTOUT=0xff


}PortDirectionType;


typedef enum   /*   Enum Def  For Input Or Output (PORT) Selection  */
{
	PLOW , PHIGH


}OutputType;

typedef enum   /*   Enum Def  For Input Or Output (PORT) Selection  */
{
	PORTIDA ,PORTIDB,PORTIDC,PORTIDD


}PortIdType;











#endif /* GPIO_TYPES_H_ */
