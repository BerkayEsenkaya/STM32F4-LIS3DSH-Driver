#include<stdint.h>
#include"main.h"
#include"lis302.h"
#include"spi.h"

#define LIS3DSH_SPIMODE_READ  0b10000000
#define LIS3DSH_SPIMODE_WRITE 0b00111111

//extern SPI_Handle_T *SPI_1;

uint8_t LIS3DSH_Init(SPI_HandleTypeDef *handle){

}


uint8_t LIS3DSH_Read_Reg(uint8_t RegAddr, uint8_t *rxBuff,uint8_t lenght){
	uint8_t txBuff[1];

	txBuff[0] = RegAddr | LIS3DSH_SPIMODE_READ;

	SPI_TransmitReceive(SPI_NO1, txBuff, rxBuff, 1, lenght);
}

uint8_t LIS3DSH_Write_Reg(uint8_t RegAddr, uint8_t *data,uint8_t lenght){
	uint8_t txBuff[lenght+1];
	uint8_t i;

	txBuff[0] = RegAddr & LIS3DSH_SPIMODE_WRITE;
	for(i=1;i<lenght+1;i++){
	  txBuff[i] = data[i-1];
	}

	SPI_TransmitReceive(SPI_NO1, txBuff, NULL, lenght, 0);
}

uint8_t LIS3DSH_Reg_Set_Ctrl1(LIS3DSH_HYST1_T hys, LIS3DSH_SM1_PIN_T sm1_pin, LIS3DSH_SM1_EN_T sm1_en){
	LIS3DSH_REG_CTRL_1_T SetReg;
	uint8_t txBuff[1];
	SetReg.hys = hys;
	SetReg.sm1_pin = sm1_pin;
	SetReg.sm1_en = sm1_en;
	txBuff[0] = SetReg.CTRL1;
	LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL1, txBuff, 2);
}

uint8_t LIS3DSH_Reg_Set_Ctrl2(LIS3DSH_HYST2_T hys, LIS3DSH_SM2_PIN_T sm2_pin, LIS3DSH_SM2_EN_T sm2_en){
	LIS3DSH_REG_CTRL_2_T SetReg;
    uint8_t txBuff[1];
    SetReg.hys = hys;
    SetReg.sm2_pin = sm2_pin;
    SetReg.sm2_en = sm2_en;
    txBuff[0] = SetReg.CTRL2;
    LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL2, txBuff, 2);
}

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
    LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL3, txBuff, 2);
}

uint8_t LIS3DSH_Reg_Set_Ctrl4(LIS3DSH_ODR_T odrVal, LIS3DSH_BDU_T bduVal, LIS3DSH_XEN_T StateXAxis, LIS3DSH_YEN_T StateYAxis, LIS3DSH_ZEN_T StateZAxis ){
    LIS3DSH_REG_CTRL_4_T SetReg;
    uint8_t txBuff[1];
    SetReg.odr = odrVal;
    SetReg.bdu = bduVal;
    SetReg.xaxis_en = StateXAxis;
    SetReg.yaxis_en = StateYAxis;
    SetReg.zaxis_en = StateZAxis;
    txBuff[0] = SetReg.CTRL4;
    LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL4, txBuff, 2);
}

uint8_t LIS3DSH_Reg_Set_Ctrl5(LIS3DSH_BW_T bw,LIS3DSH_FSCALE_T scale, LIS3DSH_ST_T selftest ,LIS3DSH_SIM_T spiMode ){
	LIS3DSH_REG_CTRL_5_T SetReg;
	uint8_t txBuff[1];
	SetReg.bandwith = bw;
	SetReg.scale = scale;
	SetReg.selftest = selftest;
	SetReg.spiMode = spiMode;
	txBuff[0] = SetReg.CTRL5;
	LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL5, txBuff, 2);
}

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
    LIS3DSH_Write_Reg(_LIS3DSH_REGADDR_CTRL6, txBuff, 2);
}

uint8_t LIS3DSH_Read_Accmeter_Data(uint8_t *data_X_buff, uint8_t *data_Y_buff, uint8_t *data_Z_buff){
	uint8_t temp[1];
	LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_XH, temp,1);
    data_X_buff[0] = temp[0];
    LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_XL, temp,1);
    data_X_buff[1] = temp[0];
    LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_YH, temp,1);
    data_Y_buff[0] = temp[0];
    LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_YL, temp,1);
    data_Y_buff[1] = temp[0];
    LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_ZH, temp,1);
    data_Z_buff[0] = temp[0];
    LIS3DSH_Read_Reg(_LIS3DSH_REGADDR_OUTPUT_AXIS_ZL, temp,1);
    data_Z_buff[1] = temp[0];
}
