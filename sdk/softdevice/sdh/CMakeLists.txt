#-----------------------------------------------------------------------------
# SoftDevice support
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

IF (SOFTDEVICE)

  build_component_from (
    nrf_sdh.c
    nrf_sdh_ble.c
    nrf_sdh_soc.c
  )
  SET_SOURCE_FILES_PROPERTIES (nrf_sdh.c
                               PROPERTIES COMPILE_FLAGS
                                  "-Wno-unreachable-code")

ENDIF ()