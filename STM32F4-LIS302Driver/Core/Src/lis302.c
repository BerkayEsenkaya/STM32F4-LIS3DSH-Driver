/******************************************************************************
 *** INCLUDES
 ******************************************************************************/
#include<stdint.h>
#include"main.h"
#include"lis302.h"
#include"spi.h"

/******************************************************************************
 *** DEFINES
 ******************************************************************************/
#define LIS3DSH_SPIMODE_READ  0b10000000
#define LIS3DSH_SPIMODE_WRITE 0b00111111

/******************************************************************************
 *** VARIABLES
 ******************************************************************************/
LIS3DSH_RESULTS_T results;
LIS3DSH_SaveSetting_T save;


/******************************************************************************
 *** FUNCTIONS
 ******************************************************************************/
/** \brief
 */
uint8_t LIS3DSH_Init(){
	uint8_t whoIam[1];
	LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_WHOIAM, whoIam, 1);
	if(whoIam[0] == _LIS3DSH_ID){
		LIS3DSH_AccalometerSoftReset();
        return _LIS3DSH_OK;
	}else{
		return _LIS3DSH_NOT_OK;
	}
}

/** \brief
 */
uint8_t LIS3DSH_Read_Reg(uint8_t RegAddr, uint8_t *rxBuff,uint8_t lenght){
	uint8_t txBuff[1];

	txBuff[0] = RegAddr | LIS3DSH_SPIMODE_READ;

	return SPI_TransmitReceive(SPI_NO1, txBuff, rxBuff, 1, lenght);
}

/** \brief
 */
uint8_t LIS3DSH_Write_Reg(uint8_t RegAddr, uint8_t *data,uint8_t lenght){
	uint8_t txBuff[lenght+1];
	uint8_t i;

	txBuff[0] = RegAddr & LIS3DSH_SPIMODE_WRITE;
	for(i=1;i<lenght+1;i++){
	  txBuff[i] = data[i-1];
	}

    SPI_TransmitReceive(SPI_NO1, txBuff, NULL, lenght, 0);
    return LIS3DSH_CTRL_WRITE_DATA_IS_CORRECT(RegAddr, data);
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl1(LIS3DSH_HYST1_T hys, LIS3DSH_SM1_PIN_T sm1_pin, LIS3DSH_SM1_EN_T sm1_en){
	LIS3DSH_REG_CTRL_1_T SetReg;
	uint8_t txBuff[1];
	SetReg.hys = hys;
	SetReg.sm1_pin = sm1_pin;
	SetReg.sm1_en = sm1_en;
	txBuff[0] = SetReg.CTRL1;
	return LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL1, txBuff, 2);
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl2(LIS3DSH_HYST2_T hys, LIS3DSH_SM2_PIN_T sm2_pin, LIS3DSH_SM2_EN_T sm2_en){
	LIS3DSH_REG_CTRL_2_T SetReg;
    uint8_t txBuff[1];
    SetReg.hys = hys;
    SetReg.sm2_pin = sm2_pin;
    SetReg.sm2_en = sm2_en;
    txBuff[0] = SetReg.CTRL2;
    return LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL2, txBuff, 2);
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl3(LIS3DSH_DR_EN_T dren, LIS3DSH_IEA_T iea, LIS3DSH_IEL_T iel, LIS3DSH_INT2_EN_T int2_en, LIS3DSH_INT1_EN_T int1_en, LIS3DSH_VFILT_T Vfilt, LIS3DSH_STRT_T reset){
	LIS3DSH_REG_CTRL_3_T SetReg;
    uint8_t txBuff[1];
    SetReg.dren = dren;
    SetReg.iea = iea;
    SetReg.iel = iel;
    SetReg.int2en = int2_en;
    SetReg.int1en = int1_en;
    SetReg.vfilt = Vfilt;
    SetReg.reset = reset;
    txBuff[0] = SetReg.CTRL3;
    return LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL3, txBuff, 2);
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl4(LIS3DSH_ODR_T odrVal, LIS3DSH_BDU_T bduVal, LIS3DSH_XEN_T StateXAxis, LIS3DSH_YEN_T StateYAxis, LIS3DSH_ZEN_T StateZAxis ){
    LIS3DSH_REG_CTRL_4_T SetReg;
    uint8_t txBuff[1];
    SetReg.odr = odrVal;
    SetReg.bdu = bduVal;
    SetReg.xaxis_en = StateXAxis;
    SetReg.yaxis_en = StateYAxis;
    SetReg.zaxis_en = StateZAxis;
    txBuff[0] = SetReg.CTRL4;
    return LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL4, txBuff, 2);
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl5(LIS3DSH_BW_T bw,LIS3DSH_FSCALE_T scale, LIS3DSH_ST_T selftest ,LIS3DSH_SIM_T spiMode ){
	LIS3DSH_REG_CTRL_5_T SetReg;
	save.scale = scale;
	uint8_t txBuff[1];
	SetReg.bandwith = bw;
	SetReg.scale = scale;
	SetReg.selftest = selftest;
	SetReg.spiMode = spiMode;
	txBuff[0] = SetReg.CTRL5;
	return LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL5, txBuff, 2);
}

/** \brief
 */
uint8_t LIS3DSH_Reg_Set_Ctrl6(uint8_t boot, LIS3DSH_FIFO_EN_T fifo_en, LIS3DSH_WTM_EN_T wtm_en, LIS3DSH_ADD_INC_T reg_inc_en, LIS3DSH_P1_EMPTY_T fifo_empty_int, LIS3DSH_P1_WTM_T fifo_wtm_int, LIS3DSH_P1_OVERRUN_T fifo_ovr_int, LIS3DSH_P2_BOOT_T bootint){
	LIS3DSH_REG_CTRL_6_T SetReg;
	uint8_t txBuff[1];
	SetReg.boot = boot;
	SetReg.fifo_en = fifo_en;
	SetReg.wtm_en = wtm_en;
	SetReg.reg_inc_en = reg_inc_en;
	SetReg.fifo_empty_int = fifo_empty_int;
	SetReg.fifo_wtm_int = fifo_wtm_int;
	SetReg.fifo_ovr_int = fifo_ovr_int;
	SetReg.bootint = bootint;
	txBuff[0] = SetReg.CTRL6;
	return LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL6, txBuff, 2);
}

/** \brief
 */
uint8_t LIS3DSH_AccalometerSoftReset(){
	LIS3DSH_Reg_Set_Ctrl3(INT1_DATA_READY_SIGNAL_DISABLE,INT_SIGNAL_ACTIVE_LOW,INT_SIGNAL_LATCH,INT2_DISABLE,INT1_DISABLE,VECTOR_FILT_DISABLE,SOFT_RESET_ENABLE);
}

/** \brief
 */
uint8_t LIS3DSH_CTRL_WRITE_DATA_IS_CORRECT(uint8_t regAddr, uint8_t *WrittenData){
	uint8_t rxBuff[1];
	LIS3DSH_Read_Reg(regAddr, rxBuff,1);
	if(WrittenData[0] == rxBuff[0]){
		return _LIS3DSH_OK;
	}else{
		while(1){

		}
	}
}

/** \brief
 */
uint8_t LIS3DSH_Read_Accmeter_Data(){
	uint8_t temph[1];
	uint8_t templ[1];

	LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_XH, temph,1);
	LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_XL, templ,1);
    results.axis[AXIS_X].raw = (templ[0]<<8);
    results.axis[AXIS_X].raw |= temph[0];

    LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_YH, temph,1);
    LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_YL, templ,1);
    results.axis[AXIS_Y].raw = (templ[0]<<8);
    results.axis[AXIS_Y].raw |= temph[0];

    LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_ZH, temph,1);
    LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_ZL, templ,1);
    results.axis[AXIS_Z].raw = (templ[0]<<8);
    results.axis[AXIS_Z].raw |= temph[0];
}

/** \brief
 */
uint8_t LIS3DSH_Read_Temperature_Data(){
	uint8_t tempdataBuff[2];
	LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_TEMPERATURE, tempdataBuff,1);
	results.temperature.raw = tempdataBuff[0]<<8;
	results.temperature.raw |= tempdataBuff[1];
}

/** \brief
 */
uint8_t LIS3DSH_ConvertData(){
	uint8_t convertMltply;
    switch(save.scale){
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
    if(results.axis[AXIS_X].raw >= 32767){
    	results.axis[AXIS_X].raw = 65535 - results.axis[AXIS_X].raw;
    }
    if(results.axis[AXIS_Y].raw >= 32767){
        	results.axis[AXIS_Y].raw = 65535 - results.axis[AXIS_Y].raw;
    }
    if(results.axis[AXIS_Z].raw >= 32767){
        	results.axis[AXIS_Z].raw = 65535 - results.axis[AXIS_Z].raw;
    }
    results.axis[AXIS_X].mg = results.axis[AXIS_X].raw * convertMltply;
    results.axis[AXIS_X].mg = results.axis[AXIS_X].mg / _LIS3DSH_CONVERT_DATA_CONST_DIVIDER;

    results.axis[AXIS_Y].mg = results.axis[AXIS_Y].raw * convertMltply;
    results.axis[AXIS_Y].mg = results.axis[AXIS_Y].mg / _LIS3DSH_CONVERT_DATA_CONST_DIVIDER;

    results.axis[AXIS_Z].mg = results.axis[AXIS_Z].raw * convertMltply;
    results.axis[AXIS_Z].mg = results.axis[AXIS_Z].mg / _LIS3DSH_CONVERT_DATA_CONST_DIVIDER;
}
