#include <iostream>
#include <vector>
#include "../include/Workout.h"
#include "../include/Customer.h"
#include "../include/Trainer.h"
#include "../include/Studio.h"
#include "../include/File_Reader.h"
#include "../include/File_Reader_Output.h"
#include <fstream>
#include <sstream>
using namespace std;

void printVector (vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<"Object number "<<i<<" is: "<<v[i]<<endl;
    }
    cout<<endl;
}


int main(int argc, char *argv) {
    //ANAEROBIC, MIXED, CARDIO
//    vector <Workout> w;
//        Workout w1 = Workout(1, "1", 3000, CARDIO);
//        Workout w2 = Workout(2, "2", 300, ANAEROBIC);
//    cout<<w1.getName()<<"    "<<w2.getName();
//    Workout w3= Workout(3,"soccer",12,MIXED);
//    Workout w4= Workout(4,"baskeyball",1,CARDIO);
//    Workout w5= Workout(5,"baskeyball",195,ANAEROBIC);
//    Workout w6= Workout(6,"baskeyball",125,MIXED);
//    Workout w7= Workout(7,"baskeyball",150,MIXED);
//    Workout w8= Workout(8,"baskeyball",15,ANAEROBIC);
//    w.push_back(w2);
//    w.push_back(w3);
//    w.push_back(w4);
//    w.push_back(w5);
//    w.push_back(w6);
//    w.push_back(w7);
//    w.push_back(w8);
//    File_Reader reader;
//////    string input="Yoga, Anaerobic, 90";
//////    string input="Spinning, Mixed, 120";
//////    Workout w =reader.convert_w(input,23);
    string path="src/config.txt";
//    int v1=reader.read_1(path);
//    vector<int> v2 = reader.read_2(path);
//    vector<Workout> v3 = reader.read_3(path);
//
//    cout<<v1<<endl;
//    printVector(v2);
//    for( Workout w : v3) {
//        w.print();
//    }
//
//string s;
//getline(cin,s);
//
//cout<<"s is "<< s <<endl;

//File_Reader_Output x(path);
//cout<<x.getNumberOfTrainers();
//    printVector(x.getTrainersCapacities());


Studio s=Studio(path);
cout<<s.numberOfTrainers;
    for( Workout w : s.workout_options) {
        w.print();
    }




//    for(string::reverse_iterator r_iter=s.rbegin();r_iter!=s.rend();++r_iter){  //iterates over price
//       cout<<*r_iter<<endl;
//        }
//    Workout w=reader.convert_w(s,1);
//    int n=reader.read_1();
//    vector<int> v=reader.read_2();
//    printVector(v);




}


