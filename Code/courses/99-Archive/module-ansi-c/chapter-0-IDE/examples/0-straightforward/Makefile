
all: README.md examples/hello.c
	rm -rf build
	mkdir build
	cp README.md build
	cd build; mkdir examples; cd ..
	gcc -std=c89 -o build/examples/hello.exe examples/hello.c

remove:
	rm -rf build

