################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_lpc5526.c 

C_DEPS += \
./startup/startup_lpc5526.d 

OBJS += \
./startup/startup_lpc5526.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC5526JBD64 -DCPU_LPC5526JBD64_cm33 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\drivers" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\CMSIS_driver" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\device" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\CMSIS" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\utilities" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\component\serial_manager" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\component\uart" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\component\lists" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\board" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\board" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\source" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\drivers" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\CMSIS_driver" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\device" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\CMSIS" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\utilities" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\component\serial_manager" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\component\uart" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\test\component\lists" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_lpc5526.d ./startup/startup_lpc5526.o

.PHONY: clean-startup

