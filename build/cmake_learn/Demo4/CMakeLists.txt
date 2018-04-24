# CMake 最低版本要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project(Demo4)

# 加入一个配置头文件，用于处理 cmake 对源码的设置
configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
	)

# 指明头文件所在路径
include_directories("${PROJECT_BINARY_DIR}")

# 是否使用自己的 Print 方法
option(_USE_MY_PRINTLN_
	"Use provided println implementation"
	OFF)

# 是否加入 Println 库
if(_USE_MY_PRINTLN_)
	include_directories("${PROJECT_SOURCE_DIR}/print")
	# 添加 print 子目录
	add_subdirectory(print)
	set(EXTRA_LIBS ${EXTRA_LIBS} PrintlnFunc)
endif(_USE_MY_PRINTLN_)

# 查找当前目录下的所有源文件
# 并将名称保存到 SOURCES 变量
aux_source_directory(. SOURCES)

# 指定生成目标
add_executable(Demo ${SOURCES})

# 添加链接库
target_link_libraries(Demo ${EXTRA_LIBS})
