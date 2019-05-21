#------------------------------------------------------------------------------
# Components for nRF52832 and BLE softdevice
#
# @file CMakeLists.txt
#------------------------------------------------------------------------------

use_nrf52832()
use_softdevice(S132)

ADD_SUBDIRECTORY (${CMAKE_SOURCE_DIR}/sdk sdk)
