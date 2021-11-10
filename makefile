all: run

run: bin/test_main.o bin/File_Reader.o bin/workout.o
	g++ bin/test_main.o bin/File_Reader.o bin/workout.o -o run

bin/test_main.o: src/test_main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/test_main.o src/test_main.cpp

bin/File_Reader.o: src/File_Reader.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/File_Reader.o src/File_Reader.cpp

bin/workout.o:src/workout.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/workout.o src/workout.cpp

	@echo success
clean:
	rm bin/test_main.o bin/File_Reader.o bin/workout.o run