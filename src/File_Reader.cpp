#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "../include/File_Reader.h"
#include "stdio.h"
using namespace std;

//all convert functions assume input is valid
//converting string of 'num1,num2,num3...' to vector<int>
vector<int> File_Reader::convert(string input){
    int numDetector=0; //index of first letter of substring
    vector<int> output=vector<int>();
    for(int i=0;i<input.size();i++){
        //case 1 - substring in the middle of string
        if(input[i]==','){
            string sub=input.substr(numDetector,i-numDetector);
            stringstream subs(sub);
            int temp=0;
            subs>>temp;
            output.push_back(temp);
            numDetector=i+1;
        }
            //case 2- substring in the end of string
        else if(i==input.size()-1){
            string sub=input.substr(numDetector,i-numDetector+1);
            stringstream subs(sub);
            int temp=0;
            subs>>temp;
            output.push_back(temp);
            numDetector=i+1;
        }
    }
    return output;
}
//converting string of a 'num1' to int
int File_Reader::convert_int(std::string input){
    stringstream subs(input);
    int num;
    subs>>num;
    return num;
}
//converting string of 'w_name,w_price,w_type' to Workout
Workout File_Reader::convert_w(string input ,int id){
    int w_id = id , w_price;       //the 4 members of Workout class
    string w_name;
    WorkoutType w_type;

    string input_temp=input;    //input_temp will be destroyed

    int counter_name=0, counter_price=0 , counter_type=0;       //counts the num of chars in each workout member
    for(string::reverse_iterator r_iter=input_temp.rbegin();r_iter!=input_temp.rend();++r_iter){  //iterates over price
        if(*r_iter>=48 && *r_iter<=57)
            counter_price++;
        else
            break;
    }
    input_temp.erase(input_temp.end()-counter_price-2 , input_temp.end());      //erasing the number + the adjacent ", "
    for(string::reverse_iterator r_iter=input_temp.rbegin();r_iter!=input_temp.rend();++r_iter) {  //iterates over type
        if(*r_iter!=' ')
            counter_type++;
        else
            break;
    }
    input_temp.erase(input_temp.end()-counter_type-2 , input_temp.end());       //erasing the type + the adjacent ", "
    for(string::reverse_iterator r_iter=input_temp.rbegin();r_iter!=input_temp.rend();++r_iter){  //iterates over name
        counter_name++;
    }

    w_name = input.substr(0 , counter_name);
    w_price = convert_int(input.substr(input.length()-1-counter_price, input.length()-1));
    if(counter_type == 5)
        w_type = MIXED;
    else if (counter_type == 6)
        w_type = CARDIO;
    else
        w_type = ANAEROBIC;
    Workout w(w_id,w_name,w_price,w_type);
    return w;
}


//reads Number of trainers
int File_Reader::read_1(string configFilePath) {      //was: int File_Reader::read_1()
    string numOfTrainers_s;
    ifstream textfile;
    string line;
    textfile.open(configFilePath);                    //was: textfile.open("src/config.txt")
    textfile >> line;
    int i=1;
    for (line; getline(textfile, line);) {
        if (i == 2) {
            numOfTrainers_s = line;
            break;
        }
        i++;
    }
    return convert_int(numOfTrainers_s);
};
//reads Trainers
vector<int> File_Reader::read_2(string configFilePath){     //was: vector<int> File_Reader::read_2()
    string trainersCapacities_s;
    ifstream textfile;
    string line;
    textfile.open(configFilePath);                          //was : textfile.open("src/config.txt");
    textfile >> line;
    int i=1;
    for (line; getline(textfile, line);) {
        if (i == 5) {
            trainersCapacities_s = line;
            break;
        }
        i++;
    }
    vector<int> trainersCapacities_v= convert(trainersCapacities_s);
    return trainersCapacities_v;
}
///reads Workout Options
vector<Workout> File_Reader::read_3(string configFilePath){        //was:vector<Workout> File_Reader::read_3()
    vector<Workout> workouts_v;     //return value
    string workouts_s;
    ifstream textfile;
    string line;
    textfile.open(configFilePath);                //was: textfile.open("src/config.txt");
    textfile >> line;
    int i=1;
    for (line; getline(textfile, line);) {
        if (i >= 8) {           //workouts start at line 8 exactly
            if(line=="")        //break condition
                break;
            else {
                workouts_s = line;
                Workout w = convert_w(workouts_s, i - 8);   //Workouts_s has price, name , type      i-8=id
                workouts_v.push_back(w);
            }
        }
        i++;
    }
    return workouts_v;
}


//reading txt function
//void File_Reader::read(){
//    string numOfTrainers;
//    string trainersCapacities;
//    vector <int> trainersCapacities_v;
////    string workouts;
//    vector <string> workouts;
//
//    ifstream textfile;
//    string line;
//    textfile.open("config.txt");
//    textfile >> line;
//    int i=1;
//    for(line;getline(textfile,line);){
//        if (i==2){
//            numOfTrainers=line;
//        }
//        if(i==5){
//            trainersCapacities=line;
//        }
//        if(i>=8){
//            workouts.push_back(line);
//        }
//        i++;
//    }
//    //converting trainersCapacities string to vector
//    int numDetector=0;
//    for(int i=0;i<trainersCapacities.size();i++){
//        if(trainersCapacities[i]==','){
//            string sub=trainersCapacities.substr(numDetector,i-numDetector);
//            const char* subr=sub.c_str();
//            trainersCapacities_v.push_back(atoi(subr));
//            numDetector=i+1;
//        }
//
//    }
//    /////////////////prints
//    cout <<numOfTrainers<<endl;
//    cout <<trainersCapacities<<endl;
//    for (string i: workouts){
//        cout <<i<<" ";
//    }
//    for (int num : trainersCapacities){
//        cout <<num<<" ";
//    }
////    while(textfile.good()){ //iterates over entire text file
////        cout <<word<<" ";
////        textfile >> word;
////    }
////    cout <<word<<" "; //last "good" word
//};


