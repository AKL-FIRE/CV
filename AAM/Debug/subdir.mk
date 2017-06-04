################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AAM_Basic.cpp \
../AAM_CAM.cpp \
../AAM_IC.cpp \
../AAM_MovieAVI.cpp \
../AAM_PAW.cpp \
../AAM_PDM.cpp \
../AAM_Shape.cpp \
../AAM_TDM.cpp \
../AAM_Util.cpp \
../VJfacedetect.cpp 

OBJS += \
./AAM_Basic.o \
./AAM_CAM.o \
./AAM_IC.o \
./AAM_MovieAVI.o \
./AAM_PAW.o \
./AAM_PDM.o \
./AAM_Shape.o \
./AAM_TDM.o \
./AAM_Util.o \
./VJfacedetect.o 

CPP_DEPS += \
./AAM_Basic.d \
./AAM_CAM.d \
./AAM_IC.d \
./AAM_MovieAVI.d \
./AAM_PAW.d \
./AAM_PDM.d \
./AAM_Shape.d \
./AAM_TDM.d \
./AAM_Util.d \
./VJfacedetect.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/usr/local/include/opencv2 -I/usr/local/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


