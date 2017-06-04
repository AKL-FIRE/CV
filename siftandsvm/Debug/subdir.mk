################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Bow.cpp \
../OtsuHand.cpp \
../SVMClassifier.cpp \
../play.cpp \
../sift.cpp 

OBJS += \
./Bow.o \
./OtsuHand.o \
./SVMClassifier.o \
./play.o \
./sift.o 

CPP_DEPS += \
./Bow.d \
./OtsuHand.d \
./SVMClassifier.d \
./play.d \
./sift.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -I/usr/local/include/opencv2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


