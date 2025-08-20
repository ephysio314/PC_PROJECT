
cc_version= -std=c89
cc= gcc $(cc_version)

build_dir= build

exe_recipies= examples/*.c src/*.c

examples= $(build_dir)/name.exe $(build_dir)/hello.exe $(build_dir)/at.exe

lib_name= MyStr

static_lib_cc= ar rcs
static_lib_condition= $(build_dir)/StrEmpty.o $(build_dir)/StrLen.o $(build_dir)/StrCpy.o $(build_dir)/Print.o $(build_dir)/InputLine.o $(build_dir)/StrAt.o

static_lib= lib$(lib_name).a

link= -l$(lib_name)

all: setup gcc

gcc: $(examples)

$(build_dir)/%.exe: examples/%.c $(build_dir)/$(static_lib)
	$(cc) -o $@ $< -L$(build_dir) $(link) -Isrc

$(build_dir)/$(static_lib): $(static_lib_condition)
	$(static_lib_cc) $@ $^

$(build_dir)/%.o: src/%.c
	$(cc) -c $< -o $@ -Isrc

setup:
	rm -rf $(build_dir)
	mkdir $(build_dir)
	cp README.md $(build_dir)


