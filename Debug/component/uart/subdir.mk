################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/uart/fsl_adapter_usart.c 

C_DEPS += \
./component/uart/fsl_adapter_usart.d 

OBJS += \
./component/uart/fsl_adapter_usart.o 


# Each subdirectory must supply rules for building sources it contributes
component/uart/%.o: ../component/uart/%.c component/uart/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC5526JBD64 -DCPU_LPC5526JBD64_cm33 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\board" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\source" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\drivers" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\CMSIS_driver" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\device" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\CMSIS" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\utilities" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\component\serial_manager" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\component\uart" -I"C:\Users\Martijn Roubus\Downloads\LPC5526_PM\component\lists" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-component-2f-uart

clean-component-2f-uart:
	-$(RM) ./component/uart/fsl_adapter_usart.d ./component/uart/fsl_adapter_usart.o

.PHONY: clean-component-2f-uart

