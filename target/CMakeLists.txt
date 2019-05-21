#-----------------------------------------------------------------------------
# nRF52 targets
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

# define subprojects
SET (subprojects nrf52832)
IF ( HAVE_NRF52840 )
  LIST (APPEND subprojects nrf52840)
ENDIF()

#-----------------------------------------------------------------------------
# Build configuration
#-----------------------------------------------------------------------------

# build all projects
FOREACH (project ${subprojects})
  ADD_SUBDIRECTORY (${project} ${project})
ENDFOREACH ()
