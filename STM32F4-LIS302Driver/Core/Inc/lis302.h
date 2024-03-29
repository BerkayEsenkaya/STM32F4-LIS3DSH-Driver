/*
 * lıs302.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Berkay Esenkaya
 */

#ifndef INC_LIS302_H_
#define INC_LIS302_H_

#endif /* INC_LIS302_H_ */

#define _LIS3DSH_REGADDR_WHOIAM 0x0F
#define _LIS3DSH_REGADDR_CTRL4  0x20

typedef enum{
  INT1_DATA_READY_SIGNAL_DISABLE,
  INT1_DATA_READY_SIGNAL_ENABLE,
}LIS3DSH_DR_EN_T;

typedef enum{
	INT_SIGNAL_ACTIVE_LOW,
	INT_SIGNAL_ACTIVE_HIGH,
}LIS3DSH_IEA_T;

typedef enum{
	INT_SIGNAL_LATCH,
	INT_SIGNAL_PULSE,
}LIS3DSH_IEL_T;

typedef enum{
	INT2_DISABLE,
	INT2_ENABLE,
}LIS3DSH_INT2_EN_T;

typedef enum{
	INT1_DISABLE,
	INT1_ENABLE,
}LIS3DSH_INT1_EN_T;

typedef enum{
	VECTOR_FILT_DISABLE,
	VECTOR_FILT_ENABLE,
}LIS3DSH_VFILT_T;

typedef enum{
	SOFT_RESET_DISABLE,
	SOFT_RESET_ENABLE,
}LIS3DSH_STRT_T;

typedef enum{
	POWER_DOWN,
	DATARATE_HZ_3,
	DATARATE_HZ_6,
	DATARATE_HZ_12,
	DATARATE_HZ_25,
	DATARATE_HZ_50,
	DATARATE_HZ_100,
	DATARATE_HZ_400,
	DATARATE_HZ_800,
	DATARATE_HZ_1600,
}LIS3DSH_ODR_T;

typedef enum{
	DATA_CONT_UPDATE,
	DATA_BLOCK,
}LIS3DSH_BDU_T;

typedef enum{
	AXIS_Z_DISABLE,
	AXIS_Z_ENABLE,
}LIS3DSH_ZEN_T;

typedef enum{
	AXIS_Y_DISABLE,
	AXIS_Y_ENABLE,
}LIS3DSH_YEN_T;

typedef enum{
	AXIS_X_DISABLE,
	AXIS_X_ENABLE,
}LIS3DSH_XEN_T;

typedef enum{
	ANTIALIASING_FILTER_BANDWIDTH_HZ_800,
	ANTIALIASING_FILTER_BANDWIDTH_HZ_400,
	ANTIALIASING_FILTER_BANDWIDTH_HZ_200,
	ANTIALIASING_FILTER_BANDWIDTH_HZ_50,
}LIS3DSH_BW_T;

typedef enum{
	SCALE_SELECT_2G,
	SCALE_SELECT_4G,
	SCALE_SELECT_6G,
	SCALE_SELECT_8G,
	SCALE_SELECT_16G,
}LIS3DSH_FSCALE_T;

typedef enum{
	NORMAL_MODE,
	SELF_TEST_POSITIVE_SIGN,
	SELF_TEST_NEGATIVE_SIGN,
}LIS3DSH_ST_T;

typedef enum{
	SPI_INTERFACE_4WIRE,
	SPI_INTERFACE_3WIRE,
}LIS3DSH_SIM_T;

typedef enum{
	BOOT_DISABLE,
	BOOT_ENABLE,
}LIS3DSH_BOOT_T;

typedef enum{
	FIFO_DISABLE,
	FIFO_ENABLE,
}LIS3DSH_FIFO_EN_T;

typedef enum{
	FIFO_WATERMARK_LEVEL_DISABLE,
	FIFO_WATERMARK_LEVEL_ENABLE,
}LIS3DSH_WTM_EN_T;

typedef enum{
	REG_ADDR_AUTO_INCREMENT_DISABLE,
	REG_ADDR_AUTO_INCREMENT_ENABLE,
}LIS3DSH_ADD_INC_T;

typedef enum{
	FIFO_EMPTY_INDICATION_DISABLE,
	FIFO_EMPTY_INDICATION_ENABLE,
}LIS3DSH_P1_EMPTY_T;

typedef enum{
	FIFO_WATERMARK_INT_DISABLE,
	FIFO_WATERMARK_INT_ENABLE,
}LIS3DSH_P1_WTM_T;

typedef enum{
	FIFO_OVERRUN_INT_DISABLE,
	FIFO_OVERRUN_INT_ENABLE,
}LIS3DSH_P1_OVERRUN_T;

typedef enum{
	BOOT_INT_DISABLE,
	BOOT_INT_ENABLE,
}LIS3DSH_P2_BOOT_T;

typedef enum{
	MODE_BYPASS,
	MODE_FIFO,
	MODE_STREAM,
	MODE_BYPASS_STREAM,
	NOTUSED1,
	NOTUSED2,
	MODE_BYPASS_FIFO,
}LIS3DSH_FMODE_T;

typedef enum{
	HYST1_0,
	HYST1_1,
	HYST1_2,
	HYST1_3,
	HYST1_4,
	HYST1_5,
	HYST1_6,
	HYST1_7,
}LIS3DSH_HYST1_T;

typedef enum{
	SM1_INT_INT1,
	SM1_INT_INT2,
}LIS3DSH_SM1_PIN_T;

typedef enum{
	SM1_DISABLE,
	SM1_ENABLE,
}LIS3DSH_SM1_EN_T;

typedef enum{
	HYST2_0,
	HYST2_1,
	HYST2_2,
	HYST2_3,
	HYST2_4,
	HYST2_5,
	HYST2_6,
	HYST2_7,
}LIS3DSH_HYST2_T;

typedef enum{
	SM2_INT_INT1,
	SM2_INT_INT2,
}LIS3DSH_SM2_PIN_T;

typedef enum{
	SM2_DISABLE,
	SM2_ENABLE,
}LIS3DSH_SM2_EN_T;

typedef union{
	uint8_t CTRL1 : 8;
	struct{
		LIS3DSH_SM1_EN_T sm1_en   : 1;
		uint8_t unused1           : 2;
		LIS3DSH_SM1_PIN_T sm1_pin : 1;
		uint8_t unused2           : 1;
		LIS3DSH_HYST1_T hys       : 3;
	};
}LIS3DSH_REG_CTRL_1_T;

typedef union{
	uint8_t CTRL2 : 8;
	struct{
		LIS3DSH_SM2_EN_T sm2_en   : 1;
		uint8_t unused1           : 2;
		LIS3DSH_SM2_PIN_T sm2_pin : 1;
		uint8_t unused2           : 1;
		LIS3DSH_HYST2_T hys       : 3;
	};
}LIS3DSH_REG_CTRL_2_T;

typedef union{
	uint8_t CTRL3 : 8;
	struct{
		LIS3DSH_STRT_T reset     : 1;
		LIS3DSH_VFILT_T vfilt    : 1;
		LIS3DSH_INT1_EN_T int1en : 1;
		LIS3DSH_INT2_EN_T int2en : 1;
		LIS3DSH_IEL_T iel        : 1;
		LIS3DSH_IEA_T iea        : 1;
		LIS3DSH_DR_EN_T dren     : 1;
	};
};

typedef union{
	uint8_t CTRL4 : 8;
	struct{
		LIS3DSH_XEN_T xaxis_en : 1;
		LIS3DSH_YEN_T yaxis_en : 1;
		LIS3DSH_ZEN_T zaxis_en : 1;
		LIS3DSH_BDU_T bdu      : 1;
		LIS3DSH_ODR_T odr      : 4;
	};
}LIS3DSH_REG_CTRL_4_T;

typedef union{
	uint8_t CTRL5 : 8;
	struct{
		LIS3DSH_SIM_T spiMode  : 1;
		LIS3DSH_ST_T selftest  : 2;
		LIS3DSH_FSCALE_T scale : 3;
		LIS3DSH_BW_T bandwith  : 2;
	};
}LIS3DSH_REG_CTRL_5_T;

typedef union{
	uint8_t CTRL6 : 8;
	struct{
		LIS3DSH_P2_BOOT_T bootint : 1;
		LIS3DSH_P1_OVERRUN_T fifo_ovr_int : 1;
		LIS3DSH_P1_WTM_T fifo_wtm_int : 1;
		LIS3DSH_P1_EMPTY_T fifo_empty_int : 1;
		LIS3DSH_ADD_INC_T reg_inc_en : 1;
		LIS3DSH_WTM_EN_T wtm_en : 1;
		LIS3DSH_FIFO_EN_T fifo_en : 1;
		uint8_t boot : 1;
	};
}LIS3DSH_REG_CTRL_6_T;



uint8_t LIS3DSH_Read_Reg(SPI_HandleTypeDef *handle, uint8_t RegAddr, uint8_t *rxBuff,uint8_t lenght);
uint8_t LIS3DSH_Write_Reg(SPI_HandleTypeDef *handle, uint8_t RegAddr, uint8_t *data,uint8_t lenght);
uint8_t LIS3DSH_REG_SET_CTRL4(SPI_HandleTypeDef *handle, LIS3DSH_ODR_T odrVal, LIS3DSH_BDU_T bduVal, LIS3DSH_XEN_T StateXAxis, LIS3DSH_YEN_T StateYAxis, LIS3DSH_ZEN_T StateZAxis);
