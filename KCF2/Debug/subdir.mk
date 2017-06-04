################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DataProcess.cpp \
../DrawPath.cpp \
../HOGFeature.cpp \
../KalmanFilter.cpp \
../SVMClassifier.cpp \
../fhog.cpp \
../kcftracker.cpp \
../train_run.cpp 

OBJS += \
./DataProcess.o \
./DrawPath.o \
./HOGFeature.o \
./KalmanFilter.o \
./SVMClassifier.o \
./fhog.o \
./kcftracker.o \
./train_run.o 

CPP_DEPS += \
./DataProcess.d \
./DrawPath.d \
./HOGFeature.d \
./KalmanFilter.d \
./SVMClassifier.d \
./fhog.d \
./kcftracker.d \
./train_run.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv -I/usr/local/include/opencv2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


