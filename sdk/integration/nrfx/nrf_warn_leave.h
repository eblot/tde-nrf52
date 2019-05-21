/**
 * Special header files to disable warnings that cannot be fixed as they come
 * from Nordic source code.
 * This file works in pair with nrf_warn_enter.h
 */

#ifndef _NRF_WARNINGS_
# error "Invalid inclusion"
#else // ! _NRF_WARNINGS_
# undef _NRF_WARNINGS_
# pragma clang diagnostic pop
#endif // _NRF_WARNINGS_
