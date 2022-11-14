/*
 *                                LCD Driver Header file
 *
 * Module : LCD.h
 *
 * Author : Mohab Amged
 *
 * Created on: 3 Oct 2022
 *
 */

#ifndef LCD_H_
#define LCD_H_

/********************************************* Includes *******************************************************************************/
#include "Std_Types.h"
#include "Macros.h"
#include "LCD_Config.h"

/********************************************* Functions Prototypes *******************************************************************************/

void LCD_SendCommand(uint8 Comm); /* Send Commands Func */

void LCD_Init(void); /* Init Func */

void LCD_DisplayChar(uint8 data); /* Send char Func */

void LCD_DisplayString(const uint8* data); /* Send String Func */

void LCD_MoveCursor(uint8 row,uint8 column); /* Move Cursor Func */

void LCD_MoveAndDisplayString(uint8* data,uint8 row,uint8 column); /* Move Cursor And Display String Func */

void LCD_ClearScreen(void); /* Clear Screen */

void LCD_IntegerDisplay(uint8 data); /* Display Integers */











#endif /* LCD_H_ */
