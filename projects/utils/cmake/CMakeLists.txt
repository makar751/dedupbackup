cmake_minimum_required(VERSION 3.9)
set (PROJECT_NAME utils)
Project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

set (HEADERS
        ../src/log.h ../src/error.h ../src/messages_dictionary.h ../src/file_utils.h)

set (SOURCES
        ../src/log.cpp ../src/error.cpp ../src/file_utils.cpp)

include(${PROJECTS_DIR}/cmakes/CMakeLists.txt)

find_package(Threads REQUIRED)

set (LIBRARIES
        ${LOG4CPLUS_LIBRARIE}
        Threads::Threads
        )

set (LINK_DIRS
        ${LOG4CPLUS_LINK}
        )

set (INCLUDE_DIRS
        ${LOG4CPLUS_INCLUDE}
        ${SHA512_INCLUDE}
        )

link_directories (${LINK_DIRS})

include_directories (${INCLUDE_DIRS})

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries (${PROJECT_NAME} ${LIBRARIES})