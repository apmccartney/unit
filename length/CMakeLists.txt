if(${verbose_traversal})
  message(STATUS "Entered length directory")
endif(${verbose_traversal})

list(APPEND unit_src )

set(unit_src "${unit_src}" PARENT_SCOPE)

if( NOT( EXISTS "${unit_HEADER_DIR}/length/src" ) )
  file(MAKE_DIRECTORY "${unit_HEADER_DIR}/length/src")
endif( NOT( EXISTS "${unit_HEADER_DIR}/length/src" ) )

set(headers "")
list(APPEND headers
  "operator>>.hpp"
)

foreach(header ${headers})
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/${header}.in"
    "${unit_HEADER_DIR}/length/src/${header}"
    COPYONLY
    )
endforeach(header)

if (${local_testing})
   list(APPEND testLabels length)
   add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
endif (${local_testing})

if(${verbose_traversal})
  message(STATUS "Exiting length directory")
endif(${verbose_traversal})
