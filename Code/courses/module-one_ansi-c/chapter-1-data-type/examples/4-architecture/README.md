
A) Descr

Base of handle time, date and randomness.

B) Add lib

- Add to "DEPS" the following format:
  "$(P1)lib{name}.a"

- Creat a variable for the objects-bin name in all uppercase:
  "DEPS_{NAME}_OBJ= $(P1){name}.o"

- Add this variable reference to the variable "DEPS_OBJ".

- Add to the "LINK" variable:
  "-l{name}"

- In the input/output part,
where we ask recipies and output files.
Append the following function:
~{
build/deps/lib{name}.a: $(DEPS_OBJ)
	$(LIB_CC) $@ $^
}~

