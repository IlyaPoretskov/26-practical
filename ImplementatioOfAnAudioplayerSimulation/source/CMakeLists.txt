cmake_minimum_required(VERSION 3.26)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(ImplementationOfAnAudioPlayerSimulation main.cpp ${MY_INCLUDE_DIR}/audio-player.h)
target_include_directories(ImplementationOfAnAudioPlayerSimulation PUBLIC ${MY_INCLUDE_DIR})