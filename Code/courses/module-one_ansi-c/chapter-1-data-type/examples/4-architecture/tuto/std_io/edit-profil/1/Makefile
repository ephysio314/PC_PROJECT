
.PHONY: build
build: build/README.md
	gcc -std=c89 -o build/app.exe main.c

run:
	./build/app.exe

setup:
	rm -rf build
	mkdir build
	cp README.md build

