#-----------------------------------------------------------------------------
# nRF52 Applications
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

find_subprojects (SUBPROJECTS)

#-----------------------------------------------------------------------------
# Build configuration
#-----------------------------------------------------------------------------

# build all projects
FOREACH (project ${SUBPROJECTS})
  ADD_SUBDIRECTORY (${project} ${project})
ENDFOREACH ()
