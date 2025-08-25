
Setup SDL2 and SDL_Image frm source using mingw:
https://www.youtube.com/watch?v=dDnfXOz8kY4&t=317s

a) Install compilers and build tools

b) Install SDL2

~{
mkdir lib
cd lib
git clone -b SDL2 https://github.com/libsdl-org/SDL.git
mkdir build-sdl
cmake -S SDL -B build-sdl
cd build-sdl
make install
}~

c) Install SDL_image

~{
git clone -b SDL2 https://github.com/libsdl-org/SDL_image.git
mkdir build-sdl-image
cmake -S SDL -B build-sdl-image
cd build-sdl-image
git submodule update --init --recursive

clear

cd external
cd zlib
mkdir build
cd build
cmake ..
make install -j8
cd ../..

clear

cd libpng
mkdir build
cd build
cmake ..
make install

cd ../../
cd ../

clear

makedir build
cd build
cmake .. -DSDL2IMAGE_JPG=OFF
make install -j8

}~

d) Compiler of example

Creat a CMakeLists.txt

