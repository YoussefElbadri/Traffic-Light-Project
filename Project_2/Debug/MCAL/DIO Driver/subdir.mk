################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO\ Driver/DIO.c 

OBJS += \
./MCAL/DIO\ Driver/DIO.o 

C_DEPS += \
./MCAL/DIO\ Driver/DIO.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO\ Driver/DIO.o: ../MCAL/DIO\ Driver/DIO.c MCAL/DIO\ Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"MCAL/DIO Driver/DIO.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


