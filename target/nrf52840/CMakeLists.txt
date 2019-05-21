#------------------------------------------------------------------------------
# Components for nRF52840 and BLE softdevice
#
# @file CMakeLists.txt
#------------------------------------------------------------------------------

use_nrf52840()
use_softdevice(S140)

ADD_SUBDIRECTORY (${CMAKE_SOURCE_DIR}/sdk sdk)
