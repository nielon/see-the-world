参考 http://www.hahack.com/codes/cmake/

坚持使用 build 目录，进行外部编译。以避免在源码目录中混杂垃圾文件。

config.h 文件应该放到哪个目录？

cd build && cmake ..
cd build && cmake .. -D_USE_MY_PRINTLN_=ON

如何修改子模块的默认参数呢？默认使用静态库
cd build && cmake .. -D_USE_MY_PRINTLN_=ON -DFOO_BUILD_SHARED=ON

能否在主模块中修改子模块参数，使得以下命令也是使用动态库呢？
参考 https://stackoverflow.com/questions/3766740/overriding-a-default-option-value-in-cmake-from-a-parent-cmakelists-txt
cd build && cmake .. -D_USE_MY_PRINTLN_=ON
