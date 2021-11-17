all: run

run: bin/test_main.o bin/File_Reader.o bin/workout.o bin/Customer.o bin/Functions.o bin/Trainer.o bin/Studio.o bin/File_Reader_Output.o
	g++ bin/test_main.o bin/File_Reader.o bin/workout.o bin/Customer.o bin/Functions.o bin/Trainer.o bin/Studio.o bin/File_Reader_Output.o -o run

bin/test_main.o: src/test_main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/test_main.o src/test_main.cpp

bin/File_Reader.o: src/File_Reader.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/File_Reader.o src/File_Reader.cpp

bin/workout.o:src/workout.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/workout.o src/workout.cpp

bin/Customer.o:src/Customer.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Customer.o src/Customer.cpp

bin/Functions.o:src/Functions.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Functions.o src/Functions.cpp

bin/Trainer.o:src/Trainer.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Trainer.o src/Trainer.cpp

bin/Studio.o:src/Studio.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Studio.o src/Studio.cpp

bin/File_Reader_Output.o:src/File_Reader_Output.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/File_Reader_Output.o src/File_Reader_Output.cpp

	@echo success
clean:
	rm bin/test_main.o bin/File_Reader.o bin/workout.o bin/Customer.o bin/Functions.o bin/Trainer.o bin/Studio.o run