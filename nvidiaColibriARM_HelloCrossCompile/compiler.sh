export CROSS_COMPILE=/opt/gcc-linaro/bin/arm-linux-gnueabihf-
${CROSS_COMPILE}gcc --sysroot=/opt/Colibri_T30_LinuxImageV2.6/colibri-t30_bin -mfloat-abi=hard -o hello_world hello_world.c
