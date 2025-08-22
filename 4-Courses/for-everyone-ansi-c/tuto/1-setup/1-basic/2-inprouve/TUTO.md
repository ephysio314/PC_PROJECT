
1) First tuto

You have a "Makefile that contain the following script:
	"app.exe: main.c
		gcc -ansi -o app.exe main.c"

Note:
	The second line have to start with a tabulation.

Open the terminal in this "root" directory.
Write the text:
	"make app.exe"

That ask the "Makefile" to output the file "app.exe".

To run this executable,
write the command:
	"./app.exe"

A success show the following message:
	"Hello, World!"

2) Second tuto

The Makefile take automatique variables
to reuse parameter of the script
without changing the value inside it.

"$@" take the output file value.

"$<" take the first recipie/condition as value.

