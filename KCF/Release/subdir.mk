################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HOGFeature.cpp \
../KalmanFilter.cpp \
../fhog.cpp \
../kcftracker.cpp \
../main.cpp 

OBJS += \
./HOGFeature.o \
./KalmanFilter.o \
./fhog.o \
./kcftracker.o \
./main.o 

CPP_DEPS += \
./HOGFeature.d \
./KalmanFilter.d \
./fhog.d \
./kcftracker.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv2 -I/usr/local/include/opencv -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


