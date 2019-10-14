#-----------------------------------------------------------------------------
# nRF52 SDK libraries
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

# define subprojects
SET (subprojects
     app_scheduler
     app_timer
     atomic
     atomic_fifo
     atomic_flags
     hardfault
     section_vars
     strerror
     usbd
     util
     utf)

#-----------------------------------------------------------------------------
# Build configuration
#-----------------------------------------------------------------------------

# build all projects
FOREACH (project ${subprojects})
  ADD_SUBDIRECTORY (${project} ${project})
ENDFOREACH ()
