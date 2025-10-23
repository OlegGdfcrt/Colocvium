cmake_minimum_required(VERSION 3.15)
project(Colocvium23102025)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

add_executable(Colocvium23102025 
    Colocvium23102025.cpp
)