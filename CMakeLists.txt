cmake_minimum_required(VERSION 3.26)
project(heap-allocator CXX)
set(CMAKE_CXX_STANDARD 20)

# Set compiler warnings
if (MSVC)
    add_compile_options(/W4 /Wall /WX)
else()
    add_compile_options(
        -Wall
        -Wextra
        -Werror
        $<$<COMPILE_LANGUAGE:CXX>:-Wold-style-cast>
        -Wno-unused-parameter
    )
endif()

#add_executable(${PROJECT_NAME} ${MY_SOURCES} ${MY_INCLUDES})
#target_include_directories(${PROJECT_NAME} PRIVATE include)
#target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL_LIBRARIES} flecs::flecs_static glm::glm)
