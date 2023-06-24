cmake_minimum_required(VERSION 2.8)

project(NMEA0183)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(

)

FILE(GLOB NMEA_Sources ${CMAKE_SOURCE_DIR}/*.cpp)

add_library(
    NMEA0183
    SHARED

    ${NMEA_Sources}
)
