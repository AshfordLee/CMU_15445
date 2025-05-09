cmake_minimum_required(VERSION 3.10)
project(CppDemo VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# 添加可执行文件
add_executable(templated_classes src/templated_classes.cpp)
add_executable(templated_functions src/templated_functions.cpp)
add_executable(references src/references.cpp)
add_executable(move_semantics src/move_semantics.cpp)
add_executable(move_constructors src/move_constructors.cpp)
add_executable(vectors src/vectors.cpp)
add_executable(sets src/sets.cpp)
add_executable(unordered_maps src/unordered_maps.cpp)
add_executable(auto src/auto.cpp)
add_executable(wrapper_class src/wrapper_class.cpp)
add_executable(iterator src/iterator.cpp)
add_executable(namespaces src/namespaces.cpp)
add_executable(unique_ptr src/unique_ptr.cpp)
add_executable(shared_ptr src/shared_ptr.cpp)
add_executable(mutex src/mutex.cpp)
add_executable(scoped_lock src/scoped_lock.cpp)
add_executable(condition_variable src/condition_variable.cpp)
add_executable(rwlock src/rwlock.cpp)
# 添加include目录（如果有头文件的话）
include_directories(include)
