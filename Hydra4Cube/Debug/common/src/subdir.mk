################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common/src/gui.c \
../common/src/hyrel_can.c \
../common/src/pins.c \
../common/src/util.c 

OBJS += \
./common/src/gui.o \
./common/src/hyrel_can.o \
./common/src/pins.o \
./common/src/util.o 

C_DEPS += \
./common/src/gui.d \
./common/src/hyrel_can.d \
./common/src/pins.d \
./common/src/util.d 


# Each subdirectory must supply rules for building sources it contributes
common/src/%.o common/src/%.su: ../common/src/%.c common/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DCOMPILE_FOR_SYSTEM -DSTM32F4XX_HYREL -DSTM32F4XX -DPINOUT_100094 -DUSE_HYREL_IO -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"C:/Users/karl6/Documents/GitHub/HydraSt_407/Hydra4Cube/OldDrivers" -I"C:/Users/karl6/Documents/GitHub/HydraSt_407/Hydra4Cube/Hydra" -I"C:/Users/karl6/Documents/GitHub/HydraSt_407/Hydra4Cube/common/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-src

clean-common-2f-src:
	-$(RM) ./common/src/gui.d ./common/src/gui.o ./common/src/gui.su ./common/src/hyrel_can.d ./common/src/hyrel_can.o ./common/src/hyrel_can.su ./common/src/pins.d ./common/src/pins.o ./common/src/pins.su ./common/src/util.d ./common/src/util.o ./common/src/util.su

.PHONY: clean-common-2f-src

