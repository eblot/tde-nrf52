/**
 * Fake nrf_log_ctrl.h
 */

#ifndef _NRF_LOG_CTRL_H_
#define _NRF_LOG_CTRL_H_

typedef enum
{
    NRF_LOG_SEVERITY_NONE,
    NRF_LOG_SEVERITY_ERROR,
    NRF_LOG_SEVERITY_WARNING,
    NRF_LOG_SEVERITY_INFO,
    NRF_LOG_SEVERITY_DEBUG,
} nrf_log_severity_t;

#define NRF_LOG_INIT(timestamp_func)
#define NRF_LOG_PROCESS()
#define NRF_LOG_FLUSH()
#define NRF_LOG_FINAL_FLUSH()

#endif // _NRF_LOG_CTRL_H_
