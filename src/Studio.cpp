#include <vector>
#include <string>
#include "../include/Workout.h"
#include "../include/Trainer.h"
#include "../include/Action.h"
#include "../include/File_Reader.h"
#include "../include/File_Reader_Output.h"
#include "../include/Studio.h"
#include <iostream>
#include <fstream>

using namespace std;

Studio::Studio(){

}
Studio::Studio(const std::string &configFilePath):open(false){
    File_Reader_Output input = File_Reader_Output(configFilePath);
    numberOfTrainers = input.getNumberOfTrainers();
    vector<int> trainersCapacities = input.getTrainersCapacities();
    trainers=vector<Trainer*>(numberOfTrainers);
    for(int i = 0; i<numberOfTrainers; i++){
        trainers[i] = new Trainer(trainersCapacities[i]);
    }
    workout_options=input.getWorkout_options();
}
//Studio::~Studio() {
//    delete &trainers;
//    delete &workout_options;
//    delete &actionsLog;
//}
void Studio::start(){
    std::cout<<"Studio is now open!";
    open = true;
    while(open){
        string user_input;
        getline(cin,user_input);
        if(user_input.substr(0 , 4) == "open"){
            int trainer_id = user_input[5];
            //studio sends customerList vector with fixed size
            //if the customer list is too big , the excess amount oof customers will be ignored
        }

    }
}                                   // -not implemented yet
int Studio::getNumOfTrainers() const{
    return numberOfTrainers;
}
std::vector<Workout>& Studio::getWorkoutOptions(){
    vector<Workout>& w = workout_options;
//    std::cout<<&w<<endl;
    return w;
//    std::cout<<&workout_options<<endl;
//    return workout_options;
}
Trainer* Studio::getTrainer(int tid){
    return trainers[tid];

}
//const std::vector<BaseAction*>& getActionsLog() const{}      - not implemented yet