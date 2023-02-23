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
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC5526JBD64 -DCPU_LPC5526JBD64_cm33 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\board" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\source" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\drivers" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\CMSIS_driver" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\device" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\CMSIS" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\utilities" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\component\serial_manager" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\component\uart" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\component\lists" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_lpc5526.d ./startup/startup_lpc5526.o

.PHONY: clean-startup

