cmake_minimum_required(VERSION 3.14)
project(omedit_opcua)

add_library(omedit_opcua STATIC)
target_sources(omedit_opcua PRIVATE open62541.c)

target_include_directories(omedit_opcua PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
