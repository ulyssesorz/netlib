#!/bin/bash

set -e

#创建build文件夹
if [ ! -d `pwd`/build ]; then
    mkdir `pwd`/build
fi

#清空build
rm -rf `pwd`/build/*

#进入build并执行cmake和make
cd `pwd`/build &&
    cmake .. &&
    make

cd ..
#在系统include创建netilib文件夹
if [ ! -d /usr/include/netlib ]; then
    mkdir /usr/include/netlib
fi

#把include的头文件拷贝到系统的include
cd `pwd`/include
for header in `ls *.h`
do
    cp $header /usr/include/netlib
done

cd ..
cp `pwd`/lib/libnetlib.so /usr/lib

#创建动态库的缓存
ldconfig