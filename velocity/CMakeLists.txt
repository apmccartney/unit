if(${verbose_traversal})
  message(STATUS "Entered velocity directory")
endif(${verbose_traversal})

list(APPEND unit_src
#  "${CMAKE_CURRENT_SOURCE_DIR}/src/make.cpp"
  )

set(unit_src "${unit_src}" PARENT_SCOPE)

if (${local_testing})
   list(APPEND testLabels velocity)
   add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
endif (${local_testing})

if(${verbose_traversal})
  message(STATUS "Exiting velocity directory")
endif(${verbose_traversal})
