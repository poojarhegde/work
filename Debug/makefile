################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ../$(APP_NAME)

# Tool invocations
../$(APP_NAME): $(OBJS) $(OBJS_$(ARCH)) $(OBJ_APP) $(USER_OBJS) $(LD_LIBS_MK)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	$Q $(CCC) $(CFLAGS) $(LDFLAGS) -static-libgcc -o $@ $(OBJS_$(ARCH)) $(OBJ_APP) $(OBJS) $(LIBS) $(LD_LIBS) $(LD_LIBS_OS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(C_DEPS)$(CPP_DEPS) ../$(APP_NAME)
	-@echo ' '

post-build:
	-$(SET_EXE_PERMISSIONS) ../$(APP_NAME)
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
