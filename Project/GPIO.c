/*
 * GPIO.c
 *
 *  Created on: 2 Oct 2022
 *      Author: marwa
 */

#include "GPIO.h"
#include "Macros.h"
#include "GPIO_Types.h"
#include <avr/io.h>

/* Set Pin Direction Func */
void GPIO_setupPinDirection(PortIdType PORT , uint8 PinNo,PinDirectionType Dir)
{
	switch (PORT)
	{

	case PORTIDA:
               if(Dir==PINPUT)
                   {

            	   CLEAR_BIT(DDRA,PinNo);

                   }
               else if(Dir==POUTPUT)

                        {

                           	SET_BIT(DDRA,PinNo);

                        }

                              break;


	case PORTIDB:
               if(Dir==PINPUT)
                   {

            	   CLEAR_BIT(DDRB,PinNo);

                   }
               else if(Dir==POUTPUT)

                        {

                           	SET_BIT(DDRB,PinNo);

                        }

                              break;
	case PORTIDC:
               if(Dir==PINPUT)
                   {

            	   CLEAR_BIT(DDRC,PinNo);

                   }
               else if(Dir==POUTPUT)

                        {

                           	SET_BIT(DDRC,PinNo);

                        }

                              break;


	case PORTIDD:
               if(Dir==PINPUT)
                   {

            	   CLEAR_BIT(DDRD,PinNo);

                   }
               else if(Dir==POUTPUT)

                        {

                           	SET_BIT(DDRD,PinNo);

                        }

                              break;



}


}

/* Wirte Pin  Func */
void GPIO_writePin(PortIdType PORT , uint8 PinNo, OutputType Out)
{

	switch (PORT)
	{

	case PORTIDA:
               if(Out==PLOW)
                   {

            	   CLEAR_BIT(PORTA,PinNo);

                   }
               else if(Out==PHIGH)

                        {

                           	SET_BIT(PORTA,PinNo);

                        }

                              break;


	case PORTIDB:
               if(Out==PLOW)
                   {

            	   CLEAR_BIT(PORTB,PinNo);

                   }
               else if(Out==PHIGH)

                        {

                           	SET_BIT(PORTB,PinNo);

                        }

                              break;
	case PORTIDC:
               if(Out==PLOW)
                   {

            	   CLEAR_BIT(PORTC,PinNo);

                   }
               else if(Out==PHIGH)

                        {

                           	SET_BIT(PORTC,PinNo);

                        }

                              break;


	case PORTIDD:
               if(Out==PLOW)
                   {

            	   CLEAR_BIT(PORTD,PinNo);

                   }
               else if(Out==PHIGH)

                        {

                           	SET_BIT(PORTD,PinNo);

                        }

                              break;



}

}

/* Read Pin  Func */
uint8 GPIO_readPin(PortIdType PORT , uint8 PinNo)
{
	uint8 read=0;
	switch (PORT)
	{

	case PORTIDA:
               read=GET_BIT(PINA,PinNo);
                              break;


	case PORTIDB:
		read=GET_BIT(PINB,PinNo);
                              break;
	case PORTIDC:
		read=GET_BIT(PINC,PinNo);
		                      break;


	case PORTIDD:
		read=GET_BIT(PIND,PinNo);
		break;

          }

	return read;







}


/* Set Port Direction Func */
void GPIO_setupPortDirection(PortIdType port ,PortDirectionType Dir)
{


		switch (port)
		{

		case PORTIDA:
	               DDRA=Dir;
	               break;


		case PORTIDB:
			     DDRB=Dir;
			     break;
		case PORTIDC:
			     DDRC=Dir;
			     break;


		case PORTIDD:
			DDRD=Dir;
			break;

	          }



}

/* Write Port Value */
void GPIO_writePort(PortIdType port , uint8 value)
{


	switch (port)
			{

			case PORTIDA:
		             PORTA=value;
		             break;


			case PORTIDB:
				     PORTB=value;
				     break;
			case PORTIDC:
				     PORTC=value;
				     break;


			case PORTIDD:
				     PORTD=value;
			     	 break;

		          }




}

/* Read Port Value */
uint8 GPIO_readPort(PortIdType port)
{
	uint8 value=0;
	switch (port)
				{

				case PORTIDA:
			             value=PINA;
			             break;


				case PORTIDB:
					     value=PINB;
					     break;
				case PORTIDC:
					     value=PINC;
					     break;


				case PORTIDD:
					     value=PIND;
				     	 break;

			          }

return value;

}
