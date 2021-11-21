#include "../include/Action.h"
#include "../include/Studio.h"
#include "../include/Trainer.h"

using namespace std;
BaseAction::BaseAction(){

}
ActionStatus BaseAction::getStatus() const{
    return status;
}

void BaseAction:: complete(){
    status = COMPLETED;
}

void BaseAction::error(string errorMsg){
    status = ERROR;
    this->errorMsg=errorMsg;
    cout<<"Error: "<<errorMsg<<endl;
}
string BaseAction::getErrorMsg() const{
    return errorMsg;
}


//////////////////////////////////////////////////////OpenTrainer///////////////////////////////////////////////////
//OpenTrainer fields:
//const int trainerId;
//std::vector<Customer *> customers;

OpenTrainer::OpenTrainer(int id, std::vector<Customer *> &customersList):trainerId(id){
customers=customersList;
}
void OpenTrainer::act(Studio &studio){
    if(trainerId > studio.getNumOfTrainers()-1 || trainerId < 0)        //check if trainer exist
        error("Workout session does not exist or is already open");
    else {
        Trainer *this_trainer = studio.getTrainer(trainerId);
        if (this_trainer->isOpen())                                 //check if trainer is already open
            error("Workout session does not exist or is already open");
        else {
            this_trainer->openTrainer();
            for (Customer *customer : customers){         //adds all the customers received at 'customersList' to the session
                this_trainer->addCustomer(customer);
            }
            complete();                                 //call for base class method complete()
        }
    }
}
string OpenTrainer::toString() const{
    return "000";
//    string s , temp;
//    for (Customer* customer : customers){
//        s += customer->toString();
//        s +="\n";
//    }
//    return s;
}            //  -not implemented yet




/////////////////////////////////////////////////////OpenTrainer///////////////////////////////////////////////////