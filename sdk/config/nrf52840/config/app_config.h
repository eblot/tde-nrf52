/**
 * NRF5 SDK customisation for nRF52840
 */

#ifndef _APP_CONFIG_H_
#define _APP_CONFIG_H_

// DEBUG
#define DEBUG_NRF                                     1

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

// Clock
#define NRFX_CLOCK_ENABLED                            1
#define NRFX_CLOCK_CONFIG_LF_SRC                      NRF_CLOCK_LF_SRC_XTAL
#define NRF_SDH_CLOCK_LF_SRC                          NRF_CLOCK_LF_SRC_XTAL
#define CLOCK_ENABLED                                 1
#ifdef HAVE_LEGACY
# define NRF_CLOCK_ENABLED                            1
#endif // HAVE_LEGACY

// POWER
#define NRFX_POWER_ENABLED                            1
#define POWER_ENABLED                                 1

#define APP_USBD_CONFIG_SELF_POWERED                  0

// GPIO
#define GPIOTE_ENABLED                                1

// PWM
#define PWM_ENABLED                                   1
#define PWM0_ENABLED                                  1

// Application timer
#define APP_TIMER_ENABLED                             1
#define APP_TIMER_CONFIG_USE_SCHEDULER                1
#define APP_TIMER_KEEPS_RTC_ACTIVE                    1
// the "frequency" here is the prescaler value freq   32768/(prescaler+1
// tick every 0.5 ms -> 2048 Hz   32768/2048 - 1   15
#define APP_TIMER_CONFIG_RTC_FREQUENCY                15

// Application scheduler
#define APP_SCHEDULER_ENABLED                         1

// USB
#ifdef HAVE_USB
 #define NRFX_USBD_ENABLED                            1
// #define USBD_ENABLED                                 1
 #define APP_USBD_CONFIG_EVENT_QUEUE_ENABLE           1
 #define APP_USBD_ENABLED                             1
 #define APP_USBD_CDC_ACM_ENABLED                     1
 #define APP_USBD_STRINGS_MANUFACTURER    APP_USBD_STRING_DESC("Iroazh")
 #define APP_USBD_STRINGS_PRODUCT         APP_USBD_STRING_DESC("nRF52840 USB")
 #define APP_USBD_STRING_SERIAL           APP_USBD_STRING_DESC("112")
 #define APP_USBD_STRINGS_CONFIGURATION   APP_USBD_STRING_DESC("USB CDC ACM")
 #define APP_USBD_VID                            0x1915
 #define APP_USBD_PID                            0xE112
#endif // HAVE_USB

// SoftDevice 140
#if defined (S140)
   #define NRF_SDH_ENABLED                            1
   #define NRF_SDH_SOC_ENABLED                        1
   #define NRF_SDH_BLE_ENABLED                        1
   #define NRF_SDH_BLE_VS_UUID_COUNT                  1
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
