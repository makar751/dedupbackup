cmake_minimum_required(VERSION 3.9)
set (PROJECT_NAME utils)
Project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

set (HEADERS
        ../src/log.h)

set (SOURCES
        ../src/log.cpp)

include(${PROJECTS_DIR}/cmakes/CMakeLists.txt)

set (LIBRARIES
        ${LOG4CPLUS_LIBRARIE}
        )

set (LINK_DIRS
        ${LOG4CPLUS_LINK}
        )

set (INCLUDE_DIRS
        ${LOG4CPLUS_INCLUDE}
        )

link_directories (${LINK_DIRS})

include_directories (${INCLUDE_DIRS})

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries (${PROJECT_NAME} ${LIBRARIES})