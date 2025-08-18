
BIN_EXE= build/examples/hello.exe build/examples/arithmetics.exe build/examples/test_myadd.exe build/examples/test_mysub.exe

CC_VERSION= -std=c89
CC_FLAGS= $(CC_VERSION)
CC= gcc $(CC_FLAGS)

P1= build/deps/
LIB= $(P1)libmyadd.a

P2= build/deps/
DYN= $(P2)libmysub.so

DEPS_OBJ= build/deps/myadd.o build/deps/mysub.o

DEPS= $(LIB) $(DYN) $(DEPS_OBJ)

LINK= -Lbuild/deps -lmyadd -lmysub

LIB_CC= ar rcs

DYN_FLAG= -shared
DYN_OBJ_FLAG= -fPIC

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
	cd deps ; cp DESCR.md ../build/deps; cd ..

build/deps/libmyadd.a: build/deps/myadd.o
	$(LIB_CC) $@ $<

build/deps/%.o: deps/%.c
	$(CC) -c $< -o $@

build/deps/libmysub.so: build/deps/mysub.o
	$(CC) $(DYN_FLAG) -o $@ $<

build/deps/%.o: deps/dyn/%.c
	$(CC) $(DYN_OBJ_FLAG) -c $< -o $@


