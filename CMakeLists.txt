cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 11)

project(Sorting)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

include_directories(include gtest)

add_subdirectory(src)
add_subdirectory(samples)
add_subdirectory(gtest)
add_subdirectory(test)
