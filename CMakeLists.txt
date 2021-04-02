cmake_minimum_required(VERSION 3.17)

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

## Joint Engine API
#file(GLOB_RECURSE JOINT_SOURCE_FILES
#        ${CMAKE_SOURCE_DIR}/src/*.cpp
#        ${CMAKE_SOURCE_DIR}/src/*.h)
#file(GLOB_RECURSE JOINT_INCLUDE_FILES
#        ${CMAKE_SOURCE_DIR}/include/*.h)
#add_library(${JOINT_LIB}
#        ${JOINT_SOURCE_FILES}
#        ${JOINT_INCLUDE_FILES})
#target_include_directories(${JOINT_LIB}
#        PRIVATE ${CMAKE_SOURCE_DIR}/include/Joint
#        PUBLIC ${CMAKE_SOURCE_DIR}/vendor/glfw/include)
#target_link_directories(${JOINT_LIB}
#        PRIVATE ${CMAKE_SOURCE_DIR}/vendor/glfw/src)
## Dependencies
## GLFW
#set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#add_subdirectory(vendor/glfw)
### Add Dependencies
#target_link_libraries(${JOINT_LIB} glfw)


