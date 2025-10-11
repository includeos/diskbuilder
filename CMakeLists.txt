cmake_minimum_required(VERSION 3.5)

project (diskimagebuilder)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILER clang++)

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to RELEASE as none was specified.")
  set(CMAKE_BUILD_TYPE "RELEASE")
endif()

# DEBUG
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -ggdb -DDEBUG")

# SANITIZER
set(CMAKE_CXX_FLAGS_SANITIZE "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fsanitize=leak -fsanitize=undefined")
set(CMAKE_EXE_LINKER_FLAGS_SANITIZE "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address -fsanitize=leak -fsanitize=undefined")

# THREAD SANITIZER
set(CMAKE_CXX_FLAGS_SANITIZE_THREAD "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=thread")
set(CMAKE_EXE_LINKER_FLAGS_SANITIZE_THREAD "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=thread")

# COVERAGE
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_DEBUG} -ftest-coverage -fprofile-arcs")
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS} -ftest-coverage -fprofile-arcs")

set(SOURCES main.cpp filetree.cpp writer.cpp)

add_executable(diskbuilder ${SOURCES})
target_link_libraries(diskbuilder stdc++)
#
# Installation
#
set(CMAKE_INSTALL_MESSAGE LAZY) # to avoid spam

install(TARGETS diskbuilder DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
