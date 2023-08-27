#include "rgb_app.h"


/*********************************************************************************************************************
* Function Name: buttonInit
* Parameters (in): port_num and pin_num (uint8)
* Return value: None
* Description: to initialize Button to WT2CCP0
* steps:
*              - init the port by enabling the clock and unlock it
*              - config the given pin as :
*                                         =input pin
*                                         =enable the internal pull-down resistor
*                                         =choose the functionality of WT2CCP0 through AFSEL and PCTL registers
*
**********************************************************************************************************************/
void buttonInit(uint8 port_num, uint8 pin_num)
{
    DIO_Init(port_num);
    DIO_configurePin(port_num, pin_num,INPUT_PIN, DISABLE, ENABLE);

    Set_Bit(GPIO_PORTD_PDR_R,pin_num);
    Set_Bit(GPIO_PORTD_AFSEL_R,pin_num);
    GPIO_PORTD_PCTL_R |= 0x07;      //selecting the alternate function
}

/*********************************************************************************************************************
* Function Name: LedInit
* Parameters (in): None
* Return value: None
* Description: to initialize the  tm4c123GH6PM built-in LEDs
*
**********************************************************************************************************************/
void LedInit(void)
{
    DIO_Init(PORTF_ID);

    Set_Bit(GPIO_PORTF_CR_R,RED_LED);
    Set_Bit(GPIO_PORTF_CR_R,BLUE_LED);
    Set_Bit(GPIO_PORTF_CR_R,GREEN_LED);

    Set_Bit(GPIO_PORTF_DIR_R, RED_LED);
    Set_Bit(GPIO_PORTF_DIR_R, BLUE_LED);
    Set_Bit(GPIO_PORTF_DIR_R, GREEN_LED);

    Set_Bit(GPIO_PORTF_DEN_R,RED_LED);
    Set_Bit(GPIO_PORTF_DEN_R,BLUE_LED);
    Set_Bit(GPIO_PORTF_DEN_R,GREEN_LED);

    Clear_Bit(GPIO_PORTF_DATA_R,RED_LED);
    Clear_Bit(GPIO_PORTF_DATA_R,BLUE_LED);
    Clear_Bit(GPIO_PORTF_DATA_R,GREEN_LED);

}
