#-----------------------------------------------------------------------------
# Legacy layer for nRF52
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

IF ( HAVE_LEGACY )

  build_component_from (
    nrf_drv_clock.c
    nrf_drv_power.c
  )

ENDIF ()