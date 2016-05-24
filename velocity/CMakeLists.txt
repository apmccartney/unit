if(${verbose_traversal})
  message(STATUS "Entered velocity directory")
endif(${verbose_traversal})

list(APPEND unit_src  )

set(unit_src "${unit_src}" PARENT_SCOPE)

if (${local_testing})
   list(APPEND testLabels velocity)
   add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
endif (${local_testing})

set(headers "")
list(APPEND headers
  "operator>>.hpp"
)

foreach(header ${headers})
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/${header}.in"
    "${unit_HEADER_DIR}/velocity/src/${header}"
    COPYONLY
    )
endforeach(header)

if(${verbose_traversal})
  message(STATUS "Exiting velocity directory")
endif(${verbose_traversal})
