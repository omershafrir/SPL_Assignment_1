#ifndef BASE_CODE_FILE_READER_H
#define BASE_CODE_FILE_READER_H
#include <iostream>
#include <vector>
#include "../include/Workout.h"

using namespace std;
class File_Reader{
public:
    File_Reader(){};

private:
    vector<int> convert(string input);
    int convert_int(string input);
    Workout convert_w(string input , int id);
//    void read();
protected:
    int read_1(string configFilePath);              //was:int read_1(
    vector<int> read_2(string configFilePath);          //was:vector<int> read_2
    vector<Workout> read_3(string configFilePath);     //was:vector<Workout> read_3()
};
#endif //BASE_CODE_FILE_READER_H