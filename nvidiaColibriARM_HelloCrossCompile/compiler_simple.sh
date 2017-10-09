export ARCH=arm
export PATH=/opt/gcc-linaro/bin/:$PATH
export CROSS_COMPILE=/opt/gcc-linaro/bin/arm-linux-gnueabihf-

${CROSS_COMPILE}gcc -mfloat-abi=hard -o hello_world2 hello_world2.c

echo "Generated hello_world2 without the file system of the target (BSP?), so, we can use libraries from the host system (printf from stdio)"
echo "We can not execute hello_world2 in the host system due is compiled with arm cross compiler"
