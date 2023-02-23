################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/peripherals.c \
../board/pin_mux.c 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/peripherals.d \
./board/pin_mux.d 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/peripherals.o \
./board/pin_mux.o 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c board/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC5526JBD64 -DCPU_LPC5526JBD64_cm33 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\drivers" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\CMSIS_driver" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\device" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\CMSIS" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\utilities" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\serial_manager" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\uart" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\lists" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\board" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\board" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\source" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\drivers" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\CMSIS_driver" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\device" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\CMSIS" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\utilities" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\serial_manager" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\uart" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\lists" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-board

clean-board:
	-$(RM) ./board/board.d ./board/board.o ./board/clock_config.d ./board/clock_config.o ./board/peripherals.d ./board/peripherals.o ./board/pin_mux.d ./board/pin_mux.o

.PHONY: clean-board

