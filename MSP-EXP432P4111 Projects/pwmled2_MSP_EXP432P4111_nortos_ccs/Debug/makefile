################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main_nortos.obj" \
"./pwmled2.obj" \
"./syscfg/ti_drivers_config.obj" \
"../MSP_EXP432P4111_NoRTOS.cmd" \
$(GEN_CMDS__FLAG) \
-l"ti/display/lib/display.aem4f" \
-l"ti/grlib/lib/ccs/m4f/grlib.a" \
-l"third_party/spiffs/lib/ccs/m4f/spiffs.a" \
-l"ti/drivers/lib/drivers_msp432p4x1xi.aem4f" \
-l"third_party/fatfs/lib/ccs/m4f/fatfs.a" \
-l"lib/nortos_msp432p4x1xi.aem4f" \
-l"ti/devices/msp432p4xx/driverlib/ccs/msp432p4xx_driverlib.lib" \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
pwmled2_MSP_EXP432P4111_nortos_ccs.out \

EXE_OUTPUTS__QUOTED += \
"pwmled2_MSP_EXP432P4111_nortos_ccs.out" \

BIN_OUTPUTS += \
pwmled2_MSP_EXP432P4111_nortos_ccs.hex \

BIN_OUTPUTS__QUOTED += \
"pwmled2_MSP_EXP432P4111_nortos_ccs.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "pwmled2_MSP_EXP432P4111_nortos_ccs.out"

# Tool invocations
pwmled2_MSP_EXP432P4111_nortos_ccs.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --advice:power=none -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on -z -m"pwmled2_MSP_EXP432P4111_nortos_ccs.map" -i"C:/ti/simplelink_msp432p4_sdk_3_40_00_05/source" -i"C:/ti/simplelink_msp432p4_sdk_3_40_00_05/kernel/nortos" -i"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/lib" --diag_suppress=10063 --diag_wrap=off --display_error_number --warn_sections --xml_link_info="pwmled2_MSP_EXP432P4111_nortos_ccs_linkInfo.xml" --entry_point=resetISR --rom_model -o "pwmled2_MSP_EXP432P4111_nortos_ccs.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

pwmled2_MSP_EXP432P4111_nortos_ccs.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: Arm Hex Utility'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armhex" --diag_wrap=off -o "pwmled2_MSP_EXP432P4111_nortos_ccs.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main_nortos.obj" "pwmled2.obj" "syscfg\ti_drivers_config.obj" 
	-$(RM) "main_nortos.d" "pwmled2.d" "syscfg\ti_drivers_config.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

