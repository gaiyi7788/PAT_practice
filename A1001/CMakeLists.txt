cmake_minimum_required (VERSION 2.8)
project(A1001)   #根据自己的工程名修改
#下面的三个set（）三选一，测试是都可行的
set(CMAKE_CXX_COMPILER "clang++-3.8")
#set(CMAKE_CXX_COMPILER "g++")
#set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
#set (CMAKE_CXX_FLAGS  "-g -fexec-charset=GBK")
# 开启调试信息
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# set(CMAKE_BUILD_TYPE "Release")
# set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g -ggdb")
#头文件所在的路径包含进去
include_directories(${PROJECT_SOURCE_DIR}/include)  
#将src 文件夹下的全部源文件添加到SrcFiles这个集合中
aux_source_directory(./src SrcFiles)
#将可执行文件输出到文件夹bin中
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)
#将集合SrcFiles中的全部文件进行add
add_executable(A1001 ${SrcFiles})

