################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../MSP_EXP432P4111_TIRTOS.cmd 

SYSCFG_SRCS += \
../outOfBox_msp432p4111.syscfg 

C_SRCS += \
../callbacks.c \
../lcd_thread.c \
../led_thread.c \
../main_tirtos.c \
./syscfg/ti_drivers_config.c \
../temperature_thread.c \
../uart_thread.c 

GEN_FILES += \
./syscfg/ti_drivers_config.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./callbacks.d \
./lcd_thread.d \
./led_thread.d \
./main_tirtos.d \
./syscfg/ti_drivers_config.d \
./temperature_thread.d \
./uart_thread.d 

OBJS += \
./callbacks.obj \
./lcd_thread.obj \
./led_thread.obj \
./main_tirtos.obj \
./syscfg/ti_drivers_config.obj \
./temperature_thread.obj \
./uart_thread.obj 

GEN_MISC_FILES += \
./syscfg/ti_drivers_config.h \
./syscfg/syscfg_c.rov.xs 

GEN_MISC_DIRS__QUOTED += \
"syscfg\" 

OBJS__QUOTED += \
"callbacks.obj" \
"lcd_thread.obj" \
"led_thread.obj" \
"main_tirtos.obj" \
"syscfg\ti_drivers_config.obj" \
"temperature_thread.obj" \
"uart_thread.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\ti_drivers_config.h" \
"syscfg\syscfg_c.rov.xs" 

C_DEPS__QUOTED += \
"callbacks.d" \
"lcd_thread.d" \
"led_thread.d" \
"main_tirtos.d" \
"syscfg\ti_drivers_config.d" \
"temperature_thread.d" \
"uart_thread.d" 

GEN_FILES__QUOTED += \
"syscfg\ti_drivers_config.c" 

C_SRCS__QUOTED += \
"../callbacks.c" \
"../lcd_thread.c" \
"../led_thread.c" \
"../main_tirtos.c" \
"./syscfg/ti_drivers_config.c" \
"../temperature_thread.c" \
"../uart_thread.c" 

SYSCFG_SRCS__QUOTED += \
"../outOfBox_msp432p4111.syscfg" 


