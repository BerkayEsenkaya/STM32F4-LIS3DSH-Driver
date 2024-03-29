#include"stdint.h"
#include"main.h"
#include<lis302.h>


#define LSD3HH_SPIMODE_READ  0b10000000
#define LSD3HH_SPIMODE_WRITE 0b00111111


extern SPI_HandleTypeDef hspi1;
LIS3DHH_Module_T LIS3DHH_Module_1;



uint8_t LIS3DHH_Read_Reg(SPI_HandleTypeDef *handle, uint8_t RegAddr, uint8_t *rxBuff,uint8_t lenght){
	uint8_t txBuff[1];

	txBuff[0] = RegAddr | LSD3HH_SPIMODE_READ;
	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

    HAL_SPI_Transmit(handle, txBuff, 1, 50);
    HAL_SPI_Receive(handle, rxBuff, lenght, 50);

    HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_SET);
}

uint8_t LIS3DHH_Write_Reg(SPI_HandleTypeDef *handle, uint8_t RegAddr, uint8_t *data,uint8_t lenght){
	uint8_t txBuff[lenght+1];
	uint8_t i;

	txBuff[0] = RegAddr & LSD3HH_SPIMODE_WRITE;
	for(i=1;i<lenght+1;i++){
	  txBuff[i] = data[i-1];
	}
	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

	HAL_SPI_Transmit(handle, txBuff, lenght+1,100);

	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_SET);
}
