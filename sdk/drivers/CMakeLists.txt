#-----------------------------------------------------------------------------
# nRF52 drivers
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

# define subprojects
SET (subprojects
     usbd)

#-----------------------------------------------------------------------------
# Build configuration
#-----------------------------------------------------------------------------

# build all projects
FOREACH (project ${subprojects})
  ADD_SUBDIRECTORY (${project} ${project})
ENDFOREACH ()
