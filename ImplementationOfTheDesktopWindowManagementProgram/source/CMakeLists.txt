cmake_minimum_required(VERSION 3.26)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable("ImplementationOfTheDesktopWindowManagementProgram"
        ${MY_INCLUDE_DIR}/window.h
        main.cpp)

target_include_directories("ImplementationOfTheDesktopWindowManagementProgram" PUBLIC ${MY_INCLUDE_DIR})