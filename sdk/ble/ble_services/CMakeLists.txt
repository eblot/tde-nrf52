#-----------------------------------------------------------------------------
# nRF52 BLE service libraries
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

# define subprojects
SET (subprojects
     ble_dis)

#-----------------------------------------------------------------------------
# Build configuration
#-----------------------------------------------------------------------------

# build all projects
FOREACH (project ${subprojects})
  ADD_SUBDIRECTORY (${project} ${project})
ENDFOREACH ()
