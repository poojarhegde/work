################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APO_user.c \
../CM_Main.c \
../CM_Vehicle.c \
../User.c 

O_SRCS += \
../APO_user.o \
../CM_Main.o \
../CM_Vehicle.o \
../User.o \
../app_tmp.o 

OBJS += \
./APO_user.o \
./CM_Main.o \
./CM_Vehicle.o \
./User.o 

C_DEPS += \
./APO_user.d \
./CM_Main.d \
./CM_Vehicle.d \
./User.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	$(CC) $(CPPFLAGS) $(CFLAGS) -O1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"   -c $< -o $@
	@echo 'Finished building: $<'
	@echo ' '


