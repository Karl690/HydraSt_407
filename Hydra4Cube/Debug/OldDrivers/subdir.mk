################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OldDrivers/can_4xx.c \
../OldDrivers/exti_4xx.c \
../OldDrivers/flash_4xx.c \
../OldDrivers/gpio_4xx.c \
../OldDrivers/iwdg_4xx.c \
../OldDrivers/misc_4xx.c \
../OldDrivers/rcc_4xx.c \
../OldDrivers/syscfg_4xx.c \
../OldDrivers/tim_4xx.c \
../OldDrivers/usart_4xx.c 

OBJS += \
./OldDrivers/can_4xx.o \
./OldDrivers/exti_4xx.o \
./OldDrivers/flash_4xx.o \
./OldDrivers/gpio_4xx.o \
./OldDrivers/iwdg_4xx.o \
./OldDrivers/misc_4xx.o \
./OldDrivers/rcc_4xx.o \
./OldDrivers/syscfg_4xx.o \
./OldDrivers/tim_4xx.o \
./OldDrivers/usart_4xx.o 

C_DEPS += \
./OldDrivers/can_4xx.d \
./OldDrivers/exti_4xx.d \
./OldDrivers/flash_4xx.d \
./OldDrivers/gpio_4xx.d \
./OldDrivers/iwdg_4xx.d \
./OldDrivers/misc_4xx.d \
./OldDrivers/rcc_4xx.d \
./OldDrivers/syscfg_4xx.d \
./OldDrivers/tim_4xx.d \
./OldDrivers/usart_4xx.d 


# Each subdirectory must supply rules for building sources it contributes
OldDrivers/%.o OldDrivers/%.su: ../OldDrivers/%.c OldDrivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DCOMPILE_FOR_SYSTEM -DSTM32F4XX_HYREL -DSTM32F4XX -DPINOUT_100094 -DUSE_HYREL_IO -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"C:/Users/karl6/Documents/GitHub/HydraSt_407/Hydra4Cube/OldDrivers" -I"C:/Users/karl6/Documents/GitHub/HydraSt_407/Hydra4Cube/Hydra" -I"C:/Users/karl6/Documents/GitHub/HydraSt_407/Hydra4Cube/common/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-OldDrivers

clean-OldDrivers:
	-$(RM) ./OldDrivers/can_4xx.d ./OldDrivers/can_4xx.o ./OldDrivers/can_4xx.su ./OldDrivers/exti_4xx.d ./OldDrivers/exti_4xx.o ./OldDrivers/exti_4xx.su ./OldDrivers/flash_4xx.d ./OldDrivers/flash_4xx.o ./OldDrivers/flash_4xx.su ./OldDrivers/gpio_4xx.d ./OldDrivers/gpio_4xx.o ./OldDrivers/gpio_4xx.su ./OldDrivers/iwdg_4xx.d ./OldDrivers/iwdg_4xx.o ./OldDrivers/iwdg_4xx.su ./OldDrivers/misc_4xx.d ./OldDrivers/misc_4xx.o ./OldDrivers/misc_4xx.su ./OldDrivers/rcc_4xx.d ./OldDrivers/rcc_4xx.o ./OldDrivers/rcc_4xx.su ./OldDrivers/syscfg_4xx.d ./OldDrivers/syscfg_4xx.o ./OldDrivers/syscfg_4xx.su ./OldDrivers/tim_4xx.d ./OldDrivers/tim_4xx.o ./OldDrivers/tim_4xx.su ./OldDrivers/usart_4xx.d ./OldDrivers/usart_4xx.o ./OldDrivers/usart_4xx.su

.PHONY: clean-OldDrivers

