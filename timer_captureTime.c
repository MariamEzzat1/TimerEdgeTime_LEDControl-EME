#include "timer_captureTime.h"

/***************************************************************************************************
* Function Name: wtimer2_Init
* Parameters (in): None
* Return value: None
* Description: to initialize the wide timer 2 to be in input edge time mode by the following
* steps:
*              - enable the clock of the timer
*              - disable the timer
*              - choose the timer A only to be used from GPTM_WTACFG register
*              - choose the  input edge time mode and count down from GPTM_WTAMR
*              -choose the falling edge to be detected through GPTM_WTACTL register
*              -set the GPTM_WTAILR by the start value - 15 secs
*              -Enable the interrupt to NVIC
*              -Enable the timer's interrupt
*              -then enable the timer2
*
****************************************************************************************************/
void wtimer2_Init(void)
{
    Set_Bit(SYSCTL_RCGCWTIMER_R,TIMER2);                /*enable the clock for timer 2*/


    Clear_Bit(WTIMER2_CTL_R,TAEN_bit);                  /*disable the timer*/

    WTIMER2_CFG_R |= 0x4;                               /* using 32 bit wide mode (timer A)*/

    WTIMER2_TAMR_R |= 0x7;                              /*setting mode to ip edge time, setting direction to count down*/

    Clear_Bit(WTIMER2_CTL_R,TAEVENT_bit1);              /* event edge is set to falling edge*/
    Clear_Bit(WTIMER2_CTL_R,TAEVENT_bit1);

    WTIMER2_TAILR_R = seconds_to_ticks(15);             /*setting start value to 15 --> 15/62.5ns = 240000000 ticks*/

    Set_Bit(NVIC_EN3_R,2);                              /*Enabling the global interrupts*/

    Set_Bit(WTIMER2_IMR_R,2);                           /*Enabling timer interrupt*/

    Set_Bit(WTIMER2_CTL_R,TAEN_bit);                    /*enable the timer*/

}

/***************************************************************************************************
* Function Name: wtimer2Handler
* Parameters (in): None
* Return value: None
* Description: to service the wide timer 2 's interrupt which handles our app
*
****************************************************************************************************/
void wtimer2Handler(void)
{
    if(WTIMER2_TAR_R<= seconds_to_ticks(15) && WTIMER2_TAR_R> seconds_to_ticks(10))     /*From 0 and  below 5 seconds*/
    {
        Set_Bit(GPIO_PORTF_DATA_R,RED_LED);          /*RED LED ON*/
        Clear_Bit(GPIO_PORTF_DATA_R,BLUE_LED);
        Clear_Bit(GPIO_PORTF_DATA_R,GREEN_LED);
    }
    else if(WTIMER2_TAR_R<= seconds_to_ticks(10) && WTIMER2_TAR_R> seconds_to_ticks(5)) /*From 5 and below  10 seconds*/
    {
        Set_Bit(GPIO_PORTF_DATA_R,BLUE_LED);   /*BLUE LED ON*/
        Clear_Bit(GPIO_PORTF_DATA_R,RED_LED);
        Clear_Bit(GPIO_PORTF_DATA_R,GREEN_LED);
    }
    else if(WTIMER2_TAR_R<= seconds_to_ticks(5) && WTIMER2_TAR_R > 0)                   /*From 10 and below  15 seconds*/
    {
        Set_Bit(GPIO_PORTF_DATA_R,GREEN_LED);   /*GREEN LED ON*/
        Clear_Bit(GPIO_PORTF_DATA_R,RED_LED);
        Clear_Bit(GPIO_PORTF_DATA_R,BLUE_LED);
    }

    WTIMER2_TAILR_R = seconds_to_ticks(15);       /*set the load value back to its initial value*/
    Set_Bit(WTIMER2_ICR_R,2);                     /*clearing the module interrupt flag*/
}

/***************************************************************************************************
* Function Name: seconds_to_ticks
* Parameters (in): seconds_num
* Return value: uint32 value
* Description: convert the given number of seconds to the number of ticks based on the timer frequency
*
****************************************************************************************************/
uint32 seconds_to_ticks(uint8 seconds_num)
{
    return (seconds_num/ ((float)1/Fcpu));
}
