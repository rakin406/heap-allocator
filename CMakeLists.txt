cmake_minimum_required(VERSION 3.26)
project(heap-allocator CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(HEADER_FILES
    "include/Allocator.h"
    "include/LinkedList.h"
)

set(SOURCE_FILES
    "src/Allocator.cpp"
    "src/LinkedList.cpp"
)

enable_testing()

add_executable(
    AllocatorTest
    tests/AllocatorTest.cpp
    ${SOURCE_FILES}
    ${HEADER_FILES}
)
target_include_directories(AllocatorTest PRIVATE include)
target_link_libraries(
    AllocatorTest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(AllocatorTest)
