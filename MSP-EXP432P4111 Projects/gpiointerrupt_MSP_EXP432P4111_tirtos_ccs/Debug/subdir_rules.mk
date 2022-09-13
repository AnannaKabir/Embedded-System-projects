################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/appna/workspace_v12/gpiointerrupt_MSP_EXP432P4111_tirtos_ccs" --include_path="C:/Users/appna/workspace_v12/gpiointerrupt_MSP_EXP432P4111_tirtos_ccs/Debug" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_00_05/source" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_00_05/source/third_party/CMSIS/Include" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_00_05/source/ti/posix/ccs" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --advice:power=none -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/appna/workspace_v12/gpiointerrupt_MSP_EXP432P4111_tirtos_ccs/Debug/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1507290415: ../gpiointerrupt.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs1200/ccs/utils/sysconfig_1.13.0/sysconfig_cli.bat" -s "C:/ti/simplelink_msp432p4_sdk_3_40_00_05/.metadata/product.json" --script "C:/Users/appna/workspace_v12/gpiointerrupt_MSP_EXP432P4111_tirtos_ccs/gpiointerrupt.syscfg" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_config.c: build-1507290415 ../gpiointerrupt.syscfg
syscfg/ti_drivers_config.h: build-1507290415
syscfg/syscfg_c.rov.xs: build-1507290415
syscfg/: build-1507290415

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/appna/workspace_v12/gpiointerrupt_MSP_EXP432P4111_tirtos_ccs" --include_path="C:/Users/appna/workspace_v12/gpiointerrupt_MSP_EXP432P4111_tirtos_ccs/Debug" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_00_05/source" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_00_05/source/third_party/CMSIS/Include" --include_path="C:/ti/simplelink_msp432p4_sdk_3_40_00_05/source/ti/posix/ccs" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --advice:power=none -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/appna/workspace_v12/gpiointerrupt_MSP_EXP432P4111_tirtos_ccs/Debug/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


