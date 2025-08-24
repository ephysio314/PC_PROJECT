
When use the root Makfile that call other Makefiles.
Should not count on those others calling others using "cd",
because the stack of directory movement could prevent to handle everything.
It's undefine behaviors.

Should instead call each sub-makefile individualy
by "cd" in the corresponding direcotry
and generate the needed ressource
for the futur ones.




