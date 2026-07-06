cmake_minimum_required(VERSION 3.20)

project(http_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
  src/*.cpp
  
)

add_executable(http_server ${SOURCES})

target_include_directories(http_server PRIVATE include)
