cmake_minimum_required(VERSION 3.9)
project(dedupbackup)

set(CMAKE_CXX_STANDARD 11)

set (ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set (PROJECTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/projects)

set(3LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty)

add_subdirectory(${ROOT}/projects/utils/cmake ${CMAKE_CURRENT_BINARY_DIR}/utils)

add_subdirectory(${ROOT}/projects/facade/cmake ${CMAKE_CURRENT_BINARY_DIR}/facade)