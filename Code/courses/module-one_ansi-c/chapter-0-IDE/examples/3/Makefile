
BIN_EXE= build/examples/hello.exe build/examples/arithmetics.exe

CC_VERSION= -std=c89
CC_FLAGS= $(CC_VERSION)
CC= gcc $(CC_FLAGS)

all: setup build

.PHONY: build
build: $(BIN_EXE)

build/examples/%.exe: examples/%.c build/examples/DESCR.md
	$(CC) -o $@ $<

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
	

