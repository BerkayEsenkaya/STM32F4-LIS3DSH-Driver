################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ExtSensorDrivers/lis302.c 

OBJS += \
./Core/ExtSensorDrivers/lis302.o 

C_DEPS += \
./Core/ExtSensorDrivers/lis302.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ExtSensorDrivers/%.o Core/ExtSensorDrivers/%.su Core/ExtSensorDrivers/%.cyclo: ../Core/ExtSensorDrivers/%.c Core/ExtSensorDrivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ExtSensorDrivers

clean-Core-2f-ExtSensorDrivers:
	-$(RM) ./Core/ExtSensorDrivers/lis302.cyclo ./Core/ExtSensorDrivers/lis302.d ./Core/ExtSensorDrivers/lis302.o ./Core/ExtSensorDrivers/lis302.su

.PHONY: clean-Core-2f-ExtSensorDrivers

