/**
 * Fake nrf_log.h
 */

#ifndef _NRF_LOG_H_
#define _NRF_LOG_H_

#define NRF_LOG_ERROR_STRING_GET(code) ""
#define NRF_LOG_ERROR(...)
#define NRF_LOG_WARNING(...)
#define NRF_LOG_INFO(...)
#define NRF_LOG_DEBUG(...)
#define NRF_LOG_RAW_INFO(...)
#define NRF_LOG_HEXDUMP_ERROR(p_data, len)
#define NRF_LOG_HEXDUMP_WARNING(p_data, len)
#define NRF_LOG_HEXDUMP_INFO(p_data, len)
#define NRF_LOG_HEXDUMP_DEBUG(p_data, len)
#define NRF_LOG_RAW_HEXDUMP_INFO(p_data, len)
#define NRF_LOG_MODULE_REGISTER()

#endif // _NRF_LOG_H_

