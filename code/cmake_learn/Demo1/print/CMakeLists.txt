
# 查找当前目录下的所有源文件
# 并将名称保存到 SOURCES 变量
aux_source_directory(. LIB_SOURCES)

# 生成链接库
add_library(PrintlnFunc ${LIB_SOURCES})
