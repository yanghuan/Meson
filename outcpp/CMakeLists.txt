# CMakeList.txt: outcpp 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)


if(WIN32)
  add_custom_target("rt")
  add_custom_command(TARGET rt
                       POST_BUILD
                       COMMAND copy_rt.bat )
endif()

include_directories(./)

file(GLOB_RECURSE all_files
    "*.h"
    "*.cpp"
)

message("files = ${all_files}")

# 将源代码添加到此项目
add_executable (outcpp ${all_files})

# TODO: 如有需要，请添加测试并安装目标。
