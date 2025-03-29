cmake_minimum_required(VERSION 3.10)
project(CppDemo VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# 添加可执行文件
add_executable(templated_classes src/templated_classes.cpp)
add_executable(templated_functions src/templated_functions.cpp)
add_executable(references src/references.cpp)
add_executable(move_semantics src/move_semantics.cpp)

# 添加include目录（如果有头文件的话）
include_directories(include)
