#-----------------------------------------------------------------------------
# nRF52 SDK libraries
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

# define subprojects
SET (subprojects
     app_scheduler
     app_timer
     app_usbd
     atomic
     atomic_fifo
     atomic_flags
     hardfault
     section_vars
     strerror
     util
     utf)

#-----------------------------------------------------------------------------
# Build configuration
#-----------------------------------------------------------------------------

# build all projects
FOREACH (project ${subprojects})
  ADD_SUBDIRECTORY (${project} ${project})
ENDFOREACH ()
