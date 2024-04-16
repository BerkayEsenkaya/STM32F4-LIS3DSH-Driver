/**
 * \file I2C.h
 * \author Kaan SARICA
 * \brief I2C communication peripheral porters
 * \date 25.03.2024
 *
 */

/******************************************************************************
 *** DEFINES
 ******************************************************************************/
#define I2C_NO1 1
#define I2C_NO2 2
#define I2C_NO3 3

#define I2C_MODE_0 0
#define I2C_MODE_1 1
#define I2C_MODE_2 2

#define EventFlagMask_I2CHandle_I2C1TxRxComplete 0x00000001
#define EventFlagMask_I2CHandle_I2C2TxRxComplete 0x00000002
#define EventFlagMask_I2CHandle_I2C3TxRxComplete 0x00000004

#ifdef STM32L433xx
  #define I2C_NO_MAX 3
  #define I2C_MODE_MAX 2
#else
  #define I2C_NO_MAX 3
  #define I2C_MODE_MAX 2
#endif

/******************************************************************************
 *** STRUCTURES
 ******************************************************************************/
typedef struct{
	void *Handle;
	uint32_t bitrate;
	uint8_t mode;
//	osSemaphoreId_t accessSemaphore;
}I2C_Module_T;

typedef struct{
	uint8_t RW_mode;
}I2C_TxRx_T;

typedef enum{
	Write,
	WriteRead,
}I2C_TxRx_Val_T;
/******************************************************************************
 *** VARIABLES
******************************************************************************/


/******************************************************************************
 *** FUNCTION PROTOTYPES
 ******************************************************************************/
/** \brief
 * \param
 * \return
*/
uint8_t I2C_Init(uint8_t i2cNo, void *handle, uint32_t bitRate_Hz, uint8_t mode );

/** \brief
 * \param
 * \return
*/
uint8_t I2C_GetAccess(uint8_t i2cNo, uint32_t wait_ms);

/** \brief
 * \param
 * \return
*/
uint8_t I2C_ReleaseAccess(uint8_t i2cNo);

/** \brief
 * \param
 * \return
*/
uint8_t I2C_SendReceive(uint8_t i2cNo, uint8_t DevAddress,uint8_t *txData, uint32_t txLength, uint8_t *rxData, uint32_t rxLength, uint32_t timeout_ms);
/** \brief
 * \param
 * \return
*/
uint8_t I2C_SendReceiveCompleteCallback(uint8_t i2cNo);

/** \brief
 * \param
 * \return
*/
I2C_Module_T *I2C_GetI2CModuleFromNo(uint8_t i2cNo);

/** \brief
 * \param
 * \return
*/
