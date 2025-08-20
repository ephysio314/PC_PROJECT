
all: setup build

.PHONY: build
build: build/examples/hello.exe

build/examples/hello.exe: build/examples/DESCR.md examples/hello.c 
	gcc -std=c89 -o build/examples/hello.exe examples/hello.c

.PHONY: remove
remove:
	rm -rf build

.PHONY: setup
setup: README.md examples/DESCR.md
	rm -rf build
	mkdir build
	cp README.md build
	cd build; mkdir examples; cd ..
	cd examples ; cp DESCR.md ../build/examples ; cd ..
	

