#!/bin/sh

#gcc -c -I./include -I/usr/local/include hello_world.c
#gcc -o hello_world hello_world.o

mkdir -p build
g++ -o build/helloworld -std=c++1y helloworld.cpp

