
CC_VERSION= -std=c89
CC_FLAG= $(CC_VERSION)
CC= gcc $(CC_FLAG)

BUILD_DIR= build

TESTS= 

P1= $(BUILD_DIR)/examples/
EXAMPLES= $(P1)hello.exe $(P1)operation.exe $(P1)int_convert.exe

P2= $(BUILD_DIR)/src/
SRC_OBJ= $(P2)module_backend.o $(P2)int_operation.o $(P2)float_operation.o $(P2)int_conversion.o

exe: $(EXAMPLES) $(TESTS)

$(BUILD_DIR)/examples/%.exe: examples/%.c $(SRC_OBJ)
	$(CC) -o $@ $^ -Isrc

$(BUILD_DIR)/tests/%.exe: tests/%.c $(SRC_OBJ)
	$(CC) -o $@ $^ -Isrc

$(BUILD_DIR)/src/%.o: src/%.c
	$(CC) -c $< -o $@

$(BUILD_DIR)/src/%.o: src/arithmetic/%.c
	$(CC) -c $< -o $@

$(BUILD_DIR)/src/%.o: src/data-type/%.c
	$(CC) -c $< -o $@

setup: README.md
	rm -rf $(BUILD_DIR)
	mkdir $(BUILD_DIR)
	cp README.md $(BUILD_DIR)
	cd $(BUILD_DIR); mkdir tests; mkdir examples; mkdir src; cd ..


