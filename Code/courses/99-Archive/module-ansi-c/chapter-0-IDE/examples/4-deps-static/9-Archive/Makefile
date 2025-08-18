
cc_version= -std=c89
cc= gcc $(cc_version)

exe_recipies= main.c src/*.c
exe= app.exe

static_lib_cc= ar rcs
static_lib_sub_condition= build/sub.o
static_lib_sub= libsub.a

dynamique_lib_obj_cc_flag= -fPIC
dynamique_lib_cc= $(cc) -shared
dynamique_lib_mult_condition= build/mult.o
dynamique_lib_mult= libmult.so

link= -lsub -lmult

all: setup gcc

gcc: build/$(exe)

exe_recipies: $(exe_recipies)
	@echo $(exe_recipies)

build/$(exe): $(exe_recipies) $(static_lib_sub) $(dynamique_lib_mult)
	$(cc) -o $@ $(exe_recipies) -Lbuild $(link) -Isrc

run: build/$(exe)
	cd build; export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../$(exe); ./$(exe)

setup:
	rm -rf build
	mkdir build

$(dynamique_lib_mult): $(dynamique_lib_mult_condition)
	$(dynamique_lib_cc) -o build/$@ $^ -Isrc

$(static_lib_sub): $(static_lib_sub_condition)
	$(static_lib_cc) build/$@ $^

build/%.o: src/%.c
	$(cc) -c $< -o $@ -Isrc

build/%.o: src/dynamique/%.c
	$(cc) $(dynamique_lib_obj_cc_flag) -c $< -o $@ -Isrc


