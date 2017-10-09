################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: colibriEclipseHello

# Tool invocations
colibriEclipseHello: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	arm-linux-gnueabihf-gcc -L/opt/Colibri_T30_LinuxImageV2.6/rootfs/usr/lib -Wl,-rpath-link,/opt/Colibri_T30_LinuxImageV2.6/rootfs/usr/lib -L/opt/Colibri_T30_LinuxImageV2.6/rootfs/lib -Wl,-rpath-link,/opt/Colibri_T30_LinuxImageV2.6/rootfs/lib -o "colibriEclipseHello" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) colibriEclipseHello
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
