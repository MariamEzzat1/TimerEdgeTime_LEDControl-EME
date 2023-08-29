
#ifndef DIO_H_
#define DIO_H_

#include "bitwise_operations.h"
#include "hw_gpio.h"
#include "std_types.h"

#define Fcpu                   (uint32)16000000

#define PORTA_ID               (uint8)0
#define PORTB_ID               (uint8)1
#define PORTC_ID               (uint8)2
#define PORTD_ID               (uint8)3
#define PORTE_ID               (uint8)4
#define PORTF_ID               (uint8)5


typedef enum
{
    INPUT_PIN, OUTPUT_PIN
}GPIO_PinDirectionType;

typedef enum
{
    DISABLE, ENABLE
}ENABLE_DISABLE;

#define LOGIC_HIGH              1U
#define LOGIC_LOW               0U

#define RED_LED                 1U
#define BLUE_LED                2U
#define GREEN_LED               3U


void DIO_Init(uint8 port_num);

void DIO_configurePin(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction ,ENABLE_DISABLE pur_val, ENABLE_DISABLE den_val );

void DIO_Write_Pin(uint8 port_num, uint8 pin_num, uint8 value);



uint8 DIO_readPin(uint8 port_num, uint8 pin_num);


#endif /* DIO_H_ */
