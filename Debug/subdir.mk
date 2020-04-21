################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AdmissionSystem.cpp \
../Capacities.cpp \
../Centers.cpp \
../Courses.cpp \
../Degrees.cpp \
../Eligibility.cpp \
../Preferences.cpp \
../Student.cpp \
../main.cpp 

OBJS += \
./AdmissionSystem.o \
./Capacities.o \
./Centers.o \
./Courses.o \
./Degrees.o \
./Eligibility.o \
./Preferences.o \
./Student.o \
./main.o 

CPP_DEPS += \
./AdmissionSystem.d \
./Capacities.d \
./Centers.d \
./Courses.d \
./Degrees.d \
./Eligibility.d \
./Preferences.d \
./Student.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


