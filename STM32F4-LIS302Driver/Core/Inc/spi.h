/*
 * spi.h
 *
 *  Created on: Mar 28, 2024
 *      Author: esenk
 */
#include<stdint.h>

#ifndef INC_SPI_H_
#define INC_SPI_H_



#endif /* INC_SPI_H_ */

#define SPI_NO_1 1
#define SPI_NO_2 2
#define SPI_NO_3 3

#define SPI_NODE_1 1
#define SPI_NODE_2 2
#define SPI_NODE_3 3


typedef struct{
	uint8_t spiNo;
	uint8_t spiNode;
}SPI_Module_T;
