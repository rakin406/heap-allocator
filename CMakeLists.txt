cmake_minimum_required(VERSION 3.26)
project(heap-allocator CXX)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

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
