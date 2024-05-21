#include"main.h"
#include<stdint.h>

#define SPI_NO_1 1
#define SPI_NO_2 2
#define SPI_NO_3 3

#define SPI_NODE_1 1
#define SPI_NODE_2 2
#define SPI_NODE_3 3

#define SPI_NODE_MAX 10

typedef struct{
	GPIO_TypeDef * SPI_CS_PORT;
	uint8_t SPI_CS_PIN;
}SPI_NODE_T;

typedef struct{
	void *handle;
	SPI_NODE_T node[SPI_NODE_MAX];
}SPI_Handle_T;

uint8_t SPI_Init(void *handle, uint8_t spiNo, uint8_t spiNode,  GPIO_TypeDef *spiCsPort, uint8_t spiCsPin);
uint8_t SPI_Com_Active(SPI_Handle_T *spiNo, uint8_t spiNode);
uint8_t SPI_Com_Deactive(SPI_Handle_T *spiNo, uint8_t spiNode);
uint8_t SPI_TransmitReceive(uint8_t spiNo, uint8_t spiNode, uint8_t *pTxdata, uint8_t *pRxdata, uint8_t Txlenght, uint8_t Rxlenght);
