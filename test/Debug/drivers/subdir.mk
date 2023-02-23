################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_dma.c \
../drivers/fsl_flexcomm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_i2c_cmsis.c \
../drivers/fsl_i2c_dma.c \
../drivers/fsl_lpadc.c \
../drivers/fsl_power.c \
../drivers/fsl_reset.c \
../drivers/fsl_spi.c \
../drivers/fsl_spi_cmsis.c \
../drivers/fsl_spi_dma.c \
../drivers/fsl_usart.c 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_dma.d \
./drivers/fsl_flexcomm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_i2c_cmsis.d \
./drivers/fsl_i2c_dma.d \
./drivers/fsl_lpadc.d \
./drivers/fsl_power.d \
./drivers/fsl_reset.d \
./drivers/fsl_spi.d \
./drivers/fsl_spi_cmsis.d \
./drivers/fsl_spi_dma.d \
./drivers/fsl_usart.d 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_dma.o \
./drivers/fsl_flexcomm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_i2c_cmsis.o \
./drivers/fsl_i2c_dma.o \
./drivers/fsl_lpadc.o \
./drivers/fsl_power.o \
./drivers/fsl_reset.o \
./drivers/fsl_spi.o \
./drivers/fsl_spi_cmsis.o \
./drivers/fsl_spi_dma.o \
./drivers/fsl_usart.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC5526JBD64 -DCPU_LPC5526JBD64_cm33 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\drivers" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\CMSIS_driver" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\device" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\CMSIS" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\utilities" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\serial_manager" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\uart" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\lists" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\board" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\board" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\source" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\drivers" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\CMSIS_driver" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\device" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\CMSIS" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\utilities" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\serial_manager" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\uart" -I"C:\Users\Martijn Roubus\Documents\github_rep\PM_playground\test\component\lists" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_dma.d ./drivers/fsl_dma.o ./drivers/fsl_flexcomm.d ./drivers/fsl_flexcomm.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_i2c.d ./drivers/fsl_i2c.o ./drivers/fsl_i2c_cmsis.d ./drivers/fsl_i2c_cmsis.o ./drivers/fsl_i2c_dma.d ./drivers/fsl_i2c_dma.o ./drivers/fsl_lpadc.d ./drivers/fsl_lpadc.o ./drivers/fsl_power.d ./drivers/fsl_power.o ./drivers/fsl_reset.d ./drivers/fsl_reset.o ./drivers/fsl_spi.d ./drivers/fsl_spi.o ./drivers/fsl_spi_cmsis.d ./drivers/fsl_spi_cmsis.o ./drivers/fsl_spi_dma.d ./drivers/fsl_spi_dma.o ./drivers/fsl_usart.d ./drivers/fsl_usart.o

.PHONY: clean-drivers

