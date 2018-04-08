cmake_minimum_required(VERSION 3.9)
set (PROJECT_NAME facade)
Project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

set (HEADERS
        ../src/main.cpp
        )

set (SOURCES

        )

include(${PROJECTS_DIR}/cmakes/CMakeLists.txt)

set (LIBRARIES
        ${LOG4CPLUS_LIBRARIE}
        utils
        )

set (LINK_DIRS
        ${LOG4CPLUS_LINK}
        )

set (INCLUDE_DIRS
        ${LOG4CPLUS_INCLUDE}
        ${PROJECTS_DIR}/utils/src
        )

link_directories(${LINK_DIRS})
include_directories(${INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries (${PROJECT_NAME} ${LIBRARIES})