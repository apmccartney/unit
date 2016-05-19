if(${verbose_traversal})
  message(STATUS "Entered area directory")
endif(${verbose_traversal})

list(APPEND unit_src
  "${CMAKE_CURRENT_SOURCE_DIR}/src/make.cpp"
#  "${CMAKE_CURRENT_SOURCE_DIR}/src/toUnit.cpp"
#  "${CMAKE_CURRENT_SOURCE_DIR}/src/toString.cpp"
  )

set(unit_src "${unit_src}" PARENT_SCOPE)

if (${local_testing})
   list(APPEND testLabels area)
   add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
endif (${local_testing})

if(${verbose_traversal})
  message(STATUS "Exiting area directory")
endif(${verbose_traversal})
