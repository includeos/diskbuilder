cmake_minimum_required(VERSION 3.5)

project (diskimagebuilder)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILER clang++)

set(SOURCES main.cpp filetree.cpp writer.cpp)

add_executable(diskbuilder ${SOURCES})
target_link_libraries(diskbuilder stdc++)
#
# Installation
#
set(CMAKE_INSTALL_MESSAGE LAZY) # to avoid spam

install(TARGETS diskbuilder DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
