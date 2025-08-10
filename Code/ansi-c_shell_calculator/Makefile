
CC_VERSION= -std=c89
CC_FLAG= $(CC_VERSION)
CC= gcc $(CC_FLAG)

BUILD_DIR= build

TEST= $(BUILD_DIR)/hello.exe $(BUILD_DIR)/operation.exe

SRC_OBJ= $(BUILD_DIR)/module_backend.o $(BUILD_DIR)/operation.o

exe: $(TEST)

$(BUILD_DIR)/%.exe: tests/%.c $(SRC_OBJ)
	$(CC) -o $@ $^ -Isrc

$(BUILD_DIR)/%.o: src/%.c
	$(CC) -c $< -o $@

$(BUILD_DIR)/%.o: src/arithmetic/%.c
	$(CC) -c $< -o $@

setup: README.md
	rm -rf $(BUILD_DIR)
	mkdir $(BUILD_DIR)
	cp README.md $(BUILD_DIR)

