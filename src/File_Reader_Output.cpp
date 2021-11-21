#include "../include/File_Reader_Output.h";
#include <vector>
#include <string>
using namespace std;

//File_Reader_Output::File_Reader_Output(){}
File_Reader_Output::File_Reader_Output(string _path):File_Reader(),path(_path){
    numberOfTrainers=read_1(path);
    trainersCapacities=read_2(path);
    workout_options=read_3(path);
}
//File_Reader_Output::~File_Reader_Output(){
////    delete &path;
//    delete &trainersCapacities;
//    delete &workout_options;
//}
int File_Reader_Output::getNumberOfTrainers(){
    return numberOfTrainers;
}
vector<int> File_Reader_Output::getTrainersCapacities(){
    return trainersCapacities;
}
vector<Workout> File_Reader_Output::getWorkout_options(){
    return workout_options;
}
