
1) Issue one fix

When use the root Makfile that call other Makefiles.
Should not count on those others calling others using "cd",
because the stack of directory movement could prevent to handle everything.
It's undefine behaviors.

Should instead call each sub-makefile individualy
by "cd" in the corresponding direcotry
and generate the needed ressource
for the futur ones.

2) Issue two fix

In the Makefile of the sub-directory "lib",
The variable "LIB{number}_BUILD" contain the name
of the build-directory to creat to store
the library-binary build.

It should stay this only name.

If the binary was in a sub-directory of this one,
it should be added in "LIB{number}_BIN = $(LIB{number}_BUILD){sub-dir}/lib{name}.a"

Be careful to not include after "$(LIB{number}_BUILD)" a "/"
because this first one was include in the "LIB{number}_BUILD" variable.


