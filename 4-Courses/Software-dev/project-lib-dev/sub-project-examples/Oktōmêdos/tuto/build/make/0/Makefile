
CC_VERSION= -std=c89
CC= gcc $(CC_VERSION)

P1= build/examples/
P2= build/tuto/

EXAMPLES= $(P1)hello.out

all: $(EXAMPLES)

$(P1)%.out: examples/%.c build/README.md
	$(CC) -o $@ $<

$(P2)%.out: tuto/%.c build/README.md
	$(CC) -o $@ $<

build/README.md: README.md
	rm -rf build
	mkdir build
	cp README.md build
	cd build; mkdir examples; cd ..;
	cd build; mkdir tuto; cd ..;

remove:
	rm -rf build
