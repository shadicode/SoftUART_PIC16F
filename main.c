//Software UART implementation for PIC16F84A 
// 2016 , Shadi Soundation, http://www.shadi.ch



/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        
#include <stdbool.h>       

#include "system.h"        
#include "user.h"          

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */



/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */

    InitApp();


    while(1)
    {
        /* TODO <INSERT USER APPLICATION CODE HERE> */
    }

}

