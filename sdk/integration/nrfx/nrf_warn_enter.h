/**
 * Special header files to disable warnings that cannot be fixed as they come
 * from Nordic source code.
 * This file works in pair with nrf_warn_leave.h
 */

#ifndef _NRF_WARNINGS_
# define _NRF_WARNINGS_ 1
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wcast-qual"
# pragma clang diagnostic ignored "-Wdocumentation"
# pragma clang diagnostic ignored "-Wconversion"
# pragma clang diagnostic ignored "-Wmissing-noreturn"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# pragma clang diagnostic ignored "-Wpadded"
# pragma clang diagnostic ignored "-Wcast-align"
# pragma clang diagnostic ignored "-Wbad-function-cast"
# pragma clang diagnostic ignored "-Wexpansion-to-defined"
# pragma clang diagnostic ignored "-Wunused-parameter"
#else // ! _NRF_WARNINGS_
# error "Invalid inclusion"
#endif // _NRF_WARNINGS_
