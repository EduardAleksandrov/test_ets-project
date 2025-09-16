
run:
	g++ -std=c++17 -o build/code main.cpp ./sources/calc.cpp && ./build/code

dir:
	mkdir build && cd tests && mkdir build && mkdir build-conan