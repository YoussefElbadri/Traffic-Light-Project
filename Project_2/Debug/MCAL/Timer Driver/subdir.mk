################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timer\ Driver/Timer.c 

OBJS += \
./MCAL/Timer\ Driver/Timer.o 

C_DEPS += \
./MCAL/Timer\ Driver/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timer\ Driver/Timer.o: ../MCAL/Timer\ Driver/Timer.c MCAL/Timer\ Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"MCAL/Timer Driver/Timer.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


