#include"stdint.h"
#include"main.h"
#include<lis302.h>


#define LSD3HH_SPIMODE_READ  0b10000000
#define LSD3HH_SPIMODE_WRITE 0b00111111


extern SPI_HandleTypeDef hspi1;


uint8_t LIS3DSH_Init(SPI_HandleTypeDef *handle){

}


uint8_t LIS3DSH_Read_Reg(SPI_HandleTypeDef *handle, uint8_t RegAddr, uint8_t *rxBuff,uint8_t lenght){
	uint8_t txBuff[1];

	txBuff[0] = RegAddr | LSD3HH_SPIMODE_READ;
	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

    HAL_SPI_Transmit_IT(handle, txBuff, 1);
    HAL_SPI_Receive_IT(handle, rxBuff, lenght);

    HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_SET);
}

uint8_t LIS3DSH_Write_Reg(SPI_HandleTypeDef *handle, uint8_t RegAddr, uint8_t *data,uint8_t lenght){
	uint8_t txBuff[lenght+1];
	uint8_t i;

	txBuff[0] = RegAddr & LSD3HH_SPIMODE_WRITE;
	for(i=1;i<lenght+1;i++){
	  txBuff[i] = data[i-1];
	}
	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

	HAL_SPI_Transmit_IT(handle, txBuff, lenght+1);

	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_SET);
}

uint8_t LIS3DSH_REG_SET_CTRL4(SPI_HandleTypeDef *handle, LIS3DSH_ODR_T odrVal, LIS3DSH_BDU_T bduVal, LIS3DSH_XEN_T StateXAxis, LIS3DSH_YEN_T StateYAxis, LIS3DSH_ZEN_T StateZAxis ){
    LIS3DSH_REG_CTRL_4_T SetReg;
    uint8_t txBuff[1];
    SetReg.odr = odrVal;
    SetReg.bdu = bduVal;
    SetReg.xaxis_en = StateXAxis;
    SetReg.yaxis_en = StateYAxis;
    SetReg.zaxis_en = StateZAxis;
    txBuff[0] = SetReg.CTRL4;
    LIS3DSH_Write_Reg(handle, _LIS3DSH_REGADDR_CTRL4, txBuff, 1);
}
