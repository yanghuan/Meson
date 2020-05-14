cmake_minimum_required (VERSION 3.8)

include_directories(./)

file(GLOB_RECURSE all_files
    "*.h"
    "*.cpp"
)

message("files = ${all_files}")

# 将源代码添加到此项目
add_executable (outcpp ${all_files} "../rt/GCobject.cpp")