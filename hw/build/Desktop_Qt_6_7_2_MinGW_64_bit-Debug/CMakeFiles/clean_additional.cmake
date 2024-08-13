# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\hw_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\hw_autogen.dir\\ParseCache.txt"
  "hw_autogen"
  )
endif()
