坚持使用 build 目录，进行外部编译。以避免在源码目录中混杂垃圾文件。

本代码参考/摘自 [CMake 入门实战 - 自定义编译选项][1]

构建指令：
```shell
cd build && cmake ..
cd build && cmake .. -D_USE_MY_PRINTLN_=ON
```

# 疑问

config.h 文件应该放到哪个目录？

【有待解答】

如何修改子模块的默认参数呢？默认使用静态库
```shell
cd build && cmake .. -D_USE_MY_PRINTLN_=ON -DFOO_BUILD_SHARED=ON
```

能否在主模块中修改子模块参数，使得以下命令 `cd build && cmake .. -D_USE_MY_PRINTLN_=ON` 也是使用动态库呢？

——本来以为很 easy 的操作，事实上也有坑。参考 [Overriding a default option(…) value in CMake from a parent CMakeLists.txt
][2]

[1]:http://www.hahack.com/codes/cmake/#%E8%87%AA%E5%AE%9A%E4%B9%89%E7%BC%96%E8%AF%91%E9%80%89%E9%A1%B9
[2]:https://stackoverflow.com/questions/3766740/overriding-a-default-option-value-in-cmake-from-a-parent-cmakelists-txt
