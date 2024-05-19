/*
 * filter.c
 *
 *  Created on: May 18, 2024
 *      Author: esenk
 */

#include"filter.h"

uint16_t AverageFilter(AverageFilterParam_T *handle, uint16_t NewData, uint8_t DataAverageSize){
	uint8_t i;
	if(handle->entered == 0){
		handle->data[handle->entered] = NewData;
		handle->entered = 1;
		return 0;
	}
	handle->data[handle->entered] = NewData;
	handle->entered += 1;
	if(handle->entered == DataAverageSize){
		for(i=0 ; i<(handle->entered); i++){
			handle->sum +=  handle->data[i];
		}
		handle->Average = handle->sum / handle->entered;
		for(i=0; i<(handle->entered-1); i++){
		    handle->data[i] = handle->data[i+1];
		}
		handle->entered -=1;
		handle->sum = 0;
		return handle->Average;
	}
}
