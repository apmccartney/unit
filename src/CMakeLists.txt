if(${verbose_traversal})
  message(STATUS "Entered src directory")
endif(${verbose_traversal})

set(headers "")
list(APPEND headers
  "functions"
  "make"
  )

foreach(header ${headers})
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${header}.hpp.in"
    "${unit_HEADER_DIR}/src/${header}.hpp"
    COPYONLY
    )
endforeach(header)

set(unit_src "${unit_src}" PARENT_SCOPE)

if(${verbose_traversal})
  message(STATUS "Exiting src directory")
endif(${verbose_traversal})
