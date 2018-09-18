CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
PROJECT(tree C CXX)

file(GLOB SOURCES "*.cpp")

add_executable(tree ${SOURCES})