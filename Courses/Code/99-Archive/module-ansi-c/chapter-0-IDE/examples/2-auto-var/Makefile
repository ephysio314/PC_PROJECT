
BIN_EXE= build/examples/hello.exe build/examples/arithmetics.exe

all: setup build

.PHONY: build
build: $(BIN_EXE)

build/examples/%.exe: examples/%.c build/examples/DESCR.md
	gcc -std=c89 -o $@ $<

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
	

