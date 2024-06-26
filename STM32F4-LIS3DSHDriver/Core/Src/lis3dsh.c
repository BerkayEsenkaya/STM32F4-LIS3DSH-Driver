/******************************************************************************
 *** INCLUDES
 ******************************************************************************/
#include<stdint.h>
#include"main.h"
#include"lis3dsh.h"

#include"spi.h"

/******************************************************************************
 *** DEFINES
 ******************************************************************************/
#define LIS3DSH_SPIMODE_READ  0b10000000
#define LIS3DSH_SPIMODE_WRITE 0b00111111

/******************************************************************************
 *** VARIABLES
 ******************************************************************************/

/******************************************************************************
 *** FUNCTIONS
 ******************************************************************************/
/** \brief
 */

uint8_t LIS3DSH_Init(uint8_t spiNo, uint8_t spiNode, LIS3DSH_SENSOR_PARAM_T *handle){
	uint8_t whoIam;
	handle->COM.SPI_No = spiNo;
    handle->COM.SPI_Node = spiNode;

	whoIam = LIS3DSH_Read_Reg(handle, _LIS3DSH_REGADDR_WHOIAM);
	if(whoIam == _LIS3DSH_ID){  /* Communication is successful*/
		LIS3DSH_AccalometerSoftReset(handle);
        return _LIS3DSH_OK ;
	}else{

	}
}

/** \brief
 */
uint16_t LIS3DSH_Read_Reg(LIS3DSH_SENSOR_PARAM_T *handle, uint8_t RegAddr){
	uint8_t txBuff[1];
	uint8_t rxBuff[1];
	txBuff[0] = RegAddr | LIS3DSH_SPIMODE_READ;

	SPI_TransmitReceive(handle->COM.SPI_No, handle->COM.SPI_Node, txBuff, rxBuff, 1, 1);
	return rxBuff[0];
}

/** \brief
 */
uint8_t LIS3DSH_Write_Reg(LIS3DSH_SENSOR_PARAM_T *handle, uint8_t RegAddr, uint8_t data){
	uint8_t txBuff[2];

	txBuff[0] = RegAddr & LIS3DSH_SPIMODE_WRITE;
	txBuff[1] = data;

    SPI_TransmitReceive(handle->COM.SPI_No, handle->COM.SPI_Node, txBuff, NULL, 2, 0);
    return LIS3DSH_CTRL_WRITE_DATA_IS_CORRECT(handle, RegAddr, data);
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl1(LIS3DSH_SENSOR_PARAM_T *handle, LIS3DSH_HYST1_T hys, LIS3DSH_SM1_PIN_T sm1_pin, LIS3DSH_SM1_EN_T sm1_en){
	handle->REG_CTRL_1.hys = hys;
	handle->REG_CTRL_1.sm1_pin = sm1_pin;
	handle->REG_CTRL_1.sm1_en = sm1_en;
	return LIS3DSH_Write_Reg(handle, _LIS3DSH_REGADDR_CTRL1, handle->REG_CTRL_1.CTRL1 );
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl2(LIS3DSH_SENSOR_PARAM_T *handle, LIS3DSH_HYST2_T hys, LIS3DSH_SM2_PIN_T sm2_pin, LIS3DSH_SM2_EN_T sm2_en){
    handle->REG_CTRL_2.hys = hys;
    handle->REG_CTRL_2.sm2_pin = sm2_pin;
    handle->REG_CTRL_2.sm2_en = sm2_en;
    return LIS3DSH_Write_Reg(handle, _LIS3DSH_REGADDR_CTRL2, handle->REG_CTRL_2.CTRL2 );
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl3(LIS3DSH_SENSOR_PARAM_T *handle, LIS3DSH_DR_EN_T dren, LIS3DSH_IEA_T iea, LIS3DSH_IEL_T iel, LIS3DSH_INT2_EN_T int2_en, LIS3DSH_INT1_EN_T int1_en, LIS3DSH_VFILT_T Vfilt, LIS3DSH_STRT_T reset){
    handle->REG_CTRL_3.dren = dren;
    handle->REG_CTRL_3.iea = iea;
    handle->REG_CTRL_3.iel = iel;
    handle->REG_CTRL_3.int2en = int2_en;
    handle->REG_CTRL_3.int1en = int1_en;
    handle->REG_CTRL_3.vfilt = Vfilt;
    handle->REG_CTRL_3.reset = reset;
    return LIS3DSH_Write_Reg(handle, _LIS3DSH_REGADDR_CTRL3, handle->REG_CTRL_3.CTRL3);
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl4(LIS3DSH_SENSOR_PARAM_T *handle, LIS3DSH_ODR_T odrVal, LIS3DSH_BDU_T bduVal, LIS3DSH_XEN_T StateXAxis, LIS3DSH_YEN_T StateYAxis, LIS3DSH_ZEN_T StateZAxis ){
    handle->REG_CTRL_4.odr = odrVal;
    handle->REG_CTRL_4.bdu = bduVal;
    handle->REG_CTRL_4.xaxis_en = StateXAxis;
    handle->REG_CTRL_4.yaxis_en = StateYAxis;
    handle->REG_CTRL_4.zaxis_en = StateZAxis;
    return LIS3DSH_Write_Reg(handle, _LIS3DSH_REGADDR_CTRL4, handle->REG_CTRL_4.CTRL4);
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl5(LIS3DSH_SENSOR_PARAM_T *handle, LIS3DSH_BW_T bw,LIS3DSH_FSCALE_T scale, LIS3DSH_ST_T selftest ,LIS3DSH_SIM_T spiMode ){
	handle->Save.scale = scale;
	handle->REG_CTRL_5.bandwith = bw;
	handle->REG_CTRL_5.scale = scale;
	handle->REG_CTRL_5.selftest = selftest;
	handle->REG_CTRL_5.spiMode = spiMode;
	return LIS3DSH_Write_Reg(handle, _LIS3DSH_REGADDR_CTRL5, handle->REG_CTRL_5.CTRL5);
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl6(LIS3DSH_SENSOR_PARAM_T *handle, uint8_t boot, LIS3DSH_FIFO_EN_T fifo_en, LIS3DSH_WTM_EN_T wtm_en, LIS3DSH_ADD_INC_T reg_inc_en, LIS3DSH_P1_EMPTY_T fifo_empty_int, LIS3DSH_P1_WTM_T fifo_wtm_int, LIS3DSH_P1_OVERRUN_T fifo_ovr_int, LIS3DSH_P2_BOOT_T bootint){
	handle->REG_CTRL_6.boot = boot;
	handle->REG_CTRL_6.fifo_en = fifo_en;
	handle->REG_CTRL_6.wtm_en = wtm_en;
	handle->REG_CTRL_6.reg_inc_en = reg_inc_en;
	handle->REG_CTRL_6.fifo_empty_int = fifo_empty_int;
	handle->REG_CTRL_6.fifo_wtm_int = fifo_wtm_int;
	handle->REG_CTRL_6.fifo_ovr_int = fifo_ovr_int;
	handle->REG_CTRL_6.bootint = bootint;
	return LIS3DSH_Write_Reg(handle, _LIS3DSH_REGADDR_CTRL6,handle->REG_CTRL_6.CTRL6);
}

/** \brief
 */
uint8_t LIS3DSH_AccalometerSoftReset(LIS3DSH_SENSOR_PARAM_T *handle){
	LIS3DSH_Reg_Set_Ctrl3(handle, INT1_DATA_READY_SIGNAL_DISABLE,INT_SIGNAL_ACTIVE_LOW,INT_SIGNAL_LATCH,INT2_DISABLE,INT1_DISABLE,VECTOR_FILT_DISABLE,SOFT_RESET_ENABLE);
}

/** \brief
 */
uint8_t LIS3DSH_CTRL_WRITE_DATA_IS_CORRECT(LIS3DSH_SENSOR_PARAM_T *handle, uint8_t regAddr, uint8_t *WrittenData){
	uint8_t rxBuff[1];
	rxBuff[0] = LIS3DSH_Read_Reg(handle, regAddr);
	if(WrittenData[0] == rxBuff[0]){
		return _LIS3DSH_OK;
	}else{

		//return _LIS3DSH_NOT_OK;
	}
}

/** \brief
 */
uint8_t LIS3DSH_Read_Accmeter_Data(LIS3DSH_SENSOR_PARAM_T *handle){

	handle->Results.axis[AXIS_X].raw  = LIS3DSH_Read_Reg(handle, _LIS3DSH_REGADDR_OUTPUT_AXIS_XH) << 8;
	handle->Results.axis[AXIS_X].raw |= LIS3DSH_Read_Reg(handle, _LIS3DSH_REGADDR_OUTPUT_AXIS_XL);

	handle->Results.axis[AXIS_Y].raw =LIS3DSH_Read_Reg(handle, _LIS3DSH_REGADDR_OUTPUT_AXIS_YH) << 8;
	handle->Results.axis[AXIS_Y].raw |=LIS3DSH_Read_Reg(handle, _LIS3DSH_REGADDR_OUTPUT_AXIS_YL);

	handle->Results.axis[AXIS_Z].raw = LIS3DSH_Read_Reg(handle, _LIS3DSH_REGADDR_OUTPUT_AXIS_ZH) << 8;
	handle->Results.axis[AXIS_Z].raw |= LIS3DSH_Read_Reg(handle, _LIS3DSH_REGADDR_OUTPUT_AXIS_ZL);

    if(handle->Results.axis[AXIS_X].raw >= 32767){
    	handle->Results.axis[AXIS_X].raw = 65535 - handle->Results.axis[AXIS_X].raw;
    	handle->Results.axis[AXIS_X].sign = _DATA_NEGATIVE;
        }else{
        	handle->Results.axis[AXIS_X].sign = _DATA_POSITIVE;
        }
        if(handle->Results.axis[AXIS_Y].raw >= 32767){
        	handle->Results.axis[AXIS_Y].raw = 65535 - handle->Results.axis[AXIS_Y].raw;
        	handle->Results.axis[AXIS_Y].sign = _DATA_NEGATIVE;
        }else{
        	handle->Results.axis[AXIS_Y].sign = _DATA_POSITIVE;
        }
        if(handle->Results.axis[AXIS_Z].raw >= 32767){
        	handle->Results.axis[AXIS_Z].raw = 65535 - handle->Results.axis[AXIS_Z].raw;
        	handle->Results.axis[AXIS_Z].sign = _DATA_NEGATIVE;
        }else{
        	handle->Results.axis[AXIS_Z].sign = _DATA_POSITIVE;
        }

}

/** \brief
 */
uint8_t LIS3DSH_Read_Temperature_Data(LIS3DSH_SENSOR_PARAM_T *handle){

	handle->Results.DieTemperature.raw = LIS3DSH_Read_Reg(handle, _LIS3DSH_REGADDR_OUTPUT_TEMPERATURE);
	if(handle->Results.DieTemperature.raw >= 0x80){
		handle->Results.DieTemperature.raw = 0xFF - handle->Results.DieTemperature.raw + 1;
	}
	handle->Results.DieTemperature.CalcData = 25 + (handle->Results.DieTemperature.raw/2);
}

/** \brief
 */
uint8_t LIS3DSH_ConvertData(LIS3DSH_SENSOR_PARAM_T *handle, uint8_t axis){
	uint32_t convertMltply;
    switch(handle->Save.scale){
       case SCALE_SELECT_2G :convertMltply = _LIS3DSH_CONVERT_DATA_CONST_2G;
       break;
       case SCALE_SELECT_4G :convertMltply = _LIS3DSH_CONVERT_DATA_CONST_4G;
       break;
       case SCALE_SELECT_6G :convertMltply = _LIS3DSH_CONVERT_DATA_CONST_6G;
       break;
       case SCALE_SELECT_8G :convertMltply = _LIS3DSH_CONVERT_DATA_CONST_8G;
       break;
       case SCALE_SELECT_16G :convertMltply = _LIS3DSH_CONVERT_DATA_CONST_16G;
       break;
    }

    handle->Results.axis[axis].CalcData = handle->Results.axis[axis].filtered * convertMltply;
    handle->Results.axis[axis].CalcData = handle->Results.axis[axis].CalcData / _LIS3DSH_CONVERT_DATA_CONST_DIVIDER;
}
