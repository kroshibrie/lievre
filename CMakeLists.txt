cmake_minimum_required(VERSION 4.4.4)

project(LIEVLANG)

set(CLI11_PRECOMPILED ON CACHE BOOL "" FORCE)
add_subdirectory(libs/CLI11)

add_executable(evre src/main.cc)

target_compile_options(evre PRIVATE -Wall -Wextra)

target_include_directories(evre PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(evre PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(evre PRIVATE CLI11::CLI11)