cmake_minimum_required(VERSION 2.8)
project(ev3bot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include(conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

set(SOURCE_FILES main.cpp oauth.cpp oauth.h token_storage.cpp token_storage.h event_receiver.cpp event_receiver.h route_set.cpp route_set.h)
add_executable(ev3bot ${SOURCE_FILES})
target_link_libraries(ev3bot ${CONAN_LIBS} bsoncxx mongocxx)