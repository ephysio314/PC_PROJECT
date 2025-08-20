
BIN_EXE= build/examples/hello.exe build/examples/test_int.exe

CC_VERSION= -std=c89
CC_FLAGS= $(CC_VERSION)
CC= gcc $(CC_FLAGS)

P1= build/deps/
DEPS= $(P1)libint.a
DEPS_OBJ= $(P1)int_conversion.o $(P1)int_operation.o

LINK= -L$(P1) -lint

LIB_CC= ar rcs

all: setup build

.PHONY: build
build: $(BIN_EXE)

build/examples/%.exe: examples/%.c build/examples/DESCR.md build/deps/DESCR.md $(DEPS)
	$(CC) -o $@ $< -Ideps $(LINK)

.PHONY: remove
remove:
	rm -rf build

.PHONY: setup
setup: README.md examples/DESCR.md deps/DESCR.md
	rm -rf build
	mkdir build
	cp README.md build
	cd build; mkdir examples; cd ..
	cd examples ; cp DESCR.md ../build/examples ; cd ..
	cd build; mkdir deps; cd ..
	cd deps ; cp DESCR.md ../build/deps ; cd ..

build/deps/libint.a: $(DEPS_OBJ)
	$(LIB_CC) $@ $^

$(P1)%.o: deps/%.c
	$(CC) -c $< -o $@

