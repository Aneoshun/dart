# Search all header and source files
file(GLOB hdrs "*.hpp")
file(GLOB srcs "*.cpp")
dart_add_core_headers(${hdrs} ${detail_hdrs})
dart_add_core_sources(${srcs} ${detail_srcs})

# Generate header for this namespace
dart_get_filename_components(header_names "collision_fcl headers" ${hdrs})
dart_generate_include_header_file(
  "${CMAKE_CURRENT_BINARY_DIR}/fcl.hpp"
  "dart/collision/fcl/"
  ${header_names}
)

# Install
install(
  FILES ${hdrs} ${CMAKE_CURRENT_BINARY_DIR}/fcl.hpp
  DESTINATION include/dart/collision/fcl
  COMPONENT headers
)
