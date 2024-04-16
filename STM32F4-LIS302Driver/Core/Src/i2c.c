/******************************************************************************
 *** INCLUDES
 ******************************************************************************/
//#include "cmsis_os2.h"                  // ::CMSIS:RTOS2
//#include "stm32l4xx_hal.h"                  // Device header
#include"stm32f4xx_hal.h"
#include "i2c.h"

/******************************************************************************
 *** DEFINES
 ******************************************************************************/
#define I2C_UnusedDataBuffer_Size 255

/******************************************************************************
 *** VARIABLES
 ******************************************************************************/
//osEventFlagsId_t EventFlag_ID_I2C;

I2C_Module_T I2C_1, I2C_2, I2C_3;
I2C_TxRx_T stat;
uint8_t I2C_UnusedDataBuffer[I2C_UnusedDataBuffer_Size];

I2C_Module_T *I2C_GetI2CModuleFromNo(uint8_t i2cNo);

/******************************************************************************
 *** GLOBAL FUNCTIONS
******************************************************************************/
/** \brief
 */
uint8_t I2C_Init(uint8_t i2cNo, void *handle, uint32_t bitRate_Hz, uint8_t mode ){
  I2C_Module_T *i2c;

	i2c = I2C_GetI2CModuleFromNo(i2cNo);
	//if(!EventFlag_ID_I2C){
	//	EventFlag_ID_I2C=osEventFlagsNew(NULL);
	//}

	i2c->Handle = handle;
	i2c->bitrate = bitRate_Hz;
	i2c->mode = mode;

	//if(!i2c->accessSemaphore){
	//	i2c->accessSemaphore=osSemaphoreNew(1, 1, NULL);
	//}
	return 1;
}

/** \brief
 */
uint8_t I2C_GetAccess(uint8_t i2cNo, uint32_t wait_ms){
	//return (osSemaphoreAcquire(I2C_GetI2CModuleFromNo(i2cNo)->accessSemaphore, wait_ms)==osOK);
}

/** \brief
 */
uint8_t I2C_ReleaseAccess(uint8_t i2cNo){
	//return (osSemaphoreRelease(I2C_GetI2CModuleFromNo(i2cNo)->accessSemaphore)==osOK);
}

/** \brief
 */
uint8_t I2C_SendReceive(uint8_t i2cNo,uint8_t DevAddress,uint8_t *txData, uint32_t txLength, uint8_t *rxData, uint32_t rxLength, uint32_t timeout_ms){
    I2C_Module_T *i2c;
	uint8_t *txdat, *rxdat;
	uint32_t flagResult, flagMask;
	uint16_t txDevAddr, rxDevAddr;
    uint8_t i;

	txDevAddr = (DevAddress<<1)&(0b11111110);
	rxDevAddr = (DevAddress<<1)|(0b00000001);

	if((txLength+rxLength)>I2C_UnusedDataBuffer_Size){
		return 0;
	}

	if(txData){
		txdat=txData;
	}else{
		txdat=I2C_UnusedDataBuffer;
	}
	if(rxData){
		rxdat=rxData;
		stat.RW_mode = WriteRead;
	}else{
		rxdat=I2C_UnusedDataBuffer;
		stat.RW_mode = Write;
	}
	i2c = I2C_GetI2CModuleFromNo(i2cNo);
	/*
	switch(i2cNo){
		case I2C_NO1: flagMask=EventFlagMask_I2CHandle_I2C1TxRxComplete; break;
     	case I2C_NO2: flagMask=EventFlagMask_I2CHandle_I2C2TxRxComplete; break;
		case I2C_NO3: flagMask=EventFlagMask_I2CHandle_I2C3TxRxComplete; break;
	}
*/
	if(stat.RW_mode == Write){
		HAL_I2C_Master_Transmit(i2c->Handle,(uint16_t)txDevAddr,txdat,txLength,timeout_ms);
	}else if(stat.RW_mode == WriteRead){
		//HAL_I2C_Master_Transmit(&hi2c1, devaddrW,devidaddr , 2, 50);
		//HAL_I2C_Master_Receive(&hi2c1, devaddrR, rxBuff, 2, 50);
		HAL_I2C_Master_Transmit(i2c->Handle,(uint16_t)txDevAddr,txdat,txLength,timeout_ms);
	    HAL_I2C_Master_Receive(i2c->Handle,(uint16_t)rxDevAddr,rxdat,rxLength,timeout_ms);
	}else{
		return 0;
	}
/*
  if(timeout_ms){

	  //flagResult=osEventFlagsWait(EventFlag_ID_I2C, flagMask, osFlagsWaitAny, timeout_ms);
		if(flagResult&osFlagsError){
			return 0;
		}else{
			return 1;
		}
	}else{
		return 1;
	}
	*/
}

/** \brief
 */
uint8_t I2C_SendReceiveCompleteCallback(uint8_t i2cNo){
	I2C_Module_T *i2c;
	i2c=I2C_GetI2CModuleFromNo(i2cNo);
	//I2C_ReleaseAccess(i2cNo);

	//switch(i2cNo){

	//case I2C_NO1:
	//	osEventFlagsSet(EventFlag_ID_I2C, EventFlagMask_I2CHandle_I2C1TxRxComplete);
	//return 1;

	//case I2C_NO2:
	//	osEventFlagsSet(EventFlag_ID_I2C, EventFlagMask_I2CHandle_I2C2TxRxComplete);
			//return 1;

	//case I2C_NO3:
	//	osEventFlagsSet(EventFlag_ID_I2C, EventFlagMask_I2CHandle_I2C3TxRxComplete);
	//return 1;

	//default: return 0;
	//}
}

/******************************************************************************
 *** PRIVATE FUNCTIONS
 ******************************************************************************/
I2C_Module_T *I2C_GetI2CModuleFromNo(uint8_t i2cNo){

	switch(i2cNo){
		case I2C_NO1: return &I2C_1;
		case I2C_NO2: return &I2C_2;
		case I2C_NO3: return &I2C_3;
		default: return NULL;
	}
}

#if STM32L433xx
/** \brief Callback function for ST microcontroller SPI data exchange complete
 * \param[in] hspi Ptr to ST SPI peripheral object
 * \return Nothing
 * \note This implementation is specific to STM microcontrollers not to be implemented for NXP microcontrollers
 */
void HAL_I2C_TxRxCpltCallback(I2C_HandleTypeDef *hi2c){

	uint8_t i2cNo;

	if(hi2c==I2C_1.Handle){
		i2cNo=I2C_NO1;
	}else if(hi2c==I2C_2.Handle){
		i2cNo=I2C_NO2;
	}else if(hi2c==I2C_3.Handle){
		i2cNo=I2C_NO3;
	}

	I2C_SendReceiveCompleteCallback(i2cNo);
}
#else if STM32F4xx
/** \brief Callback function for ST microcontroller SPI data exchange complete
 * \param[in] hspi Ptr to ST SPI peripheral object
 * \return Nothing
 * \note This implementation is specific to STM microcontrollers not to be implemented for NXP microcontrollers
 */
void HAL_I2C_TxRxCpltCallback(I2C_HandleTypeDef *hi2c){

	uint8_t i2cNo;

	if(hi2c==I2C_1.Handle){
		i2cNo=I2C_NO1;
	}else if(hi2c==I2C_2.Handle){
		i2cNo=I2C_NO2;
	}else if(hi2c==I2C_3.Handle){
		i2cNo=I2C_NO3;
	}

	I2C_SendReceiveCompleteCallback(i2cNo);
}
#endif

/*** END OF FILE **************************************************************/
