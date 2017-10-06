mkdir -p build
cd build
gcc -c -I./include -I/usr/local/include ../hello_world.c
gcc -o hello_world hello_world.o

#gcc -o hello_world hello_world.c
