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
#define _LIS3DSH_REGADDR_CTRL1  0x20


typedef struct{
  void *handle;
  uint8_t spiNo;
  uint8_t spiNode;
}LIS3DHH_Module_T;

typedef enum{
  DATA_RATE_100Hz,
  DATA_RATE_400Hz,
}LIS302_DateRateSelection_T;

typedef enum{
  POWER_DOWN,
  POWER_ON,
}LIS302_PowerControl_T;

typedef enum{
  RANGE_2G,
  RANGE_8G,
}LIS302_RangeSelection_T;

typedef enum{
  SELFTEST_DISABLE,
  SELFTEST_ENABLE,
}LIS302_SelfTestSelection_T;

typedef enum{
  AXIS_DISABLE,
  AXIS_ENABLE,
}LIS302_AxisOnOff_T;

typedef enum{
  SPIMODE_4WIRE,
  SPIMODE_3WIRE,
}LIS302_SpiMode_T;

typedef enum{
  BOOT_DISABLE,
  BOOT_ENABLE,
}LIS302_REBOOT_T;

typedef enum{
  INTERNALFILTER_OFF,
  INTERNALFILTER_ON,
}LIS302_FilterSelect_T;

typedef enum{
  HIGHPASS_FILTER_DISABLE,
  HIGHPASS_FILTER_ENABLE,
}LIS302_HighPassFilterSelect_T;

typedef enum{
  HIGHPASSCOEF_8,
  HIGHPASSCOEF_4,
  HIGHPASSCOEF_2,
  HIGHPASSCOEF_1,
}LIS302_HighPassCoefficent_T;

typedef enum{
  INTERRUPTACTIVE_LOW,
  INTERRUPTACTİVE_HIGH,
}LIS302_InterruptActiveSelec_T;

typedef enum {
  INTPAD_PUSHPULL,
  INTPAD_OPENDRAIN,
}LIS302_IntPadSelect_T;

typedef enum{
  INT_OR,
  INT_AND,
}LIS302_IntCombination_T;

typedef enum{
  IRQ_NOT_LATCH,
  IRQ_LATCH
}LIS302_LIR_T;

typedef enum{
  IRQ_DISABLE,
  IRQ_ENABLE,
}LIS302_XYZHIE_XYZLIE_T;

typedef enum{
  COUNTER_RESET,
  COUNTER_DECREMENT,
}LIS302_DCMR_T;

typedef enum{
  CLICK_OFF,
  CLICK_SINGLE,
  CLICK_DOUBLE,
  CLICK_SINGLE_DOUBLE,
}LIS302_ClickSelect_T;

typedef enum{
  CLICK_THR_0d5G,
  CLICK_THR_1G,
  CLICK_THR_1d5G,
  CLICK_THR_2G,
  CLICK_THR_2d5G,
  CLICK_THR_3G,
  CLICK_THR_3d5G,
  CLICK_THR_4G,
  CLICK_THR_4d5G,
  CLICK_THR_5G,
  CLICK_THR_5d5G,
  CLICK_THR_6G,
  CLICK_THR_6d5G,
  CLICK_THR_7G,
  CLICK_THR_7d5G,
}LIS302_ClickThreshold_T;

typedef union{
 struct{
	 LIS302_AxisOnOff_T         XaxisState : 1;
	 LIS302_AxisOnOff_T         YaxisState : 1;
	 LIS302_AxisOnOff_T         ZaxisState : 1;
	 LIS302_SelfTestSelection_T selftestM  : 1;
	 LIS302_SelfTestSelection_T selftestP  : 1;
	 LIS302_RangeSelection_T    range      : 1;
	 LIS302_PowerControl_T      pwrctrl    : 1;
	 LIS302_DateRateSelection_T datarate   : 1;
 };
}LIS302_CTRL_REG1_T;

typedef union{
 struct{
	 LIS302_HighPassCoefficent_T   hpcoef1   : 1;
	 LIS302_HighPassCoefficent_T   hpcoef2   : 1;
	 LIS302_HighPassFilterSelect_T hpfilter1 : 1;
	 LIS302_HighPassFilterSelect_T hpfilter2 : 1;
	 LIS302_FilterSelect_T         filter    : 1;
	 LIS302_REBOOT_T               boot      : 1;
	 LIS302_SpiMode_T              spimode   : 1;
 };
};



uint8_t LIS3DHH_Read_Reg(SPI_HandleTypeDef *handle, uint8_t RegAddr, uint8_t *rxBuff,uint8_t lenght);
uint8_t LIS3DHH_Write_Reg(SPI_HandleTypeDef *handle, uint8_t RegAddr, uint8_t *data,uint8_t lenght);
