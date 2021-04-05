cmake_minimum_required(VERSION 3.17)

# Main Variables
set(JOINT_BUILD_TYPES Debug Release)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Joint)

# Joint Engine API
add_subdirectory(Joint)

# Build Demo Project
option(JOINT_BUILD_DEMO "Build Demo Project" ON)
if (JOINT_BUILD_DEMO)
    add_subdirectory(Demo)
endif ()



