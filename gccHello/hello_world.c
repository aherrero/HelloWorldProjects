#include <stdio.h>                  // standard I/O header file
#include "include/hello_world.h"
#include <stdlib.h> 

int main(int argc, char **argv)
{
     printf("\nHello World !!!\n");        // print "Hello World" message on screen
system("echo helloWorld! > hello.txt");
     int x = 0;
     x = myfunc(2,3);
     printf("%d\n", x);
     return(0);
}
