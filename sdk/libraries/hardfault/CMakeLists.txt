#-----------------------------------------------------------------------------
# Hardfault handler support for nRF52
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

build_component_from (
  hardfault_implementation.c
  nrf52/handler/hardfault_handler_gcc.c
)
