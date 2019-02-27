cmake_minimum_required(VERSION 2.8)
project( opencv_microservice )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pthread -Wall -pedantic -Wextra -Wno-missing-field-initializers")

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O0 -fprofile-arcs -ftest-coverage")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/CMakeModules)

find_package( OpenCV 4.0.0 REQUIRED )
include_directories( ${PROJECT_SOURCE_DIR}/include )
include_directories( ${OpenCV_INCLUDE_DIRS} )

file(GLOB opencv_microservice_SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable( opencv_microservice ${opencv_microservice_SOURCES} )

set(CROW_ROOT_DIR PATH "${PROJECT_SOURCE_DIR}/third-party/crow")

find_package(Crow)
if (CROW_FOUND)
    include_directories(${CROW_INCLUDES})
else()
    message(FATAL_ERROR "Crow not found. Could not build this app.")
endif()

find_package(Boost COMPONENTS system REQUIRED)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDEDIR})

    set(Boost_USE_STATIC_LIBS        ON)
    set(Boost_USE_MULTITHREADED      ON)
    set(Boost_USE_STATIC_RUNTIME    OFF)

    target_link_libraries(opencv_microservice ${Boost_SYSTEM_LIBRARIES})

else()
    message(FATAL_ERROR "Boost not found. Could not build this app.")
endif()

target_link_libraries( opencv_microservice ${OpenCV_LIBS} )