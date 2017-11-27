################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/gtets_main.cpp \
../test/test_board.cpp \
../test/test_factorial.cpp 

OBJS += \
./test/gtets_main.o \
./test/test_board.o \
./test/test_factorial.o 

CPP_DEPS += \
./test/gtets_main.d \
./test/test_board.d \
./test/test_factorial.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


