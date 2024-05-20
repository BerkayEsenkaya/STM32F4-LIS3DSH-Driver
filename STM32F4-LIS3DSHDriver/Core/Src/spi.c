#include"spi.h"
#include"main.h"

SPI_Handle_T SPI_1, SPI_2, SPI_3;

uint8_t SPI_Init(void *handle, uint8_t spiNo, uint8_t spiNode,  GPIO_TypeDef *spiCsPort, uint8_t spiCsPin){
	SPI_Handle_T *SPI;
	 switch(spiNo){
	    case SPI_NO_1 : SPI = &SPI_1;break;
	    case SPI_NO_2 : SPI = &SPI_2;break;
	    case SPI_NO_3 : SPI = &SPI_3;break;
	 }
	    SPI->handle = handle;
	    SPI->node[spiNode].SPI_CS_PORT = spiCsPort;
	    SPI->node[spiNode].SPI_CS_PIN = spiCsPin;
}

uint8_t SPI_TransmitReceive(uint8_t spiNo, uint8_t spiNode, uint8_t *pTxdata, uint8_t *pRxdata, uint8_t Txlenght, uint8_t Rxlenght ){
    SPI_Handle_T *SPI;

    switch(spiNo){
    case SPI_NO_1 : SPI = &SPI_1;break;
    case SPI_NO_2 : SPI = &SPI_2;break;
    case SPI_NO_3 : SPI = &SPI_3;break;
    }

    SPI_Com_Active(SPI, spiNode);
	HAL_SPI_Transmit(SPI->handle, pTxdata, Txlenght, 200);

	if(Rxlenght != 0){
		 HAL_SPI_Receive(SPI->handle, pRxdata, Rxlenght, 200);
	}
	SPI_Com_Deactive(SPI, spiNode);
}

uint8_t SPI_Com_Active(SPI_Handle_T *spi, uint8_t spiNode){
	HAL_GPIO_WritePin(spi->node[spiNode].SPI_CS_PORT , spi->node[spiNode].SPI_CS_PIN , GPIO_PIN_RESET);
}

uint8_t SPI_Com_Deactive(SPI_Handle_T *spi, uint8_t spiNode){
	HAL_GPIO_WritePin(spi->node[spiNode].SPI_CS_PORT , spi->node[spiNode].SPI_CS_PIN , GPIO_PIN_SET);
}
