cmake_minimum_required(VERSION 3.17)
project(assignment4)
set(CMAKE_CXX_STANDARD 11)

set(Sources connectionHandler.cpp encoderdecoder.cpp MessageEncoderDecoder.cpp Protocol.cpp)
set(Headers connectionHandler.h encoderdecoder.h MessageEncoderDecoder.h Protocol.h)

find_package(Boost REQUIRED COMPONENTS thread)
link_libraries("-lboost_system")
link_libraries(-pthread)
link_libraries(Boost::thread)

include_directories(${Boost_INCLUDE_DIR})

add_executable(assignment4 BGRSclient.cpp main.cpp  ${Headers} ${Sources})