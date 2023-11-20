cmake_minimum_required(VERSION 3.26)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(ImplementationOfTheMobilePhoneSimulationProgram main.cpp ${MY_INCLUDE_DIR}/phone.h)
target_include_directories(ImplementationOfTheMobilePhoneSimulationProgram PUBLIC ${MY_INCLUDE_DIR})