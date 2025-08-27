
0) examples and tuto sub-dir

Tutorial for the build-systeme of the project "Oktōmêdos".

The examples output are all in a variable
to build them all when call all.

But the "tuto" are build on demande
to avoid having to name all the files
in there several sub-dir
that grow constantly.
The user can build any of them
by asking explicitaly for an output
that have the name of one source-file
in tuto.
And it will be automatiqualy build.

1) lib sub-dir

a) Goal

Implement feature usning stdc
to creat a lib-module.

Can use "lib" in "tuto" and "examples".

Version including "lib"
and one that note are separate
inside "tuto".
The one that don't include "lib"
could use "deps". ( in the futur )

b) Methode

Creat a local Makefile
for each libraries.
They are made to output in
"build/lib/{name}" direcotry.

The project that need a library
can request it
and a list of script
will "cd" and call the correspon ding makefile.

c) Why

By having a script to build
inside the sub-lib-dir,
by coping it we have
a setup already there

and the root-script-file
have only one script to copy
and one variable.

In other words,
easy to scale.

~FUTUR

2) deps

Link static-libraries
to be use in "lib".







