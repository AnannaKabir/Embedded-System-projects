/*
 *  ======== ti_drivers_config.h ========
 *  Configured TI-Drivers module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSP_EXP432P4111
 *  by the SysConfig tool.
 */
#ifndef ti_drivers_config_h
#define ti_drivers_config_h

#define CONFIG_SYSCONFIG_PREVIEW

#define CONFIG_MSP_EXP432P4111

#ifndef DeviceFamily_MSP432P4x1xI
#define DeviceFamily_MSP432P4x1xI
#endif

#include <ti/devices/DeviceFamily.h>

#include <stdint.h>

/* support C++ sources */
#ifdef __cplusplus
extern "C" {
#endif


/*
 *  ======== ADC ========
 */

/* P5.5 */
#define CONFIG_ADC0                 0


/*
 *  ======== GPIO ========
 */

/* P1.1, LaunchPad Button S1 (Left) */
#define CONFIG_GPIO_BUTTON0         0
/* P1.4, LaunchPad Button S2 (Right) */
#define CONFIG_GPIO_BUTTON1         1
/* P1.0, LaunchPad LED 1 Red */
#define CONFIG_GPIO_LED0            2

/* LEDs are active high */
#define CONFIG_GPIO_LED_ON  (1)
#define CONFIG_GPIO_LED_OFF (0)

#define CONFIG_LED_ON  (CONFIG_GPIO_LED_ON)
#define CONFIG_LED_OFF (CONFIG_GPIO_LED_OFF)


/*
 *  ======== PWM ========
 */

/* P2.0, LaunchPad LED 2 Red */
#define CONFIG_PWM0                 0
/* P2.1, LaunchPad LED 2 Green */
#define CONFIG_PWM1                 1
/* P2.2, LaunchPad LED 2 Blue */
#define CONFIG_PWM2                 2


/*
 *  ======== Timer ========
 */

#define CONFIG_TIMER0               0
#define CONFIG_TIMER1               1
#define CONFIG_TIMER3               2

/*
 *  ======== UART ========
 */

/*
 *  TX: P1.3
 *  RX: P1.2
 *  XDS110 UART
 */
#define CONFIG_UART0                0


/*
 *  ======== Board_init ========
 *  Perform all required TI-Drivers initialization
 *
 *  This function should be called once at a point before any use of
 *  TI-Drivers.
 */
extern void Board_init(void);

/*
 *  ======== Board_initGeneral ========
 *  (deprecated)
 *
 *  Board_initGeneral() is defined purely for backward compatibility.
 *
 *  All new code should use Board_init() to do any required TI-Drivers
 *  initialization _and_ use <Driver>_init() for only where specific drivers
 *  are explicitly referenced by the application.  <Driver>_init() functions
 *  are idempotent.
 */
#define Board_initGeneral Board_init

#ifdef __cplusplus
}
#endif

#endif /* include guard */
