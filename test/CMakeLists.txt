cmake_minimum_required(VERSION 2.8)

project(TestB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(
    ../
)

FILE(GLOB Test_Sources ${CMAKE_SOURCE_DIR}/*.cpp)

add_library(NMEA0183 SHARED IMPORTED)
set_target_properties(
    NMEA0183 PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../Debug/libNMEA0183.so
)

add_executable(
    Test

    ${Test_Sources}
)

target_link_libraries(
    Test

    NMEA0183
    
)