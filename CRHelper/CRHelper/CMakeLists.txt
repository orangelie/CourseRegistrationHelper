cmake_minimum_required (VERSION 3.8)

set(CRAPP "CRApplication.h" "CRApplication.cpp")
set(UTILS "Utils.h" "Utils.cpp")
set(FILELOADER "FileLoader.h" "FileLoader.cpp")

add_executable (CRHelper "Main.cpp" ${CRAPP} ${UTILS} ${FILELOADER})

add_custom_command(TARGET CRHelper POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
      ${CMAKE_SOURCE_DIR}/CRHelper/Bin
      ${CMAKE_BINARY_DIR}/CRHelper)

