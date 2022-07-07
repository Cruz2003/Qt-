# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\chap01_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\chap01_autogen.dir\\ParseCache.txt"
  "chap01_autogen"
  )
endif()
