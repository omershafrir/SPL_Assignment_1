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
#include <sstream>

using namespace std;
//vector<Customer*> stringToList(string user_input, int* counter, bool is_valid);              //forward declaration
Customer* makeCustomer(string name, int id , string code);                                   //forward declaration
void printCustomerList(vector<Customer*> customersList , Trainer *trainer);                  //forward declaration
//default constructor
Studio::Studio(){

}
//constructor
Studio::Studio(const std::string &configFilePath):open(false){
    customer_counter = new int(0);
    File_Reader_Output input = File_Reader_Output(configFilePath);
    numberOfTrainers = input.getNumberOfTrainers();
    vector<int> trainersCapacities = input.getTrainersCapacities();
    trainers=vector<Trainer*>(numberOfTrainers);
    for(int i = 0; i<numberOfTrainers; i++){
        trainers[i] = new Trainer(trainersCapacities[i]);
    }
    workout_options=input.getWorkout_options();

}
//copy constructor
Studio::Studio(const Studio &other){
    open = other.open;
    for(Workout w : other.workout_options){
        workout_options.push_back(w);
    }
    trainers = copyTrainers(other.trainers);
    actionsLog = copyActions(other.actionsLog);
    numberOfTrainers = other.numberOfTrainers;   //added as a help member
    int number_of_customer = *other.customer_counter;
    customer_counter = new int(number_of_customer);
}
//move constructor
//TODO-CHECK
Studio::Studio(Studio &&other){
    //copying other studios resources
    open = other.open;
    numberOfTrainers = other.numberOfTrainers;
    int number_of_customer = *other.customer_counter;
    other.customer_counter = nullptr;
    customer_counter = new int(number_of_customer);
    trainers = copyTrainers(other.trainers);
    actionsLog = copyActions(other.actionsLog);
    for(Workout w : other.workout_options){
        workout_options.push_back(w);
    }
    other.workout_options.clear();
    //destructing other studio resources
    for(Trainer *t : other.trainers){
        delete t;
    }
    other.trainers.clear();
    for(BaseAction *action : other.actionsLog){
        delete action;
    }
    other.actionsLog.clear();

}
//copy assignment operator
Studio &Studio::operator=(const Studio &studio){
    if(this == &studio){
        return *this;
    }
        open = studio.open;
        trainers = copyTrainers(studio.trainers);
        for(Workout w : studio.workout_options){
            workout_options.push_back(w);
        }
        actionsLog = studio.actionsLog;
        numberOfTrainers = studio.numberOfTrainers;   //added as a help member
        int number_of_customer = *studio.customer_counter;
        customer_counter = new int(number_of_customer);
        return *this;
}
//move assignment operator
//TODO-CHECK
Studio &Studio::operator=(Studio &&studio){
    if(this == &studio){
        return *this;
    }
    //clears all previous data of this
    open = studio.open;
    trainers.clear();
    workout_options.clear();
    actionsLog.clear();

    //stealing all other resources
    trainers = studio.trainers;
    for(Workout w : studio.workout_options){
        workout_options.push_back(w);
    }
    actionsLog = studio.actionsLog;
    numberOfTrainers = studio.numberOfTrainers;   //added as a help member
    int number_of_customer = *studio.customer_counter;
    customer_counter = new int(number_of_customer);
    return *this;
}
//destructor
Studio::~Studio() {
    for (int i=0 ; i<actionsLog.size() ; i++){
        delete actionsLog[i];
        actionsLog[i] = nullptr;
    }
    actionsLog.clear();
    for (int i=0 ; i<trainers.size() ; i++){
        delete trainers[i];
        trainers[i] = nullptr;
    }
    trainers.clear();
    workout_options.clear();
    delete customer_counter;
//    customer_counter = nullptr;
}

void Studio::start(){
    std::cout<<"Studio is now open!"<<endl;
    open = true;
    while(open){
        cout<<"----------------------------------------------------------------"<<endl;
        string user_input;
        getline(cin,user_input);
        if(user_input.substr(0 , 4) == "open"){
            cout<<"self check print: "<<"open is starting! "<<endl;   ///////////#####/////////////////
            int trainer_id;
            user_input.erase(user_input.begin() ,user_input.begin()+5);     //erasing "open "
            vector<Customer*> customersList;
            for(int i=0 ; i<user_input.length() ; i++) {
                if (user_input[i] == ' ') {
                    stringstream subs(user_input.substr(0,i));
                    user_input.erase(user_input.begin(), user_input.begin() + i + 1);
                    subs >> trainer_id;
                    break;
                }
            }
            //checking the validity of the input
            bool is_valid = true;
            if(user_input.size() == 0 || trainer_id > trainers.size()){
                is_valid = false;
            }
            customersList = stringToList(user_input , customer_counter, is_valid, trainer_id);
            OpenTrainer *open =new OpenTrainer(trainer_id , customersList);     //opening trainer
            actionsLog.push_back(open);
//            cout<<actionsLog[0]->toString()<<endl;        ///////////#####/////////////////
            open->act(*this);
//            cout<<"self check print: "<< open->toString();    ///////////#####/////////////////
        }
        if(user_input.substr(0 , 5) == "order"){
            cout<<"self check print: "<<"order is starting! "<<endl;   ///////////#####/////////////////
            int trainer_id;
            for(int i=6 ; i<user_input.length() ; i++) {
                if (i == user_input.length()-1) {
                    stringstream subs(user_input.substr(6,user_input.length()-6));
                    user_input.erase(user_input.begin(), user_input.begin() + i + 1);
                    subs >> trainer_id;
                    break;
                }
            }
                Order *order =new Order(trainer_id);     //ordering trainer
                actionsLog.push_back(order);
                order->act(*this);
        }
        if(user_input.substr(0 , 4) == "move"){
            cout<<"self check print: "<<"move is starting! "<<endl;   ///////////#####/////////////////
            int src_id , dst_id , c_id;
            bool first=true;
            user_input.erase(user_input.begin(), user_input.begin() + 5);
            for(int i=0; i < user_input.length(); i++) {
                if (user_input[i] == ' ') {
                    stringstream subs(user_input.substr(0,i));
                    user_input.erase(user_input.begin(), user_input.begin() + i + 1);
                    if(first) {
                        subs >> src_id;
                        first=false;
                    }
                    else if(!first){
                        subs >> dst_id;
                    }
                     i = 0;
                }
                 if(i == user_input.length()-1){
                    stringstream subs(user_input);
                    subs >> c_id;
                    i=0;
                    user_input = "";
                }
            }
            MoveCustomer *move = new MoveCustomer(src_id , dst_id , c_id);
            actionsLog.push_back(move);
            move->act(*this);
            cout<<move->toString()<<endl;                           ///////////#####/////////////////

        }
        if(user_input == "closeall"){
            cout << "self check print: " << "closeall is starting! " << endl;   ///////////#####/////////////////
            CloseAll *close_all = new CloseAll();
            close_all->act(*this);
            delete close_all;
            break;
        }
        if(user_input.substr(0 , 5) == "close") {
            cout << "self check print: " << "close is starting! " << endl;   ///////////#####/////////////////
            user_input.erase(user_input.begin(), user_input.begin() + 5);
            stringstream subs(user_input);
            int trainer_to_close;
            subs >> trainer_to_close;
            Close *close = new Close(trainer_to_close);
            actionsLog.push_back(close);
            close->act(*this);
        }
        if(user_input == "workout_options"){
            cout<<"self check print: "<<"print_workouts is starting! "<<endl;   ///////////#####/////////////////
            PrintWorkoutOptions *printWorkoutOptions = new PrintWorkoutOptions();
            actionsLog.push_back(printWorkoutOptions);
            printWorkoutOptions->act(*this);
            cout<<"\n";
        }
        if(user_input.substr(0 , 6) == "status"){
            cout<<"self check print_trainer: "<<"order is starting! "<<endl;   ///////////#####/////////////////
            int trainer_id;
            for(int i=7 ; i<user_input.length() ; i++) {
                if (i == user_input.length()-1) {
                    stringstream subs(user_input.substr(6,user_input.length()-6));
                    user_input.erase(user_input.begin(), user_input.begin() + i + 1);
                    subs >> trainer_id;
                    break;
                }
            }
            PrintTrainerStatus *printTrainerStatus =new PrintTrainerStatus(trainer_id);     //ordering trainer
            actionsLog.push_back(printTrainerStatus);
            printTrainerStatus ->act(*this);
            cout<<"\n";
        }
        if(user_input == "log"){
            cout<<"self check print: "<<"print_actions_log is starting! "<<endl;   ///////////#####/////////////////
            PrintActionsLog *printLog = new PrintActionsLog();
            printLog->act(*this);
            actionsLog.push_back(printLog);
            cout<<"\n";
        }
        if(user_input.substr(0 , 6) == "backup"){
            BackupStudio *backup = new BackupStudio;
            actionsLog.push_back(backup);
            backup->act(*this);
        }
        if(user_input.substr(0 , 7) == "restore"){
            RestoreStudio *restore = new RestoreStudio;
            actionsLog.push_back(restore);
            restore->act(*this);
        }
    }

}

int Studio::getNumOfTrainers() const{
    return numberOfTrainers;
}
std::vector<Workout>& Studio::getWorkoutOptions(){
    return workout_options;
}
Trainer* Studio::getTrainer(int tid) {
    return trainers[tid];
}
const vector<BaseAction*>& Studio::getActionsLog() const{
    return actionsLog;
}
vector<Trainer*> Studio::copyTrainers(vector<Trainer*> v){
    vector<Trainer*> new_trainers;
    for(Trainer* trainer_from : v){
       Trainer *trainer_to = new Trainer(*trainer_from);
        new_trainers.push_back(trainer_to);
    }
    return new_trainers;
}   //side function

vector<BaseAction*> Studio::copyActions(vector<BaseAction*> v){      //side function
    vector<BaseAction*> new_actions;
    for(BaseAction *action_from : v){
        BaseAction *action_to = action_from->clone();
        new_actions.push_back(action_to);
    }
    return new_actions;
}   //side function



vector<Customer*> Studio::stringToList(string user_input, int* counter, bool is_valid, int trainer_id){
    if(!is_valid){
        vector<Customer*> empty;
        return empty;
    }
    else{
        int capacity = getTrainer(trainer_id)->getCapacity();
        int local_counter=0;
        vector<Customer*> customersList;
        string c_name , code;
        for(int i=0 ; i<user_input.length() ; i++){
            if(local_counter == capacity || user_input ==""){
                break;
            }
            if (user_input[i] == ',') {
                c_name = user_input.substr(0, i);
                user_input.erase(user_input.begin(), user_input.begin() + i + 1);
                i = 0;
            }
            if(i==user_input.length()-1){
                code=user_input;
                user_input.erase(user_input.begin(), user_input.end());
//            customersList.push_back(makeCustomer(c_name , customer_counter , code));    //before change
//            customer_counter++;                                                         //before change
                customersList.push_back(makeCustomer(c_name , *counter , code));
                local_counter++;
                (*counter)++;
            }
            else if(user_input[i] == ' '){
                code=user_input.substr(0, i);
                user_input.erase(user_input.begin(), user_input.begin() + i + 1);
                i = 0;
//            customersList.push_back(makeCustomer(c_name , customer_counter , code));     //before change
//            customer_counter++;                                                          //before change
                customersList.push_back(makeCustomer(c_name , *counter , code));
                local_counter++;
                (*counter)++;
            }
        }
        return customersList;
    }

}                   //side function
Customer* makeCustomer(string name, int id , string code){
    Customer *c;
    if (code == "swt"){
        c=new SweatyCustomer(name , id);
    }
    if (code == "chp"){
        c=new CheapCustomer(name , id);
    }
    if (code == "mcl"){
        c=new HeavyMuscleCustomer(name , id);
    }
    if (code == "fbd"){
        c=new FullBodyCustomer(name , id);
    }
    return c;
}            //side function
