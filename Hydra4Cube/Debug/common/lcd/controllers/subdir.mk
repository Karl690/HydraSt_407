################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common/lcd/controllers/ili9341.c \
../common/lcd/controllers/ssd1306.c \
../common/lcd/controllers/st7735.c 

OBJS += \
./common/lcd/controllers/ili9341.o \
./common/lcd/controllers/ssd1306.o \
./common/lcd/controllers/st7735.o 

C_DEPS += \
./common/lcd/controllers/ili9341.d \
./common/lcd/controllers/ssd1306.d \
./common/lcd/controllers/st7735.d 


# Each subdirectory must supply rules for building sources it contributes
common/lcd/controllers/%.o common/lcd/controllers/%.su: ../common/lcd/controllers/%.c common/lcd/controllers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_HYDRA_IO -DCOMPILE_FOR_SYSTEM -DSTM32F4XX_HYREL -DSTM32F4XX -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/common/inc" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/oldcmsis_lib/inc" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/oldcmsis_boot" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/inc" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-lcd-2f-controllers

clean-common-2f-lcd-2f-controllers:
	-$(RM) ./common/lcd/controllers/ili9341.d ./common/lcd/controllers/ili9341.o ./common/lcd/controllers/ili9341.su ./common/lcd/controllers/ssd1306.d ./common/lcd/controllers/ssd1306.o ./common/lcd/controllers/ssd1306.su ./common/lcd/controllers/st7735.d ./common/lcd/controllers/st7735.o ./common/lcd/controllers/st7735.su

.PHONY: clean-common-2f-lcd-2f-controllers

