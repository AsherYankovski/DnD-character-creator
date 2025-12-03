cmake_minimum_required(VERSION 3.15)
project(dnd_creator VERSION 0.1.0 LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(DEPS_DIR "${PROJECT_SOURCE_DIR}/deps")

add_library(cJSON "${DEPS_DIR}/cJSON/cJSON.c")

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} cJSON)
target_include_directories(${PROJECT_NAME} PUBLIC "${DEPS_DIR}")
