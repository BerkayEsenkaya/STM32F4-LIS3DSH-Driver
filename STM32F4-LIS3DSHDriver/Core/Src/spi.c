#include"spi.h"
#include"main.h"

extern SPI_HandleTypeDef hspi1;
extern SPI_Handle_T SPI_1;


uint8_t SPI_TransmitReceive(uint8_t spiNo,uint8_t *pTxdata, uint8_t *pRxdata, uint8_t Txlenght, uint8_t Rxlenght ){
	if(spiNo == SPI_NO1){
		SPI_Com_Active(spiNo);
		HAL_SPI_Transmit_IT(&hspi1, pTxdata, Txlenght);

		if(Rxlenght != 0){
		   HAL_SPI_Receive_IT(&hspi1, pRxdata, Rxlenght);
		}

		SPI_Com_Deactive(spiNo);
	}

}

uint8_t SPI_Com_Active(uint8_t handle){
	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);
}

uint8_t SPI_Com_Deactive(uint8_t handle){
	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_SET);
}