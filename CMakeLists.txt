cmake_minimum_required(VERSION 3.30)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/image_processor)
set(MAIN_DIR ${SRC_DIR}/main)
set(CORE_DIR ${SRC_DIR}/core)
set(FILTERS_DIR ${SRC_DIR}/filters)
set(FACTORY_DIR ${SRC_DIR}/factory)
set(IO_DIR ${SRC_DIR}/io)

file(GLOB MAIN_SRC ${MAIN_DIR}/*.cpp)
file(GLOB CORE_SRC ${CORE_DIR}/*.cpp)
file(GLOB FILTERS_SRC ${FILTERS_DIR}/*.cpp)
file(GLOB FACTORY_SRC ${FACTORY_DIR}/*.cpp)
file(GLOB IO_SRC ${IO_DIR}/*.cpp)

add_executable(image_processor
        ${MAIN_SRC}
        ${CORE_SRC}
        ${FILTERS_SRC}
        ${FACTORY_SRC}
        ${IO_SRC}
)

include_directories(${SRC_DIR})
