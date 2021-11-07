all: main

main: base_code/bin/main.o
	g++ base_code/bin/main.o

base_code/bin/main.o: src/main.cpp
#    g++ -g -Wall -Weffc -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp
	g++ -c src/main.cpp
#Clean the build directory
#clean:
#    rm -f bin/*