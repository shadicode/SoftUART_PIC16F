//Software UART implementation for PIC16F84A 
// 2016 , Shadi Soundation, http://www.shadi.ch


#ifndef __SOFT_UART_H
#define __SOFT_UART_H

#ifndef _XTAL_FREQ
 // This definition is required to calibrate __delay_us() and __delay_ms()
 #define _XTAL_FREQ 16000000
#endif
#define Baudrate             4800                      // bps
#define OneBitDelay           (1000000/Baudrate)		// microseconds
#define DataBitCount          8                         // no parity, no flow control
#define UART_RX               RB0						// UART RX pin
#define UART_TX               RA0						// UART TX pin
#define UART_RX_DIR			  TRISB0				// UART RX pin direction register
#define UART_TX_DIR			  TRISA0

#define B_LED_DIR                 TRISB1
#define B_LED			  RB1// UART TX pin direction register

//Function Declarations
void InitSoftUART(void);
unsigned char UART_Receive(void);
void UART_Transmit(const char);
void doThings(const char);


#endif