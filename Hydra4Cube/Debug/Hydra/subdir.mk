################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hydra/GCode.c \
../Hydra/HardwareInit.c \
../Hydra/Hydra_can.c \
../Hydra/MCode.c \
../Hydra/MotorDrivers.c \
../Hydra/Serial.c \
../Hydra/bootloader.c \
../Hydra/cruftyCode.c \
../Hydra/diags.c \
../Hydra/display.c \
../Hydra/headSetup.c \
../Hydra/mailbox.c \
../Hydra/old_main.c \
../Hydra/pinInit.c 

OBJS += \
./Hydra/GCode.o \
./Hydra/HardwareInit.o \
./Hydra/Hydra_can.o \
./Hydra/MCode.o \
./Hydra/MotorDrivers.o \
./Hydra/Serial.o \
./Hydra/bootloader.o \
./Hydra/cruftyCode.o \
./Hydra/diags.o \
./Hydra/display.o \
./Hydra/headSetup.o \
./Hydra/mailbox.o \
./Hydra/old_main.o \
./Hydra/pinInit.o 

C_DEPS += \
./Hydra/GCode.d \
./Hydra/HardwareInit.d \
./Hydra/Hydra_can.d \
./Hydra/MCode.d \
./Hydra/MotorDrivers.d \
./Hydra/Serial.d \
./Hydra/bootloader.d \
./Hydra/cruftyCode.d \
./Hydra/diags.d \
./Hydra/display.d \
./Hydra/headSetup.d \
./Hydra/mailbox.d \
./Hydra/old_main.d \
./Hydra/pinInit.d 


# Each subdirectory must supply rules for building sources it contributes
Hydra/%.o Hydra/%.su: ../Hydra/%.c Hydra/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DCOMPILE_FOR_SYSTEM -DSTM32F4XX_HYREL -DSTM32F4XX -DPINOUT_100094 -DUSE_HYREL_IO -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"C:/Users/karl6/Documents/GitHub/HydraSt_407/Hydra4Cube/OldDrivers" -I"C:/Users/karl6/Documents/GitHub/HydraSt_407/Hydra4Cube/Hydra" -I"C:/Users/karl6/Documents/GitHub/HydraSt_407/Hydra4Cube/common/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Hydra

clean-Hydra:
	-$(RM) ./Hydra/GCode.d ./Hydra/GCode.o ./Hydra/GCode.su ./Hydra/HardwareInit.d ./Hydra/HardwareInit.o ./Hydra/HardwareInit.su ./Hydra/Hydra_can.d ./Hydra/Hydra_can.o ./Hydra/Hydra_can.su ./Hydra/MCode.d ./Hydra/MCode.o ./Hydra/MCode.su ./Hydra/MotorDrivers.d ./Hydra/MotorDrivers.o ./Hydra/MotorDrivers.su ./Hydra/Serial.d ./Hydra/Serial.o ./Hydra/Serial.su ./Hydra/bootloader.d ./Hydra/bootloader.o ./Hydra/bootloader.su ./Hydra/cruftyCode.d ./Hydra/cruftyCode.o ./Hydra/cruftyCode.su ./Hydra/diags.d ./Hydra/diags.o ./Hydra/diags.su ./Hydra/display.d ./Hydra/display.o ./Hydra/display.su ./Hydra/headSetup.d ./Hydra/headSetup.o ./Hydra/headSetup.su ./Hydra/mailbox.d ./Hydra/mailbox.o ./Hydra/mailbox.su ./Hydra/old_main.d ./Hydra/old_main.o ./Hydra/old_main.su ./Hydra/pinInit.d ./Hydra/pinInit.o ./Hydra/pinInit.su

.PHONY: clean-Hydra

