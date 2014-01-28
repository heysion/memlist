memlist
=======

链表内存，将malloc出来的内存统一添加至链表管理，退出时统一释放

编译方法
====

>tips
>>默认编译成静态库建议采用静态库编译的方法编译进去

静态库
==

>make 
或者
>make sa

动态库编译
==

>make so

静态库的使用方法
===

gcc -o test.out test.c -L. -lmemlist -I.
 test.c 为用例
>make test

动态库的使用
===

gcc -o test test.c -g -L. -lmemlist -I. -Wl,-rpath,.
>make test2

接口说明
===

为正常函数malloc的封装使用的时候与malloc无特殊差别，唯一差别就是会将申请的内存
注册到plist链表中，
最后函数退出的时候统一调用 cgfree 与free函数类似不使用参数

调用cgfree后会将注册的所有内存全部释放，可以再次使用 cgmalloc函数注册内存

使用简单，欢迎给意见! :)
