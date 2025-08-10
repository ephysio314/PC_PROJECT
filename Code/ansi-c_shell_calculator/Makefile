
CC_VERSION= -std=c89
CC_FLAG= $(CC_VERSION)
CC= gcc $(CC_FLAG)

BUILD_DIR= build

TEST= $(BUILD_DIR)/hello.exe

exe: $(TEST)

build/%.exe: tests/%.c
	$(CC) -o $@ $^ -Isrc

setup: README.md
	rm -rf $(BUILD_DIR)
	mkdir $(BUILD_DIR)
	cp README.md $(BUILD_DIR)

