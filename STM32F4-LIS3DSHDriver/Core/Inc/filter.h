#include<stdint.h>

typedef struct{
 uint16_t Average;
 uint8_t entered;
 uint64_t sum;
 uint16_t data[256];
}AverageFilterParam_T;


uint16_t AverageFilter(AverageFilterParam_T *handle, uint16_t NewData, uint8_t DataAverageSize);
