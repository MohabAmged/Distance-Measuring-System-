/*
 * GPIO.h
 *
 *  Created on: 2 Oct 2022
 *      Author: marwa
 */


#ifndef GPIO_H_
#define GPIO_H_
#include "Std_Types.h"
#include "GPIO_Types.h"

/* Set Pin Direction Func */
void GPIO_setupPinDirection(PortIdType PORT , uint8 PinNo,PinDirectionType Dir);

/* Wirte Pin  Func */
void GPIO_writePin(PortIdType PORT , uint8 PinNo, OutputType Out);

/* Read Pin  Func */
uint8 GPIO_readPin(PortIdType PORT , uint8 PinNo);

/* Set Port Direction Func */
void GPIO_setupPortDirection(PortIdType port ,PortDirectionType Dir);

/* Write Port Value */
void GPIO_writePort(PortIdType port , uint8 value);

/* Read Port Value */
uint8 GPIO_readPort(PortIdType port);


#endif /* GPIO_H_ */
