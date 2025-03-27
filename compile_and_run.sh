#!/bin/bash

# 检查是否提供了一个参数
if [ $# -eq 0 ]; then
    echo "用法: $0 <cpp源文件>"
    exit 1
fi

# 获取源文件名和不带扩展名的文件名
source_file=$1
filename=$(basename -- "$source_file")
filename_no_ext="${filename%.*}"

# 编译C++文件
echo "正在编译 $source_file..."
g++ -std=c++17 -Wall -Wextra -o "$filename_no_ext" "$source_file"

# 检查编译是否成功
if [ $? -eq 0 ]; then
    echo "编译成功！正在运行程序..."
    echo "----------------------------------------"
    # 运行编译后的程序
    ./"$filename_no_ext"
    echo "----------------------------------------"
    echo "程序执行完毕。"
else
    echo "编译失败！"
fi 