#include "../include/Action.h"
#include "../include/Studio.h"
#include "../include/Trainer.h"
#include <sstream>>

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
//OpenTrainer:: ~OpenTrainer(){
////    delete[] &customers;
////    for (Customer *c : customers)
////        delete c;
//}
string OpenTrainer::toString() const{
    stringstream ss;
    if(getStatus() == ERROR)
        return "The action was not successful";
    ss << "The following customers has been added to trainer num." << to_string(trainerId) <<": ";
    ss << "\n";
    for (Customer* customer : customers){
        ss << customer->toString() << "\n";
    }
    string s = ss.str();
    return s;
}




/////////////////////////////////////////////////////Order///////////////////////////////////////////////////
Order::Order(int id):trainerId(id) {
}
void Order::act(Studio &studio){
    if(trainerId > studio.getNumOfTrainers()-1 || trainerId < 0)        //check if trainer exist
        error("Trainer does not exist or is open");
    else if(!studio.getTrainer(trainerId)->isOpen())                    //check if trainer open or closed
        error("Trainer does not exist or is open");
        else{
            Trainer *this_trainer = studio.getTrainer(trainerId);
            for (Customer *c : this_trainer->getCustomers()){
                this_trainer->order(c->getId() , c->order(studio.getWorkoutOptions()) , studio.getWorkoutOptions());
            }
        this_trainer->printOrder();
        complete();
        }
}
string Order::toString() const{
    return "0";
}

////////////////////////////////////////////////////MoveCustomer//////////////////////////////////////////
//    const int srcTrainer;
//    const int dstTrainer;
//    const int id;

MoveCustomer::MoveCustomer(int src, int dst, int customerId):srcTrainer(src),dstTrainer(dst),id(customerId){}
void MoveCustomer::act(Studio &studio) {
    //if the src trainer doesn't have no one after this move
    //close this trainer!

    //check if trainer exist
    if (srcTrainer > studio.getNumOfTrainers() - 1 || srcTrainer < 0
        || dstTrainer > studio.getNumOfTrainers() - 1 || dstTrainer < 0) {
        error("Cannot move customer");
        return;
    }
    Trainer *src_t = studio.getTrainer(srcTrainer);
    Trainer *dst_t = studio.getTrainer(dstTrainer);
    //check if trainer open or closed
    if (!src_t->isOpen() || !dst_t->isOpen()) {
        error("Cannot move customer");
        return;
    }
    //no one with this id is in the src trainer
    if (src_t->getCustomer(id) == nullptr) {
        error("Cannot move customer");
        return;
    }
    //the dst trainer has no spots
    if (dst_t->getCapacity() <= dst_t->getCurrentCapacity()) {
        error("Cannot move customer");
        return;
    }
    vector<Workout> workout_options = studio.getWorkoutOptions();
    //orders the proper workout from the src to the dst trainer
    //using order function
    dst_t->order(id , src_t->getCustomer(id)->order(workout_options) , workout_options);
    dst_t->addCustomer(src_t->getCustomer(id));
    src_t->removeCustomer(id);
    complete();
}
string MoveCustomer::toString() const{
    stringstream ss;
    if(getStatus() == ERROR)
        return "Cannot move customer";
    ss << "Customer num. "<< id<<"moved from " << srcTrainer <<" to "<< dstTrainer;
    ss << "\n";
    string s = ss.str();
    return s;
}

////////////////////////////////////////////////////Close//////////////////////////////////////////
//class Close : public BaseAction {
//public:
//    Close(int id);
//    void act(Studio &studio);
//    std::string toString() const;
//private:
//    const int trainerId;


//Close::Close(int id):trainerId(id){
//}
//void Close::act(Studio &studio){
//    if(trainerId > studio.getNumOfTrainers()-1 || trainerId < 0)        //check if trainer exist
//        error("Trainer does not exist or is not open");
//    else if(!studio.getTrainer(trainerId)->isOpen())                    //check if trainer open or closed
//        error("Trainer does not exist or is not open");
//}
//string Close::toString() const{
//
//}