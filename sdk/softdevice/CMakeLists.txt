#-----------------------------------------------------------------------------
# nRF52 SoftDevice libraries
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

# define subprojects
SET (subprojects
     nosd
     sdh)

#-----------------------------------------------------------------------------
# Build configuration
#-----------------------------------------------------------------------------

# build all projects
FOREACH (project ${subprojects})
  ADD_SUBDIRECTORY (${project} ${project})
ENDFOREACH ()
