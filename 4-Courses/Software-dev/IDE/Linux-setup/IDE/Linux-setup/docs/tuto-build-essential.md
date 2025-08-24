
A) What is this dependancy

It's a package of the apt package manager natif to linux.
It install several tools to build appliquation.

https://thelinuxcode.com/install-build-essential-ubuntu/

Contain:
- gcc: C compiler.
- g++: C++ compiler.
- make: Build tool.
- GDB: Debugger.
- dpkg-dev: Tool to build debian packages.
- autoconf: config script tool.

B) Install

Open the terminal.
Enter the below commandes.
Enter your password ( because in super-user. )

Run the following commandes:
~{
sudo apt update
sudo apt install build-essential
gcc --version
}~

C) Test

Creat a file name "Makefile" with the follow contant:
~{

all: run

a.exe: main.c
    gcc -o a.exe main.c

run: a.exe
    ./a.exe

}~

Creat a source-file name "main.c"
witht he following contant:

~{

#include <stdio.h>

int main(void){
    printf("Hello, World!\n");
    return 0;
}

}~



