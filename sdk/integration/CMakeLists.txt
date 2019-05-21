#-----------------------------------------------------------------------------
# Integration libraries
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

# define subprojects
SET (subprojects
     nrfx)

#-----------------------------------------------------------------------------
# Build configuration
#-----------------------------------------------------------------------------

# build all projects
FOREACH (project ${subprojects})
  ADD_SUBDIRECTORY (${project} ${project})
ENDFOREACH ()
