#-----------------------------------------------------------------------------
# Utility library support for nRF52
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

build_component_from (
  app_error.c
  app_error_weak.c
  app_error_handler_gcc.c
  app_util_platform.c
  nrf_assert.c
  sdk_mapped_flags.c
)
