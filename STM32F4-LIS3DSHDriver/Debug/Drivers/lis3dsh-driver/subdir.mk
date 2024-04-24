################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lis3dsh-driver/lis302.c 

OBJS += \
./Drivers/lis3dsh-driver/lis302.o 

C_DEPS += \
./Drivers/lis3dsh-driver/lis302.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lis3dsh-driver/%.o Drivers/lis3dsh-driver/%.su Drivers/lis3dsh-driver/%.cyclo: ../Drivers/lis3dsh-driver/%.c Drivers/lis3dsh-driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lis3dsh-2d-driver

clean-Drivers-2f-lis3dsh-2d-driver:
	-$(RM) ./Drivers/lis3dsh-driver/lis302.cyclo ./Drivers/lis3dsh-driver/lis302.d ./Drivers/lis3dsh-driver/lis302.o ./Drivers/lis3dsh-driver/lis302.su

.PHONY: clean-Drivers-2f-lis3dsh-2d-driver

