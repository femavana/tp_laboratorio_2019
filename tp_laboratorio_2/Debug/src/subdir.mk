################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TrabajoPractico2.c \
../src/arrayEmployees.c \
../src/getInput.c 

OBJS += \
./src/TrabajoPractico2.o \
./src/arrayEmployees.o \
./src/getInput.o 

C_DEPS += \
./src/TrabajoPractico2.d \
./src/arrayEmployees.d \
./src/getInput.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


