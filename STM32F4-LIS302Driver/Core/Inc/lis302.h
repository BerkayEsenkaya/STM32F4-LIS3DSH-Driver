/*
 * lıs302.h
 *
 *  Created on: Feb 20, 2024
 *      Author: Berkay Esenkaya
 */



#ifndef INC_LIS302_H_
#define INC_LIS302_H_

#endif /* INC_LIS302_H_ */

/******************************************************************************
 *** DEFINES
 ******************************************************************************/
#define _LIS3DSH_ID 0x3F

#define _LIS3DSH_OK 1
#define _LIS3DSH_NOT_OK 0

#define _LIS3DSH_CONVERT_DATA_CONST_16G 73000
#define _LIS3DSH_CONVERT_DATA_CONST_8G  24414
#define _LIS3DSH_CONVERT_DATA_CONST_6G  18310
#define _LIS3DSH_CONVERT_DATA_CONST_4G  12207
#define _LIS3DSH_CONVERT_DATA_CONST_2G  6103
#define _LIS3DSH_CONVERT_DATA_CONST_DIVIDER 100000;

#define _LIS3DSH_REGADDR_INFO1  0x0D
#define _LIS3DSH_REGADDR_INFO2  0x0E
#define _LIS3DSH_REGADDR_WHOIAM 0x0F
#define _LIS3DSH_REGADDR_CTRL1  0x21
#define _LIS3DSH_REGADDR_CTRL2  0x22
#define _LIS3DSH_REGADDR_CTRL3  0x23
#define _LIS3DSH_REGADDR_CTRL4  0x20
#define _LIS3DSH_REGADDR_CTRL5  0x24
#define _LIS3DSH_REGADDR_CTRL6  0x25
#define _LIS3DSH_REGADDR_OUTPUT_AXIS_XL 0x28
#define _LIS3DSH_REGADDR_OUTPUT_AXIS_XH 0x29
#define _LIS3DSH_REGADDR_OUTPUT_AXIS_YL 0x2A
#define _LIS3DSH_REGADDR_OUTPUT_AXIS_YH 0x2B
#define _LIS3DSH_REGADDR_OUTPUT_AXIS_ZL 0x2C
#define _LIS3DSH_REGADDR_OUTPUT_AXIS_ZH 0x2D
#define _LIS3DSH_REGADDR_OUTPUT_TEMPERATURE 0x0C
#define _LIS3DSH_REGADDR_OFFSET_AXIS_X 0x10
#define _LIS3DSH_REGADDR_OFFSET_AXIS_Y 0x11
#define _LIS3DSH_REGADDR_OFFSET_AXIS_Z 0x12

#define _LIS3DSH_FILTERSIZE 10

#define AXIS_X 0
#define AXIS_Y 1
#define AXIS_Z 2

#define _DATA_POSITIVE 1
#define _DATA_NEGATIVE 0
/******************************************************************************
 *** STRUCTS
 ******************************************************************************/
typedef struct{
	uint16_t raw;
	uint16_t filtered;
	uint32_t mg;
	uint8_t sign;
}LIS3DSH_ACC_Data_T;

typedef struct{
	uint16_t raw;
	uint16_t filtered;
	uint8_t celcius;
}LIS3DSH_TEMP_Data_T;

typedef struct{
	uint8_t scale;
	uint8_t offsetCounter;
}LIS3DSH_SaveSetting_T;

typedef struct{
	LIS3DSH_ACC_Data_T axis[3];
	LIS3DSH_TEMP_Data_T temperature;
}LIS3DSH_RESULTS_T;

typedef struct{
	uint8_t spiNo;
	uint8_t spiNode;
}LIS3DSH_Module_T;

typedef struct{
	uint8_t entered;
	uint64_t sum;
	uint16_t data[_LIS3DSH_FILTERSIZE];
}LIS3DSH_AvgFilter_T;

typedef struct{
	LIS3DSH_AvgFilter_T AvarageFilter[4];
}LIS3DSH_Filter_T;

typedef struct{
	uint16_t Offset[3];
}LIS3DSH_OffsetValue_T;
/******************************************************************************
 *** ENUMS
 ******************************************************************************/
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


/******************************************************************************
 *** UNIONS
 ******************************************************************************/
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
}LIS3DSH_REG_CTRL_3_T;

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


/******************************************************************************
 *** FUNCTION PROTOTYPES
 ******************************************************************************/
/** \brief Controlled the LIS3DSH ID and reset the LIS3DSH.
 * \param  nothing.
 * \return nothing.
 */
uint8_t LIS3DSH_Init();

/** \brief Read the LIS3DSH registers value.
 * \param  RegAddr : Address of the register to be read.
 * \param  *rxBuff : buffer where the data to be read will be placed.
 * \param  lenght : lenght of the data which to be read from LIS3DSH registers.
 * \return nothing.
 */
uint16_t LIS3DSH_Read_Reg( uint8_t RegAddr, uint8_t lenght);

/** \brief Write to the LIS3DSH registers.
 * \param  RegAddr : Address of the register to be write.
 * \param  *data : Data to be written to lıs3dsh register.
 * \param  lenght : lenght of the data which to be write to LIS3DSH registers.
 * \return nothing.
 */
uint8_t LIS3DSH_Write_Reg( uint8_t RegAddr, uint8_t *data,uint8_t lenght);

/** \brief combines the entered settings appropriately and writes it to the CTRL1 register.
 * \param hys : Hysteresis unsigned value to be added or subtracted from threshold value in SM1.
 * \param sm1_pin : Set the interrupt routed which interrupt
 * \param sm1_en : SM1 enable or disable.
 * \return nothing
 */
uint8_t LIS3DSH_Reg_Set_Ctrl1(LIS3DSH_HYST1_T hys, LIS3DSH_SM1_PIN_T sm1_pin, LIS3DSH_SM1_EN_T sm1_en);

/** \brief combines the entered settings appropriately and writes it to the CTRL2 register.
 * \param hys : Hysteresis unsigned value to be added or subtracted from threshold value in SM2.
 * \param sm2_pin : Set the interrupt routed which interrupt
 * \param sm2_en : SM2 enable or disable.
 * \return nothing
 */
uint8_t LIS3DSH_Reg_Set_Ctrl2(LIS3DSH_HYST2_T hys, LIS3DSH_SM2_PIN_T sm2_pin, LIS3DSH_SM2_EN_T sm2_en);

/** \brief combines the entered settings appropriately and writes it to the CTRL3 register.
 * \param dr_en : Data Ready signal enable to INT1.
 * \param iea : Selection the polarity of interrupt signal.
 * \param iel : Selection the latch or pulse of interrupt signal.
 * \param int2_en : Selection of the Interrupt 2 enabled or disabled.
 * \param int1_en : Selection of the Interrupt 1 enabled or disabled.
 * \param Vfilt : Selection of the Vector filter enabled or disabled.
 * \param reset : Soft reset enable or disable.
 * \return nothing
 */
uint8_t LIS3DSH_Reg_Set_Ctrl3(LIS3DSH_DR_EN_T dren, LIS3DSH_IEA_T iea, LIS3DSH_IEL_T iel, LIS3DSH_INT2_EN_T int2_en, LIS3DSH_INT1_EN_T int1_en, LIS3DSH_VFILT_T Vfilt, LIS3DSH_STRT_T reset);

/** \brief combines the entered settings appropriately and writes it to the CTRL4 register.
 * \param odrVal : Output data rate and power mode selection.
 * \param bdu : Selection the uptading data block or continuous.
 * \param StateXAxis : Selection the X axis enable or disable.
 * \param StateYAxis : Selection the Y axis enable or disable.
 * \param StateZAxis : Selection the Z axis enable or disable.
 * \return nothing
 */
uint8_t LIS3DSH_Reg_Set_Ctrl4(LIS3DSH_ODR_T odrVal, LIS3DSH_BDU_T bduVal, LIS3DSH_XEN_T StateXAxis, LIS3DSH_YEN_T StateYAxis, LIS3DSH_ZEN_T StateZAxis );

/** \brief combines the entered settings appropriately and writes it to the CTRL5 register.
 * \param bw :  Selection the bandwidth of the Anti-aliasing filter.
 * \param scale : Selection the scale.
 * \param selftest : Selection the selftest enable or disable.
 * \param spiMode : Selection the SPI mode 3 wire or 4 wire.
 * \return nothing
 */
uint8_t LIS3DSH_Reg_Set_Ctrl5(LIS3DSH_BW_T bw,LIS3DSH_FSCALE_T scale, LIS3DSH_ST_T selftest ,LIS3DSH_SIM_T spiMode );

/** \brief combines the entered settings appropriately and writes it to the CTRL6 register.
 * \param boot :  Force reboot, cleared as soon as the reboot is finished. Active high.
 * \param fifo_en : Selection the FIFO enable or disable.
 * \param wtm_en : Selection the FIFO Watermark level using enable or disable.
 * \param reg_inc_en : Register address automatically incremented during a multiple byte access with a serial interface.
 * \param fifo_empty_int : Selection the FIFO Empty indication on int1 enable or disable.
 * \param fifo_wtm_int : Selection the FIFO Watermark interrupt on int1 enable or disable.
 * \param fifo_ovr_int : Selection the FIFO overrun interrupt on int1 enable or disable.
 * \param bootint : Selection the BOOT interrupt on int2 enable or disable.
 * \return nothing
 */
uint8_t LIS3DSH_Reg_Set_Ctrl6(uint8_t boot, LIS3DSH_FIFO_EN_T fifo_en, LIS3DSH_WTM_EN_T wtm_en, LIS3DSH_ADD_INC_T reg_inc_en, LIS3DSH_P1_EMPTY_T fifo_empty_int, LIS3DSH_P1_WTM_T fifo_wtm_int, LIS3DSH_P1_OVERRUN_T fifo_ovr_int, LIS3DSH_P2_BOOT_T bootint);

/** \brief Reset the accalometer used to CTRL2 register softreset bit.
 * \param  nothing.
 * \return nothing.
 */
uint8_t LIS3DSH_AccalometerSoftReset();

/** \brief Controlled the data which written to register. Read the written data from register if read data and written data is equal return 1.
 * \param  regAddr  : Addresses the register of written data.
 * \param  *WrittenData : Value of written data.
 * \return nothing.
 */
uint8_t LIS3DSH_CTRL_WRITE_DATA_IS_CORRECT(uint8_t regAddr, uint8_t *WrittenData);

/** \brief Read the OUT_X, OUT_Y, OUT_Z registers so read the accalometer x,y,z output data.
 * \param  nothing.
 * \return nothing.
 */
uint8_t LIS3DSH_Read_Accmeter_Data();

/** \brief Read the OUT_T register so read the temperature output data.
 * \param  nothing.
 * \return nothing.
 */
uint8_t LIS3DSH_Read_Temperature_Data();

/** \brief Convert the data to mili g from binary code.
 * \param  nothing.
 * \return nothing.
 */
uint8_t LIS3DSH_ConvertData(uint8_t axis);

uint8_t LIS3DSH_AvarageFilter(uint8_t axis);
