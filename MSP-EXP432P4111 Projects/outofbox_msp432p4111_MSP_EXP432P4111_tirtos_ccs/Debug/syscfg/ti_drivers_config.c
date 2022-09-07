/*
 *  ======== ti_drivers_config.c ========
 *  Configured TI-Drivers module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSP_EXP432P4111
 *  by the SysConfig tool.
 */

#include <stddef.h>

#ifndef DeviceFamily_MSP432P4x1xI
#define DeviceFamily_MSP432P4x1xI
#endif

#include <ti/devices/DeviceFamily.h>

#include "ti_drivers_config.h"

/*
 *  =============================== ADC ===============================
 */

#include <ti/drivers/ADC.h>
#include <ti/drivers/adc/ADCMSP432.h>

#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/adc14.h>
#include <ti/devices/msp432p4xx/driverlib/ref_a.h>

#define CONFIG_ADC_COUNT 1

/*
 *  ======== adcMSP432Objects ========
 */
ADCMSP432_Object adcMSP432Objects[CONFIG_ADC_COUNT];

/*
 *  ======== adcMSP432HWAttrs ========
 */
const ADCMSP432_HWAttrsV1 adcMSP432HWAttrs[CONFIG_ADC_COUNT] = {
    /* CONFIG_ADC0 */
    {
        .adcPin = ADCMSP432_P5_5_A0,
        .refVoltage = ADCMSP432_REF_VOLTAGE_VDD,
        .resolution = ADC_14BIT,
        .refExtValue = 3300000
    },
};

/*
 *  ======== ADC_config ========
 */
const ADC_Config ADC_config[CONFIG_ADC_COUNT] = {
    /* CONFIG_ADC0 */
    {
        .fxnTablePtr = &ADCMSP432_fxnTable,
        .object = &adcMSP432Objects[CONFIG_ADC0],
        .hwAttrs = &adcMSP432HWAttrs[CONFIG_ADC0]
    },
};

const uint_least8_t ADC_count = CONFIG_ADC_COUNT;


/*
 *  =============================== GPIO ===============================
 */

#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOMSP432.h>

/*
 *  ======== gpioPinConfigs ========
 *  Array of Pin configurations
 */
GPIO_PinConfig gpioPinConfigs[] = {
    /* CONFIG_GPIO_BUTTON0 : LaunchPad Button S1 (Left) */
    GPIOMSP432_P1_1 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING,
    /* CONFIG_GPIO_BUTTON1 : LaunchPad Button S2 (Right) */
    GPIOMSP432_P1_4 | GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING,
    /* CONFIG_GPIO_LED0 : LaunchPad LED 1 Red */
    GPIOMSP432_P1_0 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
};

/*
 *  ======== gpioCallbackFunctions ========
 *  Array of callback function pointers
 *
 *  NOTE: Unused callback entries can be omitted from the callbacks array to
 *  reduce memory usage by enabling callback table optimization
 *  (GPIO.optimizeCallbackTableSize = true)
 */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    /* CONFIG_GPIO_BUTTON0 : LaunchPad Button S1 (Left) */
    NULL,
    /* CONFIG_GPIO_BUTTON1 : LaunchPad Button S2 (Right) */
    NULL,
    /* CONFIG_GPIO_LED0 : LaunchPad LED 1 Red */
    NULL,
};

/*
 *  ======== GPIOMSP432_config ========
 */
const GPIOMSP432_Config GPIOMSP432_config = {
    .pinConfigs = (GPIO_PinConfig *)gpioPinConfigs,
    .callbacks = (GPIO_CallbackFxn *)gpioCallbackFunctions,
    .numberOfPinConfigs = 3,
    .numberOfCallbacks = 3,
    .intPriority = (~0)
};


/*
 *  =============================== PWM ===============================
 */

#include <ti/drivers/PWM.h>
#include <ti/drivers/pwm/PWMTimerMSP432.h>

/* include MSP432 driverlib definitions */
#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/timer_a.h>

#define CONFIG_PWM_COUNT 3

/*
 *  ======== pwmMSP432Objects ========
 */
PWMTimerMSP432_Object pwmTimerMSP432Objects[CONFIG_PWM_COUNT];

/*
 *  ======== pwmMSP432HWAttrs ========
 */
const PWMTimerMSP432_HWAttrsV2 pwmTimerMSP432HWAttrs[CONFIG_PWM_COUNT] = {
    /* CONFIG_PWM0 */
    /* LaunchPad LED 2 Red */
    {
        .clockSource = TIMER_A_CLOCKSOURCE_SMCLK,
        .pwmPin = PWMTimerMSP432_P2_0_TA1CCR3A, /* P2_0 */
    },
    /* CONFIG_PWM1 */
    /* LaunchPad LED 2 Green */
    {
        .clockSource = TIMER_A_CLOCKSOURCE_SMCLK,
        .pwmPin = PWMTimerMSP432_P2_1_TA1CCR2A, /* P2_1 */
    },
    /* CONFIG_PWM2 */
    /* LaunchPad LED 2 Blue */
    {
        .clockSource = TIMER_A_CLOCKSOURCE_SMCLK,
        .pwmPin = PWMTimerMSP432_P2_2_TA1CCR1A, /* P2_2 */
    },
};

/*
 *  ======== PWM_config ========
 */
const PWM_Config PWM_config[CONFIG_PWM_COUNT] = {
    /* CONFIG_PWM0 */
    /* LaunchPad LED 2 Red */
    {
        .fxnTablePtr = &PWMTimerMSP432_fxnTable,
        .object = &pwmTimerMSP432Objects[CONFIG_PWM0],
        .hwAttrs = &pwmTimerMSP432HWAttrs[CONFIG_PWM0]
    },
    /* CONFIG_PWM1 */
    /* LaunchPad LED 2 Green */
    {
        .fxnTablePtr = &PWMTimerMSP432_fxnTable,
        .object = &pwmTimerMSP432Objects[CONFIG_PWM1],
        .hwAttrs = &pwmTimerMSP432HWAttrs[CONFIG_PWM1]
    },
    /* CONFIG_PWM2 */
    /* LaunchPad LED 2 Blue */
    {
        .fxnTablePtr = &PWMTimerMSP432_fxnTable,
        .object = &pwmTimerMSP432Objects[CONFIG_PWM2],
        .hwAttrs = &pwmTimerMSP432HWAttrs[CONFIG_PWM2]
    },
};

const uint_least8_t PWM_count = CONFIG_PWM_COUNT;


/*
 *  =============================== Power ===============================
 */

#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerMSP432.h>
extern void PowerMSP432_initPolicy(void);
extern void PowerMSP432_sleepPolicy(void);

const PowerMSP432_ConfigV1 PowerMSP432_config = {
    .policyInitFxn         = PowerMSP432_initPolicy,
    .policyFxn             = PowerMSP432_sleepPolicy,
    .initialPerfLevel      = 2,
    .enablePolicy          = true,
    .enablePerf            = true,
    .enableParking         = false,
    .resumeShutdownHookFxn = NULL,
    .customPerfLevels      = NULL,
    .numCustom             = 0,
    .useExtendedPerf       = false,
    .configurePinHFXT      = false,
    .HFXTFREQ              = 0,
    .bypassHFXT            = false,
    .configurePinLFXT      = false,
    .bypassLFXT            = false,
    .LFXTDRIVE             = 0,
    .enableInterruptsCS    = false,
    .priorityInterruptsCS  = (~0),
    .isrCS                 = NULL
};


/*
 *  =============================== Timer ===============================
 */

#include <ti/drivers/Timer.h>
#include <ti/drivers/timer/TimerMSP432.h>
#include <ti/devices/msp432p4xx/driverlib/interrupt.h>
#include <ti/devices/msp432p4xx/driverlib/timer_a.h>
#include <ti/devices/msp432p4xx/driverlib/timer32.h>

#define CONFIG_TIMER_COUNT 3

/*
 *  ======== timerMSP432Objects ========
 */
TimerMSP432_Object timerMSP432Objects[CONFIG_TIMER_COUNT];

/*
 *  ======== timerMSP432HWAttrs ========
 */
const TimerMSP432_HWAttrs TimerMSP432HWAttrs[CONFIG_TIMER_COUNT] = {
    /* CONFIG_TIMER0 */
    {
        .timerBaseAddress  = TIMER32_0_BASE,
        .intNum            = INT_T32_INT1,
        .intPriority       = (~0),
    },
    /* CONFIG_TIMER1 */
    {
        .timerBaseAddress  = TIMER32_1_BASE,
        .intNum            = INT_T32_INT2,
        .intPriority       = (~0),
    },
    /* CONFIG_TIMER3 */
    {
        .timerBaseAddress  = TIMER_A3_BASE,
        .intNum            = INT_TA3_0,
        .intPriority       = (~0),
        .clockSource       = TIMER_A_CLOCKSOURCE_ACLK
    },
};

/*
 *  ======== Timer_config ========
 */
const Timer_Config Timer_config[CONFIG_TIMER_COUNT] = {
    /* CONFIG_TIMER0 */
    {
        .fxnTablePtr = &TimerMSP432_Timer32_fxnTable,
        .object      = &timerMSP432Objects[CONFIG_TIMER0],
        .hwAttrs     = &TimerMSP432HWAttrs[CONFIG_TIMER0]
    },
    /* CONFIG_TIMER1 */
    {
        .fxnTablePtr = &TimerMSP432_Timer32_fxnTable,
        .object      = &timerMSP432Objects[CONFIG_TIMER1],
        .hwAttrs     = &TimerMSP432HWAttrs[CONFIG_TIMER1]
    },
    /* CONFIG_TIMER3 */
    {
        .fxnTablePtr = &TimerMSP432_Timer_A_fxnTable,
        .object      = &timerMSP432Objects[CONFIG_TIMER3],
        .hwAttrs     = &TimerMSP432HWAttrs[CONFIG_TIMER3]
    },
};

const uint_least8_t Timer_count = CONFIG_TIMER_COUNT;


/*
 *  =============================== UART ===============================
 */

#include <ti/drivers/UART.h>
#include <ti/drivers/uart/UARTMSP432.h>
#include <ti/devices/msp432p4xx/driverlib/interrupt.h>
#include <ti/devices/msp432p4xx/driverlib/uart.h>

#define CONFIG_UART_COUNT 1

UARTMSP432_Object uartMSP432Objects[CONFIG_UART_COUNT];

static const UARTMSP432_BaudrateConfig uartMSP432Baudrates[] = {
    /* {baudrate, input clock, prescalar, UCBRFx, UCBRSx, oversampling} */
    { 115200, 3000000, 1, 10, 0, 1 },
    { 115200, 6000000, 3, 4, 2, 1 },
    { 115200, 12000000, 6, 8, 32, 1 },
    { 115200, 24000000, 13, 0, 37, 1 },
};

static unsigned char uartMSP432RingBuffer0[32];


static const UARTMSP432_HWAttrsV1 uartMSP432HWAttrs[CONFIG_UART_COUNT] = {
  {
    .baseAddr           = EUSCI_A0_BASE,
    .intNum             = INT_EUSCIA0,
    .intPriority        = (~0),
    .clockSource        = EUSCI_A_UART_CLOCKSOURCE_SMCLK,
    .bitOrder           = EUSCI_A_UART_LSB_FIRST,
    .numBaudrateEntries = sizeof(uartMSP432Baudrates) /
                          sizeof(UARTMSP432_BaudrateConfig),
    .baudrateLUT        = uartMSP432Baudrates,
    .ringBufPtr         = uartMSP432RingBuffer0,
    .ringBufSize        = sizeof(uartMSP432RingBuffer0),
    .rxPin              = UARTMSP432_P1_2_UCA0RXD,
    .txPin              = UARTMSP432_P1_3_UCA0TXD,
    .errorFxn           = NULL
  },
};

const UART_Config UART_config[CONFIG_UART_COUNT] = {
    {   /* CONFIG_UART0 */
        .fxnTablePtr = &UARTMSP432_fxnTable,
        .object      = &uartMSP432Objects[0],
        .hwAttrs     = &uartMSP432HWAttrs[0]
    },
};

const uint_least8_t UART_count = CONFIG_UART_COUNT;


#include <ti/drivers/Board.h>

/*
 *  ======== Board_initHook ========
 *  Perform any board-specific initialization needed at startup.  This
 *  function is declared weak to allow applications to override it if needed.
 */
void __attribute__((weak)) Board_initHook(void)
{
}

/*
 *  ======== Board_init ========
 *  Perform any initialization needed before using any board APIs
 */
void Board_init(void)
{
    /* ==== /ti/drivers/Power initialization ==== */
    Power_init();

    Board_initHook();
}
