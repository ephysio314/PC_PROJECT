
~TUTO ONE:

Install build-tools

~{
sudo apt update
sudo apt build-essential
sudo apt git
sudo apt cmake
}~

Install glfw dependancies

~{
sudo apt-add-repository universe
sudo apt-get update
sudo apt-get install doxygen
}~

Download the source code.

~{
rm -rf project
mkdir project
cd project
git clone https://github.com/glfw/glfw.git
ls
}~

Build the project

~{
mkdir build
cmake -S glfw -B build
cmake --build build
ls build
ls build/examples
}~

Run an example

~{
./build/examples/triangle-opengl
}~

Remove the project

~{
cd ..
rm -rf project
}~

