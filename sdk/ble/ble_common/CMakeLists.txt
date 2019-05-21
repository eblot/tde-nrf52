#-----------------------------------------------------------------------------
# BLE common library for nRF52
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

build_component_from (
  ble_advdata.c
  ble_conn_params.c
  ble_conn_state.c
  ble_srv_common.c
)
