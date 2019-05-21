#-----------------------------------------------------------------------------
# nRF52 BLE libraries
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

# define subprojects
SET (subprojects
     ble_advertising
     ble_common
     ble_db_discovery
     ble_services
     nrf_ble_gatt)

#-----------------------------------------------------------------------------
# Build configuration
#-----------------------------------------------------------------------------

IF (SOFTDEVICE)

  INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/sdk/softdevice/sdh)

  # build all projects
  FOREACH (project ${subprojects})
    ADD_SUBDIRECTORY (${project} ${project})
  ENDFOREACH ()

ENDIF ()