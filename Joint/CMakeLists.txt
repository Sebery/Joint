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
        src/core/Window.cpp)
target_include_directories(Joint
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include)
target_link_libraries(Joint
        PUBLIC glfw
        PUBLIC glad)

