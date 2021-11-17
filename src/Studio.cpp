#include <vector>
#include <string>
#include "../include/Workout.h"
#include "../include/Trainer.h"
#include "../include/Action.h"
#include "../include/File_Reader.h"
#include "../include/File_Reader_Output.h"
#include "../include/Studio.h"
#include "fstream"

using namespace std;

Studio::Studio(){

}
Studio::Studio(const std::string &configFilePath):open(false){
    File_Reader_Output input = File_Reader_Output(configFilePath);
    numberOfTrainers = input.getNumberOfTrainers();
    vector<int> trainersCapacities = input.getTrainersCapacities();
    trainers=vector<Trainer*>(numberOfTrainers);
//    for(int i = 0; i<numberOfTrainers; i++){
//        trainers[i] = new Trainer(trainersCapacities[i]);
//    }
    workout_options=input.getWorkout_options();
}
void Studio::start(){
    cout<<"Studio is now open!";
    open = true;
    while(open){
        string user_input;
        getline(cin,user_input);
    }
}
int Studio::getNumOfTrainers() const{
    return numberOfTrainers;
}