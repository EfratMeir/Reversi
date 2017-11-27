################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Board.cpp \
../src/ComputerPlayer.cpp \
../src/Fliper.cpp \
../src/GameFlow.cpp \
../src/HumenPlayer.cpp \
../src/MovesCalculator.cpp \
../src/Player.cpp \
../src/Point.cpp \
../src/PointsCounter.cpp \
../src/Sprite.cpp \
../src/TurnBase.cpp \
../src/factorial.cpp \
../src/main.cpp 

OBJS += \
./src/Board.o \
./src/ComputerPlayer.o \
./src/Fliper.o \
./src/GameFlow.o \
./src/HumenPlayer.o \
./src/MovesCalculator.o \
./src/Player.o \
./src/Point.o \
./src/PointsCounter.o \
./src/Sprite.o \
./src/TurnBase.o \
./src/factorial.o \
./src/main.o 

CPP_DEPS += \
./src/Board.d \
./src/ComputerPlayer.d \
./src/Fliper.d \
./src/GameFlow.d \
./src/HumenPlayer.d \
./src/MovesCalculator.d \
./src/Player.d \
./src/Point.d \
./src/PointsCounter.d \
./src/Sprite.d \
./src/TurnBase.d \
./src/factorial.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


