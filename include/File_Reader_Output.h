#ifndef BASE_CODE_FILE_READER_OUTPUT_H
#define BASE_CODE_FILE_READER_OUTPUT_H
#include <iostream>
#include <vector>
#include "../include/Workout.h"
#include "../include/Customer.h"
#include "../include/Trainer.h"
#include "../include/File_Reader.h"

class File_Reader_Output : File_Reader{
public:
//    File_Reader_Output();
    File_Reader_Output(string _path);
//    ~File_Reader_Output();
    int getNumberOfTrainers();
    vector<int> getTrainersCapacities();
    vector<Workout> getWorkout_options();
private:
    string path;
    int numberOfTrainers;
    vector<int> trainersCapacities;
    vector<Workout> workout_options;
};


#endif //BASE_CODE_FILE_READER_OUTPUT_H
