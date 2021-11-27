all: run

run: bin/test_main.o bin/File_Reader.o bin/workout.o bin/Customer.o bin/Functions.o bin/Trainer.o bin/Studio.o bin/File_Reader_Output.o bin/Action.o
	g++ -O0 bin/test_main.o bin/File_Reader.o bin/workout.o bin/Customer.o bin/Functions.o bin/Trainer.o bin/Studio.o bin/File_Reader_Output.o bin/Action.o -o run

bin/test_main.o: src/test_main.cpp
	g++ -O0 -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/test_main.o src/test_main.cpp

bin/File_Reader.o: src/File_Reader.cpp
	g++ -O0 -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/File_Reader.o src/File_Reader.cpp

bin/workout.o:src/workout.cpp
	g++ -O0 -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/workout.o src/workout.cpp

bin/Customer.o:src/Customer.cpp
	g++ -O0 -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Customer.o src/Customer.cpp

bin/Functions.o:src/Functions.cpp
	g++ -O0 -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Functions.o src/Functions.cpp

bin/Trainer.o:src/Trainer.cpp
	g++ -O0 -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Trainer.o src/Trainer.cpp

bin/Studio.o:src/Studio.cpp
	g++ -O0 -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Studio.o src/Studio.cpp

bin/File_Reader_Output.o:src/File_Reader_Output.cpp
	g++ -O0 -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/File_Reader_Output.o src/File_Reader_Output.cpp

bin/Action.o:src/Action.cpp
	g++ -O0 -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Action.o src/Action.cpp

	@echo success
clean:
	rm bin/test_main.o bin/File_Reader.o bin/workout.o bin/Customer.o bin/Functions.o bin/Trainer.o bin/Studio.o bin/File_Reader_Output.o bin/Action.o run

