################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common/lcd/fonts/font12.c \
../common/lcd/fonts/font16.c \
../common/lcd/fonts/font20.c \
../common/lcd/fonts/font20_14.c \
../common/lcd/fonts/font22.c \
../common/lcd/fonts/font24.c \
../common/lcd/fonts/font8.c 

OBJS += \
./common/lcd/fonts/font12.o \
./common/lcd/fonts/font16.o \
./common/lcd/fonts/font20.o \
./common/lcd/fonts/font20_14.o \
./common/lcd/fonts/font22.o \
./common/lcd/fonts/font24.o \
./common/lcd/fonts/font8.o 

C_DEPS += \
./common/lcd/fonts/font12.d \
./common/lcd/fonts/font16.d \
./common/lcd/fonts/font20.d \
./common/lcd/fonts/font20_14.d \
./common/lcd/fonts/font22.d \
./common/lcd/fonts/font24.d \
./common/lcd/fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
common/lcd/fonts/%.o common/lcd/fonts/%.su: ../common/lcd/fonts/%.c common/lcd/fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_HYDRA_IO -DCOMPILE_FOR_SYSTEM -DSTM32F4XX_HYREL -DSTM32F4XX -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/common/inc" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/oldcmsis_lib/inc" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/oldcmsis_boot" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/inc" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-lcd-2f-fonts

clean-common-2f-lcd-2f-fonts:
	-$(RM) ./common/lcd/fonts/font12.d ./common/lcd/fonts/font12.o ./common/lcd/fonts/font12.su ./common/lcd/fonts/font16.d ./common/lcd/fonts/font16.o ./common/lcd/fonts/font16.su ./common/lcd/fonts/font20.d ./common/lcd/fonts/font20.o ./common/lcd/fonts/font20.su ./common/lcd/fonts/font20_14.d ./common/lcd/fonts/font20_14.o ./common/lcd/fonts/font20_14.su ./common/lcd/fonts/font22.d ./common/lcd/fonts/font22.o ./common/lcd/fonts/font22.su ./common/lcd/fonts/font24.d ./common/lcd/fonts/font24.o ./common/lcd/fonts/font24.su ./common/lcd/fonts/font8.d ./common/lcd/fonts/font8.o ./common/lcd/fonts/font8.su

.PHONY: clean-common-2f-lcd-2f-fonts

