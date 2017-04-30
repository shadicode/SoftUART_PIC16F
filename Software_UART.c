//Software UART implementation for PIC16F84A 
// 2016 , Shadi Soundation, http://www.shadi.ch

#include "Includes.h"



void InitSoftUART(void)		// Initialize UART pins
{
	UART_TX = 1;			// TX pin is high in idle state
	UART_RX_DIR = 1;		// Input
	UART_TX_DIR = 0;		// Output
        B_LED_DIR = 0;
	INTCON     |= 0x90;     // Enable Global + INT interrupt
	OPTION_REG &= 0xbf;     // Make INT as negedge triggered
}


unsigned char UART_Receive(void)
{
	unsigned char DataValue = 0;

	//wait for start bit
	while(UART_RX==1);

	__delay_us(OneBitDelay);
	__delay_us(OneBitDelay/2);   // Take sample value in the mid of bit duration

	for ( unsigned char i = 0; i < DataBitCount; i++ )
	{
		if ( UART_RX == 1 )   //if received bit is high
		{
			DataValue += (1<<i);
		}
		__delay_us(OneBitDelay);
	}

	// Check for stop bit
	if ( UART_RX == 1 )       //Stop bit should be high
	{
		__delay_us(OneBitDelay/2);
		return DataValue;
	}
	else                      //some error occurred !
	{
		__delay_us(OneBitDelay/2);
		return 0x000;
	}
}




void UART_Transmit(const char DataValue)
{

	// Send Start Bit
	UART_TX = 0;
	__delay_us(OneBitDelay);

	for ( unsigned char i = 0; i < DataBitCount; i++ )
	{
		//Set Data pin according to the DataValue
		if( ((DataValue>>i)&0x1) == 0x1 )   //if Bit is high
		{
			UART_TX = 1;
		}
		else      //if Bit is low
		{
			UART_TX = 0;
		}

	    __delay_us(OneBitDelay);
	}

	//Send Stop Bit
	UART_TX = 1;
	__delay_us(OneBitDelay);
}


void doThings( const char x)
{
B_LED=0;
    switch (x){


        case 'a':  B_LED=1;
                    break;
        case 'b':   
                     B_LED=0;
                     __delay_ms(100);
                     B_LED=1;
                     __delay_ms(100);
                     break;
        case 'c': B_LED=0;
                     __delay_ms(200);
                     B_LED=1;
                     __delay_ms(200);
                     break;
   // Your code here


        default: break;
  

    }
UART_Transmit(x);
}