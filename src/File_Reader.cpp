#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<int>* convert(string input){
    //converting string of 'num1,num2,num3...' to int vector function
    //assumes input is valid
    int numDetector=0; //index of first letter of substring
    vector<int>* output=new  vector<int>();
    for(int i=0;i<input.size();i++){
    //case 1 - substring in the middle of string
    if(input[i]==','){
         string sub=input.substr(numDetector,i-numDetector);
         stringstream subs(sub);
         int temp=0;
         subs>>temp;
         output->push_back(temp);
         numDetector=i+1;
        }
    //case 2- substring in the end of string
    else if(i==input.size()-1){
        string sub=input.substr(numDetector,i-numDetector+1);
        stringstream subs(sub);
        int temp=0;
        subs>>temp;
        output->push_back(temp);
        numDetector=i+1;
    }
    }
    return output;
}

void deleteVector(vector<int>* v){
    for(int x : v){
        delete x;
    }
    v=nullptr;
}
//reading txt function
void read(){
    using namespace std;
    string numOfTrainers;
    string trainersCapacities;
    vector <int> trainersCapacities_v;
//    string workouts;
    vector <string> workouts;

    ifstream textfile;
    string line;
    textfile.open("ExmapleInput.txt");
    textfile >> line;
    int i=1;
    for(line;getline(textfile,line);){
        if (i==2){
            numOfTrainers=line;
        }
        if(i==5){
            trainersCapacities=line;
        }
        if(i>=8){
            workouts.push_back(line);
        }
        i++;
    }
    //converting trainersCapacities string to vector
    int numDetector=0;
    for(int i=0;i<trainersCapacities.size();i++){
        if(trainersCapacities[i]==','){
            string sub=trainersCapacities.substr(numDetector,i-numDetector);
            const char* subr=sub.c_str();
            trainersCapacities_v.push_back(atoi(subr));
            numDetector=i+1;
        }

    }
    /////////////////prints
//    cout <<numOfTrainers<<endl;
//    cout <<trainersCapacities<<endl;
//    for (string i: workouts){
//        cout <<i<<" ";
//    }
    for (int num : trainersCapacities){
        cout <<num<<" ";
    }
//    while(textfile.good()){ //iterates over entire text file
//        cout <<word<<" ";
//        textfile >> word;
//    }
//    cout <<word<<" "; //last "good" word
};

