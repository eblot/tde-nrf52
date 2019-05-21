/**
 * NRF5 SDK customisation for nRF52832
 */

#ifndef _APP_CONFIG_H_
#define _APP_CONFIG_H_

// DEBUG
#define DEBUG_NRF                                     1

// SPI
#define SPI_ENABLED                                   1
#define SPI0_ENABLED                                  1
#define SPI0_USE_EASY_DMA                             1
#define SPIM_NRF52_ANOMALY_109_WORKAROUND_ENABLED     1

// TWI
#define TWI_ENABLED                                   1
#define TWI1_ENABLED                                  1
#define TWI1_USE_EASY_DMA                             0

// UART
//  UART configuration is another nRF mess, fasten your seatbelt.
//  we just want to use the only available UART in its current incarnation,
//  namely UARTE. Default config is to enable both current and legacy mode,
//  so we have disable legacy mode, enable uart, and enable easy DMA to get
//  a chance to enable UARTE0 in NRFX. Enjoy...
#define UART_ENABLED                                  1
#define UART0_ENABLED                                 1
#define UART_EASY_DMA_SUPPORT                         1
#define UART_LEGACY_SUPPORT                           0

// Timer
#define TIMER_ENABLED                                 1
#define TIMER1_ENABLED                                1
#define POWER_ENABLED                                 1

// Clock
#define NRFX_CLOCK_ENABLED                            1
#define NRFX_CLOCK_CONFIG_LF_SRC                      NRF_CLOCK_LF_SRC_XTAL
#define NRF_SDH_CLOCK_LF_SRC                          NRF_CLOCK_LF_SRC_XTAL
#define CLOCK_ENABLED                                 1
#ifdef HAVE_LEGACY
# define NRF_CLOCK_ENABLED                            1
#endif // HAVE_LEGACY

// ADC
#define SAADC_ENABLED                                 1

// PPI
#define PPI_ENABLED                                   1

// GPIO
#define GPIOTE_ENABLED                                1

// PWM
#define PWM_ENABLED                                   1
#define PWM0_ENABLED                                  1

// Watchdog
#define WDT_ENABLED                                   1

// RTC
#define RTC_ENABLED                                   1
#define RTC2_ENABLED                                  1

//
#define HARDFAULT_HANDLER_ENABLED                     1

#if defined(LAIRD_BL652)
   // LAIRD module uses RC oscillator
  #define NRF_SDH_CLOCK_LF_SRC NRF_CLOCK_LF_SRC_RC
  #define NRF_SDH_CLOCK_LF_RC_CTIV 16
  #define NRF_SDH_CLOCK_LF_RC_TEMP_CTIV 2
#else
   // PCA10040 uses a cristal
  #define NRF_SDH_CLOCK_LF_SRC NRF_CLOCK_LF_SRC_XTAL
#endif

// Application timer
#define APP_TIMER_ENABLED                             1
#define APP_TIMER_CONFIG_USE_SCHEDULER                1
#define APP_TIMER_KEEPS_RTC_ACTIVE                    1
// the "frequency" here is the prescaler value freq   32768/(prescaler+1
// tick every 0.5 ms -> 2048 Hz   32768/2048 - 1   15
#define APP_TIMER_CONFIG_RTC_FREQUENCY                15

// Application scheduler
#define APP_SCHEDULER_ENABLED                         1

// SoftDevice 132
#if defined (S132)
   #define NRF_SDH_ENABLED                            1
   #define NRF_SDH_SOC_ENABLED                        1
   #define NRF_SDH_BLE_ENABLED                        1
   #define NRF_SECTION_ITER_ENABLED                   1
   #define NRF_BLE_CONN_PARAMS_ENABLED                1
   #define NRF_SDH_DISPATCH_MODEL                 NRF_SDH_DISPATCH_MODEL_APPSH
   #define NRF_SDH_BLE_PERIPHERAL_LINK_COUNT          1
   #define NRF_SDH_BLE_CENTRAL_LINK_COUNT             1
   #define BLE_STACK_SUPPORT_REQD                     1
   #define BLE_GATT_DB_MAX_CHARS                     20

   #define BLE_ADVERTISING_ENABLED                    1
   #define BLE_DIS_ENABLED                            1
   #define BLE_DB_DISCOVERY_ENABLED                   1
   #define NRF_BLE_GATT_ENABLED                       1
#endif

#endif // _APP_CONFIG_H_
