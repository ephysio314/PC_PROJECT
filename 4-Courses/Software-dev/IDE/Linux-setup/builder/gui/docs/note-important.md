
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

Be carefull to note add extrat "/" when concatenate Makefile variables.

SDL_image depand on external libraries
that seem to not be automatiqualy download when use cmake.
Should build them individualy using the internal script if any,
or list them and doanload them myself.


