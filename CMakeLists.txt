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

set(HEADER_FILES
    "include/Allocator.h"
)

set(SOURCE_FILES
    "src/Allocator.cpp"
)
#add_executable(${PROJECT_NAME} ${MY_SOURCES} ${MY_INCLUDES})
#target_include_directories(${PROJECT_NAME} PRIVATE include)
