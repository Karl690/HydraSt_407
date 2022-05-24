################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../oldcmsis_boot/system_stm32f4xx.c 

OBJS += \
./oldcmsis_boot/system_stm32f4xx.o 

C_DEPS += \
./oldcmsis_boot/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
oldcmsis_boot/%.o oldcmsis_boot/%.su: ../oldcmsis_boot/%.c oldcmsis_boot/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_HYDRA_IO -DCOMPILE_FOR_SYSTEM -DSTM32F4XX_HYREL -DSTM32F4XX -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/common/inc" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/oldcmsis_lib/inc" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/oldcmsis_boot" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/inc" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-oldcmsis_boot

clean-oldcmsis_boot:
	-$(RM) ./oldcmsis_boot/system_stm32f4xx.d ./oldcmsis_boot/system_stm32f4xx.o ./oldcmsis_boot/system_stm32f4xx.su

.PHONY: clean-oldcmsis_boot

