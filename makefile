all: run

run: bin/test_main.o bin/File_Reader.o
	g++ bin/test_main.o bin/File_Reader.o -o run

bin/test_main.o: src/test_main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/test_main.o src/test_main.cpp

bin/File_Reader.o: src/File_Reader.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/File_Reader.o src/File_Reader.cpp
	@echo success
clean:
	rm bin/test_main.o bin/File_Reader.o run