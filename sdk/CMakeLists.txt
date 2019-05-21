#-----------------------------------------------------------------------------
# nRF52 SDK
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

# define subprojects
SET (subprojects
     ble
     drivers
     integration
     libraries
     nrfx
     softdevice)

#-----------------------------------------------------------------------------
# Build configuration
#-----------------------------------------------------------------------------

nrf52_no_warnings ()

IF (NOT DEFINED NRF52_SOC)
  MESSAGE (FATAL_ERROR "NRF52_SOC should be defined")
ELSE ()
  IF ("${NRF52_SOC}" STREQUAL "52832")
    SET (NRF52_SUFFIX "")
  ELSEIF ("${NRF52_SOC}" STREQUAL "52840")
    SET (NRF52_SUFFIX "840")
  ELSE ()
    MESSAGE (FATAL_ERROR "Unsupported SoC: ${NRF52_SOC}")
  ENDIF ()
ENDIF ()

SET (LIBRARY_VARIANT ${NRF52_SOC})

# build all projects
FOREACH (project ${subprojects})
  ADD_SUBDIRECTORY (${project} ${project})
ENDFOREACH ()
