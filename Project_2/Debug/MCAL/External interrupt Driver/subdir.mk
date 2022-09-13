################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/External\ interrupt\ Driver/External_interrupt.c 

OBJS += \
./MCAL/External\ interrupt\ Driver/External_interrupt.o 

C_DEPS += \
./MCAL/External\ interrupt\ Driver/External_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/External\ interrupt\ Driver/External_interrupt.o: ../MCAL/External\ interrupt\ Driver/External_interrupt.c MCAL/External\ interrupt\ Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"MCAL/External interrupt Driver/External_interrupt.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


