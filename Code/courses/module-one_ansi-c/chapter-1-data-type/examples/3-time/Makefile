
BIN_EXE= build/examples/hello.exe build/examples/test_int.exe build/examples/test_str.exe build/examples/io.exe build/examples/files.exe build/examples/rand.exe build/examples/delay.exe

CC_VERSION= -std=c89
CC_FLAGS= $(CC_VERSION)
CC= gcc $(CC_FLAGS)

P1= build/deps/
DEPS= $(P1)libint.a $(P1)libstr.a $(P1)libcl.a $(P1)libmytime.a $(P1)librandom.a
DEPS_INT_OBJ= $(P1)int_conversion.o $(P1)int_operation.o
DEPS_STR_OBJ= $(P1)str.o $(P1)str_buff.o
DEPS_CL_OBJ=  $(P1)cl_io.o
DEPS_MYTIME_OBJ= $(P1)mytime.o
DEPS_RAMDOM_OBJ= $(P1)random.o
DEPS_OBJ= $(DEPS_INT_OBJ) $(DEPS_STR_OBJ) $(DEPS_CL_OBJ) $(DEPS_MYTIME_OBJ) $(DEPS_RAMDOM_OBJ)

LINK= -L$(P1) -lint -lstr -lcl -lmytime -lrandom

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

build/deps/librandom.a: $(DEPS_OBJ)
	$(LIB_CC) $@ $^

build/deps/libmytime.a: $(DEPS_OBJ)
	$(LIB_CC) $@ $^

build/deps/libcl.a: $(DEPS_OBJ)
	$(LIB_CC) $@ $^
	
build/deps/libstr.a: $(DEPS_OBJ)
	$(LIB_CC) $@ $^
	
build/deps/libint.a: $(DEPS_OBJ)
	$(LIB_CC) $@ $^

$(P1)%.o: deps/%.c
	$(CC) -c $< -o $@ -Ideps

