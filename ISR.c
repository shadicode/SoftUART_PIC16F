//Software UART implementation for PIC16F84A 
// 2016 , Shadi Soundation, http://www.shadi.ch


#include "Includes.h"



void interrupt ISR(void)
{
	if(INTF)  //If External Edge INT Interrupt
	{
		doThings(UART_Receive());
          

		INTF = 0;    // Clear the interrupt
	}
}
