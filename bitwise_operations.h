

#ifndef BITWISE_OPERATIONS_H_
#define BITWISE_OPERATIONS_H_

#define Set_Bit(Register,Bit) ( Register =( (uint32) ( ((uint32)( Register) )) | ( (uint32) ((uint32)1U<< (Bit)) )) )
#define Clear_Bit(Register,Bit) ( Register = ((uint32)( Register)) & ((uint32)(~((uint32)1U << ((uint32)(Bit)))) ))
#define Get_Bit(Register,Bit) ( ( ((uint32)(Register))>>((uint32)(Bit)))& (uint32)1U )
#define Toggle_Bit(Register,Bit) ((Register) = ((uint32)(Register)) ^ ((uint32)((uint32)1U <<(uint32)(Bit))))




#endif /* BITWISE_OPERATIONS_H_ */
