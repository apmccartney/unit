cmake_minimum_required( VERSION 3.2 )

set(projectName "unit")
set(projectVersion "1.0.0")

if(NOT DEFINED commonCMakeScripts_path)
  set(commonCMakeScripts_path "${CMAKE_SOURCE_DIR}/commonCMakeScripts")
endif(NOT DEFINED commonCMakeScripts_path)

include(subprojects.cmake)
include(${commonCMakeScripts_path}/base.cmake)
include(${commonCMakeScripts_path}/doxygen.cmake)

set(headers "")
list(APPEND headers
  "area.hpp"
  "length.hpp"
  "Quantity.hpp"
  "scale.hpp"
  "time.hpp"
  "velocity.hpp"
  "volume.hpp"
  )

foreach(header ${headers})
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${header}.in"
    "${unit_HEADER_DIR}/${header}"
    COPYONLY
    )
endforeach(header)

set(header_subdirs "")
list(APPEND header_subdirs)

foreach(subdir ${header_subdirs})
  if( NOT( EXISTS "${unit_HEADER_DIR}/${subdir}" ) )
    file(MAKE_DIRECTORY "${unit_HEADER_DIR}/${subdir}}")
  endif( NOT( EXISTS "${unit_HEADER_DIR}/${subdir}" ) )
endforeach(subdir)

if (${local_testing})
  list(APPEND testLabels unit)
  add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/test" )
endif (${local_testing})

set(subdirs ${header_subdirs} )
list(APPEND subdirs
  "area"
  "length"
  "time"
  "velocity"
  "volume"
  )

foreach(subdir ${subdirs})
  add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}" )
endforeach(subdir)

include(${commonCMakeScripts_path}/assemble.cmake)
include(${commonCMakeScripts_path}/terminus.cmake)
