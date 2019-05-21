#-----------------------------------------------------------------------------
# MDK support for nRF52
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

IF (NOT DEFINED NRF52_SUFFIX)
  MESSAGE (FATAL_ERROR "Undefined SoC suffix")
ENDIF ()

build_component_from (
  gcc_startup_nrf52${NRF52_SUFFIX}.S
  system_nrf52${NRF52_SUFFIX}.c
)
