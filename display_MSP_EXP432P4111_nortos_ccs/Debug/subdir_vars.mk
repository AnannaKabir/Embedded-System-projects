################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../MSP_EXP432P4111_NoRTOS.cmd 

SYSCFG_SRCS += \
../display.syscfg 

C_SRCS += \
../display.c \
./syscfg/ti_drivers_config.c \
../main_nortos.c \
../splash_image.c 

GEN_FILES += \
./syscfg/ti_drivers_config.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./display.d \
./syscfg/ti_drivers_config.d \
./main_nortos.d \
./splash_image.d 

OBJS += \
./display.obj \
./syscfg/ti_drivers_config.obj \
./main_nortos.obj \
./splash_image.obj 

GEN_MISC_FILES += \
./syscfg/ti_drivers_config.h \
./syscfg/syscfg_c.rov.xs 

GEN_MISC_DIRS__QUOTED += \
"syscfg\" 

OBJS__QUOTED += \
"display.obj" \
"syscfg\ti_drivers_config.obj" \
"main_nortos.obj" \
"splash_image.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\ti_drivers_config.h" \
"syscfg\syscfg_c.rov.xs" 

C_DEPS__QUOTED += \
"display.d" \
"syscfg\ti_drivers_config.d" \
"main_nortos.d" \
"splash_image.d" 

GEN_FILES__QUOTED += \
"syscfg\ti_drivers_config.c" 

C_SRCS__QUOTED += \
"../display.c" \
"./syscfg/ti_drivers_config.c" \
"../main_nortos.c" \
"../splash_image.c" 

SYSCFG_SRCS__QUOTED += \
"../display.syscfg" 


