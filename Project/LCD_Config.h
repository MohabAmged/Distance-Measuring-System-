/*
 *                                LCD Driver Configuration Header file
 *
 * Module : LCD_Config.h
 *
 * Author : Mohab Amged
 *
 * Created on: 3 Oct 2022
 *
 */
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*************************************** Includes ***********************************************************************/
#include <avr/io.h>

/*************************************** 4 or 8 pins Mode ***********************************************************************/
#define LCD_PINNUMBER   8

/************************************** Defining LCD port ***********************************************************************/

#define LCD_PORT                PORTIDA  /* Define The Used I/O Port */
#define LCD_RS_E_PORT           PORTIDB  /* Define The Used RS Port */
#define LCD_RS_PIN              0    /* RS Pin # Inside The Selected Port */
#define LCD_E_PIN               2	  /* E Pin # Inside The Selected Port */
#define LCD_RW_PIN              1


#if LCD_PINNUMBER==4   /*     Define The Used PINS */

#define LCD_PIN0       0   /* PIN 0  */
#define LCD_PIN1       1   /* PIN 1 */
#define LCD_PIN2       2   /* PIN 2 */
#define LCD_PIN3       3   /* PIN 3 */

#define LCD_INITCOMM   0x028  /* Instruction to Init LCD WIth 4 Pins Mode */


#elif   LCD_PINNUMBER==8
#define LCD_INITCOMM   0x038 /* Instruction to Init LCD WIth 8 Pins Mode */
#endif


/************************************* LCD Commands define ************************************************************************/
#define LCD_CLEAR                    0x1
#define LCD_DisplayOnCursorOff       0xC
#define LCD_DisplayOnCursorOn        0xE
#define LCD_DisplayOnCursorBlink     0xF
#define LCD_ShiftDisplayLeft         0x18
#define LCD_ShiftDisplayRight        0x1C
#define LCD_Force2ndLine             0xC0
#define LCD_Force1stLine             0x80

/************************************* Type Definition ***********************************************************************************/









#endif /* LCD_CONFIG_H_ */
