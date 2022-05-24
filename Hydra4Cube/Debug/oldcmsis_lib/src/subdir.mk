################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../oldcmsis_lib/src/old_stm32f4xx_flash.c \
../oldcmsis_lib/src/old_stm32f4xx_gpio.c \
../oldcmsis_lib/src/stm32f4xx_adc.c \
../oldcmsis_lib/src/stm32f4xx_can.c \
../oldcmsis_lib/src/stm32f4xx_dac.c \
../oldcmsis_lib/src/stm32f4xx_dma.c \
../oldcmsis_lib/src/stm32f4xx_exti.c \
../oldcmsis_lib/src/stm32f4xx_fsmc.c \
../oldcmsis_lib/src/stm32f4xx_i2c.c \
../oldcmsis_lib/src/stm32f4xx_it.c \
../oldcmsis_lib/src/stm32f4xx_iwdg.c \
../oldcmsis_lib/src/stm32f4xx_misc.c \
../oldcmsis_lib/src/stm32f4xx_pwr.c \
../oldcmsis_lib/src/stm32f4xx_rcc.c \
../oldcmsis_lib/src/stm32f4xx_rtc.c \
../oldcmsis_lib/src/stm32f4xx_sdio.c \
../oldcmsis_lib/src/stm32f4xx_spi.c \
../oldcmsis_lib/src/stm32f4xx_syscfg.c \
../oldcmsis_lib/src/stm32f4xx_tim.c \
../oldcmsis_lib/src/stm32f4xx_usart.c 

OBJS += \
./oldcmsis_lib/src/old_stm32f4xx_flash.o \
./oldcmsis_lib/src/old_stm32f4xx_gpio.o \
./oldcmsis_lib/src/stm32f4xx_adc.o \
./oldcmsis_lib/src/stm32f4xx_can.o \
./oldcmsis_lib/src/stm32f4xx_dac.o \
./oldcmsis_lib/src/stm32f4xx_dma.o \
./oldcmsis_lib/src/stm32f4xx_exti.o \
./oldcmsis_lib/src/stm32f4xx_fsmc.o \
./oldcmsis_lib/src/stm32f4xx_i2c.o \
./oldcmsis_lib/src/stm32f4xx_it.o \
./oldcmsis_lib/src/stm32f4xx_iwdg.o \
./oldcmsis_lib/src/stm32f4xx_misc.o \
./oldcmsis_lib/src/stm32f4xx_pwr.o \
./oldcmsis_lib/src/stm32f4xx_rcc.o \
./oldcmsis_lib/src/stm32f4xx_rtc.o \
./oldcmsis_lib/src/stm32f4xx_sdio.o \
./oldcmsis_lib/src/stm32f4xx_spi.o \
./oldcmsis_lib/src/stm32f4xx_syscfg.o \
./oldcmsis_lib/src/stm32f4xx_tim.o \
./oldcmsis_lib/src/stm32f4xx_usart.o 

C_DEPS += \
./oldcmsis_lib/src/old_stm32f4xx_flash.d \
./oldcmsis_lib/src/old_stm32f4xx_gpio.d \
./oldcmsis_lib/src/stm32f4xx_adc.d \
./oldcmsis_lib/src/stm32f4xx_can.d \
./oldcmsis_lib/src/stm32f4xx_dac.d \
./oldcmsis_lib/src/stm32f4xx_dma.d \
./oldcmsis_lib/src/stm32f4xx_exti.d \
./oldcmsis_lib/src/stm32f4xx_fsmc.d \
./oldcmsis_lib/src/stm32f4xx_i2c.d \
./oldcmsis_lib/src/stm32f4xx_it.d \
./oldcmsis_lib/src/stm32f4xx_iwdg.d \
./oldcmsis_lib/src/stm32f4xx_misc.d \
./oldcmsis_lib/src/stm32f4xx_pwr.d \
./oldcmsis_lib/src/stm32f4xx_rcc.d \
./oldcmsis_lib/src/stm32f4xx_rtc.d \
./oldcmsis_lib/src/stm32f4xx_sdio.d \
./oldcmsis_lib/src/stm32f4xx_spi.d \
./oldcmsis_lib/src/stm32f4xx_syscfg.d \
./oldcmsis_lib/src/stm32f4xx_tim.d \
./oldcmsis_lib/src/stm32f4xx_usart.d 


# Each subdirectory must supply rules for building sources it contributes
oldcmsis_lib/src/%.o oldcmsis_lib/src/%.su: ../oldcmsis_lib/src/%.c oldcmsis_lib/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_HYDRA_IO -DCOMPILE_FOR_SYSTEM -DSTM32F4XX_HYREL -DSTM32F4XX -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/common/inc" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/oldcmsis_lib/inc" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/oldcmsis_boot" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/inc" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-oldcmsis_lib-2f-src

clean-oldcmsis_lib-2f-src:
	-$(RM) ./oldcmsis_lib/src/old_stm32f4xx_flash.d ./oldcmsis_lib/src/old_stm32f4xx_flash.o ./oldcmsis_lib/src/old_stm32f4xx_flash.su ./oldcmsis_lib/src/old_stm32f4xx_gpio.d ./oldcmsis_lib/src/old_stm32f4xx_gpio.o ./oldcmsis_lib/src/old_stm32f4xx_gpio.su ./oldcmsis_lib/src/stm32f4xx_adc.d ./oldcmsis_lib/src/stm32f4xx_adc.o ./oldcmsis_lib/src/stm32f4xx_adc.su ./oldcmsis_lib/src/stm32f4xx_can.d ./oldcmsis_lib/src/stm32f4xx_can.o ./oldcmsis_lib/src/stm32f4xx_can.su ./oldcmsis_lib/src/stm32f4xx_dac.d ./oldcmsis_lib/src/stm32f4xx_dac.o ./oldcmsis_lib/src/stm32f4xx_dac.su ./oldcmsis_lib/src/stm32f4xx_dma.d ./oldcmsis_lib/src/stm32f4xx_dma.o ./oldcmsis_lib/src/stm32f4xx_dma.su ./oldcmsis_lib/src/stm32f4xx_exti.d ./oldcmsis_lib/src/stm32f4xx_exti.o ./oldcmsis_lib/src/stm32f4xx_exti.su ./oldcmsis_lib/src/stm32f4xx_fsmc.d ./oldcmsis_lib/src/stm32f4xx_fsmc.o ./oldcmsis_lib/src/stm32f4xx_fsmc.su ./oldcmsis_lib/src/stm32f4xx_i2c.d ./oldcmsis_lib/src/stm32f4xx_i2c.o ./oldcmsis_lib/src/stm32f4xx_i2c.su ./oldcmsis_lib/src/stm32f4xx_it.d ./oldcmsis_lib/src/stm32f4xx_it.o ./oldcmsis_lib/src/stm32f4xx_it.su ./oldcmsis_lib/src/stm32f4xx_iwdg.d ./oldcmsis_lib/src/stm32f4xx_iwdg.o ./oldcmsis_lib/src/stm32f4xx_iwdg.su ./oldcmsis_lib/src/stm32f4xx_misc.d ./oldcmsis_lib/src/stm32f4xx_misc.o ./oldcmsis_lib/src/stm32f4xx_misc.su ./oldcmsis_lib/src/stm32f4xx_pwr.d ./oldcmsis_lib/src/stm32f4xx_pwr.o ./oldcmsis_lib/src/stm32f4xx_pwr.su ./oldcmsis_lib/src/stm32f4xx_rcc.d ./oldcmsis_lib/src/stm32f4xx_rcc.o ./oldcmsis_lib/src/stm32f4xx_rcc.su ./oldcmsis_lib/src/stm32f4xx_rtc.d ./oldcmsis_lib/src/stm32f4xx_rtc.o ./oldcmsis_lib/src/stm32f4xx_rtc.su ./oldcmsis_lib/src/stm32f4xx_sdio.d ./oldcmsis_lib/src/stm32f4xx_sdio.o ./oldcmsis_lib/src/stm32f4xx_sdio.su ./oldcmsis_lib/src/stm32f4xx_spi.d ./oldcmsis_lib/src/stm32f4xx_spi.o ./oldcmsis_lib/src/stm32f4xx_spi.su ./oldcmsis_lib/src/stm32f4xx_syscfg.d ./oldcmsis_lib/src/stm32f4xx_syscfg.o ./oldcmsis_lib/src/stm32f4xx_syscfg.su ./oldcmsis_lib/src/stm32f4xx_tim.d ./oldcmsis_lib/src/stm32f4xx_tim.o ./oldcmsis_lib/src/stm32f4xx_tim.su ./oldcmsis_lib/src/stm32f4xx_usart.d ./oldcmsis_lib/src/stm32f4xx_usart.o ./oldcmsis_lib/src/stm32f4xx_usart.su

.PHONY: clean-oldcmsis_lib-2f-src

