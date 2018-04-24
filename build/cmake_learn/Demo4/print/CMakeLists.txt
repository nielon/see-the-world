
# 查找当前目录下的所有源文件
# 并将名称保存到 SOURCES 变量
aux_source_directory(. LIB_SOURCES)

message(STATUS "@1 FOO_BUILD_SHARED=${FOO_BUILD_SHARED}")
option(FOO_BUILD_SHARED "Build libfoo shared library" OFF)
message(STATUS "@2 FOO_BUILD_SHARED=${FOO_BUILD_SHARED}")
# 生成链接库
if(FOO_BUILD_SHARED)
	add_library(PrintlnFunc SHARED
		${LIB_SOURCES})
	# 安装规则
	INSTALL(TARGETS PrintlnFunc DESTINATION bin)
else()
	add_library(PrintlnFunc STATIC
		${LIB_SOURCES})
	# 安装规则
	INSTALL(TARGETS PrintlnFunc DESTINATION lib)
endif()

INSTALL(FILES func.h DESTINATION include)

