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
 *  ============================= Display =============================
 */

#include <ti/display/Display.h>
#include <ti/display/DisplayUart.h>
#include <ti/display/DisplaySharp.h>

#define Display_UARTBUFFERSIZE 1024
static char displayUARTBuffer[Display_UARTBUFFERSIZE];

#define Display_LCDSIZE 128
static uint_least8_t displayLCDBuffer[Display_LCDSIZE * Display_LCDSIZE / 8];

DisplayUart_Object displayUartObject;
DisplaySharp_Object displayLcdObject;

const DisplayUart_HWAttrs displayUartHWAttrs = {
    .uartIdx      = CONFIG_UART_0,
    .baudRate     = 115200,
    .mutexTimeout = (unsigned int)(-1),
    .strBuf       = displayUARTBuffer,
    .strBufLen    = Display_UARTBUFFERSIZE
};

const DisplaySharp_HWAttrsV1 displayLcdHWattrs = {
    .spiIndex    = CONFIG_SPI_0,
    .csPin       = CONFIG_GPIO_2,
    .powerPin    = CONFIG_GPIO_1,
    .enablePin   = CONFIG_GPIO_0,
    .pixelWidth  = Display_LCDSIZE,
    .pixelHeight = Display_LCDSIZE,
    .displayBuf  = displayLCDBuffer,
};

const Display_Config Display_config[] = {
    /* CONFIG_Display_0 */
    /* XDS110 UART */
    {
        .fxnTablePtr = &DisplayUartAnsi_fxnTable,
        .object      = &displayUartObject,
        .hwAttrs     = &displayUartHWAttrs
    },
    /* CONFIG_Display_1 */
    /* Sharp 128x128 LCD Display */
    {
        .fxnTablePtr = &DisplaySharp_fxnTable,
        .object      = &displayLcdObject,
        .hwAttrs     = &displayLcdHWattrs
    },
};

const uint_least8_t Display_count = 2;


/*
 *  =============================== DMA ===============================
 */

#include <ti/drivers/dma/UDMAMSP432.h>
#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/rom.h>
#include <ti/devices/msp432p4xx/driverlib/rom_map.h>
#include <ti/devices/msp432p4xx/driverlib/dma.h>

/* Ensure DMA control table is aligned as required by the uDMA Hardware */
static DMA_ControlTable dmaControlTable[16] __attribute__ ((aligned (256)));

/* This is the handler for the uDMA error interrupt. */
static void dmaErrorFxn(uintptr_t arg)
{
    int status = MAP_DMA_getErrorStatus();
    MAP_DMA_clearErrorStatus();

    /* Suppress unused variable warning */
    (void)status;

    while (1);
}

UDMAMSP432_Object udmaMSP432Object;

const UDMAMSP432_HWAttrs udmaMSP432HWAttrs = {
    .controlBaseAddr = (void *)dmaControlTable,
    .dmaErrorFxn     = (UDMAMSP432_ErrorFxn)dmaErrorFxn,
    .intNum          = INT_DMA_ERR,
    .intPriority     = (~0)
};

const UDMAMSP432_Config UDMAMSP432_config = {
    .object  = &udmaMSP432Object,
    .hwAttrs = &udmaMSP432HWAttrs
};


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
    /* CONFIG_GPIO_0 : Sharp128 LCD Enable */
    GPIOMSP432_P4_1 | GPIO_DO_NOT_CONFIG,
    /* CONFIG_GPIO_1 : Sharp128 LCD Power */
    GPIOMSP432_P6_0 | GPIO_DO_NOT_CONFIG,
    /* CONFIG_GPIO_2 : Sharp128 LCD SPI Slave Select */
    GPIOMSP432_P4_3 | GPIO_DO_NOT_CONFIG,
    /* CONFIG_GPIO_LED_0 : LaunchPad LED 1 Red */
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
    /* CONFIG_GPIO_0 : Sharp128 LCD Enable */
    NULL,
    /* CONFIG_GPIO_1 : Sharp128 LCD Power */
    NULL,
    /* CONFIG_GPIO_2 : Sharp128 LCD SPI Slave Select */
    NULL,
    /* CONFIG_GPIO_LED_0 : LaunchPad LED 1 Red */
    NULL,
};

/*
 *  ======== GPIOMSP432_config ========
 */
const GPIOMSP432_Config GPIOMSP432_config = {
    .pinConfigs = (GPIO_PinConfig *)gpioPinConfigs,
    .callbacks = (GPIO_CallbackFxn *)gpioCallbackFunctions,
    .numberOfPinConfigs = 4,
    .numberOfCallbacks = 4,
    .intPriority = (~0)
};


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
 *  =============================== SPI ===============================
 */

#include <ti/drivers/SPI.h>
#include <ti/drivers/spi/SPIMSP432DMA.h>

#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/dma.h>
#include <ti/devices/msp432p4xx/driverlib/interrupt.h>
#include <ti/devices/msp432p4xx/driverlib/spi.h>

#define CONFIG_SPI_COUNT 1

/*
 *  ======== spiMSP432DMAObjects ========
 */
SPIMSP432DMA_Object spiMSP432DMAObjects[CONFIG_SPI_COUNT];

/*
 *  ======== spiMSP432DMAHWAttrs ========
 */
const SPIMSP432DMA_HWAttrsV1 spiMSP432DMAHWAttrs[CONFIG_SPI_COUNT] = {
    /* CONFIG_SPI_0 */
    /* BOOSTXL-SHARP128 SPI Bus */
    {
        .baseAddr = EUSCI_B0_BASE,
        .bitOrder = EUSCI_B_SPI_MSB_FIRST,
        .clockSource = EUSCI_B_SPI_CLOCKSOURCE_SMCLK,
        .defaultTxBufValue = ~0,
        .intPriority = (~0),
        .dmaIntNum = INT_DMA_INT0,
        .rxDMAChannelIndex = DMA_CH1_EUSCIB0RX0,
        .txDMAChannelIndex = DMA_CH0_EUSCIB0TX0,
        .pinMode = EUSCI_SPI_3PIN,
        .clkPin  = SPIMSP432DMA_P1_5_UCB0CLK,
        .simoPin = SPIMSP432DMA_P1_6_UCB0SIMO,
        .somiPin = SPIMSP432DMA_P1_7_UCB0SOMI,
        .stePin  = SPIMSP432DMA_PIN_NO_CONFIG,
        .minDmaTransferSize = 10,
    },
};

/*
 *  ======== SPI_config ========
 */
const SPI_Config SPI_config[CONFIG_SPI_COUNT] = {
    /* CONFIG_SPI_0 */
    /* BOOSTXL-SHARP128 SPI Bus */
    {
        .fxnTablePtr = &SPIMSP432DMA_fxnTable,
        .object = &spiMSP432DMAObjects[CONFIG_SPI_0],
        .hwAttrs = &spiMSP432DMAHWAttrs[CONFIG_SPI_0]
    },
};

const uint_least8_t SPI_count = CONFIG_SPI_COUNT;


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
    {   /* CONFIG_UART_0 */
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
