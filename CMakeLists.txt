#------------------------------------------------------------------------------
# Applications based on nRF52
#
# @file CMakeLists.txt
#------------------------------------------------------------------------------

# Import useful macros
CMAKE_MINIMUM_REQUIRED (VERSION 3.5)

PROJECT (nrf52 C ASM)

use_target ()
use_default_xcc_warnings ()
use_default_xcc_settings ()
use_default_xas_settings ()

#------------------------------------------------------------------------------
# CMake definitions
#------------------------------------------------------------------------------

# To build nRF52840 projects, HAVE_NRF52840 should be defined to 1
IF (NOT DEFINED HAVE_NRF52840)
  SET (HAVE_NRF52840 0)
ENDIF ()

# Common definitions for all targets
ADD_DEFINITIONS (-DFLOAT_ABI_HARD)
ADD_DEFINITIONS (-DSWI_DISABLE0)
ADD_DEFINITIONS (-D__STARTUP_CLEAR_BSS=1)
ADD_DEFINITIONS (-DUSE_APP_CONFIG=1)
ADD_DEFINITIONS (-DFORCE_RELEASE_TRACES=1)

find_subprojects (SUBPROJECTS sdk)

#------------------------------------------------------------------------------
# Disable many warnings while building Nordic Semi code
#------------------------------------------------------------------------------
MACRO (nrf52_no_warnings)
  ADD_DEFINITIONS (-Wno-cast-qual)
  ADD_DEFINITIONS (-Wno-documentation)
  ADD_DEFINITIONS (-Wno-conversion)
  ADD_DEFINITIONS (-Wno-missing-noreturn)
  ADD_DEFINITIONS (-Wno-documentation-unknown-command)
  ADD_DEFINITIONS (-Wno-padded)
  ADD_DEFINITIONS (-Wno-cast-align)
  ADD_DEFINITIONS (-Wno-bad-function-cast)
  ADD_DEFINITIONS (-Wno-expansion-to-defined)
  ADD_DEFINITIONS (-Wno-unused-function)
  ADD_DEFINITIONS (-Wno-unused-parameter)
  ADD_DEFINITIONS (-Wno-unused-variable)
  ADD_DEFINITIONS (-Wno-missing-prototypes)
  ADD_DEFINITIONS (-Wno-missing-field-initializers)
  ADD_DEFINITIONS (-Wno-switch-enum)
  ADD_DEFINITIONS (-Wno-unused-macros)
  ADD_DEFINITIONS (-Wno-expansion-to-defined)
  # TEMPORARY FOR PORTING TO SDK15 only
  ADD_DEFINITIONS (-Wno-unused-parameter)
  ADD_DEFINITIONS (-Wno-used-but-marked-unused)
ENDMACRO ()

#------------------------------------------------------------------------------
# Select nRF5 SDK headers
#------------------------------------------------------------------------------
MACRO (use_sdk_headers)
  SET (inc_dirs)
  FOREACH (header ${ARGV})
    assert_directory ("Component" ${CMAKE_SOURCE_DIR}/sdk/${header})
    LIST (APPEND inc_dirs ${CMAKE_SOURCE_DIR}/sdk/${header})
  ENDFOREACH (header)
  INCLUDE_DIRECTORIES (${inc_dirs})
ENDMACRO ()

#------------------------------------------------------------------------------
# Select nrf52832 target
#------------------------------------------------------------------------------
MACRO (use_nrf52832)
# SET (LAIRD_BL652 1)
  SET (NRF52_SOC "52832")
  ADD_DEFINITIONS (-DNRF52832_XXAA=1)
  ADD_DEFINITIONS (-DNRF52_PAN_74)
  ADD_DEFINITIONS (-DCONFIG_NFCT_PINS_AS_GPIOS=1)
  ADD_DEFINITIONS (-DCONFIG_GPIO_AS_PINRESET=1)
  SET (HAVE_LEGACY 1) # because clock stack is not ported to NRFX...
  ADD_DEFINITIONS(-DHAVE_LEGACY)
  use_sdk_headers (
    integration/nrfx/legacy
  )
  LIST (APPEND NRF52_SYSLIBS legacy)
  INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/sdk/config/nrf52832/config)
ENDMACRO()

#------------------------------------------------------------------------------
# Select nrf52840 target
#------------------------------------------------------------------------------
MACRO (use_nrf52840)
  SET (NRF52_SOC "52840")
  ADD_DEFINITIONS (-DNRF52840_XXAA=1)
  ADD_DEFINITIONS (-DNRF52_PAN_74)
  ADD_DEFINITIONS (-DCONFIG_NFCT_PINS_AS_GPIOS=1)
  ADD_DEFINITIONS (-DCONFIG_GPIO_AS_PINRESET=1)
  INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/sdk/config/nrf52840/config)
  SET (HAVE_USB 1)
  SET (HAVE_LEGACY 1) # because USB stack is not ported to NRFX...
  ADD_DEFINITIONS(-DHAVE_USB -DHAVE_LEGACY)
  # USB requires the following libraries
  subdirlist (usbdirs ${CMAKE_SOURCE_DIR}/sdk/libraries/app_usbd
              RECURSIVE RELATIVE)
  FOREACH (usbdir ${usbdirs})
    LIST (APPEND sdkusbdirs libraries/app_usbd/${usbdir})
  ENDFOREACH ()
  use_sdk_headers (
    drivers/usbd
    # NordicSemi has not ported its own food to its USB stack with SDK v15.x!
    integration/nrfx/legacy
    libraries/app_usbd
    libraries/atomic_fifo
    libraries/utf
    ${sdkusbdirs}
  )
  LIST (APPEND NRF52_SYSLIBS app_usbd atomic atomic_fifo legacy usbd)
ENDMACRO()

#------------------------------------------------------------------------------
# Select a SoftDevice
# :sd: softdevice selector, as Sxxx
#------------------------------------------------------------------------------
MACRO (use_softdevice sd)
  STRING (REGEX MATCH "S1[0-9]+" NOSD ${sd})
  IF ( NOT NOSD )
    INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/sdk/softdevice/nosd)
  ELSE ()
    SET (SOFTDEVICE ${sd})
    STRING (TOLOWER ${SOFTDEVICE} softdev)
    SET (NRF52_SD softdevice/${softdev})
    ADD_DEFINITIONS (-D${SOFTDEVICE} -DSOFTDEVICE_PRESENT=1)
    ADD_DEFINITIONS (-DNRF_SD_BLE_API_VERSION=6)
    INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/sdk/softdevice/sdh)
    INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/sdk/${NRF52_SD}/include)
    use_sdk_headers (
      ble/ble_advertising
      ble/ble_common
      ble/ble_db_discovery
      ble/ble_services/ble_dis
      ble/nrf_ble_gatt
      libraries/atomic
      libraries/atomic_flags
      libraries/section_vars
    )
    LIST (APPEND NRF52_SYSLIBS
          ble_advertising ble_common nrf_ble_gatt sdh section_vars)
  ENDIF ()
ENDMACRO ()

#------------------------------------------------------------------------------
# Build configuration
#------------------------------------------------------------------------------

# It is nearly impossible to create a clean build structure with NRF SDK,
# as everything depends on everything else, in every imaginable direction.
# Sometime public headers are defined in an include subdirectory, sometimes
# they have just be thrown among other stuff. Low level stuff can even refer
# to so-called "libraries". Other stable component rely on "experimental"
# stuff. We cannot save private Ryan here, so include da mess, and try to
# forget about this bad piece of engineering.
use_sdk_headers(
  cmsis/include
  integration/nrfx
  libraries/app_scheduler
  libraries/app_timer
  libraries/delay
  libraries/util
  libraries/strerror
  nrfx
  nrfx/drivers/include
  nrfx/hal
  nrfx/mdk
)

SET (NRF52_SYSLIBS)
LIST (APPEND NRF52_SYSLIBS app_scheduler app_timer util drivers mdk strerror)

# build all projects
FOREACH (project ${SUBPROJECTS})
  ADD_SUBDIRECTORY (${project} ${project})
ENDFOREACH ()
