#-----------------------------------------------------------------------------
# USB libraries for nRF52
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

IF ( HAVE_USB )
  build_component_from (
    app_usbd.c
    app_usbd_core.c
    app_usbd_serial_num.c
    app_usbd_string_desc.c
    class/cdc/acm/app_usbd_cdc_acm.c
    class/nrf_dfu_trigger/app_usbd_nrf_dfu_trigger.c
  )
  SET_SOURCE_FILES_PROPERTIES (app_usbd_string_desc.c
                               PROPERTIES COMPILE_FLAGS
                               "-Wno-unreachable-code")
ENDIF ()
