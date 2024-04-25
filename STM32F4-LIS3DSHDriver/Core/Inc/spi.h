#include"main.h"
#include<stdint.h>

#define SPI_NO1 1
#define SPI_NO2 2
#define SPI_NO3 3

#define SPI_NODE1 1
#define SPI_NODE2 2
#define SPI_NODE3 3

uint8_t SPI_Com_Active(uint8_t spiNo);
uint8_t SPI_Com_Deactive(uint8_t handle);
uint8_t SPI_TransmitReceive(uint8_t handle,uint8_t *pTxdata, uint8_t *pRxdata, uint8_t Txlenght, uint8_t Rxlenght );
