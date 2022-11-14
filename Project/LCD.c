/*
 *                                LCD Driver Src file
 *
 * Module : LCD.c
 *  *
 * Author : Mohab Amged
 *
 * Created on: 3 Oct 2022
 *
 */

/********************************************* Includes *******************************************************************************/
#include "LCD.h"
#include "util/delay.h"
#include "GPIO.h"
#include "Macros.h"
#include "string.h"
/********************************************* Functions Prototypes *******************************************************************************/






void LCD_SendCommand(uint8 Comm) /* Send Commands Func */
{

	GPIO_writePin(LCD_RS_E_PORT,LCD_RS_PIN,PLOW); /* LCD RS Command Select */
    _delay_ms(1);
	/* 8 Bits Command */

#if LCD_PINNUMBER==4   /*     Used 4 Bits */

	/* Writing first 4 Bits Of The Command On LCD Pins*/
	  GPIO_writePin(LCD_PORT,LCD_PIN0,GET_BIT(Comm,0));
	  GPIO_writePin(LCD_PORT,LCD_PIN1,GET_BIT(Comm,1));
	  GPIO_writePin(LCD_PORT,LCD_PIN2,GET_BIT(Comm,2));
	  GPIO_writePin(LCD_PORT,LCD_PIN3,GET_BIT(Comm,3));

	  /* Enable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PHIGH);

		/* Delay for Some Seconds */
		_delay_ms(2);

		/* Disable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PLOW);


	/* Writing Last 4 Bits Of The Command On LCD Pins*/
      GPIO_writePin(LCD_PORT,LCD_PIN0,GET_BIT(Comm,4));
	  GPIO_writePin(LCD_PORT,LCD_PIN1,GET_BIT(Comm,5));
	  GPIO_writePin(LCD_PORT,LCD_PIN2,GET_BIT(Comm,6));
	  GPIO_writePin(LCD_PORT,LCD_PIN3,GET_BIT(Comm,7));

	  /* Enable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PHIGH);

		/* Delay for Some Seconds */
		_delay_ms(2);

		/* Disable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PLOW);



#elif   LCD_PINNUMBER==8 /* Used 8 bits */


		   GPIO_writePort(LCD_PORT, Comm);

	  /* Enable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PHIGH);

		/* Delay for Some Seconds */
		_delay_ms(2);

		/* Disable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PLOW);
#endif



}


void LCD_Init(void) /* Init Func */
{

	_delay_ms(40); /* Delay As Data Sheet */


	/* Make Enable Pin Output */
	GPIO_setupPinDirection(LCD_RS_E_PORT, LCD_E_PIN, POUTPUT);
	/* Make RS Pin Output */
    GPIO_setupPinDirection(LCD_RS_E_PORT, LCD_RS_PIN, POUTPUT);

#if LCD_PINNUMBER==8
	/* LCD PORTS Init */
	GPIO_setupPortDirection(LCD_PORT, PORTOUT);
#elif LCD_PINNUMBER==4

	GPIO_setupPinDirection(LCD_PORT, LCD_PIN0, POUTPUT);
	GPIO_setupPinDirection(LCD_PORT, LCD_PIN1, POUTPUT);
	GPIO_setupPinDirection(LCD_PORT, LCD_PIN2, POUTPUT);
	GPIO_setupPinDirection(LCD_PORT, LCD_PIN3, POUTPUT);

#endif

	/* Mode Selection */
	LCD_SendCommand(LCD_INITCOMM);

	/* Display and Cursor Selection */
	LCD_SendCommand(LCD_DisplayOnCursorOff);

	/* Clear Screen */
	LCD_SendCommand(LCD_CLEAR);
}










void LCD_DisplayChar(uint8 data) /* Send char Func */
{


	GPIO_writePin(LCD_RS_E_PORT,LCD_RS_PIN,PHIGH); /* LCD RS Command Select */ /* LCD RS Command Select */
   _delay_ms(1);
	/* 8 Bits Command */

#if LCD_PINNUMBER==4   /*     Used 4 Bits */

	/* Writing first 4 Bits Of The Data On LCD Pins*/
		  GPIO_writePin(LCD_PORT,LCD_PIN0,GET_BIT(data,0));
		  GPIO_writePin(LCD_PORT,LCD_PIN1,GET_BIT(data,1));
		  GPIO_writePin(LCD_PORT,LCD_PIN2,GET_BIT(data,2));
		  GPIO_writePin(LCD_PORT,LCD_PIN3,GET_BIT(data,3));

	  /* Enable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PHIGH);

		/* Delay for Some Seconds */
		_delay_ms(2);

		/* Disable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PLOW);


		/* Writing Last 4 Bits Of The Command On LCD Pins*/
			  GPIO_writePin(LCD_PORT,LCD_PIN0,GET_BIT(data,4));
			  GPIO_writePin(LCD_PORT,LCD_PIN1,GET_BIT(data,5));
			  GPIO_writePin(LCD_PORT,LCD_PIN2,GET_BIT(data,6));
			  GPIO_writePin(LCD_PORT,LCD_PIN3,GET_BIT(data,7));

	  /* Enable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PHIGH);

		/* Delay for Some Seconds */
		_delay_ms(2);

		/* Disable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PLOW);



#elif   LCD_PINNUMBER==8 /* Used 8 bits */


	   GPIO_writePort(LCD_PORT, data);

	  /* Enable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PHIGH);

		/* Delay for Some Seconds */
		_delay_ms(2);

		/* Disable Sending */
		GPIO_writePin(LCD_RS_E_PORT,LCD_E_PIN,PLOW);
#endif





}
void LCD_DisplayString(const uint8* data) /* Send String Func */
{
uint8 count=0;
	/* Looping Over The String till The End and Send data */
    while(*(data+count) != '\0' )
    {
       /* Send Char Via lcd */
    	LCD_DisplayChar(*(data+count));

    	/* Increment count */
    	count++;

    }

}
void LCD_MoveCursor(uint8 row,uint8 column)/* Move Cursor Func */
{



	// Initialising a Variable To store the address we want to write in
		uint8 Address=0;

		// Test cases for the invalid inputs
		if(column>15 || column<0)
		{
			column=0;
		}
		if(row != 1 && row != 0 )
			{
				row=1;
			}

		// if we want to write at the first row we select the position directlcolumn from column Number
		if(row==0)
		{
			Address=column;

		}

		/* if we want to write at the 2nd row we select the position
		 * by adding column Number +0x40 (data sheet)*/

		else if(row==1)
			{
				Address=0x40+column;

			}
		// address is 7 bits and MSB must be = 1 (data sheet )
			SET_BIT(Address,7);
			// sending command to LCD
			LCD_SendCommand(Address);




}


void LCD_MoveAndDisplayString(uint8* data,uint8 row,uint8 column) /* Move Cursor And Display String Func */
{
	/* Setting The Cursor to The right position */
	LCD_MoveCursor(row,column);

	/* Sending The String */

	LCD_DisplayString(data);

}
void LCD_ClearScreen(void) /* Clear Screen */
{
    /* Send Clear Command */
	LCD_SendCommand(LCD_CLEAR);



}
void LCD_IntegerDisplay(uint8 data) /* Display Integers */
{
	char digits[16];/* String to hold the ascii result */
	itoa(data,digits,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
    LCD_DisplayString(digits); /* Display String */

}










