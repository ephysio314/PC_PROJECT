
Implementation of project IDE using makefile as script-tool.

Most straightforward implementation.

B) Scripts

1) "all"

Able only if the following files are available:
- "README.md"
- "examples/hello.c"

Action:
- Remove current "build" directory if any with all he's contant.
- make a new one.
- copy the needed docs files into build.
- Creat a diretory in build for examples.
- Compile the source file "examples/hello.c"
into a binary-executable "build/examples/hello.exe".

2) "remove"

Action:
- Remove current "build" directory if any with all he's contant.


