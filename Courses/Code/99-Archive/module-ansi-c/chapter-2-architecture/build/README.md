
A) Descr

a) General

About appliquation architecture.

Distinguish usages.

b) Version

This project focus
on the usage of examples.

Is it test of:
- Sintax/grammar.
- Pattern.
- Architecture. ( mixt methode )
- Standard lib.
- Third part lib.
- My library implementation.

My library use others lib
but test every features used
and self-implemented.



B) Implemenation

a) Add lib

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

