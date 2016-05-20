if(${verbose_traversal})
  message(STATUS "Entered constants directory")
endif(${verbose_traversal})

list(APPEND unit_src)

set(unit_src "${unit_src}" PARENT_SCOPE)

if (${local_testing})
   list(APPEND testLabels constants)
   add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
endif (${local_testing})

if(${verbose_traversal})
  message(STATUS "Exiting constants directory")
endif(${verbose_traversal})
