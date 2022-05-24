################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GCode.c \
../src/HardwareInit.c \
../src/Hydra_can.c \
../src/MCode.c \
../src/MotorDrivers.c \
../src/Serial.c \
../src/bootloader.c \
../src/cruftyCode.c \
../src/diags.c \
../src/display.c \
../src/headSetup.c \
../src/mailbox.c \
../src/pinInit.c 

OBJS += \
./src/GCode.o \
./src/HardwareInit.o \
./src/Hydra_can.o \
./src/MCode.o \
./src/MotorDrivers.o \
./src/Serial.o \
./src/bootloader.o \
./src/cruftyCode.o \
./src/diags.o \
./src/display.o \
./src/headSetup.o \
./src/mailbox.o \
./src/pinInit.o 

C_DEPS += \
./src/GCode.d \
./src/HardwareInit.d \
./src/Hydra_can.d \
./src/MCode.d \
./src/MotorDrivers.d \
./src/Serial.d \
./src/bootloader.d \
./src/cruftyCode.d \
./src/diags.d \
./src/display.d \
./src/headSetup.d \
./src/mailbox.d \
./src/pinInit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DUSE_HYDRA_IO -DCOMPILE_FOR_SYSTEM -DSTM32F4XX_HYREL -DSTM32F4XX -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/common/inc" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/oldcmsis_lib/inc" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/oldcmsis_boot" -I"D:/HYREL/GIT/HydraSt_407/Hydra4Cube/inc" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/GCode.d ./src/GCode.o ./src/GCode.su ./src/HardwareInit.d ./src/HardwareInit.o ./src/HardwareInit.su ./src/Hydra_can.d ./src/Hydra_can.o ./src/Hydra_can.su ./src/MCode.d ./src/MCode.o ./src/MCode.su ./src/MotorDrivers.d ./src/MotorDrivers.o ./src/MotorDrivers.su ./src/Serial.d ./src/Serial.o ./src/Serial.su ./src/bootloader.d ./src/bootloader.o ./src/bootloader.su ./src/cruftyCode.d ./src/cruftyCode.o ./src/cruftyCode.su ./src/diags.d ./src/diags.o ./src/diags.su ./src/display.d ./src/display.o ./src/display.su ./src/headSetup.d ./src/headSetup.o ./src/headSetup.su ./src/mailbox.d ./src/mailbox.o ./src/mailbox.su ./src/pinInit.d ./src/pinInit.o ./src/pinInit.su

.PHONY: clean-src

