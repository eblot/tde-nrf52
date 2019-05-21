#-----------------------------------------------------------------------------
# SoftDevice-less support
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

IF (NOT SOFTDEVICE)

  build_component_from (
    nrf_nvic.c
    nrf_soc.c
  )

ENDIF ()