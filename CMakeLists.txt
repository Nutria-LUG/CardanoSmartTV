#set(CMAKE_CXX_STANDARD 11) 
add_compile_options(-W -Wall -std=c++11)

cmake_minimum_required(VERSION 3.0.2)
project(smart_tv)
#Brings the headers in to the project

include_directories(include)

#if debugger is not disabled.
IF (NOT DEFINED NDEBUG)
    file(GLOB SOURCES "src/*.cc")
    file(GLOB SOURCES_DEBUG "src/debug/*.cc")
    add_executable(smart_tv ${SOURCES} ${SOURCES_DEBUG})
ENDIF()

#if debugger disabled.
IF(DEFINED NDEBUG)
    ADD_DEFINITIONS(-DNDEBUG=${NDEBUG})
    file(GLOB SOURCES "src/*.cc")
    add_executable(smart_tv ${SOURCES})
ENDIF()

target_link_libraries(smart_tv cec)
#Add custom library: custom_lib
## START LIB custom_lib
# file(GLOB CUSTOMLIBSOURCES "lib/custom_lib/*.cc")
# add_library(custom_lib STATIC ${CUSTOMLIBSOURCES})
# target_link_libraries(smart_tv custom_lib)
## END LIB custom_lib
