cmake_minimum_required(VERSION 3.16)
project(rob-run-performance CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(robrunperformance
    src/main.cpp
    src/tuner.cpp
    src/network.cpp
    src/profiles.cpp
)

target_include_directories(robrunperformance PRIVATE include)

if(WIN32)
    target_link_libraries(robrunperformance PRIVATE userenv)
endif()
