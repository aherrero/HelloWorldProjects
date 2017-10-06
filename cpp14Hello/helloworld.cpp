#include <stdio.h>                  // standard I/O header file
#include <stdlib.h>

#include "include/hello_world.h"

#include <chrono>	//Online available after C++11!!
typedef std::chrono::high_resolution_clock Clock;

int main(int argc, char **argv)
{
     printf("\nHello World !!!\n");        // print "Hello World" message on screen

     system("echo helloWorld! > hello.txt");

     int x = 0;
     x = myfunc(2,3);
     printf("%d\n", x);

     return(0);
}
