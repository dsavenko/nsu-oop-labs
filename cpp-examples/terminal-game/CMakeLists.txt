
cmake_minimum_required(VERSION 3.14)

project(game CXX)

set(CMAKE_CXX_STANDARD 17)

set(exe_name ${PROJECT_NAME})

if(WIN32 OR MSVC)
    include(FetchContent)
    FetchContent_Declare(
        PDcurses
        GIT_REPOSITORY https://github.com/dsavenko/PDCurses.git
        GIT_TAG        dfbac0fe5ef90a40a67d6b13cc7d9c69bf40a5f5
    )
    FetchContent_MakeAvailable(PDcurses)
endif()

add_executable(${exe_name} main.cpp)

if(WIN32 OR MSVC)
    target_link_libraries(${exe_name} PDcurses)
else()
    target_link_libraries(${exe_name} curses)
endif()

