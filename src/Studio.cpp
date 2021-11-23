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
vector<Customer*> stringToList(string user_input , int capacity , int* counter);              //forward declaration
Customer* makeCustomer(string name, int id , string code);      //forward declaration
void printCustomerList(vector<Customer*> customersList , Trainer *trainer);     //forward declaration


Studio::Studio(){

}
Studio::Studio(const std::string &configFilePath):open(false){
    customer_counter = new int(0);
    File_Reader_Output input = File_Reader_Output(configFilePath);
    numberOfTrainers = input.getNumberOfTrainers();
    vector<int> trainersCapacities = input.getTrainersCapacities();
    trainers=vector<Trainer*>(numberOfTrainers);
//    trainers=*(new vector<Trainer*>(numberOfTrainers));               ////to remove this line when finished testing/////
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
    std::cout<<"Studio is now open!"<<endl;
    open = true;
    while(open){
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
            customersList = stringToList(user_input ,trainers[trainer_id]->getCapacity() , customer_counter);
            OpenTrainer *open =new OpenTrainer(trainer_id , customersList);     //opening trainer
            open->act(*this);
            cout<<"self check print: "<< open->toString();                   //self check print
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
                order->act(*this);
//                cout<<"---------------------------"<<endl;
//                cout<<"salary : "<< trainers[trainer_id]->getSalary();  ///////////#####/////////////////
//                trainers[trainer_id]->printOrderList();
        }
        if(user_input.substr(0 , 4) == "move"){
            cout<<"self check print: "<<"move is starting! "<<endl;   ///////////#####/////////////////
            int src_id , dst_id , c_id;
            bool first=true;
            user_input.erase(user_input.begin(), user_input.begin() + 5);
            cout<<user_input<<endl;                                 //////////#####/////////////////
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
                    cout<<"found: "<<user_input<<endl;
                    stringstream subs(user_input);
                    subs >> c_id;
                    i=0;
                }

            }
            cout<<src_id<<endl;
            cout<<dst_id<<endl;
            cout<<c_id<<endl;
            MoveCustomer *move = new MoveCustomer(src_id , dst_id , c_id);
            move->act(*this);
            cout<<move->toString()<<endl;                           ///////////#####/////////////////

        }
    }
}                                   // -not implemented yet


int Studio::getNumOfTrainers() const{
    return numberOfTrainers;
}
std::vector<Workout>& Studio::getWorkoutOptions(){
    return workout_options;
}
Trainer* Studio::getTrainer(int tid) {
    return trainers[tid];
}
//const std::vector<BaseAction*>& getActionsLog() const{}      - not implemented yet





vector<Customer*> stringToList(string user_input , int capacity , int* counter){
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
