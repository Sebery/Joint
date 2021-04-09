# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

# GLAD
add_subdirectory(vendor/glad)

# Joint API
add_library(Joint STATIC
        src/core/Application.cpp
        include/Joint/core/Application.h
        include/Joint/Joint.h
        include/Joint/events/IEvent.h
        include/Joint/core/Module.h
        src/core/Module.cpp
        include/Joint/testing/TestModule.h
        src/testing/TestModule.cpp
        include/Joint/modules/Window.h
        src/modules/Window.cpp
        include/Joint/events/IWindowEvent.h)
target_include_directories(Joint
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include)
target_link_libraries(Joint
        PUBLIC glfw
        PUBLIC glad)

# Build Configuration
if (CMAKE_CONFIGURATION_TYPES) # For Multi Configuration Generators
    set(CMAKE_CONFIGURATION_TYPES ${JOINT_BUILD_TYPES} CACHE INTERNAL "")
else()
    # For Single Configuration Generators
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${JOINT_BUILD_TYPES}")

    if (NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE) # Select Default Build Configuration
    elseif(NOT CMAKE_BUILD_TYPE IN_LIST JOINT_BUILD_TYPES)
        message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
    endif()
endif()

